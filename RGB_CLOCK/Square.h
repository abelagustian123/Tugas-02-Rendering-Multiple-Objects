#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Square
{
    //5
public:
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Square();
    void setColor(glm::vec4 newColor);
    glm::vec4 getColor();
    glm::mat4x4 getTransformationMat4x4();

    void setTranslation(glm::vec3 newTranslation);
    void setTranslation(float transX, float transY, float transZ);
    void setScale(float scaleX, float scaleY, float scaleZ);

    void setRotation(float angle, glm::vec3 axis);
    void setScale(glm::vec3 newScale);

    void draw();

private:
    //1
    float vertices[16] = {
       -0.2, 0.9, 0.0f, 0.0f,
       -0.2f, 0.6f, 0.0f, 1.0f,
       0.2f, 0.6f, 1.0f, 1.0f,
       0.2f, 0.9f, 1.0f, 0.0f
    };

    unsigned int indexArr[6] = {
        0,1,2,
        0,2,3
    };

    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    glm::mat4x4 transformationMat4x4 = glm::mat4x4(1.0f);

};

