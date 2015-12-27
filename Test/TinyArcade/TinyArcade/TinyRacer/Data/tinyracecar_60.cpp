#include "Image.h"

unsigned short tinyracecar_60_pixels[] =
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0xf924,0x0000,
	0x0000,0x0000,0x0000,0x6082,0xa104,0xf986,0x0000,
	0x0000,0xf965,0xf986,0x80e3,0x2820,0xe986,0x0000,
	0x0000,0xf986,0xf986,0xf986,0x3041,0x90e3,0x0000,
	0x0000,0xf966,0xf986,0xf986,0x70c3,0x9882,0x0000,
	0x0000,0xf965,0xf966,0xf986,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

unsigned char tinyracecar_60_alpha[] =
{
	0x00,0x00,0x00,0x00,0x00,0x07,0x00,
	0x00,0x00,0x00,0x4f,0xd9,0x5f,0x00,
	0x00,0x2e,0xb7,0xff,0xff,0xe9,0x00,
	0x00,0xff,0xff,0xff,0xff,0xf4,0x00,
	0x00,0xac,0xff,0xff,0x94,0x0f,0x00,
	0x00,0x20,0xb9,0x2e,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

Image tinyracecar_60 =
{
	7,7,
	(unsigned short*)&tinyracecar_60_pixels,
	(unsigned char*)&tinyracecar_60_alpha,
	(unsigned char*)"tinyracecar_60",
};
