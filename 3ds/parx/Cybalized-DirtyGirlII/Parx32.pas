//copyrights 2017 Kenneth Dwayne Lee 

unit Parx32;
 
{$mode objfpc}{$H+}
 
interface
 
        
//32bit Quad
//TRGBA= array[0..3] of u8;

type
DEC32 = 0..4294967295;
HEX32 = 0..$ffffffff;
OCT32 = 0..&37777777777;
BIN32 = 0..%11111111111111111111111111111111;

BoolBit32= array[0..31] of boolean; 
Byte32= array[0..3] of Byte;

TRGBA = record
r,g,b,a:Byte;
end; 

 ColourExt = record
 case longint of
  0 : (N : TRGBA);
  1 : (D : DEC32);
  2 : (H : HEX32);
  3 : (O : OCT32);
  4 : (B : BIN32);
  5 : (Bools: BoolBit32); 
  6 : (Bytes: Byte32); 
 end; 
 


RGBATopi= array[0..96000] of TRGBA; //240×400
PRGBATopi= ^RGBATopi;
RGBABoti= array[0..76800] of TRGBA; //240×320
PRGBABoti= ^RGBABoti;

RGBATop= array[0..399,0..239] of TRGBA; //240×400
PRGBATop= ^RGBATop;
RGBABot= array[0..319,0..239] of TRGBA; //240×320
PRGBABot= ^RGBABot;

{$define Quad}
{.$i GFXMethodDef.inc}
{$undef Quad}

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


{$.i GFXMethodTable.inc}

{$undef Quad}

//I'd like too spank "lets play, pick a hole" for every thing !!!  
function GetPixL(x: word; y: word): TRGBA;stdcall;
BEGIN
  GetPixL:= TRGBA(gfxTopLeftFramebuffers[BuffIndex]^[x,y]);
END;
 
function GetPixR(x: word; y: word): TRGBA;stdcall;
BEGIN
  GetPixR:= TRGBA(gfxTopRightFramebuffers[BuffIndex]^[x,y]);
END;
  
function GetPixB(x: word; y: word): TRGBA;stdcall;
VAR	
  v:longint;
  c: TRGBA;
BEGIN
  y := 239-y;
  v:= (y+x*240)*3;
  c.r:= gfxBottomFramebuffers[BuffIndex]^[v];
  c.g:= gfxBottomFramebuffers[BuffIndex]^[v+1];
  c.b:= gfxBottomFramebuffers[BuffIndex]^[v+2];
  c.a:= gfxBottomFramebuffers[BuffIndex]^[v+3];
  GetPixB:= c;
END;

// 
procedure SetPixL(x: word; y: word;colour: TRGBA);stdcall; 
BEGIN
  gfxTopLeftFramebuffers[BuffIndex]^[x,y]:= BYTE32(colour)
END;

//comment out untill tests  
procedure SetPixR(x: word; y: word;colour: TRGBA);stdcall; 
BEGIN
  gfxTopRightFramebuffers[BuffIndex]^[x,y]:= BYTE32(colour)
END;

//assert define ln 62 (PBotRawLinear Vs. PBotMapLED) gfx.inc?
procedure SetPixB(x: word; y: word;colour: TRGBA);stdcall; 
var
  v:longint;
BEGIN
  y := 239-y;
  v:= (y+x*240)*4;
  gfxBottomFramebuffers[BuffIndex]^[v]:= colour.b;
  gfxBottomFramebuffers[BuffIndex]^[v+1]:= colour.g;
  gfxBottomFramebuffers[BuffIndex]^[v+2]:= colour.r;
  gfxBottomFramebuffers[BuffIndex]^[v+3]:= colour.a;
END;

//  
procedure TopByteFill(screen:PByte; Interval:BYTE; Pitch: BYTE);stdcall;
Var
  x,y: integer;
  mvid : PTopMapLED; // PBGRTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= PTopMapLED(screen);
        for x :=  0 to 399 do 
        for y :=  0 to 239 do  
  mvid^[x,y,Interval]:= Pitch //.r; 
END;

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