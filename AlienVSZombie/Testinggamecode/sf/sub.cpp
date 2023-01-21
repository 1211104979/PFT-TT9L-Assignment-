#include "sub.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
using namespace std;

namespace sf
{
    class Mars 
    { 
    private: 
        vector< vector<char> > map_; // convention to put trailing underscore 
        int dimX_, dimY_;            // to indicate private data 
        
    public: 
        Mars(int dimX = 9, int dimY = 5); 
        void init(int dimX, int dimY); 
        void display() const; 
        void settings();
        int setDimX(int x);
        int setDimY(int y);

        int getDimX() const;
        int getDimY() const;

        char getObject(int dimX, int dimY) const;
    }; 

    Mars::Mars(int dimX, int dimY) 
    { 
        init(dimX, dimY); 
    } 

    void Mars::init(int dimX, int dimY)
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
    // const int kRows = 5;
    // const int kColumns = 9;
    // char kBoard[kRows][kColumns];

    int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

    int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }

    void CreateGameBoard()
    {
        // for (int row = 0; row < kRows; ++row)
        // for (int col = 0; col < kColumns; ++col)
        // {
        //     int random_number = std::rand() % 2;
        //     if (random_number)
        //         kBoard[row][col] = '*';
        //     else
        //         kBoard[row][col] = 'r';
        // }
    }

    void ShowGameBoard()
    {
        // for (int row = 0; row < kRows; ++row)
        // {
        //     for (int col = 0; col < kColumns; ++col)
        //     {
        //         std::cout << kBoard[row][col];
        //     }
        //     std::cout << std::endl;
        // }
    }
}