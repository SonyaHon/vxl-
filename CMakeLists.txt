cmake_minimum_required(VERSION 3.17)
project(vxl__)

set(CMAKE_CXX_STANDARD 17)
if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
endif ()

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

set(SOURCE_FILES src/main.cpp src/settings/window-settings.h src/d3/MeshData.h src/d3/MeshData.cpp src/d3/Transform.cpp src/d3/Transform.h src/shader/Shader.cpp src/shader/Shader.h src/utils/FileLoader.cpp src/utils/FileLoader.h src/d3/Camera.cpp src/d3/Camera.h)
add_executable(vxl__ ${SOURCE_FILES})
target_link_libraries(vxl__ PRIVATE glfw)
target_link_libraries(vxl__ PRIVATE GLEW::GLEW)
target_link_libraries(vxl__ PRIVATE glm)