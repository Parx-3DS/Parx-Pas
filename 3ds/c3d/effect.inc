//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

  procedure C3D_DepthMap(zScale:double; zOffset:double);cdecl;external;

  procedure C3D_CullFace(mode:GPU_CULLMODE);cdecl;external;

  procedure C3D_StencilTest(enable:bool; _function:GPU_TESTFUNC; ref:cint; inputMask:cint; writeMask:cint);cdecl;external;

  procedure C3D_StencilOp(sfail:GPU_STENCILOP; dfail:GPU_STENCILOP; pass:GPU_STENCILOP);cdecl;external;

  procedure C3D_BlendingColor(color:u32);cdecl;external;

  procedure C3D_DepthTest(enable:bool; _function:GPU_TESTFUNC; writemask:GPU_WRITEMASK);cdecl;external;

  procedure C3D_AlphaTest(enable:bool; _function:GPU_TESTFUNC; ref:cint);cdecl;external;

  procedure C3D_AlphaBlend(colorEq:GPU_BLENDEQUATION; alphaEq:GPU_BLENDEQUATION; srcClr:GPU_BLENDFACTOR; dstClr:GPU_BLENDFACTOR; srcAlpha:GPU_BLENDFACTOR; 
              dstAlpha:GPU_BLENDFACTOR);cdecl;external;

  procedure C3D_ColorLogicOp(op:GPU_LOGICOP);cdecl;external;

  procedure C3D_FragOpMode(mode:GPU_FRAGOPMODE);cdecl;external;