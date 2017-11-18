{$ifdef ScHex}{$ifdef Trap}{$ifdef Quad}HEX32 {$else}HEX24 {$endif Quad}{$else} H {$endif}{$endif}
{$ifdef ScDec}{$ifdef Trap}{$ifdef Quad}DEC32 {$else}DEC24 {$endif Quad}{$else} D {$endif}{$endif}
{$ifdef ScOCT}{$ifdef Trap}{$ifdef Quad}OCT32 {$else}OCT24 {$endif Quad}{$else} O {$endif}{$endif}
{$ifdef ScBIN}{$ifdef Trap}{$ifdef Quad}BIN32 {$else}BIN24 {$endif Quad}{$else} B {$endif}{$endif}
{$ifdef ScBool}{$ifdef Trap}{$ifdef Quad}BoolBit32 {$else}BoolBit24 {$endif Quad}{$else} Bools {$endif}{$endif}
{$ifdef ScBGR}{$ifdef Trap}{$ifdef Quad}TRGBA {$else}TBGR {$endif Quad}{$else} N {$endif}{$endif}