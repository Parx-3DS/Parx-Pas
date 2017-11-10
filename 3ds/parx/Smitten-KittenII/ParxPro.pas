//  Nintendo 2ds 3ds Live on Channel 5
//
//   24bit segnifgent smitten GFX, RPN kitten @ the house Hindu
//
// Copyright (c) 2017 PhD Kenny D. Lee
// ANY Corprate logos & Trade Marks usage &or portions of "Must provide resonable funding!"
// all rights reserved.

{$ifndef NO_SMART_LINK}
{$smartlink on}
{$endif}
unit ParxPro;
 
{$mode objfpc}{$H+}
 
interface
 
uses
  ctypes;

{$packrecords c}
 
{$linklib libParx}

{$include parx_inf.inc}

{$linklib libctru}

{$include gfx.inc}

        
type
//TRGB = record
//b,g,r:u8;
//end; 

//24bit triplet
//TRGB= array[0..2] of u8;
//TRGBALED= array[0..3] of u8;

//packed byte alignment in ord type assignments? 
//BGR is ok! Hex24 type of the mapped is garbaled & resembals linear 
//PasTopfill Vs. HexTopfill 

DEC24 = 0..16777215;
HEX24 = 0..$ffffff;
OCT24 = 0..&77777777;
BIN24 = 0..%111111111111111111111111;

BoolBit= array[0..23] of boolean; 
Byte24= array[0..2] of u8;

TBGR = record
b,g,r:u8;
end; 

 TripExt = record
 case longint of
  0 : (BGR : TBGR);
  1 : (D : DEC24);
  2 : (H : HEX24);
  3 : (O : OCT24);
  4 : (B : BIN24);
  5 : (Bools: BoolBit); 
  6 : (Bytes: Byte24); 
 end; 

{.$i buffrun.inc}

{$define ScBGR}
{.$i Buf24.inc}
{$undef ScBGR}

procedure PSetPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'PSetPix';

procedure TestPattern(); stdcall; public name 'TestPattern';

procedure PasClrSrc(screen:Pu8; colour: TBGR);stdcall; public name 'PasClrSrc';
procedure PasTopfill(screen:Pu8; colour: TBGR);stdcall; public name 'PasTopfill';
procedure HexTopfill(screen:Pu8);stdcall; public name 'HexTopfill';
procedure PasBotfill(screen:Pu8);stdcall; public name 'PasBotfill';

procedure Topfill1(); stdcall; public name 'Topfill1';
procedure Topfill2(); stdcall; public name 'Topfill2';
function CopyRight: PChar; stdcall; public name 'CopyRight';
function PGetPix(x: u16; y: u16): TBGR;stdcall; public name 'PGetPix';
{
procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: HEX24);stdcall; overload; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: HEX24);stdcall; overload; public name 'BotLCD';
procedure TopMap(colour: HEX24; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'TopMap';
procedure BotMap(colour: HEX24; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'BotMap';

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; overload; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; overload; public name 'BotLCD';
procedure TopMap(colour: BoolBit; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'TopMap';
procedure BotMap(colour: BoolBit; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'BotMap';
}



{$define ColVertLine}

{$define ScHex}
{.$i ParxPro.inc}
{$undef ScHex}

{$define ScBool}
{.$i ParxPro.inc}
{$undef ScBool}

{$define ScDec}
{.$i ParxPro.inc}
{$undef ScDec}

{$define ScBGR}
{$i ParxPro.inc}
{$undef ScBGR}

{$define ScBin}
{.$i ParxPro.inc}
{$undef ScBin}

{$define ScOct}
{.$i ParxPro.inc}
{$undef ScOct}

{$undef ColVertLine}

implementation

{$include parx.inc}

type	

//
TopRawLinear= array[0..287999] of u8; //240×400×3
PTopRawLinear= ^TopRawLinear;
BotRawLinear= array[0..230399] of u8; //240×320×3
PBotRawLinear= ^BotRawLinear;

//mapped
TopMapLED= array[0..399,0..239,0..2] of u8; 
PTopMapLED= ^TopMapLED;
BotMapLED= array[0..319,0..239,0..2] of u8; // y,x,c @ lengths
PBotMapLED= ^BotMapLED;

//
BGRTopl= array[0..96000] of TBGR; //240×400
PBGRTopl= ^BGRTopl;
BGRBotl= array[0..76800] of TBGR; //240×320
PBGRBotl= ^BGRBotl;

BGRTop= array[0..399,0..239] of TBGR; //240×400
PBGRTop= ^BGRTop;
BGRBot= array[0..319,0..239] of TBGR; //240×320
PBGRBot= ^BGRBot;

//VRAM Map
var 

        ParxLeft1 : PTopRawLinear absolute $1E6000;
        ParxRight1 : PTopRawLinear absolute $22C800;
        ParxBot1 : PBotRawLinear absolute $48F000;
                
        ParxLeft2 : TopMapLED absolute $273000;
        ParxRight2 : TopMapLED absolute $2B9800;
        ParxBot2 : BotMapLED absolute $48F800;
        
        
        ParxL1 : Pu8 absolute $22C501; // $2FE or 766 bytes upto $22C7FF
        ParxR1 : Pu8 absolute $272D01; // $2FE or 766 bytes upto $2B97FF
        ParxB1 : Pu8 absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF?


function CopyRight: PChar; stdcall;
begin
  Result:= 'Parx-GDI v1.3 2015 Kenny D Lee';
end;

procedure PasClrSrc(screen:Pu8; colour: TBGR);stdcall;
VAR	
  vid : PBotRawLinear;// absolute screen;
  lp, le: integer;
BEGIN
        vid:= PBotRawLinear(screen);
        lp:= 0;
        for le :=  0 to 76800 do 
       	begin			
{	        vid^[lp]:= colour[0];
	        vid^[lp+1]:= colour[1];
	        vid^[lp+2]:= colour[2];
}

	        vid^[lp]:= colour.b;
	        vid^[lp+1]:= colour.g;
	        vid^[lp+2]:= colour.r;

	lp+=3;
        end;
END;

//test worked!!
procedure PasBotfill(screen:Pu8);stdcall;
VAR	
  vid : PBotRawLinear;// absolute screen;
  le: integer;
BEGIN
        vid:= PBotRawLinear(screen);
        for le :=  0 to 230399 do 
       	begin	
	        vid^[le]:= $FF;
        end;
END;

//BGR test worked!! output @ bottem & right  
procedure PasTopfill(screen:Pu8; colour: TBGR);stdcall;
Var
  x,y: integer;
  mvid : PBGRTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= PBGRTop(screen);
        for x :=  0 to 199 do //half
        for y :=  0 to 119 do //half again 
  mvid^[x,y]:= colour //.r; 
END;

//Re: PHEX24Top &  mvid^[x,y]:= $FFFFFF in fact is passed as a LongInt
//weird output on video display, packed byte alignment in ord type assignments?  
procedure HexTopfill(screen:Pu8);stdcall;
Var
  x,y: integer;
  c: TripExt;
  mvid : PTopMapLED; // PBGRTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= PTopMapLED(screen);
  c.h := $FFFFFF;
        for x :=  0 to 199 do //half
        for y :=  0 to 119 do //half again 
  mvid^[x,y]:= c.Bytes // works & so I get to remove alot of type defines 
END;

//
procedure Topfill1;stdcall;
Var
  le: integer;
BEGIN

        for le := 0 to 287999 do 
       	begin	
	        ParxLeft1^[le]:= $CC;
                ParxRight1^[le]:= $CC;
        end;
END;

//
procedure Topfill2;stdcall;
Var
  x,y,c: integer;
BEGIN
        for x :=  0 to 399 do 
        for y :=  0 to 239 do
        for c :=  0 to 2 do 
       	begin
	        ParxLeft2[x,y,c]:= $FF;
                ParxRight2[x,y,c]:= $FF;
        end;

END;


// 
function PGetPix(x: u16; y: u16): TBGR;stdcall;
VAR	
  mvid : PTopRawLinear; // absolute screen;
  v:u32;
  c: TBGR;
BEGIN
  mvid:= PTopRawLinear(ParxRight1);
  y := 239-y;
  v:= (y+x*240)*3;
  c.r:= mvid^[v];
  c.g:= mvid^[v+1];
  c.b:= mvid^[v+2];
  PGetPix:= c;
END;

// x,y zero @ top screen 
procedure PSetPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall;
VAR	
  mvid : PBotRawLinear; // absolute screen;
  v:u32;
BEGIN
  mvid:= PBotRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour.r;
  mvid^[v+1]:= colour.g;
  mvid^[v+2]:= colour.b;
END;

// x,y zero @ bottom corner sold as in sci &or ++ in libs
// out proform SetGFXPix with less CPU cycles ?
procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; 
VAR	
  mvid : PTopMapLED; // PBGRTop absolute screen;
BEGIN
  mvid:= PTopMapLED(screen);
  mvid^[x,y]:= Byte24(colour) //.r;
 // mvid^[y,x,1]:= colour.g;
 // mvid^[y,x,2]:= colour.b;
END;

//colour pattern is solid 
procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: HEX24);stdcall; overload; //& make a C call 
VAR	
  c: TripExt;
  mvid : PTopRawLinear; //PTopMapLED; // PHEX24TopL absolute screen;
  v:u32;
BEGIN
  c.h := colour;
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:=  c.BGR.b;
  mvid^[v+1]:= c.BGR.g;
  mvid^[v+2]:= c.BGR.r;
END;

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; overload; //& make a C call 
VAR	
  c: TripExt;
  mvid : PTopRawLinear; // PTopRawLinear; // absolute screen;
  v:u32;
BEGIN
  c.Bools := colour;
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:=  c.BGR.b;
  mvid^[v+1]:= c.BGR.g;
  mvid^[v+2]:= c.BGR.r;
END;

//
{$define ScBool}
{$i DiCa24.inc}
{$undef ScBool}

{$define ScHex}
{$i DiCa24.inc}
{$undef ScHex}

{$define ScBin}
{$i DiCa24.inc}
{$undef ScBin}

{$define ScOct}
{$i DiCa24.inc}
{$undef ScOct}

{$define ScBGR}
{$i DiCa24.inc}
{$undef ScBGR}

//here @ the local 
{$define ScDec}
{$i DiCa24.inc}
{$undef ScDec}


procedure SetPixTop(x,y: integer; colour: Hex24); stdcall;
begin
//  SetGFXPix(gfxTopLeftFramebuffers[bufnum],x,y,colour);
//  SetGFXPix(gfxTopRightFramebuffers[bufnum],x,y,colour);
  SetGFXPix(ParxLeft,x,y,colour);
  SetGFXPix(ParxRight,x,y,colour);
//  TopMap(colour,y,x,ParxLeft);
//  TopMap(colour,y,x,ParxRight);
end;

procedure TestPattern(); stdcall;
var i,j: integer; 
begin
//test pattern 1st pass 
				for i := 0 to 79 do 
				  for j := 0 to 200 do 
begin
                                SetPixTop(i,j,$FF0000); //RED
                                SetPixTop(i+80,j, $FFFF00); //CYAN
                                SetPixTop(i+160,j,$00FFFF); //YELLOW
                                SetPixTop(i+240,j,$0);
                                SetPixTop(i+320,j,$0000FF);//BLUE				
end;
//test pattern 2nd pass 
				for i := 0 to 99 do 
				  for j := 201 to 239 do
begin
                                SetPixTop(i,j,$FF00FF);//PINK
                                SetPixTop(i+100,j,$00CC00); //LIGHT_GREEN
                                SetPixTop(i+200,j,$FFFFFF); //WHITE
                                SetPixTop(i+300,j,$FF9900); //ORANGE
end;
end;
 
//exports
//  GetAnswer;
 
end.