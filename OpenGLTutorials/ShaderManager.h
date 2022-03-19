#pragma once
#include <map>
#include <string>
#include <vector>
#include "shader_s.h"
class ShaderManager
{
public:
    using ShaderTypes = Shader::Type;
    using ShaderData = Shader::ShaderData;

    static ShaderManager* getInstance()
    {
        static ShaderManager    instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return &instance;
    }
private:
    ShaderManager() {} 
    ShaderManager(ShaderManager const&); 
    void operator=(ShaderManager const&); 

    //Functionality
public:
    void AddProgram(std::string programName,std::vector<ShaderData> shaderData)
    {
        shaders.insert(std::pair<std::string, Shader>(programName, Shader(shaderData)));
    }

    const Shader* GetProgram(std::string name)
    {
        auto el = shaders.find(name);
        if (el != shaders.end()) {
           return &el->second;
        }
        else {
            return nullptr;
        }

    }

private:
    std::map<std::string, Shader> shaders;
};