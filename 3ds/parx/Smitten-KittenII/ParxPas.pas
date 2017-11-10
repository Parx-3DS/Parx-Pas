 
// Native Pascal Nintendo 3ds 
//
// Copyright (c) 2015 Kenny D. Lee
// all rights reserved.
//

{$ifndef NO_SMART_LINK}
{$smartlink on}
{$endif}
unit ParxPas;
 
{$mode objfpc}{$H+}
 
interface
 
uses
  ctypes;

{$packrecords c}
 
{$linklib libParx}

{$include parx_inf.inc}

{$linklib libctru}

{$include gfx.inc}

procedure initTest(Screen:Pu8); stdcall; public name 'initTest';
function CopyRight: PChar; stdcall; public name 'CopyRight'; 
procedure TestPattern; stdcall; public name 'TestPattern';
procedure MoveEllipse(Pos,posx,posy:integer); stdcall; public name 'MoveEllipse';
procedure Setbuffers(x: integer); stdcall; public name 'SetTopFramebuffers';
procedure SetFramebuffers; stdcall; public name 'SetFramebuffers';

procedure PScale3d(x,y,z:integer); stdcall; public name 'PScale3d';

type
//TRGB = record
//b,g,r:u8;
//end; 

//24bit triplet
//TRGB= array[0..2] of u8;
//TRGBALED= array[0..3] of u8;

DECI = 0..16777215;
HEX = 0..$ffffff;
//OCT = 0..77777777;

BoolBit= array[0..23] of boolean; 

TBGR = record
b,g,r:u8;
end; 

TVect = record
x,y,z: s16; 
end;


//TRGB = packed record
//  case byte of
//   0: (hex: trange);
 //  1: (X: TBGR);
 //  2: (BRG: array[0..2] of u8);
 //  3: (BoolBit: array[0..23] of boolean);
//end;


procedure PasClrSrc(screen:Pu8; colour: TBGR);stdcall; public name 'PasClrSrc';
procedure PasBotfill(Screen:Pu8); stdcall; public name 'PasBotfill';
procedure PasTopfill(Screen:Pu8); stdcall; public name 'PasTopfill';

procedure PSetPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'PSetPix';

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: HEX);stdcall; overload; // meat for the name magala

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; overload; // meat for the name magala

procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'SetGFXPix';
function PGetPix(screen:Pu8; x: u16; y: u16): TBGR;stdcall; public name 'PGetPix';
{
procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: TBGR);stdcall; public name 'BotLCD';
procedure TopMap(colour: TBGR; y: u16; x: u16; screen:Pu8);stdcall; public name 'TopMap';
procedure BotMap(colour: TBGR; y: u16; x: u16; screen:Pu8);stdcall; public name 'BotMap';
}
procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: DECI);stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: DECI);stdcall; public name 'BotLCD';
procedure TopMap(colour: DECI; y: u16; x: u16; screen:Pu8);stdcall; public name 'TopMap';
procedure BotMap(colour: DECI; y: u16; x: u16; screen:Pu8);stdcall; public name 'BotMap';

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: Hex);stdcall; overload; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: HEX);stdcall; overload; public name 'BotLCD';
procedure TopMap(colour: HEX; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'TopMap';
procedure BotMap(colour: HEX; y: u16; x: u16; screen:Pu8);stdcall; overload; public name 'BotMap';

procedure TopLCD(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16;colour: BoolBit);stdcall; public name 'BotLCD';
procedure TopMap(colour: BoolBit; y: u16; x: u16; screen:Pu8);stdcall; public name 'TopMap';
procedure BotMap(colour: BoolBit; y: u16; x: u16; screen:Pu8);stdcall; public name 'BotMap';


procedure ExTran3d(m,t:TVect); stdcall; public name 'ExTran3d';

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

// ... BGR BOOL HEX DEC
{
BGRTopL= array[0..96000] of TBGR; //240×400
PBGRTopL= ^BGRTopL;
BGRTop= array[0..399,0..239] of TBGR; //240×400
PBGRTop= ^BGRTop;

BGRBotL= array[0..76800] of TBGR; //240×320
PBGRBotL= ^BGRBotL;
BGRBot= array[0..319,0..239] of TBGR; //240×320
PBGRBot= ^BGRBot;

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

DECTopL= array[0..96000] of DEC; //240×400
PDECTopL= ^DECTopL;
DECTop= array[0..399,0..239] of DEC; //240×400
PDECTop= ^DECTop;

DECBotL= array[0..76800] of DEC; //240×320
PDECBotL= ^DECBotL;
DECBot= array[0..319,0..239] of DEC; //240×320
PDECBot= ^DECBot;
}

{$i buffrun.inc}

  TopLED =  record
    case word of
      0: (lin: TopRawLinear);
      1: (map: TopMapLED);
      2: (buf: pu8);
  end;

  BotLED =  record
    case word of
      0: (lin: BotRawLinear);
      1: (map: BotMapLED);
      2: (buf: pu8);
  end;

VideoBuff = record
LEDL: TopLED;
LEDR: TopLED;
LEDB: BotLED;
end; 
var 
bufnum: integer = 0;

function slope(x,y: u16):double; stdcall;
begin
  Result:=  (x / y);
end;


function Area(x,y: u16):u32; stdcall;
begin
  Result:=  x * y;
end;

function TriArea(x,y: u16):u16; stdcall;
begin
  Result:= Area(x,y) shr 1;
end;

function Pow2(x: u16):u32; stdcall;
begin
  Result:= x * x;
end;

function Pow(x, n: u16):u32; stdcall;
var i: u16;
begin
 Result := Pow2(x);
 if n > 2 then 
  for i := 1 to n do Result := Result * x;
end;

function Pith(x,y: u16):u16; stdcall;
begin
  Result:= Pow2(x) + Pow2(y);
end;

function abs(x: integer):integer; stdcall;
begin
//if x > -1 then Result:= x else Result := -x  
end;

//Revised --> http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
procedure Pasline(screen: pu8; x0, y0, x1, y1:integer; colour: u32); stdcall;
var
dx,dy,sx,sy,err,e2: integer;
begin
  dx := abs(x1-x0); if x0 < x1 then sx := 1 else sx := -1;
  dy := abs(y1-y0); if y0 < y1 then sy := 1 else sy := -1; 
  if (dx > dy) then err := dx else err := -dy;
  err := err shr 1;
 
  repeat
    SetPix(screen,x0,y0,colour);
 //   if (x0=x1) and (y0=y1) then break;
    e2 := err;
    if (e2 > -dx) then begin err -= dy; x0 += sx; end;
    if (e2 < dy)  then begin err += dx; y0 += sy; end;
  until ((x0=x1) and (y0=y1));
end;//kdl

//along x,y,z A star 
//next more theta & 3D harmonic breaks as the line steps from z's 0 .. normal .. infinity 
procedure Exline3d(colour: u32; rl, ll, nxy :TVect); //119,199 is normal to viewer
var
zav: integer;
begin

   zav := (rl.z + ll.z) shl 2;
      if (rl.z > ll.z) then // ^ 399,398,397,.. is in
	begin
         line(ParxRight,nxy.x+rl.x, nxy.y+rl.y, nxy.x+ll.x + (ll.z + zav), nxy.y + ll.y, colour);
         line(ParxLeft,nxy.x+rl.x - (rl.z + zav), nxy.y + rl.y, nxy.x+ll.x, nxy.y + ll.y ,colour);
 	 end    
     else if (rl.z < ll.z) then // 0,1,2,...  is out
	begin
         line(ParxRight,nxy.x+rl.x, nxy.y+rl.y, nxy.x+ll.x - ll.z, nxy.y+ ll.y, colour);
         line(ParxLeft ,nxy.x+rl.x + rl.z, nxy.y+ rl.y, nxy.x+ll.x, nxy.y+ ll.y ,colour);
	end;
end;

procedure pline3d(colour: u32; rl, ll:TVect); 
const
nx3DS=199;
ny3DS=119;
var
dx :TVect;
begin
dx.x := nx3DS;
dx.y := ny3DS;
dx.z := 0;
 Exline3d(colour, rl, ll, dx)
end;

procedure PScale3d(x,y,z:integer);
var
liner,linel:TVect;
begin
liner.x:=1*x;
liner.y:=1*y;
liner.z:=1*z;

linel.x:=3*x;
linel.y:=3*y;
linel.z:=-1*z;
pline3d(BLUE,liner,linel);

liner.x:=3*x;
liner.y:=1*y;
liner.z:=1*z;
pline3d(GREEN,liner,linel);

linel.x:=1*x;
linel.y:=3*y;
linel.z:=-1*z;
pline3d(RED,liner,linel);
end;


//void Trans3d(int tx, int ty, int z)
procedure ExTran3d(m,t :TVect); stdcall;
var
liner,linel:TVect;
begin
liner.x:=(1*m.x)-t.x;
liner.y:=(1*m.y)-t.y;
liner.z:=(1*m.z)-t.z;

linel.x:=(3*m.x)-t.x;
linel.y:=(3*m.y)-t.y;
linel.z:=(-1*m.z)-t.z;
pline3d(BLUE,liner,linel);

liner.x:=(3*m.x)-t.x;
liner.y:=(1*m.y)-t.y;
liner.z:=(1*m.z)-t.z;
pline3d(GREEN,liner,linel);

linel.x:=(1*m.x)-t.x;
linel.y:=(3*m.y)-t.y;
linel.z:=(-1*m.z)-t.z;
pline3d(RED,liner,linel);
end;

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
Pith(x,y);
//slope(x,y);
TriArea(x,y);
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


procedure initTest(screen:Pu8); stdcall;
begin
  CanvasString(screen, 'CPAD moves dirgibal',20,30, CYAN);
  CanvasString(screen, 'Y: Resets Three-ds video toaster-A500',20,40,CYAN);
  CanvasString(screen, 'Try out [Y]CPAD[r][l][X]',10,60,CYAN);
  CanvasString(screen, 'FreePascal on a 3DS!', 10,20, LIGHT_GREEN);
end;

var lastPos,lposx,lposy: integer;  
 
procedure MoveEllipse(Pos,posx,posy:integer); stdcall;
begin  

  if posy < 219 then EllipseSample(ParxRight, posx, posy, 1, 20, lastPos, 1, ParxBot);

  Ellipse(ParxLeft, lposx, lposy,  20, 10, lastPos, BLACK); // 50, 150,
  Ellipse(ParxRight, lposx, lposy, 20, 10, lastPos, BLACK); // 349, 150,
  gfxFlushBuffers;
//  gfxSwapBuffers;
 lastPos := Pos;
 lposx   := posx;
 lposy   := posy;
  Ellipse(ParxLeft, posx,posy, 20, 10, Pos, BLUE);
  Ellipse(ParxRight, posx,posy, 20, 10, Pos, BLUE);
end;

procedure Setbuffers(x: integer); stdcall;
begin
  gfxTopLeftFramebuffers[x] := gfxGetFramebuffer(GFX_TOP,GFX_LEFT,nil,nil); 
  gfxTopRightFramebuffers[x] := gfxGetFramebuffer(GFX_TOP,GFX_RIGHT,nil,nil); 
  gfxBottomFramebuffers[x] := gfxGetFramebuffer(GFX_BOTTOM,GFX_LEFT,nil,nil);
  bufnum:= x; 
end;

procedure SetFramebuffers; stdcall;
begin
  ParxLeft := gfxGetFramebuffer(GFX_TOP,GFX_LEFT,nil,nil); 
  ParxRight := gfxGetFramebuffer(GFX_TOP,GFX_RIGHT,nil,nil); 
  ParxBot := gfxGetFramebuffer(GFX_BOTTOM,GFX_RIGHT,nil,nil); 
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


procedure SetGFXPix(screen:Pu8; x: u16; y: u16;colour: HEX);stdcall; overload; //& make a C call 
VAR	
  mvid : PHexTopL; // PTopRawLinear; // absolute screen;
  v:u32;
BEGIN
  mvid:= PHexTopL(screen);
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

{$define ScBool}
{$i DiCa24.inc}
{$undef ScBool}

{$define ScHex}
{$i DiCa24.inc}
{$undef ScHex}

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