#version 400 core

//in vec4 position;

out vec4 vertColor;

// Uniforms
    uniform mat4 mv_matrix;
    uniform mat4 proj_matrix;
    uniform vec3 vLightPos;
    uniform vec4 vColor;

// Attributes
	layout (location = 0) in vec4 position;
	layout (location = 1) in vec2 uv;
	layout (location = 2) in vec3 normal;

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

    // Get vertColor
        float fDot = max(0.0, dot (vNorm, vLightDir));
        vertColor.rgb = vColor.rgb * fDot;
        vertColor.a = vColor.a;

	gl_Position = proj_matrix * mv_matrix * position;
}