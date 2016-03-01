#include "Engine/Types.h"
#include "Engine/Graphics/Image.h"

const uint16 sprite_pickup_bomb_01_pixels[] =
{
	0x0000,0xa9ed,0xa9ed,0xc1e4,0x0000,
	0xa9ed,0x48f7,0xa1e6,0xa1e6,0xc1e4,
	0xc1e4,0xa1e6,0xa1e6,0x48f7,0xc1e4,
	0xc1e4,0xa1e6,0x48f7,0xffff,0xc0bb,
	0x0000,0xc1e4,0xc0bb,0xc0bb,0x0000,
};

const uint8 sprite_pickup_bomb_01_alpha[] =
{
	0x00,0xff,0xff,0xff,0x00,
	0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,
	0x00,0xff,0xff,0xff,0x00,
};

extern "C" const Image sprite_pickup_bomb_01;
const Image sprite_pickup_bomb_01 =
{
	5,5,
	(uint16*)&sprite_pickup_bomb_01_pixels,
	(uint8*)&sprite_pickup_bomb_01_alpha,
	(uint8*)"sprite_pickup_bomb_01",
};
