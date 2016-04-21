#include "Engine/Types.h"
#include "Engine/Graphics/Image.h"

const uint16 sprite_enemy_missile_00_pixels[] =
{
	0x0000,0x581d,0x581d,0x4e0b,0x581d,0x5825,0x4e13,0x571d,0x0000,0xa4eb,0xa4eb,0xa4eb,0xe488,0x0000,0x0000,
	0x771d,0x1ca7,0x1ca7,0x741c,0x1ca7,0x1ca7,0x941c,0x571d,0xa5eb,0xffff,0x54ff,0xa5f3,0xa4eb,0xe488,0x0321,
	0x0000,0x5825,0x5825,0x4e0b,0x5825,0x3825,0x4e0b,0x581d,0x0000,0xa4f3,0xa4eb,0xa4eb,0xe488,0x0000,0x0000,
};

const uint8 sprite_enemy_missile_00_alpha[] =
{
	0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xff,0x00,0x00,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff,0xff,0x00,0x00,
};

extern "C" const Image sprite_enemy_missile_00;
const Image sprite_enemy_missile_00 =
{
	15,3,
	(uint16*)&sprite_enemy_missile_00_pixels,
	(uint8*)&sprite_enemy_missile_00_alpha,
	(uint8*)"sprite_enemy_missile_00",
};