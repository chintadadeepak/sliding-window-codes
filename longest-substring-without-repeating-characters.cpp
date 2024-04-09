#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int l;
        int r;
        int res;
        l = res = 0;
        for (r = 0; r < s.size(); r++)
        {
            if (m.find(s[r]) == m.end())
            {
                m.insert({s[r], r});
                res = max(res, r - l + 1);
            }
            else
            {
                if (m.find(s[r])->second >= l)
                {
                    l = m[s[r]] + 1;
                    m[s[r]] = r;
                    res = max(res, r - l + 1);
                }
                else
                {
                    m[s[r]] = r;
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};

int main()
{
    // call the lengthOfLongestSubstring function
}