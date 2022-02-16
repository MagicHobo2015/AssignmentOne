/*********************************************************************************************
 *               Simple Console App.                                                          *
 *   Author(s):                                                                               *
 *       Joshua Land, Simon Lariz, Jesus Contreras, Quan Duong                                *
 *                                                                                            *
 *  Description: This is a simple command line interpreter, that gets and runs user commands. *
 *                                                                                            *
 *                                                                                            *
 *********************************************************************************************/

// Includes

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

// End Includes

// Start ProtoTypes
void welcome();
void prompt();
void help();
void createChildThread(pid_t processID, const char *command);
void makeToken(char *input);

// End ProtoTypes

// Stuff we're using to prevent typing std over and over.
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

// Variable declaration starts here

char *input = NULL;
int i;
char *token;
char *arr[250];
string userInput;
const char *inputToChar;
pid_t pid;

// variables Declaration ends here

int main()
{
    // welcome banner should include instructions to type exit to leave.
    welcome();
    // start a loop
    while (1)
    {
        // Display prompt
        prompt();
        // Take user input
        getline(cin, userInput);

        // Check for exit condition
        if ( userInput == "exit" || userInput == "quit" )
        {
            // Clean up happens here...

            return 0;
        }
        else if (userInput == "help")
        {
            // If youre here the user needs help
            help();
        }
        else
        {
            // If youre here then you have work to do.
            inputToChar = userInput.c_str();
            // Call createChildThread
            createChildThread(pid, inputToChar);
        }

        // Clean up the string for the next loop
        userInput = "";
    }

    return 0;
}

void welcome()
{
    // Print Welcome statement
    cout << "Welcome to myShell, please enter a command to execute or enter \"exit\" to quit the program." << endl;
}

void prompt()
{
    cout << "==> ";
}

void help()
{
    // TODO: add a help message.
    cout << "If you need to exit the program type \"exit\", If you would like to learn more about bash and terminal commands visit https://ss64.com/bash/ for more information." << endl;
}

void createChildThread(pid_t processID, const char *command)
{
    // Create a new process with fork() and save processID
    processID = fork();
    // If processID == 0, then it is the child process
    if (processID == 0)
    {
        // Allow child thread to run system(command)
        system(command);
        // Exit child thread
        _exit(0);
    }
    // This is parent thread
    else
    {
        // Wait for child thread to exit or terminate before continuing
        wait(NULL);
    }
}
<<<<<<< HEAD
=======

void makeToken(char *input)
{
    i = 0;
    token = strtok(input, " ");
    while (token != NULL)
    {
        arr[i++] = token;
        token = strtok(NULL, " ");
    }
    arr[i] = NULL;
}
>>>>>>> ca923c63bd118251d7b43d3262d48698cf42ef03
