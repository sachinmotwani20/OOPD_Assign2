//Library management system
#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit()
#include <windows.h> //To use Sleep() in windows 

using namespace std;

#include "classes.h"
#include "functions.h"

string books_path="/Data/books.csv";
string journals_path="/Data/journals.csv";
string magazines_path="/Data/magazines.csv";
int Physical_Location= 10000;


int main(){
    //Setup;
    Generate_Setup_Files(books_path, journals_path, magazines_path, Physical_Location);
    Generate_Login_Credentials();
    Generate_Purchase_Recommendations();

    //Variable declarations
    int choice, start=1, stop=5;
    bool Login_Status = false;
    
    Welcome();
    do {
        cout<<"How do you want to enter the LMS? As a "<<endl;
        cout<<"1. Student"<<endl;
        cout<<"2. Faculty"<<endl;
        cout<<"3. Guest [No login required]"<<endl;
        cout<<"4. Library Staff"<<endl;
        cout<<"5. Exit"<<endl;
        choice = Get_Valid_Choice(start, stop);
        
        switch (choice) {
        case 1: {Student s; //Create an object of class Student
                Login_Status = s.Login(); 
                if (!Login_Status) {
                    continue;
                } else {
                        s.Student_Menu();
                }
                break;
                }
        case 2: {Faculty f; //Create an object of class Faculty
                Login_Status = f.Login();
                if (!Login_Status) {
                    continue;
                } else {
                        f.Faculty_Menu();
                }
                break;
                }
        case 3: {Guest g; //Create an object of class Guest
                g.Guest_Menu();
                break;
                }
        case 4: {LibraryStaff ls; //Create an object of class LibraryStaff
                Login_Status = ls.Login();
                if (!Login_Status) {
                    continue;
                } else {
                        ls.LibraryStaff_Menu();
                }
                break;
                }
        case 5: {Exit_Protocol(); // Exit the program
                break;}
        default: 
            cout<<"Invalid choice."<<endl;
            break;
        }
    } while (choice!=stop);
    return 0;

}



