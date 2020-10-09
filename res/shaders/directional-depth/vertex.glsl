#version 330 core

layout (location = 0) in vec3 inPosition;

uniform mat4 lightSpaceMatix;
uniform mat4 transfromMatrix;

void main() {
    gl_Position = lightSpaceMatix * transfromMatrix * vec4(inPosition, 1.0);
}
