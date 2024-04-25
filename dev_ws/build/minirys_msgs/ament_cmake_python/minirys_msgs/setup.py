from setuptools import find_packages
from setuptools import setup

setup(
    name='minirys_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('minirys_msgs', 'minirys_msgs.*')),
)
