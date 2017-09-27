#pragma once

const float FPS = 60;
const float TIMESTEP = 100.0f / FPS;
const float G = 1e-3;
const int WINWIDTH = 800;
const int WINHEIGHT = 800;
const int PLAYFIELDMINX = -200;
const int PLAYFIELDMAXX =  200;
const int PLAYFIELDMINY = -200;
const int PLAYFIELDMAXY =  200;

float map_(float input, float input_start, float input_end, float output_start, float output_end)
{
	float slope = 1.0 * (output_end - output_start) / (input_end - input_start);
	return output_start + slope * (input - input_start);
	/*return ((input - input_start) / (input_end - input_start))*(output_end - output_start) + output_start;*/
}