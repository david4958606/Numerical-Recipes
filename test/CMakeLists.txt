# 引入 Google Test
find_package(GTest CONFIG REQUIRED)

# 添加所有测试源文件
#file(GLOB TEST_SOURCES "*.cpp")

# 为每个测试源文件创建一个可执行目标，并链接 GTest 和被测试的库
# 假设 TEST_SOURCES 已经包含所有测试源文件
# 例如：
set(TEST_SOURCES TestMain.cpp TestBinaryTricky.cpp)

# 创建一个单一的可执行文件，将所有测试源文件包含进去
add_executable(AllTests ${TEST_SOURCES})

# 设置包含路径
target_include_directories(AllTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# 链接 GTest 和其他必要的库
target_link_libraries(AllTests PRIVATE GTest::gtest_main NumericalRecipesLibs)

# 启用测试
enable_testing()

# 将单一的可执行文件作为一个测试添加
add_test(NAME AllTests COMMAND AllTests)

