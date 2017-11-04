
{$define NSTL}{$i PIXelView.inc}{$undef NSTL} = array[0..96000] of {$define Trap}{$i PIXelView.inc}{$undef Trap}; //240×400
{$define PNSTL}{$i PIXelView.inc}{$undef PNSTL} = ^ {$define NSTL}{$i PIXelView.inc}{$undef NSTL};
{$define NSBL}{$i PIXelView.inc}{$undef NSBL} = array[0..76800] of {$define Trap}{$i PIXelView.inc}{$undef Trap}; //240×320
{$define PNSBL}{$i PIXelView.inc}{$undef PNSBL} = ^ {$define NSBL}{$i PIXelView.inc}{$undef NSBL};

{$define NST}{$i PIXelView.inc}{$undef NST} = array[0..399,0..239] of {$define Trap}{$i PIXelView.inc}{$undef Trap}; //240×400
{$define PNST}{$i PIXelView.inc}{$undef PNST} = ^ {$define NST}{$i PIXelView.inc}{$undef NST};
{$define NSB}{$i PIXelView.inc}{$undef NSB} = array[0..319,0..239] of {$define Trap}{$i PIXelView.inc}{$undef Trap}; //240×320
{$define PNSB}{$i PIXelView.inc}{$undef PNSB} = ^ {$define NSB}{$i PIXelView.inc}{$undef NSB};
//kdl