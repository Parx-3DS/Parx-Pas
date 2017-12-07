//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.


//Top screens are declared as MapLED 
procedure TopByteFill(screen:PByte;{$ifdef MCRobot} Interval:WORD; Pitch: XBW {$else} Interval:BYTE; Pitch: BYTE {$endif MCRobot});stdcall;
Var
  x,y: integer;
  mvid : PTopMapLED; 
BEGIN
  mvid:= PTopMapLED(screen);
        for x :=  0 to 399 do 
        for y :=  0 to 239 do  
  {$ifdef MCRobot}
   if ((Interval mod y) <> 0) and ((Interval mod y) <> 0) then
   mvid^[x,y]:= Pitch
  {$else}
  mvid^[x,y,Interval]:= Pitch 
  {$endif MCRobot}
END;

//Bottem declared as RawLinear  
procedure BotByteFill(screen:PByte; Interval:BYTE; Pitch: {$ifdef MCRobot}XBW {$else}BYTE {$endif MCRobot});stdcall;
Var
  x,y: integer;
  mvid : PBotMapLED; 
BEGIN
  mvid:= PBotMapLED(screen); 
        for x :=  0 to 339 do 
        for y :=  0 to 239 do    
  {$ifdef MCRobot}
   if (Interval mod y) <> 0 then
   mvid^[x,y]:= Pitch
  {$else}
  mvid^[x,y,Interval]:= Pitch 
  {$endif MCRobot}
END;
