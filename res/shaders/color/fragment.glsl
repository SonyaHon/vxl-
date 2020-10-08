#version 330 core

in vec3 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

uniform float ambientStrength;
uniform vec3 ambientColor;

uniform vec3 directionalDirection;
uniform vec3 directionalColor;
uniform float directionalStrength;

out vec4 outColor;

void main() {
    // ambient light
    vec3 ambient = ambientColor * ambientStrength;

    // diffuse light
    float difference = max(dot(normalize(fragNormal), normalize(-directionalDirection)), 0.0);
    vec3 diffuse = directionalColor * directionalStrength * difference;

    vec3 result = (ambient + diffuse) * fragColor;
    outColor = vec4(result, 1.0);
}
