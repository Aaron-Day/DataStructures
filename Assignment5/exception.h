/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 exception.h
*
* Overview:     Used for throwing exceptions with a char array message
*
* Input:        Input is used to create custom error messages that can be thrown when an exception
*               criteria is met within a try/catch block
*
* Output:       Output stream with error message as a char array
 *********************************************************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

/*********************************************************************************************************
 * Class: Exception
 *
 * Constructors/Destructors:
 *      Exception()
 *              Default constructor. Creates an exception with a generic error message
 *      Exception(char* msg)
 *              1 arg constructor. Creates an exception with a defined message that's passed in
 *      Exception(const Exception& copy)
 *              Copy constructor. Creates an exception using a current exception as a template
 *      ~Iterator()
 *              Destructor, frees memory when the exceptions are destroyed
 *
 * Accessors:
 *      friend ostream& operator<<(ostream& stream, const Exception& except)
 *              Provides an output stream for the error messages
 *      const char* getMessage() const
 *              Returns a pointer to the error message
 *
 * Mutators:
 *      Exception& operator=(const Exception& rhs)
 *              Deletes the current message and makes the message the same as the rhs message
 *      void setMessage(char* msg)
 *              Changes the current message to a new message
 *********************************************************************************************************/

class Exception
{
public:
    //constructors
    Exception();
    Exception(char* msg);
    Exception(const Exception& copy);
    ~Exception();

    //accessors
    friend ostream& operator<<(ostream& stream, const Exception& except);
    const char* getMessage() const;

    //mutators
    Exception& operator=(const Exception& rhs);
    void setMessage(char* msg);

private:
    char* m_msg;
};

#endif // EXCEPTION_H
