#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsequenceVec(const vector<int> &v)
{
    vector<int> empty;
    vector<vector<int>> ans{empty};
    for (auto x : v)
    {
        vector<vector<int>> buffer;
        int n = ans.size();
        for (int i=  0; i< n;i++) // avoided auto x:v when adding stuff into vector
        {
            auto temp = ans[i];
            temp.push_back(x);
            ans.push_back(temp);
        }
    }

    return ans;
}

vector<vector<int>> subsequenceRec(const vector<int> &v, int idx)
{
    if (idx < 0)
    {
        vector<int> temp;
        vector<vector<int>> ans{temp};
        return ans;
    }
    auto curr = v[idx];
    auto nottake = subsequenceRec(v, idx-1);

    auto take = nottake;
    for (auto &v : take)
    {
        v.push_back(curr);
    }

    vector<vector<int>> ans;
    ans.reserve(take.size() + nottake.size());
    for (auto v : take)
    {
        ans.push_back(v);
    }

    for (auto v : nottake)
    {
        ans.push_back(v);
    }

    return ans;
}

vector<vector<int>> subsequenceRecParam(vector<int> &ds, const vector<int> &v, int idx, int n){
    if(idx == n){
        // for(const auto& x: ds){
        //     cout << x << " ";
        // }
        // cout<<'\n';
        vector<vector<int>> ans{ds};
        return ans;
    }

    ds.push_back(v[idx]);
    auto take = subsequenceRecParam(ds, v, idx+1, n);
    ds.pop_back();
    auto nottake = subsequenceRecParam(ds,v,idx+1, n);

    vector<vector<int>> ans;
    ans.reserve(take.size() + nottake.size());

    for(const auto &sub: take){
        ans.push_back(sub);
    }
    for(const auto &sub: nottake){
        ans.push_back(sub);
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};
    // reverse(v.begin(),v.end());
    // auto ans = subsequenceRec(v, v.size()-1);
    vector<int> ds;
    auto ans = subsequenceRecParam(ds,v,0,v.size());
    for (auto arr : ans)
    {
        if(!arr.size()){
            cout << "[]" << endl;
            continue;
        }

        for (auto x : arr)
        {

            cout << x << " ";
        }
        cout << '\n';
    }
    

    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << '\n';
}