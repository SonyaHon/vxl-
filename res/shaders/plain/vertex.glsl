#version 330 core

layout (location = 0) in vec3 inPosition;

uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main() {
    gl_Position = projectionMatrix * viewMatrix * transformMatrix * vec4(inPosition, 1.0);
}
