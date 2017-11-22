{$ifdef Quad}	{$ifdef Trap}TRGBA {$else}{$ifdef instrife}TStife32 {$else}BYTE32 {$endif instrife}{$endif Trap}{$endif Quad}
{$ifdef Sweet16}{$ifdef Trap}TRGB16{$else}{$ifdef instrife}TStife16 {$else}BYTE16 {$endif instrife}{$endif Trap}{$endif Sweet16}
{$ifdef Triplet}{$ifdef Trap}TBGR  {$else}{$ifdef instrife}TStife24 {$else}BYTE24 {$endif instrife}{$endif Trap}{$endif Triplet}

