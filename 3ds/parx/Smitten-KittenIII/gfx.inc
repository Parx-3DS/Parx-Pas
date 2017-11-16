//the Pascal translation of libctru headers files for the 2DS & 3DS platform
//
// Copyright (c) 2015, 2017 Kenny D. Lee
// all rights reserved
//
// If the Box didn't have a bow; twats that never felt or what it is to sexlive, for whom & why ... prude reasons? 
//!! poster sized is optional, Pix of before & after on the doors of any & all Christ's churches !!   

  type
     gfxScreen_t = (GFX_TOP := 0,GFX_BOTTOM := 1);
     gfx3dSide_t = (GFX_LEFT := 0,GFX_RIGHT := 1);


     GSP_FramebufferFormats = (GSP_RGBA8_OES := 0,
				GSP_BGR8_OES := 1,
                                GSP_RGB565_OES := 2,
				GSP_RGB5_A1_OES := 3, 
				GSP_RGBA4_OES := 4);
  {system stuff }
  procedure gfxInitDefault;cdecl;external;
  procedure gfxInit(topFormat,bottomFormat:GSP_FramebufferFormats;vrambuffers:boolean);cdecl;external;
  procedure gfxExit;cdecl;external;

  {control stuff }
  procedure gfxSet3D(enable:bool);cdecl;external;
  function gfxIs3D:boolean;cdecl;external;
  procedure gfxFlushBuffers;cdecl;external;
  procedure gfxSwapBuffers;cdecl;external;
  procedure gfxSwapBuffersGpu;cdecl;external;

  {helper stuff }
  function gfxGetFramebuffer(screen:gfxScreen_t; side:gfx3dSide_t; width:pu16; height:pu16):pu8;cdecl;external;
  procedure gfxSetScreenFormat(screen:gfxScreen_t; format:GSP_FramebufferFormats);cdecl;external;
  function gfxGetScreenFormat(screen:gfxScreen_t):GSP_FramebufferFormats;cdecl;external;
  procedure gfxSetDoubleBuffering(screen:gfxScreen_t; doubleBuffering:boolean);cdecl;external;
  procedure gfxConfigScreen(screen:gfxScreen_t; immediate:boolean);cdecl;external;

    var
       gfxTopLeftFramebuffers : array[0..1] of ^u8;cvar;external;
       gfxTopRightFramebuffers : array[0..1] of ^u8;cvar;external;
       gfxBottomFramebuffers : array[0..1] of ^u8;cvar;external;
       gxCmdBuf : ^u32;cvar;external;