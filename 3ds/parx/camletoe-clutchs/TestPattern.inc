
procedure TestPattern(); stdcall;

procedure SetPixTop(x,y: integer; colour: Hex24); stdcall;
begin
  SetGFXPix(PByte(gfxTopLeftFramebuffers[0]),x,y,colour);
  SetGFXPix(PByte(gfxTopRightFramebuffers[0]),x,y,colour);
end;

var i,j: integer; 
begin
//test pattern 1st pass 
				for i := 0 to 79 do 
				  for j := 0 to 200 do 
begin
                                SetPixTop(i,j, {$ifdef Quad}RED {$endif Quad} {$ifdef Triplet}$FF0000{$endif Triplet}); 
                                SetPixTop(i+80,j, {$ifdef Quad} CYAN{$endif Quad} {$ifdef Triplet} $FFFF00{$endif Triplet});
                                SetPixTop(i+160,j, {$ifdef Quad} YELLOW{$endif Quad} {$ifdef Triplet} $00FFFF{$endif Triplet}); 
                                SetPixTop(i+240,j,{$ifdef Quad} BLACK{$endif Quad} {$ifdef Triplet} $0{$endif Triplet});
                                SetPixTop(i+320,j, {$ifdef Quad} BLUE{$endif Quad} {$ifdef Triplet} $0000FF{$endif Triplet});				
end;
//test pattern 2nd pass 
				for i := 0 to 99 do 
				  for j := 201 to 239 do
begin
                                SetPixTop(i,j, {$ifdef Quad} PINK{$endif Quad} {$ifdef Triplet}$FF00FF{$endif Triplet});
                                SetPixTop(i+100,j,{$ifdef Quad} LIGHT_GREEN{$endif Quad} {$ifdef Triplet} $00CC00{$endif Triplet}); 
                                SetPixTop(i+200,j,{$ifdef Quad} WHITE{$endif Quad} {$ifdef Triplet} $FFFFFF {$endif Triplet}); 
                                SetPixTop(i+300,j,{$ifdef Quad} ORANGE{$endif Quad} {$ifdef Triplet} $FF9900 {$endif Triplet});
end;
end;
// {$ifdef Quad} $FFFF0000 {$endif Quad} 
// {$ifdef Triplet}$FF0000{$endif Triplet} 
// {$ifdef Sweet16}$FF00  {$endif Sweet16}
 //{$ifdef MCRobot}$FF0000 {$endif MCRobot}
