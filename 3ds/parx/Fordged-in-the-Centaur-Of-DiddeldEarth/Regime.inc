//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.

//I'd like too spank "lets play, pick a hole" for every thing !!!  
function GetPixL(x: word; y: word): {$i Propaganda.inc};stdcall; {$ifdef PascalPublic} Public name 'GetPixL';{$endif PascalPublic}
BEGIN
  GetPixL:= {$i Propaganda.inc}(gfxTopLeftFramebuffers[BuffIndex]^[x,y]);
END;

//  
function GetPixR(x: word; y: word): {$i Propaganda.inc};stdcall; {$ifdef PascalPublic} Public name 'GetPixR';{$endif PascalPublic}
BEGIN
  GetPixR:= {$i Propaganda.inc}(gfxTopRightFramebuffers[BuffIndex]^[x,y]);
END;

//  
function GetPixB(x: word; y: word): {$i Propaganda.inc};stdcall; {$ifdef PascalPublic} Public name 'GetPixB';{$endif PascalPublic}
VAR	
  v:longint;
  c: {$i Propaganda.inc};
BEGIN
  y := 239-y;
  v:= (y+x*240) {$ifdef MCRobot};  
  c:= gfxBottomFramebuffers[BuffIndex]^[v];
      {$endif MCRobot}{$ifdef Sweet16} * 2; 
  c:= (gfxBottomFramebuffers[BuffIndex]^[v] shr 4) + gfxBottomFramebuffers[BuffIndex]^[v+1];
      {$endif Sweet16}{$ifdef Triplet} * 3; 
  c.b:= gfxBottomFramebuffers[BuffIndex]^[v];
  c.g:= gfxBottomFramebuffers[BuffIndex]^[v+1];
  c.r:= gfxBottomFramebuffers[BuffIndex]^[v+2]; 
      {$endif Triplet}{$ifdef Quad} * 4;
  c.r:= gfxBottomFramebuffers[BuffIndex]^[v];
  c.g:= gfxBottomFramebuffers[BuffIndex]^[v+1];
  c.b:= gfxBottomFramebuffers[BuffIndex]^[v+2];
  c.a:= gfxBottomFramebuffers[BuffIndex]^[v+3];
      {$endif Quad}
  GetPixB:= c;
END;
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc});stdcall; {$ifdef PascalPublic} Public name 'SetPixL';{$endif PascalPublic} 
BEGIN
  gfxTopLeftFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc});stdcall; {$ifdef PascalPublic} Public name 'SetPixR';{$endif PascalPublic} 
BEGIN
  gfxTopRightFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

//assert define (PBotRawLinear Vs. PBotMapLED) gfx.inc?
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc});stdcall; {$ifdef PascalPublic} Public name 'SetPixB';{$endif PascalPublic} 
var
  v:longint;
BEGIN
  y := 239-y;
  v:= (y+x*240){$ifdef MCRobot};  
  gfxBottomFramebuffers[BuffIndex]^[v] := colour;
      {$endif MCRobot}{$ifdef Sweet16} * 2; 
  gfxBottomFramebuffers[BuffIndex]^[v]   := hi(colour); 
  gfxBottomFramebuffers[BuffIndex]^[v+1] := lo(colour);
      {$endif Sweet16}{$ifdef Triplet} * 3; 
  gfxBottomFramebuffers[BuffIndex]^[v]:= colour.b;
  gfxBottomFramebuffers[BuffIndex]^[v+1]:= colour.g;
  gfxBottomFramebuffers[BuffIndex]^[v+2]:= colour.r;
       {$endif Triplet}{$ifdef Quad} * 4;
  gfxBottomFramebuffers[BuffIndex]^[v]:= colour.r;
  gfxBottomFramebuffers[BuffIndex]^[v+1]:= colour.g;
  gfxBottomFramebuffers[BuffIndex]^[v+2]:= colour.b;
  gfxBottomFramebuffers[BuffIndex]^[v+3]:= colour.a;
  {$endif Quad}
END;
    
procedure propriganda;stdcall;
{$ifdef Sweet16}
var
mode:GSP_FramebufferFormats;
{$endif Sweet16}
begin

{$ifdef Sweet16} 
 if (GSP_16bit_OES <> (3 or 4)) then mode := GSP_RGB565_OES else //	 := 2,
 if (GSP_16bit_OES <> (2 or 4)) then mode := GSP_RGB5_A1_OES else //	 := 3,
 {if (GSP_16bit_OES <> (2 or 3)) then} mode := GSP_RGBA4_OES;     //	 := 4, 
{$endif Sweet16}

 gfxSetScreenFormat(GFX_TOP, {$ifdef MCRobot}GSP_BW_OES{$endif MCRobot} {$ifdef Sweet16}mode{$endif Sweet16}{$ifdef Triplet}GSP_BGR8_OES{$endif Triplet}{$ifdef Quad} GSP_RGBA8_OES{$endif Quad});
 gfxSetScreenFormat(GFX_BOTTOM, {$ifdef MCRobot}GSP_BW_OES{$endif MCRobot} {$ifdef Sweet16}mode{$endif Sweet16}{$ifdef Triplet}GSP_BGR8_OES{$endif Triplet}{$ifdef Quad} GSP_RGBA8_OES{$endif Quad});
end;

//{.$i Rastarfar.inc}.
{
constructor Create;// $i Rastarfar.inc .
begin
 inherited Create();
end;

Destructor Destroy;
begin
 inherited Destroy();
end;
}

procedure ClrAll(colour: {$i Propaganda.inc});stdcall;
Var
  x,y: integer;
begin
//    ClExt.O := colour; //assign ordinal val
        for x :=  0 to 399 do 
        for y :=  0 to 239 do
       	begin
	        L3D[x,y]:= colour; // ClExt.n;
	        R3D[x,y]:= colour; // ClExt.n;
	        if x >= 339 then 
                  Bot[x,y] := colour;
        end;
end;

var
        ParxBot :  {$i BMapper.inc};cvar;external; 
        ParxLeft : {$i Rastarfar.inc};cvar;external;
        ParxRight :{$i Rastarfar.inc};cvar;external;
    
//calls based in InitBufDub 
//ParxLeft := GetSrcL(0) or GetSrcL(1); 
Function GetSrcL(index: integer):{$i Rastarfar.inc};stdcall;[Public];
begin
 if index <> -1  then 
 case index of
  0 : Result := {$i Rastarfar.inc}(ParxLeft0);
  1 : Result := {$i Rastarfar.inc}(ParxLeft1); 
 end
    
  { Result := {$ifdef MCRobot}PXTop {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Top {$endif Sweet16}
    	     {$ifdef Triplet}PBGRTop {$endif Triplet}
	     {$ifdef Quad}PRGBATop{$endif Quad}(gfxTopLeftFramebuffers[index])^ }
 else
   Result := ParxLeft  
end;

Function GetSrcR(index: integer):{$i Rastarfar.inc};stdcall;[Public]; 
begin
 if index <> -1  then 
 case index of
  0 : Result := {$i Rastarfar.inc}(ParxRight0);
  1 : Result := {$i Rastarfar.inc}(ParxRight1); 
 end else 
   Result := ParxRight
end;

Function GetSrcB(index: integer):{$ifdef MCRobot}XBot {$endif MCRobot}
    						    {$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					            {$ifdef Triplet}BGRBot {$endif Triplet}
						    {$ifdef Quad}RGBABot{$endif Quad}; stdcall;[Public];
begin
 if index <> -1  then 
   Result := {$ifdef MCRobot}PXBot {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Bot {$endif Sweet16}
    	     {$ifdef Triplet}PBGRBot {$endif Triplet}
	     {$ifdef Quad}PRGBABot{$endif Quad}(gfxBottomFramebuffers[index])^ 
  // gfxBottomFramebuffers[index] := PBotRawLinear(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil));}
   else
   Result := {$ifdef MCRobot}PXBot {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Bot {$endif Sweet16}
    	     {$ifdef Triplet}PBGRBot {$endif Triplet}
    	     {$ifdef Quad}PRGBABot{$endif Quad}(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil))^;
end;
    
//calls in InitBufSingle 
//SetSrcL(-1,ParxLeft);	// jumping in and out of single & double it (glitchs &or freezes) feud if buffer aren't their
//
procedure SetSrcL(index: integer; Val :{$i Rastarfar.inc});stdcall; [Public];
begin
 if index <> -1  then 
 case index of
  0 : {$i Rastarfar.inc}(ParxLeft0) := Val;
  1 : {$i Rastarfar.inc}(ParxLeft1) := Val; 
 end
else
//   LScr[index] := Val; 
   ParxLeft := Val;
end;

procedure SetSrcR(index: integer; Val :{$i Rastarfar.inc}); stdcall;[Public];
begin
 if index <> -1  then 
 case index of
  0 : {$i Rastarfar.inc}(ParxRight0) := Val;
  1 : {$i Rastarfar.inc}(ParxRight1) := Val; 
 end 
  else
 //  RScr[index] := Val; 
   ParxRight := Val;
end;

procedure SetSrcB(index: integer; Val :{$ifdef MCRobot}XBot {$endif MCRobot}
    							  {$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    							  {$ifdef Triplet}BGRBot {$endif Triplet}
						          {$ifdef Quad}RGBABot{$endif Quad});stdcall; [Public];
begin
 if index <> -1  then 
   begin
    gfxBottomFramebuffers[index] := PBotRawLinear(@Val);
  end else
  begin
   BScr[index] := Val;
{    ParxBot :=    {$ifdef MCRobot}PXBot {$endif MCRobot}
                  {$ifdef Sweet16}PRGB16Bot {$endif Sweet16}
    	          {$ifdef Triplet}PBGRBot {$endif Triplet}
    	          {$ifdef Quad}PRGBABot{$endif Quad}(Val)^;
 }   	          
  //  ParxBot := PBotRawLinear(@Val);
  end 
end;
    
//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"
procedure BufDubSub(index: integer);stdcall; 
begin
 if index <> -1  then 
   begin
   gfxTopLeftFramebuffers[index] := PTopMapLED(gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil)); 
   gfxTopRightFramebuffers[index] := PTopMapLED(gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil));  
   gfxBottomFramebuffers[index] := PBotRawLinear(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil));
  end else
  begin
   LScr[index] := {$ifdef MCRobot}PXTop {$endif MCRobot}
                  {$ifdef Sweet16}PRGB16Top {$endif Sweet16}
    	          {$ifdef Triplet}PBGRTop {$endif Triplet}
	          {$ifdef Quad}PRGBATop{$endif Quad}(gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil))^; 
   RScr[index] := {$ifdef MCRobot}PXTop {$endif MCRobot}
                  {$ifdef Sweet16}PRGB16Top {$endif Sweet16}
    	          {$ifdef Triplet}PBGRTop {$endif Triplet}
	          {$ifdef Quad}PRGBATop{$endif Quad}(gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil))^; 
   BScr[index] := {$ifdef MCRobot}PXBot {$endif MCRobot}
                  {$ifdef Sweet16}PRGB16Bot {$endif Sweet16}
    	          {$ifdef Triplet}PBGRBot {$endif Triplet}
    	          {$ifdef Quad}PRGBABot{$endif Quad}(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil))^;
  end 
end;  

procedure BufDubClr(colour: {$i Propaganda.inc}; index: integer); stdcall;
begin
  BufDubSub(index);
  ClrAll(colour);
end;

procedure InitBufSingle(colour: {$i Propaganda.inc}); stdcall;
begin
  propriganda;
  gfxSetDoubleBuffering(GFX_TOP,false);
  gfxSetDoubleBuffering(GFX_BOTTOM,false);
  BufDubSub(0);
end;

procedure InitBufDub(colour: {$i Propaganda.inc}); stdcall;
begin
  propriganda;
  gfxSetDoubleBuffering(GFX_TOP,true);
  gfxSetDoubleBuffering(GFX_BOTTOM,true);
  BufDubClr(colour,0);
  BufDubClr(colour,1);
end;
//  walk'n on, walk'n on the mammoon 
