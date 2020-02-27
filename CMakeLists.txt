cmake_minimum_required(VERSION 3.15)
project(kth_is1200 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories("lab 3")
include_directories(orievg)
include_directories(orievg/lab-3)
include_directories(orievg/lab-3/time4int)
include_directories(orievg/lab-3/time4io)
include_directories(orievg/lab-3/timer4timer)
include_directories(project)

add_executable(kth_is1200
        orievg/lab-3/time4int/mipslab.h
        orievg/lab-3/time4int/mipslabdata.c
        orievg/lab-3/time4int/mipslabfunc.c
        orievg/lab-3/time4int/mipslabmain.c
        orievg/lab-3/time4int/mipslabwork.c
        orievg/lab-3/time4int/stubs.c
        orievg/lab-3/time4int/time4io.c
        orievg/lab-3/time4io/mipslab.h
        orievg/lab-3/time4io/mipslabdata.c
        orievg/lab-3/time4io/mipslabfunc.c
        orievg/lab-3/time4io/mipslabmain.c
        orievg/lab-3/time4io/mipslabwork.c
        orievg/lab-3/time4io/stubs.c
        orievg/lab-3/time4io/time4io.c
        orievg/lab-3/timer4timer/mipslab.h
        orievg/lab-3/timer4timer/mipslabdata.c
        orievg/lab-3/timer4timer/mipslabfunc.c
        orievg/lab-3/timer4timer/mipslabmain.c
        orievg/lab-3/timer4timer/mipslabwork.c
        orievg/lab-3/timer4timer/stubs.c
        orievg/lab-3/timer4timer/time4io.c
        project/.old/main.c orievg/lab-4/ass5.c project/test.c project/test/figures.h project/test/test.c project/test/test.new.c)

add_executable(ass5 orievg/lab-4/ass5.c)
add_executable(main project/main.c project/test.c project/test.new.cpp)
add_executable(test project/test/test.c)

add_executable(figures project/test/figures.h)
add_executable(test.new project/test/test.new.c)
