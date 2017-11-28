//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.

unit Parx24;
 
{$mode objfpc}{$H+}
 
interface
 
uses
//  ctypes;
 ParxM;
 
//24bit triplet
//TBGR= array[0..2] of u8;

//packed byte alignment in ord type assignments? 
//BGR is ok! Hex24 type of the mapped is garbaled & resembals linear 
//PasTopfill Vs. HexTopfill 

type
TBGR = record
b,g,r:Byte;
end; 


//DEC24 = 0..16777215;
HEX24 = 0..$ffffff; //# Sys 
//OCT24 = 0..&77777777;
//BIN24 = 0..%111111111111111111111111;

BoolBit24= array[0..31] of boolean; 
Byte24= array[0..2] of byte;

BGRTopi= array[0..95999] of TBGR; //240×400
PBGRTopi= ^BGRTopi;
BGRBoti= array[0..76799] of TBGR; //240×320
PBGRBoti= ^BGRBoti;

BGRTop= array[0..399,0..239] of TBGR; //240×400
PBGRTop= ^BGRTop;
BGRBot= array[0..319,0..239] of TBGR; //240×320
PBGRBot= ^BGRBot;

TStife24= array[0..239] of TBGR; //240×320

procedure Topfill1(); stdcall; public name 'Topfill1';
procedure Topfill2(); stdcall; public name 'Topfill2';
//procedure Topfill3(); stdcall; public name 'Topfill3';

//kinjunction with GetPixB ?
procedure PSetPixB(screen:PByte; x: word; y: word;colour: TBGR);stdcall; public name 'PSetPixB'; 
procedure PSetPixT(screen:PByte; x: word; y: word;colour: TBGR);stdcall; public name 'PSetPixT';

//works 
//function GetPixL(x: word; y: word): TBGR;stdcall; public name 'GetPixL';
//function GetPixR(x: word; y: word): TBGR;stdcall; public name 'GetPixR';
//function GetPixB(x: word; y: word): TBGR;stdcall; public name 'GetPixB';

//Works t&b, i'll say again I'm not in love persay, But she does give good   
//procedure SetPixL(x: word; y: word;colour: TBGR);stdcall; public name 'SetPixL';
//procedure SetPixR(x: word; y: word;colour: TBGR);stdcall; public name 'SetPixR';
//procedure SetPixB(x: word; y: word;colour: TBGR);stdcall; public name 'SetPixB';

procedure HexTopfill(screen:PByte);stdcall; public name 'HexTopfill';
procedure SetGFXPix(screen:PByte; x: word; y: word;colour: TBGR);stdcall; public name 'SetGFXPix';
procedure SetGFXPix(screen:PByte; x: word; y: word;colour: HEX24);stdcall; overload; 

procedure PasClrSrc(screen:PByte; colour: TBGR);stdcall; public name 'PasClrSrc';
procedure PasTopfill(screen:PByte; colour: TBGR);stdcall; public name 'PasTopfill';
procedure PasBotfill(screen:PByte);stdcall; public name 'PasBotfill';



type
 ColourExt = record
 case HEX24 of
  0 : (N : TBGR);
  1 : (O : HEX24); 
  2 : (Bytes: Byte24); 
  3 : (Bools: BoolBit24);
 end; 

{$define Triplet}
{$define Trap}
{.$STATIC ON}
//I3DSViewerInterface = Interface
//function GetPixL(x: word; y: word): {$i Propaganda.inc};
//function GetPixR(x: word; y: word): {$i Propaganda.inc};  
//function GetPixB(x: word; y: word): {$i Propaganda.inc}; 
 
//procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc});  
//procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc});  
//procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc});  
//end;
{$undef Trap}
{$undef Triplet}

//Parx3D24 = Class(Parx3D)  //(TInterfacedObject,I3DSViewerInterface)
{$define PascalPublic}
{$define Triplet}
{$define Trap}
{$i Regime_inf.inc}
{$undef Trap}
{$undef Triplet}
{$undef PascalPublic}
//end; 


implementation

uses 
 ParxVideoRAM;
 
{$define Triplet}
{$i BufferDef.inc}

{$define ParxGrid}
{$define TopMapped}
{.$define BotMapped} //comment out for PBotRawLinear usage
  {$include gfx.inc} 
{.$undef BotMapped}
{$undef TopMapped}
{$undef ParxGrid}

var                 
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF?

{$define Trap}
  {$i Regime.inc} 
{$undef Trap}

{$undef Triplet}

{$i IntervalPitch.inc}

// x,y zero @ top screen 
procedure PSetPixB(screen:PByte; x: word; y: word;colour: TBGR);stdcall;
VAR	
  mvid : PBotRawLinear; // absolute screen;
  v:longint;
BEGIN
  mvid:= PBotRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour.b;
  mvid^[v+1]:= colour.g;
  mvid^[v+2]:= colour.r;
END;

//
procedure PSetPixT(screen:PByte; x: word; y: word;colour: TBGR);stdcall;
VAR	
  mvid : PTopRawLinear; // absolute screen;
  v:longint;
BEGIN
  mvid:= PTopRawLinear(screen); 
//sliding is good & one to play with
//  mvid:= PTopRawLinear(Unaligned(@screen[239*3]));   
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:= colour.b;
  mvid^[v+1]:= colour.g;
  mvid^[v+2]:= colour.r;
END;

//Works in Double Buffing
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

//Works in Double Buffing
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
{procedure Topfill3;stdcall;
Var
  x,y: integer;
  P24:Parx3D24;
//  C:TBGR;
BEGIN
        P24:=Parx3D24.create;
    //    c.n.b := $FF;
    //    c.n.g := $FF;
     //   c.n.r := $FF;
        P24.ClExt.O := $000000; //assign ordinal val
        with P24 do for x :=  0 to 399 do 
        for y :=  0 to 239 do
       	begin
	        L3D[x,y]:= ClExt.n;
	        R3D[x,y]:= ClExt.n;    
	        if x >= 339 then 
	         Bot[x,y]:= ClExt.n;
        end;

        P24.Destroy;
        P24.free;
END;
}

procedure PasClrSrc(screen:PByte; colour: TBGR);stdcall;
VAR	
  vid : PBotRawLinear;// absolute screen;
  lp, le: integer;
BEGIN
        vid:= PBotRawLinear(screen);
        lp:= 0;
        for le :=  0 to 76799 do 
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
procedure PasBotfill(screen:PByte);stdcall;
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
procedure PasTopfill(screen:PByte; colour: TBGR);stdcall;
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
procedure HexTopfill(screen:PByte);stdcall;
Var
  x,y: integer;
  c: ColourExt;
  mvid : PTopMapLED; // PBGRTop; //PTopMapLED; // absolute screen;
BEGIN
  mvid:= PTopMapLED(screen);
  c.O := $FFFFFF;
        for x :=  0 to 199 do //half
        for y :=  0 to 119 do //half again 
  mvid^[x,y]:= c.Bytes // works & so I get to remove alot of type defines 
END;

// x,y zero @ bottom corner sold as in sci &or ++ in libs
// out proform SetGFXPix with less CPU cycles ?
procedure SetGFXPix(screen:PByte; x: word; y: word;colour: TBGR);stdcall; 
VAR	
  mvid : PTopMapLED; // PBGRTop absolute screen;
BEGIN
  mvid:= PTopMapLED(screen);
  mvid^[x,y]:= Byte24(colour) //.r;
 // mvid^[y,x,1]:= colour.g;
 // mvid^[y,x,2]:= colour.b;
END;

//colour pattern is solid 
procedure SetGFXPix(screen:PByte; x: word; y: word;colour: HEX24);stdcall; //& make a C call 
VAR	
  c: ColourExt;
  mvid : PTopRawLinear; //PTopMapLED; // PHEX24TopL absolute screen;
  v:longint;
BEGIN
  c.O := colour;
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240)*3;
  mvid^[v]:=  c.n.b;
  mvid^[v+1]:= c.n.g;
  mvid^[v+2]:= c.n.r;
END;

end.
