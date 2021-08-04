#version 330

layout (location = 0) in vec3 pos;

out vec4 vCol;

uniform mat4 model;
uniform mat4 projection;
uniform vec3 u_color;
uniform float value;

void main() {
	gl_Position = projection * model * vec4(pos, 1.0);
	vCol = vec4(value / 100, 1.0 - value / 100, 1.0 - value / 100, 1.0);

	float hue = value * 3.6;
	if (hue >= 0 &&  hue <= 60) {
		vCol = vec4(1.0, hue / 60, 0.0, 1.0);
	} else if (hue > 60 && hue <= 120) {
		vCol = vec4(1.0 - ((hue - 60) / 60), 1.0, 0.0, 1.0);
	} else if (hue > 120 && hue <= 180) {
		vCol = vec4(0.0, 1.0, (hue - 120) / 60, 1.0);
	} else if (hue > 180 && hue <= 240) {
		vCol = vec4(0.0, 1.0 - ((hue - 180) / 60), 1.0, 1.0);
	} else if (hue > 240 && hue <= 300) {
		vCol = vec4((hue - 240) / 60, 0.0, 1.0, 1.0);
	} else if (hue > 300) {
		vCol = vec4(1.0, 0.0, 1.0 - ((hue - 300) / 60), 1.0);
	} else {
		vCol = vec4(1.0, 1.0, 1.0, 1.0);
	}
}