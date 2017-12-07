//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.

//I'll hunt the few remaining Modula $epretistS, learking behind a Red Dwarf hiding in a tartas... 
//what would the engine core of Tartas, (fetch on the open market) &or (collect the randsom from the BBC after)?    
unit ParxM;
 
{$mode objfpc}{$H+}
 
interface

const
no = 0;
yes = 1;  

off = no;
on = yes;      
     
//if she can to the spilts & Wire between two voltswagons, 
//& shove a motor controller up her ass for a glimps of etrenity &or just 2c god? 
type
BINSys = 0..%1;
OCTSys = 0..&1;
XBW = no .. yes;
//today in broom the honkey when taking a 
Switch //over &or up side your very owned pet honkey 
 = off .. on; //ooh. C that, that one ooh & got 3D sterio hobbled 
//what did that rodeosexfan / Mesale men convert / Just divorced 
//ever whip, shackle &or being 2 javac 2 fail, do to deserve that 
//the Oil & Gas Capital of Canada only knows
 
TBit = XBW;//boolean;


type
Parx3D = Class
	private
//        LScr,RScr,BScr: {function (index: integer):} PByte;
function GetPixL(x: word; y: word): PByte; virtual; abstract;
function GetPixR(x: word; y: word): PByte; virtual; abstract;
function GetPixB(x: word; y: word): PByte; virtual; abstract;
 
procedure SetPixL(x: word; y: word;colour: PByte); virtual; abstract;
procedure SetPixR(x: word; y: word;colour: PByte); virtual; abstract;
procedure SetPixB(x: word; y: word;colour: PByte); virtual; abstract;

//      protected
//	public
//	published
    property L3D[x: word; y: word]: PByte read GetPixL write SetPixL;
    property R3D[x: word; y: word]: PByte read GetPixR write SetPixR;
    property B3D[x: word; y: word]: PByte read GetPixB write SetPixB;

end;


//take a hercules over Sinclair,Texas? Then steer us in to the void?
NilFunc = Function():boolean;
TBitr = record
 case boolean of
  false : (No : NilFunc);
  true :  (Yes : record xbValue:BINSys end);
end;
    
 ColourExt = record
 case boolean of
  0 : (N : boolean);
  1 : (O : OCTSys);
  2 : (V : TBitr);
 end; 
				
TBWByte = record
 case Byte of
  false : (B : record R:BYTE end);
  true :  (Bl : record B0,B1,B2,B3,B4,B5,B6,B7:BINSys end);
end;
				
TBWWord = record
 case Word of
  false : (B : record xhi,xlo:BYTE end);
  true :  (Bl : record B0,B1,B2,B3,B4,B5,B6,B7,
                       B8,B9,B10,B11,B12,B13,B14,B15:BINSys end);
end;

BWTopi= array[0..95999] of TBit; //240×400
PBWTopi= ^BWTopi;
BWBoti= array[0..76799] of TBit; //240×320
PBWBoti= ^BWBoti;

XTop= array[0..399,0..239] of TBit; //240×400
PXTop= ^XTop;
XBot= array[0..319,0..239] of TBit; //240×320
PXBot= ^XBot;

TStifeB= array [0..239] of TBit; //240×boolean
TByteArrayV= array[0..29] of TBWByte;// Byte; //
TWordArrayV= array[0..15] of TBWWord; //Word; //
TDWordArrayV= array[0..7] of DWord; //??
TXArray= array[0..1499] of QWord; //??


Parx3DX = Class(Parx3D)
{$define MCRobot} 
{$define Trap}
{$i Regime_inf.inc}
{$undef Trap}
{$undef MCRobot}
end; 

implementation

uses 
 ParxVideoRAM;
 
//if her pussy hairy fit some giz in her ass 
{$define MCRobot} 
{$i BufferDef.inc}

{$define ParxGrid}
{$define TopMapped}
{.$define BotMapped} //comment out for PBotRawLinear usage
  {$include gfx.inc} 
{.$undef BotMapped}
{$undef TopMapped}
{$undef ParxGrid}
       
       //T. Sexpranks is on Channel 5 in "the, 3D sprite stuff", 
       //here honey give me the remote i'm going to flush it. I know where wii're staying ...     
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF //(239 * 399)? 
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF ?
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF //(239 * 339)??

{$define Trap}
{$i Regime.inc} //Join today  
{$undef Trap}

{$i IntervalPitch.inc}

{$undef MCRobot} //& give a gift &or bribe to the KGB leader of the Nintendo 3DS world 
//for his treatment of santa, rubber raindeers with shiny one up front at gregorian X-MAS time 
//someone shot santa, he had put on the suit & finished the...

procedure SetGFXPix(screen:Pbyte; x: word; y: word;colour: TBit);stdcall; overload; //& make a C call 
VAR	
//  c: ColourExt;
  mvid : PTopRawLinear; // PTopRawLinear; // absolute screen;
  v: longint;
BEGIN
//  c.Bools := colour;
{$R+}
  //gives error c.O := &2;
{$R+}
  mvid:= PTopRawLinear(screen);
  y := 239-y;
  v:= (y+x*240);
  mvid^[v]:= yes;
//  mvid^[v+1]:= lo(colour);
//  mvid^[v+2]:= c.n.b;
//  mvid^[v+3]:= c.n.a;
END;


end.