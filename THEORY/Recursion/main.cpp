#include<bits/stdc++.h>
using namespace std;

void f(int i){
    cout << "[" << i << "]"<<"start: " << __LINE__ << endl;
    if(i==3) return;
    cout << i << endl;
    cout << "[" << i << "]"<<"before: " << __LINE__ << endl;
    f(i+1);
    cout << "[" << i << "]"<<"after: " << __LINE__ << endl;
    cout << i << endl;
    cout << "[" << i << "]"<<"returning: " << __LINE__ << endl;
}

int main()
{
    f(0);
    return 0;
}