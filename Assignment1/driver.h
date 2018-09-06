/*
 * Assignment       :   1
 * Class            :   CST211
 *
 * Author           :   Aaron Day
 *
 * File             :   driver.h
 *
 * Description      :   Declarations of testing functions for the Array template class and the Exception class
 */

//#include <iostream>
#include <sstream>

#include "array.h"
#include "exception.h"

using namespace std;

//
//EXCEPTION TEST DECLARATIONS:
//

void test_exception_default_ctor();
void test_exception_1arg_ctor();
void test_exception_copy_ctor();
void test_exception_destructor();

void test_exception_equal();
void test_exception_getMessage();
void test_exception_setMessage();
void test_exception_stream();

//
//ARRAY TEST DECLARATIONS:
//

void test_array_default_ctor();
void test_array_2arg_ctor();
void test_array_copy_ctor();
void test_array_destructor();

void test_array_equal();
void test_array_index();
void test_array_getStartIndex();
void test_array_setStartIndex();
void test_array_getLength();
void test_array_setLength();

//
//ARRAY/EXCEPTION THROW DECLARATION
//
void test_array_exception();

//
//EXCEPTION TEST DEFINITIONS:
//

void test_exception_default_ctor()
{
    Exception except;
    if(*except.getMessage() == '0')
    {
        cout << "PASS - test_exception_default_ctor()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_default_ctor()" << endl;
    }
}
void test_exception_1arg_ctor()
{
    char c = 'E';
    char* err = &c;
    Exception except(err);
    if(*except.getMessage() == 'E')
    {
        cout << "PASS - test_exception_1arg_ctor()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_1arg_ctor()" << endl;
    }
}
void test_exception_copy_ctor()
{
    char c = 'E';
    char* err = &c;
    Exception except(err);
    Exception copy(except);
    if(*except.getMessage() == 'E' && *except.getMessage() == *copy.getMessage())
    {
        cout << "PASS - test_exception_copy_ctor()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_copy_ctor()" << endl;
    }
}
void test_exception_destructor()
{
    cout << "NO TEST - test_exception_destructor()" << endl;
}

void test_exception_equal()
{
    char c = 'C';
    char d = 'D';
    char* err = &c;
    char* err1 = &d;
    Exception except(err);
    Exception except1(err1);
    except = except1;
    if(*except.getMessage() == 'D' && *except.getMessage() == *except1.getMessage())
    {
        cout << "PASS - test_exception_equal()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_equal()" << endl;
    }
}
void test_exception_getMessage()
{
    Exception except;
    if(*except.getMessage() == '0')
    {
        cout << "PASS - test_exception_getMessage()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_getMessage()" << endl;
    }
}
void test_exception_setMessage()
{
    char c = 'C';
    char d = 'D';
    char* err = &c;
    char* err1 = &d;
    Exception except(err);
    except.setMessage(err1);
    if(*except.getMessage() == 'D')
    {
        cout << "PASS - test_exception_setMessage()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_setMessage()" << endl;
    }
}
void test_exception_stream()
{
    Exception except;
    stringstream s;
    s << except.getMessage();
    if(s.str() == "0")
    {
        cout << "PASS - test_exception_stream()" << endl;
    }
    else
    {
        cout << "FAIL - test_exception_stream()" << endl;
    }
}

//
//ARRAY TEST DEFINITIONS:
//

void test_array_default_ctor()
{
    Array<int> array;
    if(array.getLength() == 1 && array.getStartIndex() == 0)
    {
        cout << "PASS - test_array_default_ctor()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_default_ctor()" << endl;
    }
}
void test_array_2arg_ctor()
{
    Array<int> array(5,1);
    if(array.getLength() == 5 && array.getStartIndex() == 1)
    {
        cout << "PASS - test_array_2arg_ctor()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_2arg_ctor()" << endl;
    }
}
void test_array_copy_ctor()
{
    try
    {
        Array<int> array(5,1);
        int start = array.getStartIndex();
        int len = array.getLength();
        for(int i = start; i < start + len; ++i)
        {
            array[i] = 8;
        }
        Array<int> copy(array);
        bool pass = true;
        if(len != 5) pass = false;
        if(start != 1) pass = false;
        if(len != copy.getLength()) pass = false;
        if(start != copy.getStartIndex()) pass = false;
        for(int i = 0; i < len; ++i)
        {
            if(array[i + start] != copy[i + copy.getStartIndex()]) pass = false;
            if(array[i + start] != 8) pass = false;
        }
        if(pass)
        {
            cout << "PASS - test_array_copy_ctor()" << endl;
        }
        else
        {
            cout << "FAIL - test_array_copy_ctor()" << endl;
        }
    }
    catch(Exception except)
    {
        switch(*except.getMessage())
        {
        case 'l':
            cout << "FAIL - Index too low" << endl;
            break;
        case 'u':
            cout << "FAIL - Index too high" << endl;
            break;
        }
    }
}
void test_array_destructor()
{
    cout << "NO TEST - test_array_destructor()" << endl;
}

void test_array_equal()
{
    try {
        Array<int> array(5,1);
        int start = array.getStartIndex();
        int len = array.getLength();
        for(int i = start; i < start + len; ++i)
        {
            array[i] = 8;
        }
        Array<int> copy = array;
        bool pass = true;
        if(len != 5) pass = false;
        if(start != 1) pass = false;
        if(len != copy.getLength()) pass = false;
        if(start != copy.getStartIndex()) pass = false;
        for(int i = 0; i < len; ++i)
        {
            if(array[i + start] != copy[i + copy.getStartIndex()]) pass = false;
            if(array[i + start] != 8) pass = false;
        }
        if(pass)
        {
            cout << "PASS - test_array_equal()" << endl;
        }
        else
        {
            cout << "FAIL - test_array_equal()" << endl;
        }
    }
    catch(Exception except)
    {
        switch(*except.getMessage())
        {
        case 'l':
            cout << "FAIL - Index too low" << endl;
            break;
        case 'u':
            cout << "FAIL - Index too high" << endl;
            break;
        }
    }
}
void test_array_index()
{
    try
    {
        Array<int> array(5,1);
        int start = array.getStartIndex();
        int len = array.getLength();
        for(int i = start; i < start + len; ++i)
        {
            array[i] = 8;
        }
        bool pass = true;
        if(len != 5) pass = false;
        if(start != 1) pass = false;
        for(int i = 0; i < len; ++i)
        {
            if(array[i + start] != 8) pass = false;
        }
        if(pass)
        {
            cout << "PASS - test_array_index()" << endl;
        }
        else
        {
            cout << "FAIL - test_array_index()" << endl;
        }
    }
    catch(Exception except)
    {
        switch(*except.getMessage())
        {
        case 'l':
            cout << "FAIL - Index too low" << endl;
            break;
        case 'u':
            cout << "FAIL - Index too high" << endl;
            break;
        }
    }
}
void test_array_getStartIndex()
{
    Array<int> array;
    if(array.getStartIndex() == 0)
    {
        cout << "PASS - test_array_getStartIndex()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_getStartIndex()" << endl;
    }
}
void test_array_setStartIndex()
{
    Array<int> array;
    array.setStartIndex(1);
    if(array.getStartIndex() == 1)
    {
        cout << "PASS - test_array_setStartIndex()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_setStartIndex()" << endl;
    }
}
void test_array_getLength()
{
    Array<int> array;
    if(array.getLength() == 1)
    {
        cout << "PASS - test_array_getLength()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_getLength()" << endl;
    }
}
void test_array_setLength()
{
    Array<int> array;
    array.setLength(2);
    if(array.getLength() == 2)
    {
        cout << "PASS - test_array_setLength()" << endl;
    }
    else
    {
        cout << "FAIL - test_array_setLength()" << endl;
    }
}

//
//ARRAY EXCEPTION THROW DEFINITION
//

void test_array_exception()
{
    Array<int> array(5,5);
    try
    {
        cout << array[10] << endl;//<5 or >9
    }
    catch(Exception except)
    {
        switch(*except.getMessage())
        {
        case 'l':
            cout << "PASS - Caught index low exception" << endl;
            break;
        case 'u':
            cout << "PASS - Caught index high exception" << endl;
            break;
        default:
            cout << "FAIL - Exception not listed" << endl;
        }
    }
}
