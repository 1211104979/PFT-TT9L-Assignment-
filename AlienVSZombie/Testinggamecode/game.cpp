#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
using namespace std; 

class GameBoard 
{ 
private: 
    vector< vector<char> > map_; // convention to put trailing underscore 
    int dimX_, dimY_;            // to indicate private data 
    
public: 
    GameBoard(int dimX = 9, int dimY = 5); 
    void BoardGame(int dimX, int dimY);

    void init(int dimX, int dimY); 
    void display() ; 
    void settings();
    int setDimX(int x);
    int setDimY(int y);

    int getDimX() const;
    int getDimY() const;

    char getObject(int dimX, int dimY) const;
}; 

GameBoard::GameBoard(int dimX, int dimY) 
{ 
    init(dimX, dimY); 
} 

void GameBoard::init(int dimX, int dimY)
{ 
    dimX_ = dimX; 
    dimY_ = dimY; 
    
    char objects[] = {'<', '^', '>', 'v', 'h', 'p', 'r', '.', ' ', ' '}; 
    int noOfObjects = 10; // number of objects in the objects array 
    
    // create dynamic 2D array using vector 
    map_.resize(dimY_); // create empty rows 
    for (int i = 0; i < dimY_; ++i)
    { 
        map_[i].resize(dimX_); // resize each row 
    } 
    
    // put random characters into the vector array 
    for (int i = 0; i < dimY_; ++i) 
    { 
        for (int j = 0; j < dimX_; ++j) 
        { 
            int objNo = rand() % noOfObjects; 
            map_[i][j] = objects[objNo]; 
        } 
    } 
}

void GameBoard::settings() 
{  
    GameBoard board;
    // mars.display(); 
    cout << " Board Rows     : " << board.getDimY() << endl; 
    cout << " Board Columns  : " << board.getDimX() << endl; 
    cout << " Zombie Count   : " << endl; // add zombie in the game
    cout << endl;

}

void changesetting()
{
    GameBoard board;
    int x, y;
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    board.setDimX(x);
    board.setDimY(y);
    cout << board.getDimX();
    cout << board.getDimY();
    //Mars(x,y) need to set something to change the board config
}

void GameBoard::display() 
{ 
    // comment this out during testing 
    //system("cls"); // OR system("clear"); for Linux / MacOS 
    cout << " --__--__--__--__--__--__--__--_" << endl; 
    cout << " =       Alien vs Zombie       =" << endl; 
    cout << " __--__--__--__--__--__--__--__-" << endl; 
    
    // for each row 
    for (int i = 0; i < dimY_; ++i) 
    { 
        // display upper border of the row 
        cout << " "; 
        for (int j = 0; j < dimX_; ++j) 
        { 
            cout << "+-"; 
        } 
        cout << "+" << endl; 
        
        // display row number 
        cout << setw(2) << (dimY_ - i); 
        // display cell content and border of each column 
        for (int j = 0; j < dimX_; ++j) 
        { 
            cout << "|" << map_[i][j]; 
        } 
        cout << "|" << endl; 
    } 
    
    // display lower border of the last row 
    cout << " "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        cout << "+-"; 
    } 
    cout << "+" << endl; 
    
    // display column number 
    cout << " "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        int digit = (j + 1) / 10; 
        cout << " "; 
        if (digit == 0) 
            cout << " "; 
        else 
            cout << digit; 
    } 
    cout << endl; 
    cout << " "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        cout << " " << (j + 1) % 10; 
    } 
    cout << endl << endl; 
}

void displaysetting() 
{
    GameBoard board;
    cout << " Default Game Settings " << endl;
    cout << "-----------------------" << endl;
    board.settings();
    cout << " Do you wish to change the game settings (y/n)? =>" << endl;
}

int GameBoard::setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}

int GameBoard::setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}

int GameBoard::getDimX() const
{
    return dimX_;
}

int GameBoard::getDimY() const
{
    return dimY_; 
}

char GameBoard::getObject(int x, int y) const 
{ 
    return map_[dimY_-y][x-1]; 
}

void Board() 
{ 
    GameBoard board; board.display(); 
    
    // int x, y; 
    // char obj; x = 1; y = 1; 
    // obj = mars.getObject(x, y); 
    // cout << "Object at column " << x << " and row " << y << " is [" 
    //      << obj << "]" << endl; 
    // x = 9; y = 2; 
    // obj = mars.getObject(x, y); 
    // cout << "Object at column " << x << " and row " << y << " is [" 
    //      << obj << "]" << endl; 
    
    // x = 5; y = 5; 
    // obj = mars.getObject(x, y); 
    // cout << "Object at column " << x << " and row " << y << " is [" 
    //      << obj << "]" << endl; 
    
    // x = 5; y = 2;
    // obj = mars.getObject(x, y); 
    // cout << "Object at column " << x << " and row " << y << " is [" 
    //      << obj << "]" << endl; 
}

int main() 
{ 
    GameBoard board;
    char input;
    displaysetting();
    cin >> input;
    if (input == 'y' || input == 'Y')
        changesetting();
        Board();

    if (input == 'n' || input == 'N')
        srand(1); // use this for fixed map during testing 

        // srand(time(NULL)); // try this for random map 
        //test1_1();
        //test1_3(); 
        Board();
}