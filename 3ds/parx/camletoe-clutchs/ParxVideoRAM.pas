unit ParxVideoRAM;
 
{$mode objfpc}{$H+}
 
interface

  {$include gfx.inc}
  
//single & double buffer Video RAM Map address
const

        PVL0= $1E6000;
        PVR0= $22C800;
        PVB0= $48F000;
                
        PVL1= $273000;
        PVR1= $2B9800;
        PVB1= $4C7800;
 
       
//  PVL: array[0..1] of LongInt = (PVL0,PVL1);
//  PVR: array[0..1] of LongInt = (PVR0,PVR1);
//  PVB: array[0..1] of LongInt = (PVB0,PVB1);   

{$TYPEDADDRESS ON}
{Var
  PVL: array[0..1] of TopMapLED; // = (PVL0, PVL1);
  PVR: array[0..1] of TopMapLED; // = (PVR0,PVR1);
  PVB: array[0..1] of BotMapLED; // = (PVB0,PVB1);   
 
  VL: PVL absolute gfxTopLeftFramebuffers; 
}{$TYPEDADDRESS OFF} 
type
T24Q= array[0..239, 0..2 {720 div 80 = 9}] of Byte;  
T8Q= array[0..239] of Byte; 
T16Q= array[0..239] of Word; 
T32Q= array[0..239] of DWord; //RGBA 959

Var 
BuffIndex: integer;        
    
    
procedure RefreshBuffer(); stdcall; public name 'RefreshBuffer';
    
implementation     
     
Var
       //T. Sexpranks is on Channel 5 in "the, 3D sprite stuff", 
       //here honey give me the remote i'm going to flush it. I know where wii're staying ...     
        ParxL1 : PByte absolute $22C501; // $2FE or 766 bytes upto $22C7FF //(239 * 399)? 
        ParxR1 : PByte absolute $272D01; // $2FE or 766 bytes upto $2B97FF ?
        ParxB1 : PByte absolute $4C7401; //$3FE or 1022 bytes upto $4C77FF //(239 * 339)??

procedure RefreshBuffer();
begin 
 gfxFlushBuffers();
 if BuffIndex <> -1 then gfxSwapBuffers();
 if BuffIndex <> 1 then inc(BuffIndex) else dec(BuffIndex); 
end;

end.