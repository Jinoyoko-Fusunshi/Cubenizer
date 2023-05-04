#include <cstdlib>
#include "Model.hpp"
#include "Geometry.hpp"
#include "Rendering.hpp"

Model::Model(GeometryObject &geometry_object_reference, ShaderProgram shader_program, Vector3F position) {
    uint8_t r = random() % 255u;
    uint8_t g = random() % 255u;
    uint8_t b = random() % 255u;

    Vector3F color(r / 255.0, g / 255.0, b / 255.0);

    this->position = position;
    this->geometry = geometry_object_reference;
    this->shader = shader_program;
    this->color = color;
}

void Model::UpdateProjectionMatrix(Matrix4F &projection_matrix) {
    SetMatrix4fUniformData(shader.program_id, "projection", projection_matrix);
}

void Model::UpdateModelPosition() {
    SetVector3fUniformData(shader.program_id, "model_position", position);
}

void Model::UpdateCameraPosition(Vector3F &cam_position) {
    SetVector3fUniformData(shader.program_id, "camera_position", cam_position);
}

void Model::UpdateColor(Vector3F &color) {
    SetVector3fUniformData(shader.program_id, "model_color", color);
}

void Model::UpdateFaces(int* face_ids, int face_length) {
    GLint id = glGetUniformLocation(shader.program_id, "neighbour_indices");
    glUseProgram(shader.program_id);
    glUniform1iv(id, face_length, face_ids);
}

void Model::DrawModel() {
    glUseProgram(shader.program_id);
    glBindVertexArray(geometry.GetVAO());
    glBindBuffer(GL_ARRAY_BUFFER, geometry.GetVBO());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(Vector3F)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, (GLint)geometry.GetVerticesSize());
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}