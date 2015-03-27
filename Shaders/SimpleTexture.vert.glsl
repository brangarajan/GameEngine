#version 400 core

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 tc;

out vec2 textureUV;

void main(void)
{
		textureUV = tc;
		gl_Position = proj_matrix * mv_matrix * position;
}