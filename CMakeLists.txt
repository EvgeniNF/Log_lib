#---------------------------------------------------------------------#
#----------------------Set minimum version Cmake ---------------------#
cmake_minimum_required(VERSION 3.19)
#---------------------------------------------------------------------#
#---------------------------Set name project -------------------------#
project(Logs_lib
        VERSION 0.0.1
        DESCRIPTION "Lib for generate logs"
        LANGUAGES CXX)
#---------------------------------------------------------------------#
#------------------------Set language standard -----------------------#
set(CMAKE_CXX_STANDARD 20)
#---------------------------------------------------------------------#
#--------------------------Add lib directory -------------------------#
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
add_subdirectory(scr)
#---------------------------------------------------------------------#
#-------------------------Add executable file ------------------------#
add_executable(Logs_lib main.cpp)
#---------------------------------------------------------------------#
#----------------------------Link libraries --------------------------#
target_link_libraries(Logs_lib PUBLIC loglib)
#---------------------------------------------------------------------#