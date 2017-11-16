#include <string.h>
#include <stdarg.h>

#include <3ds.h>
#include <ParxGDI.h>

//#include "bmp.h"
#include "Canvas_font.h"

char * CopyRight ();external;
void * TestPattern ();external;


void * InitBufSingle(u32 colour);external;

void * PasClrSrc(u8* screen, TBGR colour);external;
void * PasTopfill(u8* screen, TBGR colour);external;
void * HexTopfill(u8* screen);external;

void * PasBotfill(u8* screen);external;
void * Topfill1;external;
void * Topfill2;external;

void * PSetPix(u8* screen, int x, int y, TBGR colour);external;
void * PSetPix1(u8* screen, int x, int y, TBGR colour);external;

TBGR PGetPix(int y, int x);external;

//void * TopLCD(u8* screen, int x, int y, TRGB colour);external;
//void * BotLCD(u8* screen, int x, int y, TRGB colour);external;
//void * TopMap(TRGB colour, int y, int x, u8* screen);external;
//void * BotMap(TRGB colour, int y, int x, u8* screen);external;


void text_printf(u8* screen, int x, int y, const char* str,...)
{
    char* formated[256];
    va_list ap;
    va_start(ap, str);
    snprintf(formated, 256, str, ap);
    //sprintf(formated, str, ap);
    va_end(ap);
    CanvasString(screen, formated, x, y, WHITE);
}

int main()
{
	gfxInitDefault();
        gfxSet3D(true); // uncomment if using stereoscopic 3D

        gfxFlushBuffers();

        transparent = BLACK;
	 gfxSetScreenFormat(GFX_TOP, GSP_BGR8_OES);
	 gfxSetScreenFormat(GFX_BOTTOM, GSP_BGR8_OES);
        InitBufSingle(BLACK);
/*
	ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
	ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
	ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 

	ClrParx(ParxLeft, BLACK); 
	ClrParx(ParxRight, BLACK); 
	ClrParx(ParxBot, BLACK);
*/

	char* str[256];
        int l, k, j, i=20, posx = 100, posy = 100;
        TBGR rgbsam;
        TBGR rgb;
	u64 time; 

	// Main loop
	while (aptMainLoop())
	{
//		gspWaitForVBlank();

//		  	ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
//			ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
//			ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 

		hidScanInput();              
		u32 kDown = hidKeysHeld();

		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
                if (kDown & KEY_A)
			{
                          CanvasString(ParxBot, CopyRight(), 10,10, LIGHT_GREEN);
			}
                if (kDown & KEY_B)
			{
                          
			}
                if (kDown & KEY_X)
			{
                          TestPattern();
			}
                if (kDown & KEY_Y)
			{

		  	ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
                          ClrParx(ParxLeft, BLACK); 
 			  //PasTopfill(ParxLeft);

			ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
	                  ClrParx(ParxRight, BLACK);
 			 // PasTopfill(ParxRight);

			ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 
	                  //ClrParx(ParxBot, BLACK);
	
//			  PasBotfill(ParxBot);
			rgb.r= 0xFF;
			rgb.g= 0x00;
			rgb.b= 0x8F;
			  PasClrSrc(ParxBot, rgb);
			}
                if(kDown & KEY_CPAD_DOWN)
                        {	     
			rgb.r= 0x00;
			rgb.g= 0x00;
			rgb.b= 0XFF;
			PasTopfill(ParxLeft, rgb);
			PasTopfill(ParxRight, rgb);
			}

                if(kDown & KEY_CPAD_UP) 
                        {	
                        
			rgb.r= 0xFF;
			rgb.g= 0x00;
			rgb.b= 0x00;		
			PasTopfill(ParxLeft, rgb);
			PasTopfill(ParxRight, rgb);
			}
                if(kDown & KEY_CPAD_RIGHT) 
                        {	
                        
			rgb.r= 0x00;
			rgb.g= 0xFF;
			rgb.b= 0x00;
			PasTopfill(ParxLeft, rgb);
			PasTopfill(ParxRight, rgb);
			}

                if(kDown & KEY_CPAD_LEFT)
                        {
                        
			rgb.r= 0x00;
			rgb.g= 0x11;
			rgb.b= 0x00;
						
			HexTopfill(ParxLeft);
			HexTopfill(ParxRight);
			}               
                if(kDown & KEY_R)
                        {	
                                Topfill1;
                                ClrParx(ParxBot, BLACK);
                                sprintf(str, "Dergibal Rad:%i  X:%i  Y:%i", i, posx, posy);
				CanvasString(ParxBot, str, 0, 0, RED);
			}

                if(kDown & KEY_L) 
                        {			
			        Topfill2;
                                ClrParx(ParxBot, BLACK);
                                sprintf(str, "Dergibal Rad:%i  X:%i  Y:%i", i, posx, posy);
				CanvasString(ParxBot, str, 0, 0, RED);
			}
                if(kDown & KEY_DUP)
                        {	
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  if (k<320) PSetPix(ParxBot,k,l, PGetPix(k,l));
} 

			}

                if(kDown & KEY_DDOWN)
                        {	
                             //   SetTopFramebuffers(0);  
time= osGetTime();
			
			rgb.r= 0xCC;
			rgb.g= 0x11;
			rgb.b= 0xCC;
			
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  TopLCD(ParxRight,k,l, rgb);
  TopLCD(ParxLeft,k,l, rgb);
  if (k<320) BotLCD(ParxBot,k,l, rgb);
}

time = osGetTime() - time; 
sprintf(str, "%i:ms ParxPro,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  
		
			}                
		if(kDown & KEY_DRIGHT)
                        {
time= osGetTime();
			rgb.r= 0xEE;
			rgb.g= 0x00;
			rgb.b= 0xCC;
		
			
                       for (k=0;l<400;l++)
                        for (l=0;k<240;k++)
{
				TopMap(rgb,l,k,ParxRight); 
				TopMap(rgb,l,k,ParxLeft); 
                                if (k<320) BotMap(rgb,l,k,ParxBot); 
}

time = osGetTime() - time; 
sprintf(str, "L&R&B %i:ms ParxPro,kdl", time);

CanvasString(ParxBot, str, 10,10, LIGHT_GREEN); 

			}

                if(kDown & KEY_DLEFT)
                        {				
                     //   SetTopFramebuffers(0);  
time= osGetTime();
			
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  SetPix(ParxRight,k,l,BLACK);
  SetPix(ParxLeft,k,l,BLACK);
  if (k<320) SetPix(ParxBot,k,l,BLACK);
}

time = osGetTime() - time; 
sprintf(str, "%i:ms Parx-GDI,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  
		}
//gfxString(ParxRight, str, 30,30, 3, rgb); 
//gfxString(ParxLeft, str, 30,30, 3, rgb);   
//for (l=1;l<16;l++) print3d(rgb,10*l,10*l,l-1,3,str);



		//render rainbow
//		renderEffect();
		//copy buffer to lower screen (don't have to do it every frame)
//		memcpy(gfxGetFramebuffer(GFX_BOTTOM, GFX_BOTTOM, NULL, NULL), buffer, size);
		//wait & swap
//		gfxSwapBuffersGpu();
//		gspWaitForEvent(GSPGPU_EVENT_VBlank0, false);

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
