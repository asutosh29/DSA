#include <iostream>
using namespace std;

void str_to_upper(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        if ('a' <= *ptr && *ptr <= 'z')
        {
            *ptr = char(*ptr + 'A' - 'a');
        }
        ptr++;
    }
}

void str_to_lower(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        if ('A' <= *ptr && *ptr <= 'Z')
        {
            *ptr = char(*ptr - 'A' + 'a');
        }
        ptr++;
    }
}

void test_str_to_lower()
{
    char name[] = "AbcDeEfGGhh";
    str_to_lower(name);
    cout << name << endl;
}

void invert(char* str){
    char *ptr = str;
    while (*ptr != '\0')
    {
        if ('A' <= *ptr && *ptr <= 'Z')
        {
            *ptr = char(*ptr - 'A' + 'a');
        }else if ('a' <= *ptr && *ptr <= 'z')
        {
            *ptr = char(*ptr + 'A' - 'a');
        }
        ptr++;
    }
}

void test_str_invert()
{
    char name[] = "AbcDeEfGGhh";
    invert(name);
    cout << name << endl;
}


int main()
{
    test_str_invert();
    return 0;
}