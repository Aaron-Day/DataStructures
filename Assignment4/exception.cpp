/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 exception.cpp
 *********************************************************************************************************/
#include "exception.h"

using namespace std;

//
//constructors
//

Exception::Exception()
{
    m_msg = new char[8];                //Create a new C-string and assign to m_msg
    char msg[] = "Error: ";             //Create a C-string with a generic error message
    for(int i = 0; i < 8; ++i)          //Loop through all of the characters of the message
    {
        m_msg[i] = msg[i];              //Copy the characters to m_msg
    }
}
Exception::Exception(char* msg)
    :m_msg(nullptr)
{
    setMessage(msg);            //Set m_msg as msg
}
Exception::Exception(const Exception& copy)
    :m_msg(nullptr)
{
    if(this != &copy)                                   //Verify that it is not making a copy of itself
    {
        setMessage(copy.m_msg);                         //Set m_msg as the copies m_msg
    }
    else                                                //If this is a self copy
    {
        char error[] = "Cannot self copy exception";    //Message if self copy
        throw Exception(error);                         //Throw exception
    }
}
Exception::~Exception()
{
    delete m_msg;
}

//
//accessors
//

/*********************************************************************************************************
 * ostream& operator<<(ostream& stream, const Exception& except)
 *
 *  Purpose:    Converts the message to an output stream
 *
 *  Entry:      Exception with message you want sent to output stream
 *
 *  Exit:       Output stream with exception message
 *********************************************************************************************************/
ostream& operator<<(ostream& stream, const Exception& except)
{
    stream << except.m_msg;         //Copy the message to the output stream
    return stream;                  //Return the output stream
}
/*********************************************************************************************************
 * const char* Exception::getMessage() const
 *
 *  Purpose:    This function returns a pointer to the C-string object
 *              with the exception message
 *
 *  Entry:      Function must be connected to an Exception object
 *
 *  Exit:       Returns pointer to the C-string message
 *********************************************************************************************************/
const char* Exception::getMessage() const
{
    return m_msg;
}

//
//mutators
//

/*********************************************************************************************************
 * Exception& Exception::operator=(const Exception& rhs)
 *
 *  Purpose:    Overloaded equal operator so that an Exception object
 *              can easily be set equal to that of an existing
 *              Exception object using a deep copy
 *
 *  Entry:      This function takes an Exception object on both sides
 *              of the binary operator
 *
 *  Exit:       Both exceptions will have the same message
 *********************************************************************************************************/
Exception& Exception::operator=(const Exception& rhs)
{
    setMessage(rhs.m_msg);              //Set m_msg as the rhs's m_msg
    return *this;                       //Return the Exception object
}
/*********************************************************************************************************
 * void Exception::setMessage(char* msg)
 *
 *  Purpose:    Change a current message to a new message
 *
 *  Entry:      Address of C-string object with new message
 *
 *  Exit:       Removes the old message and replaces it with the new
 *              message
 *********************************************************************************************************/
void Exception::setMessage(char* msg)
{
    if(m_msg != msg)                            //If this is not the current message, continue
    {
        if(m_msg != nullptr)
        {
            delete [] m_msg;                    //Delete the old message if there is one
        }
        int numChars = 0;                       //Number of characters in message
        while(msg[numChars] != '\0')            //Loop until the end of message
        {
            ++numChars;                         //Increase the number of characters
        }
        ++numChars;                             //Increase once more to account for the null character
        m_msg = new char[numChars];             //Create a new C-string and assign to m_msg
        for(int i = 0; i < numChars; ++i)       //Loop through all of the characters of the message
        {
            m_msg[i] = msg[i];                  //Copy the characters to m_msg
        }
    }
}
