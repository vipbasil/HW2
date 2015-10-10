#include "object3d.h"

Object3D::Object3D()
{
    this->ScaleX = 1;
    this->ScaleY = 1;
    this->ScaleZ = 1;

    this->TranslationX = 0;
    this->TranslationY = 0;
    this->TranslationZ = 0;

    this->RotationX = 0;
    this->RotationY = 0;
    this->RotationZ = 0;
}

QMatrix4x4 Object3D::get_transformations()
{
    QMatrix4x4 result;
    result.setToIdentity();

    result.scale(this->ScaleX, this->ScaleY, this->ScaleZ);

    result.rotate(this->RotationX, 1, 0, 0);
    result.rotate(this->RotationY, 0, 1, 0);
    result.rotate(this->RotationZ, 0, 0, 1);

    result.translate(this->TranslationX, this->TranslationY, this->TranslationZ);

    return result;


}

