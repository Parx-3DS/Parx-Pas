// Copyright (c) 2017 PhD. Kenny D. Lee
//  
//  Illistrated in pascal resorting to Plan "B" long ago & still short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY OTHER Corprate logos & Trade Marks usage of "Must provide reasonable funding!"  
//
//		 Handles GSP_FramebufferFormats of IBM & MicroSoft "GSP_RGBA8_OES" 
//		           or "GSP_BGR8_OES" without an alpha, thire propaganda &or treacheries!!! 
//  
//  "I Re-Present, & now with strife" included for Nintendo 2DS .. 3DS Pascal Development? 
//  
// all rights reserved.

{$define Trap}
// x,y zero @ bottom in RPN
procedure {$i LCD3DS.inc}({$ifdef ColVertLine} colour: array of {$else} colour:{$endif}{$i PIXelView.inc};{$ifndef ColVertLine} y: word; {$endif}  x: word; screen:Pbyte);stdcall;
{$undef Trap}
VAR
  j: integer;	
  k: ColourExt;
  c: {$ifndef ColVertLine} ColourExt {$else} Strife {$endif ColVertLine};
  mvid : {$i LCD3DS.inc};// PRGBTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= {$i LCD3DS.inc}(screen);
  {$ifdef ColVertLine}
    for j:= 0 to 239 do
    begin
     k.{$i PIXelView.inc} := colour[j];
     c[j,0] := k.Bytes[0];  
     c[j,1]:= k.Bytes[1];  
     c[j,2]:= k.Bytes[2]; 
    {$ifdef Quad}  
     c[j,3]:= k.Bytes[3]; 
    {$endif Quad} 
    end;
  mvid^[x]:= c; 
   {$else ColVertLine}
  mvid^[x,y,0]:= c.Bytes[0];  
  mvid^[x,y,1]:= c.Bytes[1];  
  mvid^[x,y,2]:= c.Bytes[2];  
 {$ifdef Quad}  
  mvid^[x,y,3]:= c.Bytes[3]; 
 {$endif Quad}
  {$endif ColVertLine}
END;
//kdl