/*
 * Assignment       :   1
 * Class            :   CST211
 *
 * Author           :   Aaron Day
 *
 * File             :   exception.h
 *
 * Description      :   Declarations for the Array template class
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

class Exception
{
public:
    Exception();
    Exception(char* msg);
    Exception(const Exception& copy);
    ~Exception();

    Exception& operator=(const Exception& rhs);
    const char* getMessage() const;
    void setMessage(char* msg);
    friend ostream& operator<<(ostream& stream, const Exception& except);

private:
    char* m_msg;
};

#endif // EXCEPTION_H
