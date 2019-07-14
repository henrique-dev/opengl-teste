#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
out vec3 ourColor; // specify a color output to the fragment shader
uniform float xOffset;
void main()
{
    //gl_Position = vec4(aPos, 1.0f); // see how we directly give a vec3 to vec4's constructor
    //gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0f);
    gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0f);
    //vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
    //ourColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
    ourColor = vec3(aPos.x + xOffset, aPos.y, aPos.z);
}
