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
#include <direct.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int Loadstatus = 0;
int LoadAlien_X, LoadAlien_Y, HP_Alien, ATK_Alien, numberofZom;
vector<vector<int>> ZB_atrr(9, vector<int>(3));

char num[9] = {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'}; // number of zombies replaced by char o = 1, p = 2,...

// delete the character inside the string
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

// check the extension of the filename
int chkExtension(string fileNme)
{
    int valid = 0;
    int length = fileNme.size();
    if (fileNme[length - 4] == '.' && fileNme[length - 3] == 't' && fileNme[length - 2] == 'x' && fileNme[length - 1] == 't')
    {
        valid = 1;
    }

    return valid;
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
    mkdir(".\\savefiles"); // create the folder if it doesn't exist

    if (chkExtension(nameFile) == 1)
    {
        userFile = ".\\savefiles\\" + nameFile;
        gameFile.open(userFile, ios::out);
        if (gameFile.is_open())
        {
            gameFile << "Y" << dimY_ << "\nX" << dimX_; // save the dimension of the board
            for (int i = 0; i < dimY_; ++i)
            {

                gameFile << "\n";
                gameFile << 'T';
                for (int j = 0; j < dimX_; ++j)
                {
                    gameFile << map_[i][j]; // save all the objects in the board to the txt file
                }
            }

            int ahp = HP_Alien;
            int aAtk = ATK_Alien;
            gameFile << "\nEH" << ahp << "\nEA" << aAtk;

            int *zhp = getZomHP(Znum);
            int *zatk = getZomAtk(Znum);
            int *zrge = getZomRge(Znum);
            gameFile << "\nx ";
            for (int j = 0; j < Znum; j++)
            {
                int Z_x = getZomX(j); // location(x-axis) of each zombies

                gameFile << Z_x << ",";
            }

            gameFile << "\ny ";
            for (int k = 0; k < Znum; k++)
            {
                int Z_y = getZomY(k); // location(y-axis) of each zombies

                gameFile << Z_y << ",";
            }

            for (int i = 0; i < Znum; i++)
            {

                char ZBnum = num[i];
                // Attributes of all zombies
                gameFile << "\nZ" << i << "\nB" << ZBnum << "H" << zhp[i] << "\nB" << ZBnum << "A" << zatk[i] << "\nB" << ZBnum << "R" << zrge[i];
            }

            gameFile.close();
            cout << "Game saved successfully." << endl;
        }
    }
    else
    {
        cout << "Invalid file extension, only .txt is accepted.\nPlease Try Again." << endl;
        Pause();
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

int loadDim(string Line, char dim)
{

    string content = split(Line, dim);
    int dimNum = stoi(content);

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
    numberofZom = numZom;
    return numZom;
}

int GetLZom()
{
    return numberofZom;
}
int GetLoad()
{
    return Loadstatus;
}

void resetLoad()
{
    Loadstatus = 0;
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

// load zombies' attributes
// B -> Zombie, H -> HP, A -> Attack, R -> Range
void loadZB(string LoadFname)
{
    ifstream gameFile;
    string existFile;
    int testExisting, nZB, i, j;
    i = 0;
    j = 0;

    existFile = ".\\savefiles\\" + LoadFname;

    gameFile.open(existFile, ios::in); // read the file
    if (gameFile.is_open())
    {
        nZB = getLoadZom(existFile);
        int max = nZB * 2 + 2;
        string readLine;
        while (getline(gameFile, readLine))
        {
            char theNum = num[i];

            if (readLine[0] == 'B' && readLine[1] == theNum) // Find the line related to Zombies' Attributes
            {

                if (readLine[2] == 'H')
                {
                    string temp = split(readLine, 'B');
                    string temp1 = split(temp, theNum);
                    string temp2 = split(temp1, 'H');
                    int ZB_hp = stoi(temp2);
                    ZB_atrr[i][0] = ZB_hp;
                }

                else if (readLine[2] == 'A')
                {
                    string temp = split(readLine, 'B');
                    string temp1 = split(temp, theNum);
                    string temp2 = split(temp1, 'A');
                    int ZB_atk = stoi(temp2);
                    ZB_atrr[i][1] = ZB_atk;
                }

                else if (readLine[2] == 'R')
                {
                    string temp = split(readLine, 'B');
                    string temp1 = split(temp, theNum);
                    string temp2 = split(temp1, 'R');
                    int ZB_rge = stoi(temp2);
                    ZB_atrr[i][2] = ZB_rge;
                }

                j++;
                if (j % 3 == 0 && j != 0) // conditions checked 3 times then i increases by 1
                {
                    i++;
                }
            }
            else if (readLine[0] == 'x')
            {
                ZomX_.clear();
                for (int n = 0; n < max; n++)
                {
                    if (readLine[n] == ',')
                    {
                        int numX_ = readLine[n - 1];
                        int actualX = numX_ - 48;
                        ZomX_.push_back(actualX);
                    }
                }
            }
            else if (readLine[0] == 'y')
            {
                ZomY_.clear();
                for (int m = 0; m < max; m++)
                {
                    if (readLine[m] == ',')
                    {
                        int numY_ = readLine[m - 1];
                        int actualY = numY_ - 48;
                        ZomY_.push_back(actualY);
                    }
                }
            }
        }
    }
}

// load all the objects inside the file
// T -> map objects, E -> Alien's attributes, H -> HP, A -> Attack
void loadmap()
{
    ifstream gameFile;
    string existFile, LoadFname;
    int testExist, i, j, k, m, strLength, nZom, dim_x, dim_y, NoZB;
    char del = ',';
    i = 0;
    nZom = 0;
    NoZB = 1;
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
        loadZB(LoadFname);

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
                            if (item == 'A') // Find the axis of Alien
                            {
                                LoadAlien_X = j;
                                LoadAlien_Y = i;
                            }
                        }
                        ++i;
                    }
                }

                else if (readLine[0] == 'E') // Find the line related to Alien's attributes
                {
                    if (readLine[1] == 'H')
                    {
                        string temp = split(readLine, 'E');
                        string temp1 = split(temp, 'H');
                        int Ali_HP = stoi(temp1); // convert string to numeric
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
        Board();
    }

    else
    {
        cout << "The file does not exist." << endl;
        Pause();
    }
}
