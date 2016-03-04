#include "Engine/Types.h"
#include "Engine/Graphics/Image.h"

const uint16 sprite_enemy_spinloop_00_pixels[] =
{
	0x0000,0xe490,0xe490,0xe490,0x0000,
	0xe490,0x4a38,0xb158,0x4a38,0xe490,
	0xe490,0xb158,0x1981,0xb158,0xe490,
	0xe490,0x4a38,0xb158,0x4a38,0xe490,
	0x0000,0xe490,0xe490,0xe490,0x0000,
};

const uint8 sprite_enemy_spinloop_00_alpha[] =
{
	0x00,0xff,0xff,0xff,0x00,
	0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,
	0x00,0xff,0xff,0xff,0x00,
};

extern "C" const Image sprite_enemy_spinloop_00;
const Image sprite_enemy_spinloop_00 =
{
	5,5,
	(uint16*)&sprite_enemy_spinloop_00_pixels,
	(uint8*)&sprite_enemy_spinloop_00_alpha,
	(uint8*)"sprite_enemy_spinloop_00",
};