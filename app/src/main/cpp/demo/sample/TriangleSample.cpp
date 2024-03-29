//
// Created by zhangyelei on 2024/1/26.
//

#include "TriangleSample.h"

TriangleSample::TriangleSample() {

}

TriangleSample::~TriangleSample() {
    if (m_ProgramObj) {
        glDeleteProgram(m_ProgramObj);
    }
}

void TriangleSample::init() {
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec4 vPosition;  \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vPosition;              \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
            "}                                            \n";

    m_ProgramObj = GLUtils::CreateProgram(vShaderStr, fShaderStr, m_VertexShader, m_FragmentShader);
}

void TriangleSample::draw() {
    // 定义了三个顶点的坐标。每个顶点包含三个浮点数，分别表示 x、y、z 坐标。
    GLfloat  vVertices[] = {
            0.0f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
    };
    // 如果为 0，表示没有有效的 OpenGL 着色器程序对象
    if (m_ProgramObj == 0) {
        return;
    }
    glUseProgram(m_ProgramObj);
    // 配置顶点属性。在这里，它指定了顶点属性索引为 0（因为参数为 0），
    // 包含三个浮点数（size 参数为 3），每个浮点数占用 4 个字节（type 参数为 GL_FLOAT），
    // 不需要进行归一化处理（normalized 参数为 GL_FALSE），
    // 顶点数组中相邻两个顶点的间隔为 0（stride 参数为 0），
    // 并且使用的是顶点数组 vVertices。
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    // 启用顶点属性数组。这是因为在默认情况下，
    // OpenGL 是不会使用顶点属性数组的，必须启用相应的顶点属性数组才能让 OpenGL 使用它们。
    glEnableVertexAttribArray(0);
    // 它告诉 OpenGL 画一个三角形，从顶点数组的第一个顶点开始（0），画三个顶点。
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
