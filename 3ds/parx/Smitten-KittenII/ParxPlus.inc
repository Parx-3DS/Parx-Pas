// Nintendo 3ds "love for sale"  
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

{$ifdef 3dsintf} //mapped sold as in sci &or ++ in libs
TopMapLED= array[0..399,0..239,0..2] of u8; 
PTopMapLED= ^TopMapLED;

BotMapLED= array[0..319,0..239,0..2] of u8; // y,x,c
PBotMapLED= ^BotMapLED;

RGBTop= array[0..319,0..239] of TBGR; //240×400
PRGBTop= ^RGBTop;

RGBBot= array[0..319,0..239] of TBGR; //240×320
PRGBBot= ^RGBBot;

procedure TopMap(colour: TBGR; y: u16; x: u16; screen:Pu8);stdcall; public name 'TopMap';
procedure BotMap(colour: TBGR; y: u16; x: u16; screen:Pu8);stdcall; public name 'BotMap';
 {$endif 3dsintf}


{$ifdef 3dsimpl}

{$define TopMapped}
{$i LCDMapped.inc}
{$undef TopMapped}

{$define BotMapLED}
{$i LCDMapped.inc}
{$undef BotMapLED}


{$endif 3dsimpl}