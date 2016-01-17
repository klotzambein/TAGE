#include "Types.h"
#include "Image.h"

uint16 tinyracecar_20_pixels[] =
{
	0x0000,0x0000,0xf965,0xf966,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x68a3,0xd945,0xf986,0xf986,0x0000,
	0x0000,0x0000,0x5082,0x0000,0x2020,0x80e3,0x0000,
	0x0000,0xf986,0xf986,0xf986,0xa104,0x3020,0x0000,
	0x0000,0xf965,0xf986,0xf986,0xf986,0x0000,0x0000,
	0x0000,0xf965,0xf965,0xf986,0xf966,0x0000,0x0000,
	0x0000,0x0000,0x0000,0xf965,0xf945,0x0000,0x0000,
};

uint8 tinyracecar_20_alpha[] =
{
	0x00,0x00,0x0b,0x2e,0x00,0x00,0x00,
	0x00,0x00,0x50,0xff,0xd3,0x54,0x00,
	0x00,0x00,0xba,0xff,0xff,0x94,0x00,
	0x00,0x15,0xfc,0xff,0xff,0x20,0x00,
	0x00,0x82,0xff,0xff,0xca,0x00,0x00,
	0x00,0x42,0xc5,0xff,0x63,0x00,0x00,
	0x00,0x00,0x00,0x22,0x12,0x00,0x00,
};

Image tinyracecar_20 =
{
	7,7,
	(uint16*)&tinyracecar_20_pixels,
	(uint8*)&tinyracecar_20_alpha,
	(uint8*)"tinyracecar_20",
};