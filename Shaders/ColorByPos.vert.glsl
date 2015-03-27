#version 400 core

in vec4 position;

out vec4 vertColor;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

void main(void)
{
	gl_Position = proj_matrix * mv_matrix * position;
	vertColor = position * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);
}