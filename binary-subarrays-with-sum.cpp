#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
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
            sum += nums[r];
            while (sum > g)
                sum -= nums[l++];
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return numSubarraysWithSum2(nums, goal) - numSubarraysWithSum2(nums, goal - 1);
    }
};

int main()
{
    // call the function
}