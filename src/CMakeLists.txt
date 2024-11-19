# 设置源文件目录
#file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# 将文件打包为库
#add_library(NumericalRecipesLibs STATIC ${SOURCES} ${HEADERS})
add_library(NumericalRecipesLibs STATIC
        calendar.cpp
        BinaryTricky.cpp BinaryTricky.h
)
