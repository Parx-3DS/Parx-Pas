//U can't hide your ...
//
#include "Canvas_font.h"

//gfxChar && CanvasString
//revised --> https://bitbucket.org/xerpi/eleven-arms/src/

extern const u8 msx_font[];

//int font_draw_char(int x, int y, u32 color, char c)
int gfxChar(u8* screen,  char c, int x, int y, int direct, TBGR colour)
{
	u8 *font = (u8*)(msx_font + (c - (u32)' ') * 8);
	int i, j;
//up=0, down=1, left=2, right=3
	
for (i = 0; i < 8; ++i) 
 {
for (j = 0; j < 8; ++j) if ((*font & (128 >> j))) 
 {
if (direct == 0) {TopMap(colour, x+j, y+7-i, screen);} //Perfect char orent
else if (direct == 1) {TopLCD(screen, 399-x-j, y+7-i, colour);} // Perfect top char orent 
else if (direct == 2) {TopMap(colour, y-7+i, x-7+j, screen);}  //Perfect
else if (direct == 3) {TopLCD(screen, 407-y-i, x-7+j, colour);} //Perfect
 }
 ++font;
  	}
	return x+8;
}

//int font_draw_string(int x, int y, u32 color, const char *string)
int gfxString(u8* screen, const char *string, int x, int y, int direct, TBGR colour)
{
	if (string == NULL) return x;
	int startx = x;
	const char *s = string;


	while (*s) {
		if (*s == '\n') {
			x = startx;
			y+=8;
		} else if (*s == ' ') {
			x+=8;
		} else if(*s == '\t') {
			x+=8*4;
		} else {
//			draw_fillrect(x, y, 8, 8, BLACK);
//			font_draw_char(x, y, color, *s);
			gfxChar(screen, *s, x, y, direct, colour);
			x+=8;
		}
//if (direct == 1) --s;
//else if (direct == 3) --s;
//else
 ++s;
	}
	return x;
}
