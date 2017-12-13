//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

    {----------------------------------------------------------------------------- }
    { Light }
    {----------------------------------------------------------------------------- }

    type

       C3D_LightMatConf = record
            specular0 : u32;
            specular1 : u32;
            diffuse : u32;
            ambient : u32;
         end;

       C3D_LightConf = record
            material : C3D_LightMatConf;
            position : array[0..2] of u16;
            padding0 : u16;
            spotDir : array[0..2] of u16;
            padding1 : u16;
            padding2 : u32;
            config : u32;
            distAttnBias : u32;
            distAttnScale : u32;
         end;
         
    {C3DF_Light_Shadow   = BIT(3), }
    {C3DF_Light_Spot     = BIT(4), }
    {C3DF_Light_DistAttn = BIT(5), }    


  {----------------------------------------------------------------------------- }
  { Material }
  {----------------------------------------------------------------------------- }

  type

     C3D_Material = record
          ambient : array[0..2] of double;
          diffuse : array[0..2] of double;
          specular0 : array[0..2] of double;
          specular1 : array[0..2] of double;
          emission : array[0..2] of double;
       end;
    PC3D_Material  = ^C3D_Material;
    
  {----------------------------------------------------------------------------- }
  { Light environment }
  {----------------------------------------------------------------------------- }
  { Forward declarations }
    
{$i lightlut.inc}

type
     C3D_LightLutInputConf = record
          abs : u32;
          select : u32;
          scale : u32;
       end;

     C3D_LightEnvConf = record
          ambient : u32;
          numLights : u32;
          config : array[0..1] of u32;
          lutInput : C3D_LightLutInputConf;
          permutation : u32;
       end;
       
    const
       C3DF_LightEnv_LutDirtyAll = $3F shl 26;       
       

    type
       PC3D_LightEnv= ^C3D_LightEnv; 
       C3D_LightEnv = record
            Update : procedure (env:PC3D_LightEnv);cdecl;
            Dirty : procedure (env:PC3D_LightEnv);
            flags : u32;
            luts : array[0..5] of ^C3D_LightLut;
            ambient : array[0..2] of double;
            lights : array[0..7] of ^C3D_Light;
            conf : C3D_LightEnvConf;
            material : C3D_Material;
         end;

       C3D_Light = record
            flags : u16;
            id : u16;
            parent : ^C3D_LightEnv;
            lut_SP : ^C3D_LightLut;
            lut_DA : ^C3D_LightLut;
            color : array[0..2] of double;
            conf : C3D_LightConf;
         end;
       PC3D_Light  = ^C3D_Light;

    procedure C3D_LightEnvInit(env:PC3D_LightEnv);cdecl;external;

    procedure C3D_LightEnvBind(env:PC3D_LightEnv);cdecl;external;
    procedure C3D_LightEnvMaterial(env:PC3D_LightEnv; mtl:PC3D_Material);cdecl;external;

    procedure C3D_LightEnvAmbient(env:PC3D_LightEnv; r:double; g:double; b:double);cdecl;external;

    procedure C3D_LightEnvLut(env:PC3D_LightEnv; lutId:cint; input:cint; abs:bool; lut:PC3D_LightLut);cdecl;external;

    procedure C3D_LightEnvFresnel(env:PC3D_LightEnv; selector:GPU_FRESNELSEL);cdecl;external;

    procedure C3D_LightEnvBumpMode(env:PC3D_LightEnv; mode:GPU_BUMPMODE);cdecl;external;

    procedure C3D_LightEnvBumpSel(env:PC3D_LightEnv; texUnit:cint);cdecl;external;

    procedure C3D_LightEnvShadowMode(env:PC3D_LightEnv; mode:u32);cdecl;external;

    procedure C3D_LightEnvShadowSel(env:PC3D_LightEnv; texUnit:cint);cdecl;external;

    procedure C3D_LightEnvClampHighlights(env:PC3D_LightEnv; clamp:bool);cdecl;external;


    function C3D_LightInit(light:PC3D_Light; env:PC3D_LightEnv):cint;cdecl;external;

    procedure C3D_LightEnable(light:PC3D_Light; enable:bool);cdecl;external;

    procedure C3D_LightTwoSideDiffuse(light:PC3D_Light; enable:bool);cdecl;external;

    procedure C3D_LightGeoFactor(light:PC3D_Light; id:cint; enable:bool);cdecl;external;

    procedure C3D_LightColor(light:PC3D_Light; r:double; g:double; b:double);cdecl;external;

    procedure C3D_LightPosition(light:PC3D_Light; pos:PC3D_FVec);cdecl;external;

    procedure C3D_LightShadowEnable(light:PC3D_Light; enable:bool);cdecl;external;

    procedure C3D_LightSpotEnable(light:PC3D_Light; enable:bool);cdecl;external;

    procedure C3D_LightSpotDir(light:PC3D_Light; x:double; y:double; z:double);cdecl;external;

    procedure C3D_LightSpotLut(light:PC3D_Light; lut:PC3D_LightLut);cdecl;external;

    procedure C3D_LightDistAttnEnable(light:PC3D_Light; enable:bool);cdecl;external;

    procedure C3D_LightDistAttn(light:PC3D_Light; lut:PC3D_LightLutDA);cdecl;external;
