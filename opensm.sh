#!/bin/sh
export SIM_HOST="H-0013970201000978" OSM_TMP_DIR=./ OSM_CACHE_DIR=./ LD_PRELOAD=/usr/lib/umad2sim/libumad2sim.so
sudo LD_PRELOAD=/usr/lib/umad2sim/libumad2sim.so opensm -e -v -f ./osm.log
