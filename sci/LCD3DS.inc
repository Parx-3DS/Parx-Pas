{$ifdef TopLinear}{$ifdef Trap}PSetPix{$else}PTopRawLinear{$endif}{$endif}
{$ifdef BotLinear}{$ifdef Trap}BSetPix{$else}PBotRawLinear{$endif}{$endif}
{$ifdef TopMapped}{$ifdef Trap}GFXPix{$else}PRGBTop{$endif}{$endif}
{$ifdef BotMapLED}{$ifdef Trap}GFXPixB{$else}PRGBBot{$endif}{$endif}

//@ of var & smother your mother assignments ...