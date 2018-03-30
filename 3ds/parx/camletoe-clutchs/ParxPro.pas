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

{$include gfx.inc}
{$include parx_inf.inc}

{$linklib libctru}

{
type
Parx3D = Class
        protected
function GetPixL(x: word; y: word): PByte; virtual; abstract;
function GetPixR(x: word; y: word): PByte; virtual; abstract;
function GetPixB(x: word; y: word): PByte; virtual; abstract;
 
procedure SetPixL(x: word; y: word;colour: PByte); virtual; abstract;
procedure SetPixR(x: word; y: word;colour: PByte); virtual; abstract;
procedure SetPixB(x: word; y: word;colour: PByte); virtual; abstract;
//	private
  //LScr,RScr,BScr: function (index: integer): PByte;
	public
	 
//	published
    property L3D[x: word; y: word]: PByte read GetPixL write SetPixL;
    property R3D[x: word; y: word]: PByte read GetPixR write SetPixR;
    property B3D[x: word; y: word]: PByte read GetPixB write SetPixB;

end; 
}

function CopyRight: PChar; stdcall; public name 'CopyRight';

implementation

uses ParxVideoRAM, ParxM,{ Parx16,} Parx24{, Parx32};

{$include parx.inc}

function CopyRight: PChar; stdcall;
begin
  Result:= 'Parx-GDI v1.3 2015 Kenny D Lee';
end;

 
//exports
//  GetAnswer;
 
end.