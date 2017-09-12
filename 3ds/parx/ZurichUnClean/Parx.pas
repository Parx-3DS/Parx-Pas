// Nintendo 3ds, sex living after "coup de etat" edition  
//
// Copyright (c) 2017 Kenny D. Lee
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

trange = 0..$ffffff;
prange = ^trange;

TBGR = record
b,g,r:u8;
end; 

{
TRGB = record
  case byte of
   0: (Range: trange);
   1: (X: TBGR);
   2: (BRG: array[0..2] of u8);
   3: (BoolBit: array[0..23] of boolean);
end;
}
TopRawLinear= array[0..287999] of u8; //240×400×3
PTopRawLinear= ^TopRawLinear;

RGBTopL= array[0..96000] of TBGR; //240×400
PRGBTopL= ^RGBTopL;

BotRawLinear= array[0..230399] of u8; //240×320×3
PBotRawLinear= ^BotRawLinear;

RGBBotL= array[0..76800] of TBGR; //240×320
PRGBBotL= ^RGBBotL;

{$define 3dsintf}
{$include ParxPlus.inc}
{$undef 3dsintf}

{$include gfx.inc}

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'PSetPix';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'BSetPix';
 
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