#include <iostream>
using namespace std;

struct Complex
{
    float real;
    float img;
    Complex()
    {
        this->real = 0.0f;
        this->img = 0.0f;
    };
    Complex(float real, float img)
    {
        this->real = real;
        this->img = img;
    };
};

Complex *add_cmplx(Complex *c1, Complex *c2)
{
    Complex *result = new Complex();
    result->real = c1->real + c2->real;
    result->img = c1->img + c2->img;
    return result;
}

Complex *mult_cmplx(Complex *c1, Complex *c2)
{
    Complex *result = new Complex();
    result->real = c1->real * c2->real - c1->img * c2->img;
    result->img = c1->real * c2->img + c1->img * c2->real;
    return result;
}

Complex *div_cmplx(Complex *c1, Complex *c2)
{
    if (c2->real == 0 && c2->img == 0)
    {
        cout << "Error: Division by zero complex number!" << endl;
        return nullptr;
    }
    Complex *result = new Complex();
    float denom = c2->real * c2->real + c2->img * c2->img;
    result->real = (c1->real * c2->real + c1->img * c2->img) / denom;
    result->img = (c1->img * c2->real - c1->real * c2->img) / denom;
    return result;
}

Complex *negate_cmplx(Complex *c) // returns conjugate as a NEW object
{
    Complex *result = new Complex(c->real, -c->img);
    return result;
}

void print_cmplx(const char *label, Complex *c)
{
    cout << label << ": " << c->real;
    if (c->img >= 0)
        cout << " + " << c->img << "i" << endl;
    else
        cout << " - " << (-c->img) << "i" << endl;
}

void test()
{
    float r1, i1, r2, i2;

    cout << "Enter first complex number (real imag): ";
    cin >> r1 >> i1;
    Complex *c1 = new Complex(r1, i1);

    cout << "Enter second complex number (real imag): ";
    cin >> r2 >> i2;
    Complex *c2 = new Complex(r2, i2);

    print_cmplx("c1", c1);
    print_cmplx("c2", c2);

    Complex *sum = add_cmplx(c1, c2);
    print_cmplx("Sum", sum);

    Complex *product = mult_cmplx(c1, c2);
    print_cmplx("Product", product);

    Complex *quotient = div_cmplx(c1, c2);
    if (quotient != nullptr)
    {
        print_cmplx("Quotient", quotient);
        delete quotient;
    }

    Complex *conj1 = negate_cmplx(c1);
    print_cmplx("Conjugate of c1", conj1);

    delete c1;
    delete c2;
    delete sum;
    delete product;
    delete conj1;
}

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--)
    {
        test();
    }

    return 0;
}