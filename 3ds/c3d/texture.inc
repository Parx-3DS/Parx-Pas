//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}
  type

     C3D_Tex = record
          data : pointer;
          flag0 : longint;
          width : u16;
          height : u16;
          param : u32;
       end;
     PC3D_Tex  = ^C3D_Tex;
  
  const
     bm_C3D_Tex_fmt = $F;
     bp_C3D_Tex_fmt = 0;
     bm_C3D_Tex_size = $FFFFFFF0;
     bp_C3D_Tex_size = 4;

  function fmt(var a : C3D_Tex) : GPU_TEXCOLOR;
  procedure set_fmt(var a : C3D_Tex; __fmt : GPU_TEXCOLOR);
  function size(var a : C3D_Tex) : u32;
  procedure set_size(var a : C3D_Tex; __size : u32);

  function C3D_TexInit(tex:PC3D_Tex; width:cint; height:cint; format:GPU_TEXCOLOR):bool;cdecl;external;

  function C3D_TexInitVRAM(tex:PC3D_Tex; width:cint; height:cint; format:GPU_TEXCOLOR):bool;cdecl;external;

  procedure C3D_TexUpload(tex:PC3D_Tex; data:pointer);cdecl;external;

  procedure C3D_TexSetFilter(tex:PC3D_Tex; magFilter:GPU_TEXTURE_FILTER_PARAM; minFilter:GPU_TEXTURE_FILTER_PARAM);cdecl;external;

  procedure C3D_TexSetWrap(tex:PC3D_Tex; wrapS:GPU_TEXTURE_WRAP_PARAM; wrapT:GPU_TEXTURE_WRAP_PARAM);cdecl;external;

  procedure C3D_TexBind(unitId:cint; tex:PC3D_Tex);cdecl;external;

  procedure C3D_TexFlush(tex:PC3D_Tex);cdecl;external;

  procedure C3D_TexDelete(tex:PC3D_Tex);cdecl;external;

{$endif 3dsintf}

{$ifdef 3dsimpl}  

  function fmt(var a : C3D_Tex) : GPU_TEXCOLOR;
    begin
       fmt:=(a.flag0 and bm_C3D_Tex_fmt) shr bp_C3D_Tex_fmt;
    end;

  procedure set_fmt(var a : C3D_Tex; __fmt : GPU_TEXCOLOR);
    begin
       a.flag0:=a.flag0 or ((__fmt shl bp_C3D_Tex_fmt) and bm_C3D_Tex_fmt);
    end;

  function size(var a : C3D_Tex) : u32;
    begin
       size:=(a.flag0 and bm_C3D_Tex_size) shr bp_C3D_Tex_size;
    end;

  procedure set_size(var a : C3D_Tex; __size : u32);
    begin
       a.flag0:=a.flag0 or ((__size shl bp_C3D_Tex_size) and bm_C3D_Tex_size);
    end;

{$endif 3dsimpl}
