#version 400 core

// Uniforms
	uniform mat4 mv_matrix;
	uniform mat4 proj_matrix;
	uniform vec3 vLightPos;
	uniform vec4 vColor;

// Attributes
	layout (location = 0) in vec4 position;
	layout (location = 1) in vec2 uv;
	layout (location = 2) in vec3 normal;

// Varying
	out vec4 fragColor;
	out vec2 tex;

void main(void) 
{ 
	// Get vNorm
		mat4 mvmatrix = mv_matrix;
		mat3 mNormalMatrix;
		mNormalMatrix[0] = normalize(mvmatrix[0].xyz);
		mNormalMatrix[1] = normalize(mvmatrix[1].xyz);
		mNormalMatrix[2] = normalize(mvmatrix[2].xyz);
		vec3 vNorm = normalize(mNormalMatrix * normal);

	// Get vLightDir
		vec4 ecPosition;
		vec3 ecPosition3;
		ecPosition = mvmatrix * position;
		ecPosition3 = ecPosition.xyz /ecPosition.w;
		vec3 vLightDir = normalize(vLightPos - ecPosition3);

	// Get vFragColor
		float fDot = max(0.0, dot(vNorm, vLightDir)); 
		fragColor.rgb = vColor.rgb * fDot;
		fragColor.a = vColor.a;

	// Get vTex;
		tex = uv;

	// Set Gl_position
		gl_Position = proj_matrix * mv_matrix * position;
}