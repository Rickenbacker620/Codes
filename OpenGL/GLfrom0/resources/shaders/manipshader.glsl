#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 transform;
uniform float shift;
out vec3 Color;
out vec2 TexCoord;

void main()
{
    gl_Position = transform*vec4(aPos, 1.0);
    Color = aColor*shift;
    TexCoord = vec2(aTexCoord.x, 1.0 - aTexCoord.y);
}

#shader fragment
#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec3 Color;

uniform sampler2D box;
uniform sampler2D happy;
void main()
{
   FragColor = mix(texture(box,TexCoord) ,texture(happy, TexCoord), 0.2) * vec4(Color,1.0);
}