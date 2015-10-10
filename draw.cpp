#include "draw.h"

Draw::Draw(QOpenGLShaderProgram *program, int LvertexAttr, int LcolorAttr, int LmodelViewMatrix):
shader_program(program),
vertexAttr(LvertexAttr),
colorAttr(LcolorAttr),
modelViewMatrix(LmodelViewMatrix)
{
    countAttr = 0;
    selectedColor.resize(3);
    selectedColor[0] = 0.9f;
    selectedColor[1] = 0.9f;
    selectedColor[2] = 0.9f;
}


void Draw::addSphereR( float radius, unsigned int tessellation)
{
    //prepare afine transformation
    Object3D obj;

    /*QMatrix4x4 matrix;
    matrix.setToIdentity();
    transformations.push_back(matrix);
    */


    unsigned int i = 0;
    float alpha = 0.0f;
    float theta = 0.0f;
    float step = 360 / tessellation;
      for (alpha = step; alpha < 360; alpha += step ){
        for (theta = step; theta < 360; theta += step ){

          obj.vertices.push_back(radius * sin(alpha * M_PI / 180) * cos(theta * M_PI / 180));
          obj.vertices.push_back(radius * cos(alpha * M_PI / 180));
          obj.vertices.push_back(radius * sin(alpha * M_PI / 180) * sin(theta * M_PI / 180));

          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * cos(theta * M_PI / 180));
          obj.vertices.push_back(radius * cos((alpha - step) * M_PI / 180));
          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * sin(theta * M_PI / 180));

          obj.vertices.push_back(radius * sin((alpha) * M_PI / 180) * cos((theta - step) * M_PI / 180));
          obj.vertices.push_back(radius * cos((alpha) * M_PI / 180));
          obj.vertices.push_back(radius * sin((alpha) * M_PI / 180) * sin((theta - step) * M_PI / 180));

          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * cos(theta * M_PI / 180));
          obj.vertices.push_back(radius * cos((alpha - step) * M_PI / 180));
          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * sin(theta * M_PI / 180));

          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * cos((theta - step )* M_PI / 180));
          obj.vertices.push_back(radius * cos((alpha - step) * M_PI / 180));
          obj.vertices.push_back(radius * sin((alpha - step) * M_PI / 180) * sin((theta - step) * M_PI / 180));


          obj.vertices.push_back(radius * sin((alpha) * M_PI / 180) * cos((theta - step) * M_PI / 180));
          obj.vertices.push_back(radius * cos((alpha) * M_PI / 180));
          obj.vertices.push_back(radius * sin((alpha) * M_PI / 180) * sin((theta - step) * M_PI / 180));

        }
      }


    //prepare colors array

    unsigned int array_length = obj.vertices.size();
    obj.colors.resize(array_length);
    obj.frame_colors.resize(array_length);
    i = 0;
    while (i < array_length){
        obj.colors[i + 0] = selectedColor[0];
        obj.colors[i + 1] = selectedColor[1];
        obj.colors[i + 2] = selectedColor[2];

        obj.frame_colors[i + 0] = selectedColor[0] * 0.9f;
        obj.frame_colors[i + 1] = selectedColor[1] * 0.9f;
        obj.frame_colors[i + 2] = selectedColor[2] * 0.9f;
        i += 3;
    }
    objects.push_back(obj);

}
void Draw::addConeR(float radius, float height, unsigned int tessellation)
{
    //prepare afine transformation

    QMatrix4x4 matrix;
    matrix.setToIdentity();
    transformations.push_back(matrix);

    unsigned int i = 0;
    std::vector<float> local_vertices;
    /*
    Students work
    1. Add the cone's triangles
    2. Add the base's triangles
     */


    vertices.push_back(local_vertices);

    //prepare colors array
    std::vector<float> allcolor;
    std::vector<float> allframe_color;
    unsigned int array_length = local_vertices.size();
    allcolor.resize(array_length);
    allframe_color.resize(array_length);
    i = 0;
    while (i < array_length){
        allcolor[i + 0] = selectedColor[0];
        allcolor[i + 1] = selectedColor[1];
        allcolor[i + 2] = selectedColor[2];

        allframe_color[i + 0] = selectedColor[0] * 0.9f;
        allframe_color[i + 1] = selectedColor[1] * 0.9f;
        allframe_color[i + 2] = selectedColor[2] * 0.9f;
        i += 3;
    }
    colors.push_back(allcolor);
    frame_colors.push_back(allframe_color);


}
void Draw::deleteObject(int index)
{
    vertices.erase(vertices.begin() + index);
}

float Draw::dist(std::vector<float> points)
{
    //this function return the distance between two points
    return sqrt(powl(points[0] - points[3], 2) + powl(points[1] - points[4], 2) + powl(points[2] - points[5], 2));
}

float Draw::angle(std::vector<float> points)
{
    //this function return the angle of a vector between two points
    return atan2(points[4] - points[1], points[3] - points[0]);
}

void Draw::Paint(int index)
{
    if( index == -1)
        for (unsigned  int i = 0; i < objects.size(); i++)   {

            shader_program->setAttributeArray(vertexAttr, objects[i].vertices.data(), 3);
            shader_program->setAttributeArray(colorAttr, objects[i].colors.data(), 3);
            shader_program->setUniformValue(modelViewMatrix,objects[i].get_transformations());

            shader_program->enableAttributeArray(vertexAttr);
            shader_program->enableAttributeArray(colorAttr);

            glDrawArrays(GL_TRIANGLES, 0, objects[i].vertices.size() / 3);

            shader_program->disableAttributeArray(vertexAttr);
            shader_program->disableAttributeArray(colorAttr);

            shader_program->setAttributeArray(vertexAttr, objects[i].vertices.data(), 3);
            shader_program->setAttributeArray(colorAttr, objects[i].frame_colors.data(), 3);

            shader_program->enableAttributeArray(vertexAttr);
            shader_program->enableAttributeArray(colorAttr);

            glDrawArrays(GL_LINE_LOOP, 0, objects[i].vertices.size() / 3);

            shader_program->disableAttributeArray(vertexAttr);
            shader_program->disableAttributeArray(colorAttr);

        }


}

void Draw::setHeight(unsigned int h)
{
    Height  = h;
}

void Draw::setWidth(unsigned int w)
{
    Width = w;
}

