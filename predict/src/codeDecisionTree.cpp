#include <iostream>  
#include "codeDecisionTree.h" 
using namespace std; 
 
int decision_tree(double mu[], double sigma[]){ 
if(mu[321] <= -0.5226435661315918){if(mu[497] <= -0.4203045517206192){if(mu[8] <= -0.21952355653047562){cout << "classical" << endl; return 1;}else{if(sigma[486] <= -0.5190359950065613){cout << "jazz" << endl; return 5;}else{cout << "classical" << endl; return 1;}}}else{cout << "jazz" << endl; return 5;}}else{if(mu[249] <= 1.035169780254364){if(mu[323] <= -0.4955050051212311){if(mu[432] <= -0.430603951215744){if(mu[465] <= -0.34426701068878174){if(mu[483] <= -0.46866239607334137){if(mu[4] <= -0.7408444881439209){if(mu[510] <= -0.7003301084041595){if(mu[413] <= -0.580259770154953){cout << "classical" << endl; return 1;}else{if(sigma[185] <= -0.5212569236755371){cout << "country" << endl; return 2;}else{if(mu[421] <= -0.6894896626472473){cout << "rock" << endl; return 9;}else{if(mu[3] <= -0.8437094986438751){cout << "disco" << endl; return 3;}else{cout << "reggae" << endl; return 8;}}}}}else{if(mu[441] <= -0.6064468920230865){if(sigma[435] <= -0.5197503566741943){cout << "pop" << endl; return 7;}else{cout << "jazz" << endl; return 5;}}else{if(sigma[361] <= -0.5079891681671143){cout << "classical" << endl; return 1;}else{cout << "hiphop" << endl; return 4;}}}}else{if(mu[3] <= -0.6199044585227966){if(mu[5] <= -0.7835456430912018){if(sigma[271] <= -0.5164878964424133){cout << "classical" << endl; return 1;}else{cout << "rock" << endl; return 9;}}else{cout << "country" << endl; return 2;}}else{if(mu[419] <= -0.6589592397212982){cout << "blues" << endl; return 0;}else{if(sigma[97] <= -0.4927690476179123){cout << "reggae" << endl; return 8;}else{if(mu[302] <= -0.423472061753273){cout << "rock" << endl; return 9;}else{cout << "hiphop" << endl; return 4;}}}}}}else{if(mu[501] <= 0.24396222829818726){if(mu[166] <= -0.5217835903167725){if(mu[44] <= 0.28964441269636154){if(mu[333] <= -0.5775691866874695){cout << "country" << endl; return 2;}else{if(mu[81] <= -0.48222243785858154){cout << "jazz" << endl; return 5;}else{cout << "country" << endl; return 2;}}}else{cout << "classical" << endl; return 1;}}else{if(mu[135] <= -0.495325043797493){cout << "reggae" << endl; return 8;}else{cout << "hiphop" << endl; return 4;}}}else{if(sigma[371] <= -0.3598461002111435){cout << "country" << endl; return 2;}else{cout << "jazz" << endl; return 5;}}}}else{if(mu[450] <= 1.7498701214790344){cout << "classical" << endl; return 1;}else{cout << "reggae" << endl; return 8;}}}else{if(mu[506] <= -0.528955489397049){if(mu[442] <= -0.5162787437438965){cout << "jazz" << endl; return 5;}else{cout << "reggae" << endl; return 8;}}else{if(mu[455] <= -0.07752536702901125){if(mu[433] <= -0.42464034259319305){if(mu[199] <= -0.4901401996612549){cout << "blues" << endl; return 0;}else{cout << "country" << endl; return 2;}}else{cout << "blues" << endl; return 0;}}else{if(sigma[310] <= -0.450030654668808){cout << "rock" << endl; return 9;}else{cout << "jazz" << endl; return 5;}}}}}else{if(mu[511] <= 0.963645726442337){if(mu[453] <= 0.10357379540801048){if(mu[10] <= -0.3438164293766022){if(mu[2] <= -0.5037486553192139){if(mu[6] <= -0.8104710280895233){if(mu[485] <= -0.5725468397140503){cout << "metal" << endl; return 6;}else{cout << "jazz" << endl; return 5;}}else{if(mu[1] <= -0.4704500138759613){if(mu[395] <= -0.08879607543349266){if(mu[259] <= -0.31689946353435516){cout << "disco" << endl; return 3;}else{if(mu[37] <= 0.11203333362936974){if(mu[400] <= -0.48430851101875305){if(mu[69] <= -0.6494672894477844){cout << "rock" << endl; return 9;}else{cout << "country" << endl; return 2;}}else{cout << "rock" << endl; return 9;}}else{cout << "disco" << endl; return 3;}}}else{if(sigma[24] <= -0.446136012673378){cout << "blues" << endl; return 0;}else{cout << "metal" << endl; return 6;}}}else{if(mu[510] <= -0.5938737392425537){if(mu[458] <= -0.44829772412776947){if(mu[5] <= -0.3612216841429472){cout << "pop" << endl; return 7;}else{cout << "rock" << endl; return 9;}}else{cout << "metal" << endl; return 6;}}else{if(mu[20] <= -0.5929518640041351){if(sigma[355] <= -0.4785981625318527){cout << "pop" << endl; return 7;}else{if(sigma[103] <= -0.4533841609954834){cout << "country" << endl; return 2;}else{cout << "hiphop" << endl; return 4;}}}else{if(mu[122] <= 0.487200066447258){cout << "disco" << endl; return 3;}else{cout << "country" << endl; return 2;}}}}}}else{if(mu[110] <= -0.41082701086997986){if(mu[116] <= -0.37885986268520355){if(mu[100] <= -0.3644006997346878){if(mu[351] <= -0.3199148178100586){if(mu[123] <= -0.3985372632741928){if(mu[256] <= -0.07161327078938484){if(mu[508] <= 0.8273708820343018){if(mu[10] <= -0.3516237735748291){cout << "reggae" << endl; return 8;}else{cout << "hiphop" << endl; return 4;}}else{cout << "hiphop" << endl; return 4;}}else{cout << "pop" << endl; return 7;}}else{cout << "disco" << endl; return 3;}}else{if(sigma[15] <= -0.4349781423807144){cout << "disco" << endl; return 3;}else{cout << "hiphop" << endl; return 4;}}}else{cout << "pop" << endl; return 7;}}else{if(mu[372] <= -0.3793649673461914){cout << "blues" << endl; return 0;}else{cout << "rock" << endl; return 9;}}}else{if(mu[201] <= -0.34822867810726166){if(mu[395] <= 0.06064397282898426){if(mu[400] <= -0.31252461671829224){if(sigma[315] <= -0.4440317004919052){cout << "rock" << endl; return 9;}else{if(sigma[35] <= -0.40855687856674194){cout << "country" << endl; return 2;}else{if(sigma[256] <= -0.36923177540302277){cout << "blues" << endl; return 0;}else{cout << "reggae" << endl; return 8;}}}}else{if(mu[459] <= -0.10153068229556084){cout << "hiphop" << endl; return 4;}else{if(mu[325] <= -0.370994433760643){if(sigma[396] <= -0.15534250065684319){cout << "disco" << endl; return 3;}else{cout << "hiphop" << endl; return 4;}}else{cout << "metal" << endl; return 6;}}}}else{cout << "blues" << endl; return 0;}}else{if(mu[144] <= -0.06684269430115819){if(mu[413] <= -0.4525803327560425){if(sigma[236] <= -0.19340610597282648){cout << "hiphop" << endl; return 4;}else{cout << "pop" << endl; return 7;}}else{cout << "disco" << endl; return 3;}}else{if(mu[304] <= -0.24826080352067947){if(mu[485] <= -0.35743604600429535){cout << "metal" << endl; return 6;}else{if(sigma[166] <= -0.3766482323408127){cout << "country" << endl; return 2;}else{cout << "hiphop" << endl; return 4;}}}else{cout << "reggae" << endl; return 8;}}}}}}else{if(mu[300] <= -0.34874387085437775){if(mu[363] <= -0.47000253200531006){if(mu[49] <= -0.4724207669496536){if(sigma[479] <= -0.48737476766109467){cout << "rock" << endl; return 9;}else{if(mu[216] <= -0.3716546595096588){cout << "hiphop" << endl; return 4;}else{cout << "blues" << endl; return 0;}}}else{if(mu[121] <= -0.4084959626197815){cout << "country" << endl; return 2;}else{if(sigma[3] <= -0.0761214941740036){cout << "classical" << endl; return 1;}else{cout << "rock" << endl; return 9;}}}}else{if(mu[256] <= -0.29439085721969604){if(mu[2] <= -0.437117263674736){if(mu[356] <= -0.44041748344898224){cout << "blues" << endl; return 0;}else{cout << "rock" << endl; return 9;}}else{cout << "disco" << endl; return 3;}}else{if(mu[315] <= -0.34946027398109436){if(mu[58] <= 0.0047051263973116875){if(mu[1] <= 0.354216780513525){cout << "blues" << endl; return 0;}else{cout << "metal" << endl; return 6;}}else{if(mu[361] <= -0.481375589966774){cout << "jazz" << endl; return 5;}else{if(mu[149] <= -0.38418957591056824){cout << "country" << endl; return 2;}else{cout << "metal" << endl; return 6;}}}}else{if(mu[107] <= -0.24375539273023605){cout << "country" << endl; return 2;}else{cout << "rock" << endl; return 9;}}}}}else{if(mu[498] <= 1.1965243220329285){if(mu[511] <= 0.03597377985715866){if(mu[481] <= 0.9065265953540802){if(mu[140] <= -0.12239641696214676){if(mu[85] <= -0.40016596019268036){if(mu[366] <= -0.41328516602516174){if(mu[509] <= -0.4283299744129181){if(mu[201] <= -0.34825441241264343){cout << "pop" << endl; return 7;}else{if(mu[217] <= -0.33513443171977997){cout << "blues" << endl; return 0;}else{if(mu[87] <= -0.6569782793521881){cout << "rock" << endl; return 9;}else{cout << "country" << endl; return 2;}}}}else{cout << "reggae" << endl; return 8;}}else{if(mu[45] <= -0.0023541804403066635){if(mu[482] <= -0.6740459203720093){cout << "hiphop" << endl; return 4;}else{cout << "rock" << endl; return 9;}}else{cout << "disco" << endl; return 3;}}}else{if(mu[106] <= -0.047201386420056224){if(mu[28] <= -0.4687228500843048){cout << "blues" << endl; return 0;}else{if(mu[502] <= 0.417186938226223){cout << "country" << endl; return 2;}else{cout << "reggae" << endl; return 8;}}}else{if(mu[220] <= -0.1566748647019267){cout << "metal" << endl; return 6;}else{if(mu[65] <= -0.4463757574558258){cout << "pop" << endl; return 7;}else{cout << "rock" << endl; return 9;}}}}}else{if(mu[119] <= -0.09967514127492905){cout << "disco" << endl; return 3;}else{if(sigma[181] <= -0.353495255112648){if(sigma[479] <= -0.39800210297107697){if(sigma[174] <= -0.4377731382846832){cout << "rock" << endl; return 9;}else{cout << "disco" << endl; return 3;}}else{cout << "reggae" << endl; return 8;}}else{cout << "hiphop" << endl; return 4;}}}}else{cout << "rock" << endl; return 9;}}else{if(mu[260] <= -0.2026168704032898){if(mu[65] <= -0.29907843470573425){cout << "jazz" << endl; return 5;}else{if(mu[414] <= 0.1935371235013008){if(mu[5] <= -0.1389076691120863){cout << "hiphop" << endl; return 4;}else{cout << "reggae" << endl; return 8;}}else{cout << "disco" << endl; return 3;}}}else{if(mu[43] <= -0.3396011143922806){if(sigma[77] <= 0.5778526365756989){cout << "rock" << endl; return 9;}else{cout << "hiphop" << endl; return 4;}}else{cout << "pop" << endl; return 7;}}}}else{if(mu[4] <= 0.04534380882978439){cout << "jazz" << endl; return 5;}else{if(sigma[481] <= 0.1146840937435627){if(sigma[337] <= -0.14571942389011383){cout << "rock" << endl; return 9;}else{cout << "classical" << endl; return 1;}}else{cout << "hiphop" << endl; return 4;}}}}}}else{if(mu[282] <= -0.3389829695224762){if(mu[468] <= 0.6936512887477875){cout << "metal" << endl; return 6;}else{cout << "rock" << endl; return 9;}}else{if(mu[107] <= 2.2373872995376587){if(mu[1] <= -0.29552483558654785){if(mu[90] <= -0.05178744625300169){if(mu[363] <= -0.27977532148361206){if(mu[184] <= -0.505304679274559){cout << "country" << endl; return 2;}else{if(sigma[483] <= -0.35639816522598267){cout << "metal" << endl; return 6;}else{if(mu[382] <= -0.466554656624794){cout << "classical" << endl; return 1;}else{if(mu[501] <= 0.2577011212706566){cout << "pop" << endl; return 7;}else{cout << "jazz" << endl; return 5;}}}}}else{cout << "disco" << endl; return 3;}}else{if(mu[314] <= -0.05769566632807255){if(mu[468] <= -0.07835531630553305){cout << "metal" << endl; return 6;}else{cout << "rock" << endl; return 9;}}else{if(mu[331] <= 0.4843042194843292){if(mu[118] <= 0.18052035570144653){cout << "reggae" << endl; return 8;}else{cout << "metal" << endl; return 6;}}else{cout << "disco" << endl; return 3;}}}}else{if(mu[274] <= -0.17874165624380112){if(mu[32] <= 1.026541829109192){if(mu[509] <= 0.004630813375115395){if(mu[10] <= 0.2847937047481537){if(mu[204] <= -0.18390448577702045){cout << "blues" << endl; return 0;}else{cout << "disco" << endl; return 3;}}else{cout << "country" << endl; return 2;}}else{if(mu[60] <= 0.32212933618575335){if(mu[418] <= -0.009552575647830963){cout << "disco" << endl; return 3;}else{cout << "country" << endl; return 2;}}else{if(mu[4] <= 0.3442034125328064){cout << "metal" << endl; return 6;}else{cout << "metal" << endl; return 6;}}}}else{if(mu[2] <= 0.07748203165829182){if(sigma[388] <= 1.2470078766345978){cout << "disco" << endl; return 3;}else{cout << "rock" << endl; return 9;}}else{cout << "blues" << endl; return 0;}}}else{if(mu[489] <= 0.10652561485767365){if(mu[432] <= 0.20897474884986877){if(sigma[27] <= -0.2374102845788002){cout << "country" << endl; return 2;}else{cout << "reggae" << endl; return 8;}}else{cout << "hiphop" << endl; return 4;}}else{if(mu[477] <= 0.37557828426361084){cout << "pop" << endl; return 7;}else{if(mu[119] <= 0.8201369941234589){if(mu[9] <= 0.1126990313641727){if(mu[510] <= 0.22260718047618866){cout << "reggae" << endl; return 8;}else{cout << "disco" << endl; return 3;}}else{cout << "country" << endl; return 2;}}else{cout << "rock" << endl; return 9;}}}}}}else{cout << "metal" << endl; return 6;}}}}else{if(mu[4] <= -0.17278381809592247){if(mu[185] <= -0.18504882603883743){if(mu[197] <= -0.3099731504917145){cout << "hiphop" << endl; return 4;}else{cout << "rock" << endl; return 9;}}else{cout << "reggae" << endl; return 8;}}else{if(mu[488] <= 0.7833849489688873){if(mu[41] <= -0.5550695061683655){cout << "reggae" << endl; return 8;}else{if(mu[259] <= 0.9950088560581207){cout << "hiphop" << endl; return 4;}else{cout << "pop" << endl; return 7;}}}else{if(mu[177] <= 0.7013648748397827){if(sigma[459] <= 0.8943100050091743){cout << "metal" << endl; return 6;}else{if(mu[477] <= 0.5876519531011581){cout << "reggae" << endl; return 8;}else{if(mu[493] <= 0.7299868762493134){cout << "hiphop" << endl; return 4;}else{if(mu[365] <= 1.3163210451602936){cout << "blues" << endl; return 0;}else{cout << "country" << endl; return 2;}}}}}else{cout << "pop" << endl; return 7;}}}}}}else{if(mu[10] <= 1.3279789686203003){if(mu[511] <= -0.14059442654252052){if(mu[453] <= -0.21554316580295563){cout << "pop" << endl; return 7;}else{cout << "disco" << endl; return 3;}}else{cout << "pop" << endl; return 7;}}else{cout << "hiphop" << endl; return 4;}}}}