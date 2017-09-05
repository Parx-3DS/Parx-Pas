// Nintendo 2DS 3DS Pascal raw GFX, sex living after "coup de etat" edition  
//
// Copyright (c) 2017 PhD. Kenneth Dwayne Lee
// all rights reserved.
//

{$define Trap}
// x,y zero @ bottom in RPN
procedure {$i LCD3DS.inc}(colour: TRGB; y: u16; x: u16; screen:Pu8);stdcall;
{$undef Trap}
VAR	
  mvid : {$i LCD3DS.inc};// PRGBTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= {$i LCD3DS.inc}(screen);
  mvid^[y,x]:= colour; //.r;
 // mvid^[y,x,1]:= colour.g;
 // mvid^[y,x,2]:= colour.b;
END;
//kdl