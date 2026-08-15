#include <iostream>
#include <cstdlib>
using namespace std;

void test()
{
    int N;
    cout << "Enter block size (number of ints): ";
    cin >> N;
    if (N <= 0) {
        cout << "N must be positive." << endl;
        return;
    }

    int growBy;
    cout << "Enter amount to grow by: ";
    cin >> growBy;
    if (growBy < 0) {
        cout << "Grow amount cannot be negative." << endl;
        return;
    }

    int shrinkBy;
    cout << "Enter amount to shrink by (from grown size): ";
    cin >> shrinkBy;
    if (shrinkBy < 0) {
        cout << "Shrink amount cannot be negative." << endl;
        return;
    }

    cout << "--- malloc ---" << endl;;
    int *nums = (int *)malloc(N * sizeof(int));
    cout << "Uninitialized values: ";
    for (int i = 0; i < N; i++)
        cout << nums[i] << " ";
    cout << endl;

    cout << "--- calloc ---" << endl;
    int *nums2 = (int *)calloc(N, sizeof(int));
    cout << "Zero-initialized values: ";
    for (int i = 0; i < N; i++)
        cout << nums2[i] << " ";
    cout << endl;

    for (int i = 0; i < N; i++)
        nums2[i] = i;

    cout << "--- realloc (grow by " << growBy << ") ---" << endl;
    int grownSize = N + growBy;
    int *nums3 = (int *)realloc(nums2, grownSize * sizeof(int));
    if (nums3 == nullptr) {
        cout << "realloc (grow) failed!" << endl;
        free(nums2);
        free(nums);
        return;
    }
    cout << "After growing to " << grownSize << " ints: ";
    for (int i = 0; i < grownSize; i++)
        cout << nums3[i] << " ";
    cout << endl;

    cout << "--- realloc (shrink by " << shrinkBy << ") ---" << endl;
    int shrunkSize = grownSize - shrinkBy;
    if (shrunkSize <= 0) {
        cout << "Shrink amount too large — resulting size would be " << shrunkSize
             << " (<= 0). Skipping shrink step." << endl;
        free(nums3);
        free(nums);
        return;
    }
    int *nums4 = (int *)realloc(nums3, shrunkSize * sizeof(int));
    if (nums4 == nullptr) {
        cout << "realloc (shrink) failed!" << endl;
        free(nums3);
        free(nums);
        return;
    }
    cout << "After shrinking to " << shrunkSize << " ints: ";
    for (int i = 0; i < shrunkSize; i++)
        cout << nums4[i] << " ";
    cout << endl;

    free(nums4);
    free(nums);
}

int main()
{
    test();
    return 0;
}