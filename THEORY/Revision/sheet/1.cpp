#include <iostream>
using namespace std;

int *insert(int *arr, int n, int val)
{
    int* temp = new int[n+1]; // allocated in heap so that it persists after stack pops
    int i= 0;
    for (i = 0; i < n; i++)
    {
        if(arr[i] < val){
            temp[i] = arr[i];
        }else{
            temp[i] = val;
            break;
        }
    }
    for (int j = i; j < n; j++)
    {
        temp[j+1] = arr[j];
    }
    return temp;
}

int main()
{
    const int N = 5;
    int arr[N] = {1, 2, 3, 4, 5};
    auto ans = insert(arr, N, 3);
    for (int i = 0; i < N+1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // size has to be increase.
    return 0;
}