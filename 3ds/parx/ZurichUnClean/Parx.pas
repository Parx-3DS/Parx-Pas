// Nintendo 2DS 3DS Pascal raw GFX, sex living after "coup de etat" edition  
//
// Copyright (c) 2017 PhD. Kenneth Dwayne Lee
// all rights reserved.
//

unit Parx;
{$mode objfpc}{$H+}
 
interface
 
uses
  ctypes;

{$packrecords c}
 
{$linklib libctru}

{$define 3dsintf}
{$include 3dstypes.inc}
{$undef 3dsintf}

type	

TRGB = record
b,g,r:u8;
end; 

TopRawLinear= array[0..287999] of u8; //240×400×3
PTopRawLinear= ^TopRawLinear;

RGBTopL= array[0..96000] of TRGB; //240×400
PRGBTopL= ^RGBTopL;

BotRawLinear= array[0..230399] of u8; //240×320×3
PBotRawLinear= ^BotRawLinear;

RGBBotL= array[0..76800] of TRGB; //240×320
PRGBBotL= ^RGBBotL;

{$define 3dsintf}
{$include ParxPlus.inc}
{$undef 3dsintf}

{$include gfx.inc}

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: TRGB);stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: TRGB);stdcall; public name 'BotLCD';
 
implementation

// x,y zero @ top of display

{$define TopLinear}
{$i LCDLinear.inc}
{$undef TopLinear}

{$define BotLinear}
{$i LCDLinear.inc}
{$undef BotLinear}


{$define 3dsimpl}
{$include 3dstypes.inc}
{$include ParxPlus.inc}
{$undef 3dsimpl}

end.
//KDL @ 10 times the viscosity of Government
//& rule the 2DS 3DS world!