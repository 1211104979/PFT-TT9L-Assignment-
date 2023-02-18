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

    int ClearScreen() // clear screen
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

    int Pause() // Pause the game
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }
    
// randomise object for gameboard
char randObject(char x) 
{
    int Num = rand() % 11 + 1;
    switch (Num)             
    {
    case 1:
        x = '^'; 
        break;

    case 2:
        x = 'v'; 
        break;

    case 3:
        x = '<'; 
        break;

    case 4:
        x = '>'; 
        break;

    case 5:
        x = 'h'; 
        break;

    case 6:
        x = 'p';
        break;

    case 7:
        x = 'r';
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

    case 11:
        x = ' ';
        break;
    }
    return x;
}

char refreshObj(char x) 
{
    int Num = rand() % 6 + 1;
    switch (Num)             
    {
    case 1:
        x = 'h'; 
        break;

    case 2:
        x = 'p';
        break;

    case 3:
        x = ' ';
        break;

    case 4:
        x = ' ';
        break;

    case 5:
        x = ' ';
        break;

    case 6:
        x = ' ';
        break;
    }
    return x;
}

void rockobjupdate(int y, int x)
{
    char ranobj, obj;
    if(map_[y][x] == 'r')
    {
        ranobj = randObject(obj);
        map_[y][x] = ranobj;
    }
}

void ranobjupdate()
{
    char ranobj, x;
    int dimY = getDimY();
    int dimX = getDimX();
    for (int i = 0; i < dimY; ++i)
    {
        for (int j = 0; j < dimX; ++j)
        {
            if(map_[i][j] == '.')
            {
                ranobj = randObject(x);
                map_[i][j] = ranobj;
            }
        }
    }
}


