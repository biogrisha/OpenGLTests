#pragma once

struct RGBA
{
	RGBA(float R, float G, float B) : R{ R }, G{ G }, B{ B }, A{ A }{}
	float R;
	float G;
	float B;
	float A;
};
