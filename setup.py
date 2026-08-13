from setuptools import setup, Extension

fast_crow_module = Extension(
    'fast_crow',          
    sources=['fast_crow.c'] 
)

with open('README.md', 'r', encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='fast_crow',                   
    version='0.1.0',                    
    author='Muchprow',
    description='A fast string cleaner library written in C for Python',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/Muchprow/Fast-Crow',
    ext_modules=[fast_crow_module],     
    python_requires='>=3.6',
)
