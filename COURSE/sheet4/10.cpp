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

int partition(int arr[], int beg, int end, int order = 0)
{
    // Init
    int dir = order ? -1 : 1; 
    // 1 = ascending, -1 = descending
    int left = beg;
    int right = end;
    int loc = left;
    // loc tracks the current position of the element to places correctly

    while (left < right )
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

void quickSort(int arr[], int low, int high, int order = 0)
{
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

void test_partition()
{
    int n = 12;
    int arr[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    printArr(arr, n);
    int loc = partition(arr, 0, 12, 1);
    printArr(arr, n);
}

void test_quick_sort()
{
    int n = 12;
    int arr[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    quickSort(arr, 0, n - 1, 1);
    printArr(arr, n);
}
int main()
{
    test_quick_sort();
    return 0;
}