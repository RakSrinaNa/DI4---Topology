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
sudo apt-get install libsqlite3-dev
sudo apt-get install libxml2
sudo apt-get install libxml2-dev
sudo apt-get install libgtk2.0-0
sudo apt-get install libgtk2.0-dev
sudo apt-get install uncrustify
sudo apt-get install doxygen
sudo apt-get install graphviz
sudo apt-get install imagemagick
sudo apt-get install texlive
sudo apt-get install texlive-latex-extra
sudo apt-get install texlive-generic-extra
sudo apt-get install texlive-generic-recommended
sudo apt-get install texinfo
sudo apt-get install dia
sudo apt-get install texlive-extra-utils
sudo apt-get install texlive-generic-recommended
sudo apt-get install texi2html
sudo apt-get install python-pygraphviz
sudo apt-get install python-kiwi
sudo apt-get install python-pygoocanvas
sudo apt-get install libgoocanvas-dev
sudo apt-get install python-pygccxml
git clone https://github.com/jgunthorpe/ibsim.git
cd ibsim
make
cd ..
#sudo echo "ib_umad" >> /etc/modules
