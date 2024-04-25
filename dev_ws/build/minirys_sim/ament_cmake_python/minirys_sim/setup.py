from setuptools import find_packages
from setuptools import setup

setup(
    name='minirys_sim',
    version='0.0.0',
    packages=find_packages(
        include=('minirys_sim', 'minirys_sim.*')),
)
