#version 120

varying vec2 texCoordVarying;

void main()
{
     gl_FrontColor = vec4(1.0, 0.0, 0.0, 1.0);
    gl_Position = ftransform();
}