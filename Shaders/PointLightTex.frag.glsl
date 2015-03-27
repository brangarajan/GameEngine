#version 400 core

// Uniforms
	uniform sampler2D textureUnit0;

// Varying
	in vec4 fragColor;
	in vec2 tex;
	
	out vec4 color;

void main(void) 
{ 
	color = fragColor * texture(textureUnit0, tex);
}
