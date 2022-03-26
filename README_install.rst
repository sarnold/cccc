Installation Quick Start
========================

cccc is currently tested on the Github CI runners using Ubuntu, Macos,
and Windows.  Older versions are still packaged on Debian/Ubuntu and other
places, however, to get the latest you need to compile from source or use
the `Launchpad PPA`_ (Ubuntu focal only) or the `Gentoo ebuild`_.

For the former, make sure you have the ``add-apt-repository`` command
installed and then add the PPA:

::

  $ sudo apt-get install software-properties-common
  $ sudo add-apt-repository -y -s ppa:nerdboy/embedded
  $ sudo apt-get install cccc

The latest version is now available in conda-forge_ so if you have a
conda environment handy, you can install with::


  $ conda config --add channels conda-forge
  $ conda install cccc


.. _conda-forge: https://github.com/conda-forge/cccc-feedstock

Compiling from source
---------------------

Requirements for building cccc from the repo source:

* A build environment with ``gcc``, ``clang``, ``mingw64``, ``msvc``, etc.

  + On Ubuntu/Debian, install via ``sudo apt-get install build-essential``
  + On Gentoo, just emerge it
  + On Macos, use xcode/clang
  + On Windows, use one of the MSCV "free" editions or cygwin/msys


With a build environment in place, clone the repo and build it::

  $ git clone https://github.com/sarnold/cccc
  $ cd cccc/
  $ make cccc
  $ make test

For MSVC on windows you can follow the same basic procedure, but use the
``.bat`` file to build instead of ``make``::

  $ git clone https://github.com/sarnold/cccc
  $ cd cccc
  $ ./build_msvc.bat --clean


.. note:: On windows the executable name is ``cccc.exe``.


From there you can copy the executable to the ``bin`` directory of your
choice, eg, ``$HOME/bin`` or ``/usr/local/bin``.


.. _Launchpad PPA: https://launchpad.net/~nerdboy/+archive/ubuntu/embedded
.. _Gentoo ebuild: https://packages.gentoo.org/packages/dev-util/cccc
