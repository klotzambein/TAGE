#include "Engine/Types.h"
#include "Engine/Graphics/Image.h"

const uint16 sprite_impact_bullet_00_pixels[] =
{
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0xffff,0xffff,
	0x0000,0x0000,0x0000,0xffff,0xffff,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,
};

const uint8 sprite_impact_bullet_00_alpha[] =
{
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xff,0xff,
	0x00,0x00,0x00,0xff,0xff,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,
};

extern "C" const Image sprite_impact_bullet_00;
const Image sprite_impact_bullet_00 =
{
	5,8,
	(uint16*)&sprite_impact_bullet_00_pixels,
	(uint8*)&sprite_impact_bullet_00_alpha,
	(uint8*)"sprite_impact_bullet_00",
};
