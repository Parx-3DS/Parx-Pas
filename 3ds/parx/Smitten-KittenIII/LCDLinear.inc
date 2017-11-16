// Copyright (c) 2017 PhD. Kenny D. Lee
//  
//  Illistrated in pascal resorting to Plan "B" long ago & still short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY OTHER Corprate logos & Trade Marks usage of "Must provide resonable funding!"
//
//		 Handles GSP_FramebufferFormats of IBM & MicroSoft "GSP_RGBA8_OES" 
//		           or "GSP_BGR8_OES" without an alpha, thire propaganda &or treacheries!!! 
//  
//  "I Re-Present, & now with strife" included for Nintendo 2DS .. 3DS Pascal Development? 
//  
// all rights reserved.
//

{$define Trap}
// x,y zero @ top of bottom screen
procedure {$i LCD3DS.inc}(screen:PByte; x: word; y: word; colour:{$i PIXelView.inc});stdcall;
{$undef Trap} 
VAR	
  c: ColourExt;
  mvid : {$i LCD3DS.inc}; // absolute screen;
  v:longint;
BEGIN
  c. {$i PIXelView.inc} := colour;
  mvid:= {$i LCD3DS.inc}(screen); 
  y := 239-y;
  v:= (y+x*240)* {$i ZeroBase.inc} ; 
  mvid^[v]:=  c.Bytes[0];
  mvid^[v+1]:= c.Bytes[1];//n.g;
  mvid^[v+2]:= c.Bytes[2]; //n.r; 
 {$ifdef Quad} 
  mvid^[v+3]:= c.n.a;
 {$endif Quad}
END;
//kdl