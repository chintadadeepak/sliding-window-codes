#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // naive solution
    int characterReplacement(string s, int k)
    {
        map<char, int> mpp;
        int mf;
        int ml;
        int ch;
        ml = mf = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int hash[26] = {0};
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j] - 'A']++;
                mf = max(mf, hash[s[j] - 'A']);
                ch = (j - i + 1) - mf;
                if (ch <= k)
                    ml = max(ml, j - i + 1);
                else
                    break;
            }
        }
    }
    // better solution
    int characterReplacement(string s, int k)
    {
        int hash[26] = {0};
        int l;
        int r;
        int mf;
        int ml;
        int ch;
        l = r = ml = mf = 0;
        while (r < s.size())
        {
            hash[s[r] - 'A']++;
            mf = max(mf, hash[s[r]]);
            ch = (r - l + 1) - mf;
            if (ch > k)
            {
                while (ch > k)
                {
                    hash[s[l]]--;
                    l++;
                    mf = 0;
                    for (int i = 0; i < 26; i++)
                        mf = max(mf, hash[i]);
                    ch = (r - l + 1) - mf;
                }
            }
            else
                ml = max(ml, r - l + 1);
            r++;
        }
    }

    // optimal solution
    int characterReplacement(string s, int k)
    {
        int hash[26] = {0};
        int l;
        int r;
        int mf;
        int ml;
        int ch;
        l = r = ml = mf = 0;
        while (r < s.size())
        {
            hash[s[r] - 'A']++;
            mf = max(mf, hash[s[r] - 'A']);
            ch = (r - l + 1) - mf;
            if (ch > k)
            {
                hash[s[l] - 'A']--;
                l++;
                mf = 0;
                for (int i = 0; i < 26; i++)
                    mf = max(mf, hash[i]);
            }
            else
                ml = max(ml, r - l + 1);
            r++;
        }
        return ml;
    }
};