// Live from the 3DS Pascal banic in: (Kirk & alter ego Twin) fresh off the transporter	     
//
// Copyright (c) 2015 .. 2017 Kenneth Dwayen Lee PhD.
// if U Frontier & founded a lifeform does the PhD title cum into play?
// all rights reserved on
//
// Nintendo 3DS BootStrap & ... any & all portions of "Pascal"  
// WE Both YOU & I & maybe others are intent on PROFIT with & from any $ale$ in &or of the "Nintendo 2DS &or 3DS" 
// It's rearing, developments & benifits from the "Pascal" computer language usage. 
 
unit ParxPas;

{$mode objfpc}{$H+}
 
interface
 
uses
  ctypes;


procedure PMLoop; stdcall; public name 'PMLoop'; 
// I voted for Weed/Pot & so did everyone else, 
// Not!!! (Baseface good for nothing &or Facist Crackhead in distress &or jibteck &or some other petro-reach-a-round)  
//houseboat, sill unpaid (don't know how to treat the elderly, earn a buck! & social'll avail width other portions of lofty housing budget) 
  
{$linklib libctru}
{$linklib libm}
{$linklib libParx}
{$linklib libsf2d}

//-Fl/opt/radiofreedom/libctru/lib  
//-Fu/opt/radiofreedom/libctru/pascal
//-Fi/opt/radiofreedom/libctru/pascal/3ds

{$define 3dsintf}
{$i 3dstypes.inc}
{$i services/apt.inc}
{$i services/gsplcd.inc}
{$i services/gsp.inc}
{.$i services/gspgpu.inc}
{$i services/fs.inc}
{$i services/hid.inc}
{$i gpu/gpu.inc}
{$i gpu/shbin.inc}
{$i gpu/shaderProgram.inc}
{$i gfx.inc}

{$i c3d/types.inc}
{.$i c3d/maths.inc}
{.$i c3d/mtxstack.inc}
{.$i c3d/uniforms.inc}
{.$i c3d/attribs.inc}
{.$i c3d/buffers.inc}
{.$i c3d/base.inc}
{$i c3d/texenv.inc}
{$i c3d/effect.inc}
{$i c3d/texture.inc}
{.$i c3d/light.inc}
{$i c3d/renderbuffer.inc}
{$i c3d/renderqueue.inc}

{$i sf2d.inc}
{$undef 3dsintf}

{$i "parx/parx_inf.inc"}
 
implementation

type
 _img = packed record 
  width, height, bytes_per_pixel :u32;
  pixel_data: array of u8;
end;

    var
     citra_img: _img cvar;external;
     dice_img: _img cvar;external;
     
       
{$i "parx/parx.inc"}

{$define 3dsimpl}
{$i sf2d.inc}
{$i gpu/gpu.inc}

{$i c3d/types.inc}
{.$i c3d/maths.inc}
{.$i c3d/mtxstack.inc}
{.$i c3d/lightlut.inc}
{$i c3d/texenv.inc}
{$i c3d/texture.inc}
{.$i c3d/base.inc}
{$i c3d/renderbuffer.inc}


{$i services/fs.inc}
{$i services/gsp.inc}
{$i 3dstypes.inc}
{$undef 3dsimpl}
  
function CopyRight: PChar; stdcall;
begin
  CopyRight:= 'Parx3DS - Kenneth Dwayne Lee';
end;

procedure TestPattern(); stdcall;
begin

end;

procedure initTest(screen:Pu8); stdcall;
begin
  CanvasString(screen, 'Pascal puritan Ken`s', 10,20, LIGHT_GREEN);
end;

//So much good karma, ritch & welcome thankless?        
//I have yet to gain the wages of a Teacher, whom perscribed a Democracy will save U!
procedure PMLoop; stdcall;
var
held:u32;
rad:cfloat;
offset3d:u32;
touch_x, touch_y: u16;
touch: PtouchPosition;
circle: PcirclePosition;
//tex1, tex2: psf2d_texture;
begin

	// Set the random seed based on the time
//	random(time(nil)); //rand(time(nil));
	touch_x := 320 div 2;
	touch_y := 240 div 2;
	
	sf2d_init();
	sf2d_set_clear_color(RGBA8($40, $40, $40, $FF));
	sf2d_set_3D(1);

//	tex1 := sf2d_create_texture_mem_RGBA8(dice_img.pixel_data, dice_img.width, dice_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
//	tex2 := sf2d_create_texture_mem_RGBA8(citra_img.pixel_data, citra_img.width, citra_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	
	// Main loop
	repeat 	
        	hidScanInput();
		hidCircleRead(@circle);
		held := hidKeysHeld();

		if (held and KEY_START)>0 then break 
		 else if (held and KEY_TOUCH)>0 then begin
			hidTouchRead(@touch);
			touch_x := touch^.px;
			touch_y := touch^.py; end
		;// else if (held and (KEY_L or KEY_R)) >0 then sf2d_set_clear_color(RGBA8((random() MOD 255),(random() MOD 255), (random() MOD 255), 255));

		 offset3d :=  30;
		// offset3d := CONFIG_3D_SLIDERSTATE * 30.0;
		
	
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sf2d_draw_fill_circle(offset3d + 60, 100, 35, RGBA8($00, $FF, $00, $FF));
			sf2d_draw_fill_circle(offset3d + 180, 120, 55, RGBA8($FF, $FF, $00, $FF));

		//	sf2d_draw_rectangle_rotate(offset3d + 260, 20, 40, 40, RGBA8($FF, $FF, $00, $FF), -2.0*rad);
			sf2d_draw_rectangle(offset3d + 20, 60, 40, 40, RGBA8($FF, $00, $00, $FF));
			sf2d_draw_rectangle(offset3d + 5, 5, 30, 30, RGBA8($00, $FF, $FF, $FF));
//			sf2d_draw_texture_rotate(tex1, offset3d + 400 shr 1 + circle^.dx, 240 shr 1 - circle^.dy, rad);
		sf2d_end_frame();

		sf2d_start_frame(GFX_TOP, GFX_RIGHT);

			sf2d_draw_fill_circle(60, 100, 35, RGBA8($00, $FF, $00, $FF));
			sf2d_draw_fill_circle(180, 120, 55, RGBA8($FF, $FF, $00, $FF));

		//	sf2d_draw_rectangle_rotate(260, 20, 40, 40, RGBA8($FF, $FF, $00, $FF), -2.0*rad);
			sf2d_draw_rectangle(20, 60, 40, 40, RGBA8($FF, $00, $00, $FF));
			sf2d_draw_rectangle(5, 5, 30, 30, RGBA8($00, $FF, $FF, $FF));
//			sf2d_draw_texture_rotate(tex1, 400 shr 1 + circle^.dx, 240 shr 1 - circle^.dy, rad);
		sf2d_end_frame();

		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		//	sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8($FF, $FF, $FF, $FF), 3.0*rad);
			sf2d_draw_rectangle(30, 100, 40, 60, RGBA8($FF, $00, $FF, $FF));
//			sf2d_draw_texture_rotate(tex2, touch_x, touch_y, rad); // -rad
		//	sf2d_draw_rectangle(160-15 + cos(rad)*50.0, 120-15 + sin(rad)*50, 30, 30, RGBA8($00, $FF, $FF, $FF));
			sf2d_draw_fill_circle(40, 40, 35, RGBA8($00, $FF, $00, $FF));
		sf2d_end_frame();

		rad := 0.2;

		sf2d_swapbuffers();
	until not aptMainLoop();
	
//	sf2d_free_texture(tex1);
//	sf2d_free_texture(tex2);

	sf2d_fini();
end;

end.
//how ever percived "superficial &or buggy" 
//Ps. Brittany if you every read, Tell my Ex-Wife she F^&ked a
//kdl PhD 