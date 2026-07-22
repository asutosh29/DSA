#include <iostream>
using namespace std;

void test()
{
    const int N = 10;
    int *nums = (int *)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int *nums2 = (int *)calloc(N, sizeof(float));
    for (int i = 0; i < N; i++)
    {
        cout << nums2[i] << " ";
        nums2[i] = i;
    }
    cout << endl;

    int *nums3 = (int *)realloc(nums2, (N + 5) * sizeof(float));
    for (int i = 0; i < N + 5; i++)
    {
        cout << nums3[i] << " ";
    }
    cout << endl;

    int *nums4 = (int *)realloc(nums2, (N - 5) * sizeof(float));
    for (int i = 0; i < N - 5; i++)
    {
        cout << nums4[i] << " ";
    }
    cout << endl;

    free(nums4);
    free(nums3);
    free(nums2);
    free(nums);
}

int main()
{
    test();
    return 0;
}