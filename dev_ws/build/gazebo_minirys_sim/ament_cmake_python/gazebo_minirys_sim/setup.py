from setuptools import find_packages
from setuptools import setup

setup(
    name='gazebo_minirys_sim',
    version='0.0.0',
    packages=find_packages(
        include=('gazebo_minirys_sim', 'gazebo_minirys_sim.*')),
)
