cmake_minimum_required(VERSION 3.25)
project(TextRPG C)

set(CMAKE_C_STANDARD 11)

add_executable(TextRPG main.c PureCStrings.c)
