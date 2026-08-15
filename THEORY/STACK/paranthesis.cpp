#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    for (const auto &br : s)
    {
        if (br == '(' || br == '{' || br == '[')
        {
            stk.push(br);
        }
        else
        {
            if(stk.empty()) return false;

            char top = stk.top();
            stk.top();
            // Check for the Negation of Unions and return early!
            if(br == ')' && top != '(') return false;
            if(br == ']' && top != '[') return false;
            if(br == '}' && top != '{') return false;
        }
    }

    return stk.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << '\n';
}