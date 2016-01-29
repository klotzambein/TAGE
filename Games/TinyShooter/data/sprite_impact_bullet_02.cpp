#include "Engine/Types.h"
#include "Engine/Graphics/Image.h"

const uint16 sprite_impact_bullet_02_pixels[] =
{
	0x0000,0x0000,0x0000,0x0000,0xffff,
	0xffff,0xf626,0x0000,0x0000,0xf626,
	0x0000,0x0000,0x5082,0x0000,0x5082,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x5082,0x0000,0x5082,
	0x0000,0xf626,0x0000,0x0000,0xf626,
	0x0000,0xffff,0x0000,0x0000,0xffff,
};

const uint8 sprite_impact_bullet_02_alpha[] =
{
	0x00,0x00,0x00,0x00,0xff,
	0xff,0xff,0x00,0x00,0xff,
	0x00,0x00,0xff,0x00,0xff,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0x00,0xff,
	0x00,0xff,0x00,0x00,0xff,
	0x00,0xff,0x00,0x00,0xff,
};

extern "C" const Image sprite_impact_bullet_02;
const Image sprite_impact_bullet_02 =
{
	5,8,
	(uint16*)&sprite_impact_bullet_02_pixels,
	(uint8*)&sprite_impact_bullet_02_alpha,
	(uint8*)"sprite_impact_bullet_02",
};