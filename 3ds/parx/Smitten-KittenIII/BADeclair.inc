//KDL
{$ifdef Trap} {$ifdef Trip} Byte32 {$else} Byte24 {$endif}{$else}
{$ifdef TopLinear}{$ifdef ScBin} PBINTopl {$endif} {$ifdef ScOct} POCTTopl {$endif} {$ifdef ScHex} PHEXTopl {$endif} {$ifdef ScDec}PDECTopl{$endif} {$ifdef ScBool}PBoolTopl{$endif}{$endif}
{$ifdef BotLinear}{$ifdef ScBin} PBINBotl {$endif} {$ifdef ScOct} POCTBotl {$endif} {$ifdef ScHex} PHEXBotl {$endif}{$ifdef ScDec}PDECBotl {$endif} {$ifdef ScBool}PBoolBotl {$endif}{$endif}
{$ifdef TopMapped}{$ifdef ScBin} PBINTop {$endif} {$ifdef ScOct} POCTTop {$endif} {$ifdef ScHex} PHEXTop {$endif} {$ifdef ScDec}PDECTop {$endif} {$ifdef ScBool}PBoolTop {$endif}{$endif}
{$ifdef BotMapLED} {$ifdef ScBin} PBINBot {$endif} {$ifdef ScOct} POCTBot {$endif} {$ifdef ScHex} PHEXBot {$endif} {$ifdef ScDec}PDECBot {$endif} {$ifdef ScBool}PBoolBot {$endif}{$endif}