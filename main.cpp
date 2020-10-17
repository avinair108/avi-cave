/*
Author: Avinash Nair
Compiler: LLVM GCC
Date: 10/17/2020
Purpose of program: This program gives the user a list of 4 options for cellphone plans that will either
 calculate their bill, compare plans, give plan info, or quit the program.
 The program runs input validation to make sure the user enters a valid plan and number of gigabytes.
 The program runs a function named calcBill to calculate the bill using paramters for the number of gigs and
 plan.
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//function prototype
double calcBill(double numGigabytes, char plan);

int main()
{
    // initalize variables for menu selction, plan, and number of gigabytes
    int menuChoice;
    char plan;
    double numGigabytes;
    
    cout << "Make your choice" << endl;
    cout << "1 - Calculate bill" << endl;
    cout << "2 - Compare my plan with the other plan" << endl;
    cout << "3 - Get the pricing info for the plans" << endl;
    cout << "4 - Quit" << endl;
    
    cin >> menuChoice;
    // sets a switch based off of the user's input
    switch (menuChoice)
    {
        case 1: // runs if user enters 1
        {
            cout << "Enter your plan, S for silver, G for gold: ";
            cin >> plan;
            if (plan == 'G' || plan == 'S') //validation of plan type
            {
                cout << "How many Gigabytes did you use? ";
                cin >> numGigabytes;
                
                if (numGigabytes >= 0) // validation of number of gigs
                {
                    // rounds up to nearest whole number of gigs
                    numGigabytes = numGigabytes + .9999999;
                    numGigabytes = static_cast<int>(numGigabytes);
            
                    double totalBill;
                    //function call
                    totalBill = calcBill(numGigabytes,plan);
                
                    cout << "Your bill amount is $" << totalBill << endl;
                }
                else
                    cout << "Invalid usage" << endl;
            }
            else
                cout << "Invalid plan" << endl;
            
            cout << "Exiting" << endl;
            break;
        }
        case 2: // runs if user enters 2
        {
            cout << "Enter your plan, S for silver, G for gold: ";
            cin >> plan;
            if (plan == 'G' || plan == 'S') // validation of plan type
            {
                cout << "How many Gigabytes did you use? ";
                cin >> numGigabytes;
                
                if (numGigabytes >= 0) // validation of number of gigs
                {
                    // rounds up to nearest whole number of gigs
                    numGigabytes = numGigabytes + .9999999;
                    numGigabytes = static_cast<int>(numGigabytes);
                
                    if (plan == 'S')
                    {
                        double totalBill;
                        //function call
                        totalBill = calcBill(numGigabytes,plan);
                        
                        cout << "Your bill amount is $" << totalBill << endl;
                        // changes plan to show other option
                        plan = 'G';
                        //function call with new arguments
                        totalBill = calcBill(numGigabytes,plan);
                        cout << "Your bill would have been $" << totalBill << " with the Gold plan" << endl;
                    }
                    else if (plan == 'G')
                    {
                        double totalBill;
                        totalBill = calcBill(numGigabytes,plan);
                        
                        cout << "Your bill amount is $" << totalBill << endl;
                        // changes plan to show other option
                        plan = 'S';
                        //function call with new arguments
                        totalBill = calcBill(numGigabytes,plan);
                        cout << "Your bill would have been $" << totalBill << " with the Silver plan" << endl;
                    }
                }
                else
                    cout << "Invalid usage" << endl;
            }
            else
                cout << "Invalid plan" << endl;
            
            cout << "Exiting" << endl;
            break;
        }
        case 3: // runs if user enters 3
        {
            cout << "Silver Plan" << endl;
            cout << "monthly fee is $29.99, 4 Gbytes are included, charge $10 per excess Gbyte" << endl;
            cout << "Gold Plan" << endl;
            cout << "monthly fee is $49.99, 8 Gbytes are included, charge $5 per excess Gbyte" << endl;
            cout << "Exiting" << endl;
            break;
        }
        case 4: // runs if user enters 4
        {
            cout << "Exiting" << endl;
            break;
        }
        default: // runs if user enters an invalid choice
            cout << "Invalid choice" << endl;
            cout << "Exiting" << endl;
    }

    return 0;
}

double calcBill(double numGigabytes, char plan)
{
    //initalize double userBill
    double userBill = 0.0;
    
    if (plan == 'S') // if selected plan is silver
    {
        // first 4 bytes are ignored (free)
        numGigabytes = numGigabytes-4;
        if (numGigabytes >= 0) // if remainder is greater than 0, each gbyte is $10
        {
            userBill = ((numGigabytes*10)+ 29.99);
        }
        else
        {
            userBill = 29.99;
        }
    }
    else if (plan == 'G')
    {
        // first 8 bytes are ignored (free)
        numGigabytes = numGigabytes-8;
        if (numGigabytes >= 0) // if remainder is greater than 0, each gbyte is $5
        {
            userBill = ((numGigabytes*5)+ 49.99);
        }
        else
        {
            userBill = 49.99;
        }
    }
    
    return userBill;
}
