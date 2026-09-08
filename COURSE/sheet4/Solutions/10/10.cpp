#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Stack
struct Stack
{
    int size;
    int top;
    int *S;
    Stack(int size)
    {
        if (size <= 0)
        {
            cout << "Invalid size" << endl;
            return;
        }
        this->size = size;
        this->top = -1;
        this->S = new int[size];
    }
};

bool underflow(Stack *st)
{
    if (st->top == -1)
    {
        return true;
    }

    return false;
}

bool overflow(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return true;
    }
    return false;
}

int pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return -99;
    }
    int x = st->S[st->top];
    st->top--;
    return x;
}

void push(Stack *st, int x)
{
    if (overflow(st))
    {
        cout << "Stack is full" << endl;
        return;
    }
    st->top++;
    st->S[st->top] = x;
}

bool isEmpty(Stack *st)
{
    return st->top == -1;
}

// order = 0 is ascending, order = 1 is descending
int partition(int arr[], int beg, int end, int order = 0)
{
    // Init
    int dir = order ? -1 : 1;
    // 1 = ascending, -1 = descending
    int left = beg;
    int right = end;
    int loc = left;
    // loc tracks the current position of the element to places correctly

    while (left < right)
    { // Scan R to L if larger element found then Swap and brake
        while (dir * arr[right] >= dir * arr[loc] && right != loc)
        {
            right--;
        }
        if (right == loc)
        {
            return loc;
        }
        if (dir * arr[right] < dir * arr[loc])
        {
            // swap the elements and loc
            int temp = arr[right];
            arr[right] = arr[loc];
            arr[loc] = temp;
            loc = right;
        }
        // Scan L to R if smaller element found then Swap and break
        while (dir * arr[left] <= dir * arr[loc] && left != loc)
        {
            left++;
        }
        if (left == loc)
        {
            return loc;
        }
        if (dir * arr[left] > dir * arr[loc])
        {
            // swap the elements and loc
            int temp = arr[left];
            arr[left] = arr[loc];
            arr[loc] = temp;
            loc = left;
        }
    }
}

// order = 0 is ascending, order = 1 is descending
void quickSort(int arr[], int low, int high, int order = 0)
{
    if (low >= high)
    {
        return;
    }

    Stack lowidx(high - low + 1);
    Stack highidx(high - low + 1);

    push(&lowidx, low);
    push(&highidx, high);

    while (!isEmpty(&lowidx) && !isEmpty(&highidx))
    {
        low = pop(&lowidx);
        high = pop(&highidx);

        int loc = partition(arr, low, high, order);
        if ((high - loc) > 1)
        {
            push(&lowidx, loc + 1);
            push(&highidx, high);
        }

        if ((loc - low) > 1)
        {
            push(&lowidx, low);
            push(&highidx, loc - 1);
        }
    }
}

// sorts one array both ways (ascending and descending) and prints each result
void runTest(int arr[], int n)
{
    cout << "Original: ";
    printArr(arr, n);

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = arr[i];
    quickSort(a, 0, n - 1, 0); // ORDER = 0 is ascending
    cout << "Ascending  (ORDER = 0): ";
    printArr(a, n);

    for (int i = 0; i < n; i++)
        a[i] = arr[i];
    quickSort(a, 0, n - 1, 1); // ORDER = 1 is descending
    cout << "Descending (ORDER = 1): ";
    printArr(a, n);

    delete[] a;
    cout << endl;
}

int main()
{
    int arr1[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int arr2[] = {9, 7, 5, 3, 1};
    int arr3[] = {2, 4, 2, 1, 3};
    int arr4[] = {5};   
    int *arr5 = new int[0]; 

    runTest(arr1, 12);
    runTest(arr2, 5);
    runTest(arr3, 5);
    runTest(arr4, 1);
    runTest(arr5, 0);

    delete[] arr5;
    return 0;
}
