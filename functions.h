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
    bool Check_File_Exists(string);
    bool Check_Folder_Exists(string);
    string Generate_Library_Identifier(string, int&);
    bool Is_Valid_Library_Identifier(string&);
    string Get_Library_Identifier();
    bool Is_valid_Library_Identifier_Loan(string&);
    string Get_Library_Identifier_Loan();
    bool Is_Present_In_Inventory(string);
    void Generate_Setup_Files(string, string, string, int&);
    string Create_Login_Credentials(string, string, string);
    void Generate_Login_Credentials();
    void Generate_Purchase_Recommendations();
    void Generate_Borrow_Record();
    bool Is_Valid_Choice(string& , int , int);
    int Get_Valid_Choice(int, int);
    void Print_Catalogue_Menu();
    void Print_Items(string);
    string Get_Search_File();
    string Get_Search_Item();
    void Search_Inventory(string, string);
    string Delay_7_Days(string);
    string Get_Date_Time();
    void Requests_Log(string, string, string, string);
    string Find_File(string);
    bool Is_Present_In_File(string, string);
    string Get_Issue_Duration(string, string);
    void Update_Borrow_Record(string, string, string, string);
    void Update_Borrowed_Item_File(string, string, string, string, string);
    void View_Borrow_Logs();
    void Generate_Uni1_Items_Record();
    void Generate_Uni2_Items_Record();
    void Exit_Protocol();

#endif