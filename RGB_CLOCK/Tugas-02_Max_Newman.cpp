// TrianglesWithModernOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "util.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"

float currentTime = 0.0f;
float lastTime = 0.0f;
float deltaTime = 0.0f;

float speedUp = 4.0f;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Tugas 02 - Max Newman", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /*
        Dari kode diatas berfungsi membuat windows dengan kuran 640*480 dengan tulisan hello world
    */

    /* Make the window's context current */
    glfwMakeContextCurrent(window); //disini membuat contextnya yang artinya menjalankan windowsnya


    GLenum err = glewInit();
    //2
    
    //kepala
    Square s1;
    s1.setScale(0.8f, 0.8f, 1.0f);
    s1.setColor(glm::vec4(1.0f, 0.92f, 0.8f, 1.0f));

    //mata kiri
    Square s2;
    s2.setTranslation(-0.08f, 0.49f, 0.0f);
    s2.setScale(0.2f, 0.2f, 1.0f);
    s2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    //mata kanan
    Square s3;
    s3.setTranslation(0.08f, 0.49f, 0.0f);
    s3.setScale(0.2f, 0.2f, 1.0f);
    s3.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    //alis kiri
    Square s4;
    s4.setTranslation(-0.08f, 0.65f, 0.0f);
    s4.setScale(0.2f, 0.05f, 1.0f);
    s4.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    //alis kanan
    Square s5;
    s5.setTranslation(0.08f, 0.65f, 0.0f);
    s5.setScale(0.2f, 0.05f, 1.0f);
    s5.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    //Mulut
    Square s6;
    s6.setTranslation(0.0f, 0.49f, 0.0f);
    s6.setScale(0.2f, 0.05f, 1.0f);
    s6.setColor(glm::vec4(0.69f, 0.19f, 0.38f, 1.0f));

    Square s7;
    s7.setTranslation(-0.036f, 0.492f, 0.0f);
    s7.setScale(0.017f, 0.067f, 1.0f);
    s7.setColor(glm::vec4(0.69f, 0.19f, 0.38f, 1.0f));

    Square s8;
    s8.setTranslation(0.036f, 0.492f, 0.0f);
    s8.setScale(0.017f, 0.067f, 1.0f);
    s8.setColor(glm::vec4(0.69f, 0.19f, 0.38f, 1.0f));

    //Telinga kiri
    Square s9;
    s9.setTranslation(-0.17f, 0.41f, 0.0f);
    s9.setScale(0.05f, 0.27f, 1.0f);
    s9.setColor(glm::vec4(0.55f, 0.55f, 0.51f, 1.0f));

    //Telinga kanan
    Square s10;
    s10.setTranslation(0.17f, 0.41f, 0.0f);
    s10.setScale(0.05f, 0.27f, 1.0f);
    s10.setColor(glm::vec4(0.55f, 0.55f, 0.51f, 1.0f));

    //Leher
    Square s11;
    s11.setTranslation(0.0f, 0.338f, 0.0f);
    s11.setScale(0.26f, 0.16f, 1.0f);
    s11.setColor(glm::vec4(0.55f, 0.55f, 0.51f, 1.0f));

    //Badan
    Square s12;
    s12.setTranslation(0.0f, -0.82f, 0.0f);
    s12.setScale(0.8f, 1.4f, 1.0f);
    s12.setColor(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

    //Bahu kiri
    Square s13;
    s13.setTranslation(-0.2f, 0.1247f, 0.0f);
    s13.setScale(0.2f, 0.35f, 1.0f);
    s13.setColor(glm::vec4(0.55f, 0.55f, 0.51f, 1.0f));

    //Bahu kanan
    Square s14;
    s14.setTranslation(0.2f, 0.1247f, 0.0f);
    s14.setScale(0.2f, 0.35f, 1.0f);
    s14.setColor(glm::vec4(0.55f, 0.55f, 0.51f, 1.0f));

    //Lengan kiri
    Square s15;
    s15.setTranslation(-0.32f, 0.207f, 0.0f);
    s15.setScale(0.4f, 0.26f, 1.0f);
    s15.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));
    
    Square s16;
    s16.setTranslation(-0.36f, 0.19f, 0.0f);
    s16.setScale(0.2f, 0.42f, 1.0f);
    s16.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));
    
    //Pergelangan kiri
    Square s17;
    s17.setTranslation(-0.361f, 0.46f, 0.0f);
    s17.setScale(0.2f, 0.18f, 1.0f);
    s17.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    //Lengan Kanan
    Square s18;
    s18.setTranslation(0.32f, 0.207f, 0.0f);
    s18.setScale(0.4f, 0.26f, 1.0f);
    s18.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));
    
    Square s19;
    s19.setTranslation(0.36f, -0.017f, 0.0f);
    s19.setScale(0.2f, 0.42f, 1.0f);
    s19.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));

    //Pergelangan kanan
    Square s20;
    s20.setTranslation(0.359f, 0.071f, 0.0f);
    s20.setScale(0.2f, 0.18f, 1.0f);
    s20.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    //SABUK ROBOT
    Square s21;
    s21.setTranslation(0.0f, -0.21f, 0.0f);
    s21.setScale(0.9f, 0.26f, 1.0f);
    s21.setColor(glm::vec4(0.0f, 0.5f, 0.5f, 1.0f));

    //PAHA kiri
    Square s22;
    s22.setTranslation(-0.09f, -0.592f, 0.0f);
    s22.setScale(0.34f, 0.6f, 1.0f);
    s22.setColor(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

    //PAHA kanan
    Square s23;
    s23.setTranslation(0.09f, -0.592f, 0.0f);
    s23.setScale(0.34f, 0.6f, 1.0f);
    s23.setColor(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

    //KAKI kiri
    Square s24;
    s24.setTranslation(-0.09f, -0.77f, 0.0f);
    s24.setScale(0.28f, 0.6f, 1.0f);
    s24.setColor(glm::vec4(0.0f, 0.5f, 0.5f, 1.0f));

    //KAKI kanan
    Square s25;
    s25.setTranslation(0.09f, -0.77f, 0.0f);
    s25.setScale(0.28f, 0.6f, 1.0f);
    s25.setColor(glm::vec4(0.0f, 0.5f, 0.5f, 1.0f));

    //PERGELANGAN KAKI kiri
    Square s26;
    s26.setTranslation(-0.11f, -0.64f, 0.0f);
    s26.setScale(0.38f, 0.26f, 1.0f);
    s26.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));

    //PERGELANGAN KAKI kanan
    Square s27;
    s27.setTranslation(0.11f, -0.64f, 0.0f);
    s27.setScale(0.38f, 0.26f, 1.0f);
    s27.setColor(glm::vec4(0.2f, 0.3f, 1.0f, 1.0f));

    //Bola Mata kanan
    Square s28;
    s28.setTranslation(-0.08f, 0.6f, 0.0f);
    s28.setScale(0.04f, 0.05f, 1.0f);
    s28.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    //Bola Mata kanan
    Square s29;
    s29.setTranslation(0.08f, 0.6f, 0.0f);
    s29.setScale(0.04f, 0.05f, 1.0f);
    s29.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glUseProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");
    /* Dibawah ini adalah loop penggambaran object */
    while (!glfwWindowShouldClose(window))
    {
        currentTime = glfwGetTime();
        deltaTime = (currentTime - lastTime) * speedUp;
        lastTime = currentTime;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f,1.0f, 0.0f, 1.0f);
        glUseProgram(program);

        //3
        
        //object1
        glUniform4fv(uColor,1, &s1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4,1, GL_FALSE, &s1.getTransformationMat4x4()[0][0]);
        s1.draw();

        //object2
        glUniform4fv(uColor, 1, &s2.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s2.getTransformationMat4x4()[0][0]);
        s2.draw();

        //object3
        glUniform4fv(uColor, 1, &s3.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s3.getTransformationMat4x4()[0][0]);
        s3.draw();

        //object4
        glUniform4fv(uColor, 1, &s4.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s4.getTransformationMat4x4()[0][0]);
        s4.draw();

        //object5
        glUniform4fv(uColor, 1, &s5.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s5.getTransformationMat4x4()[0][0]);
        s5.draw();

        //object6
        glUniform4fv(uColor, 1, &s6.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s6.getTransformationMat4x4()[0][0]);
        s6.draw();

        //object7
        glUniform4fv(uColor, 1, &s7.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s7.getTransformationMat4x4()[0][0]);
        s7.draw();

        //object8
        glUniform4fv(uColor, 1, &s8.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s8.getTransformationMat4x4()[0][0]);
        s8.draw();

        //object9
        glUniform4fv(uColor, 1, &s9.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s9.getTransformationMat4x4()[0][0]);
        s9.draw();

        //object10
        glUniform4fv(uColor, 1, &s10.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s10.getTransformationMat4x4()[0][0]);
        s10.draw();

        //object11
        glUniform4fv(uColor, 1, &s11.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s11.getTransformationMat4x4()[0][0]);
        s11.draw();

        //object12
        glUniform4fv(uColor, 1, &s12.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s12.getTransformationMat4x4()[0][0]);
        s12.draw();

        //object13
        glUniform4fv(uColor, 1, &s13.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s13.getTransformationMat4x4()[0][0]);
        s13.draw();

        //object14
        glUniform4fv(uColor, 1, &s14.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s14.getTransformationMat4x4()[0][0]);
        s14.draw();

        //object15
        glUniform4fv(uColor, 1, &s15.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s15.getTransformationMat4x4()[0][0]);
        s15.draw();

        //object16
        glUniform4fv(uColor, 1, &s16.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s16.getTransformationMat4x4()[0][0]);
        s16.draw();

        //object17
        glUniform4fv(uColor, 1, &s17.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s17.getTransformationMat4x4()[0][0]);
        s17.draw();

        //object18
        glUniform4fv(uColor, 1, &s18.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s18.getTransformationMat4x4()[0][0]);
        s18.draw();

        //object19
        glUniform4fv(uColor, 1, &s19.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s19.getTransformationMat4x4()[0][0]);
        s19.draw();

        //object20
        glUniform4fv(uColor, 1, &s20.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s20.getTransformationMat4x4()[0][0]);
        s20.draw();

        //object21
        glUniform4fv(uColor, 1, &s21.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s21.getTransformationMat4x4()[0][0]);
        s21.draw();

        //object22
        glUniform4fv(uColor, 1, &s22.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s22.getTransformationMat4x4()[0][0]);
        s22.draw();

        //object23
        glUniform4fv(uColor, 1, &s23.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s23.getTransformationMat4x4()[0][0]);
        s23.draw();

        //object24
        glUniform4fv(uColor, 1, &s24.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s24.getTransformationMat4x4()[0][0]);
        s24.draw();

        //object25
        glUniform4fv(uColor, 1, &s25.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s25.getTransformationMat4x4()[0][0]);
        s25.draw();

        //object26
        glUniform4fv(uColor, 1, &s26.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s26.getTransformationMat4x4()[0][0]);
        s26.draw();

        //object27
        glUniform4fv(uColor, 1, &s27.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s27.getTransformationMat4x4()[0][0]);
        s27.draw();

        //object28
        glUniform4fv(uColor, 1, &s28.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s28.getTransformationMat4x4()[0][0]);
        s28.draw();

        //object29
        glUniform4fv(uColor, 1, &s29.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s29.getTransformationMat4x4()[0][0]);
        s29.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}