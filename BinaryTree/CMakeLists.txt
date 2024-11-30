# 设置输出可执行文件的目录
 set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

# 收集源代码文件
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# 包含头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加可执行文件目标
add_executable(test01 ${SRC})

# 如果 CMake 版本大于 3.12，设置 C++ 标准为 C++20
if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.12)
  set_property(TARGET test01 PROPERTY CXX_STANDARD 20)
endif()

