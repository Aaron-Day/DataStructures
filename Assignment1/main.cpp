#include <iostream>
#include "array.h"
#include "exception.h"
#include "driver.h"

using namespace std;

int main()
{
    cout << "Exception Constructors/Destructors:" << endl;

    test_exception_default_ctor();
    test_exception_1arg_ctor();
    test_exception_copy_ctor();
    test_exception_destructor();//NO TEST

    cout << endl << "Exception Functions/Operators:" << endl;

    test_exception_equal();
    test_exception_getMessage();
    test_exception_setMessage();
    test_exception_stream();

    cout << endl << "Array Constructors/Destructors:" << endl;

    test_array_default_ctor();
    test_array_2arg_ctor();
    test_array_copy_ctor();
    test_array_destructor();//NO TEST

    cout << endl << "Array Functions/Operators:" << endl;

    test_array_equal();
    test_array_index();
    test_array_getStartIndex();
    test_array_setStartIndex();
    test_array_getLength();
    test_array_setLength();

    cout << endl << "Array Exception Throw:" << endl;

    test_array_exception();

    cout << endl;

    return 0;
}

