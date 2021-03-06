#version 330
in vec3 vertex;
in vec3 normal;
//in ivec4 BoneIDs;
//in vec4 Weights;

//const int MAX_BONES = 100;

uniform mat4 projMatrix;
uniform mat4 mvMatrix;
uniform mat3 normalMatrix;
//uniform mat4 Bones[MAX_BONES];
//uniform vec3 BoneColours[MAX_BONES];

out vec3 vert;
out vec3 vertNormal;


void main()
{
   vert = (mvMatrix * vec4(vertex, 1.0f)).xyz;
   vertNormal = normalMatrix * normal;
   gl_Position = projMatrix * mvMatrix * vec4(vertex, 1.0);
}
