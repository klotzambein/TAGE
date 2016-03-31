//
//  spacebase_boss.cpp
//  TinyShooter
//
//  Created by Magnus Runesson on 2016-03-14.
//  Copyright © 2016 Magnus Runesson. All rights reserved.
//

#include <stdlib.h>
#include "Engine/Scene/GameObject.h"
#include "Engine/Scene/GameObjectManager.h"
#include "Engine/Graphics/Animation.h"
#include "Engine/debug.h"
#include "src/Ingame/ContextIngame.h"
#include "src/Ingame/spacebase_boss.h"
#include "src/Ingame/Enemy.h"
#include "src/Ingame/EnemyManager.h"
#include "data/alldata.h"

uint8 sbbDoorPattern[ 10 ] = {
	0,2,0,1,2,1,2,0,1,2
};
const uint8 sbbDoorPatternLength = sizeof( sbbDoorPattern );

Enemy* sbbDoor[ 3 ];
Enemy* sbbWallFlower;
Enemy* sbbWarningLights[ 3 ];
int sbbTimer;
int sbbDoorPatternIndex;
void(*pfnBoss)();

/******************************************************************************************************************************************
 
 State variables
 
 ******************************************************************************************************************************************/
int sbbDoorIndex;


//
// States
//
void sbbGotoIntro();
void sbbGotoWarningLights( int _doorIndex );
void sbbGotoOpenDoor();
void sbbGotoCloseDoor();
void sbbsIntro();
//void sbbsWarningLights();
//void sbbsOpenDoor();
//void sbbsCloseDoor();
void sbbsWaitForAnimationCallback();
void cbDoorOpenDone();
void cbDoorCloseDone();
void cbWarningLightDone();
void cbWallflowerHit( Enemy* _pEnemy );

/******************************************************************************************************************************************
 
 Helpers
 
 ******************************************************************************************************************************************/
//
//
//
Enemy* sbbCreateDoor( int _x, int _y )
{
	Enemy* pRet = enemySpawn( &enemy_spacebase_door, _x, _y, NULL );
	pRet->Timeout = 0;
	return pRet;
}

//
//
//
Enemy* sbbCreateWarningLights( int _x, int _y )
{
	Enemy* pRet = enemySpawn( &enemy_spacebase_warninglights, _x, _y, NULL );
	pRet->Timeout = 0;
	pRet->pTargetGameObject->GetSprite()->SetSort( -1 );
	return pRet;
}

int sbbDoorPositionX[] = {
	944,
	940,
	940,
};

int sbbDoorPositionY[] = {
	3,
	27,
	51,
};

//
// Public functions
//
void sbbSpawn()
{
	pfnIngameCallback = &sbbUpdate;
	
	sbbWallFlower = enemySpawn( &enemy_wallflower, sbbDoorPositionX[ 0 ] + 1, sbbDoorPositionY[ 0 ] + 2, NULL );
	sbbWallFlower->Timeout = 0;
	sbbWallFlower->pTargetGameObject->GetSprite()->SetSort( -2 );
	sbbWallFlower->pfnHitCallback = &cbWallflowerHit;
	
	sbbDoor[ 0 ] = sbbCreateDoor( sbbDoorPositionX[ 0 ], sbbDoorPositionY[ 0 ]);
	sbbDoor[ 1 ] = sbbCreateDoor( sbbDoorPositionX[ 1 ], sbbDoorPositionY[ 1 ]);
	sbbDoor[ 2 ] = sbbCreateDoor( sbbDoorPositionX[ 2 ], sbbDoorPositionY[ 2 ]);

	sbbWarningLights[ 0 ] = sbbCreateWarningLights( sbbDoorPositionX[ 0 ] + 4, sbbDoorPositionY[ 0 ]);
	sbbWarningLights[ 1 ] = sbbCreateWarningLights( sbbDoorPositionX[ 1 ] + 4, sbbDoorPositionY[ 1 ]);
	sbbWarningLights[ 2 ] = sbbCreateWarningLights( sbbDoorPositionX[ 2 ] + 4, sbbDoorPositionY[ 2 ]);
	
	sbbDoorPatternIndex = 0;
	
	sbbGotoIntro();
}

void sbbUpdate()
{
	pfnBoss();
}



/******************************************************************************************************************************************
 
 State helpers
 
 ******************************************************************************************************************************************/
//
// Goto the intro state
//
void sbbGotoIntro()
{
	sbbTimer = 360;
	pfnBoss = &sbbsIntro;
}

//
// This function will initiate the next door opening phase. A door opening phase consist of:
// 1. Flash warning lights
// 2. Open door
// 3. Do an enemy routine
// 3.1. Enemy 1: The red kill part
// 3.2. Enemy 2: Sparrows
// 3.3. Enemy 3: Missile
// 3.4. Enemy 4: Dragons
// 4. Close door
//
// When the door phase is over we idle for a bit, then open another door at random
//
void sbbStartNextDoor()
{
	// Get current index
	int currentDoorPatternIndex = sbbDoorPatternIndex;
	
	// Increment for next time
	sbbDoorPatternIndex++;
	if( sbbDoorPatternIndex >= sbbDoorPatternLength )
		sbbDoorPatternIndex -= sbbDoorPatternLength;
	
	// Fetch door index from pattern
	int doorIndex = sbbDoorPattern[ currentDoorPatternIndex ];
	sbbGotoWarningLights( doorIndex );
}


//
// Flash the warning lights that will indicate which door is about to open
//
void sbbGotoWarningLights( int _doorIndex )
{
	pfnBoss = &sbbsWaitForAnimationCallback;
	sbbDoorIndex = _doorIndex;
	Animation* pAnim = sbbWarningLights[ sbbDoorIndex ]->pTargetGameObject->GetAnimation();
	pAnim->SetSequence( &animation_spacebase_boss_warninglights_blink );
	pAnim->SetDoneCallback( &cbWarningLightDone );
	pAnim->Play();
	//sbbTimer = (18*5)-1;
}

//
// Go to Opening Door state
//
void sbbGotoOpenDoor()
{
	pfnBoss = &sbbsWaitForAnimationCallback;
	Animation* pAnim = sbbDoor[ sbbDoorIndex ]->pTargetGameObject->GetAnimation();
	pAnim->SetSequence( &animation_spacebase_boss_door_open );
	pAnim->SetDoneCallback( cbDoorOpenDone );
	pAnim->Play();
	//sbbTimer = (9*4)-1;
	sbbWallFlower->SpecialFlag = 0;
}

void sbbGotoCloseDoor()
{
	pfnBoss = &sbbsWaitForAnimationCallback;
	Animation* pAnim = sbbDoor[ sbbDoorIndex ]->pTargetGameObject->GetAnimation();
	pAnim->SetSequence( &animation_spacebase_boss_door_close );
	pAnim->SetDoneCallback( cbDoorCloseDone );
	pAnim->Play();
	//sbbTimer = (9*1)-1;
}

/******************************************************************************************************************************************
 
 Animation callbacks
 
 ******************************************************************************************************************************************/
void cbWarningLightDone()
{
	debugLog("Warning light done, y'all!\n");
	sbbGotoOpenDoor();
}

void cbDoorOpenDone()
{
	debugLog("Door open done, yah!\n");
	sbbGotoCloseDoor();
}

void cbDoorCloseDone()
{
	debugLog("Door close done, yah!\n");
	sbbGotoIntro();
}

void cbWallflowerHit( Enemy* _pEnemy )
{
	_pEnemy->SpecialFlag = ENEMY_SPECIALFLAG_INVINCIBLE;
}

/******************************************************************************************************************************************
 
 The states
 
******************************************************************************************************************************************/
//
// Intro state
//
void sbbsIntro()
{
	sbbTimer--;
	if( sbbTimer == 0 )
		sbbStartNextDoor();
}

/*
void sbbsWarningLights()
{
	sbbTimer--;
	if( sbbTimer == 0 )
	{
		sbbWarningLights[ sbbDoorIndex ]->GetAnimation()->SetDoneCallback( NULL );
		sbbGotoOpenDoor();
	}
}

//
// Animate an opening door
//
void sbbsOpenDoor()
{
	sbbTimer--;
	if( sbbTimer == 0 )
	{
		sbbDoor[ sbbDoorIndex ]->pTargetGameObject->GetAnimation()->SetDoneCallback( NULL );
		sbbGotoCloseDoor();
	}
}

//
// Animate an opening door
//
void sbbsCloseDoor()
{
	sbbTimer--;
	if( sbbTimer == 0 )
	{
		sbbDoor[ sbbDoorIndex ]->pTargetGameObject->GetAnimation()->SetDoneCallback( NULL );
		sbbGotoIntro();
	}
}
*/

void sbbsWaitForAnimationCallback()
{
	
}
