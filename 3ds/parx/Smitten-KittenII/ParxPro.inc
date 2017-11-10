//KDL
{$define Trap}
procedure TopLCD(screen:Pu8; x: u16; y: u16; colour:{$i PIXelView.inc});stdcall; public name 'TopLCD';
procedure BotLCD(screen:Pu8; x: u16; y: u16; colour:{$i PIXelView.inc});stdcall; public name 'BotLCD';
procedure TopMap(colour:{$i PIXelView.inc}; y: u16; x: u16; screen:Pu8);stdcall; public name 'TopMap';
procedure BotMap(colour:{$i PIXelView.inc}; y: u16; x: u16; screen:Pu8);stdcall; public name 'BotMap';
{$ifdef ColVertLine} 
//procedure TopMap(colour: array of {$i PIXelView.inc}; x: u16; screen:Pu8);stdcall; public name 'TopMap';
//procedure BotMap(colour: array of {$i PIXelView.inc}; x: u16; screen:Pu8);stdcall; public name 'BotMap';
{$endif} 
{$undef Trap}