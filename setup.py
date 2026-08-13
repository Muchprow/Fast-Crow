from setuptools import setup, Extension

module = Extension('fast_crow', sources=['fast_crow.c'])

setup(
    name='fast_crow',
    version='1.0',
    description='Native C Extension for Python Performance',
    ext_modules=[module]
)
