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

Var 
BuffIndex: integer;        
    
    
procedure RefreshBuffer(); stdcall; public name 'RefreshBuffer';
    
implementation

procedure RefreshBuffer();
begin 
 gfxFlushBuffers();
 if BuffIndex <> -1 then gfxSwapBuffers();
 if BuffIndex <> 1 then inc(BuffIndex) else dec(BuffIndex); 
end;

end.