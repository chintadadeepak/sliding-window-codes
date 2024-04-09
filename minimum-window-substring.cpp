#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute solution
    string minWindow(string s, string t)
    {
        int cnt;
        unordered_map<char, int> mpp, temp;
        vector<pair<int, int>> answers;
        for (char ch : t)
            mpp[ch]++;
        for (int i = 0; i < s.size(); i++)
        {
            temp = mpp;
            cnt = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (temp.find(s[j]) == temp.end())
                    temp.insert({s[j], -1});
                else if (temp[s[j]] <= 0)
                    temp[s[j]]--;
                else
                {
                    cnt++;
                    temp[s[j]]--;
                    if (cnt == t.size())
                    {
                        answers.push_back({i, j});
                        break;
                    }
                }
            }
        }
        int len = INT_MAX;
        int left;
        int right;
        for (pair<int, int> p : answers)
        {
            if (p.second - p.first < len)
            {
                left = p.first;
                right = p.second;
            }
        }
        string result = "";
        for (int i = left; i <= right; i++)
            result += s[i];
        return result;
    }
    string minWindow(string s, string t)
    {
        int cnt;
        unordered_map<char, int> mpp;
        for (char ch : t)
            mpp[ch]++;
        int l;
        int r;
        int len;
        int startInd;
        l = r = cnt = 0;
        startInd = -1;
        len = INT_MAX;
        while (r < s.size())
        {
            if (mpp.find(s[r]) == mpp.end())
                mpp.insert({s[r], -1});
            else if (mpp[s[r]] > 0)
            {
                cnt++;
                mpp[s[r]]--;
            }
            else
                mpp[s[r]]--;
            while (cnt == t.size())
            {
                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    cnt--;
                if ((r - l + 1) < len)
                {
                    len = (r - l + 1);
                    startInd = l;
                }
                l++;
            }
            r++;
        }
        if (startInd == -1)
            return "";
        string result = "";
        for (int i = startInd; i < startInd + len; i++)
            result.push_back(s[i]);
        return result;
    }
};

int main()
{
    // call the function
}