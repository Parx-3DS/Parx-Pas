
{$define ColVertLine}

{$define ScHex}
{$i ParxPro.inc}
{$undef ScHex}

{$define ScBool}
{$i ParxPro.inc}
{$undef ScBool}

{$define ScDec}
{$i ParxPro.inc}
{$undef ScDec}

{$ifdef Quad} 
{$define PascalPublic}
{$endif Quad}

{$define ScBGR}
{$i ParxPro.inc}
{$undef ScBGR}

{$ifdef Quad} 
{$undef PascalPublic}
{$endif Quad}

{$define ScBin}
{$i ParxPro.inc}
{$undef ScBin}

{$define ScOct}
{$i ParxPro.inc}
{$undef ScOct}

{$undef ColVertLine}