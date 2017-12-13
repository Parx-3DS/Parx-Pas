//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}
  const
     C3D_MTXSTACK_SIZE = 8;     

  type

     C3D_MtxStack = record
          m : array[0..(C3D_MTXSTACK_SIZE)-1] of C3D_Mtx;
          pos : cint;
          unifType : u8;
          unifPos : u8;
          unifLen : u8;
          isDirty : bool;
       end;
    PC3D_MtxStack= ^C3D_MtxStack;   
    
    function MtxStack_Cur(stk:PC3D_MtxStack):PC3D_Mtx;

    procedure MtxStack_Init(stk:PC3D_MtxStack);cdecl;external;

    procedure MtxStack_Bind(stk:PC3D_MtxStack; unifType:GPU_SHADER_TYPE; unifPos:cint; unifLen:cint);cdecl;external;

    function MtxStack_Push(stk:PC3D_MtxStack):PC3D_Mtx;cdecl;external;

    function MtxStack_Pop(stk:PC3D_MtxStack):PC3D_Mtx;cdecl;external;

    procedure MtxStack_Update(stk:PC3D_MtxStack);cdecl;external;


{$endif 3dsintf}

{$ifdef 3dsimpl}

function MtxStack_Cur(stk:PC3D_MtxStack):PC3D_Mtx;
begin
  stk^.isDirty := true;
  MtxStack_Cur := @stk^.m[stk^.pos];
end;

{$endif 3dsimpl}