//Citizen Ken's: But; U'r Eminence; wii the people of pascal republic half
//how do U say thee de-light full
//De Coded "Channel 5" transmissions of Sisters Sledge & the armada of hypoalogentic

//But Sir: U'r Eminence, Her distress beacon it's the telegraph is requesting "send in the clowns"?
//U'r Eminence if wii kick in the doors & dump there knight $tand$ of Modula $epretistS 
//Yes i'll do it in for "Kink & cunt for free"   
  
   
 
type
TopRawLinear= array[0..{$ifdef MCRobot}95999 {$endif MCRobot}{$ifdef Quad}499999 {$endif Quad}{$ifdef Triplet}287999 {$endif Triplet} {$ifdef Sweet16}191999 {$endif Sweet16}] of {$ifdef MCRobot}XBW {$else}Byte {$endif MCRobot}; //240×400×(4 or 3)bytes  
PTopRawLinear= ^TopRawLinear;
BotRawLinear= array[0..{$ifdef MCRobot}76799 {$endif MCRobot}{$ifdef Quad}403999 {$endif Quad}{$ifdef Triplet}230399 {$endif Triplet} {$ifdef Sweet16}153599 {$endif Sweet16}] of {$ifdef MCRobot}XBW {$else}Byte {$endif MCRobot}; //240×320×((4 or 3)bytes or single bits)
PBotRawLinear= ^BotRawLinear;

//alpha map
TopMapLED= array[0..399,0..239 {$ifdef MCRobot} ] of XBW {$else} ,0..{$i ZeroBase.inc}] of Byte {$endif MCRobot};
PTopMapLED= ^TopMapLED;
BotMapLED= array[0..319,0..239 {$ifdef MCRobot} ] of XBW {$else} ,0..{$i ZeroBase.inc}] of Byte {$endif MCRobot}; // y,x,c @ lengths
PBotMapLED= ^BotMapLED;
Strife= Array[0..239 {$ifdef MCRobot} ] of XBW {$else} ,0..{$i ZeroBase.inc}] of Byte {$endif MCRobot}; 

//VRAM Map sprites & after the collaps of Alpha ???
//cast as Type seem to Work in Single & Double Buffering  
    var
        ParxLeft0 :  {$i Rastarfar.inc} absolute PVL0;
        ParxRight0 : {$i Rastarfar.inc}	absolute PVR0;
        ParxBot0 :   BotRawLinear 	absolute PVB0;
                
        ParxLeft1 :  {$i Rastarfar.inc} absolute PVL1; 
        ParxRight1 : {$i Rastarfar.inc} absolute PVR1;
        ParxBot1 :   BotRawLinear 	absolute PVB1;
        
//kdl