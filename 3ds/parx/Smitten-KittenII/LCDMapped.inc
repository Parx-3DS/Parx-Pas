// Copyright (c) 2017 PhD. Kenny D. Lee
//  
//  Illistrated in pascal resorting to Plan "B" long ago & still short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY OTHER Corprate logos & Trade Marks usage of "Must provide reasonable funding!"  
//  "I present, now with strife" included for Nintendo 2DS .. 3DS Pascal Development? 
//  
// all rights reserved.

{$define Trap}
// x,y zero @ bottom in RPN
procedure {$i LCD3DS.inc}({$ifdef ColVertLine} colour: array of {$else} colour:{$endif}{$i PIXelView.inc};{$ifndef ColVertLine} y: u16; {$endif}  x: u16; screen:Pu8);stdcall;
{$undef Trap}
TYPE
 Strife= Array[0..239, 0..2] Of Byte; 
VAR
  j: integer;	
  k: TripExt;
  c: {$ifndef ColVertLine} TripExt {$else} Strife {$endif};
  mvid : {$i LCD3DS.inc};// PRGBTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= {$i LCD3DS.inc}(screen);
  {$ifdef ColVertLine}
    for j:= 0 to 239 do
    begin
     k.{$i PIXelView.inc} := colour[j];
     c[j] := k.Bytes;
    end;
  mvid^[x]:= c; 
   {$else}
  mvid^[x,y]:= c.Bytes;  
//  mvid^[x,y,1]:= c.Bytes[1];  
//  mvid^[x,y,2]:= c.Bytes[2];  
  {$endif}
END;
//kdl