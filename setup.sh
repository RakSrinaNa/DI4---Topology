#!/bin/sh
sudo apt-get update
sudo apt-get install libibmad-dev libibumad-dev ibsim-utils opensm git gcc g++ python python-dev mercurial bzr gdb valgrind gsl-bin libgsl0-dev libgsl0ldbl flex bison tcpdump sqlite sqlite3 libsqlite3-dev libxml2 libxml2-dev libgtk2.0-0 libgtk2.0-dev uncrustify doxygen graphviz imagemagick texlive texlive-latex-extra texlive-generic-extra texlive-generic-recommended texinfo dia texlive texlive-latex-extra texlive-extra-utils texlive-generic-recommended texi2html python-pygraphviz python-kiwi python-pygoocanvas libgoocanvas-dev python-pygccxml
git clone https://github.com/jgunthorpe/ibsim.git
cd ibsim
make
cd ..
#sudo echo "ib_umad" >> /etc/modules
