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

DEC24 = 0..16777215;
HEX24 = 0..$ffffff;
OCT24 = 0..&77777777;
BIN24 = 0..%111111111111111111111111;

BoolBit= array[0..23] of boolean; 

TBGR = record
b,g,r:u8;
end; 
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
{$i ParxPro.inc}
{$undef ScHex}

{$define ScBool}
{$i ParxPro.inc}
{$undef ScBool}

{$define ScDec}
{$i ParxPro.inc}
{$undef ScDec}

{$define ScBGR}
{.$i ParxPro.inc}
{$undef ScBGR}

{$define ScBin}
{$i ParxPro.inc}
{$undef ScBin}

{$define ScOct}
{$i ParxPro.inc}
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
BotMapLED= array[0..319,0..239,0..2] of u8; // y,x,c
PBotMapLED= ^BotMapLED;

//  BGR BOOL HEX DEC OCT BIN  ... 24bit
{
BoolTopL= array[0..96000] of BoolBit; //240×400
PBoolTopL= ^BoolTopL;
BoolTop= array[0..399,0..239] of BoolBit; //240×400
PBoolTop= ^BoolTop;

BoolBotL= array[0..76800] of BoolBit; //240×320
PBoolBotL= ^BoolBotL;
BoolBot= array[0..319,0..239] of BoolBit; //240×320
PBoolBot= ^BoolBot;

HexTopL= array[0..96000] of HEX; //240×400
PHexTopL= ^HexTopL;
HexTop= array[0..399,0..239] of HEX; //240×400
PHexTop= ^HexTop;

HexBotL= array[0..76800] of HEX; //240×320
PHexBotL= ^HexBotL;
HexBot= array[0..319,0..239] of HEX; //240×320
PHexBot= ^HexBot;
}

{$i buffrun.inc}

function CopyRight: PChar; stdcall;
begin
  Result:= 'Parx-GDI v1.3 2015 Kenny D Lee';
end;

procedure SetPixTop(x,y: integer; colour: u32); stdcall;
begin
//  SetPix(gfxTopLeftFramebuffers[bufnum],x,y,colour);
//  SetPix(gfxTopRightFramebuffers[bufnum],x,y,colour);
  SetPix(ParxLeft,x,y,colour);
  SetPix(ParxRight,x,y,colour);
end;

procedure TestPattern(); stdcall;
var i,j: integer; 
begin
//test pattern 1st pass 
				for i := 0 to 79 do 
				  for j := 0 to 200 do 
begin
                                SetPixTop(i,j,RED);
                                SetPixTop(i+80,j,CYAN);
                                SetPixTop(i+160,j,YELLOW);
                                SetPixTop(i+240,j,BLACK);
                                SetPixTop(i+320,j,BLUE);				
end;
//test pattern 2nd pass 
				for i := 0 to 99 do 
				  for j := 201 to 239 do
begin
                                SetPixTop(i,j,PINK);
                                SetPixTop(i+100,j,LIGHT_GREEN);
                                SetPixTop(i+200,j,WHITE);
                                SetPixTop(i+300,j,ORANGE);
end;
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

	        vid^[lp]:= colour.r;
	        vid^[lp+1]:= colour.g;
	        vid^[lp+2]:= colour.b;

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

//poops out ?! boot strapped 
procedure PasTopfill(screen:Pu8);stdcall;
VAR	
  lvid : PTopRawLinear; // absolute screen;
//  mvid : PTopMapLED; // absolute screen;
//  y,x,c: word;
  le: integer;
BEGIN
        for le := 0 to 287999 do 
       	begin	
	        lvid^[le]:= $FF;
        end;

{        for x :=  0 to 399 do 
        for y :=  0 to 239 do
        for c :=  0 to 2 do 
       	begin	
          mvid^[x,y,c]:= $00;
        end;}

END;


// 
function PGetPix(screen:Pu8; x: u16; y: u16): TBGR;stdcall;
VAR	
  mvid : PTopRawLinear; // absolute screen;
  v:u32;
  c: TBGR;
BEGIN
  mvid:= PTopRawLinear(screen);
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
  mvid : PBGRTopL; // PTopRawLinear; // absolute screen;
  v:u32;
BEGIN
  mvid:= PBGRTopL(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour //.r;
 // mvid^[v+1]:= colour.g;
 // mvid^[v+2]:= colour.b;
END;

// x,y zero @ bottom corner sold as in sci &or ++ in libs
// out proform PSetPix with less CPU cycles 
procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; 
VAR	
  mvid : PBGRTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= PBGRTop(screen);
  mvid^[y,x]:= colour //.r;
 // mvid^[y,x,1]:= colour.g;
 // mvid^[y,x,2]:= colour.b;
END;

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: HEX24);stdcall; overload; //& make a C call 
VAR	
  mvid : PHEX24TopL; // PTopRawLinear; // absolute screen;
  v:u32;
BEGIN
  mvid:= PHEX24TopL(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour //.r;
 // mvid^[v+1]:= colour.g;
 // mvid^[v+2]:= colour.b;
END;

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; overload; //& make a C call 
VAR	
  mvid : PBoolTopL; // PTopRawLinear; // absolute screen;
  v:u32;
BEGIN
  mvid:= PBoolTopL(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour //.r;
 // mvid^[v+1]:= colour.g;
 // mvid^[v+2]:= colour.b;
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
{.$i DiCa24.inc}
{$undef ScBGR}

//here @ the local 
{$define ScDec}
{$i DiCa24.inc}
{$undef ScDec}


//exports
//  GetAnswer;
 
end.