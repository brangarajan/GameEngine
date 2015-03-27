#version 400 core

out vec4 fragColor;

in vec4 vertColor;

void main(void)
{
	fragColor = vertColor;
}