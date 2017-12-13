//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}
    Type
     C3D_LightLut = record
          data : array[0..255] of u32;
       end;
     PC3D_LightLut  = ^C3D_LightLut;

     C3D_LightLutDA = record
          lut : C3D_LightLut;
          bias : double;
          scale : double;
       end;
     PC3D_LightLutDA  = ^C3D_LightLutDA;

     C3D_LightLutFunc = function (x:double; param:double):double;cdecl;

     C3D_LightLutFuncDA = function (dist:double; arg0:double; arg1:double):double;cdecl;

    function quadratic_dist_attn(dist:double; linear:double; quad:double):double;cdecl;

    procedure LightLut_FromArray(lut:PC3D_LightLut; data:Pdouble);cdecl;external;

    procedure LightLut_FromFunc(lut:PC3D_LightLut; func:C3D_LightLutFunc; param:double; negative:bool);cdecl;external;

    procedure LightLutDA_Create(lut:PC3D_LightLutDA; func:C3D_LightLutFuncDA; pfrom:double; pto:double; arg0:double; arg1:double);cdecl;external;

    procedure LightLut_Phong(lut:PC3D_LightLut; shininess: double); cdecl;external; //moved too lightlut.c keep powf     

    procedure LightLutDA_Quadratic(lut: PC3D_LightLutDA; pfrom,pto,linear,quad: double)cdecl;external ; //moved too lightlut.c

{$endif 3dsintf}

{$ifdef 3dsimpl}

    function quadratic_dist_attn(dist:double; linear:double; quad:double):double;cdecl;
      begin
        quadratic_dist_attn := 1 / (1 + linear*dist + quad*dist*dist);
      end;

{$endif 3dsimpl}
