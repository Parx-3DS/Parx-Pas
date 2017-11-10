// Copyright (c) 2017 PhD. Kenny D. Lee
//  
//  Illistrated in pascal resorting to Plan "B" long ago & still short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY OTHER Corprate logos & Trade Marks usage of "Must provide resonable funding!"  
//  "I present, now with strife" included for Nintendo 2DS .. 3DS Pascal Development? 
//  
// all rights reserved.

{$define Trap}
// x,y zero @ bottom in RPN
procedure {$i LCD3DS.inc}({$ifdef ColVertLine} colour: array of {$else} colour:{$endif}{$i PIXelView.inc};{$ifndef ColVertLine} y: u16; {$endif}  x: u16; screen:Pu8);stdcall;
{$undef Trap}{$ifdef BotMapLED} {$define PNSB} {$else} {$define PNST} {$endif}
VAR	
  mvid : {$i PIXelView.inc};// PRGBTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= {$i PIXelView.inc}(screen);
  mvid^[x{$ifndef ColVertLine},y{$endif}]:= colour //.r;  
 // mvid^[y,x,1]:= colour.g;
 // mvid^[y,x,2]:= colour.b; 
END;
{$ifdef BotMapLED} {$undef PNSB} {$else} {$undef PNST} {$endif}
//kdl