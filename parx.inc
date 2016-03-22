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
//kdl
