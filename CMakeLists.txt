cmake_minimum_required(VERSION 3.17)
project(vxl__)

set(CMAKE_CXX_STANDARD 17)
if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
endif ()

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(vxl__ src/main.cpp src/settings/window-settings.h src/shader/Shader.h src/components/Transform.h src/d3/MeshData.h src/d3/MeshData.cpp src/d3/Transform.cpp src/d3/Transform.h)
target_link_libraries(vxl__ PRIVATE glfw)
target_link_libraries(vxl__ PRIVATE GLEW::GLEW)
target_link_libraries(vxl__ PRIVATE glm)