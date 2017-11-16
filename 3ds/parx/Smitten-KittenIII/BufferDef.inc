type
TopRawLinear= array[0..{$ifdef Quad}499999 {$else}287999 {$endif Quad}] of Byte; //240×400×(4 or 3)bytes  
PTopRawLinear= ^TopRawLinear;
BotRawLinear= array[0..{$ifdef Quad}403999 {$else}230399 {$endif Quad}] of Byte; //240×320×(4 or 3)bytes
PBotRawLinear= ^BotRawLinear;

//alpha map
TopMapLED= array[0..399,0..239,0..{$i ZeroBase.inc}] of Byte; 
PTopMapLED= ^TopMapLED;
BotMapLED= array[0..319,0..239,0..{$i ZeroBase.inc}] of Byte; // y,x,c @ lengths
PBotMapLED= ^BotMapLED;
Strife= Array[0..239, 0..{$i ZeroBase.inc}] Of Byte; 

//VRAM Map sprites & after the collaps of Alpha ???
var        
        ParxLeft1 : PTopRawLinear absolute PVL0;
        ParxRight1 : PTopRawLinear absolute PVR0;
        ParxBot1 : PBotRawLinear absolute PVB0;
                
        ParxLeft2 : TopMapLED absolute PVL1;
        ParxRight2 : TopMapLED absolute PVR1;
        ParxBot2 : BotMapLED absolute PVB1;
        
//kdl