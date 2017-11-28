//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 PhD. Kenneth Dwayne Lee 
//all rights reserved.
  
function GetPixL(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixL';{$else}overload; {$endif PascalPublic}  //override
function GetPixR(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixR';{$else}overload; {$endif PascalPublic}
function GetPixB(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixB';{$else}overload; {$endif PascalPublic}
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixL';{$else}overload; {$endif PascalPublic}
procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixR';{$else}overload; {$endif PascalPublic}
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixB';{$else}overload; {$endif PascalPublic}


//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"


      
    function GetSrcL(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap}; stdcall;{$ifdef PascalPublic} public name 'GetSrcL';{$else}overload; {$endif PascalPublic}
    function GetSrcR(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap}; stdcall;{$ifdef PascalPublic} public name 'GetSrcR';{$else}overload; {$endif PascalPublic}
    function GetSrcB(index: integer):	{$ifdef MCRobot}XBot {$endif MCRobot}
    					{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					{$ifdef Triplet}BGRBot {$endif Triplet}
					{$ifdef Quad}RGBABot{$endif Quad} ;          {$ifdef PascalPublic} public name 'GetSrcB';{$else}overload; {$endif PascalPublic} 
					

    procedure SetSrcL(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap}); stdcall;{$ifdef PascalPublic} public name 'SetSrcL';{$else}overload; {$endif PascalPublic}
    procedure SetSrcR(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap}); stdcall;{$ifdef PascalPublic} public name 'SetSrcR';{$else}overload; {$endif PascalPublic}
    procedure SetSrcB(index: integer; Val :{$ifdef MCRobot}XBot {$endif MCRobot}
    					{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					{$ifdef Triplet}BGRBot {$endif Triplet}
					{$ifdef Quad}RGBABot{$endif Quad} ); 		    stdcall;{$ifdef PascalPublic} public name 'SetSrcB';{$else}overload; {$endif PascalPublic}
					
    procedure ClrAll(colour: {$i Propaganda.inc});stdcall;   
    procedure propriganda;stdcall;

//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D" 
    procedure BufDubSub(index: integer);stdcall;				
    {$ifdef PascalPublic} public name 'BufDubSub';{$else}overload; {$endif PascalPublic}
    
    procedure BufDubClr(colour: {$i Propaganda.inc}; index: integer);stdcall;	
    {$ifdef PascalPublic} public name 'BufDubClr';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufSingle(colour: {$i Propaganda.inc});stdcall;		
    {$ifdef PascalPublic} public name 'InitBufSingle';{$else}overload; {$endif PascalPublic}
    
    procedure InitBufDub(colour: {$i Propaganda.inc});stdcall;			
    {$ifdef PascalPublic} public name 'InitBufDub';{$else}overload; {$endif PascalPublic}



   // constructor Create; 
   // Destructor Destroy;
   //	public
	
 //  LScr := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
 //  RScr := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil); 
 //  BScr := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);


{.$ifndef PascalPublic}  
// protected
// private
var
    ClExt: ColourExt;
{.$endif PascalPublic}       
    property LScr[x: integer]: {$undef Trap}{$i Rastarfar.inc} {$define Trap} read GetSrcL write SetSrcL;
    property RScr[x: integer]: {$undef Trap}{$i Rastarfar.inc} {$define Trap} read GetSrcR write SetSrcR;
    property BScr[x: integer]:  {$ifdef MCRobot}XBot {$endif MCRobot}
    				{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    				{$ifdef Triplet}BGRBot {$endif Triplet}
				{$ifdef Quad}RGBABot{$endif Quad} {BotRawLinear} read GetSrcB write SetSrcB;
    
    property L3D[x: word; y: word]: {$i Propaganda.inc} read GetPixL write SetPixL;
    property R3D[x: word; y: word]: {$i Propaganda.inc} read GetPixR write SetPixR;
    property Bot[x: word; y: word]: {$i Propaganda.inc} read GetPixB write SetPixB;

//  hopefully I don't have to shake my own leg 
