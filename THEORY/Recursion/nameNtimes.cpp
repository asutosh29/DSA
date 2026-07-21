#include<bits/stdc++.h>
using namespace std;

void printName(int i, string name){
    if(i == 0) return;
    cout << name << endl;
    printName(i - 1, name);
}

int main()
{
    printName(5, "Alice");
    return 0;
}
