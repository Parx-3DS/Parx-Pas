// Copyright (c) 2017 PhD. Kenny D. Lee
//  
//  Illistrated in pascal resorting to Plan "B" long ago & still short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY OTHER Corprate logos & Trade Marks usage of "Must provide resonable funding!"  
//  "I present, now with strife" included for Nintendo 2DS .. 3DS Pascal Development? 
//  
// all rights reserved.
//

{$define Trap}
// x,y zero @ top of bottom screen
procedure {$i LCD3DS.inc}(screen:Pu8; x: u16; y: u16; colour:{$i PIXelView.inc});stdcall;
{$undef Trap} 
VAR	
  c: TripExt;
  mvid : {$i LCD3DS.inc}; // absolute screen;
  v:u32;
BEGIN
  c. {$i PIXelView.inc} := colour;
  mvid:= {$i LCD3DS.inc}(screen); 
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:=  c.BGR.b;
  mvid^[v+1]:= c.BGR.g;
  mvid^[v+2]:= c.BGR.r;
END;
//kdl