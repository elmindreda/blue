
cmake_minimum_required(VERSION 3.0)

project(blue C)

add_library(blue SHARED main.c)
set_target_properties(blue PROPERTIES PREFIX "")

