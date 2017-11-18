unit Parx16;
 
{$mode objfpc}{$H+}
 
interface
 
        
//32bit Quad
//TRGBA= array[0..3] of u8;

type
DEC16 = 0..65535;
HEX16 = 0..$ffff;
OCT16 = 0..&177777;
BIN16 = 0..%1111111111111111;

BoolBit16= array[0..15] of boolean; 
Byte16= array[0..1] of Byte;

TRGB16 = record
C:word;
end; 

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