//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.

//I'd like too spank "lets play, pick a hole" for every thing !!!  
function {$i Rastarfar.inc}.GetPixL(x: word; y: word): {$i Propaganda.inc}; {$ifdef Triplet} Public name 'GetPixL';{$endif Triplet}
BEGIN
  GetPixL:= {$i Propaganda.inc}(gfxTopLeftFramebuffers[BuffIndex]^[x,y]);
END;
 
function {$i Rastarfar.inc}.GetPixR(x: word; y: word): {$i Propaganda.inc}; {$ifdef Triplet} Public name 'GetPixR';{$endif Triplet}
BEGIN
  GetPixR:= {$i Propaganda.inc}(gfxTopRightFramebuffers[BuffIndex]^[x,y]);
END;
  
function {$i Rastarfar.inc}.GetPixB(x: word; y: word): {$i Propaganda.inc}; {$ifdef Triplet} Public name 'GetPixB';{$endif Triplet}
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
 
procedure {$i Rastarfar.inc}.SetPixL(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef Triplet} Public name 'SetPixL';{$endif Triplet} 
BEGIN
  gfxTopLeftFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

procedure {$i Rastarfar.inc}.SetPixR(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef Triplet} Public name 'SetPixR';{$endif Triplet} 
BEGIN
  gfxTopRightFramebuffers[BuffIndex]^[x,y]:= {$undef Trap}{$i Propaganda.inc} {$define Trap}(colour)
END;

//assert define (PBotRawLinear Vs. PBotMapLED) gfx.inc?
procedure {$i Rastarfar.inc}.SetPixB(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef Triplet} Public name 'SetPixB';{$endif Triplet} 
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
    
procedure {$i Rastarfar.inc}.propriganda;
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

constructor {$i Rastarfar.inc}.Create;
begin
 inherited Create();
end;

Destructor {$i Rastarfar.inc}.Destroy;
begin
 inherited Destroy();
end;


procedure {$i Rastarfar.inc}.ClrAll(colour: {$i Propaganda.inc});
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

//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"
Function {$i Rastarfar.inc}.GetSrcL(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap};[Public];
begin
 if index <> -1  then 
   begin
   gfxTopLeftFramebuffers[index] := PTopMapLED(gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil)); 
  end else
  begin
   Result := {$ifdef MCRobot}PXTop {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Top {$endif Sweet16}
    	     {$ifdef Triplet}PBGRTop {$endif Triplet}
	     {$ifdef Quad}PRGBATop{$endif Quad}(gfxTopLeftFramebuffers[index])^;  
  end 
end;

Function {$i Rastarfar.inc}.GetSrcR(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap};[Public]; 
begin
 if index <> -1  then 
   begin
   gfxTopRightFramebuffers[index] := PTopMapLED(gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil));  
  end else
  begin
   Result := {$ifdef MCRobot}PXTop {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Top {$endif Sweet16}
    	     {$ifdef Triplet}PBGRTop {$endif Triplet}
	     {$ifdef Quad}PRGBATop{$endif Quad}(gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil))^; 
  end 
end;

Function {$i Rastarfar.inc}.GetSrcB(index: integer):{$ifdef MCRobot}XBot {$endif MCRobot}
    						    {$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					            {$ifdef Triplet}BGRBot {$endif Triplet}
						    {$ifdef Quad}RGBABot{$endif Quad}; [Public];
begin
 if index <> -1  then 
   begin 
   gfxBottomFramebuffers[index] := PBotRawLinear(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil));
  end else
  begin
   Result := {$ifdef MCRobot}PXBot {$endif MCRobot}
             {$ifdef Sweet16}PRGB16Bot {$endif Sweet16}
    	     {$ifdef Triplet}PBGRBot {$endif Triplet}
    	     {$ifdef Quad}PRGBABot{$endif Quad}(gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil))^;
  end 
end;

procedure {$i Rastarfar.inc}.SetSrcL(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap});[Public];
begin
 if index <> -1  then 
   begin
    gfxTopLeftFramebuffers[index] := PTopMapLED(@Val); 
  end else
  begin
   LScr[index] := Val; 
  end 
end;

procedure {$i Rastarfar.inc}.SetSrcR(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap}); [Public];
begin
 if index <> -1  then 
   begin
   gfxTopRightFramebuffers[index] := PTopMapLED(@Val); 
  end else
  begin
   RScr[index] := Val; 
  end 
end;

procedure {$i Rastarfar.inc}.SetSrcB(index: integer; Val :{$ifdef MCRobot}XBot {$endif MCRobot}
    							  {$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    							  {$ifdef Triplet}BGRBot {$endif Triplet}
						          {$ifdef Quad}RGBABot{$endif Quad}); [Public];
begin
 if index <> -1  then 
   begin
    gfxBottomFramebuffers[index] := PBotRawLinear(@Val);
  end else
  begin
    BScr[index] := Val;
  end 
end;
    
//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"
procedure {$i Rastarfar.inc}.BufDubSub(index: integer); 
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
//  walk'n on, walk'n on the mammoon 
