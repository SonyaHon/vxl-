#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec3 inColor;

uniform mat4 transformMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 fragColor;

void main() {
    gl_Position = projectionMatrix * viewMatrix * transformMatrix * vec4(inPosition, 1.0);
    fragColor = inColor;
}
