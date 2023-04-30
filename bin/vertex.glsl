#version 450

out vec3 vertex_out;
out vec3 normals_out;
out vec3 camera_position_out;
out vec3 model_position_out;
out vec3 model_color_out;
out flat int neighbour_indices_out[6];
out flat int face_index_out;

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normals;

uniform mat4 projection;
uniform vec3 camera_position;
uniform vec3 model_position;
uniform vec3 model_color;
uniform int neighbour_indices[6];

void main() {
    vertex_out = vertex;
    normals_out = normals;
    camera_position_out = camera_position;
    model_position_out = model_position;
    model_color_out = model_color;

    face_index_out = gl_VertexID / 6;
    neighbour_indices_out = neighbour_indices;

    gl_Position = projection * vec4(vertex + model_position - camera_position, 1.0);
}