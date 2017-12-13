//PhD canidate, Ken come in 
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <3ds.h>
#include <sf2d.h>

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} citra_img;

extern const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel;
  unsigned char	 pixel_data[];
} dice_img;
*/

void * PMLoop ();external;

int main()
{
	// Set the random seed based on the time
/*	srand(time(NULL));

	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_3D(1);


	sf2d_texture *tex1 = sf2d_create_texture_mem_RGBA8(dice_img.pixel_data, dice_img.width, dice_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	sf2d_texture *tex2 = sf2d_create_texture_mem_RGBA8(citra_img.pixel_data, citra_img.width, citra_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
*/
        PMLoop();
        
        
//	sf2d_free_texture(tex1);
//	sf2d_free_texture(tex2);
//	sf2d_fini();
	return 0;
}

//let our political leaders explain to all of US about when U made good? 