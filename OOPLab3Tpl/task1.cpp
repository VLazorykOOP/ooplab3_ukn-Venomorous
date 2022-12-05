#include <iostream>
#include <math.h>
using namespace std;

class Parallelogram
{
private:
    double a;
    double b;
    double angle;
    unsigned int color;

public:
    Parallelogram()
    {
        a = 0;
        b = 0;
        angle = 0;
    }
    Parallelogram(double a, double b, double angle, unsigned int color)
    {
        this->a = a;
        this->b = b;
        this->angle = angle;
        this->color = color;
    }

    double GetArea()
    {
        return a * b * sin(angle);
    }

    double GetPerimeter()
    {
        return 2 * (a + b);
    }

    double GetHeight()
    {
        return b * sin(angle);
    };

    double GetWidth()
    {
        return b * cos(angle);
    }

    int GetColor()
    {
        return color;
    }

    bool CheckParamCorrectness()
    {
        bool boolean = true;

        if (a <= 0 || b <= 0 || angle <= 0 || angle >= 180)
        {
            cout << "Incorrect parameters" << endl;
            boolean = false;
        }

        return boolean;
    }

    void Print()
    {
        if (CheckParamCorrectness())
        {
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "angle: " << angle << endl;
            cout << "area: " << GetArea() << endl;
            cout << "perimeter: " << GetPerimeter() << endl;
            cout << "height: " << GetHeight() << endl;
            cout << "width: " << GetWidth() << endl;
            cout << "color: " << GetColor() << endl;
        }
    }
};

int main()
{

    Parallelogram a(5, 10, 45, 4);
    a.Print();

    return 0;
}