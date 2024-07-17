#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N, C, P; cin >> N >> C >> P;
    vector<string> noun;
    vector<string> tverb;
    vector<string> itverb;
    vector<string> conj;
    rep(0, N)
    {
        string w, type; cin >> w >> type;
        if (type == "noun") noun.emplace_back(w);
        else if (type == "transitive-verb") tverb.emplace_back(w);
        else if (type == "intransitive-verb") itverb.emplace_back(w);
        else conj.emplace_back(w);
    }
    int maxs = P + min(P, int(conj.size())); // most sentences structurally possible with the given periods and conjunctions
    int maxw = 0, maxtr = 0, maxitr = 0, maxcomma = 0;
    for (int itr = 0; itr <= min(maxs, int(itverb.size())); ++itr)
    {
        int tr = min(int(tverb.size()), maxs - itr);
        bool valid = (noun.size() >= itr + 2 * tr);
        while(tr and !valid)
        {
            --tr;
            valid = (noun.size() >= itr + 2 * tr);
        }
        if (!valid) continue;

        int nouns = 2 * tr + itr;
        int conjs = min(int(conj.size()), (tr + itr)/2);
        int commas = tr ? min(int(noun.size()) - nouns, C) : 0;
        int words = nouns + conjs + commas + tr + itr;
        if (words > maxw)
        {
            maxw = words;
            maxtr = tr;
            maxitr = itr;
            maxcomma = commas;
        }
    }
    vector<string> sentences;
    while(maxitr--)
    {
        string s = noun.back(); noun.pop_back();
        s += " " + itverb.back(); itverb.pop_back();
        sentences.emplace_back(s);
    }
    if (maxcomma)
    {
        string s = noun.back(); noun.pop_back();
        s += " " + tverb.back() + " "; tverb.pop_back();
        s += noun.back(); noun.pop_back();
        while (maxcomma--)
        {
            s += ", " + noun.back(); 
            noun.pop_back();
        }
        sentences.emplace_back(s);
        --maxtr;
    }
    while(maxtr--)
    {
        string s = noun.back(); noun.pop_back();
        s += " " + tverb.back() + " "; tverb.pop_back();
        s += noun.back(); noun.pop_back();
        sentences.emplace_back(s);
    }

    string paragraph = "";
    while (sentences.size())
    {
        if (sentences.size() > 1 and conj.size())
        {
            paragraph += sentences.back(); sentences.pop_back();
            paragraph += " " + conj.back() + " "; conj.pop_back();
            paragraph += sentences.back() + ". "; sentences.pop_back();
            continue;
        }
        paragraph += sentences.back() + ". "; sentences.pop_back();
    }

    if (paragraph[paragraph.size() - 1] == ' ') paragraph.resize(paragraph.size() - 1);
    cout << maxw << '\n';
    cout << paragraph << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
