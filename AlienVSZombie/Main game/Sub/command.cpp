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

// Command of the game
void play()
{
    movement move;
    int x, y;
    int ChkLoadSta = GetLoad();
    if (ChkLoadSta == 1)
    {
        x = GetAlienX();
        y = GetAlienY();
    }

    else
    {
        x = getDimX() / 2;
        y = getDimY() / 2;
    }

    move.setalienX_(x);
    move.setalienY_(y);
    while (1)
    {
        move.chkAlien_hp();
        move.chkZomB_hp();

        string con;
        cout << endl;
        cout << " Command ";
        cin >> con;

        if (con == "up")
        {
            move.move_up();
            move.zommove();
        }

        else if (con == "down")
        {
            move.move_down();
            move.zommove();
        }

        else if (con == "left")
        {
            move.move_left();
            move.zommove();
        }

        else if (con == "right")
        {
            move.move_right();
            move.zommove();
        }

        else if (con == "arrow")
        {
            int arY, arX;
            string ardir;
            int number = 0;
                cout << " x-axis :";
                while (!(cin >> arX))
                {
                    cout << " wrong input, please put a number for x-axis:";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                cout << " y-axis :";
                while (!(cin >> arY))
                {
                    cout << " wrong input, please put a number for y-axis:";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                cout << " direction(up/down/left/right) :";
                cin >> ardir;
                move.move_arrow(arX, arY, ardir);                
        }

        else if (con == "help")
        {
            help();
            Pause();
            display();
            int no = getZomB();      
            move.alienturndisplay(); 
            zomdisplay(no);
        }

        else if (con == "save")
        {
            fileExist();
        }

        else if (con == "load")
        {
            loadmap();
        }

        else if (con == "menu")
        {
            getMenu();
        }

        else if (con == "quit")
        {
            exit(0);
        }

        else
        {
            cout << "invalid input" << endl;
            Pause();
            display();
            int no = getZomB();      
            move.alienturndisplay(); 
            zomdisplay(no);
        }
    }
}
