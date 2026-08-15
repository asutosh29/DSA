#include <iostream>
using namespace std;

void rotK(int *arr, int n, int k)
{
    k = ((k % n) + n) % n;
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    delete[] temp;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while (t--)
    {
        int k;
        cout << "Enter rotation amount k: ";
        cin >> k;

        rotK(arr, n, k);

        cout << "Rotated array: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    delete[] arr;
    return 0;
}