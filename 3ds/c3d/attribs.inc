//the Pascal citro3d headers for use with 3ds platform
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

  Type
     C3D_AttrInfo = record
          flags : array[0..1] of u32;
          permutation : u64;
          attrCount : cint;
       end;
  PC3D_AttrInfo  = ^C3D_AttrInfo;

  procedure AttrInfo_Init(info:PC3D_AttrInfo);cdecl;external;

  function AttrInfo_AddLoader(info:PC3D_AttrInfo; regId:cint; format: GPU_FORMATS; count:cint):cint;cdecl;external;

  function AttrInfo_AddFixed(info:PC3D_AttrInfo; regId:cint):cint;cdecl;external;

  function C3D_GetAttrInfo:PC3D_AttrInfo;cdecl;external;

  procedure C3D_SetAttrInfo(info:PC3D_AttrInfo);cdecl;external;
