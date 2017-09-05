// Nintendo 2DS 3DS Pascal raw GFX, sex living after "coup de etat" edition  
//
// Copyright (c) 2017 PhD. Kenneth Dwayne Lee
// all rights reserved.
//

{$define Trap}
// x,y zero @ top of bottom screen
procedure {$i LCD3DS.inc}(screen:Pu8; x: u16; y: u16;colour: TRGB);stdcall;
{$undef Trap}
VAR	
  mvid : {$i LCD3DS.inc}; // absolute screen;
  v:u32;
BEGIN
  mvid:= {$i LCD3DS.inc}(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour.b;
  mvid^[v+1]:= colour.g;
  mvid^[v+2]:= colour.r;
END;
//kdl