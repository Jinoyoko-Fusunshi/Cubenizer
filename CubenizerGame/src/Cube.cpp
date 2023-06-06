#include "Cube.hpp"
#include "ComposedVertex.hpp"

void Cube::UpdateFaces(const int* face_ids) {
    shader.SetIntegerArray("neighbour_indices", face_ids, Cube::CubeFaceCount);
}

void Cube::DrawModel(const Matrix4F &view_matrix_reference, const Matrix4F &projection_matrix_reference) {
    shader.SetMatrix4fUniformData("view_matrix", view_matrix_reference);
    shader.SetMatrix4fUniformData("projection", projection_matrix_reference);
    shader.SetMatrix4fUniformData("model_matrix", GetModelMatrix());

    glUseProgram(shader.GetProgramID());
    glBindVertexArray(mesh.GetVertexArrayID());
    glBindBuffer(GL_ARRAY_BUFFER, mesh.GetVertexBufferID());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.GetElementBufferID());
    glBindTexture(GL_TEXTURE_2D, texture.GetTextureID());

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)(sizeof(Vector3F)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ComposedVertex), (void*)(2 * sizeof(Vector3F)));
    glEnableVertexAttribArray(2);

    glDrawElements(GL_TRIANGLES, (GLint)mesh.GetIndicesSize(), GL_UNSIGNED_INT, nullptr);

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}