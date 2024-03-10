@echo off

chpr 65001

ctest -j -N --output-on-failure -R %1
	
