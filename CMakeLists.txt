cmake_minimum_required(VERSION 3.25)
project(msgpackm)

enable_testing()
include_directories(inc)
add_subdirectory(src)
add_subdirectory(tests)

# https://www.mcternan.me.uk/mscgen/
find_package(Doxygen REQUIRED dot OPTIONAL_COMPONENTS mscgen dia)

set(OPTIMIZE_OUTPUT_FOR_C YES)
set(DOXYGEN_SOURCE_BROWSER YES)
doxygen_add_docs(msgpackm-doxy ${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/src)
