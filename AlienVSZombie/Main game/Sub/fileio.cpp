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
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int Loadstatus = 0;
int LoadAlien_X, LoadAlien_Y, HP_Alien, ATK_Alien;

// split string by finding the delimiter
string split(string stence, char del)
{
    string temp = "";

    for (int i = 0; i < stence.size(); i++)
    {
        if (stence[i] != del)
        {
            temp += stence[i];
        }
        else
        {
            cout << temp << " ";
            temp = "";
        }
    }
    return temp;
}

string getFileName()
{
    string fileName;

    cout << "Name your file -> ";
    cin >> fileName;
    cout << endl;
    return fileName;
}

// check the existence of the file
int fileExisting(string fileNme)
{
    ifstream gameFile;
    string fname;
    char oWrite;
    int i = 0;

    gameFile.open(".\\savefiles\\" + fileNme);
    if (gameFile)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void saveHP(int hp)
{
    HP_Alien = hp;
}

void saveATK(int atk)
{
    ATK_Alien = atk;
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
        gameFile << "Y" << dimY_ << "\nX" << dimX_;
        for (int i = 0; i < dimY_; ++i)

        {

            gameFile << "\n";
            gameFile << 'T';
            for (int j = 0; j < dimX_; ++j)
            {

                gameFile << map_[i][j];
            }
        }

        int ahp = HP_Alien;
        int aAtk = ATK_Alien;
        // int aAtk = alien.alatk_;
        gameFile << "\nEH" << ahp << "\nEA" << aAtk;

        int *zhp = getZomHP(Znum);
        int *zatk = getZomAtk(Znum);
        int *zrge = getZomRge(Znum);

        for (int i = 0; i < Znum; i++)
        {
            int ZBnum = i + 1;
            gameFile << "\nZ" << ZBnum << "\nB" << ZBnum << "H" << zhp[i] << "\nB" << ZBnum << "A" << zatk[i] << "\nB" << ZBnum << "R" << zrge[i];
        }

        gameFile.close();
        cout << "Game saved successfully." << endl;
    }
}

// menu for existed fike
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

// convert the string to integer
int loadDim(string Line, char dim)
{

    string content = split(Line, dim);
    int dimNum = stoi(content); // turn string into integer

    return dimNum;
}

string getLoadFname()
{
    string loadName;

    cout << "Enter the file name to load -> ";
    cin >> loadName;
    cout << endl;
    return loadName;
}

// find the x-axis value in the txt file
int getLoadDimX(string file)
{
    ifstream gameFile;
    int dim_x;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'X')
            {
                dim_x = loadDim(readL, 'X');
            }
        }
        gameFile.close();
    }
    return dim_x;
}

// Find the y-axis value in the txt file
int getLoadDimY(string file)
{
    ifstream gameFile;
    int dim_y;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'Y')
            {
                dim_y = loadDim(readL, 'Y');
            }
        }
        gameFile.close();
    }
    return dim_y;
}

// count the number of zombies in the txt file
int getLoadZom(string file)
{
    ifstream gameFile;
    int numZom;
    gameFile.open(file, ios::in); // read the file
    if (gameFile.is_open())
    {
        string readL;
        while (getline(gameFile, readL))
        {
            if (readL[0] == 'Z')
            {
                numZom++;
            }
        }
        gameFile.close();
    }
    return numZom;
}

int GetLoad()
{
    return Loadstatus;
}

int GetAlienX()
{
    return LoadAlien_X;
}

int GetAlienY()
{
    return LoadAlien_Y;
}

int GetAlienHP()
{
    return HP_Alien;
}

int GetAlienATK()
{
    return ATK_Alien;
}

// load all the objects inside the file
void loadmap()
{
    movement AliZom;
    ifstream gameFile;
    string existFile, LoadFname;
    int testExist, i, j, k, m, strLength, nZom, dim_x, dim_y;
    char del = ',';
    i = 0;
    nZom = 0;
    dim_x = 0;
    dim_y = 0;

    LoadFname = getLoadFname();
    testExist = fileExisting(LoadFname);

    if (testExist == 1)
    {
        existFile = ".\\savefiles\\" + LoadFname;
        dim_x = getLoadDimX(existFile);
        dim_y = getLoadDimY(existFile);
        nZom = getLoadZom(existFile);
        init(dim_x, dim_y, nZom);
        map_.clear();
        emptymap(dim_x, dim_y);

        gameFile.open(existFile, ios::in); // read the file
        if (gameFile.is_open())
        {
            string readLine;
            while (getline(gameFile, readLine))
            {

                if (readLine[0] == 'T')
                {
                    if (i < dim_y)
                    {
                        for (int j = 0; j < dim_x; ++j)
                        {
                            char item = readLine[j + 1];
                            cout << item;
                            map_[i][j] = item;
                            if (item == 'A')
                            {
                                LoadAlien_X = j;
                                LoadAlien_Y = i;
                            }
                        }
                        ++i;
                    }
                }

                else if (readLine[0] == 'E')
                {
                    if (readLine[1] == 'H')
                    {
                        string temp = split(readLine, 'E');
                        string temp1 = split(temp, 'H');
                        int Ali_HP = stoi(temp1);
                        HP_Alien = Ali_HP;
                    }

                    else if (readLine[1] == 'A')
                    {
                        string temp = split(readLine, 'E');
                        string temp1 = split(temp, 'A');
                        int Ali_ATK = stoi(temp1);
                        ATK_Alien = Ali_ATK;
                    }
                }
            }
        }
        gameFile.close();
        Loadstatus = 1;
    }

    else
    {
        cout << "The file does not exist." << endl;
    }
}
