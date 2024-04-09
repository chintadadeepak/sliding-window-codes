#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    int l;
    int r;
    int res;
    unordered_map<char, int> m;
    l = r = res = 0;
    while (r < str.size())
    {
        m[str[r]]++;
        if (m.size() > k)
        {
            m[str[l]]--;
            if (m[str[l]] == 0)
                m.erase(str[l]);
            l++;
        }
        else
        {
            res = max(res, r - l + 1);
        }
        r++;
    }
    return res;
}