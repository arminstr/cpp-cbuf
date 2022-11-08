add_executable (BasicTest basicTest.cpp)
target_link_libraries (BasicTest Cbuf)

add_executable (DatatypeTest datatypeTest.cpp)
target_link_libraries (DatatypeTest Cbuf)

add_executable (ThreadedTest threadedTest.cpp)
target_link_libraries (ThreadedTest Cbuf)