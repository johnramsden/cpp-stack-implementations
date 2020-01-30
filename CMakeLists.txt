cmake_minimum_required(VERSION 3.10)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stackprofile VecStack.h LinkedStack.h Stack.h DequeStack.h stackprofile.cpp)

enable_testing()

add_test(ProfileStack stackprofile)

# For gprof profiling
#target_compile_options(stackprofile PRIVATE -pg)
#target_link_options(stackprofile PRIVATE -pg)