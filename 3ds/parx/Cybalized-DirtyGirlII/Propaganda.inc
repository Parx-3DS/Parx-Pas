{$ifdef Quad}{$ifdef Trap}TRGBA{$else} BYTE32 {$endif Trap}{$else}
{$ifdef Trap}TBGR{$else} BYTE24 {$endif Trap}{$endif Quad}