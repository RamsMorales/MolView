cmake_minimum_required(VERSION 3.10)
project(MolView)

set(CMAKE_CXX_STANDARD 17)

# Add Eigen (header-only)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# Add FreeGLUT and OpenGL
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# Link libraries
target_link_libraries(MolView GLUT::GLUT OpenGL::GL)

# Add source files
add_executable(MolView src/main.cpp)