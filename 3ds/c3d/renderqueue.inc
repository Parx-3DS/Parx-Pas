//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


// Flags for C3D_FrameBegin
const

	C3D_FRAME_SYNCDRAW = (1 shl 0); // Do not render the frame until the previous has finished rendering
	C3D_FRAME_NONBLOCK = (1 shl 1); // Return false instead of waiting for the GPU to finish rendering

	C3D_CLEAR_COLOR = (1 shl 0);
	C3D_CLEAR_DEPTH = (1 shl 1);
	C3D_CLEAR_ALL   = (1 shl 0) or (1 shl 1);

  type
     C3D_RenderTarget = record
          next : ^C3D_RenderTarget;
          prev : ^C3D_RenderTarget;
          link : ^C3D_RenderTarget;
          frame : array[0..1] of ^C3D_RenderTarget;
          renderBuf : C3D_RenderBuf;
          transferFlags : u32;
          clearBits : u8;
          drawOk : bool;
          transferOk : bool;
          linked : bool;
          screen : gfxScreen_t;
          side : gfx3dSide_t;
       end;
    PC3D_RenderTarget  = ^C3D_RenderTarget;

    function C3D_FrameBegin(flags:u8):bool;cdecl;external;

    function C3D_FrameDrawOn(target:PC3D_RenderTarget):bool;cdecl;external;

    procedure C3D_FrameEnd(flags:u8);cdecl;external;

    function C3D_RenderTargetCreate(width:cint; height:cint; colorFmt:cint; depthFmt:cint):PC3D_RenderTarget;cdecl;external;

    procedure C3D_RenderTargetDelete(target:PC3D_RenderTarget);cdecl;external;

    procedure C3D_RenderTargetSetClear(target:PC3D_RenderTarget; clearBits:u32; clearColor:u32; clearDepth:u32);cdecl;external;

    procedure C3D_RenderTargetSetOutput(target:PC3D_RenderTarget; screen:gfxScreen_t; side:gfx3dSide_t; transferFlags:u32);cdecl;external;

    procedure C3D_SafeDisplayTransfer(inadr:Pu32; indim:u32; outadr:Pu32; outdim:u32; flags:u32);cdecl;external;

    procedure C3D_SafeTextureCopy(inadr:Pu32; indim:u32; outadr:Pu32; outdim:u32; size:u32; 
                flags:u32);cdecl;external;

    procedure C3D_SafeMemoryFill(buf0a:Pu32; buf0v:u32; buf0e:Pu32; control0:u16; buf1a:Pu32; 
                buf1v:u32; buf1e:Pu32; control1:u16);cdecl;external;
