cmake_minimum_required(VERSION 3.20)
project(NumericalRecipes LANGUAGES CXX)
# 设置项目名称和语言
# 设置C++标准为C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 添加子目录
add_subdirectory(src)
add_subdirectory(test)

# 添加main.cpp可执行目标
add_executable(NumericalRecipes main.cpp)

# 链接静态库和其他依赖
# 链接NumericalRecipes静态库到MainExecutable
# 确保在 src/CMakeLists.txt 中创建的库名称是正确的
# 使用target_link_libraries进行链接

# 链接src中的静态库NumericalRecipes到主可执行文件
target_link_libraries(NumericalRecipes PRIVATE NumericalRecipesLibs)

# 启用测试
enable_testing()

