//Pascal & 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//
//

unit citro3d;

interface

uses
  ctypes, n3ds;


{$ifdef CITRO3D_BUILD}
{$error "This header file is only for external users of citro3d."}
{$endif}

{$define 3dsintf}
{$i c3d/types.inc}
{$i c3d/maths.inc}
{$i c3d/mtxstack.inc}
{$i c3d/uniforms.inc}
{$i c3d/attribs.inc}
{$i c3d/buffers.inc}
{$i c3d/base.inc}
{$i c3d/texenv.inc}
{$i c3d/effect.inc}
{$i c3d/texture.inc}
{$i c3d/light.inc}
{$i c3d/renderbuffer.inc}
{$i c3d/renderqueue.inc}
{$undef 3dsintf}

implementation

{$define 3dsimpl}
{$i c3d/types.inc}
{$i c3d/maths.inc}
{$i c3d/mtxstack.inc}
{$i c3d/lightlut.inc}
{$i c3d/texenv.inc}
{$i c3d/texture.inc}
{$i c3d/base.inc}
{$i c3d/renderbuffer.inc}
{$undef 3dsintf}

end.
