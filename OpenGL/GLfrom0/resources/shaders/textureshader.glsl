#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;
uniform float shift;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor*shift;
    TexCoord = aTexCoord;
}

#shader fragment
#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec3 ourColor;
uniform sampler2D box;
uniform sampler2D happy;
void main()
{
   gl_FragColor = mix(texture(box, TexCoord) ,texture(happy, TexCoord), 0.2) * vec4(ourColor,1.0);
}