#include <cstdlib>
#include "Model.hpp"
#include "Rendering.hpp"
#include "VertexData.hpp"

Model::Model(Vector3F position, GeometryMesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference)
    : position(position), geometry(geometry_object_reference), shader(shader_reference), texture(texture_reference) {
    uint8_t r = random() % 255u;
    uint8_t g = random() % 255u;
    uint8_t b = random() % 255u;

    this->color = Vector3F((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f);
}

void Model::UpdateProjectionMatrix(Matrix4F &projection_matrix) {
    SetMatrix4fUniformData(shader.GetProgramID(), "projection", projection_matrix);
}

void Model::UpdateModelPosition() {
    SetVector3fUniformData(shader.GetProgramID(), "model_position", position);
}

void Model::UpdateCameraPosition(Vector3F &cam_position) {
    SetVector3fUniformData(shader.GetProgramID(), "camera_position", cam_position);
}

void Model::UpdateColor(Vector3F &color) {
    SetVector3fUniformData(shader.GetProgramID(), "model_color", color);
}

void Model::UpdateFaces(int* face_ids, int face_length) {
    GLint id = glGetUniformLocation(shader.GetProgramID(), "neighbour_indices");
    glUseProgram(shader.GetProgramID());
    glUniform1iv(id, face_length, face_ids);
}

void Model::DrawModel() {
    glUseProgram(shader.GetProgramID());
    glBindVertexArray(geometry.GetVAO());
    glBindBuffer(GL_ARRAY_BUFFER, geometry.GetVBO());
    glBindTexture(GL_TEXTURE_2D, texture.GetTextureID());

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(Vector3F)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(2 * sizeof(Vector3F)));
    glEnableVertexAttribArray(2);

    glDrawArrays(GL_TRIANGLES, 0, (GLint)geometry.GetVerticesSize());

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}