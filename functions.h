#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//Header Files
#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit()
#include <windows.h> //To use Sleep() in windows 

using namespace std;

//Function declarations/prototypes
    void Welcome();
    string Generate_Library_Identifier(string, int&);
    bool Is_Valid_Library_Identifier(string);
    void Generate_Setup_Files(string, string, string, int&);
    string Create_Login_Credentials(string, string, string);
    void Generate_Login_Credentials();
    void Generate_Purchase_Recommendations();
    bool Is_Valid_Choice(string& , int , int);
    int Get_Valid_Choice(int, int);
    void Print_Catalogue_Menu();
    void Print_Items(string);
    string Get_Search_File();
    string Get_Search_Column(string);
    string Get_Search_Item(string, string);
    void Search_Inventory(string, string, string);
    string Get_Date_Time();
    void Requests_Log(string, string, string, string, string);
    void Exit_Protocol();
#endif