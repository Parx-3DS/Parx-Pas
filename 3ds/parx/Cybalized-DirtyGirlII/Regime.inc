//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.

//I'd like too spank "lets play, pick a hole" for every thing !!!  
function GetPixL(x: word; y: word): {$i Propaganda.inc};stdcall;
BEGIN
  GetPixL:= {$i Propaganda.inc}(gfxTopLeftFramebuffers[BuffIndex]^[x,y]);
END;
 
function GetPixR(x: word; y: word): {$i Propaganda.inc} ;stdcall;
BEGIN
  GetPixR:= {$i Propaganda.inc}(gfxTopRightFramebuffers[BuffIndex]^[x,y]);
END;
  
function GetPixB(x: word; y: word): {$i Propaganda.inc};stdcall;
VAR	
  v:longint;
  c: {$i Propaganda.inc};
BEGIN
  y := 239-y;
  v:= (y+x*240) * {$ifndef Quad} 3; 
  c.b:= gfxBottomFramebuffers[BuffIndex]^[v];
  c.g:= gfxBottomFramebuffers[BuffIndex]^[v+1];
  c.r:= gfxBottomFramebuffers[BuffIndex]^[v+2]; 
  {$else} 4;
  c.r:= gfxBottomFramebuffers[BuffIndex]^[v];
  c.g:= gfxBottomFramebuffers[BuffIndex]^[v+1];
  c.b:= gfxBottomFramebuffers[BuffIndex]^[v+2];
  c.a:= gfxBottomFramebuffers[BuffIndex]^[v+3];
  {$endif}
  GetPixB:= c;
END;
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc});stdcall; 
BEGIN
  gfxTopLeftFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc});stdcall; 
BEGIN
  gfxTopRightFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

//assert define (PBotRawLinear Vs. PBotMapLED) gfx.inc?
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc});stdcall; 
var
  v:longint;
BEGIN
  y := 239-y;
  v:= (y+x*240)* 
  {$ifndef Quad} 3; 
  gfxBottomFramebuffers[BuffIndex]^[v]:= colour.b;
  gfxBottomFramebuffers[BuffIndex]^[v+1]:= colour.g;
  gfxBottomFramebuffers[BuffIndex]^[v+2]:= colour.r;
  {$else} 4;
  gfxBottomFramebuffers[BuffIndex]^[v]:= colour.r;
  gfxBottomFramebuffers[BuffIndex]^[v+1]:= colour.g;
  gfxBottomFramebuffers[BuffIndex]^[v+2]:= colour.b;
  gfxBottomFramebuffers[BuffIndex]^[v+3]:= colour.a;
  {$endif}
END;
//  walk'n on, walk'n on the mammoon 
