@echo off

chpr 65001

ctest -j 5 -N --output-on-failure
