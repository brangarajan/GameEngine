#version 400 core

uniform sampler2D textureData;

in vec2 textureUV;

out vec4 fragColor;

void main(void)
{
	fragColor = texture(textureData, textureUV);
}