#include "Camera.h"

void TranslateCamera(Camera *camera_reference, Vector3f translation_vector) {
    AddToVector(&camera_reference->position, translation_vector);
}