//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.


function GetPixL(x: word; y: word): {$i Propaganda.inc};stdcall; public name 'GetPixL';
function GetPixR(x: word; y: word): {$i Propaganda.inc};stdcall; public name 'GetPixR';
function GetPixB(x: word; y: word): {$i Propaganda.inc};stdcall; public name 'GetPixB';
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc});stdcall; public name 'SetPixL';
procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc});stdcall; public name 'SetPixR';
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc});stdcall; public name 'SetPixB';
				
    procedure ClrAll(colour: {$i Propaganda.inc});stdcall;   
    procedure propriganda;stdcall;

//call up the buffers & burst there double bubbles in 3D"
    procedure BufSub(index: integer);stdcall;				
    {$ifdef PascalPublic} public name 'BufSub';{$else}overload; {$endif PascalPublic}
    
    procedure BufDubClr(colour: {$i Propaganda.inc}; index: integer);stdcall;	
    {$ifdef PascalPublic} public name 'BufDubClr';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufSingle(colour: {$i Propaganda.inc});stdcall;		
    {$ifdef PascalPublic} public name 'InitBufSingle';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufDub(colour: {$i Propaganda.inc});stdcall;			
    {$ifdef PascalPublic} public name 'InitBufDub';{$else}overload; {$endif PascalPublic}

var
    ClExt: ColourExt;

//UCLA Berkeley, this is Pascal calling --> https://www.youtube.com/watch?v=xLy2SaSQAtA
    property L3D[x: word; y: word]: {$i Propaganda.inc} read GetPixL write SetPixL;
    property R3D[x: word; y: word]: {$i Propaganda.inc} read GetPixR write SetPixR;
    property Bot[x: word; y: word]: {$i Propaganda.inc} read GetPixB write SetPixB;

//  hopefully I don't have to shake my own leg 
