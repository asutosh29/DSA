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

Complex* add_cmplx(Complex *c1, Complex *c2)
{
    Complex *result = new Complex();
    result->real = c1->real + c2->real;
    result->img = c1->img + c2->img;
    return result;
}
Complex* mult_cmplx(Complex *c1, Complex *c2)
{
    Complex *result = new Complex();
    result->real = c1->real * c2->real - c1->img * c2->img;
    result->img = c1->real * c2->img + c1->img * c2->real;
    return result;
}

Complex* div_cmplx(Complex *c1, Complex *c2)
{
    if(c2->real == 0 && c2->img == 0)
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

Complex* negate_cmplx(Complex *c)
{
    c->img = -c->img;
    return c;
}

void test_cmplx(){
    
    Complex *c1 = new Complex(3.0f, 4.0f);
    Complex *c2 = new Complex(1.0f, 2.0f);

    cout << "c1: " << c1->real << " + " << c1->img << "i" << endl;
    cout << "c2: " << c2->real << " + " << c2->img << "i" << endl;

    Complex *sum = add_cmplx(c1, c2);
    cout << "Sum: " << sum->real << " + " << sum->img << "i" << endl;

    Complex *product = mult_cmplx(c1, c2);
    cout << "Product: " << product->real << " + " << product->img << "i" << endl;

    Complex *quotient = div_cmplx(c1, c2);
    if (quotient != nullptr)
    {
        cout << "Quotient: " << quotient->real << " + " << quotient->img << "i" << endl;
        delete quotient;
    }

    Complex *negated = negate_cmplx(c1);
    cout << "Negated c1: " << negated->real << " + " << negated->img << "i" << endl;

    // Freeing memory from heap
    delete c1;
    delete c2;
    delete sum;
    delete product;
    delete negated;
}

int main()
{
    test_cmplx();
    return 0;
}