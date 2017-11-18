//KDL
{$define Trap}
procedure TopLCD(screen:Pbyte; x: word; y: word; colour:{$i PIXelView.inc});stdcall; {$ifdef PascalPublic}public name 'TopLCD';{$else}overload; {$endif PascalPublic} 
procedure BotLCD(screen:Pbyte; x: word; y: word; colour:{$i PIXelView.inc});stdcall; {$ifdef PascalPublic} public name 'BotLCD';{$else}overload; {$endif PascalPublic}
procedure TopMap(colour:{$i PIXelView.inc}; y: word; x: word; screen:Pbyte);stdcall; {$ifdef PascalPublic} public name 'TopMap';{$else}overload; {$endif PascalPublic}
procedure BotMap(colour:{$i PIXelView.inc}; y: word; x: word; screen:Pbyte);stdcall; {$ifdef PascalPublic} public name 'BotMap';{$else}overload; {$endif PascalPublic}
{$ifdef ColVertLine} 
//procedure TopMap(colour: array of {$i PIXelView.inc}; x: word; screen:Pbyte);stdcall; {$ifdef PascalPublic} public name 'TopMap';{$else}overload; {$endif PascalPublic}
//procedure BotMap(colour: array of {$i PIXelView.inc}; x: word; screen:Pbyte);stdcall; {$ifdef PascalPublic} public name 'BotMap';{$else}overload; {$endif PascalPublic}
{$endif} 
{$undef Trap}