#include<bits/stdc++.h>
using namespace std;

int sum(int i){
    if(i==0) return 0; // return 0 since sum of 0 numbers is 0, trivially
    return i + sum(i-1);
}

int fact(int n){
    if(n==0) return 1; //return 1 since 0! is 1; !! Mistake can be to ommit 0!=1;
    return n*fact(n-1);
}

int main(){
    cout << sum(10) << endl;
    cout << fact(5) << endl;
    return 0;
}