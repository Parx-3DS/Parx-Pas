// Nintendo 3ds, Java enemy # ? ...  
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//
// Ps. Even if U are hailing the from N3DS Rex, D ... language S.V.P! 
// Wii, gba, gamecube & DS all sling "telecom's through a class action suit" for several reasons! 
//a.) un lawfuly did proform buggary .. a night stand & placed 6 foot deep? 
//b.) Junk they spread in the media; & of rheo good times dyke the Crack we see in news; &or can't sexlive upto the Media's take on one of the linguistics Professor Reginald Watt's theories on & or of "stacks"? 

#include <3ds.h>

typedef struct TRGB
{
   u8   b;
   u8   g;
   u8   r;
} TRGB;

//Non-Alpha use, faster than our stock GDI functions presented in c   
void * PSetPix(u8* screen, int x, int y, TRGB colour);external;
void * BSetPix(u8* screen, int x, int y, TRGB colour);external;

//& these in less cpu cycles used, out proform PSetPix && BSetPix in the above  
void * GFXPix(TRGB colour, int y, int x, u8* screen);external;
void * GFXPixB(TRGB colour, int y, int x, u8* screen);external;

//R&D jacker be nimble; "Canadian Oil, Gaz & that disaster never happend" think your slick? 
//kdl 