#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static int maxScore(vector<int> &nums, int k)
    {
        int left;
        int right;
        int ls;
        int rs;
        int res;
        left = k - 1;
        right = nums.size() - 1;
        ls = rs = res = 0;
        while (left >= 0)
            ls += nums[left--];
        if (k == nums.size())
            return ls;
        res = max(res, ls + rs);
        left = k - 1;
        while (left >= 0)
        {
            ls -= nums[left--];
            rs += nums[right--];
            res = max(res, ls + rs);
        }
        return res;
    }
};
int main()
{
    // call the maxScore()
}