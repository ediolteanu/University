#version 330

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 object_color;
uniform int shouldTransform;
uniform float r1;
uniform float r2;
uniform float r3;

// Output value to fragment shader
out vec3 color;

void main()
{
	float PI = 3.14159;

	color = object_color;
	if (shouldTransform == 0) {
		gl_Position = Projection * View * Model * vec4(v_position, 1.0);
	}
	else {
		gl_Position = Projection * View * Model * vec4(v_position.x + sin(2 * PI * v_position.x * cos(r1)) / 4, v_position.y + sin(2 * PI *  v_position.y * cos(r2)) / 4, v_position.z + sin(2 * PI *  v_position.z * cos(r3)) / 4, 1.0);
	}
}
