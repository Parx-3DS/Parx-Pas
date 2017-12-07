//Nintendo 2DS .. 3DS Pascal Development 
//  
//  illustrated in pascal resorting to Plan "B" long ago & still I'm short sums of money from none other than 
//                a.) Oil & Gas Re: Television, media, communications &or radio their divsions 
//                b.) ANY Corporate logos & Trade Marks usage of "Must provide resonable funding!"  
//   
// copyrights 2017 Kenneth Dwayne Lee 
//all rights reserved.
  


{.$ifndef PascalPublic}  
// protected
 private
    ClExt: ColourExt;
{.$endif PascalPublic}    
    
    
function GetPixL(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixL';{$else}overload; {$endif PascalPublic}  //override
function GetPixR(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixR';{$else}overload; {$endif PascalPublic}
function GetPixB(x: word; y: word): {$i Propaganda.inc}; {$ifdef PascalPublic} public name 'GetPixB';{$else}overload; {$endif PascalPublic}
 
procedure SetPixL(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixL';{$else}overload; {$endif PascalPublic}
procedure SetPixR(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixR';{$else}overload; {$endif PascalPublic}
procedure SetPixB(x: word; y: word;colour: {$i Propaganda.inc}); {$ifdef PascalPublic} public name 'SetPixB';{$else}overload; {$endif PascalPublic}


{$ifndef PascalPublic}


//call up the buffers -1 .. 1 for " ... & burst there double bubbles in 3D"


      
    function GetSrcL(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap}; 
    function GetSrcR(index: integer):{$undef Trap}{$i Rastarfar.inc} {$define Trap}; 
    function GetSrcB(index: integer):	{$ifdef MCRobot}XBot {$endif MCRobot}
    					{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					{$ifdef Triplet}BGRBot {$endif Triplet}
					{$ifdef Quad}RGBABot{$endif Quad} ;  
					

    procedure SetSrcL(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap} );
    procedure SetSrcR(index: integer; Val :{$undef Trap}{$i Rastarfar.inc} {$define Trap}); 
    procedure SetSrcB(index: integer; Val :{$ifdef MCRobot}XBot {$endif MCRobot}
    					{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    					{$ifdef Triplet}BGRBot {$endif Triplet}
					{$ifdef Quad}RGBABot{$endif Quad} ); 
					
    procedure ClrAll(colour: {$i Propaganda.inc});
    procedure BufDubSub(index: integer); 
    procedure propriganda;
    constructor Create; 
    Destructor Destroy;
	public
	
 //  LScr := gfxGetFramebuffer(GFX_TOP, GFX_LEFT, nil, nil); 
 //  RScr := gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, nil, nil); 
 //  BScr := gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, nil, nil);
   
    property LScr[x: integer]: {$undef Trap}{$i Rastarfar.inc} {$define Trap} read GetSrcL write SetSrcL;
    property RScr[x: integer]: {$undef Trap}{$i Rastarfar.inc} {$define Trap} read GetSrcR write SetSrcR;
    property BScr[x: integer]:  {$ifdef MCRobot}XBot {$endif MCRobot}
    				{$ifdef Sweet16}RGB16Bot {$endif Sweet16}
    				{$ifdef Triplet}BGRBot {$endif Triplet}
				{$ifdef Quad}RGBABot{$endif Quad} {BotRawLinear} read GetSrcB write SetSrcB;
    
    property L3D[x: word; y: word]: {$i Propaganda.inc} read GetPixL write SetPixL;
    property R3D[x: word; y: word]: {$i Propaganda.inc} read GetPixR write SetPixR;
    property Bot[x: word; y: word]: {$i Propaganda.inc} read GetPixB write SetPixB;
{$endif PascalPublic}

//  hopefully I don't have to shake my own leg 
