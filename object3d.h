#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <vector>
#include <QOpenGLShaderProgram>


class Object3D
{
public:
    Object3D();
    std::vector<float> vertices;
    std::vector<float> colors;
    std::vector<float> frame_colors;
    QMatrix4x4 get_transformations();
    void set_color(float R, float G, float B);
    float RotationX, RotationY, RotationZ;
    float ScaleX, ScaleY, ScaleZ;
    float TranslationX, TranslationY, TranslationZ;

signals:

public slots:
};

#endif // OBJECT3D_H
