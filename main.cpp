

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

constexpr int width = 640;
constexpr int height = 480;

GLFWwindow *window = nullptr;

void main_loop( )
{
    // main loop
    glfwSwapBuffers( window );
    glfwPollEvents( );
}

int main( )
{
    if ( !glfwInit( ) )
        return 1;

    window = glfwCreateWindow( width, height, "Simple example", NULL, NULL );
    if ( !window )
    {
        glfwTerminate( );
        return 1;
    }
    glfwMakeContextCurrent( window );

#ifndef __EMSCRIPTEN__
    gladLoadGL( );
#endif

    glfwSwapInterval( 1 );

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop( main_loop, 0, true );
#else
    while ( !glfwWindowShouldClose( window ) )
        main_loop( );
#endif

    glfwDestroyWindow( window );
    glfwTerminate( );
    return 0;
}