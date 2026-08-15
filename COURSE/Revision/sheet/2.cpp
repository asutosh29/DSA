#include <iostream>
using namespace std;

void test()
{
    int N;
    cout << "Enter size N: ";
    cin >> N;

    cout << "--- malloc ---" << endl;
    int *nums = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "--- calloc ---" << endl;
    int *nums2 = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
    {
        cout << nums2[i] << " ";
        nums2[i] = i;
    }
    cout << endl;

    int growBy;
    cout << "Enter amount to expand by: ";
    cin >> growBy;

    cout << "--- realloc (grow by " << growBy << ") ---" << endl;
    int *nums3 = (int *)realloc(nums2, (N + growBy) * sizeof(int));
    for (int i = 0; i < N + growBy; i++)
    {
        cout << nums3[i] << " ";
    }
    cout << endl;

    int shrinkBy;
    cout << "Enter amount to shrink by: ";
    cin >> shrinkBy;

    if (N + growBy - shrinkBy <= 0)
    {
        cout << "Shrink amount too large, resulting size would be " << (N + growBy - shrinkBy) << endl;
        free(nums3);
        free(nums);
        return;
    }

    cout << "--- realloc (shrink by " << shrinkBy << ") ---" << endl;
    int *nums4 = (int *)realloc(nums3, (N + growBy - shrinkBy) * sizeof(int));
    for (int i = 0; i < N + growBy - shrinkBy; i++)
    {
        cout << nums4[i] << " ";
    }
    cout << endl;

    free(nums4);
    free(nums);
}

int main()
{
    test();
    return 0;
}