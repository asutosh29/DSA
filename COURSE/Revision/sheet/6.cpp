#include <iostream>
using namespace std;

void invert(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        if ('A' <= *ptr && *ptr <= 'Z')
        {
            *ptr = char(*ptr - 'A' + 'a');
        }
        else if ('a' <= *ptr && *ptr <= 'z')
        {
            *ptr = char(*ptr + 'A' - 'a');
        }
        ptr++;
    }
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

        invert(str);
        cout << "Inverted case: " << str << endl;
    }

    return 0;
}