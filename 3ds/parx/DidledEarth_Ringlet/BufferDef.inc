type
TopRawLinear= array[0..{$ifdef Quad}499999 {$endif Quad}{$ifdef Triplet}287999 {$endif Triplet} {$ifdef Sweet16}191999 {$endif Sweet16}] of Byte; //240×400×(4 or 3)bytes  
PTopRawLinear= ^TopRawLinear;
BotRawLinear= array[0..{$ifdef Quad}403999 {$endif Quad}{$ifdef Triplet}230399 {$endif Triplet} {$ifdef Sweet16}153599 {$endif Sweet16}] of Byte; //240×320×(4 or 3)bytes
PBotRawLinear= ^BotRawLinear;

//alpha map
TopMapLED= array[0..399,0..239,0..{$i ZeroBase.inc}] of Byte; 
PTopMapLED= ^TopMapLED;
BotMapLED= array[0..319,0..239,0..{$i ZeroBase.inc}] of Byte; // y,x,c @ lengths
PBotMapLED= ^BotMapLED;
Strife= Array[0..239, 0..{$i ZeroBase.inc}] Of Byte; 

//VRAM Map sprites & after the collaps of Alpha ???
//Pointer & Type seem to Work in Double Buffering
    var
        ParxLeft1 : PTopRawLinear absolute PVL0;
        ParxRight1 : PTopRawLinear absolute PVR0;
        ParxBot1 : PBotRawLinear absolute PVB0;
                
        ParxLeft2 : TopMapLED absolute PVL1; 
        ParxRight2 : TopMapLED absolute PVR1;
        ParxBot2 : BotMapLED absolute PVB1;
        
//kdl