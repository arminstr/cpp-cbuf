![cmake workflow](https://github.com/arminstr/cpp-cbuf/actions/workflows/cmake.yml/badge.svg)
# Circular Buffer Implementation in C++

## Main Design Decisions
 * As few dependencies as possible.
 * Template class to allow storage of different data types.
 * Mutex locking for threaded push and pop access.
 * Basic testing using ctest and custom executables. 
