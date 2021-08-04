#version 330

in vec4 vCol;
in vec2 texCoord;

out vec4 color;

uniform sampler2D theTexture;

void main() {
	vec4 texColor = texture(theTexture, texCoord);
	if (texColor.r < 0.1 && texColor.g < 0.1 && texColor.b < 0.1) {
		discard;
	}
	color = texColor;
}