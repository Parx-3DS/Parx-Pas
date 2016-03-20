copyrights 2016 kenneth dwayne Lee 

  Type
     Pu8 = ^u8;

    imagebuff = record
        width : u16;
        height : u16;
        data : Pu8;
        depth : u8;
        used : bool;
      end;

    RamType = (generic := 0,linear := 1,vram := 2);

    const
      RED = $FFFF0000;      
      GREEN = $FF00FF00;      
      BLUE = $FF0000FF;      
      CYAN = $FF00FFFF;      
      PINK = $FFFF00FF;      
      YELLOW = $FFFFFF00;      
      BLACK = $FF000000;      
      WHITE = $FFFFFFFF;      
      ORANGE = $FFFF9900;      
      LIGHT_GREEN = $FF00CC00;      
      PURPLE = $FF660033;      

      var
        transparent : u32;cvar;public;
        ParxBottom : Pu8;cvar;public;
        screenBottom : Pu8;cvar;public;
        screenBottom : Pu8;cvar;public;

    procedure SetPixEx(screen:Pu8; bpp:u16; h:cint; x:cint; y:cint; colour:u32);cdecl;external;

    procedure SetPix(screen:Pu8; x,y,colour: u32);cdecl;    

    function GetPixEx(screen:Pu8; bpp:u16; h:cint; x:cint; y:cint):u32;cdecl;external;

    function GetPix(screen:Pu8,x,y : cint): u32;cdecl;    

    procedure ClearCanvas(screen:Pu8; colour:u32);cdecl;external;

    procedure SetRecEx(screen:Pu8; Top:cint; Left:cint; Height:cint; Width:cint;  Region:Pu8; CleanUp:bool; RamLocal:RamType);cdecl;external;

    procedure SetRecRe(screen:Pu8; Top,Left,Height,Width: cint; Region:Pu8);cdecl;    

    function GetRecEx(screen:Pu8; Top:cint; Left:cint; Height:cint; Width:cint; bpp:u16; RamLocal:RamType):Pu8;cdecl;external;

    function GetRecRe(screen:Pu8; Top,Left,Height,Width: cint):Pu8; cdecl;    

    function CanvasChar(screen:Pu8; c:cchar; x:cint; y:cint; colour:u32):cint;cdecl;external;

    function CanvasString(screen:Pu8; _string:pcchar; x:cint; y:cint; colour:u32):cint;cdecl;external;

    procedure line(screen:Pu8; x0:cint; y0:cint; x1:cint; y1:cint; colour:u32);cdecl;external;

    procedure box(screen:Pu8; x:cint; y:cint; w:cint; h:cint; colour:u32);cdecl;external;

    procedure poly(screen:Pu8; argv:Ppcint; argc:cint; colour:u32);cdecl;external;

    procedure CircleFill(screen:Pu8; xCen:cint; yCen:cint; radius:cint; colour:u32);cdecl;external;

    procedure Ellipse(screen: Pu8; xctr: cint; yctr: cint; majaxis: cint; minaxis: cint; rotnrad: cint; u32: colour);cdecl;external;

    procedure Circle(screen: Pu8; cx: cint; cy: cint; radius: cint; u32: colour);cdecl;

kdl
