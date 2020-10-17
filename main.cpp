//  9_14_stream_manipulator

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    //setw(x)
    double s11 = 100.0 , s12 = 100.0 , s13 = 100.0; //student 1
    double s21 = 79.123 , s22 = 88 , s23 = 99; //student 2
    string name1 = "Chewbacca", name2 = "R2D2";
    
    cout << "Student's name: " << name1 << ' ' << s11 << ' ' << s12 << ' ' << s13 << endl;
    
    cout << "Student's name: " << name2 << ' ' << s21 << ' ' << s22 << ' ' << s23 << endl;
    
    cout << "\nwith setw() " << endl;
    
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8) << s12 << setw(8) << s13 << endl;
    
    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8) << s22 << setw(8) << s23 << endl;
    
    // showpoint
    cout << "\nShowpoint\n";
    cout << "s11 w/o showpoint is " << s11 << endl;
    cout << showpoint << "s11 with showpoint is " << s11 << endl;
    
    //reset showpoint
    cout << resetiosflags(ios::showpoint);
    cout << "s11 after resetiosflags(ios::showpoint) is " << s11 << endl;
    
    //setprecision(x) without fixed
    double PI = 3.14159;
    cout << "\nPI w/o setprecision: " << PI << endl;
    cout << setprecision(6) << "Pi with setprecision(6): " << PI << endl;
    cout << setprecision(4) << "Pi with setprecision(4): " << PI << endl;
    
    //setprecision(x) with fixed
    cout << fixed;
    cout << setprecision(6) << "Pi with setprecision(6) with fixed: " << PI << endl;
    cout << setprecision(4) << "Pi with setprecision(4) with fixed: " << PI << endl;
    
    //reset fixed
    cout << resetiosflags(ios::fixed);
    cout << "PI after resetflags(fixed) is " << PI << endl;
    cout << "PI without setprecision: " << PI << endl;
    
    cout << "\nTest scores with setw() and setprecision(2) and fixed" << endl;
    
    cout << fixed << setprecision(2);
    //cout << left; // use this for left justification
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8) << s12 << setw(8) << s13 << endl;
    
    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8) << s22 << setw(8) << s23 << endl;
    
    // difference between fixed and showpoint
    cout << resetiosflags(ios::fixed);
    double x = 90000000.0;
    cout << "x is " << x << endl;
    cout << fixed << "x with fixed is " << x << endl;
    cout << resetiosflags(ios::fixed);
    cout << showpoint;
    cout << "x with showpoint is " << x << endl;
    
    return 0;
}

