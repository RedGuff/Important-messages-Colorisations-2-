#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

//*****************************************************//
//  BUG of C++:                                        //
// This principle DO NOT work with clog in GNU/Linux!  //
//*****************************************************//
#ifdef _WIN32

void iout ( string message = "",  int colorisationFin = 7, int colorisation1 = 4, int colorisation2 = 31 ){ // Ok.
            HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); // just once
     /* W   http://cppqa.blogspot.com/2013/11/colour-coding-in-c-first-time-i-saw.html
        1_____Blue                                       10______Light Green
2_____Green                                    11______Light Aqua
3_____Aqua                                      12______Light Red
4_____Red                                        13______Light Purple
5_____Purple                                   14______Light Yellow
6_____Yellow                                   15______Bright White
7_____White
8_____Gray
9_____Light Blue
0_____Black

        */

               SetConsoleTextAttribute(color, colorisation1);
       cout << message;

               SetConsoleTextAttribute(color, colorisationFin);
}

void ierr ( string message = "",  int colorisationFin = 7, int colorisation1 = 4, int colorisation2 = 31 ){ // Ok.
     HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); // just once
               SetConsoleTextAttribute(color, colorisation1);
       cerr << message;
               SetConsoleTextAttribute(color, colorisationFin);
}
void ilog ( string message = "",  int colorisationFin = 7, int colorisation1 = 4, int colorisation2 = 31 ){ // Ok.
     HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); // just once
               SetConsoleTextAttribute(color, colorisation1);
       clog << message;
               SetConsoleTextAttribute(color, colorisationFin);
}
#else
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
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cout << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
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
    printf ( "\033[%dm", colorisation1 );
    printf ( "\033[%dm", colorisation2 );
    cerr << message;  // http://www.cplusplus.com/forum/beginner/108474/
    printf ( "\033[%dm", colorisationFin );
}

void ilog(string message = "",  int colorisationFin = 0, int colorisation1 = 1, int colorisation2 = 31){ // No color with clog in GNU/Linux!
clog << message << endl;
}

#endif
int main()
{
cout << "Common Output!" << endl;
iout ( "Important Output!\n");
cout << "Common Output!" << endl;

cerr << "Common Error!" << endl;
ierr ( "Important Error!\n");
cerr << "Common Error!" << endl;

clog << "Common Log!" << endl;
ilog ( "Important Log!\n");
clog << "Common Log!" << endl;

    return 0;
}
