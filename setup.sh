#!/bin/sh
sudo apt-get update
sudo apt-get install libibmad-dev
sudo apt-get install libibumad-dev
sudo apt-get install ibsim-utils
sudo apt-get install opensm
sudo apt-get install git
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install python
sudo apt-get install python-dev
sudo apt-get install mercurial
sudo apt-get install bzr
sudo apt-get install gdb
sudo apt-get install valgrind
sudo apt-get install gsl-bin
#sudo apt-get install libgsl0-dev
#sudo apt-get install libgsl0ldbl 
sudo apt-get install libgsl2-dev
sudo apt-get install libgsl2
sudo apt-get install flex
sudo apt-get install bison
sudo apt-get install tcpdump
sudo apt-get install sqlite
sudo apt-get install sqlite3
sudo apt-get install libsqlite3-dev libxml2 libxml2-dev libgtk2.0-0 libgtk2.0-dev uncrustify doxygen graphviz imagemagick texlive texlive-latex-extra texlive-generic-extra texlive-generic-recommended texinfo dia texlive texlive-latex-extra texlive-extra-utils texlive-generic-recommended texi2html python-pygraphviz python-kiwi python-pygoocanvas libgoocanvas-dev python-pygccxml
git clone https://github.com/jgunthorpe/ibsim.git
cd ibsim
make
cd ..
#sudo echo "ib_umad" >> /etc/modules
