add_library (Cbuf INTERFACE)
target_include_directories(Cbuf INTERFACE .)
add_executable (demo main.cpp)
target_link_libraries (demo Cbuf)