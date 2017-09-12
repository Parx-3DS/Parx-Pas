//the witch, warlock burning & pilgrammige hour Presents
//Bow on box stollen from U bi the insain, like a sexlife without cite, sent nor taste 

//So what's Twisting Sister?
//& your going to burn in .. 
//don't shrew C != evil && don't shrew pascal <> evil 

#include <string.h>
#include <stdarg.h>

#include <3ds.h>
#include <ParxGDI.h>
#include "Parx/ZürichUnclean/Parx.h"


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
        transparent = BLACK;
        InitBufSingle(BLACK);
//	ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
//	ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
//	ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 

//	ClrParx(ParxLeft, BLACK); //	ClrParx(ParxRight, BLACK); 
//	ClrParx(ParxBot, BLACK);


	char* str[256];
        int j,k,l;

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();

		hidScanInput();              
		u32 kDown = hidKeysHeld();

		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
                if (kDown & KEY_SELECT)
                       {
                       
	        InitBufSingle(BLACK);
                       	//ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
//                          ClrParx(ParxLeft, BLACK); 
			//ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
//	                  ClrParx(ParxRight, BLACK);
			//ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 
//	                  ClrParx(ParxBot, BLACK);
			}
                if(kDown & KEY_DRIGHT)
                        {	 	
			 bgr.r= 0x00;	
			 bgr.g= 0x00;	
			 bgr.b= 0x00;
time= osGetTime();
			
     for (k=0;k<400;k++)
      for (l=0;l<240;l++)
{
     PSetPix(ParxRight,k,l,bgr);
     PSetPix(ParxLeft,k,l,bgr);
   if (k<320) BSetPix(ParxBot,k,l,bgr);
}

time = osGetTime() - time; 
sprintf(str, "%i:ms Parx-GDI,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  

			}

                if(kDown & KEY_DLEFT) 
                        {			
			 bgr.r= 0xFF;	
			 bgr.g= 0xFF;	
			 bgr.b= 0xFF;
time= osGetTime();
			
       for (l=0;l<400;l++)
        for (k=0;k<240;k++)
{
	GFXPix(bgr,l,k,ParxRight); 
	GFXPix(bgr,l,k,ParxLeft); 
        if (l<320) GFXPixB(bgr,l,k,ParxBot); 
}

time = osGetTime() - time; 
sprintf(str, "L&R&B %i:ms Parx+&GDI,kdl", time);
CanvasString(ParxBot, str, 10,10, LIGHT_GREEN); 
    
			
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
//Your last chance to atone, pilgram
// Please send Your virgin?? Daugter & sum of money 
//C.o. PhD kenneth Dwayne Lee 