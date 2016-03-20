copyrights 2016 kenneth dwayne lee

    procedure SetPix(screen: Pu8; x,y: cint; colour : u32);
    begin
      SetPixEx(screen,3,240,x,y,colour);
    end;

    function GetPix(screen: Pu8; x,y: cint): u32;
    begin
      GetPixel:=GetPixEx(screen,3,240,x,y);
    end;

    procedure SetRecRe(screen: Pu8; Top,Left,Height,Width: cint; Region: Pu8);
    begin
      SetRecEx(screen,Top,Left,Height,Width,Region,1,linear);
    end;

    function GetRecRe(screen: Pu8; Top,Left,Height,Width: cint) : longint;
    begin
      GetRecRe:=GetRecEx(screen,Top,Left,Height,Width,3,linear);
    end;

    procedure Circle(screen: Pu8; cx: cint; cy: cint; radius: cint; u32: colour);
    begin
      Ellipse(screen, cx, cy, radius, radius, 0, colour);
    end;
kdl
