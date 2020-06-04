//
// Created by srdczk on 2020/6/4.
//

#ifndef LEARNOPENGL_GLOBAL_H
#define LEARNOPENGL_GLOBAL_H

#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

const size_t kWidth = 800;
const size_t kHeight = 600;

void FrameBufferSizeCallback(GLFWwindow *, int, int);
void ProcessInput(GLFWwindow *);

#endif //LEARNOPENGL_GLOBAL_H
