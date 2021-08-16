#---------------------------------------------------------------------#
#-----------------------------Set lib name ---------------------------#
set(LIB_NAME loglib)
#---------------------------------------------------------------------#
#------------------------Set standard languages ----------------------#
set(CMAKE_CXX_STANDARD 20)
#---------------------------------------------------------------------#
#----------------------------Message output --------------------------#
message("-- LIB NAME: ${LIB_NAME}")
message("-- SOURCE DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- BINARY DIR: ${CMAKE_BINARY_DIR}")
#---------------------------------------------------------------------#
#---------------------------Include headers --------------------------#
set(LIB_PATH ${PROJECT_SOURCE_DIR}/include/loglib)
set(HEADER_LIST ${LIB_PATH}/loglib.hpp)
#---------------------------------------------------------------------#
#-----------------------------Find package ---------------------------#
find_package(Threads REQUIRED)
#---------------------------------------------------------------------#
#------------------------------Add source ----------------------------#
set(SOURCE loglib.cpp)
#---------------------------------------------------------------------#
#-----------------------------Add library ----------------------------#
add_library(${LIB_NAME} SHARED
        ${SOURCE}
        ${HEADER_LIST})
#---------------------------------------------------------------------#
#-----------------------------Include dirs ---------------------------#
target_include_directories(${LIB_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include/loglib)
#---------------------------------------------------------------------#
#-----------------------------Required std ---------------------------#
target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)
#---------------------------------------------------------------------#
#-----------------------------Cmake build ----------------------------#
source_group(TREE "${PROJECT_SOURCE_DIR}/include/loglib"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})
#---------------------------------------------------------------------#
install(TARGETS ${LIB_NAME} DESTINATION bin)
install(FILES ${HEADER_LIST} DESTINATION include)