/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/07/2015
 * Last Modification Date:      10/09/2015
 * Assignment Number:           2
 * Filename:                    exception.h
 *
 * Overview:
 *      This is a exception class that can easily create customized
 *      error messages and send them to output streams
 * Input:
 *      Input is often a C-string object passed in as a parameter
 *      with a desired error message to be thrown as an exception
 * Output:
 *      Output stream with the error message
 *********************************************************************************************************/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

/*********************************************************************************************************
 * Class: Exception
 *
 * Constructors/Destructors:
 *      Exception()
 *              Default constructor with generic error message
 *      Exception(char* msg)
 *              1-arg constructor to pass C-string as message
 *      Exception(const Exception& copy)
 *              Copy constructor copies message to new object
 *      ~Exception()
 *              Destructor frees memory allocated for the message
 *
 * Accessors:
 *      const char* getMessage() const
 *              Returns the address of a C-string object
 *      ostream& operator<<(ostream& stream, const Exception& except)
 *              Converts the exception message to an output stream
 *
 * Mutators:
 *      void setMessage(char* msg)
 *              Changes the current message to a new message
 *      Exception& operator=(const Exception& rhs)
 *              Changes the current message to an existing exception
 *              message
 *********************************************************************************************************/

class Exception
{
public:
    //
    //Constructors/Destructors
    //

    //Default constructor
    Exception();

    //1-arg constructor
    Exception(char* msg);

    //Copy constructor
    Exception(const Exception& copy);

    //Destructor
    ~Exception();

    //
    //Accessors
    //

    //Return pointer to C-string message
    const char* getMessage() const;

    //Return output stream with exception message
    friend std::ostream& operator<<(std::ostream& stream, const Exception& except);

    //
    //Mutators
    //

    //Changes the message to a new message
    void setMessage(char* msg);

    //Changes the message to an existing message
    Exception& operator=(const Exception& rhs);

private:
    char* m_msg;        //Exception message C-string

};

#endif // EXCEPTION_H
