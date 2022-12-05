#include <iostream>
#include <clocale>
using namespace std;

enum State
{
    OK,
    NOT_ENOUGH_MEMORY,
    BEYOND_THE_ARRAY
};

class Vector
{
    short *s;
    int amount, Amount;
    int state, count = 0;
    unsigned char c;

public:
    Vector()
    {
        amount = 1;
        s = new short[amount];
        s[0] = 0;
        state = OK;
        count++;
    }
    Vector(int amount)
    {
        this->amount = amount;
        s = new short[amount];
        for (int i = 0; i < amount; i++)
        {
            s[i] = 0;
        }
        state = OK;
        if (amount <= 0)
        {
            state = NOT_ENOUGH_MEMORY;
        }
        count++;
    }
    Vector(int amount, int number)
    {
        this->amount = amount;
        s = new short[amount];
        for (int i = 0; i < amount; i++)
        {
            s[i] = number;
        }
        state = OK;
        cout << "Vector " << this << " created" << endl;
        count++;
    }

    Vector(const Vector &v)
    {
        amount = v.amount;
        s = new short[amount];
        for (int i = 0; i < amount; i++)
        {
            s[i] = v.s[i];
        }
        state = OK;
        cout << "Vector " << this << " was copied from " << &v << endl;
        count++;
    }
    ~Vector()
    {
        delete[] s;
        cout << " Vector " << this << " deleted \n";
        count--;
    }

    void Print()
    {
        for (int i = 0; i < amount; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    void SetElement(int index, int value)
    {
        if (index < amount)
        {
            s[index] = value;
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error! Index is beyond the array!" << endl;
        }
    }

    void Elem0is10()
    {
        s[0] = 10;
    }

    void GetElem(int i)
    {
        cout << s[i] << endl;
    }

    void Add(int i, unsigned char c)
    {
        s[i] += c;
    }

    void Sub(int i, unsigned char c)
    {
        s[i] -= c;
    }

    bool Comparison(Vector &v)
    {
        if (amount == v.amount)
        {
            for (int i = 0; i < amount; i++)
            {
                if (s[i] != v.s[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    int AmountOfArrays()
    {
        return count;
    }
};

int main()
{
    Vector v1(5, 4);
    Vector v2(v1);

    int count = 0;

    bool Compare;

    v1.Print();
    v2.Print();

    v2.Elem0is10();
    cout << "Element 0 is: ";
    v2.GetElem(0);

    v1.Add(0, 1);
    v1.Sub(1, 1);
    v1.Print();

    count += v1.AmountOfArrays();
    count += v2.AmountOfArrays();

    if (v1.Comparison(v2))
    {
        cout << "Vectors are equal" << endl;
    }
    else
    {
        cout << "Vectors are not equal" << endl;
    }

    v2.SetElement(9, 4);

    cout << "Amount of arrays: " << count << endl;

    return 0;
}