//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.

unit Parx16;
 
{$mode objfpc}{$H+}
 
interface
 
        
//Sweet 16bit 
type
//DEC16 = 0..65535;
//HEX16 = 0..$ffff;
//OCT16 = 0..&177777;
BIN16 = 0..%1111111111111111;

BoolBit16= array[0..15] of boolean; 
Byte16= array[0..1] of Byte;

BIN4 = 0..%11;
BIN5 = 0..%111;
BIN6 = 0..%1111;

//OCT4 = 0..&3;
//OCT5 = 0..&7;
OCT6 = 0..&17;

//HEX4 = 0..$3;
//HEX5 = 0..$7;
HEX6 = 0..$F;

//DEC4 = 0..3;
//DEC5 = 0..7;
DEC6 = 0..15;

Colour4 = array[0..3] of boolean; 
Colour5 = array[0..4] of boolean;
Colour6 = array[0..5] of boolean;

//GSP_RGB565_OES				
TRGB565 = record
 case word of
  0 : (B : record R:BIN5; G:BIN6; B:BIN5 end);
  1 : (Bl : record R:Colour5; G:Colour6; B:Colour5 end);
end;

//GSP_RGB5_A1_OES 
TRGB5_A1 = record
 case word of
  0 : (B : record R,G,B:BIN5; A:boolean end);
  1 : (Bl : record R,G,B:Colour5; A:boolean; end);
end; 

//GSP_RGBA4_OES 
TRGBA4 = record
 case word of
  0 : (B : record R,G,B,A:BIN4 end);
  1 : (Bl : record R,G,B,A:Colour4 end);
end; 

TRGB16 = word;

//natural, ordinal, bytes, Bools & other propaganda's 
 ColourExt = record
 case word of
  0 : (N : TRGB16);
  1 : (O : BIN16);
  2 : (Bytes: Byte16);   //computer
  3 : (Bools: BoolBit16); //computer 
  4 : (c565 : TRGB565); //Colour delimated
  5 : (cA1 : TRGB5_A1); //Colour delimated
  6 : (c4 : TRGBA4); //Colour delimated
 end; 
 

RGB16Topi= array[0..96000] of TRGB16; //240×400
PRGB16Topi= ^RGB16Topi;
RGB16Boti= array[0..76800] of TRGB16; //240×320
PRGB16Boti= ^RGB16Boti;

RGB16Top= array[0..399,0..239] of TRGB16; //240×400
PRGB16Top= ^RGB16Top;
RGB16Bot= array[0..319,0..239] of TRGB16; //240×320
PRGB16Bot= ^RGB16Bot;

TStife16= array [0..239] of TRGB16; //240×TRGB16

{$define Sweet16}

{$define Trap}
{$i Regime_inf.inc}
{$undef Trap}

{$undef Sweet16}

implementation

uses 
 ParxVideoRAM;
 
{$define Sweet16}

{$i BufferDef.inc}

{$define ParxGrid}
{$define TopMapped}
{.$define BotMapped} //comment out for PBotRawLinear usage
  {$include gfx.inc} 
{.$undef BotMapped}
{$undef TopMapped}
{$undef ParxGrid}
       
       //quickly, KDE, gnome, ntsc, secam be a pal feed these babies &or valuse too the propaganda's   
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF //(239 * 399)? 
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF ?
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF //(239 * 339)??

{$define Trap}
{$i Regime.inc} //Join today  
{$undef Trap}

{$undef Sweet16}

procedure SetGFXPix(screen:Pbyte; x: word; y: word;colour: TRGB16);stdcall; overload; //& make a C call 
VAR	
  c: ColourExt;
  mvid : PTopRawLinear; // PTopRawLinear; // absolute screen;
  v: longint;
BEGIN
//  c.Bools := colour;
{$R+}
 // gives error c.n := &277777;
{$R+}
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*2;
  mvid^[v]:=  Hi(colour);
  mvid^[v+1]:= lo(colour);
//  mvid^[v+2]:= c.n.b;
//  mvid^[v+3]:= c.n.a;
END;

end.