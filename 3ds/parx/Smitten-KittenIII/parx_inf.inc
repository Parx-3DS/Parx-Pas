//copyrights 2016 kenneth dwayne Lee 

  Type
     u8 = cuint8;
     pu8 = ^u8;
     u16 = cuint16;
     pu16 = ^u16;
     u32 = cuint32;
     pu32 = ^u32;
     u64 = cuint64;
     pu64 = ^u64;

     s8 = cint8;
     s16 = cint16;
     s32 = cint32;
     ps32 = ^s32;
     s64 = cint64;
     ps64 = ^s64;

     bool= boolean;

    imagebuff = record
        width : u16;
        height : u16;
        data : Pu8;
        depth : u8;
        used : bool;
      end;


    rect = record
        top,left,bottom,right : u16;
      end;
    Prect =^rect;  

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
        ParxBot : Pu8;cvar;public;
        ParxLeft : Pu8;cvar;public;
        ParxRight : Pu8;cvar;public;

// --> ParxGDI.h
    procedure SetPixEx(screen:Pu8; bpp:u16; h,x,y:integer; colour:u32);cdecl;external;
    procedure SetPix(screen:Pu8; x,y: integer; colour: u32);cdecl;    
    function GetPixEx(screen:Pu8; bpp:u16; h,x,y:integer):u32;cdecl;external;
    function GetPix(screen:Pu8; x,y : integer):u32 ;cdecl;    
    procedure ClrParx(screen:Pu8; colour:u32);cdecl;external;
    procedure SetRecEx(screen:Pu8; Top,Left,Height,Width: integer;  Region:Pu8; CleanUp:bool; RamLocal:RamType);cdecl;external;
    procedure SetRecRe(screen:Pu8; Top,Left,Height,Width: integer; Region:Pu8);cdecl;    
    function GetRecEx(screen:Pu8; Top,Left,Height,Width: integer; bpp:u16; RamLocal:RamType):Pu8;cdecl;external;
    function GetRecRe(screen:Pu8; Top,Left,Height,Width: integer):Pu8; cdecl;    

// --> Parx_Font.h
    function CanvasChar(screen:Pu8; c:char; x,y:integer; colour:u32):cint;cdecl;external;
    function CanvasString(screen:Pu8; _string:pchar; x,y:integer; colour:u32):cint;cdecl;external;

// --> Parx_Shapes.h
    procedure line(screen:Pu8; x0,y0,x1,y1:integer; colour:u32);cdecl;external;
    procedure box(screen:Pu8; x,y,w,h: integer; colour:u32);cdecl;external;
    procedure poly(screen:Pu8; argv:pcint; argc:cint; colour:u32);cdecl;external;
    procedure CircleFill(screen:Pu8; xCen,yCen,radius:integer; colour:u32);cdecl;external;
    procedure Ellipse(screen: Pu8; xctr,yctr,majaxis,minaxis,rotnrad: integer; colour: u32);cdecl;external;
    procedure Circle(screen: Pu8; cx,cy,radius: integer; colour:u32);cdecl;

    procedure lineSample(screen:Pu8; x0,y0,x1,y1:integer;buffer:Pu8);cdecl;external;
    procedure EllipseSample(screen: Pu8; xctr,yctr,majaxis,minaxis,rotnrad, DisplayAxis: integer; buffer: Pu8);cdecl;external;

// --> Parx_Fill.h
    procedure GradientFillRect(prc:Prect; radius:cint; mode:cint; s_col:u32; e_col:u32; screen:Pu8);cdecl;external;
    procedure FillRoundRect(prc:Prect; radius:cint; b_col:u32; f_col:u32; screen:Pu8);cdecl;external;
    procedure RoundRectShadow(prc:Prect; radius:cint; col:u32; length:cint; screen:Pu8);cdecl;external;
    procedure FillRect(prc:Prect; col:u32; screen:Pu8);cdecl;external;
    procedure FloodFill(x0:cint; y0:cint; fillColor:u32; interiorColor:u32; screen:Pu8);cdecl;external;

// ...
procedure ClrAll(colour: u32); stdcall;  public name 'ClrAll';
procedure InitBufSingle(colour: u32); stdcall; public name 'InitBufSingle';
procedure InitBufDub(colour: u32); stdcall; public name 'InitBufDub';


//call up the buffers 0 .. 1 for " ... & burst there double bubbles in 3D"
procedure BufDubSub(index: u8); stdcall; public name 'BufDubSub';
procedure BufDubClr(colour: u32; index: u8); stdcall; public name 'BufDubClr';
//kdl
