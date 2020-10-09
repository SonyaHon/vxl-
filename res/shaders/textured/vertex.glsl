#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inUV;

uniform mat4 transformMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec2 fragUV;
out vec3 fragPosition;
out vec3 fragNormal;

void main() {
    vec4 worldPos = transformMatrix * vec4(inPosition, 1.0);
    gl_Position = projectionMatrix * viewMatrix * worldPos;

    fragUV = inUV;
    fragPosition = vec3(worldPos);
    fragNormal = mat3(transpose(inverse(transformMatrix))) * inNormal;
}
