#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    public:
        unsigned int ID;
        bool status = true;

        Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

        void use();

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

        virtual ~Shader();

    protected:

    private:
};

#endif // SHADER_H
