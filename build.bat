@echo off
setlocal EnableDelayedExpansion

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001


set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .


set arr[0].file=run_bubble.bat
set arr[1].file=run_bubble_sort_split.bat
set arr[2].file=run_refactoring.bat
set arr[3].file=run_hello.bat
set arr[4].file=run_my_project.bat

set arr[0].folder=bubble_sort
set arr[1].folder=bubble_sort_split
set arr[2].folder=refactoring_proj
set arr[3].folder=hello
set arr[4].folder=my_project


for /L %%i in (0, 1, 4) do (
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .