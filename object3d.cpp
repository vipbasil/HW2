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

    result.translate(this->TranslationX, this->TranslationY, this->TranslationZ);

    result.rotate(this->RotationX, 1, 0, 0);
    result.rotate(this->RotationY, 0, 1, 0);
    result.rotate(this->RotationZ, 0, 0, 1);

    result.scale(this->ScaleX, this->ScaleY, this->ScaleZ);



    return result;


}

void Object3D::set_color(float R, float G, float B)
{
    unsigned int array_length = this->vertices.size();

    unsigned int i = 0;
    while (i < array_length){
        this->colors[i + 0] = R;
        this->colors[i + 1] = G;
        this->colors[i + 2] = B;

        this->frame_colors[i + 0] = R * 0.9f;
        this->frame_colors[i + 1] = G * 0.9f;
        this->frame_colors[i + 2] = B * 0.9f;
        i += 3;
    }

}

