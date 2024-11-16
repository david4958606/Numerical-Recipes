# 设置最低CMake版本
cmake_minimum_required(VERSION 3.20)

# 设置项目名称和语言
project(NumericalRecipe LANGUAGES CXX)

# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "clang")

# 设置源文件目录
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
# Add header files to make them visible in IDE
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")

# 添加可执行目标
add_executable(NumericalRecipe ${SOURCES} ${HEADERS})

# 打印包含的源文件（可选，用于调试）
message(STATUS "Source files included in NumericalRecipe:")
foreach(FILE ${SOURCES})
    message(STATUS "  ${FILE}")
endforeach()
