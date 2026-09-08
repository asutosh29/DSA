#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->S = new int[size];
    }
};

bool underflow(Stack *st)
{
    return st->top == -1;
}

bool overflow(Stack *st)
{
    return st->top == st->size - 1;
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

void Tower_NR(int n, Stack *beg, Stack *end, Stack *aux)
{
    int max_depth = n + 5;
    int *STN = new int[max_depth];
    Stack **STBEG = new Stack *[max_depth];
    Stack **STAUX = new Stack *[max_depth];
    Stack **STEND = new Stack *[max_depth];
    int *STADD = new int[max_depth];

    int top = -1;
    int addr;

step2:
    if (n == 1)
    {
        int x = pop(beg);
        push(end, x);
        cout << "Moved " << x << " from beg to end" << endl;
        goto step6;
    }

step3:
    top++;
    STN[top] = n;
    STBEG[top] = beg;
    STAUX[top] = aux;
    STEND[top] = end;
    STADD[top] = 4;

    n = n - 1;
    {
        Stack *temp = aux;
        aux = end;
        end = temp;
    }

    goto step2;

step4:
    {
        int x = pop(beg);
        push(end, x);
        cout << "Moved " << x << " from beg to end" << endl;
    }

step5:
    top++;
    STN[top] = n;
    STBEG[top] = beg;
    STAUX[top] = aux;
    STEND[top] = end;
    STADD[top] = 6;

    n = n - 1;
    {
        Stack *temp = beg;
        beg = aux;
        aux = temp;
    }

    goto step2;

step6:
    if (top == -1)
    {
        delete[] STN;
        delete[] STBEG;
        delete[] STAUX;
        delete[] STEND;
        delete[] STADD;
        return;
    }

    n = STN[top];
    beg = STBEG[top];
    aux = STAUX[top];
    end = STEND[top];
    addr = STADD[top];
    top--;

    if (addr == 4)
    {
        goto step4;
    }
    else if (addr == 6)
    {
        goto step6;
    }
}

void test_tower(int n)
{
    Stack *beg = new Stack(n);
    Stack *end = new Stack(n);
    Stack *aux = new Stack(n);

    for (int i = n; i >= 1; i--)
    {
        push(beg, i);
    }

    Tower_NR(n, beg, end, aux);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Number of disks must be positive!" << endl;
        return 0;
    }

    test_tower(n);
    return 0;
}
