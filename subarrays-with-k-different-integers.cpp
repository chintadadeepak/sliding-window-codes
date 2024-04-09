#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int subarraysWithKDistinct2(vector<int> &nums, int k)
    {
        int l;
        int r;
        int cnt;
        unordered_map<int, int> m;
        l = r = cnt = 0;
        while (r < nums.size())
        {
            m[nums[r]]++;
            while (m.size() > k)
            {
                m[nums[l]]--;
                if (m[nums[l]] == 0)
                    m.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return subarraysWithKDistinct2(nums, k) - subarraysWithKDistinct2(nums, k - 1);
    }
};