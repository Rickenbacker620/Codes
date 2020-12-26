#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
uniform float baase;
out vec3 aColl;
void main()
{
   gl_Position = vec4(aPos*baase/2, 1.0);
   aColl = aCol*baase;
}

#shader fragment
#version 330 core
in vec3 aColl;
out vec4 FragColor;
void main()
{
   FragColor = vec4(aColl, 1.0f);
}