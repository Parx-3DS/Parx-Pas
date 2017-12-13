//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}

  const
     C3D_DEFAULT_CMDBUF_SIZE = $40000;
     C3D_UNSIGNED_BYTE = 0;
     C3D_UNSIGNED_SHORT = 1;

    function C3D_Init(cmdBufSize:u32):bool;cdecl;external;

    procedure C3D_FlushAsync;cdecl;external;

    procedure C3D_Fini;cdecl;external;

    function C3D_GetCmdBufUsage:double;cdecl;external;

    procedure C3D_BindProgram(ShProg :PshaderProgram_s);cdecl;external;

    procedure C3D_SetViewport(x:u32; y:u32; w:u32; h:u32);cdecl;external;

    procedure C3D_SetScissor(mode:GPU_SCISSORMODE; left:u32; top:u32; right:u32; bottom:u32);cdecl;external;

    procedure C3D_DrawArrays(primitive:GPU_Primitive_t; first:cint; size:cint);cdecl;external;

    procedure C3D_DrawElements(primitive:GPU_Primitive_t; count:cint; _type:cint; indices:pointer);cdecl;external;

    { Immediate-mode vertex submission }
    procedure C3D_ImmDrawBegin(primitive:GPU_Primitive_t);cdecl;external;

    procedure C3D_ImmSendAttrib(x:double; y:double; z:double; w:double);cdecl;external;

    procedure C3D_ImmDrawEnd;cdecl;external;

    procedure C3D_ImmDrawRestartPrim;cdecl;

    procedure C3D_FlushAwait;cdecl;

    procedure C3D_Flush;cdecl;

    { Fixed vertex attributes }
    function C3D_FixedAttribGetWritePtr(id:cint):PC3D_FVec;cdecl;external;

    procedure C3D_FixedAttribSet(id:cint; x:double; y:double; z:double; w:double);cdecl;

{$endif 3dsintf}

{$ifdef 3dsimpl}

    procedure C3D_ImmDrawRestartPrim;cdecl;
    begin
	GPUCMD_AddWrite($25F, 1); //GPUREG_RESTART_PRIMITIVE
    end;

    procedure C3D_FlushAwait;cdecl;
    begin
	gspWaitForP3D();
    end;

    procedure C3D_Flush;cdecl;
    begin
	C3D_FlushAsync();
	C3D_FlushAwait();
    end;

    procedure C3D_VideoSync;cdecl;
    begin
	gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);
	gfxSwapBuffersGpu();
    end;

    procedure C3D_FixedAttribSet(id:cint; x:double; y:double; z:double; w:double);cdecl;
    var
     ptr: PC3D_FVec;
    begin
        ptr := C3D_FixedAttribGetWritePtr(id);
	ptr^.Vect.x := x;
	ptr^.Vect.y := y;
	ptr^.Vect.z := z;
	ptr^.Vect.w := w;
    end;

{$endif 3dsimpl}
