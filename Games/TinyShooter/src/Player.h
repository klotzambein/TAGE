//
//  Player.h
//  TinyShooter
//
//  Created by Magnus Runesson on 2016-01-29.
//  Copyright © 2016 Magnus Runesson. All rights reserved.
//

#ifndef Player_h
#define Player_h

void playerReset( int _mapscroll );
void playerInit();
void playerCameraMove( int _cameraMoveDistance );
void playerUpdate();
void playerUpgrade();
bool playerHit( int _mapScroll, bool _forceKill );

#endif /* Player_h */
