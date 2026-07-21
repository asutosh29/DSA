#include <bits/stdc++.h>
using namespace std;

void f(int i)
{
    if (i == 0)
    {
        return;
    }
    f(i - 1);
    cout << i << endl;
}

int main()
{
    f(2);
    return 0;
}
