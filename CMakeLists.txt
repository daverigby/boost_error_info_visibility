cmake_minimum_required(VERSION 3.3)
project(error_info_visibility)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost)

add_compile_definitions(_GNU_SOURCE)
# Changing default visibility to 'default' and everything works...
set(CMAKE_CXX_VISIBILITY_PRESET hidden CACHE STRING "Default symbol visibility")

add_library(boost-exception-lib SHARED boost_exception_lib.cc)
target_link_libraries(boost-exception-lib PUBLIC Boost::boost)

add_executable(boost-exception-test boost_exception_test.cc)
target_link_libraries(boost-exception-test PRIVATE
        boost-exception-lib)
