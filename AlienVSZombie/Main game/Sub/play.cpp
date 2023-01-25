#include "MainHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <conio.h>

using namespace std;

void defplay()
{
    ClearScreen();
    Board();
    while(1)
    {
        string con;
        cout << " Command " ;
        cin >> con ;
        if (con == "up")
        {

        }
        if (con == "down")
        {
            
        }
        if (con == "left")
        {
            
        }
        if (con == "right")
        {
            
        }
        if (con == "help")
        {
            help();
        }
        if (con == "save")
        {
            //save();
        }
        if (con == "load")
        {
            //load();
        }
        if (con == "quit")
        {
            exit(0);
        }
    }
}

void play()
{
    ClearScreen();
    changesetting();
    while(1)
    {
        string con;
        cout << " Command " ;
        cin >> con ;
        if (con == "up")
        {

        }
        if (con == "down")
        {
            
        }
        if (con == "left")
        {
            
        }
        if (con == "right")
        {
            
        }
        if (con == "help")
        {
            help();
        }
        if (con == "save")
        {
            //save();
        }
        if (con == "load")
        {
            //load();
        }
        if (con == "quit")
        {
            exit(0);
        }
    }
}