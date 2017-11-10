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

BotRawLinear= array[0..230399] of u8; //240×320×3
PBotRawLinear= ^BotRawLinear;

RGBTopL= array[0..96000] of TBGR; //240×400
PRGBTopL= ^RGBTopL;

RGBBotL= array[0..76800] of TBGR; //240×320
PRGBBotL= ^RGBBotL;

{$define 3dsintf}
{$include ParxPlus.inc}
{$undef 3dsintf}

{$include gfx.inc}


procedure Setbuffers(x: integer); stdcall; public name 'SetTopFramebuffers';
procedure Setgfxbuffers; stdcall; public name 'SetFramebuffers';

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'BotLCD';
 
implementation

var 
bufnum: integer = 0;

procedure Setbuffers(x: integer); stdcall;
begin
  gfxTopLeftFramebuffers[x] := gfxGetFramebuffer(GFX_TOP,GFX_LEFT,nil,nil); 
  gfxTopRightFramebuffers[x] := gfxGetFramebuffer(GFX_TOP,GFX_RIGHT,nil,nil); 
  gfxBottomFramebuffers[x] := gfxGetFramebuffer(GFX_BOTTOM,GFX_LEFT,nil,nil);
  bufnum:= x; 
end;

procedure Setgfxbuffers; stdcall;
begin
  gfxTopLeftFramebuffers[bufnum] := gfxGetFramebuffer(GFX_TOP,GFX_LEFT,nil,nil); 
  gfxTopRightFramebuffers[bufnum] := gfxGetFramebuffer(GFX_TOP,GFX_RIGHT,nil,nil); 
  gfxBottomFramebuffers[bufnum] := gfxGetFramebuffer(GFX_BOTTOM,GFX_RIGHT,nil,nil); 
end;


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