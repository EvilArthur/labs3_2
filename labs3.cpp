#include <iostream>
using namespace std;


class Complex {
private:
    double a;
    double b;
public:
    Complex() {
        a = 0;
        b = 0;
    }
    
    Complex(double new_a, double new_b) {
        a = new_a;
        b = new_b;
    }

    Complex& operator = (const Complex& complexNum) {
        a = complexNum.a;
        b = complexNum.b;
        return *this;
    }

    ~Complex() {};

    Complex& operator += (const Complex& complexNum) {
        a += complexNum.a;
        b += complexNum.b;
        return *this;
    }

    Complex operator + (const Complex& complexNum) {
        Complex newComplexNum;
        newComplexNum.a = a + complexNum.a;
        newComplexNum.b = b + complexNum.b;
        return newComplexNum;
    }
    
    Complex operator *= (const Complex& complexNum) {
        double tempA, tempB;
        tempA = (a * complexNum.a) - (b * complexNum.b);
        tempB = (a * complexNum.b) + (b * complexNum.a);
        a = tempA;
        b = tempB;
        return *this;
    }

    Complex operator * (const Complex& complexNum) {
        Complex newComplexNum;
        newComplexNum.a = (a * complexNum.a) - (b * complexNum.b);
        newComplexNum.b = (a * complexNum.b) + (b * complexNum.a);
        return newComplexNum;
    }

    Complex& operator ++ () {
        a++;
        return *this;
    }

    Complex operator ++(int) {
        Complex newComplexNum(*this);
        a++;
        return newComplexNum;
    }

    friend istream& operator >> (istream& in, Complex& complexNum) {
        in >> complexNum.a;
        in >> complexNum.b;
        return in;
    }

    friend ostream& operator << (ostream& out, const Complex& complexNum) {
        out << complexNum.a << "+" << complexNum.b << "i";
        return out;
    }







};

int main()
{
    Complex c1, c2, c3;

    cin >> c1;
    cin >> c2;

    c3 = c1 + c2;
    cout << c3 << endl;

    c3 = c1 * c2;
    cout << c3 << endl;

    ++c1;
    cout << c1 << endl;

    c1 += c2;
    cout << c1 << endl;

    c1 *= c2;
    cout << c1 << endl;

    ++c1;
    cout << c1 << endl;
}

