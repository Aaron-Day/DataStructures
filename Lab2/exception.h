/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   10/26/2015
* Assignment Number:        Lab 2
* Filename:                 exception.h
 *********************************************************************************************************/

#include <iostream>

#ifndef EXCEPTION_H
#define EXCEPTION_H

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
