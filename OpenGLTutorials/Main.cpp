#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <iostream>

#include "ShaderManager.h"
#include "Rectangle.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Rectangle* rect;
int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------

    std::vector<Shader::ShaderData> shaders1 =
    { 
        Shader::ShaderData(Shader::Type::VERTEX,"VShader.vs") ,
        Shader::ShaderData(Shader::Type::GEOMETRY,"GShader.gs"),
        Shader::ShaderData(Shader::Type::FRAGMENT,"FShader.fs")
     };

    std::vector<Shader::ShaderData> shaders2 =
    { 
        Shader::ShaderData(Shader::Type::VERTEX,"TrivialVShader.vs") ,
        Shader::ShaderData(Shader::Type::FRAGMENT,"TrivialFShader.fs")
     };

    ShaderManager* shManager = ShaderManager::getInstance();
    shManager->AddProgram("RoundRect",shaders1);
    shManager->AddProgram("SimpleShader", shaders2);
    glm::vec3 pos(0, 0, 0);
;   rect = new Rectangle (0.9,0.9, pos, 0.1);
    
    shManager->GetProgram("RoundRect")->use();
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render the triangle
        rect->Draw();


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }



    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    delete rect;
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        rect->SetX(rect->GetX() - 0.001);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        rect->SetX(rect->GetX() + 0.001);

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        rect->SetY(rect->GetY() - 0.001);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        rect->SetY(rect->GetY() + 0.001);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}