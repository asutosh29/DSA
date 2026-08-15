#include <iostream>
using namespace std;

void reverse_string_array(char **arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int n;
    cout << "Enter number of names: ";
    cin >> n;
    cin.ignore();

    char names[n][100];
    char *ptrs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name " << (i + 1) << ": ";
        cin.getline(names[i], 100);
        ptrs[i] = names[i];
    }

    reverse_string_array(ptrs, n);

    cout << "Reversed order:" << endl;
    for (int i = 0; i < n; i++)
        cout << ptrs[i] << endl;

    return 0;
}