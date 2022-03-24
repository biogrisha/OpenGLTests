#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



class BaseVBO
{
public:
    struct BufferSettings
    {
        int size = 0;
        GLenum target = GL_ARRAY_BUFFER;
        GLenum usage = GL_DYNAMIC_DRAW;
        GLenum type = GL_FLOAT;

    };
public:
    BaseVBO(const BufferSettings& bufSettings) : settings{ bufSettings }
    {
        
    }
    ~BaseVBO()
    {
        glDeleteBuffers(1, &bufferName);
    }

    void DeleteBuffer()
    {
        glDeleteBuffers(1, &bufferName);
    }

    void Bind()
    {
        if (!IsBinded())
        {
            bindedBufferName = bufferName;
            glBindBuffer(settings.target, bufferName);
        }
    }

    void Unbind()
    {
        if (IsBinded())
        {
            bindedBufferName = 0;
            glBindBuffer(settings.target, 0);
        }
    }

    bool IsBinded()
    {
        return bindedBufferName == bufferName;
    }

    void SetTarget(GLenum bTarget)
    {
        bool wasBinded = IsBinded();
        Unbind();
        settings.target = bTarget;
        if (wasBinded)
        {
            Bind();
        }
    }



    static GLuint GetBindedBufferName()
    {
        return bindedBufferName;
    }
protected:
    BufferSettings settings;
    int sizeBytes;
    GLuint bufferName;

    static GLuint bindedBufferName;
};

GLuint BaseVBO::bindedBufferName = 0;

template<typename BufferDataType>
class VBO : public BaseVBO
{
public:
    VBO(const BufferSettings& bufSettings) : BaseVBO(bufSettings)
    {
        CheckTypeConsistency();
        sizeBytes = settings.size * sizeof(BufferDataType);
        glGenBuffers(1, &bufferName);
        Bind();
        Clear();
    }

    VBO(const VBO&) = delete;


    void Clear()
    {
        glBufferData(settings.target, sizeBytes, NULL, settings.usage);
    }

    void AddData(std::vector<BufferDataType> data, int elOffset)
    {
        int dataSize = sizeof(BufferDataType) * data.size();
        int offset = elOffset * sizeof(BufferDataType);
        Bind();
        if (dataSize <= (sizeBytes - offset))
        {
            glBufferSubData(settings.target, offset, dataSize, &data[0]);
        }
    }


private:
    void CheckTypeConsistency()
    {
        switch (settings.type)
        {
        case GL_FLOAT:
            if (typeid(BufferDataType) != typeid(float))
            {
                throw std::invalid_argument("The provided type \"GL_FLOAT\" not consistent with the template parameter");
            }
            break;
        case GL_INT:
            if (typeid(BufferDataType) != typeid(int))
            {
                throw std::invalid_argument("The provided type \"GL_INT\" not consistent with the template parameter");
            }
            break;
        default:
            throw std::invalid_argument("The provided type is not supported");
            break;
        }
    }

};





class VAO
{

private:

    bool isBinded = false;
    unsigned int pVAO;
    unsigned int pVBO;

public:
    

public:
	VAO()
	{
        glGenVertexArrays(1, &pVAO);
	}
    ~VAO()
    {

    }

    void Unbind()
    {
        glBindVertexArray(0);
        isBinded = false;
    }

    void Bind()
    {
        if(!isBinded)
        {
        glBindVertexArray(pVAO);
        }
        isBinded = true;
    }


};


class BufferManager
{
public:
	void GetBuffer(std::vector<int> format);
};