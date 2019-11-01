#include <iostream>
using namespace std;

/*******************************************
//  BUG of C++:                            /
// This principle DO NOT work with clog!   /
*******************************************/

void iout ( string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31 ) // Ok.
{
    // Linux:
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...

#ifdef _WIN32

#else
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
#endif
    cout << message;  // http://www.cplusplus.com/forum/beginner/108474/
#ifdef _WIN32

#else
    printf ( "\033[%dm", colorisationFin );
#endif
}

void ierr ( string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31 ) // Ok.
{
    // Linux:
    // 31 = RED.
    // 1 = bold.
    // 3 = italic.
    // 4 = underline.
    // 0 = normal.
    // 2 effects or color only.
    // 41 = red background...
#ifdef _WIN32

#else
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
#endif
    cerr << message;  // http://www.cplusplus.com/forum/beginner/108474/
#ifdef _WIN32

#else
    printf ( "\033[%dm", colorisationFin );
#endif
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
