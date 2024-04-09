#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Better Solution
    int longestOnes(vector<int> &nums, int k)
    {
        int l;
        int r;
        int z;
        int len;
        l = r = z = 0;
        len = INT_MIN;
        while (r < nums.size())
        {
            if (nums[r] == 0)
                z++;
            if (z <= k)
                len = max(len, r - l + 1);
            else
            {
                while (z > k && l <= r)
                {
                    if (nums[l] == 0)
                        z--;
                    l++;
                    if (z <= k)
                        len = max(len, r - l + 1);
                }
            }
            r++;
        }
        return len;
    }
    // optimal solution
    int longestOnes(vector<int> &nums, int k)
    {
        int l;
        int r;
        int z;
        int len;
        l = r = z = 0;
        len = INT_MIN;
        while (r < nums.size())
        {
            if (nums[r] == 0)
                z++;
            if (z > k)
            {
                if (nums[l] == 0)
                    z--;
                l++;
            }
            if (z <= k)
                len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};

int main()
{
    // call longestOnes()
}