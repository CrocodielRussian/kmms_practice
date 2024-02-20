@echo off

::setlocal EnableDelayedExpansion

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001


set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .


set arr[0].file=run_bubble_sort.bat
set arr[1].file=run_bubble_sort_split.bat
set arr[2].file=run_refactoring_proj.bat
set arr[3].folder=hello.bat

set arr[0].folder=bubble_sort
set arr[1].folder=bubble_sort_split
set arr[2].folder=refactoring_proj
set arr[3].folder=hello


for /L %%i in (0,1,3) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)