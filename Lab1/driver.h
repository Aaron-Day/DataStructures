#ifndef DRIVER
#define DRIVER

#include <sstream>

#include "array2d.h"
#include "row.h"
#include "exception.h"

using namespace std;

//
//Exception class test declarations
//

void testException_default_ctor();
void testException_1arg_ctor();
void testException_cctor();

void testException_getMessage();
void testException_ostream_oper();

void testException_setMessage();
void testException_equal_oper();

//
//Array2D class test declarations
//

void testArray2D_default_ctor();
void testArray2D_2arg_ctor();
void testArray2D_cctor();

void testArray2D_getRow();
void testArray2D_getColumn();
void testArray2D_subscript_oper();
void testArray2D_const_subscript_oper();
void testArray2D_Select();

void testArray2D_setRow();
void testArray2D_setColumn();
void testArray2D_equal_oper();

//
//Row class test declarations
//

void testRow_2arg_ctor();

void testRow_subscript_oper();
void testRow_const_subscript_oper();



//
//Exception class test definitions
//

void testException_default_ctor()
{
    Exception err;
    char c[] = "Error: ";
    bool pass = *err.getMessage() == *c;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_default_ctor()" << endl;
}

void testException_1arg_ctor()
{
    char c[] = "Oops: ";
    Exception err(c);
    bool pass = *err.getMessage() == *c;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_1arg_ctor()" << endl;
}

void testException_cctor()
{
    char c[] = "Copy";
    Exception err(c);
    Exception copy(err);
    bool pass = *err.getMessage() == *c && *copy.getMessage() == *c;
    try
    {
        Exception self(self);
    }
    catch(Exception ex)
    {
        char test[] = "Cannot self copy exception";
        if(*ex.getMessage() != *test)
        {
            pass = false;
        }
    }
    catch(...)
    {
        pass = false;
    }

    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_cctor()" << endl;
}

void testException_getMessage()
{
    Exception err;
    char c[] = "Error: ";
    bool pass = *err.getMessage() == *c;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_getMessage()" << endl;
}

void testException_ostream_oper()
{
    char c[] = "PASS";
    Exception err(c);
    try
    {
        cout << err;
    }
    catch(...)
    {
        cout << "FAIL";
    }
    cout << " - testException_ostream_oper()" << endl;

}

void testException_setMessage()
{
    char c[] = "New error: ";
    Exception err;
    err.setMessage(c);
    bool pass = *err.getMessage() == *c;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_setMessage()" << endl;
}

void testException_equal_oper()
{
    char c[] = "Copy";
    Exception err;
    Exception copy(c);
    err = copy;
    bool pass = *err.getMessage() == *c && *copy.getMessage() == *c;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testException_equal_oper()" << endl;
}

//
//Array2D class test definitions
//

void testArray2D_default_ctor()
{
    Array2D<int> array;
    bool pass = array.getRow() == 1 && array.getColumn() == 1;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_default_ctor()" << endl;
}

void testArray2D_2arg_ctor()
{
    Array2D<double> array(2, 2);
    bool pass = array.getRow() == 2 && array.getColumn() == 2;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_2arg_ctor()" << endl;
}

void testArray2D_cctor()
{
    Array2D<int> array(5, 5);
    array.Select(0, 0) = 211;
    Array2D<int> copy(array);
    bool pass = copy.getRow() == 5 && copy.getColumn() == 5 && copy.Select(0, 0) == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_cctor()" << endl;
}

void testArray2D_getRow()
{
    Array2D<int> array;
    bool pass = array.getRow() == 1;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_getRow()" << endl;
}

void testArray2D_getColumn()
{
    Array2D<int> array;
    bool pass = array.getColumn() == 1;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_getColumn()" << endl;
}

void testArray2D_subscript_oper()
{
    Array2D<int> array(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            array.Select(i, j) = 211;
        }
    }
    Row<int> row(array, 0);
    bool pass = row[1] == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_subscript_oper()" << endl;
}

void testArray2D_const_subscript_oper()
{
    Array2D<int> array(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            array.Select(i, j) = 211;
        }
    }
    Row<int> row(array, 0);
    bool pass = row[1] == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_const_subscript_oper()" << endl;
}

void testArray2D_Select()
{
    Array2D<int> array;
    array.Select(0, 0) = 1;
    bool pass = array.Select(0, 0) == 1;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_Select()" << endl;
}

void testArray2D_setRow()
{
    Array2D<int> array;
    array.setRow(2);
    bool pass = array.getRow() == 2;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_setRow()" << endl;
}

void testArray2D_setColumn()
{
    Array2D<int> array;
    array.setColumn(2);
    bool pass = array.getColumn() == 2;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_setColumn()" << endl;
}

void testArray2D_equal_oper()
{
    Array2D<int> array1;
    array1.Select(0, 0) = 211;
    Array2D<int> array2;
    array2 = array1;
    bool pass = array2.Select(0, 0) == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testArray2D_equal_oper()" << endl;
}

//
//Row class test definitions
//

void testRow_2arg_ctor()
{
    Array2D<int> array(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            array.Select(i, j) = 211;
        }
    }
    Row<int> row(array, 0);
    bool pass = row[1] == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testRow_2arg_ctor()" << endl;
}

void testRow_subscript_oper()
{
    Array2D<int> array(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            array.Select(i, j) = 211;
        }
    }
    Row<int> row(array, 0);
    bool pass = row[1] == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testRow_subscript_oper()" << endl;
}

void testRow_const_subscript_oper()
{
    Array2D<int> array(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            array.Select(i, j) = 211;
        }
    }
    Row<int> row(array, 0);
    bool pass = row[1] == 211;
    if(pass)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }
    cout << " - testRow_const_subscript_oper()" << endl;
}

#endif // DRIVER

