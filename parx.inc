copyrights 2016 kenneth dwayne lee

    function SetCanvasPixel(screen,x,y,colour : longint) : longint;
    begin
      SetCanvasPixel:=SetCanvasPixelEx(screen,3,240,x,y,colour);
    end;

    function GetCanvasPixel(screen,x,y : longint) : longint;
    begin
      GetCanvasPixel:=GetCanvasPixelEx(screen,3,240,x,y);
    end;

    function SetRecRe(screen,Top,Left,Height,Width,Region : longint) : longint;
    begin
      SetRecRe:=SetRecEx(screen,Top,Left,Height,Width,Region,1,linear);
    end;

    function GetRecRe(screen,Top,Left,Height,Width : longint) : longint;
    begin
      GetRecRe:=GetRecEx(screen,Top,Left,Height,Width,3,linear);
    end;

    procedure Circle(screen: Pu8; cx: cint; cy: cint; radius: cint; u32: colour);
    begin
      Ellipse(screen, cx, cy, radius, radius, 0, colour);
    end;
kdl
