// Live from the 2DS .. 3DS Pascal banic in: (Kirk & alter ego Twin) Back on the transporter	     
//
// Copyright (c) 2015 .. 2017 Kenneth Dwayen Lee PhD.
// all rights reserved on
//
// Nintendo 3DS & 2DS any & all portions of "Pascal" concering Nintendo 3DS & 2DS 
// WE Both YOU & I & maybe others are intent on PROFIT with & from any $ale$ in &or proceeds from!
// the benifits obtained overall & should stand to profit in it's usage alone in rearing & developments? 
//
// again for You & Many others  
//it's non participant others whom seem to cash it all in & leave nothing tobe desired, 
//&or it lacks of the good intent afterwards, as with it's 
//"Farday, reminiscent in nature &or a scafold that reachs too the profound" or was givin but 
// now it's nears computer laws & forms theories of (Language vs. Pica200) & won over or just being mere threoy !  
//
//I've Asked U all to grab your seats & make your one &or votes illustrated.     

// I definitly require a sum &or $um$, for computer languages "Pascal @ 2 votes" &or "Perl @ 2 votes"  
// in or be it U are the JVM all mighty, fell from sky & reacking Javac a pone little people @ 2 votes 
// &or LVM is your faith at the colony on road-apple7 @ 2 votes
 
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
{$linklib libsfil}
{$linklib libcitro3d}

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
{$i sfil.inc}
{$undef 3dsintf}

{$i "parx/parx_inf.inc"}
 
implementation
       
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
  
//the Pascal version of Dr. Xerpi's --> sfillib/sample    
procedure PMLoop; stdcall;
var
tex1, tex2: psf2d_texture;
begin
	
	sf2d_init();
	sf2d_set_clear_color(RGBA8($40, $40, $40, $FF));
	sf2d_set_3D(1);

	tex1 := sfil_load_JPEG_file('citra.jpeg', SF2D_PLACE_RAM);
	tex2 := sfil_load_PNG_file('3dbrew.png', SF2D_PLACE_RAM);
	
	// Main loop
	repeat 	
        	hidScanInput();

		if (hidKeysHeld() and KEY_START)>0 then break ;
	
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
	
			sf2d_draw_texture(tex1, 200 - (tex1^.width div 2), 240 div 2 - tex1^.height div 2);

		sf2d_end_frame();

		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

			sf2d_draw_texture(tex2, 320 div 2 - tex2^.width div 2, 240 div 2 - tex2^.height div 2);

		sf2d_end_frame();
		sf2d_swapbuffers();
		
	until not aptMainLoop();
	
	sf2d_free_texture(tex1);
	sf2d_free_texture(tex2);

	sf2d_fini();
end;

end. 
//look up the head office's of "Telecom & Oil" located in Canada?
//kdl
