cmake_minimum_required(VERSION 3.17)
project(vxl__)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(vxl__ src/main.cpp src/settings/window-settings.h src/shader/Shader.h src/components/MeshData.h src/components/Transform.h)

target_link_libraries(vxl__ PRIVATE glfw)
target_link_libraries(vxl__ PRIVATE GLEW::GLEW)
target_link_libraries(vxl__ PRIVATE glm)