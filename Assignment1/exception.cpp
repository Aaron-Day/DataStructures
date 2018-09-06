/*
 * Assignment       :   1
 * Class            :   CST211
 *
 * Author           :   Aaron Day
 *
 * File             :   exception.cpp
 *
 * Description      :   Definitions for the Exception class
 */

#include "exception.h"

/**
 * @brief Exception::Exception          Default constructor. Creates an exception with error code '0'
 */
Exception::Exception()
{
    m_msg = new char;
    *m_msg = '0';
}

/**
 * @brief Exception::Exception          1-arg constructor. Creates an exception with a pointer to a char
 *
 * @param msg                           Pointer to a char representing an error code
 */
Exception::Exception(char* msg)
{
    m_msg = new char;
    *m_msg = *msg;
}

/**
 * @brief Exception::Exception          Copy constructor. Creates a new exception with the same error code
 *                                          as the exception being copied
 *
 * @param copy                          Exception being copied
 */
Exception::Exception(const Exception& copy)
{
    m_msg = new char;
    *m_msg = *copy.m_msg;
}

/**
 * @brief Exception::~Exception         Destructor. Deletes the heap memory allocated to the exception
 */
Exception::~Exception()
{
    delete m_msg;
}

/**
 * @brief Exception::operator =         Equal operator. Creates a new exception with the same error code
 *                                          as the exception on the right-hand-side of the expression
 * @param rhs                           Right-hand-side of the expression
 * @return                              Reference to the Left-hand-side of the expression
 */
Exception& Exception::operator=(const Exception& rhs)
{
    *m_msg = *rhs.m_msg;
    return *this;
}

/**
 * @brief Exception::getMessage         Returns a pointer to the error code char
 *
 * @return                              Error code pointer
 */
const char* Exception::getMessage() const
{
    return m_msg;
}

/**
 * @brief Exception::setMessage         Sets the current error code pointer to a new error code pointer
 *
 * @param msg                           New error code pointer
 */
void Exception::setMessage(char* msg)
{
    *m_msg = *msg;
}

/**
 * @brief operator <<                   Stream extraction operator. Returns the error code as an output stream
 *
 * @param stream                        Output stream
 * @param except                        Exception to retrieve the error code from
 * @return                              Exception error code as output stream
 */
std::ostream& operator<<(std::ostream& stream, const Exception& except)
{
    stream << *except.m_msg;
    return stream;
}

