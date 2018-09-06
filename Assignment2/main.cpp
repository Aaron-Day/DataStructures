#include <iostream>

#include "driver.h"

using namespace std;

int main()
{
    cout << "\nTESTING EXCEPTION CLASS\n" << endl;

    testException_default_ctor();
    testException_1arg_ctor();
    testException_cctor();

    cout << endl;

    testException_getMessage();
    testException_ostream_oper();

    cout << endl;

    testException_setMessage();
    testException_equal_oper();

    cout << "\nTESTING ARRAY2D CLASS\n" << endl;

    testArray2D_default_ctor();
    testArray2D_2arg_ctor();
    testArray2D_cctor();

    cout << endl;

    testArray2D_getRow();
    testArray2D_getColumn();
    testArray2D_subscript_oper();
    testArray2D_const_subscript_oper();
    testArray2D_Select();

    cout << endl;

    testArray2D_setRow();
    testArray2D_setColumn();
    testArray2D_equal_oper();

    cout << "\nTESTING ROW CLASS\n" << endl;

    testRow_2arg_ctor();

    cout << endl;

    testRow_subscript_oper();
    testRow_const_subscript_oper();

    cout << endl;

    return 0;
}

