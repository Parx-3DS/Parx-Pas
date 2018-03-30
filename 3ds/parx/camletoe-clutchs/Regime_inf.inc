//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.
  
function GetPixL(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixL';{$else}overload; {$endif PascalPublic}  //override
function GetPixR(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixR';{$else}overload; {$endif PascalPublic}
function GetPixB(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixB';{$else}overload; {$endif PascalPublic}
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixL';{$else}overload; {$endif PascalPublic}
procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixR';{$else}overload; {$endif PascalPublic}
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixB';{$else}overload; {$endif PascalPublic}
					
    procedure ClrAll(colour: {$i Propaganda.inc});stdcall;   
    procedure propriganda;stdcall;

// movedto -> Parx_inf.inc
//    procedure BufSub(index: integer);stdcall;				
//    {$ifdef PascalPublic} public name 'BufSub';{$else}overload; {$endif PascalPublic}
    
    procedure BufClr(colour: {$i Propaganda.inc}; index: integer);stdcall;	
    {$ifdef PascalPublic} public name 'BufDubClr';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufSingle(colour: {$i Propaganda.inc});stdcall;		
    {$ifdef PascalPublic} public name 'InitBufSingle';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufDub(colour: {$i Propaganda.inc});stdcall;			
    {$ifdef PascalPublic} public name 'InitBufDub';{$else}overload; {$endif PascalPublic}


{.$ifndef PascalPublic}  
// protected
// private
var
    ClExt: ColourExt;
{.$endif PascalPublic}       
    
    property L3D[x: word; y: word]: {$i Propaganda.inc} read GetPixL write SetPixL;
    property R3D[x: word; y: word]: {$i Propaganda.inc} read GetPixR write SetPixR;
    property Bot[x: word; y: word]: {$i Propaganda.inc} read GetPixB write SetPixB;

//  hopefully I don't have to shake my own leg 
