//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.

unit Parx32;
 
{$mode objfpc}{$H+}
 
interface
 
 uses ParxM;
        
//32bit Quad
//TRGBA= array[0..3] of u8;

type
//DEC32 = 0..4294967295;
HEX32 = 0..$ffffffff;
//OCT32 = 0..&37777777777;
//BIN32 = 0..%11111111111111111111111111111111;

BoolBit32= array[0..31] of boolean; 
Byte32= array[0..3] of Byte;

TRGBA = record
r,g,b,a:Byte;
end; 

 ColourExt = record
 case longint of
  0 : (N : TRGBA);
  1 : (O : HEX32);
  2 : (Bytes: Byte32); 
  3 : (Bools: BoolBit32); 
 end; 

RGBATopi= array[0..95999] of TRGBA; //240×400
PRGBATopi= ^RGBATopi;
RGBABoti= array[0..76799] of TRGBA; //240×320
PRGBABoti= ^RGBABoti;

RGBATop= array[0..399,0..239] of TRGBA; //240×400
PRGBATop= ^RGBATop;
RGBABot= array[0..319,0..239] of TRGBA; //240×320
PRGBABot= ^RGBABot;

TStife32= array[0..239] of TRGBA; //$%%cholic synonamis might be of

Parx3D32 = Class(Parx3DX)
{$define Quad}
{$define Trap}
{$i Regime_inf.inc}
{$undef Trap}
{$undef Quad}
end; 

implementation

uses 
 ParxVideoRAM;
 
{$define Quad}

{$i BufferDef.inc}

{$define ParxGrid}
{$define TopMapped}
{.$define BotMapped} //comment out for PBotRawLinear usage
  {$include gfx.inc} 
{.$undef BotMapped}
{$undef TopMapped}
{$undef ParxGrid}

        
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF //(239 * 399)? 
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF ?
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF //(239 * 339)??

{$define Trap}
{$i Regime.inc}
{$undef Trap}

{$undef Quad}

{$i IntervalPitch.inc}

//
procedure SetGFXPix(screen:Pbyte; x: word; y: word;colour: BoolBit32);stdcall; overload; //& make a C call 
VAR	
  c: ColourExt;
  mvid : PTopRawLinear; // PTopRawLinear; // absolute screen;
  v: longint;
BEGIN
  c.Bools := colour;
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*4;
  mvid^[v]:=  c.n.r;
  mvid^[v+1]:= c.n.g;
  mvid^[v+2]:= c.n.b;
  mvid^[v+3]:= c.n.a;
END;

end. 
