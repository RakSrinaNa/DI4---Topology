#!/bin/sh
sudo apt-get update
sudo apt-get install libibmad-dev
sudo apt-get install libibumad-dev
sudo apt-get install ibsim-utils
sudo apt-get install opensm
sudo apt-get install git
git clone https://github.com/jgunthorpe/ibsim.git
cd ibsim
make
