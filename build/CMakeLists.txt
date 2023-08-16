cmake_minimum_required(VERSION 3.10)

project(CHASM2)

# source files
set(SOURCES
    ../src/nodemode/node.c
    ../src/chasm.c
    ../src/templator.c
)

# executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# include directories when structure is modified
# target_include_directories(${PROJECT_NAME} PRIVATE include)
