@echo off
set PATH=%PATH%;C:\Users\holtal\Documents\GitHub\ESO-20\Tools\GetRegions
@echo on
GetRegions.exe %1 -c -s -oSource\Profiler\region.c
