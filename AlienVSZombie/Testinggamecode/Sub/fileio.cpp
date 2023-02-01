#include "MainHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int fileExisting(string fileNme)
{
    ifstream gameFile;
    string fname;
    char oWrite;
    int i = 0;

    gameFile.open(".\\testfiles\\" + fileNme);
    if (gameFile)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string getFileName()
{
    string fileName;

    cout << "Name your file -> ";
    cin >> fileName;
    cout << endl;
    return fileName;
}

string getLoadFname()
{
    string loadName;

    cout << "Enter the file name to load -> ";
    cin >> loadName;
    cout << endl;
    return loadName;
}

void saveFile(string nameFile)
{
    fstream gameFile;
    string userFile;

    int dimY_ = getDimY();
    int dimX_ = getDimX();
    int Znum = getZomB();

    userFile = ".\\savefiles\\" + nameFile;
    gameFile.open(userFile, ios::out);
    if (gameFile.is_open())
    {
        gameFile << "Y:" << dimY_ << " X:" << dimX_;
        for (int i = 0; i < dimY_; ++i)
        {
            gameFile << "\n";
            for (int j = 0; j < dimX_; ++j)
            {
                gameFile << map_[i][j];
            }
        }

        int *hp = getZomHP(Znum);
        int *atk = getZomAtk(Znum);
        int *rge = getZomRge(Znum);

        for (int i = 0; i < Znum; i++)
        {
            gameFile << '\n'
                     << "Z" << i + 1 << ", HP: " << hp[i] << ", ATK:" << atk[i] << ", RGE:" << rge[i];
        }
        gameFile.close();
        cout << "Game saved successfully." << endl;
    }
}

void loadFile(string LoadFname)
{
    ifstream gameFile;
    string existFile;
    int testExist;

    testExist = fileExisting(LoadFname);
    existFile = ".\\savefiles\\" + LoadFname;

    if (testExist == 1)
    {
        gameFile.open(existFile, ios::in); // read the file
        if (gameFile.is_open())
        {
            string readLine;
            while (getline(gameFile, readLine))
            {
                cout << readLine << endl;
            }
            gameFile.close();

            cout << "Game loaded successfully." << endl;
        }
    }
    else
    {
        cout << "The file does not exist." << endl;
    }
}

int fileExist()
{
    ifstream gameFile;
    string fname, name;
    char oWrite;
    int i, Exist;

    name = getFileName();
    Exist = fileExisting(name);

    do
    {
        i = 0;
        if (Exist == 1)
        {
            cout << "The file is existed before. Do you want to overwrite the previous history?\n Y/N -->";
            cin >> oWrite;
            if (oWrite == 'Y' || oWrite == 'y')
            {
                saveFile(name);
            }
            else if (oWrite == 'N' || oWrite == 'n')
            {
                fileExist();
            }

            else
            {
                cout << "Invalid input. Please try again." << endl;
                i = 1;
            }
        }
        else
        {
            saveFile(name);
        }
    } while (i == 1);
    return 0;
}

/*
ios::in - opens the file to read(default for ifstream)
ios::out - opens the file to write(default for ofstream)
ios::binary - opens the file in binary mode
ios::app- opens the file to append new info at the end
ios::ate - opens and moves the control to the end of the file
ios::trunc - removes the data in the existing file
ios::nocreate - opens the file only if it already exists
ios::noreplace - opens the file only if it doesn't already exist
*/
