#ifndef DRAW_H
#define DRAW_H
#include <vector>
#include <QOpenGLShaderProgram>
#include <math.h>
#include "object3d.h"
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

#ifndef ORTHO_DIST
#    define ORTHO_DIST 2.0f
#endif


class Draw
{
    public:
        Draw( QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr, int LmodelViewMatrix);
        void addSphereR(float radius = 0.5, unsigned int tessellation = 36);
        void addConeR(float radius  = 0.5 , float height = 1, unsigned int tessellation  = 36);
        void addCylinderR(float radius  = 0.5 , float height = 1, unsigned int tessellation  = 36);

        void deleteObject(int index);
        int count();
        float dist(std::vector<float> points);
        float angle(std::vector<float> points);
        void Paint( int index = -1);
        void setHeight(unsigned int );
        void setWidth(unsigned int );
        std::vector<Object3D> objects;
        std::vector<float>selectedColor;
        std::vector< QMatrix4x4 > transformations;


   private:

        std::vector< std::vector<float> > vertices;
        std::vector< std::vector<float> > colors;
        std::vector< std::vector<float> > frame_colors;


        QOpenGLShaderProgram *shader_program;

        int vertexAttr;
        int colorAttr;
        int countAttr;
        int modelViewMatrix;
        int Width;
        int Height;




};

#endif // DRAW_H
