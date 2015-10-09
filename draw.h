#ifndef DRAW_H
#define DRAW_H
#include <vector>
#include <QOpenGLShaderProgram>
#include <math.h>



class Draw
{
    public:
        Draw( QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr, int LmodelViewMatrix);
        void addSphereR(std::vector<float> point, std::vector<float> color, float radius = 0.5, unsigned int tessellation = 36);

        void deleteObject(int index);
        int count();
        float dist(std::vector<float> points);
        float angle(std::vector<float> points);
        void Paint( int index = -1);
        void setHeight(unsigned int );
        void setWidth(unsigned int );


   private:

        std::vector< std::vector<float> > vertices;
        std::vector< std::vector<float> > colors;
        std::vector< std::vector<float> > frame_colors;
        std::vector< QMatrix4x4 > transformations;

        QOpenGLShaderProgram *shader_program;

        int vertexAttr;
        int colorAttr;
        int countAttr;
        int modelViewMatrix;
        int Width;
        int Height;




};

#endif // DRAW_H
