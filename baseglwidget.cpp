#include "baseglwidget.h"

BaseGLWidget::BaseGLWidget(QWidget *parent):QOpenGLWidget(parent){

}

void BaseGLWidget::initializeGL(){

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);


    //shaders link
    QOpenGLShader vShader(QOpenGLShader::Vertex);
    vShader.compileSourceFile(":/files/Shaders/vShader.glsl");


    QOpenGLShader fShader(QOpenGLShader::Fragment);
    fShader.compileSourceFile(":/files/Shaders/fShader.glsl");

    glClearDepth(1.0f);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    shader_program.addShader(&vShader);
    shader_program.addShader(&fShader);

    if(!shader_program.link()){
        qWarning("Can't link the shader program");
    }

    vertexAttr = shader_program.attributeLocation("vertexAttr");
    colorAttr = shader_program.attributeLocation("colorAttr");
    matrixUniform = shader_program.uniformLocation("projection");
    modelViewMatrix = shader_program.uniformLocation("modelView");

    pen = new Draw(&shader_program, vertexAttr, colorAttr, modelViewMatrix);


}

void BaseGLWidget::paintGL(){


    if(!shader_program.bind())
        return;

    //translate the camera away
    QMatrix4x4 matrix;
    matrix.ortho( -ORTHO_DIST, ORTHO_DIST, -ORTHO_DIST, ORTHO_DIST, ORTHO_DIST, -ORTHO_DIST);
    shader_program.setUniformValue(matrixUniform, matrix);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pen->Paint();
    //release the  binded shader program
    shader_program.release();

}

void BaseGLWidget::resizeGL(int width, int height){
    glViewport(0, 0, width, height);
    //translate the camera away
    QMatrix4x4 matrix;
    matrix.ortho( -ORTHO_DIST, ORTHO_DIST, -ORTHO_DIST, ORTHO_DIST, ORTHO_DIST, -ORTHO_DIST);

    shader_program.setUniformValue(matrixUniform, matrix);
    pen->setHeight(height);
    pen->setWidth(width);

}

