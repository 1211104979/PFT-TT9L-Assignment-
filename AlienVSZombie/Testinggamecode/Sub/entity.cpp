// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //

#include "MainHeader.h"

using namespace std;

char randomiseItems(char x)
{
    int randomNum = rand() % 10 + 1; // Can't randomise letters, so assigning each one number with a letter
    switch (randomNum)               // 4 assigned to space to make the chances of " " increase.
    {
    case 1:
        x = 'h'; // h is Health (+20 health to Alien)
        break;

    case 2:
        x = 'v'; // Arrows (v ^ < >) changes movement for alien
        break;

    case 3:
        x = '^'; // Arrows (v ^ < >) changes movement for alien
        break;

    case 4:
        x = '<'; // Arrows (v ^ < >) changes movement for alien
        break;

    case 5:
        x = '>'; // Arrows (v ^ < >) changes movement for alien
        break;

    case 6:
        x = 'p';
        break;

    case 7:
        x = ' ';
        break;

    case 8:
        x = ' ';
        break;

    case 9:
        x = ' ';
        break;

    case 10:
        x = ' ';
        break;
    }
    return x;
}
