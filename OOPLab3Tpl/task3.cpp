#include <iostream>

using namespace std;

class Matrix
{
    short **matrix;
    short rows, columns;
    int state;
    enum State
    {
        OK,
        NOT_ENOUGH_MEMORY,
        BEYOND_THE_ARRAY
    };

public:
    Matrix()
    {
        rows = 4;
        columns = 4;
        matrix = new short *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new short[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = 0;
            }
        }
        state = OK;
    }
    Matrix(short n)
    {
        rows = n;
        columns = n;
        matrix = new short *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new short[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = 0;
            }
        }
        state = OK;
    }
    Matrix(short n, short m, int value)
    {
        rows = n;
        columns = m;
        matrix = new short *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new short[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = value;
            }
        }
        state = OK;
    }
    Matrix(const Matrix &m)
    {
        rows = m.rows;
        columns = m.columns;
        matrix = new short *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new short[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = m.matrix[i][j];
            }
        }
        state = OK;
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void SetElem(short i, short j, short value)
    {
        if (i < rows && j < columns)
        {
            matrix[i][j] = value;
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
        }
    }

    void GetElem(short i, short j)
    {
        if (i < rows && j < columns)
        {
            cout << matrix[i][j] << endl;
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
        }
    }

    void MatrixAdd(const Matrix &m)
    {
        if (rows == m.rows && columns == m.columns)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    matrix[i][j] += m.matrix[i][j];
                }
            }
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
        }
    }

    void MatrixSub(const Matrix &m)
    {
        if (rows == m.rows && columns == m.columns)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    matrix[i][j] -= m.matrix[i][j];
                }
            }
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
        }
    }

    void MatrixMultiply(const Matrix &m)
    {
        if (columns == m.rows)
        {
            short **temp = new short *[rows];
            for (int i = 0; i < rows; i++)
            {
                temp[i] = new short[m.columns];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < m.columns; j++)
                {
                    temp[i][j] = 0;
                }
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < m.columns; j++)
                {
                    for (int k = 0; k < columns; k++)
                    {
                        temp[i][j] += matrix[i][k] * m.matrix[k][j];
                    }
                }
            }
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = temp;
            columns = m.columns;
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
        }
    }

    void MatrixMultipShort(short value)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] *= value;
            }
        }
    }

    bool Comparison(const Matrix &m)
    {
        if (rows == m.rows && columns == m.columns)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (matrix[i][j] != m.matrix[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            state = BEYOND_THE_ARRAY;
            cout << "Error: beyond the array" << endl;
            return false;
        }
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix m1;
    Matrix m2(5);
    Matrix m3(5, 5, 5);

    bool Compare;

    cout << "Empty matrix:" << endl;
    m1.print();

    cout << "Adding one element to the matxrix:" << endl;
    m1.SetElem(0, 5, 5);

    m2.SetElem(0, 0, 1);
    m2.SetElem(1, 1, 1);
    m2.SetElem(2, 2, 1);
    m2.SetElem(3, 3, 1);
    m2.SetElem(4, 4, 1);
    cout << "Matrix 5x5 with diagonal elements:" << endl;
    m2.print();

    cout << "Matrix 3x5 with all elements equal to 5:" << endl;
    m3.print();

    cout << "Adding matrices 2 and 3:" << endl;
    m2.MatrixAdd(m3);
    m2.print();

    cout << "Subtracting matrices 2 and 3:" << endl;
    m2.MatrixSub(m3);
    m2.print();

    cout << "Multiplying matrices 2 and 3:" << endl;
    m2.MatrixMultiply(m3);
    m2.print();

    cout << "Multiplying matrix 2 by 5:" << endl;
    m2.MatrixMultipShort(5);
    m2.print();

    cout << "Comparing matrices 1 and 3:" << endl;
    if (m1.Comparison(m3))
    {
        cout << "Matrices are equal" << endl;
    }
    else
    {
        cout << "Matrices are not equal" << endl;
    }

    cin.get();

    return 0;
}