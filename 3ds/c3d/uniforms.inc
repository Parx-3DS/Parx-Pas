//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

  const
     C3D_FVUNIF_COUNT = 96;     
     C3D_IVUNIF_COUNT = 4;     

    var
       C3D_FVUnif : array[0..1] of array[0..(C3D_FVUNIF_COUNT)-1] of C3D_FVec;cvar;external;
       C3D_IVUnif : array[0..1] of array[0..(C3D_IVUNIF_COUNT)-1] of C3D_IVec;cvar;external;
       C3D_BoolUnifs : array[0..1] of u16;cvar;external;
       C3D_FVUnifDirty : array[0..1] of array[0..(C3D_FVUNIF_COUNT)-1] of bool;cvar;external;
       C3D_IVUnifDirty : array[0..1] of array[0..(C3D_IVUNIF_COUNT)-1] of bool;cvar;external;
       C3D_BoolUnifsDirty : array[0..1] of bool;cvar;external;

  function C3D_FVUnifWritePtr(_type:GPU_SHADER_TYPE; id:cint; size:cint):PC3D_FVec;cdecl;external;

  function C3D_IVUnifWritePtr(_type:GPU_SHADER_TYPE; id:cint):PC3D_IVec;cdecl;external;

  procedure C3D_FVUnifMtxNx4(_type:GPU_SHADER_TYPE; id:cint; mtx:PC3D_Mtx; num:cint);cdecl;external;

  procedure C3D_FVUnifMtx4x4(_type:GPU_SHADER_TYPE; id:cint; mtx:PC3D_Mtx);cdecl;external;

  procedure C3D_FVUnifMtx3x4(_type:GPU_SHADER_TYPE; id:cint; mtx:PC3D_Mtx);cdecl;external;

  procedure C3D_FVUnifMtx2x4(_type:GPU_SHADER_TYPE; id:cint; mtx:PC3D_Mtx);cdecl;external;

  procedure C3D_FVUnifSet(_type:GPU_SHADER_TYPE; id:cint; x:double; y:double; z:double; 
              w:double);cdecl;external;

  procedure C3D_IVUnifSet(_type:GPU_SHADER_TYPE; id:cint; x:cint; y:cint; z:cint; 
              w:cint);cdecl;external;

  procedure C3D_BoolUnifSet(_type:GPU_SHADER_TYPE; id:cint; value:bool);cdecl;external;