#include <iostream>
using namespace std;

void reverse(char *str)
{
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    end--;
    char *front = str;
    while (front <= end)
    {
        char temp = *front;
        *front = *end;
        *end = temp;

        front++;
        end--;
    }
}
void test_reverse()
{
    char name[] = "Asutosh";
    reverse(name);
    cout << name << endl;
}

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
void test_is_palindrome()
{
    char name[] = "";
    cout << name << endl;
    cout << is_palindrome(name) << endl;
}


int main()
{

    test_is_palindrome();
    return 0;
}