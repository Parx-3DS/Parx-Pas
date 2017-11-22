//  Nintendo 2ds 3ds Live on Channel 5
//
//   24bit segnifgent smitten GFX, RPN kitten @ the house Hindu
//
// Copyright (c) 2017 PhD Kenny D. Lee
// ANY Corprate logos & Trade Marks usage &or portions of "Must provide resonable funding!"
// all rights reserved.

{$ifndef NO_SMART_LINK}
{$smartlink on}
{$endif}
unit ParxPro;
 
{$mode objfpc}{$H+}
 
interface
 
uses ctypes;

{$packrecords c}
 
{$linklib libParx}

{$include parx_inf.inc}

{$linklib libctru}

procedure TestPattern(); stdcall; public name 'TestPattern';
function CopyRight: PChar; stdcall; public name 'CopyRight';


implementation

uses ParxVideoRAM, Parx16, Parx24, Parx32;

{$include parx.inc}

function CopyRight: PChar; stdcall;
begin
  Result:= 'Parx-GDI v1.3 2015 Kenny D Lee';
end;


procedure SetPixTop(x,y: integer; colour: Hex24); stdcall;
begin
//  SetGFXPix(gfxTopLeftFramebuffers[bufnum],x,y,colour);
//  SetGFXPix(gfxTopRightFramebuffers[bufnum],x,y,colour);
//  SetGFXPix(ParxLeft,x,y,colour);
//  SetGFXPix(ParxRight,x,y,colour);
  SetGFXPix(gfxTopLeftFramebuffers[0],x,y,colour);
  SetGFXPix(gfxTopRightFramebuffers[0],x,y,colour);
  
  
//  TopMap(colour,y,x,ParxLeft);
//  TopMap(colour,y,x,ParxRight);
end;

procedure TestPattern(); stdcall;
var i,j: integer; 
begin
//test pattern 1st pass 
				for i := 0 to 79 do 
				  for j := 0 to 200 do 
begin
                                SetPixTop(i,j,$FF0000); //RED
                                SetPixTop(i+80,j, $FFFF00); //CYAN
                                SetPixTop(i+160,j,$00FFFF); //YELLOW
                                SetPixTop(i+240,j,$0);
                                SetPixTop(i+320,j,$0000FF);//BLUE				
end;
//test pattern 2nd pass 
				for i := 0 to 99 do 
				  for j := 201 to 239 do
begin
                                SetPixTop(i,j,$FF00FF);//PINK
                                SetPixTop(i+100,j,$00CC00); //LIGHT_GREEN
                                SetPixTop(i+200,j,$FFFFFF); //WHITE
                                SetPixTop(i+300,j,$FF9900); //ORANGE
end;
end;
 
//exports
//  GetAnswer;
 
end.