/*********************************************************************************************
*               Simple Console App.                                                          *
*   Author(s):                                                                               *
*       Joshua Land,                                                                         *
*                                                                                            *
*   Description: This is a simple command line interpreter, that gets and runs user commands.
*
*                                                                                            *
*********************************************************************************************/

// Includes

#include <iostream>
#include <string>

// End Includes

// Start ProtoTypes
void welcome();
void prompt();
void help();
// End ProtoTypes

// Stuff were using to prevent typing std over and over.
using std::cout; using std::getline; using std::endl; 
using std::string; using std::cin;


int main() 
{
    // Variable declaration starts here
    
    bool run = true;
    string userInput;
    
    // variables Declaration ends here

    // welcome banner should include instructions to type exit to leave.
    // start a loop
    while (run) 
    {
        // first prompt
        prompt();
        // then get the input
        getline(cin, userInput);
        // check for exit condition
        if ( userInput == "exit") 
        {
            // clean up happens here...

            return 0;
        } else if (userInput == "help")
        {
            // if youre here the user needs help
            help();
        }

        // clean up the string for the next loop
        userInput = "";
    }

    return 0;
}

void welcome()
{
    // TODO: Create a welcome message
}

void prompt() 
{
    cout << "==> ";
}

void help()
{
    // TODO: add a help message.
}