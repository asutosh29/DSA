#include <iostream>
using namespace std;

int *insert(int *arr, int n, int *val)
{
    int *temp = new int[n + 1]; // allocated in heap so that it persists after stack pops
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < *val)
        {
            temp[i] = arr[i];
        }
        else
        {
            temp[i] = *val;
            break;
        }
    }
    for (int j = i; j < n; j++)
    {
        temp[j + 1] = arr[j];
    }
    if (i == n)
        temp[n] = *val; // val is largest, insert at end
    return temp;
}

int main()
{
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid size. Size must be non-negative." << endl;
        return 0;
    }

    int *arr = new int[n];
    if (n > 0)
    {
        cout << "Enter " << n << " sorted integers: ";
    }
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    int *ans = insert(arr, n, &val);

    cout << "Array after insertion: ";
    for (int i = 0; i < n + 1; i++)
        cout << ans[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] ans;
    return 0;
}