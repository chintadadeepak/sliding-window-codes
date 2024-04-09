#include <bits/stdc++.h>
using namespace std;
int main()
{
    // call the function
}

// better solution
int fruitsIntoBaskets(vector<int> &arr)
{
    unordered_map<int, int> m;
    int l;
    int r;
    int res;
    l = r = res = 0;
    while (r < arr.size())
    {
        m[arr[r]]++;
        if (m.size() > 2)
        {
            while (m.size() > 2)
            {
                m[arr[l]]--;
                if (m[arr[l]] == 0)
                    m.erase(m.find(arr[l]));
                l++;
            }
        }
        else
            res = max(res, r - l + 1);
        r++;
    }
}

int fruitsIntoBaskets(vector<int> &arr)
{
    unordered_map<int, int> m;
    int l;
    int r;
    int res;
    l = r = res = 0;
    while (r < arr.size())
    {
        m[arr[r]]++;
        if (m.size() > 2)
        {
            m[arr[l]]--;
            if (m[arr[l]] == 0)
                m.erase(m.find(arr[l]));
            l++;
        }
        else
            res = max(res, r - l + 1);
        r++;
    }
}