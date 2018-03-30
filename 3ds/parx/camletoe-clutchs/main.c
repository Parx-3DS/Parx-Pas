#include <string.h>
#include <stdarg.h>

#include <3ds.h>
#include <ParxGDI.h>

//#include "bmp.h"

typedef struct TBGR
{ 
   u8   b;
   u8   g;
   u8   r;  
} TBGR;


void * TopLCD(u8* screen, int x, int y, TBGR colour);external;
void * BotLCD(u8* screen, int x, int y, TBGR colour);external;
void * TopMap(TBGR colour, int y, int x, u8* screen);external;
void * BotMap(TBGR colour, int y, int x, u8* screen);external;

char * CopyRight ();external;
void * TestPattern ();external;
void * RefreshBuffer ();external;

void * InitParx(u32 colour);external;
void * InitBufSingle(u32 colour);external;
void * InitBufDub(u32 colour);external;

void* BufSub(int index);external;

void * PasClrSrc(u8* screen, TBGR colour);external;
void * PasTopfill(u8* screen, TBGR colour);external;
void * HexTopfill(u8* screen);external;

void * PasBotfill(u8* screen);external;
void * Topfill1;external;
void * Topfill2;external;
void * Topfill3;external;

void * PSetPixB(u8* screen, int x, int y, TBGR colour);external;
void * PSetPixT(u8* screen, int x, int y, TBGR colour);external;
void * PSetPix1(u8* screen, int x, int y, TBGR colour);external;

void * SetPixL(int x, int y, TBGR colour);external;
void * SetPixR(int x, int y, TBGR colour);external;
void * SetPixB(int x, int y, TBGR colour);external;

TBGR GetPixL(int y, int x);external;
TBGR GetPixR(int y, int x);external;
TBGR GetPixB(int y, int x);external;

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
        InitParx(BLACK);
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
	u8* tempScr;
	bool Dbuf;	
	
	circlePosition pos;
	touchPosition touch;

	// Main loop
	while (aptMainLoop())
	{
//		gspWaitForVBlank();

//		  	ParxLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
//			ParxRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 
//			ParxBot = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL); 

		hidScanInput();              
		u32 kDown = hidKeysHeld();

         
		//Read the CirclePad position
		hidCircleRead(&pos);

		//Print the CirclePad position
//-		printf("\x1b[2;0H%04d; %04d", pos.dx, pos.dy);
		

		//Read the touch screen coordinates
		hidTouchRead(&touch);
		
		//Print the touch screen coordinates
//		printf("\x1b[2;0H%03d; %03d", touch.px, touch.py);
		

		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
                if (kDown & KEY_A)
			{
                          CanvasString(ParxBot, CopyRight(), 10,10, LIGHT_GREEN);
			}
                if (kDown & KEY_B)
			{
                          time= osGetTime();
			
			rgb.r= 0xCC;
			rgb.g= 0x33;
			rgb.b= 0xCC;
			
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  SetPixL(k,l,rgb); //TopLCD
  SetPixR(k,l,rgb);
  if (k<320) SetPixB(k,l,rgb); //BotLCD
}

time = osGetTime() - time; 
sprintf(str, "%i:ms ParxPro SetPix L/R/B,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  

			}
                if (kDown & KEY_X)
			{
                          TestPattern();
			}
                if (kDown & KEY_Y)
			{
			InitParx(BLACK);
		  	
//			  PasBotfill(ParxBot);
			rgb.r= 0xFF;
			rgb.g= 0x00;
			rgb.b= 0x8F;
			  PasClrSrc(ParxBot, rgb);
			  CanvasString(ParxBot, "InitParx", 10,10, GREEN);  
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
time= osGetTime();
			PasTopfill(ParxLeft, rgb);
			PasTopfill(ParxRight, rgb);

time = osGetTime() - time; 
sprintf(str, "%i:ms L&R BGRTop,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  
			}

                if(kDown & KEY_CPAD_LEFT)
                        {
                        
			rgb.r= 0x00;
			rgb.g= 0x11;
			rgb.b= 0x00;
time= osGetTime();					
						
			HexTopfill(ParxLeft);
			HexTopfill(ParxRight);

time = osGetTime() - time; 
sprintf(str, "%i:ms L&R TopMapLED,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  
			}               
                if(kDown & KEY_R)
                        {	
                              	//InitBufSingle(BLACK);
                                ClrParx(ParxBot, BLACK);
                                //i of linearSpaceFree(); //no effect
                                //i of vramSpaceFree(); //reads as Zero 
                                //i of mappableSpaceFree(); //no change in alloc & free 
                                
                                sprintf(str, "v:%i  m:%i  l:%i", vramSpaceFree, mappableSpaceFree, linearSpaceFree);
				CanvasString(ParxBot, str, 0, 10, RED);
				
                                Topfill2;
                                sprintf(str, "v:%i  m:%i  l:%i", vramSpaceFree, mappableSpaceFree, linearSpaceFree);
				CanvasString(ParxBot, str, 0, 20, RED);
				
                               // Topfill3;
                               // sprintf(str, "Topfill3 Free :%i", vramSpaceFree);
				//CanvasString(ParxBot, str, 0, 40, RED);
				
                                //sprintf(str, "Topfill3 Free :%i", );
				//CanvasString(ParxBot, str, 0, 40, RED);
			}

                if(kDown & KEY_L) 
                        {	
                        	if (Dbuf) InitBufDub(BLACK); else InitBufSingle(BLACK);		
			        Topfill1;
                                ClrParx(ParxBot, BLACK);
                              //  sprintf(str, "Dergibal Rad:%i  X:%i  Y:%i", i, posx, posy);
                              
                        	if (Dbuf) CanvasString(ParxBot, "InitBufDub", 0, 40, RED); else
                        	CanvasString(ParxBot, "InitBufSingle", 0, 40, RED); (BLACK);	
                        	Dbuf = !Dbuf;
			}
                if(kDown & KEY_DUP)
                        {	
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  if (k<320) PSetPixT(ParxRight,k,l, GetPixB(k,l));
} 

			}

                if(kDown & KEY_DDOWN)
                        {	
time= osGetTime();
			
			rgb.r= 0xCC;
			rgb.g= 0x11;
			rgb.b= 0xCC;
			
                        for (k=0;k<400;k++)
                          for (l=0;l<240;l++)
{
  PSetPixT(ParxRight,k,l, rgb); //TopLCD
  PSetPixT(ParxLeft,k,l, rgb);
  if (k<320) PSetPixB(ParxBot,k,l, rgb); //BotLCD
}

time = osGetTime() - time; 
sprintf(str, "%i:ms ParxPro,kdl", time);
CanvasString(ParxBot, str, 10,10, GREEN);  
		
			}                
		if(kDown & KEY_DRIGHT)
                        {

                         ClrParx(ParxBot, BLACK);    
                          
			rgb.r= 0xEE;
			rgb.g= 0x00;
			rgb.b= 0xCC;
		
time= osGetTime();			
                       for (k=0;k<400;k++)
                          for (l=0;l<240;l++) SetPixL(k,l,rgb); //TopLCD
time = osGetTime() - time; 
sprintf(str, "Left %i:ms ParxPro,kdl", time);
CanvasString(ParxBot, str, 10,10, LIGHT_GREEN); 

time= osGetTime();				
//ParxLeft = GetSrcL(-1); // good!!			
//tempScr = GetSrcL(0); // good!!	
//tempScr = GetSrcL(1); // good!!
//                       for (k=0;k<400;k++)
//                        { 
//                            ParxLeft = GetSrcL(-1); // good!!
//                          for (l=0;l<80;l++) PSetPixT(ParxRight,k,l, GetPixL(k,l)); // 
//       			    ParxLeft = GetSrcL(0); // good!!
//                          for (l=80;l<160;l++) PSetPixT(ParxRight,k,l, GetPixL(k,l));   		
//     			    ParxLeft = GetSrcL(1); // good!!
//                          for (l=160;l<240;l++) PSetPixT(ParxRight,k,l, GetPixL(k,l)); 
//                          //assignment to eg PSetPixT(GetSrcR(-1),k,l, GetPixL(k,l)) poops out                      
//                        }  
time = osGetTime() - time; 
sprintf(str, "ParxLeft = GetSrcL(-1&0&1); %i:ms ,kdl", time);
CanvasString(ParxBot, str, 10,20, LIGHT_GREEN); 

time= osGetTime();			
//SetSrcR(0,tempScr);	// No Good 

//SetSrcL(-1,ParxLeft);	// 
//sprintf(str, "SetSrcL(-1,ParxLeft); %i:ms ,kdl", time);
//CanvasString(ParxBot, str, 10,40, LIGHT_GREEN); 

//BufSub(-1);
//BufSub(-2);
//BufSub(-3);

//SetSrcL(-1,ParxLeft);	// 
sprintf(str, "SetSrcL(1,ParxLeft); %i:ms ,kdl", time);
CanvasString(ParxBot, str, 10,50, LIGHT_GREEN); 
//SetSrcR(0,ParxRight);	//
//sprintf(str, "SetSrcR(0,ParxRight) %i:ms ,kdl", time);
//CanvasString(ParxBot, str, 10,60, LIGHT_GREEN); 

                    //   for (k=0;k<400;k++)
                    //      for (l=0;l<240;l++) PSetPixT(GetSrcR(0),k,l,rgb); //GetSrcR(0) works                      
time = osGetTime() - time; 
sprintf(str, "SetSrc L&R(-1,(ParxLeft & ParxRight); %i:ms ,kdl", time);
CanvasString(ParxBot, str, 10,30, LIGHT_GREEN); 
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
	//	gfxFlushBuffers();
	//	gfxSwapBuffers();
        	RefreshBuffer();
		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
