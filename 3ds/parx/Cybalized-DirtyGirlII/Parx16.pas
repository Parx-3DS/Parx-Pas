//Everyone has to face there own 16bit evils some time, or a other 
//
//I've organized your journey into 
//        &or
///  from the bowels of 
//
//as to "why & where is this, the red dwarf?" 
//& rgb16 format true, true, true, Nintendo 2DS .. 3DS Channel 5 Live from -39 & a wind chill plus?

//is avail in 3D, on boob your area?
//--> http://www.google.ca/search?q=secam+pal 
 
//(when two tribe goto &or it's love on) Xerox's common user interface. Thire in the parc; doing it; cum quickly
//--> http://www.google.ca/search?q=kde+gnome+comparison

unit Parx16;
 
{$mode objfpc}{$H+}
 
interface

type
DEC16 = 0..65535;
HEX16 = 0..$ffff;
OCT16 = 0..&177777;
BIN16 = 0..%1111111111111111;

BoolBit16= array[0..15] of boolean; 
Byte16= array[0..1] of Byte;

B6= array[0..5] of boolean; 
G6= array[0..5] of boolean; 

B5= array[0..5] of boolean; 
G5= array[0..5] of boolean; 

R5= array[0..4] of boolean; 

//mode 2 RGB5_A1_OES                  RGB  
TRGB565 = record
R:R5,
G:G6,
B:B5
end; 

//mode 3 RGB5_A1_OES                  RGBA  
TRGB5_A1 = record
R:R5,
G:G5,
B:B5,
A:boolean;
end; 

//mod 4 RGBA4_OES                    RGBA
TRGBA4 = record
R: array[0..3] of boolean,
G: array[0..3] of boolean,
B: array[0..3] of boolean,
A: array[0..3] of boolean;
end; 

//--> https://www.khronos.org/registry/OpenGL/extensions/OES/OES_compressed_paletted_texture.txt
TRGB16 = record
 case longint of
  0 : (W :word)
  1 : (cA1 : TRGB5_A1);
  2 : (c565 : TRGB565);
  3 : (cA4 : TRGBA4);
end; 
//--> https://github.com/Parx-3DS/Parx-Pas/blob/master/3ds/parx/Cybalized-DirtyGirlII/gfx.inc

 ColourExt = record
 case longint of
  0 : (N : TRGB16);
  1 : (D : DEC16);
  2 : (H : HEX16);
  3 : (O : OCT16);
  4 : (B : BIN16);
  5 : (Bools: BoolBit16); 
  6 : (Bytes: Byte16); 
 end; 
 
RGBATopi= array[0..96000] of TRGB16; //240×400
PRGBATopi= ^RGBATopi;
RGBABoti= array[0..76800] of TRGB16; //240×320
PRGBABoti= ^RGBABoti;

RGBATop= array[0..399,0..239] of TRGB16; //240×400
PRGBATop= ^RGBATop;
RGBABot= array[0..319,0..239] of TRGB16; //240×320
PRGBABot= ^RGBABot;

{$define Quad}
{$i GFXMethodDef.inc}
{$undef Quad}

implementation

uses 
 ParxVideoRAM;
 
{$define Quad}

{$i BufferDef.inc}
        
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF //(239 * 399)? 
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF ?
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF //(239 * 339)??


{$i GFXMethodTable.inc}

{$undef Quad}

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
