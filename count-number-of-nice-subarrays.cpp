#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int numSubarraysWithSum2(vector<int> &nums, int g)
    {
        if (g < 0)
            return 0;
        int l;
        int r;
        int cnt;
        int sum;
        l = r = cnt = sum = 0;
        while (r < nums.size())
        {
            sum += nums[r] % 2;
            while (sum > g)
                sum -= nums[l++] % 2;
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int g)
    {
        return numSubarraysWithSum2(nums, g) - numSubarraysWithSum2(nums, g - 1);
    }
};