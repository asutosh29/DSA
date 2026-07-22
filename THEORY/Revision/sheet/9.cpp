#include <iostream>
using namespace std;

void rotK(int *arr, int n, int k)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    delete[] temp; // Dont forget to deallocate memory!
}

void test_rotK()
{
    const int N = 5;
    int nums[N] = {1, 2, 3, 4, 5};
    rotK(nums, N, 2);
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

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

void test_reverse_string_array()
{
    const int N = 6;
    char *names[N] = {
        "ROOPESH",
        "ASHA",
        "AMAR",
        "MEERA",
        "SUSHMA",
        "KIRAN"};

    reverse_string_array(names, N);

    for (int i = 0; i < N; i++)
    {
        cout << names[i] << endl;
    }
}

int main()
{
    test_rotK();
    test_reverse_string_array();
    return 0;
}