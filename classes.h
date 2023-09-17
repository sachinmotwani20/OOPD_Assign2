#ifndef CLASSES_H
#define CLASSES_H

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


class User{
    private:
        string user_type="GUE";
        string user_id ="Guest";
        string password ="No value";
        int physical_location=10000;
    public:
        //User Type
        string Access_User_Type();
        void Mutate_User_Type(string );
        //User ID
        string Access_User_Id(); //Getters
        void Mutate_User_Id(); //Setters
        bool Check_User_ID_in_File(string user_id);
        bool Is_Valid_User_Id(string& user_id, string& user_type);
        //Password
        string Access_Password();
        bool Verify_Password();
        bool Check_Password_in_File(string);
        //Other Functions
        bool Login();
        void Purchase_Recommendation(string, string);
};

class Student : public User{
    
    public:
    Student (){ //Constructor
        cout<<"Welcome, Student!"<<endl;
        Mutate_User_Type("STU");
    }
    void Student_Menu();
    void Borrow_Item(string, string);
    
};

class Faculty : public User{

    public:
    Faculty (){ //Constructor
        cout<<"Welcome, Faculty!"<<endl;
        Mutate_User_Type("FAC");
    }
    void Faculty_Menu();
    void Borrow_Item(string, string);
    
};

class Guest : public User{
    public:
    Guest (){ //Constructor
        cout<<"Welcome, Guest!"<<endl;
        Mutate_User_Type("GUE");
    }
    void Guest_Menu();
};

class LibraryStaff : public User{ 
    public:
    LibraryStaff (){ //Constructor 
        cout<<"Welcome, Library Staff!"<<endl;
        Mutate_User_Type("EMP");
    }
    void LibraryStaff_Menu();
    void Manage_Users_Menu();
    void View_Current_Users_List();
    bool Is_Valid_Password(string);
    void Add_New_User();
    void Delete_User();
    void Manage_Inventory_Menu();
    void Add_New_Item();
    void Add_Electronic_Book();
    void Add_Physical_Book();
    void Add_Electronic_Journal();
    void Add_Physical_Journal();
    void Add_Electronic_Magazine();
    void Add_Physical_Magazine();
    void Add_Electronic_Newspaper();
    void Add_Physical_Newspaper();
    void Delete_Item();
    void Delete_Electronic_Book();
    void Delete_Physical_Book();
    void Delete_Electronic_Journal();
    void Delete_Physical_Journal();
    void Delete_Electronic_Magazine();
    void Delete_Physical_Magazine();
    void Delete_Electronic_Newspaper();
    void Delete_Physical_Newspaper();
    void View_Requests_Logs();
    void View_Purchase_Recommendations();
};


#endif