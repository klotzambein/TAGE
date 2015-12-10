#include "Image.h"

unsigned short tinyracecar_70_pixels[] =
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x98e3,0x4861,0xf986,0x0000,
	0x0000,0xf965,0xf986,0xa104,0x2820,0xf986,0x0000,
	0x0000,0xf986,0xf986,0xf986,0x0800,0xc945,0x0000,
	0x0000,0xf966,0xf986,0xf9a6,0x3841,0xa904,0x0000,
	0x0000,0xf965,0xf966,0xf986,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

unsigned char tinyracecar_70_alpha[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x20,0x7d,0x70,0x00,
	0x00,0x65,0xc3,0xff,0xff,0xda,0x00,
	0x00,0xff,0xff,0xff,0xff,0xff,0x00,
	0x00,0xc2,0xff,0xff,0xb4,0x57,0x00,
	0x00,0x56,0x6e,0x14,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

Image tinyracecar_70 =
{
	7,7,
	(unsigned short*)&tinyracecar_70_pixels,
	(unsigned char*)&tinyracecar_70_alpha,
};
