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
     
 //pilford -->https://github.com/kennyd-lee/ctru-pas/blob/master/3ds/services/gsp.inc      
     GSP_FramebufferFormats = (GSP_RGBA8_OES := 0,
				GSP_BGR8_OES := 1,
       GSP_RGB565_OES := 2,
				GSP_RGB5_A1_OES := 3, 
				GSP_RGBA4_OES := 4);


    imagebuff = record
        width : u16;
        height : u16;
        data : Pu8;
        depth : u8;
        used : bool;
      end;

    RamType = (linear := 0, vram:= 1, mappable:= 2);

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
        ParxTopLeft : Pu8;cvar;public;
        ParxTopRight : Pu8;cvar;public;

    procedure SetPixEx(screen:Pu8; bpp:u16; h,x,y:integer; colour:u32);cdecl;external;

    procedure SetPix(screen:Pu8; x,y: integer; colour: u32);cdecl;    

    function GetPixEx(screen:Pu8; bpp:u16; h,x,y:integer):u32;cdecl;external;

    function GetPix(screen:Pu8; x,y : integer):u32 ;cdecl;    

    procedure ClearParx(screen:Pu8; colour:u32);cdecl;external;

    procedure SetRecEx(screen:Pu8; Top,Left,Height,Width: integer;  Region:Pu8; CleanUp:bool; RamLocal:RamType);cdecl;external;

    procedure SetRecRe(screen:Pu8; Top,Left,Height,Width: integer; Region:Pu8);cdecl;    

    function GetRecEx(screen:Pu8; Top,Left,Height,Width: integer; bpp:u16; RamLocal:RamType):Pu8;cdecl;external;

    function GetRecRe(screen:Pu8; Top,Left,Height,Width: integer):Pu8; cdecl;    

    function CanvasChar(screen:Pu8; c:char; x,y:integer; colour:u32):cint;cdecl;external;

    function CanvasString(screen:Pu8; _string:pchar; x,y:integer; colour:u32):cint;cdecl;external;

    procedure line(screen:Pu8; x0,y0,x1,y1:integer; colour:u32);cdecl;external;

    procedure box(screen:Pu8; x,y,w,h: integer; colour:u32);cdecl;external;

    procedure poly(screen:Pu8; argv:pcint; argc:cint; colour:u32);cdecl;external;

    procedure CircleFill(screen:Pu8; xCen,yCen,radius:integer; colour:u32);cdecl;external;

    procedure Ellipse(screen: Pu8; xctr,yctr,majaxis,minaxis,rotnrad: integer; colour: u32);cdecl;external;

    procedure Circle(screen: Pu8; cx,cy,radius: integer; colour:u32);cdecl;

    function palletformat(FormatIndex:u8):GSPGPU_FramebufferFormats;cdecl;external;

    function bytes_per_pixel(format:GSPGPU_FramebufferFormats):u32;cdecl;external;
    
    procedure rgb_to_pixel(dst:Pu8; src:Pu8; format:GSPGPU_FramebufferFormats);cdecl;external;

    procedure pixel_to_rgba(dst:Pu8; src:Pu8; format:GSPGPU_FramebufferFormats);cdecl;external;

//(Lady Zurtch) v1.3 log 
//add GSP_FramebufferFormats for lib use 
//append PalletFormats & 
//Github::mtheall use of pallet context handling of  
//bytes_per_pixel, rgb_to_pixel, pixel_to_rgba  


//kdl

