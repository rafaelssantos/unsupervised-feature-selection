cmake_minimum_required(VERSION 3.5)

project(ufs  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ufs 
    src/main.cpp
    src/stringutils.h
    src/feature.cpp
    src/feature.hpp
    src/featureio.cpp
    src/featureio.hpp
    src/measure.hpp
    src/measure.cpp
    src/similaritymat.cpp
    src/similaritymat.hpp
    src/ufs.cpp
    src/ufs.hpp
)

include(GNUInstallDirs)
install(TARGETS ufs
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
