#version 450

out vec4 color;

in vec3 vertices_out;
in vec3 normals_out;
in vec2 textures_out;

in mat4 camera_position_out;
in mat4 model_position_out;
in vec3 model_color_out;
in flat int neighbour_indices_out[6];
in flat int face_index_out;

uniform sampler2D model_texture;

void main() {
    if (neighbour_indices_out[face_index_out] == 1)
        discard;

    const vec3 LightPosition = vec3(10.0, 4.0, -10.0);
    const vec3 LightColor = vec3(0.5, 0.5, 0.5);
    const vec3 AmbientColor = vec3(0.9, 0.9, 0.9);
    const float AmbientStrength = 0.2;
    const float SpecularStrength = 0.5;

    vec3 translated_vertex = (vec4(vertices_out, 1.0) * model_position_out).xyz;
    vec3 normal = normalize(normals_out);

    vec3 ambient_color = AmbientColor * AmbientStrength;
    vec3 light_direction = normalize(translated_vertex - LightPosition);
    float light_difference = max(dot(normal, -light_direction), 0.0);
    vec3 diffuse_color = light_difference * LightColor;

    vec3 view_direction = normalize(translated_vertex - (vec4(1.0) * camera_position_out).xyz);
    vec3 reflected_direction = reflect(-light_direction, normal);
    float light_dot_product = max(dot(view_direction, reflected_direction), 0.0);
    float specular_factor = pow(light_dot_product, 32.0);
    vec3 specular_color = SpecularStrength * specular_factor * LightColor;

    vec3 color_result = (specular_color + ambient_color + diffuse_color);

    color = vec4(0.0,1.0,0.0, 1.0);
}