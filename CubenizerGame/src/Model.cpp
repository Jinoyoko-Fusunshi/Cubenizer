#include <cstdlib>
#include "Model.hpp"
#include "VertexData.hpp"
#include "Camera.hpp"

Model::Model(Vector3F position, GeometryMesh &geometry_object_reference, ShaderProgram &shader_reference, Texture &texture_reference)
    : position(position), geometry(geometry_object_reference), shader(shader_reference), texture(texture_reference) {
    uint8_t r = random() % 255u;
    uint8_t g = random() % 255u;
    uint8_t b = random() % 255u;

    this->color = Vector3F((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f);
}

void Model::UpdateModelMatrix() {
    shader.SetMatrix4fUniformData("model_matrix", GetModelMatrix());
}

void Model::UpdateViewMatrix(const Matrix4F &view_matrix_reference) {
    shader.SetMatrix4fUniformData("view_matrix", view_matrix_reference);
}

void Model::UpdateProjectionMatrix(const Matrix4F &projection_matrix_reference) {
    shader.SetMatrix4fUniformData("projection", projection_matrix_reference);
}

void Model::UpdateColor() {
    shader.SetVector3fUniformData("model_color", color);
}

void Model::UpdateFaces(const int* face_ids, const int face_length) {
    GLint id = glGetUniformLocation(shader.GetProgramID(), "neighbour_indices");
    glUseProgram(shader.GetProgramID());
    glUniform1iv(id, face_length, face_ids);
}

void Model::DrawModel() {
    glUseProgram(shader.GetProgramID());
    glBindVertexArray(geometry.GetVAO());
    glBindBuffer(GL_ARRAY_BUFFER, geometry.GetVBO());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry.GetEBO());
    glBindTexture(GL_TEXTURE_2D, texture.GetTextureID());

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(Vector3F)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(2 * sizeof(Vector3F)));
    glEnableVertexAttribArray(2);

    glDrawElements(GL_TRIANGLES, (GLint)geometry.GetIndicesSize(), GL_UNSIGNED_INT, nullptr);

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Matrix4F Model::GetModelMatrix() {
    auto screen_space_position = Camera::GetScreenTransformationMatrix() * Vector4F(position, 1.0);

    float elements[16] = {
        1.0, 0.0, 0.0, screen_space_position.GetX(),
        0.0, 1.0, 0.0, screen_space_position.GetY(),
        0.0, 0.0, 1.0, screen_space_position.GetZ(),
        0.0, 0.0, 0.0, 1.0,
    };

    return Matrix4F(elements);
}
