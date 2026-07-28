#include <iostream>
#include <cstring>
using namespace std;

struct House
{
    char address[50];
    int rooms;
    float asking_price;
};

union AgentCode
{
    char ch_code;
    int int_code;
    float dec_code;
    char string_code[6];
};

void p1()
{
    House village[10];
    cout << "sizeof village: " << sizeof(village) << " sizeof house: " << sizeof(House) << endl;

    AgentCode code;
    cout << "sizeof code: " << sizeof(code) << endl;
}

struct Details
{
    char author[30];
    int pages;
    float price;
};

struct Book
{
    char title[30]; // char*
    Details details;
};

Book create_book(char *title, char *author, int pages, float price)
{
    Book b{};

    strncpy(b.details.author, author, sizeof(b.details.author)-1);
    strncpy(b.title, title, sizeof(b.title)-1);
    b.details.pages = pages;
    b.details.price = price;
    return b;
}

void print_book(const Book &b)
{
    cout << b.details.author << " authors " << b.title << endl;

}

void p2()
{
    Book b = create_book("amx rulzzz", "amx", 67, 67.67);
    print_book(b);
}

int main()
{
    // p1();
    p2();
    return 0;
}