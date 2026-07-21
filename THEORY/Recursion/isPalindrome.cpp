#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(vector<int> &v, int start, int end){
    if(v[start] != v[end]) return false;
    if(start >= end) return true;
    return (true)&(isPalindrom(v,start+1, end-1)); // true & is just for illustrative purpose
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }   
    cout << isPalindrom(v,0,n-1) << endl;
    return 0;
}