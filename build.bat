@echo off
cl /EHsc /c *.cpp
link *.obj /out:main.exe
