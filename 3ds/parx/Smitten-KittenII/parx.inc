//copyrights 2016 kenneth dwayne lee

    procedure SetPix(screen: Pu8; x,y: integer; colour : u32);cdecl;
    begin
      SetPixEx(screen,3,240,x,y,colour);
    end;

    function GetPix(screen: Pu8; x,y: integer): u32;cdecl;
    begin
      result:=GetPixEx(screen,3,240,x,y);
    end;

    procedure SetRecRe(screen: Pu8; Top,Left,Height,Width: integer; Region: Pu8);cdecl;
    begin
      SetRecEx(screen,Top,Left,Height,Width,Region,true,linear);
    end;

    function GetRecRe(screen: Pu8; Top,Left,Height,Width: integer) : Pu8;cdecl;
    begin
      GetRecRe:=GetRecEx(screen,Top,Left,Height,Width,3,linear);
    end;

    procedure Circle(screen: Pu8; cx,cy,radius: integer; colour:u32);cdecl;
    begin
      Ellipse(screen, cx, cy, radius, radius, 0, colour);
    end;

procedure ClrAll(colour: u32); stdcall;
begin
  ClrParx(ParxLeft, colour); 
  ClrParx(ParxRight, colour); 
  ClrParx(ParxBot, colour);
end;

procedure InitBufSingle(colour: u32); stdcall;
begin
  gfxSetDoubleBuffering(GFX_TOP,false);
  gfxSetDoubleBuffering(GFX_BOTTOM,false);
  
  ParxLeft := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
  ParxRight := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil); 
  ParxBot := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);
  ClrAll(colour);//  ClrAll(BLACK);
end;

procedure BufDubSub(colour: u32; index: u8); stdcall;
begin
  gfxTopLeftFramebuffers[index] := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
  ClrParx(gfxTopLeftFramebuffers[index], colour); 
  gfxTopRightFramebuffers[index] := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil);   
  ClrParx(gfxTopRightFramebuffers[index], colour); 
  gfxBottomFramebuffers[index] := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);
  ClrParx(gfxBottomFramebuffers[index], colour); 
end;

procedure InitBufDub(colour: u32); stdcall;
begin
//  gfxSetDoubleBuffering(GFX_TOP,true);
//  gfxSetDoubleBuffering(GFX_BOTTOM,true);
  BufDubSub(colour,0);
  BufDubSub(colour,1);
end;
//kdl
