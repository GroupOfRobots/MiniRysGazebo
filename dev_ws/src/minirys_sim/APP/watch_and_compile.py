import os
import sys
import time
import subprocess
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class SourceCodeChangeHandler(FileSystemEventHandler):
    def __init__(self):
        self.process = None

    def on_modified(self, event):
        if event.src_path.endswith('App.py'): 
            if self.process is not None and self.process.poll() is None:
                self.process.terminate()
                self.process.wait()

            print("Running App.py")
            self.process = subprocess.Popen(['python3', 'App.py'])

def main():
    path = sys.argv[1] if len(sys.argv) > 1 else '.'
    observer = Observer()
    handler = SourceCodeChangeHandler()
    observer.schedule(handler, path, recursive=True)
    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
        if handler.process is not None and handler.process.poll() is None:
            handler.process.terminate()
            handler.process.wait()
    observer.join()

if __name__ == "__main__":
    main()
