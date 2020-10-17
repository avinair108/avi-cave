/*
Author: Avinash Nair
Compiler: LLVM GCC
Date: 10/11/2020
Purpose of program: This program prompts the user to enter the number of seconds, and makes sure it is
 greater than 0. Next, if there are enough seconds entered for a day, it will output the number of days, and
 will keep checking if there are enough seconds for hours and minutes, outputting the amount for both, and
 finally outputting the remaining seconds.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Initiaalize for user input, day, hours, and minutes
    long long int userSeconds, days, hours, minutes;
    
    //prompt user
    cout << "Enter seconds" << endl;
    cin >> userSeconds;
    cout << "Total seconds: " << userSeconds << endl << endl;
    
    if (userSeconds > 0) // only runs if seconds are postive and greater than 0
    {
        
        // these 8 lines assign values to days, hours, and minutes based off input, decreasing the value in seconds each time
        days = (userSeconds/86400);
        userSeconds = (userSeconds - (days * 86400));
                
        hours = (userSeconds/3600);
        userSeconds = (userSeconds - (hours * 3600));
                
        minutes = (userSeconds/60);
        userSeconds = (userSeconds - (minutes * 60));
        
        if (days > 0) // only runs this if userSeconds is greater or equal to 86400
        {
            cout << days << " day(s)" << endl;
            if (hours > 0) // only runs this if leftover userSeconds is greater than 3600
            {
                cout << hours << " hour(s)" << endl;
                if (minutes > 0) // only runs this if leftover userSeconds is greater than 60
                {
                    cout << minutes << " minute(s)" << endl;
                    if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
                    {
                        cout << userSeconds << " second(s)" << endl;
                    }
                }
                else if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
                {
                    cout << userSeconds << " second(s)" << endl;
                }
            }
            else if (minutes > 0) // only runs this if leftover userSeconds is greater than 60
            {
                cout << minutes << " minute(s)" << endl;
                if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
                {
                    cout << userSeconds << " second(s)" << endl;
                }
            }
            else if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
            {
                cout << userSeconds << " second(s)" << endl;
            }
        }
        
        else if (hours > 0) // only runs this if userSeconds is greater or equal to 3600
        {
            cout << hours << " hour(s)" << endl;
            if (minutes > 0) // only runs this if leftover userSeconds is greater than 60
            {
                cout << minutes << " minute(s)" << endl;
                if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
                {
                    cout << userSeconds << " second(s)" << endl;
                }
            }
            else if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
            {
                cout << userSeconds << " second(s)" << endl;
            }
        }
        else if (minutes > 0) // only runs this if userSeconds is greater or equal to 60
        {
            cout << minutes << " minute(s)" << endl;
            if (userSeconds > 0) // only runs this if leftover userSeconds is greater than 0
            {
                cout << userSeconds << " second(s)" << endl;
            }
        }
        else if (userSeconds > 0) // only runs this if userSeconds is greater than 0
        {
            cout << userSeconds << " second(s)" << endl;
        }
    }
    
    else // error message
        cout << "Total seconds must be greater than zero" << endl;
    
    
    return 0;
}

