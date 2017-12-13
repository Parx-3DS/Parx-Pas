
  type

     C3D_BufCfg = record
          offset : u32;
          flags : array[0..1] of u32;
       end;

     C3D_BufInfo = record
          base_paddr : u32;
          bufCount : cint;
          buffers : array[0..11] of C3D_BufCfg;
       end;
     PC3D_BufInfo  = ^C3D_BufInfo;

  procedure BufInfo_Init(info:PC3D_BufInfo);cdecl;external;

  function BufInfo_Add(info:PC3D_BufInfo; data:pointer; var stride:pointer; attribCount:cint; permutation:u64):cint;cdecl;external;

  function C3D_GetBufInfo:PC3D_BufInfo;cdecl;external;

  procedure C3D_SetBufInfo(info:PC3D_BufInfo);cdecl;external;
