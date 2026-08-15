#include <iostream>
using namespace std;

bool is_palindrome(char *str)
{
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    end--;
    char *front = str;
    bool isPal = true;
    while (front <= end)
    {
        if (*front != *end)
        {
            isPal = false;
            break;
        }
        front++;
        end--;
    }
    return isPal;
}

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--)
    {
        char str[100];
        cout << "Enter a string: ";
        cin.getline(str, 100);

        if (is_palindrome(str))
        {
            cout << str << " is a palindrome." << endl;
        }
        else
        {
            cout << str << " is not a palindrome." << endl;
        }
    }
    return 0;
}