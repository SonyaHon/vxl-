#version 330 core

in vec2 fragUV;
in vec3 fragPosition;
in vec3 fragNormal;

uniform float ambientStrength;
uniform vec3 ambientColor;

uniform vec3 directionalDirection;
uniform vec3 directionalColor;
uniform float directionalStrength;

uniform float specularStrength;
uniform float specularSharpness;
uniform vec3 specularColor;

uniform vec3 cameraPos;

uniform sampler2D textureSampler;

out vec4 outColor;

void main() {
    // ambient light
    vec3 ambient = ambientColor * ambientStrength;

    // diffuse light
    float difference = max(dot(normalize(fragNormal), normalize(-directionalDirection)), 0.0);
    vec3 diffuse = directionalColor * directionalStrength * difference;

    //specular light
    vec3 viewDir = normalize(cameraPos - fragPosition);
    vec3 reflectDir = reflect(normalize(-directionalDirection), fragNormal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), specularSharpness);
    vec3 specular = specularStrength * spec * specularColor;

//    vec3 result = (ambient + diffuse + specular) * vec3(texture(textureSampler, fragUV).r);
    outColor = vec4(vec3(texture(textureSampler, fragUV).r), 1.0);
}
