#include <iostream>
using namespace std;

int lcs_dp(string text1, string text2)
{
    // we call lcs, and take the substr(v1, v2) of texts as the coordinate of the 2D matrix.
    // minimum coordinates: (0, 0)
    // maximum coordinates: (m, n)
    // size: horizontal = 0 to m = m + 1
    // vertical = 0 to n = n + 1

    int **memo = new int *[text1.size() + 1];

    for (int i = 0; i < text1.size() + 1; i++)
        memo[i] = new int[text2.size() + 1];

    for (int i = 0; i < text1.size() + 1; i++)
        memo[i][0] = 0;

    for (int j = 0; j < text2.size() + 1; j++)
        memo[0][j] = 0;

    for (int i = 1; i < text1.size() + 1; i++)
    {
        for (int j = 1; j < text2.size() + 1; j++)
        {
            // 4 possible cases for memo[i][j]
            // as i, j represents substr(j) and substr(j).
            // The requirement of substr() is dependent on text1[0] and text2[0] of the previous cell
            // so write the action accordingly

            // 1. Both text1[0] and text2[0] are the same, then
            if (text1[i - 1] == text2[j - 1])
                memo[i][j] = 1 + memo[i - 1][j - 1];

            // 2. and 3. Something from text1[0] or text2[0] or both are absent.
            else
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            // If both are absent. Then value of
            // memo[i-1][j-1] will be equal to memo[i-1][j] and memo[i][j-1]. If these is are 0. Which they are.
            // Remember that this happens only if text1[0]!=text2[0]. And it is accessible in that section only.
        }
    }

    int ret = memo[text1.size()][text2.size()];
    //deallocate memory
    for (int i = 0; i < text1.size() + 1; i++)
        delete[] memo[i];
    delete[] memo;

    return ret;
    // T.C = O(3*m*n) - 3 dependencies
    // S.C = O(m*n)
}

int lcs_memo_h(int **memo, string text1, string text2)
{
    int i = text1.size();
    int j = text2.size();

    if (memo[i][j] == -1)
    {
        if (text1[0] != text2[0])
            memo[i][j] = max(lcs_memo_h(memo, text1, text2.substr(1)), lcs_memo_h(memo, text1.substr(1), text2));
        else
            memo[i][j] = 1 + lcs_memo_h(memo, text1.substr(1), text2.substr(1));
    }
    // already stored
    return memo[i][j];
}

int lcs_memo(string text1, string text2)
{
    // we call lcs, and take the size of text as the coordinate of the 2D matrix.
    // minimum coordinates: (0, 0)
    // maximum coordinates: (m, n)
    // horizontal = 0 to m = m + 1
    // vertical = 0 to n = n + 1
    // storage size = unique calls = number of points = (m+1)*(n+1)

    int **memo = new int *[text1.size() + 1];

    for (int i = 0; i < text1.size() + 1; i++)
    {
        memo[i] = new int[text2.size() + 1];
        for (int j = 0; j < text2.size() + 1; j++)
            memo[i][j] = -1;
    }

    for (int i = 0; i < text1.size() + 1; i++)
        memo[i][0] = 0;

    for (int j = 0; j < text2.size() + 1; j++)
        memo[0][j] = 0;

    // T.C = O(3*m*n) - 3 dependencies
    // S.C = O(k*m*n) - k is system dependant constant, for each AR.

    return lcs_memo_h(memo, text1, text2);
}

int lcs_bf(string text1, string text2)
{
    // As we are working on strings. Let us do the first one by recursiona nd the rest of the string by recursion

    // Base case, written after writing the 4 possible cases
    if (text1.size() == 0 || text2.size() == 0)
        return 0;

    // 4 cases are possible.

    // 1. the t1[0] and t2[0] are the same, then we have atleast the 1 as the answer. Plus the lcs of the remaining strings. Makes sense.
    if (text1[0] == text2[0])
        return 1 + lcs_bf(text1.substr(1), text2.substr(1));

    // t1[0] and t2[0] are different.

    // 2. t1[0] is not a part of the lcs.
    // 3. t2[0] is not part of the lcs.
    // We can't say about the other arr[0]. i.e we don't assume arr[0] is present for the non-substred array.
    return max(lcs_bf(text1, text2.substr(1)), lcs_bf(text1.substr(1), text2));

    // 4. Both t1[0] and t2[0] are not a part of the lcs.
    // return lcs(text1.substr(1), text2.substr(1))
    // A closer look, during a dry run reveals that 4. actually comes up during 2 and 3.
    // So it is unnecessary. i.e if it were the case that both t1[0] and t2[0] were absent, then case 4 would be taken care of.
    // Or else it's not needed, i.e we have either of them included. "Longest" goal is achieved.

    // T.C = O(2^n) - 3 calls at each function, but we make only 2.
    // S.C = O(n) - height of the tree.
}

int main()
{
    string x = "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny";
    string y = "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan";

    cout << lcs_dp(x, y);
    cout << endl;
    return 0;
}
