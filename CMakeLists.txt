cmake_minimum_required(VERSION 3.21)
project(skia-glfw-app)

find_package(unofficial-skia CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp)

if (EMSCRIPTEN)
    message("using emscripten")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
else ()
    find_package(glad CONFIG REQUIRED)
    find_package(glfw3 CONFIG REQUIRED)

    target_link_libraries(app PRIVATE glad::glad glfw)
endif ()

target_link_libraries(app PRIVATE unofficial::skia::skia)
