add_executable (BasicTest basicTest.cpp)
target_link_libraries (BasicTest Cbuf)

add_executable (DatatypeTest datatypeTest.cpp)
target_link_libraries (DatatypeTest Cbuf)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable (ThreadedTest threadedTest.cpp)
target_link_libraries(ThreadedTest PRIVATE Threads::Threads Cbuf)