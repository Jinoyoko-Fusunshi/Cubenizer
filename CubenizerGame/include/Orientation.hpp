#pragma once

#include <Vector4.hpp>
#include <Matrix4.hpp>

class Orientation {
private:
    Matrix4F position_translation = Matrix4F::IdentityMatrix();
    Matrix4F yaw_rotation = Matrix4F::IdentityMatrix();
    Matrix4F pitch_rotation = Matrix4F::IdentityMatrix();
    Matrix4F roll_rotation = Matrix4F::IdentityMatrix();

public:
    Orientation() = default;
    ~Orientation() = default;

    void SetTranslation(Vector3F position) { position_translation = Matrix4F::TranslationMatrix(position); }
    void SetYawRotation(FDegree angle) { yaw_rotation = Matrix4F::YRotationMatrix(angle); }
    void SetPitchRotation(FDegree angle) { pitch_rotation = Matrix4F::XRotationMatrix(angle); }
    void SetRollRotation(FDegree angle) { roll_rotation = Matrix4F::ZRotationMatrix(angle); }

    Matrix4F GetTranslation() { return position_translation; }
    Matrix4F GetYawRotation() { return yaw_rotation; }
    Matrix4F GetPitchRotation() { return pitch_rotation; }
    Matrix4F GetRollRotation() { return roll_rotation; }
    Matrix4F GetRotation() { return pitch_rotation * yaw_rotation * roll_rotation; }
    Matrix4F GetTransformation();
    Vector3F GetRightDirection() { return GetRotation() * Vector4F::XUnitVector4() * -1.0f; }
    Vector3F GetTopDirection() { return GetRotation() * Vector4F::YUnitVector4() * -1.0f; }
    Vector3F GetLookDirection() { return GetRotation() * Vector4F::ZUnitVector4() * -1.0f; }
};
