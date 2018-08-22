//the Pascal use of the Nintendo 2DS & 3DS platform
//
// Copyright (c) 2013, 2015, 2017 Kenneth Dwayne Lee Bsc.
// all rights reserved
//  
// Apartied vagina, swim around in that same vagina doing "the I love U back stoke after, hey?"
// 1, My statis, Indian Card 
// 2. Trudeau too with draw his sad treaty with me & any other crowfoot or members of the first nations in Canada 


  type
     gfxScreen_t = (GFX_TOP := 0,GFX_BOTTOM := 1);
     gfx3dSide_t = (GFX_LEFT := 0,GFX_RIGHT := 1);


     GSP_FramebufferFormats = (GSP_RGBA8_OES := 0,
				GSP_BGR8_OES := 1,
                                GSP_RGB565_OES := 2,
				GSP_RGB5_A1_OES := 3, 
				GSP_RGBA4_OES := 4, 
				GSP_8BIT_OES := 5, //?
				GSP_BW_OES := 6); //?
  {system stuff }
  procedure gfxInitDefault;cdecl;external;
  procedure gfxInit(topFormat,bottomFormat:GSP_FramebufferFormats;vrambuffers:boolean);cdecl;external;
  procedure gfxExit;cdecl;external;

  {control stuff }
  procedure gfxSet3D(enable:boolean);cdecl;external;
  function gfxIs3D:boolean;cdecl;external;
  procedure gfxFlushBuffers;cdecl;external;
  procedure gfxSwapBuffers;cdecl;external;
  procedure gfxSwapBuffersGpu;cdecl;external;

  {helper stuff }
  function gfxGetFramebuffer(screen:gfxScreen_t; side:gfx3dSide_t; width:pword; height:pword):pbyte;cdecl;external;
  procedure gfxSetScreenFormat(screen:gfxScreen_t; format:GSP_FramebufferFormats);cdecl;external;
  function gfxGetScreenFormat(screen:gfxScreen_t):GSP_FramebufferFormats;cdecl;external;
  procedure gfxSetDoubleBuffering(screen:gfxScreen_t; doubleBuffering:boolean);cdecl;external;
  procedure gfxConfigScreen(screen:gfxScreen_t; immediate:boolean);cdecl;external;

    var        
       gfxTopLeftFramebuffers  : array[0..1] of {$ifdef ParxGrid}{$i TMapper.inc}{$else}pbyte{$endif ParxGrid} ;cvar;external;
       gfxTopRightFramebuffers : array[0..1] of {$ifdef ParxGrid}{$i TMapper.inc}{$else}pbyte{$endif ParxGrid} ;cvar;external;
       gfxBottomFramebuffers   : array[0..1] of {$ifdef ParxGrid}{$i BMapper.inc}{$else}pbyte{$endif ParxGrid} ;cvar;external; 
       gxCmdBuf : ^dword;cvar;external;