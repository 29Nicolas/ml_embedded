#include <iostream>
#include "code.h"
using namespace std;

int decision_tree(double mu[], double sigma[])
{
    if (mu[322] <= -0.5210878551006317)
    {
        if (mu[90] <= -0.6441756784915924)
        {
            if (mu[510] <= -0.7368937432765961)
            {
                cout << "classical" << endl;
                return 1;
            }
            else
            {
                if (mu[347] <= -0.6746048331260681)
                {
                    cout << "jazz" << endl;
                    return 5;
                }
                else
                {
                    cout << "classical" << endl;
                    return 1;
                }
            }
        }
        else
        {
            if (mu[342] <= -0.6545003056526184)
            {
                cout << "jazz" << endl;
                return 5;
            }
            else
            {
                if (mu[334] <= -0.5731102526187897)
                {
                    cout << "classical" << endl;
                    return 1;
                }
                else
                {
                    cout << "country" << endl;
                    return 2;
                }
            }
        }
    }
    else
    {
        if (mu[249] <= 1.1204942464828491)
        {
            if (mu[172] <= -0.5976554751396179)
            {
                if (mu[511] <= -0.5201341509819031)
                {
                    if (mu[1] <= -0.547496110200882)
                    {
                        if (mu[330] <= -0.580091655254364)
                        {
                            if (mu[319] <= -0.5334554612636566)
                            {
                                cout << "country" << endl;
                                return 2;
                            }
                            else
                            {
                                cout << "classical" << endl;
                                return 1;
                            }
                        }
                        else
                        {
                            if (sigma[117] <= -0.5755567848682404)
                            {
                                if (sigma[27] <= -0.5927715003490448)
                                {
                                    cout << "reggae" << endl;
                                    return 8;
                                }
                                else
                                {
                                    if (mu[117] <= -0.7476710677146912)
                                    {
                                        cout << "disco" << endl;
                                        return 3;
                                    }
                                    else
                                    {
                                        cout << "pop" << endl;
                                        return 7;
                                    }
                                }
                            }
                            else
                            {
                                cout << "jazz" << endl;
                                return 5;
                            }
                        }
                    }
                    else
                    {
                        if (mu[472] <= -0.3176537752151489)
                        {
                            if (mu[443] <= -0.7579235732555389)
                            {
                                cout << "blues" << endl;
                                return 0;
                            }
                            else
                            {
                                if (mu[503] <= 2.0439550280570984)
                                {
                                    if (mu[471] <= -0.638742595911026)
                                    {
                                        if (sigma[359] <= -0.5867664813995361)
                                        {
                                            cout << "blues" << endl;
                                            return 0;
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[2] <= -0.5677746832370758)
                                        {
                                            cout << "jazz" << endl;
                                            return 5;
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "country" << endl;
                                    return 2;
                                }
                            }
                        }
                        else
                        {
                            if (mu[2] <= -0.6687181293964386)
                            {
                                if (mu[145] <= -0.6796928644180298)
                                {
                                    cout << "blues" << endl;
                                    return 0;
                                }
                                else
                                {
                                    cout << "classical" << endl;
                                    return 1;
                                }
                            }
                            else
                            {
                                cout << "country" << endl;
                                return 2;
                            }
                        }
                    }
                }
                else
                {
                    if (mu[457] <= -0.29684022814035416)
                    {
                        if (mu[78] <= -0.458002969622612)
                        {
                            if (mu[426] <= -0.6810301244258881)
                            {
                                if (mu[32] <= -0.7265020608901978)
                                {
                                    if (mu[100] <= -0.5737751424312592)
                                    {
                                        cout << "blues" << endl;
                                        return 0;
                                    }
                                    else
                                    {
                                        if (sigma[80] <= -0.57456374168396)
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                        else
                                        {
                                            cout << "hiphop" << endl;
                                            return 4;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "jazz" << endl;
                                    return 5;
                                }
                            }
                            else
                            {
                                if (mu[61] <= -0.4550965130329132)
                                {
                                    cout << "country" << endl;
                                    return 2;
                                }
                                else
                                {
                                    cout << "jazz" << endl;
                                    return 5;
                                }
                            }
                        }
                        else
                        {
                            if (mu[371] <= -0.6005106568336487)
                            {
                                cout << "blues" << endl;
                                return 0;
                            }
                            else
                            {
                                cout << "rock" << endl;
                                return 9;
                            }
                        }
                    }
                    else
                    {
                        cout << "reggae" << endl;
                        return 8;
                    }
                }
            }
            else
            {
                if (mu[400] <= -0.30047035217285156)
                {
                    if (mu[504] <= -0.5437167286872864)
                    {
                        if (mu[2] <= -0.4331110566854477)
                        {
                            if (mu[6] <= -0.8374696969985962)
                            {
                                if (mu[27] <= -0.6591576337814331)
                                {
                                    if (sigma[500] <= -0.5854504406452179)
                                    {
                                        cout << "metal" << endl;
                                        return 6;
                                    }
                                    else
                                    {
                                        cout << "reggae" << endl;
                                        return 8;
                                    }
                                }
                                else
                                {
                                    if (sigma[179] <= -0.5724382102489471)
                                    {
                                        cout << "jazz" << endl;
                                        return 5;
                                    }
                                    else
                                    {
                                        if (mu[162] <= -0.5811616480350494)
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (mu[440] <= 0.019997820258140564)
                                {
                                    if (mu[64] <= -0.5635931491851807)
                                    {
                                        if (mu[469] <= -0.5335496962070465)
                                        {
                                            if (mu[457] <= -0.6284691393375397)
                                            {
                                                if (mu[330] <= -0.5749068856239319)
                                                {
                                                    cout << "blues" << endl;
                                                    return 0;
                                                }
                                                else
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                            }
                                            else
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[100] <= -0.5620029866695404)
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
                                            }
                                            else
                                            {
                                                if (mu[10] <= -0.22320179268717766)
                                                {
                                                    if (mu[109] <= -0.5616543889045715)
                                                    {
                                                        if (mu[167] <= -0.5223361551761627)
                                                        {
                                                            cout << "jazz" << endl;
                                                            return 5;
                                                        }
                                                        else
                                                        {
                                                            cout << "reggae" << endl;
                                                            return 8;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (mu[204] <= -0.45866450667381287)
                                                        {
                                                            cout << "disco" << endl;
                                                            return 3;
                                                        }
                                                        else
                                                        {
                                                            if (mu[464] <= -0.5265732109546661)
                                                            {
                                                                cout << "rock" << endl;
                                                                return 9;
                                                            }
                                                            else
                                                            {
                                                                if (mu[318] <= -0.4584082067012787)
                                                                {
                                                                    cout << "pop" << endl;
                                                                    return 7;
                                                                }
                                                                else
                                                                {
                                                                    cout << "classical" << endl;
                                                                    return 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "rock" << endl;
                                        return 9;
                                    }
                                }
                                else
                                {
                                    cout << "metal" << endl;
                                    return 6;
                                }
                            }
                        }
                        else
                        {
                            if (mu[4] <= -0.051686713472008705)
                            {
                                if (mu[489] <= -0.18646401911973953)
                                {
                                    if (mu[460] <= -0.12015843018889427)
                                    {
                                        if (mu[436] <= -0.22736426442861557)
                                        {
                                            if (mu[477] <= -0.7331333756446838)
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
                                            }
                                            else
                                            {
                                                if (mu[505] <= -0.3369360566139221)
                                                {
                                                    cout << "reggae" << endl;
                                                    return 8;
                                                }
                                                else
                                                {
                                                    cout << "blues" << endl;
                                                    return 0;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "rock" << endl;
                                            return 9;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[282] <= -0.25080356746912)
                                        {
                                            cout << "hiphop" << endl;
                                            return 4;
                                        }
                                        else
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                    }
                                }
                                else
                                {
                                    if (sigma[243] <= -0.3381178304553032)
                                    {
                                        cout << "rock" << endl;
                                        return 9;
                                    }
                                    else
                                    {
                                        cout << "blues" << endl;
                                        return 0;
                                    }
                                }
                            }
                            else
                            {
                                if (sigma[266] <= -0.32615210115909576)
                                {
                                    cout << "rock" << endl;
                                    return 9;
                                }
                                else
                                {
                                    cout << "hiphop" << endl;
                                    return 4;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (mu[140] <= -0.6207813620567322)
                        {
                            if (mu[358] <= -0.6659921705722809)
                            {
                                if (sigma[87] <= -0.4480513334274292)
                                {
                                    cout << "jazz" << endl;
                                    return 5;
                                }
                                else
                                {
                                    cout << "blues" << endl;
                                    return 0;
                                }
                            }
                            else
                            {
                                if (mu[2] <= -0.37578466534614563)
                                {
                                    if (mu[37] <= -0.6054643094539642)
                                    {
                                        cout << "rock" << endl;
                                        return 9;
                                    }
                                    else
                                    {
                                        if (mu[218] <= -0.30025114119052887)
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                        else
                                        {
                                            cout << "classical" << endl;
                                            return 1;
                                        }
                                    }
                                }
                                else
                                {
                                    if (sigma[334] <= -0.4818856120109558)
                                    {
                                        cout << "jazz" << endl;
                                        return 5;
                                    }
                                    else
                                    {
                                        if (mu[451] <= -0.6167458891868591)
                                        {
                                            cout << "pop" << endl;
                                            return 7;
                                        }
                                        else
                                        {
                                            if (sigma[315] <= -0.31303147971630096)
                                            {
                                                cout << "reggae" << endl;
                                                return 8;
                                            }
                                            else
                                            {
                                                cout << "classical" << endl;
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (mu[302] <= -0.3995783030986786)
                            {
                                if (mu[6] <= -0.3901153802871704)
                                {
                                    if (mu[59] <= -0.5423299968242645)
                                    {
                                        cout << "disco" << endl;
                                        return 3;
                                    }
                                    else
                                    {
                                        if (mu[493] <= 0.23025714606046677)
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[511] <= -0.15864180773496628)
                                    {
                                        if (sigma[37] <= -0.5084041357040405)
                                        {
                                            if (mu[90] <= -0.4611075669527054)
                                            {
                                                if (sigma[502] <= -0.5182493627071381)
                                                {
                                                    if (sigma[500] <= -0.54143887758255)
                                                    {
                                                        cout << "blues" << endl;
                                                        return 0;
                                                    }
                                                    else
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                            }
                                            else
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[145] <= -0.5442270636558533)
                                            {
                                                if (mu[357] <= -0.5308717787265778)
                                                {
                                                    cout << "blues" << endl;
                                                    return 0;
                                                }
                                                else
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                            }
                                            else
                                            {
                                                cout << "blues" << endl;
                                                return 0;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "country" << endl;
                                        return 2;
                                    }
                                }
                            }
                            else
                            {
                                if (mu[74] <= -0.22386982291936874)
                                {
                                    if (mu[297] <= -0.2920257896184921)
                                    {
                                        if (mu[508] <= 0.7574595808982849)
                                        {
                                            if (mu[436] <= -0.5704027414321899)
                                            {
                                                if (mu[47] <= -0.619675874710083)
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                                else
                                                {
                                                    if (mu[20] <= -0.2616584536153823)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
                                                    }
                                                    else
                                                    {
                                                        cout << "pop" << endl;
                                                        return 7;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (mu[483] <= -0.07303837034851313)
                                                {
                                                    if (mu[372] <= -0.5875760316848755)
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                    else
                                                    {
                                                        cout << "reggae" << endl;
                                                        return 8;
                                                    }
                                                }
                                                else
                                                {
                                                    if (sigma[495] <= -0.33086497336626053)
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                    else
                                                    {
                                                        if (sigma[472] <= 0.24333525449037552)
                                                        {
                                                            cout << "country" << endl;
                                                            return 2;
                                                        }
                                                        else
                                                        {
                                                            cout << "jazz" << endl;
                                                            return 5;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (mu[345] <= -0.43598395586013794)
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                            else
                                            {
                                                cout << "blues" << endl;
                                                return 0;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mu[510] <= -0.26114024221897125)
                                        {
                                            if (mu[302] <= 0.09127521142363548)
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                            else
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[92] <= -0.45852814614772797)
                                            {
                                                if (sigma[377] <= 1.8655541129410267)
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
                                                }
                                                else
                                                {
                                                    cout << "hiphop" << endl;
                                                    return 4;
                                                }
                                            }
                                            else
                                            {
                                                cout << "pop" << endl;
                                                return 7;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[9] <= -0.1014580950140953)
                                    {
                                        if (mu[343] <= -0.4074520766735077)
                                        {
                                            if (mu[439] <= 0.047337789088487625)
                                            {
                                                if (sigma[281] <= -0.1641020681709051)
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                                else
                                                {
                                                    cout << "classical" << endl;
                                                    return 1;
                                                }
                                            }
                                            else
                                            {
                                                cout << "jazz" << endl;
                                                return 5;
                                            }
                                        }
                                        else
                                        {
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[359] <= -0.48464667797088623)
                                        {
                                            if (sigma[501] <= 0.4477177858352661)
                                            {
                                                cout << "classical" << endl;
                                                return 1;
                                            }
                                            else
                                            {
                                                cout << "pop" << endl;
                                                return 7;
                                            }
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (mu[282] <= -0.16973131150007248)
                    {
                        if (mu[419] <= 0.039351530373096466)
                        {
                            if (mu[10] <= -0.4930334985256195)
                            {
                                if (mu[1] <= -0.35503217577934265)
                                {
                                    if (mu[18] <= -0.46473999321460724)
                                    {
                                        if (mu[50] <= -0.23266678303480148)
                                        {
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                        else
                                        {
                                            if (mu[15] <= -0.6363315284252167)
                                            {
                                                cout << "blues" << endl;
                                                return 0;
                                            }
                                            else
                                            {
                                                if (mu[342] <= -0.44119951128959656)
                                                {
                                                    cout << "jazz" << endl;
                                                    return 5;
                                                }
                                                else
                                                {
                                                    if (mu[343] <= -0.3021590858697891)
                                                    {
                                                        cout << "rock" << endl;
                                                        return 9;
                                                    }
                                                    else
                                                    {
                                                        cout << "hiphop" << endl;
                                                        return 4;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "metal" << endl;
                                        return 6;
                                    }
                                }
                                else
                                {
                                    if (mu[79] <= 0.2771493270993233)
                                    {
                                        cout << "hiphop" << endl;
                                        return 4;
                                    }
                                    else
                                    {
                                        cout << "disco" << endl;
                                        return 3;
                                    }
                                }
                            }
                            else
                            {
                                if (mu[397] <= 0.1943921521306038)
                                {
                                    if (mu[147] <= -0.057308465242385864)
                                    {
                                        if (mu[334] <= -0.3581930994987488)
                                        {
                                            if (mu[451] <= -0.19981822464615107)
                                            {
                                                cout << "blues" << endl;
                                                return 0;
                                            }
                                            else
                                            {
                                                if (mu[197] <= -0.37114445865154266)
                                                {
                                                    cout << "metal" << endl;
                                                    return 6;
                                                }
                                                else
                                                {
                                                    if (mu[31] <= 0.6201483905315399)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
                                                    }
                                                    else
                                                    {
                                                        cout << "classical" << endl;
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (mu[373] <= -0.02371101826429367)
                                            {
                                                if (mu[499] <= -0.3885456621646881)
                                                {
                                                    cout << "hiphop" << endl;
                                                    return 4;
                                                }
                                                else
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                            }
                                            else
                                            {
                                                if (mu[505] <= 0.3376450687646866)
                                                {
                                                    cout << "hiphop" << endl;
                                                    return 4;
                                                }
                                                else
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mu[21] <= -0.4102226048707962)
                                        {
                                            if (sigma[61] <= -0.4932866394519806)
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                            else
                                            {
                                                cout << "reggae" << endl;
                                                return 8;
                                            }
                                        }
                                        else
                                        {
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[374] <= 1.7256497144699097)
                                    {
                                        cout << "blues" << endl;
                                        return 0;
                                    }
                                    else
                                    {
                                        if (mu[507] <= -0.35986781120300293)
                                        {
                                            cout << "rock" << endl;
                                            return 9;
                                        }
                                        else
                                        {
                                            cout << "jazz" << endl;
                                            return 5;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (mu[457] <= 1.80611252784729)
                            {
                                if (mu[70] <= -0.08956431224942207)
                                {
                                    if (mu[15] <= -0.5586020946502686)
                                    {
                                        cout << "disco" << endl;
                                        return 3;
                                    }
                                    else
                                    {
                                        if (mu[120] <= 0.3656788319349289)
                                        {
                                            if (mu[472] <= 0.08074615150690079)
                                            {
                                                if (mu[352] <= -0.3563954830169678)
                                                {
                                                    if (mu[352] <= -0.4948161840438843)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                    else
                                                    {
                                                        if (mu[71] <= -0.008265740354545414)
                                                        {
                                                            cout << "reggae" << endl;
                                                            return 8;
                                                        }
                                                        else
                                                        {
                                                            cout << "hiphop" << endl;
                                                            return 4;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                            }
                                            else
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                        }
                                        else
                                        {
                                            cout << "blues" << endl;
                                            return 0;
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[27] <= 0.7674630582332611)
                                    {
                                        if (mu[327] <= -0.31260083615779877)
                                        {
                                            if (mu[330] <= -0.3607795983552933)
                                            {
                                                if (mu[118] <= -0.1924566775560379)
                                                {
                                                    if (mu[473] <= -0.10025802999734879)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
                                                    }
                                                    else
                                                    {
                                                        if (mu[282] <= -0.38215920329093933)
                                                        {
                                                            cout << "rock" << endl;
                                                            return 9;
                                                        }
                                                        else
                                                        {
                                                            cout << "jazz" << endl;
                                                            return 5;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    if (sigma[230] <= -0.016177218407392502)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                    else
                                                    {
                                                        cout << "reggae" << endl;
                                                        return 8;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (mu[391] <= -0.24377745389938354)
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
                                                }
                                                else
                                                {
                                                    cout << "blues" << endl;
                                                    return 0;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (mu[0] <= 1.4729216694831848)
                                            {
                                                if (mu[503] <= 0.6006848216056824)
                                                {
                                                    if (mu[478] <= 2.1008272767066956)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                    else
                                                    {
                                                        cout << "reggae" << endl;
                                                        return 8;
                                                    }
                                                }
                                                else
                                                {
                                                    if (mu[466] <= 0.48732711374759674)
                                                    {
                                                        cout << "hiphop" << endl;
                                                        return 4;
                                                    }
                                                    else
                                                    {
                                                        if (sigma[431] <= 0.5166963898955146)
                                                        {
                                                            cout << "country" << endl;
                                                            return 2;
                                                        }
                                                        else
                                                        {
                                                            cout << "metal" << endl;
                                                            return 6;
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mu[115] <= 0.06424870155751705)
                                        {
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                        else
                                        {
                                            cout << "rock" << endl;
                                            return 9;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (sigma[146] <= -0.04122581519186497)
                                {
                                    cout << "rock" << endl;
                                    return 9;
                                }
                                else
                                {
                                    cout << "blues" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (mu[510] <= 1.4748734831809998)
                        {
                            if (mu[27] <= -0.1646524742245674)
                            {
                                if (mu[6] <= -0.48900502920150757)
                                {
                                    if (mu[155] <= 0.1950078010559082)
                                    {
                                        if (mu[202] <= -0.03609311580657959)
                                        {
                                            cout << "jazz" << endl;
                                            return 5;
                                        }
                                        else
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                    }
                                    else
                                    {
                                        cout << "reggae" << endl;
                                        return 8;
                                    }
                                }
                                else
                                {
                                    if (mu[471] <= -0.17448488622903824)
                                    {
                                        cout << "hiphop" << endl;
                                        return 4;
                                    }
                                    else
                                    {
                                        if (mu[430] <= -0.07958317920565605)
                                        {
                                            cout << "pop" << endl;
                                            return 7;
                                        }
                                        else
                                        {
                                            if (mu[458] <= 0.07289259880781174)
                                            {
                                                cout << "reggae" << endl;
                                                return 8;
                                            }
                                            else
                                            {
                                                if (mu[176] <= -0.02303455024957657)
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                                else
                                                {
                                                    if (sigma[114] <= 0.6728111505508423)
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                    else
                                                    {
                                                        cout << "hiphop" << endl;
                                                        return 4;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (mu[25] <= 1.6887719631195068)
                                {
                                    if (mu[502] <= -0.06414162181317806)
                                    {
                                        if (mu[420] <= -0.35587118566036224)
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                        else
                                        {
                                            if (mu[223] <= -0.10970192030072212)
                                            {
                                                cout << "pop" << endl;
                                                return 7;
                                            }
                                            else
                                            {
                                                if (mu[491] <= -0.37415026128292084)
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                                else
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mu[187] <= 0.4631947875022888)
                                        {
                                            if (mu[255] <= -0.14208738505840302)
                                            {
                                                if (mu[480] <= 1.0299428403377533)
                                                {
                                                    cout << "jazz" << endl;
                                                    return 5;
                                                }
                                                else
                                                {
                                                    if (mu[27] <= 1.0385128855705261)
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                    else
                                                    {
                                                        cout << "rock" << endl;
                                                        return 9;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (mu[418] <= -0.09863021643832326)
                                                {
                                                    if (sigma[218] <= -0.4186647981405258)
                                                    {
                                                        cout << "rock" << endl;
                                                        return 9;
                                                    }
                                                    else
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "pop" << endl;
                                                    return 7;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (mu[23] <= 0.5791544020175934)
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
                                            }
                                            else
                                            {
                                                if (sigma[59] <= 0.7220176160335541)
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                                else
                                                {
                                                    if (sigma[508] <= 1.344748079776764)
                                                    {
                                                        cout << "reggae" << endl;
                                                        return 8;
                                                    }
                                                    else
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[5] <= 0.07307816483080387)
                                    {
                                        cout << "rock" << endl;
                                        return 9;
                                    }
                                    else
                                    {
                                        cout << "pop" << endl;
                                        return 7;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (mu[149] <= 1.41850346326828)
                            {
                                if (mu[326] <= 2.44575297832489)
                                {
                                    cout << "hiphop" << endl;
                                    return 4;
                                }
                                else
                                {
                                    if (sigma[60] <= 3.560734987258911)
                                    {
                                        cout << "pop" << endl;
                                        return 7;
                                    }
                                    else
                                    {
                                        cout << "disco" << endl;
                                        return 3;
                                    }
                                }
                            }
                            else
                            {
                                if (mu[500] <= 0.6003097295761108)
                                {
                                    if (mu[69] <= 0.7527229487895966)
                                    {
                                        cout << "hiphop" << endl;
                                        return 4;
                                    }
                                    else
                                    {
                                        if (sigma[117] <= 2.416041374206543)
                                        {
                                            cout << "pop" << endl;
                                            return 7;
                                        }
                                        else
                                        {
                                            cout << "metal" << endl;
                                            return 6;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "country" << endl;
                                    return 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (mu[511] <= -0.21003194898366928)
            {
                cout << "disco" << endl;
                return 3;
            }
            else
            {
                if (mu[97] <= -0.40821926295757294)
                {
                    cout << "reggae" << endl;
                    return 8;
                }
                else
                {
                    if (mu[11] <= 2.7226229906082153)
                    {
                        if (mu[204] <= 6.6107800006866455)
                        {
                            cout << "pop" << endl;
                            return 7;
                        }
                        else
                        {
                            cout << "hiphop" << endl;
                            return 4;
                        }
                    }
                    else
                    {
                        cout << "hiphop" << endl;
                        return 4;
                    }
                }
            }
        }
    }
}