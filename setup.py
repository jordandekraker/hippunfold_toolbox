#!/usr/bin/env python3

"""A setuptools based setup module.
See:
https://packaging.python.org/guides/distributing-packages-using-setuptools/
"""

import setuptools

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setuptools.setup(
    name="hippunfold_toolbox",
    version="0.1.0",
    author="Jordan DeKraker",
    author_email="jordandekraker@gmail.com",
    description="A toolbox for viewing, manipulating, and additional actions on HippUnfold outputs",
    long_description=long_description,
    long_description_content_type="text/x-rst",
    url="https://github.com/jordandekraker/hippunfold_toolbox",
    packages=setuptools.find_packages(),
    license="BSD 3-Clause License",
    package_data={
        "resources": ["*"],
    },
    classifiers=[
        "Intended Audience :: Science/Research",
        "Intended Audience :: Developers",
        "Topic :: Software Development :: Build Tools",
        "Topic :: Scientific/Engineering",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Programming Language :: Python :: 3.9",
    ],
    python_requires=">=3.7.*",
    install_requires=[
        "Path>=16.4.0",
        "brainspace>=0.1.2",
        "h5py",
        "netneurotools",
        "neurosynth",
        "nibabel",
        "nilearn>=0.7.0",
        "nimare",
        "numpy>=1.16.5",
        "pandas>=0.23",
        "scikit_learn",
        "scipy>=1.3.3",
        "templateflow",
        "matplotlib",
    ],
    extras_require={"dev": ["gitpython", "hcp-utils", "mypy", "plotly", "pytest"]},
    project_urls={  # Optional
        "Documentation": "https://brainstat.readthedocs.io",
        "Bug Reports": "https://github.com/MICA-LAB/BrainStat/issues",
        "Source": "https://github.com/MICA-LAB/BrainStat/",
    },
)
