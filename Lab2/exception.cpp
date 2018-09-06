/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   10/26/2015
* Assignment Number:        Lab 2
* Filename:                 exception.cpp
 *********************************************************************************************************/
#include "exception.h"

using namespace std;

Exception::Exception()
{
    m_msg = new char;
    *m_msg = '0';
}

Exception::Exception(char* msg)
{
    m_msg = new char;
    *m_msg = *msg;
}

Exception::Exception(const Exception& copy)
{
    m_msg = new char;
    *m_msg = *copy.m_msg;
}

Exception::~Exception()
{
    delete m_msg;
}

Exception& Exception::operator=(const Exception& rhs)
{
    *m_msg = *rhs.m_msg;
    return *this;
}

const char* Exception::getMessage() const
{
    return m_msg;
}

void Exception::setMessage(char* msg)
{
    *m_msg = *msg;
}

ostream& operator<<(ostream& stream, const Exception& except)
{
    stream << *except.m_msg;
    return stream;
}
