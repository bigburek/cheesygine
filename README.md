### Cheesygine

A simple OpenGL C++ application/engine. This project is created with the help of The Cherno's YouTube tutorials. It's a great starting point for learning OpenGL and game engine basics.  
Prerequisites

To build and run Cheesygine, you will need the following:

    C++17 or later
    Premake (for build configuration)
    OpenGL libraries (included in the project files):
        GLFW
        GLEW

#### Linux

Setup: Run the Setup-Linux.sh script to configure Premake and generate the Makefile:

    ./Setup-Linux.sh

Build: Compile the project using make:

    make

#### Windows

Premake is not yet fully functional on Windows, so building on this platform is not supported at the moment.  

#### Next Steps

Implementing batch rendering. Currently, each object triggers a separate draw call, which is inefficient.
