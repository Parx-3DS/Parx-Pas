//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}

  type

     C3D_RenderBuf = record
          colorBuf : C3D_Tex;
          depthBuf : C3D_Tex;
          clearColor : u32;
          clearDepth : u32;
          depthFmt : cint;
       end;
  PC3D_RenderBuf  = ^C3D_RenderBuf;

  procedure C3D_RenderBufClear(rb:PC3D_RenderBuf);cdecl;
  
  function C3D_RenderBufInit(rb:PC3D_RenderBuf; width:cint; height:cint; colorFmt:cint; depthFmt:cint):bool;cdecl;external;

  procedure C3D_RenderBufClearAsync(rb:PC3D_RenderBuf);cdecl;external;

  procedure C3D_RenderBufTransfer(rb:PC3D_RenderBuf; frameBuf:Pu32; flags:u32);cdecl;
  
  procedure C3D_RenderBufTransferAsync(rb:PC3D_RenderBuf; frameBuf:Pu32; flags:u32);cdecl;external;

  procedure C3D_RenderBufBind(rb:PC3D_RenderBuf);cdecl;external;

  procedure C3D_RenderBufDelete(rb:PC3D_RenderBuf);cdecl;external;
  

{$endif 3dsintf}

{$ifdef 3dsimpl}  


procedure C3D_RenderBufClear(rb:PC3D_RenderBuf);cdecl;
begin
	C3D_RenderBufClearAsync(rb);
	gspWaitForPSC0();
end;


procedure C3D_RenderBufTransfer(rb:PC3D_RenderBuf; frameBuf:Pu32; flags:u32);cdecl;
begin
        C3D_RenderBufTransferAsync(rb, frameBuf, flags);
	gspWaitForPPF();
end;

{$endif 3dsimpl}