#include <iostream>
using namespace std;

/*******************************************
//  BUG of C++:                            /
// This principle DO NOT work with clog!   /
*******************************************/

void iout ( string message = "",  int colorisationFin = 0, int colorisation1 = 4, int colorisation2 = 1) // Ok.
{
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cout << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
}

void ierr ( string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31 ) // Ok.
{
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cerr << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
}

int main()
{
    cout << "Common Output!" << endl;
iout ( "Important Output!\n");
cout << "Common Output!" << endl;

cerr << "Common Error!" << endl;
ierr ( "Important Error!\n");
cerr << "Common Error!" << endl;
    return 0;
}
