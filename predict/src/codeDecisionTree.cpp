#include <iostream>
#include "codeDecisionTree.h"
using namespace std;

int decision_tree(double mu[], double sigma[])
{
    if (mu[321] <= -0.5226435661315918)
    {
        if (mu[497] <= -0.4203045517206192)
        {
            if (mu[504] <= -0.21952306479215622)
            {
                cout << "classical" << endl;
                return 1;
            }
            else
            {
                if (mu[39] <= -0.6087585687637329)
                {
                    cout << "classical" << endl;
                    return 1;
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
            cout << "jazz" << endl;
            return 5;
        }
    }
    else
    {
        if (mu[249] <= 1.035169780254364)
        {
            if (mu[323] <= -0.4955050051212311)
            {
                if (mu[80] <= -0.4306039363145828)
                {
                    if (mu[47] <= -0.34426701068878174)
                    {
                        if (mu[483] <= -0.46866239607334137)
                        {
                            if (mu[4] <= -0.7408444881439209)
                            {
                                if (mu[2] <= -0.7003301084041595)
                                {
                                    if (mu[99] <= -0.5802597999572754)
                                    {
                                        cout << "classical" << endl;
                                        return 1;
                                    }
                                    else
                                    {
                                        if (mu[85] <= -0.7274550795555115)
                                        {
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                        else
                                        {
                                            if (mu[105] <= -0.5056978613138199)
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                            else
                                            {
                                                if (sigma[141] <= -0.5197038948535919)
                                                {
                                                    cout << "reggae" << endl;
                                                    return 8;
                                                }
                                                else
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[441] <= -0.6064468920230865)
                                    {
                                        if (sigma[84] <= -0.5197607576847076)
                                        {
                                            cout << "pop" << endl;
                                            return 7;
                                        }
                                        else
                                        {
                                            cout << "jazz" << endl;
                                            return 5;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[484] <= -0.542649894952774)
                                        {
                                            cout << "hiphop" << endl;
                                            return 4;
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
                                if (mu[3] <= -0.6199044585227966)
                                {
                                    if (mu[463] <= -0.3546062707901001)
                                    {
                                        cout << "country" << endl;
                                        return 2;
                                    }
                                    else
                                    {
                                        if (mu[466] <= -0.5287961810827255)
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
                                }
                                else
                                {
                                    if (mu[419] <= -0.6589592397212982)
                                    {
                                        cout << "blues" << endl;
                                        return 0;
                                    }
                                    else
                                    {
                                        if (sigma[45] <= -0.4925125241279602)
                                        {
                                            cout << "reggae" << endl;
                                            return 8;
                                        }
                                        else
                                        {
                                            if (sigma[484] <= -0.47647352516651154)
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
                        }
                        else
                        {
                            if (mu[11] <= 0.24396225810050964)
                            {
                                if (mu[360] <= -0.5814903378486633)
                                {
                                    if (mu[0] <= -0.7192158401012421)
                                    {
                                        cout << "classical" << endl;
                                        return 1;
                                    }
                                    else
                                    {
                                        if (mu[137] <= -0.6310198903083801)
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                        else
                                        {
                                            if (mu[431] <= -0.48222239315509796)
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
                                }
                                else
                                {
                                    if (sigma[15] <= -0.46311168372631073)
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
                                if (sigma[69] <= -0.3596296012401581)
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
                    else
                    {
                        if (mu[476] <= 0.36261944472789764)
                        {
                            cout << "classical" << endl;
                            return 1;
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
                    if (mu[506] <= -0.528955489397049)
                    {
                        if (mu[71] <= -0.4212164729833603)
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
                        if (mu[57] <= -0.07752536539919674)
                        {
                            if (mu[433] <= -0.42464034259319305)
                            {
                                if (sigma[106] <= -0.4851837456226349)
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
                                cout << "blues" << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            if (mu[505] <= -0.41536766290664673)
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
                if (mu[511] <= 0.963645726442337)
                {
                    if (mu[59] <= 0.10357377678155899)
                    {
                        if (mu[502] <= -0.34381645917892456)
                        {
                            if (mu[510] <= -0.5037486851215363)
                            {
                                if (mu[6] <= -0.8104710280895233)
                                {
                                    if (mu[31] <= -0.6755794584751129)
                                    {
                                        cout << "metal" << endl;
                                        return 6;
                                    }
                                    else
                                    {
                                        cout << "jazz" << endl;
                                        return 5;
                                    }
                                }
                                else
                                {
                                    if (mu[511] <= -0.4704499840736389)
                                    {
                                        if (mu[395] <= -0.08879607543349266)
                                        {
                                            if (mu[240] <= -0.34140799939632416)
                                            {
                                                cout << "disco" << endl;
                                                return 3;
                                            }
                                            else
                                            {
                                                if (mu[49] <= -0.008180524921044707)
                                                {
                                                    if (mu[399] <= -0.5193310678005219)
                                                    {
                                                        if (mu[196] <= -0.3993556946516037)
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
                                                        cout << "rock" << endl;
                                                        return 9;
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
                                            if (sigma[77] <= -0.44757385551929474)
                                            {
                                                cout << "blues" << endl;
                                                return 0;
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
                                        if (mu[510] <= -0.5938737392425537)
                                        {
                                            if (mu[436] <= -0.44121892750263214)
                                            {
                                                if (sigma[499] <= -0.5034196674823761)
                                                {
                                                    cout << "pop" << endl;
                                                    return 7;
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
                                        else
                                        {
                                            if (mu[20] <= -0.5929518640041351)
                                            {
                                                if (sigma[21] <= -0.4766245037317276)
                                                {
                                                    cout << "pop" << endl;
                                                    return 7;
                                                }
                                                else
                                                {
                                                    if (mu[296] <= -0.3102523684501648)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
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
                                                if (mu[0] <= -0.5936086773872375)
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                                else
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (mu[110] <= -0.41082701086997986)
                                {
                                    if (mu[116] <= -0.37885986268520355)
                                    {
                                        if (mu[503] <= -0.12976536061614752)
                                        {
                                            if (mu[350] <= -0.3431248068809509)
                                            {
                                                if (mu[87] <= -0.7211149036884308)
                                                {
                                                    cout << "pop" << endl;
                                                    return 7;
                                                }
                                                else
                                                {
                                                    if (mu[389] <= -0.3985373377799988)
                                                    {
                                                        if (mu[508] <= 0.8273708820343018)
                                                        {
                                                            if (mu[502] <= -0.3516238033771515)
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
                                                        else
                                                        {
                                                            cout << "hiphop" << endl;
                                                            return 4;
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
                                                if (mu[352] <= -0.22341304272413254)
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
                                            cout << "pop" << endl;
                                            return 7;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[98] <= -0.47951725125312805)
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
                                    if (mu[201] <= -0.34822867810726166)
                                    {
                                        if (mu[395] <= 0.06064397282898426)
                                        {
                                            if (mu[400] <= -0.31252461671829224)
                                            {
                                                if (sigma[100] <= -0.44408421218395233)
                                                {
                                                    cout << "rock" << endl;
                                                    return 9;
                                                }
                                                else
                                                {
                                                    if (sigma[101] <= -0.4076484590768814)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
                                                    }
                                                    else
                                                    {
                                                        if (sigma[36] <= -0.37066856026649475)
                                                        {
                                                            cout << "blues" << endl;
                                                            return 0;
                                                        }
                                                        else
                                                        {
                                                            cout << "reggae" << endl;
                                                            return 8;
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (mu[459] <= -0.10153068229556084)
                                                {
                                                    cout << "hiphop" << endl;
                                                    return 4;
                                                }
                                                else
                                                {
                                                    if (mu[190] <= -0.3858538866043091)
                                                    {
                                                        if (sigma[108] <= -0.15523285418748856)
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
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "blues" << endl;
                                            return 0;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[144] <= -0.06684269430115819)
                                        {
                                            if (mu[443] <= -0.572272002696991)
                                            {
                                                if (mu[322] <= 0.11743099940940738)
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
                                                cout << "disco" << endl;
                                                return 3;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[218] <= -0.27939772605895996)
                                            {
                                                if (mu[248] <= -0.2824373245239258)
                                                {
                                                    cout << "metal" << endl;
                                                    return 6;
                                                }
                                                else
                                                {
                                                    if (mu[224] <= -0.2543591111898422)
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
                                            else
                                            {
                                                cout << "reggae" << endl;
                                                return 8;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (mu[300] <= -0.34874387085437775)
                            {
                                if (mu[363] <= -0.47000253200531006)
                                {
                                    if (mu[463] <= -0.4724207818508148)
                                    {
                                        if (sigma[464] <= -0.4875612109899521)
                                        {
                                            cout << "rock" << endl;
                                            return 9;
                                        }
                                        else
                                        {
                                            if (sigma[97] <= -0.3454539179801941)
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
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
                                        if (mu[383] <= -0.4283272922039032)
                                        {
                                            cout << "country" << endl;
                                            return 2;
                                        }
                                        else
                                        {
                                            if (sigma[107] <= -0.0947989895939827)
                                            {
                                                cout << "classical" << endl;
                                                return 1;
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
                                    if (mu[249] <= -0.3075125217437744)
                                    {
                                        if (mu[2] <= -0.437117263674736)
                                        {
                                            if (mu[157] <= -0.45560042560100555)
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
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[315] <= -0.34946027398109436)
                                        {
                                            if (mu[454] <= 0.004705101659055799)
                                            {
                                                if (mu[510] <= 0.5632778108119965)
                                                {
                                                    cout << "blues" << endl;
                                                    return 0;
                                                }
                                                else
                                                {
                                                    cout << "metal" << endl;
                                                    return 6;
                                                }
                                            }
                                            else
                                            {
                                                if (mu[146] <= -0.3105352967977524)
                                                {
                                                    if (mu[51] <= -0.016791701316833496)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                    else
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
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
                                            if (sigma[57] <= -0.19201236963272095)
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                            else
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (mu[14] <= 1.196524441242218)
                                {
                                    if (mu[1] <= 0.03597371280193329)
                                    {
                                        if (mu[481] <= 0.9065265953540802)
                                        {
                                            if (mu[140] <= -0.12239641696214676)
                                            {
                                                if (mu[85] <= -0.40016596019268036)
                                                {
                                                    if (mu[146] <= -0.41328516602516174)
                                                    {
                                                        if (mu[3] <= -0.4283299744129181)
                                                        {
                                                            if (sigma[9] <= -0.47528526186943054)
                                                            {
                                                                cout << "pop" << endl;
                                                                return 7;
                                                            }
                                                            else
                                                            {
                                                                if (mu[155] <= -0.49362504482269287)
                                                                {
                                                                    cout << "rock" << endl;
                                                                    return 9;
                                                                }
                                                                else
                                                                {
                                                                    if (sigma[280] <= -0.4690753221511841)
                                                                    {
                                                                        cout << "country" << endl;
                                                                        return 2;
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
                                                            cout << "reggae" << endl;
                                                            return 8;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (mu[394] <= -0.5252724289894104)
                                                        {
                                                            cout << "disco" << endl;
                                                            return 3;
                                                        }
                                                        else
                                                        {
                                                            if (mu[288] <= 0.002582285553216934)
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
                                                    if (mu[106] <= -0.047201386420056224)
                                                    {
                                                        if (sigma[266] <= 0.11324525624513626)
                                                        {
                                                            if (mu[3] <= -0.7407214641571045)
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
                                                        else
                                                        {
                                                            cout << "blues" << endl;
                                                            return 0;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (sigma[56] <= -0.39756886661052704)
                                                        {
                                                            cout << "metal" << endl;
                                                            return 6;
                                                        }
                                                        else
                                                        {
                                                            if (sigma[247] <= -0.09686384350061417)
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
                                            }
                                            else
                                            {
                                                if (mu[119] <= -0.09967514127492905)
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
                                                }
                                                else
                                                {
                                                    if (sigma[179] <= -0.35361771285533905)
                                                    {
                                                        if (mu[510] <= -0.3975885212421417)
                                                        {
                                                            if (mu[479] <= -0.27122917026281357)
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
                                                            cout << "reggae" << endl;
                                                            return 8;
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
                                        else
                                        {
                                            cout << "rock" << endl;
                                            return 9;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[284] <= -0.18716858327388763)
                                        {
                                            if (mu[463] <= 0.04337424039840698)
                                            {
                                                if (mu[109] <= 0.1073644757270813)
                                                {
                                                    if (mu[98] <= 0.12943676486611366)
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
                                                else
                                                {
                                                    cout << "disco" << endl;
                                                    return 3;
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
                                            if (mu[488] <= -0.437685489654541)
                                            {
                                                if (sigma[428] <= 0.5767650753259659)
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
                                    if (mu[508] <= 0.04534374177455902)
                                    {
                                        cout << "jazz" << endl;
                                        return 5;
                                    }
                                    else
                                    {
                                        if (sigma[474] <= 0.11389702931046486)
                                        {
                                            if (mu[189] <= -0.3570745587348938)
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
                                            cout << "hiphop" << endl;
                                            return 4;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (mu[284] <= -0.34338854253292084)
                        {
                            if (mu[199] <= -0.4525359869003296)
                            {
                                cout << "rock" << endl;
                                return 9;
                            }
                            else
                            {
                                cout << "metal" << endl;
                                return 6;
                            }
                        }
                        else
                        {
                            if (mu[107] <= 2.2373872995376587)
                            {
                                if (mu[1] <= -0.29552483558654785)
                                {
                                    if (mu[422] <= -0.0517874751240015)
                                    {
                                        if (mu[348] <= -0.22406728565692902)
                                        {
                                            if (mu[150] <= -0.567047506570816)
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                            else
                                            {
                                                if (mu[73] <= -0.035848867148160934)
                                                {
                                                    cout << "pop" << endl;
                                                    return 7;
                                                }
                                                else
                                                {
                                                    if (sigma[58] <= -0.3573586940765381)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
                                                    }
                                                    else
                                                    {
                                                        if (mu[237] <= -0.21671414375305176)
                                                        {
                                                            cout << "classical" << endl;
                                                            return 1;
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
                                            cout << "disco" << endl;
                                            return 3;
                                        }
                                    }
                                    else
                                    {
                                        if (mu[198] <= -0.0576956681907177)
                                        {
                                            if (mu[5] <= 1.9087910056114197)
                                            {
                                                cout << "rock" << endl;
                                                return 9;
                                            }
                                            else
                                            {
                                                cout << "metal" << endl;
                                                return 6;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[28] <= 0.024635018780827522)
                                            {
                                                if (mu[233] <= -0.1042620912194252)
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
                                                cout << "disco" << endl;
                                                return 3;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (mu[238] <= -0.17874164134263992)
                                    {
                                        if (mu[32] <= 1.026541829109192)
                                        {
                                            if (mu[509] <= 0.004630813375115395)
                                            {
                                                if (mu[4] <= -0.027259450405836105)
                                                {
                                                    if (sigma[114] <= -0.003895757719874382)
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
                                                if (mu[47] <= -0.1950783208012581)
                                                {
                                                    if (mu[276] <= -0.3339427560567856)
                                                    {
                                                        cout << "country" << endl;
                                                        return 2;
                                                    }
                                                    else
                                                    {
                                                        cout << "disco" << endl;
                                                        return 3;
                                                    }
                                                }
                                                else
                                                {
                                                    if (mu[486] <= 0.703839123249054)
                                                    {
                                                        cout << "metal" << endl;
                                                        return 6;
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
                                            if (mu[510] <= 0.07748201861977577)
                                            {
                                                if (mu[339] <= -0.15996961295604706)
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
                                                cout << "blues" << endl;
                                                return 0;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (mu[489] <= 0.10652561485767365)
                                        {
                                            if (mu[400] <= -0.01871519722044468)
                                            {
                                                if (sigma[4] <= -0.22608045488595963)
                                                {
                                                    cout << "country" << endl;
                                                    return 2;
                                                }
                                                else
                                                {
                                                    cout << "reggae" << endl;
                                                    return 8;
                                                }
                                            }
                                            else
                                            {
                                                cout << "hiphop" << endl;
                                                return 4;
                                            }
                                        }
                                        else
                                        {
                                            if (mu[477] <= 0.37557828426361084)
                                            {
                                                cout << "pop" << endl;
                                                return 7;
                                            }
                                            else
                                            {
                                                if (mu[115] <= 0.4619387835264206)
                                                {
                                                    if (mu[100] <= 0.00750906765460968)
                                                    {
                                                        if (sigma[409] <= 0.25685232505202293)
                                                        {
                                                            cout << "reggae" << endl;
                                                            return 8;
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
                    }
                }
                else
                {
                    if (mu[508] <= -0.17278386652469635)
                    {
                        if (mu[321] <= -0.2705841213464737)
                        {
                            if (sigma[486] <= -0.046824559569358826)
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
                        else
                        {
                            cout << "reggae" << endl;
                            return 8;
                        }
                    }
                    else
                    {
                        if (mu[24] <= 0.7833849191665649)
                        {
                            if (mu[62] <= -0.4494442641735077)
                            {
                                cout << "reggae" << endl;
                                return 8;
                            }
                            else
                            {
                                if (mu[253] <= 0.9950088858604431)
                                {
                                    cout << "hiphop" << endl;
                                    return 4;
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
                            if (mu[178] <= 0.79708032310009)
                            {
                                if (mu[264] <= -0.27231428027153015)
                                {
                                    cout << "blues" << endl;
                                    return 0;
                                }
                                else
                                {
                                    if (mu[169] <= 0.36799950897693634)
                                    {
                                        cout << "hiphop" << endl;
                                        return 4;
                                    }
                                    else
                                    {
                                        if (mu[310] <= 0.2282494120299816)
                                        {
                                            cout << "metal" << endl;
                                            return 6;
                                        }
                                        else
                                        {
                                            if (sigma[239] <= 3.4445122480392456)
                                            {
                                                cout << "country" << endl;
                                                return 2;
                                            }
                                            else
                                            {
                                                cout << "reggae" << endl;
                                                return 8;
                                            }
                                        }
                                    }
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
            }
        }
        else
        {
            if (mu[10] <= 1.3279789686203003)
            {
                if (mu[511] <= -0.14059442654252052)
                {
                    if (mu[504] <= -0.33376161754131317)
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
                else
                {
                    cout << "pop" << endl;
                    return 7;
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