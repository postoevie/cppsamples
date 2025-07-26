cmake_minimum_required(VERSION 3.15)

project(SortNum VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SortNum sort_num.cxx)

option(USE_CUSTOM_SORT "Use custom sort implementation" ON)

target_include_directories(SortNum PRIVATE
                           "${PROJECT_SOURCE_DIR}"
                           )

if(USE_CUSTOM_SORT)

target_compile_definitions(SortNum PRIVATE "USE_CUSTOM_SORT")

add_library(CustomSortLibrary sort_num_custom_.cxx)

target_link_libraries(SortNum PRIVATE CustomSortLibrary)

endif()