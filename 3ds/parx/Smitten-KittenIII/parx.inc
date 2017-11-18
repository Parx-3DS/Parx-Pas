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

//& our cleanesnes is @  0..2 or 3 byte totals per Pixle   
procedure propriganda;
begin
 gfxSetScreenFormat(GFX_TOP, GSP_BGR8_OES);
 gfxSetScreenFormat(GFX_BOTTOM, GSP_BGR8_OES);
end;
	 
procedure InitParx(colour: u32); stdcall;
begin
  propriganda;
  gfxSetDoubleBuffering(GFX_TOP,false);
  gfxSetDoubleBuffering(GFX_BOTTOM,false);
  BufDubSub(-1);
  ClrAll(colour);//  ClrAll(BLACK);
end;

procedure BufDubClr(colour: u32; index: u8); stdcall;
begin
  BufDubSub(index);
  ClrParx(gfxTopLeftFramebuffers[index], colour); 
  ClrParx(gfxTopRightFramebuffers[index], colour);
  ClrParx(gfxBottomFramebuffers[index], colour); 
end;

//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"
procedure BufDubSub(index: s8); stdcall;
begin
 if index <> -1  then 
   begin
   gfxTopLeftFramebuffers[index] := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
   gfxTopRightFramebuffers[index] := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil);  
   gfxBottomFramebuffers[index] := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);
  end else
  begin
   ParxLeft := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
   ParxRight := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil); 
   ParxBot := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);
  end 
end;

procedure InitBufSingle(colour: u32); stdcall;
begin
  gfxSetDoubleBuffering(GFX_TOP,false);
  gfxSetDoubleBuffering(GFX_BOTTOM,false);
  BufDubSub(0);
end;

procedure InitBufDub(colour: u32); stdcall;
begin
  propriganda;
  gfxSetDoubleBuffering(GFX_TOP,true);
  gfxSetDoubleBuffering(GFX_BOTTOM,true);
  BufDubClr(colour,0);
  BufDubClr(colour,1);
end;

procedure RefreshBuffer(); stdcall;
begin 
 gfxFlushBuffers();
 if BuffIndex <> -1 then gfxSwapBuffers();
 if BuffIndex <> 1 then inc(BuffIndex) else dec(BuffIndex); 
end;
//kdl
