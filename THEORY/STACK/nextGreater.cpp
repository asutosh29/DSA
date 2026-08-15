#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums)
{
    stack<int> stk;
    vector<int> hsh(1e4 + 1, 0);
    vector<int> ans(nums1.size(), -1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && nums[i] >= stk.top())
        {
            stk.pop();
        }
        if (stk.empty())
        {
            hsh[nums[i]] = -1;
            stk.push(nums[i]);
            continue;
        }

        hsh[nums[i]] = stk.top();
        stk.push(nums[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        ans[i] = hsh[nums1[i]];
    }

    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1);
    vector<int> nums2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }
    auto ans = nextGreaterElement(nums1, nums2);
    for (const auto &a : ans)
    {
        cout << a << " ";
    }
    cout << '\n';
    return 0;
}