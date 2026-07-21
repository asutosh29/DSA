#include<bits/stdc++.h>
using namespace std;

void revArr(vector<int> &v, int start, int end){
    if(start>end) return;
    swap(v[start], v[end]);
    revArr(v,start+1,end-1);
}

vector<int> revFun(vector<int> &v, int start, int end){
    if(start > end) return v;
    swap(v[start],v[end]);
    return revFun(v,start+1,end-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    revArr(v,0,n-1);
    for(auto x: v){
        cout << x << " ";;
    }
    cout << '\n';
    auto reversed = revFun(v,0,n-1);
    for(auto x: reversed){
        cout << x << " ";;
    }
    cout << '\n';
    return 0;
}