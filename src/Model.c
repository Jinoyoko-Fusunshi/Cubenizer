#include <stdlib.h>
#include "Model.h"
#include "Geometry.h"
#include "Rendering.h"

Model* CreateModel(GeometryObject *object_reference_reference, GLuint program_id, Vector3f position) {
    ShaderProgram program = {
        .program_id = program_id,
    };

    Model *model = (Model*)malloc(1 * sizeof(Model));
    model->position = position;
    model->shader = program;
    model->geometry = object_reference_reference;

    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;

    Vector3f color = {(float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f};
    model->color = color;

    return model;
}

void UpdateProjectionMatrix(Model* model_reference, Matrix4f* projection_matrix) {
    SetMatrix4fUniformData(model_reference->shader.program_id, "projection", projection_matrix);
}

void UpdateModelPosition(Model* model_reference) {
    SetVector3fUniformData(model_reference->shader.program_id, "model_position", &model_reference->position);
}

void UpdateCameraPosition(Model* model_reference, Vector3f cam_position) {
    SetVector3fUniformData(model_reference->shader.program_id, "camera_position", &cam_position);
}

void UpdateColor(Model* model_reference, Vector3f color) {
    SetVector3fUniformData(model_reference->shader.program_id, "model_color", &color);
}

void UpdateFaces(Model* model_reference, int* face_ids, int face_length) {
    GLint id = glGetUniformLocation(model_reference->shader.program_id, "neighbour_indices");
    glUseProgram(model_reference->shader.program_id);
    glUniform1iv(id, face_length, face_ids);
}

void DrawModel(Model *model_reference) {
    glUseProgram(model_reference->shader.program_id);
    glBindVertexArray(model_reference->geometry->vao_id);
    glBindBuffer(GL_ARRAY_BUFFER, model_reference->geometry->vbo_id);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(Vector3f)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, (GLint)model_reference->geometry->vertices_length);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}