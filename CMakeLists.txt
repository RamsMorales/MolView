cmake_minimum_required(VERSION 3.10)
project(MolView)

set(CMAKE_CXX_STANDARD 17)

# Add Eigen (header-only)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# macOS-specific handling
if(APPLE)
    # Force FreeGLUT paths explicitly
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)

    # Add source files
    add_executable(MolView src/main.cpp)

    # Link explicitly to FreeGLUT and OpenGL
    target_link_libraries(MolView
        /opt/homebrew/lib/libglut.dylib
        /System/Library/Frameworks/OpenGL.framework
    )
else()
    # Use default detection for Linux/Windows
    find_package(GLUT REQUIRED)
    find_package(OpenGL REQUIRED)

    # Add source files
    add_executable(MolView src/main.cpp)

    # Link dynamically
    target_link_libraries(MolView GLUT OpenGL)
endif()
