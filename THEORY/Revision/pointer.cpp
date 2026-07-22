#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void p1()
{
    float x = 6.5f;
    float y = 0;
    float *fpx = nullptr;
    float *fpy = nullptr;

    fpx = &x;
    fpy = &y;
    cout << "x: " << x << " address fpx: " << fpx << endl;
    cout << "y: " << y << " address fpy: " << fpy << endl;

    // Modifying value in place
    *fpx = 6.7f;
    cout << "x: " << x << " address fpx: " << fpx << endl;
    *fpx += 1.5f;
    cout << "x: " << x << " address fpx: " << fpx << endl;

    y = *fpx;
    fpy = fpx;
    cout << "y: " << y << " address fpy: " << fpy << endl;
}

void p2()
{
    const int N = 3;
    const int M = 4;
    int matrix[N][M]; // int **matrix

    int k = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = k;
            k++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << "\n";
    }

    // Using row
    int *rows[N];
    for (int i = 0; i < N; i++)
    {
        rows[i] = matrix[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << *(*(rows + i) + j) << " ";
        }
        cout << "\n";
    }
}

void p3()
{
    char str[] = "UNIVERSITY";

    // print the string
    char *ch = str;
    while (*ch != '\0')
    {
        cout << *ch;
        ch++;
    }
    cout << endl;

    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
    cout << endl;

    i = 0;
    while (str[i] != '\0')
    {
        cout << *(str + i);
        i++;
    }
    cout << endl;

    i = 0;
    while (str[i] != '\0')
    {
        cout << i[str]; // Crazy!!!!
        i++;
    }
    cout << endl;

    // Buffer
    char name[20] = "amx";
    cout << "sizeof name: " << sizeof(name) << " || length: " << strlen(name) << endl;
    string name_cpp = "amxasdoihfsoihadfoishfoidshofihdsafgserhgpehorisgpohieroghserhpo";
    cout << "sizeof name: " << sizeof(name_cpp) << " || length: " << name_cpp.size() << endl;
}

void p4()
{
    const int LIST_SIZE = 7;
    const char *list[LIST_SIZE] = {
        "ROOPESH", "ASHA", "AMAR",
        "MEERA", "SUSHMA", "KIRAN", "SANJAY"};

    for (int i = 0; i < LIST_SIZE; i++)
    {
        cout << list[i] << endl;
    }

    if (list[0][0] > list[1][0])
    {
        const char *temp;
        temp = list[0];
        list[0] = list[1];
        list[1] = temp;
    }

    for (int i = 0; i < LIST_SIZE; i++)
    {
        cout << list[i] << endl;
    }
}

void display_row(const int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

int find_max(const int *p, int size)
{
    int mx = INT64_MIN;
    for (int i = 0; i < size; i++)
    {
        mx = max(mx, *(p + i));
    }
    return mx;
}

void p5()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 0, 2},
        {5, 3, 6}};

    for (int i = 0; i < 3; i++)
    {
        display_row(matrix[i], 3);
        cout << "max in row " << i+1 << " is: " << find_max(matrix[i], 3) << "\n";
    }
}

int main()
{
    // p1();
    // p2();
    // p3();
    // p4();
    p5();
    return 0;
}