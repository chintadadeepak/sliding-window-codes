#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> hash(3, -1);
        int result = 0;
        int ans;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
            if ((hash[0] >= 0) && (hash[1] >= 0) && (hash[2] >= 0))
                result += min(hash[0], min(hash[1], hash[2])) + 1;
        }
        return result;
    }
};

int main()
{
    // call the function
}