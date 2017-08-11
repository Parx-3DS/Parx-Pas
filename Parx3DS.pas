//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved on
//
// 2DS & 3DS BootStrap & ... any & all portions of "Pascal"  
// WE Both YOU & I are intent on profit with & from any $ale$ &or in "Nintendo 2DS & 3DS" development usage of the "Pascal" computer language! 
 
unit Parx3DS;
 
{$mode objfpc}{$H+}
 
interface
 
uses
  ctypes;
 
{$linklib libctru}
{$linklib libm}
{$linklib libParx}

//-Fl/opt/radiofreedom/libctru/lib  
//-Fu/opt/radiofreedom/libctru/pascal
//-Fi/opt/radiofreedom/libctru/pascal/3ds

{$define 3dsintf}
{$i 3dstypes.inc}
{$i services/gfx.inc}
{$i services/apt.inc}
{$i services/gsp.inc}
{$i services/fs.inc}
{$i services/hid.inc}
{$undef 3dsintf}

{$i "parx/parx_inf.inc"}
 
implementation

{$i "parx/parx.inc"}

{$define 3dsimpl}
{$i services/fs.inc}
{$i services/gsp.inc}
{$i 3dstypes.inc}
{$undef 3dsimpl}

end.
//kdl 