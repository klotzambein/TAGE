#include "Image.h"

unsigned short tinyracecar_30_pixels[] =
{
	0x0000,0x0000,0x0000,0xf986,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0800,0xa104,0xf986,0xf986,0x0000,
	0x0000,0xf800,0xa104,0x1800,0x3041,0xc925,0x0000,
	0x0000,0xf965,0xf986,0xf986,0x78e3,0x0000,0x0000,
	0x0000,0xf966,0xf986,0xf986,0xf986,0xb800,0x0000,
	0x0000,0xf965,0xf966,0xf986,0xf965,0x0000,0x0000,
	0x0000,0x0000,0x0000,0xf965,0x0000,0x0000,0x0000,
};

unsigned char tinyracecar_30_alpha[] =
{
	0x00,0x00,0x00,0x59,0x00,0x00,0x00,
	0x00,0x00,0x16,0xf0,0xd9,0x52,0x00,
	0x00,0x04,0x98,0xff,0xff,0xed,0x00,
	0x00,0x34,0xf5,0xff,0xff,0x48,0x00,
	0x00,0xc9,0xff,0xff,0xb2,0x04,0x00,
	0x00,0x28,0xb9,0xff,0x2b,0x00,0x00,
	0x00,0x00,0x00,0x4b,0x00,0x00,0x00,
};

Image tinyracecar_30 =
{
	7,7,
	(unsigned short*)&tinyracecar_30_pixels,
	(unsigned char*)&tinyracecar_30_alpha,
};
