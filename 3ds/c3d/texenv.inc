//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}

 const
	C3D_RGB   = (1 shl 0);
	C3D_Alpha = (1 shl 1);
	C3D_Both  = (1 shl 0) or (1 shl 1);
  type

     C3D_TexEnv = record
          srcRgb : u16;
          srcAlpha : u16;
          opRgb : u16;
          opAlpha : u16;
          funcRgb : u16;
          funcAlpha : u16;
          color : u32;
          scaleRgb : u16;
          scaleAlpha : u16;
       end;
    PC3D_TexEnv  = ^C3D_TexEnv;

    procedure TexEnv_Init(env:PC3D_TexEnv);cdecl;external;

    function C3D_GetTexEnv(id:cint):PC3D_TexEnv;cdecl;external;

    procedure C3D_SetTexEnv(id:cint; env:PC3D_TexEnv);cdecl;external;

    procedure C3D_TexEnvBufUpdate(mode:cint; mask:cint);cdecl;external;

    procedure C3D_TexEnvBufColor(color:u32);cdecl;external;

    procedure C3D_TexEnvSrc(env:PC3D_TexEnv; mode, s1, s2, s3:cint);cdecl;

    procedure C3D_TexEnvOp(env:PC3D_TexEnv; mode, o1, o2, o3:cint);cdecl;

{$endif 3dsintf}

{$ifdef 3dsimpl}

procedure C3D_TexEnvSrc(env:PC3D_TexEnv; mode, s1, s2, s3:cint);cdecl;
var
 param: integer;
begin
      	param := GPU_TEVSOURCES(s1, s2, s3);
	if (mode and C3D_RGB) > 0  then
		env^.srcRgb := param;
	if (mode and C3D_Alpha) > 0 then
		env^.srcAlpha := param;
end;

procedure C3D_TexEnvOp(env:PC3D_TexEnv; mode, o1, o2, o3:cint);cdecl;
var
 param: integer;
begin
      	param := GPU_TEVOPERANDS(o1, o2, o3);
	if (mode and C3D_RGB) > 0 then
		env^.opRgb := param;
	if (mode and C3D_Alpha) > 0 then
		env^.opAlpha := param;
end;

procedure C3D_TexEnvFunc(env:PC3D_TexEnv;mode:cint; mask:cint);cdecl;
begin
	if (mode and C3D_RGB) > 0 then
		env^.funcRgb := mask;
	if (mode and C3D_Alpha) > 0 then
		env^.funcAlpha := mask;
end;

procedure C3D_TexEnvColor(env:PC3D_TexEnv;color:u32);cdecl;
begin
       env^.color := color;
end;

procedure C3D_TexEnvScale(env:PC3D_TexEnv; mode:cint; param:cint);cdecl;
begin
      	if (mode and C3D_RGB) > 0 then
		env^.scaleRgb := param;
	if (mode and C3D_Alpha) > 0 then
		env^.scaleAlpha := param;
end;


{$endif 3dsimpl}
