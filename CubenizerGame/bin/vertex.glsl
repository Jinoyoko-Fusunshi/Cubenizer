#version 450

out vec3 vertices_out;
out vec3 normals_out;
out vec2 textures_out;
out vec3 model_color_out;

out mat4 camera_position_out;
out mat4 model_position_out;
out flat int neighbour_indices_out[6];
out flat int face_index_out;

layout (location = 0) in vec3 vertices;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 textures;

uniform vec3 model_color;
uniform int neighbour_indices[6];

uniform mat4 projection;
uniform mat4 camera_position;
uniform mat4 model_position;

const int VerticesPerFace = 4;

void main() {
    vertices_out = vertices;
    normals_out = normals;
    textures_out = textures;

    camera_position_out = camera_position;
    model_position_out = model_position;
    model_color_out = model_color;

    face_index_out = gl_VertexID / VerticesPerFace;
    neighbour_indices_out = neighbour_indices;

    gl_Position = projection * camera_position * model_position * vec4(vertices, 1.0);
}