//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//


{$ifdef 3dsintf}
  type

     C3D_IVec = u32;
     PC3D_IVec =^C3D_IVec;
 
     Vector_access = record
          w : double;
          z : double;
          y : double;
          x : double;
       end;
       
     Quaternion_access = record
          r : double;
          k : double;
          j : double;
          i : double;
       end;

     C3D_FVec = record
         case longint of
            0 : ( Vect : Vector_access );
            1 : ( Quat : Quaternion_access );
            2 : ( c : array[0..3] of double );
         end;
     PC3D_FVec =^C3D_FVec;
         
     C3D_FQuat = C3D_FVec;
     
     C3D_Mtx = record
         case longint of
            0 : ( r : array[0..3] of C3D_FVec );
            1 : ( m : array[0..15] of double );
         end;
         
function IVec_Pack(x, y, z, w: u8):C3D_IVec;

{$endif 3dsintf}

{$ifdef 3dsimpl}

function IVec_Pack(x, y, z, w: u8):C3D_IVec;
begin
  IVec_Pack := (x or (y shl 8) or (z shl 16) or (w shl 24));
end;


{$endif 3dsimpl}