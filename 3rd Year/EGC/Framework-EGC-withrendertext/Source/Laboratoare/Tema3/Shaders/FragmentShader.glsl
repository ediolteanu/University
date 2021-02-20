#version 330

// TODO: get color value from vertex shader

uniform sampler2D texture;
uniform int apply_texture;

layout(location = 0) out vec4 out_color;

in vec3 color;
in vec2 texcoord;

void main()
{
	vec4 texcolor = texture2D(texture, texcoord);
	if (apply_texture == 1) {
		if(color != vec3(0.f, 0.f, 0.f)) {
			out_color = mix(texcolor, vec4(color, 1), 0.5f);
		} else {
			out_color = texcolor;
		}
	} else {
		out_color = vec4(color, 1);
	}
	
}