cmake_minimum_required(VERSION 3.23)
project(fstdcxx VERSION 0.0.1)

# Setup basic build settings
enable_language(ASM)

# Library
add_library(fstdcxx)
add_library(fstdcxx_hosted)

target_include_directories(fstdcxx SYSTEM BEFORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/base")
set_target_properties(fstdcxx PROPERTIES CXX_STANDARD 23)

target_include_directories(fstdcxx_hosted SYSTEM BEFORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/base" "${CMAKE_CURRENT_SOURCE_DIR}/include/hosted")
set_target_properties(fstdcxx_hosted PROPERTIES CXX_STANDARD 23)

add_subdirectory(src)
