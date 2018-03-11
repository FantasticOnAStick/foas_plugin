cmake_minimum_required(VERSION 2.8)
project(foas_plugin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -fPIC")

if(NOT TARGET foas_common)
  add_subdirectory(../foas_common build/foas_common)
endif()

if(NOT TARGET foas_message)
  add_subdirectory(../foas_message build/foas_message)
endif()

include_directories(
  include
  ../foas_common/include
  ../foas_message/include)

file(GLOB_RECURSE LIB_SRC src/plugin FOLLOW_SYMLINKS *.cpp)
add_library(${PROJECT_NAME}
  ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}
  foas_common
  dl)
