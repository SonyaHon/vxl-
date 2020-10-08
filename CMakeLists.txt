cmake_minimum_required(VERSION 3.17)
project(vxl__)

set(CMAKE_CXX_STANDARD 17)
if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
endif ()

find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

set(SOURCE_FILES src/main.cpp src/settings/window-settings.h src/d3/MeshData.h src/d3/MeshData.cpp src/d3/Transform.cpp src/d3/Transform.h src/shader/Shader.cpp src/shader/Shader.h src/utils/FileLoader.cpp src/utils/FileLoader.h src/d3/Camera.cpp src/d3/Camera.h src/game/controllers/FreeCameraController.cpp src/game/controllers/FreeCameraController.h src/d3/Mesh.cpp src/d3/Mesh.h src/game/primitive.h src/game/world/World.cpp src/game/world/World.h src/game/world/generation/Chunk.cpp src/game/world/generation/Chunk.h src/game/player/Player.cpp src/game/player/Player.h src/game/controllers/PlayerController.cpp src/game/controllers/PlayerController.h src/game/controllers/BindedCameraController.cpp src/game/controllers/BindedCameraController.h src/d3/GameObject.cpp src/d3/GameObject.h src/d3/Material.cpp src/d3/Material.h src/light/DirectionalLight.cpp src/light/DirectionalLight.h src/light/SpotLight.cpp src/light/SpotLight.h src/light/AmbientLight.cpp src/light/AmbientLight.h src/d3/Scene.cpp src/d3/Scene.h)
add_executable(vxl__ ${SOURCE_FILES})
target_link_libraries(vxl__ PRIVATE glfw)
target_link_libraries(vxl__ PRIVATE GLEW::GLEW)
target_link_libraries(vxl__ PRIVATE glm)