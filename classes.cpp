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

#include "classes.h"
#include "functions.h"

/*Definition of Class Functions*/

//-------------"User" Class-------------//

string User :: Access_User_Id(){
    return user_id;
}

bool User :: Check_User_ID_in_File(string u_id){
    string File_Name = "Data/Login_Credentials.csv";
    
    ifstream file(File_Name); //Open the file
    
    if (!file) {
        cout<<"No user database available."<<endl;
        ofstream New_File(File_Name); //Create a new file if it does not exist
        if (!New_File.is_open()) {
            cout << "Error opening user database file: " << File_Name << endl;
        }
        New_File<<"User ID, Password, Name, User Type"<<endl;
        cout<<"New user database created. It is empty."<<endl;
        New_File.close();
        return false;
    } else {
        string row;
        
        while (getline(file, row)) { 

            string user_id_in_file="";
            stringstream input_string(row); //To parse the data read into the stringstream
            
            while(getline(input_string, user_id_in_file, ',')) {
                // cout<<user_id_in_file<<endl;
                // cout<<u_id<<endl;
                if (user_id_in_file == u_id) { //Check if the user ID matches
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

}

bool User :: Is_Valid_User_Id(string& user_id, string u_type){

    string user_type_by_user_ID="";

    // Check Length
    if (user_id.length() != 8) {
        cout<<"Invalid length. User ID must be 8 AlphaNumeric characters long."<<endl;
        return false; // Invalid length
    }

    //Check Characters
    for (int i=0; i< static_cast<int>(user_id.length()); i++) { //Run though the 'for' loop for every character in the string 'user_id' 
        if (i<3) {
            if (isalpha(user_id[i])) { //First three characters
                user_type_by_user_ID += toupper(user_id[i]);
                continue;
            } else {
                cout<<"Invalid character(s) found. User ID must start with three letters."<<endl;
                return false; 
            }

        } else { //Last five characters
            if (isdigit(user_id[i])) {
                continue;
            } else if (user_id[i] == '.') {
                cout<<"Decimal point found. User ID must end with five digits."<<endl;
                return false; 
            } else {
                cout<<"Invalid character(s) found. User ID must end with five digits."<<endl;
                return false; 
            }
        }
    }

    //Check User Type

    if (user_type_by_user_ID != u_type){
        cout<<"User Type does not match the type of user mentioned in the User ID."<<endl;
        return false; // Invalid nomenclature
    }

    //Check if User ID exists in the database
    if (!Check_User_ID_in_File(user_id)){
        cout<<"User ID does not exist in the database."<<endl;
        return false;
    }

    return true; 
}

bool User :: Is_Valid_User_Id_Add_User(string& user_id, string u_type){

    string user_type_by_user_ID="";

    // Check Length
    if (user_id.length() != 8) {
        cout<<"Invalid length. User ID must be 8 AlphaNumeric characters long."<<endl;
        return false; // Invalid length
    }

    //Check Characters
    for (int i=0; i<static_cast<int>(user_id.length()); i++) { //Run though the 'for' loop for every character in the string 'user_id' 
        if (i<3) {
            if (isalpha(user_id[i])) { //First three characters
                user_type_by_user_ID += toupper(user_id[i]);
                continue;
            } else {
                cout<<"Invalid character(s) found. User ID must start with three letters."<<endl;
                return false; 
            }

        } else { //Last five characters
            if (isdigit(user_id[i])) {
                continue;
            } else if (user_id[i] == '.') {
                cout<<"Decimal point found. User ID must end with five digits."<<endl;
                return false; 
            } else {
                cout<<"Invalid character(s) found. User ID must end with five digits."<<endl;
                return false; 
            }
        }
    }

    //Check User Type

    if (user_type_by_user_ID != u_type){
        cout<<"User Type does not match the type of user mentioned in the User ID."<<endl;
        return false; // Invalid nomenclature
    }

    return true; 
}


bool User :: Is_Valid_User_Id_Del_User(string& user_id, string u_type){

    string user_type_by_user_ID="";

    // Check Length
    if (user_id.length() != 8) {
        cout<<"Invalid length. User ID must be 8 AlphaNumeric characters long."<<endl;
        return false; // Invalid length
    }

    //Check Characters
    for (int i=0; i< static_cast<int>(user_id.length()); i++) { //Run though the 'for' loop for every character in the string 'user_id' 
        if (i<3) {
            if (isalpha(user_id[i])) { //First three characters
                user_type_by_user_ID += toupper(user_id[i]);
                continue;
            } else {
                cout<<"Invalid character(s) found. User ID must start with three letters."<<endl;
                return false; 
            }

        } else { //Last five characters
            if (isdigit(user_id[i])) {
                continue;
            } else if (user_id[i] == '.') {
                cout<<"Decimal point found. User ID must end with five digits."<<endl;
                return false; 
            } else {
                cout<<"Invalid character(s) found. User ID must end with five digits."<<endl;
                return false; 
            }
        }
    }

    //Check User Type

    if (user_type_by_user_ID != u_type){
        return false; // Invalid nomenclature
    }

    //Check if User ID exists in the database
    if (!Check_User_ID_in_File(user_id)){
        cout<<"User ID does not exist in the database."<<endl;
        return false;
    }

    return true; 
}

void User :: Mutate_User_Id(){
    while (true) {
        cout<<"Enter your User ID: "<<endl;
        getline(cin, user_id); 
        string u_type = Access_User_Type();
        if (Is_Valid_User_Id(user_id, u_type )) {
            break;
        } else {
            cout << "Please enter a valid User ID." << endl;
        }
    cout<<"User ID is an alphanumeric of 3 letters ('STU','FAC', or, 'EMP') followed by a 5-digit number (Roll number / Employee ID)."<<endl;
    }
}

bool User :: Check_Password_in_File(string provided_password){
    string File_Name = "Data/Login_Credentials.csv";
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string user_type_in_file, user_id_in_file, password_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, user_type_in_file, ','); 
        getline(input_string, user_id_in_file, ','); 
        getline(input_string, password_in_file, ','); 

        if (user_id_in_file == user_id) { 
            if (password_in_file == provided_password) { //Check if the password matches
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

bool User :: Verify_Password(){
    string provided_password;
    bool password_correct=false;
    int counter=0;
    while (true) {
        counter++;
        cout<<"Enter your password: ";
        getline(cin, provided_password);

        // Check Password
        password_correct = Check_Password_in_File(provided_password);
        if (password_correct) {
            cout<<"Password correct."<<endl;
            return true;
        } else {
            cout<<"Password incorrect."<<endl;
            if (counter==3) {
                cout<<"You have entered the wrong password 3 times. Please try again later."<<endl;
                return false;
            }
        }
        
    
    }
}

bool User :: Login(){
   bool verify_user=false;
   Mutate_User_Id();
   verify_user = Verify_Password();
    if (verify_user) {
        cout<<"Login successful."<<endl;
        verify_user = true; 
    } else {
        cout<<"Login unsuccessful."<<endl;
    }
    return verify_user;
}


string User :: Access_Password(){
    return password;
}



void User :: Purchase_Recommendation(string user_id, string date_time){
    string File_Name = "Data/Purchase_Recommendations.csv";
    ofstream file(File_Name, ios::app); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string item_type, item_name, item_author, item_publisher, item_ISBN, item_ISBN13, item_price, item_recommended_by, item_recommended_on;

    cout<<"Enter the item type (Book/Journal/Magazine/Newspaper): ";
    getline(cin, item_type);
    cout<<"Enter the item name/title: ";
    getline(cin, item_name);
    cout<<"Enter the item author: ";
    getline(cin, item_author);
    cout<<"Enter the item publisher: ";
    getline(cin, item_publisher);
    cout<<"Enter the item ISBN: ";
    getline(cin, item_ISBN);

    file<<user_id<<", "<<date_time<<", "<<item_type<<", "<<item_name<<", "<<item_author<<", "<<item_publisher<<", "<<item_ISBN<<endl;
    cout<<"Thanks for suggesting. Item added to the 'Purchase Suggestions' list successfully."<<endl;
    file.close();
}

void User :: Borrow_Item(string user_id, string issue_date_time, string library_identifier){
    
    string File_Name  = Find_File(library_identifier);

    if (File_Name=="") {
        cout<<"Item not found."<<endl;
        return;
    }
    else{
        cout<<"Item found."<<endl;
        Update_Borrow_Record(user_id, issue_date_time, Get_Issue_Duration(user_id, library_identifier), library_identifier);
        Update_Borrowed_Item_File(user_id, issue_date_time, Get_Issue_Duration(user_id, library_identifier), library_identifier, File_Name);
        cout<<"Borrowed item file updated."<<endl;
    }   
    
}

//-------------"Student" Class-------------//

void Student :: Student_Menu(){
    int selection,start=1,stop=5;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Student Menu****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Print Catalogue"<<endl;
        cout<<"2. Search Inventory"<<endl;
        cout<<"3. Borrow Item"<<endl;
        cout<<"4. Recommend a Purchase"<<endl;
        cout<<"5. Exit"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                Print_Catalogue_Menu();
                break;
                }
        case 2: {
                string where_to_search = Get_Search_File();
                string data_to_search = Get_Search_Item();
                cout<<"Query is "<<data_to_search<<" in "<<where_to_search<<endl;
                Search_Inventory(where_to_search, data_to_search);
                cout<<"Search complete."<<endl;
                Requests_Log(Access_User_Id(), where_to_search, data_to_search, Get_Date_Time() ); //Add to requests log
                break;
                }
        case 3: {
                cout<<"Provide Library Identifier of the item you want to borrow: "<<endl;
                string L_Identifier = Get_Library_Identifier();
                string u_id = Access_User_Id();
                string d_t = Get_Date_Time();
                Borrow_Item(u_id, d_t, L_Identifier);
                break;
                }
        case 4: {
                Purchase_Recommendation(Access_User_Id(), Get_Date_Time());
                break;
                }
        case 5: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}

//-------------"Faculty" Class-------------//

void Faculty :: Faculty_Menu(){
    int selection,start=1,stop=5;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Faculty Menu****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Print Catalogue"<<endl;
        cout<<"2. Search Inventory"<<endl;
        cout<<"3. Borrow Item"<<endl;
        cout<<"4. Recommend a Purchase"<<endl;
        cout<<"5. Exit"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                Print_Catalogue_Menu();
                break;
                }
        case 2: {
                string where_to_search = Get_Search_File();
                string data_to_search = Get_Search_Item();
                cout<<"Query is "<<data_to_search<<" in "<<where_to_search<<endl;
                Search_Inventory(where_to_search, data_to_search);
                cout<<"Search complete."<<endl;
                Requests_Log(Access_User_Id(), where_to_search, data_to_search, Get_Date_Time() ); //Add to requests log
                break;
                }
        case 3: {
                cout<<"Provide Library Identifier of the item you want to borrow: "<<endl;
                string L_Identifier = Get_Library_Identifier();
                string u_id = Access_User_Id();
                string d_t = Get_Date_Time();
                Borrow_Item(u_id, d_t, L_Identifier);
                break;
                }
        case 4: {
                Purchase_Recommendation(Access_User_Id(), Get_Date_Time());
                break;
                }
        case 5: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}

//-------------"Guest" Class-------------//
void Guest :: Guest_Menu(){
    int selection,start=1,stop=3;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Guest Menu****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Print Catalogue"<<endl;
        cout<<"2. Search Inventory"<<endl;
        cout<<"3. Exit"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                Print_Catalogue_Menu();
                break;
                }
        case 2: {
                string where_to_search = Get_Search_File();
                string data_to_search = Get_Search_Item();
                cout<<"Query is "<<data_to_search<<" in "<<" of "<<where_to_search<<endl;
                Search_Inventory(where_to_search, data_to_search);
                cout<<"Search complete."<<endl;
                Requests_Log(Access_User_Id(), where_to_search, data_to_search, Get_Date_Time() ); //Add to requests log
                break;
                }
        case 3: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}

//-------------"Staff" Class-------------//

void LibraryStaff :: View_Current_Users_List(){
    string File_Name = "Data/Login_Credentials.csv";
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { //Run though the 'while' loop for every line in the file

        string user_id_in_file, password_in_file, name_in_file, user_type_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, user_type_in_file, ','); //Get the user type from the stringstream
        getline(input_string, user_id_in_file, ','); //Get the user ID from the stringstream
        getline(input_string, password_in_file, ','); //Get the password from the stringstream
        
        
        cout<<user_type_in_file<<","<<user_id_in_file<<","<<password_in_file<<endl;
    }
    file.close();
    return;
}

bool LibraryStaff :: Is_Valid_Password(string password){
    
    if ((password.length() < 8) || (password.length() > 15)) {
        cout<<"Password must be between 8 to 15 characters long."<<endl;
        return false;
    } 

    bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
    for (int i=0; i<static_cast<int>(password.length()); i++) {
        if (isupper(password[i])) {
            has_upper = true;
        } else if (islower(password[i])) {
            has_lower = true;
        } else if (isdigit(password[i])) {
            has_digit = true;
        } else {
            has_special = true;
        }
    }

    if (!has_upper) {
        cout<<"Password must contain at least one uppercase letter."<<endl;
        return false;
    } else if (!has_lower) {
        cout<<"Password must contain at least one lowercase letter."<<endl;
        return false;
    } else if (!has_digit) {
        cout<<"Password must contain at least one digit."<<endl;
        return false;
    } else if (!has_special) {
        cout<<"Password must contain at least one special character."<<endl;
        return false;
    } else {
        return true;
    }
    
}

void LibraryStaff :: Add_New_User(){
    string File_Name = "Data/Login_Credentials.csv";
    ofstream file(File_Name, ios::app); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string user_id, password, name, user_type;

    while (true) {
        cout<<"Enter the User ID: ";
        getline(cin, user_id); 
        cout<<"Enter the User Type: ";
        getline(cin, user_type);
        if (Is_Valid_User_Id_Add_User(user_id, user_type )) {
            break;
        } else if (Check_User_ID_in_File(user_id)) {
            cout << "User ID already exists. Please enter a new User ID." << endl;
        } else  {
            cout << "Invalid input. Please enter a valid User ID." << endl;
        }
    }

    while (true) {
        cout<<"Enter the Password: ";
        getline(cin, password);
        if (Is_Valid_Password(password)) {
            break;
        } else {
            cout<<"Invalid password. Please enter a valid password."<<endl;
        }
        
    }    

    file<<user_type<<','<<user_id<<","<<password<<endl;
    cout<<"User added successfully."<<endl;
    file.close();
    return;
}

void LibraryStaff :: Delete_User(){
    string File_Name = "Data/Login_Credentials.csv";
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string user_id_to_delete, stu_type="STU", fac_type="FAC", emp_type="EMP";
    while (true) {
        cout<<"Enter the User ID of the user to be deleted: ";
        getline(cin, user_id_to_delete); 
        if (Is_Valid_User_Id_Del_User(user_id_to_delete, stu_type) || Is_Valid_User_Id_Del_User(user_id_to_delete, fac_type) || Is_Valid_User_Id_Del_User(user_id_to_delete, emp_type)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid User ID." << endl;
        }
    }

    file.close();

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 

        string user_type_in_file, user_id_in_file, password_in_file;
        stringstream input_string(row1); //To parse the data read into the stringstream
        
        getline(input_string, user_type_in_file, ','); //Get the user type from the stringstream
        getline(input_string, user_id_in_file, ','); //Get the user ID from the stringstream
        getline(input_string, password_in_file, ','); //Get the password from the stringstream
        
        
        if (user_id_in_file == user_id_to_delete) { 
            continue;
        } else {
            file2<<user_type_in_file<<","<<user_id_in_file<<","<<password_in_file<<endl;
        }
    }
    file1.close();
    file2.close();
    remove("Data/Login_Credentials.csv");
    rename("Data/temp.csv", "Data/Login_Credentials.csv");
    cout<<"User deleted successfully."<<endl;
}

void LibraryStaff :: Manage_Users_Menu(){
    int selection,start=1,stop=4;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Manage Users ****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. View Current Users List"<<endl;
        cout<<"2. Add New User"<<endl;
        cout<<"3. Delete User"<<endl;
        cout<<"4. Exit Menu"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                View_Current_Users_List();
                break;
                }
        case 2: {
                Add_New_User();
                break;
                }
        case 3: {
                Delete_User();
                break;
                }
        case 4: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}

void LibraryStaff :: Add_Electronic_Book(){
    
    string File_Name = "Data/Modified/Electronic_Books.csv";
    ofstream file(File_Name, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string book_id, goodreads_book_id, best_book_id, work_id,books_count,isbn,isbn13,authors,original_publication_year,original_title,title,language_code,average_rating,ratings_count,work_ratings_count,work_text_reviews_count,ratings_1,ratings_2,ratings_3,ratings_4,ratings_5,image_url,small_image_url, Library_Identifier, Physical_Copy_Available ;
    int physical_location = 10000;
    Library_Identifier = Generate_Library_Identifier("ELC", physical_location);
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Physical_Copy_Available"<<endl;
    getline(cin, Physical_Copy_Available);
    cout<<"Enter book_id"<<endl;
    getline(cin, book_id);
    cout<<"Enter goodreads_book_id"<<endl;
    getline(cin, goodreads_book_id);
    cout<<"Enter best_book_id"<<endl;
    getline(cin, best_book_id);
    cout<<"Enter work_id"<<endl;
    getline(cin, work_id);
    cout<<"Enter books_count"<<endl;
    getline(cin, books_count);
    cout<<"Enter isbn"<<endl;
    getline(cin, isbn);
    cout<<"Enter isbn13"<<endl;
    getline(cin, isbn13);
    cout<<"Enter authors"<<endl;
    getline(cin, authors);
    cout<<"Enter original_publication_year"<<endl;
    getline(cin, original_publication_year);
    cout<<"Enter original_title"<<endl;
    getline(cin, original_title);
    cout<<"Enter title"<<endl;
    getline(cin, title);
    cout<<"Enter language_code"<<endl;
    getline(cin, language_code);
    cout<<"Enter average_rating"<<endl;
    getline(cin, average_rating);
    cout<<"Enter ratings_count"<<endl;
    getline(cin, ratings_count);
    cout<<"Enter work_ratings_count"<<endl;
    getline(cin, work_ratings_count);
    cout<<"Enter work_text_reviews_count"<<endl;
    getline(cin, work_text_reviews_count);
    cout<<"Enter ratings_1"<<endl;
    getline(cin, ratings_1);
    cout<<"Enter ratings_2"<<endl;
    getline(cin, ratings_2);
    cout<<"Enter ratings_3"<<endl;
    getline(cin, ratings_3);
    cout<<"Enter ratings_4"<<endl;
    getline(cin, ratings_4);
    cout<<"Enter ratings_5"<<endl;
    getline(cin, ratings_5);
    cout<<"Enter image_url"<<endl;
    getline(cin, image_url);
    cout<<"Enter small_image_url"<<endl;
    getline(cin, small_image_url);
    

    file<<Library_Identifier<<","<<Physical_Copy_Available<<","<<book_id<<","<<goodreads_book_id<<","<<best_book_id<<","<<work_id<<","<<books_count<<","<<isbn<<","<<isbn13<<","<<authors<<","<<original_publication_year<<","<<original_title<<","<<title<<","<<language_code<<","<<average_rating<<","<<ratings_count<<","<<work_ratings_count<<","<<work_text_reviews_count<<","<<ratings_1<<","<<ratings_2<<","<<ratings_3<<","<<ratings_4<<","<<ratings_5<<","<<image_url<<","<<small_image_url<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_Physical_Book(){
        
    string File_Name = "Data/Modified/Physical_Books.csv";
    ofstream file(File_Name, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration, book_id, goodreads_book_id, best_book_id, work_id,books_count,isbn,isbn13,authors,original_publication_year,original_title,title,language_code,average_rating,ratings_count,work_ratings_count,work_text_reviews_count,ratings_1,ratings_2,ratings_3,ratings_4,ratings_5,image_url,small_image_url;
    int physical_location = 10000;
    Library_Identifier = Generate_Library_Identifier("PHY", physical_location);
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Electronic_Copy_Available"<<endl;
    getline(cin, Electronic_Copy_Available);
    cout<<"Enter Issue_Status"<<endl;
    getline(cin, Issue_Status);
    cout<<"Enter Checked_Out_Date_And_Time"<<endl;
    getline(cin, Checked_Out_Date_And_Time);
    cout<<"Enter Issue Duration"<<endl;
    getline(cin, Issue_Duration);
    cout<<"Enter book_id"<<endl;
    getline(cin, book_id);
    cout<<"Enter goodreads_book_id"<<endl;
    getline(cin, goodreads_book_id);
    cout<<"Enter best_book_id"<<endl;
    getline(cin, best_book_id);
    cout<<"Enter work_id"<<endl;
    getline(cin, work_id);
    cout<<"Enter books_count"<<endl;
    getline(cin, books_count);
    cout<<"Enter isbn"<<endl;
    getline(cin, isbn);
    cout<<"Enter isbn13"<<endl;
    getline(cin, isbn13);
    cout<<"Enter authors"<<endl;
    getline(cin, authors);
    cout<<"Enter original_publication_year"<<endl;
    getline(cin, original_publication_year);
    cout<<"Enter original_title"<<endl;
    getline(cin, original_title);
    cout<<"Enter title"<<endl;
    getline(cin, title);
    cout<<"Enter language_code"<<endl;
    getline(cin, language_code);
    cout<<"Enter average_rating"<<endl;
    getline(cin, average_rating);
    cout<<"Enter ratings_count"<<endl;
    getline(cin, ratings_count);
    cout<<"Enter work_ratings_count"<<endl;
    getline(cin, work_ratings_count);
    cout<<"Enter work_text_reviews_count"<<endl;
    getline(cin, work_text_reviews_count);
    cout<<"Enter ratings_1"<<endl;
    getline(cin, ratings_1);
    cout<<"Enter ratings_2"<<endl;
    getline(cin, ratings_2);
    cout<<"Enter ratings_3"<<endl;
    getline(cin, ratings_3);
    cout<<"Enter ratings_4"<<endl;
    getline(cin, ratings_4);
    cout<<"Enter ratings_5"<<endl;
    getline(cin, ratings_5);
    cout<<"Enter image_url"<<endl;
    getline(cin, image_url);
    cout<<"Enter small_image_url"<<endl;
    getline(cin, small_image_url);

    file<<Library_Identifier<<","<<Electronic_Copy_Available<<","<<Issue_Status<<","<<Checked_Out_Date_And_Time<<","<<Issue_Duration<<","<<book_id<<","<<goodreads_book_id<<","<<best_book_id<<","<<work_id<<","<<books_count<<","<<isbn<<","<<isbn13<<","<<authors<<","<<original_publication_year<<","<<original_title<<","<<title<<","<<language_code<<","<<average_rating<<","<<ratings_count<<","<<work_ratings_count<<","<<work_text_reviews_count<<","<<ratings_1<<","<<ratings_2<<","<<ratings_3<<","<<ratings_4<<","<<ratings_5<<","<<image_url<<","<<small_image_url<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();

}

void LibraryStaff :: Add_Electronic_Journal(){
        
    string File_Name = "Data/Modified/Electronic_Journals.csv";
    ofstream file(File_Name, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    int physical_location = 10000;
    string Topic, Library_Identifier, Physical_Copy_Available ;

    Library_Identifier= Generate_Library_Identifier("ELC", physical_location);
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Physical_Copy_Available"<<endl;
    getline(cin, Physical_Copy_Available);
    cout<<"Enter Topic"<<endl;
    getline(cin, Topic);

    file<<Library_Identifier<<","<<Physical_Copy_Available<<","<<Topic<<endl;
    
    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_Physical_Journal(){
        
    string File_Name = "Data/Modified/Physical_Journals.csv";
    ofstream file(File_Name, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }
    int physical_location = 10000;
    string Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration, Topic;
    Library_Identifier = Generate_Library_Identifier("PHY", physical_location);
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Electronic_Copy_Available"<<endl;
    getline(cin, Electronic_Copy_Available);
    cout<<"Enter Issue_Status"<<endl;
    getline(cin, Issue_Status);
    cout<<"Enter Checked_Out_Date_And_Time"<<endl;
    getline(cin, Checked_Out_Date_And_Time);
    cout<<"Enter Issue Duration"<<endl;
    getline(cin, Issue_Duration);
    cout<<"Enter Topic"<<endl;
    getline(cin, Topic);

    file<<Library_Identifier<<","<<Electronic_Copy_Available<<","<<Issue_Status<<","<<Checked_Out_Date_And_Time<<","<<Issue_Duration<<","<<Topic<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_Electronic_Magazine(){
            
    string File_Name = "Data/Modified/Electronic_Magazines.csv";
    ofstream file(File_Name, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    int physical_location = 10000;
    string publication, rank, totalPaid, wordRate, daysToBePaid, paymentDifficulty, rank_totalPaid, rank_wordRate, rank_daysToBePaid, rank_paymentDifficulty, Library_Identifier, Physical_Copy_Available ;
    Library_Identifier= Generate_Library_Identifier("ELC", physical_location);
    
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Physical_Copy_Available"<<endl;
    getline(cin, Physical_Copy_Available);
    cout<<"Enter publication"<<endl;
    getline(cin, publication);
    cout<<"Enter rank"<<endl;
    getline(cin, rank);
    cout<<"Enter totalPaid"<<endl;
    getline(cin, totalPaid);
    cout<<"Enter wordRate"<<endl;
    getline(cin, wordRate);
    cout<<"Enter daysToBePaid"<<endl;
    getline(cin, daysToBePaid);
    cout<<"Enter paymentDifficulty"<<endl;
    getline(cin, paymentDifficulty);
    cout<<"Enter rank_totalPaid"<<endl;
    getline(cin, rank_totalPaid);
    cout<<"Enter rank_wordRate"<<endl;
    getline(cin, rank_wordRate);
    cout<<"Enter rank_daysToBePaid"<<endl;
    getline(cin, rank_daysToBePaid);
    cout<<"Enter rank_paymentDifficulty"<<endl;
    getline(cin, rank_paymentDifficulty);

    file<<Library_Identifier<<","<<Physical_Copy_Available<<","<<publication<<","<<rank<<","<<totalPaid<<","<<wordRate<<","<<daysToBePaid<<","<<paymentDifficulty<<","<<rank_totalPaid<<","<<rank_wordRate<<","<<rank_daysToBePaid<<","<<rank_paymentDifficulty<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_Physical_Magazine(){
                
        string File_Name = "Data/Modified/Physical_Magazines.csv";
        ofstream file(File_Name, ios::app); 
    
        if (!file.is_open()) {
            cout << "Error opening user database file: " << File_Name << endl;
        }
        int physical_location = 10000;
        string publication, rank, totalPaid, wordRate, daysToBePaid, paymentDifficulty, rank_totalPaid, rank_wordRate, rank_daysToBePaid, rank_paymentDifficulty, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration;
        Library_Identifier = Generate_Library_Identifier("PHY", physical_location);

        cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
        cout<<"Enter Electronic_Copy_Available"<<endl;
        getline(cin, Electronic_Copy_Available);
        cout<<"Enter Issue_Status"<<endl;
        getline(cin, Issue_Status);
        cout<<"Enter Checked_Out_Date_And_Time"<<endl;
        getline(cin, Checked_Out_Date_And_Time);
        cout<<"Enter Issue Duration"<<endl;
        getline(cin, Issue_Duration);
        cout<<"Enter publication"<<endl;
        getline(cin, publication);
        cout<<"Enter rank"<<endl;
        getline(cin, rank);
        cout<<"Enter totalPaid"<<endl;
        getline(cin, totalPaid);
        cout<<"Enter wordRate"<<endl;
        getline(cin, wordRate);
        cout<<"Enter daysToBePaid"<<endl;
        getline(cin, daysToBePaid);
        cout<<"Enter paymentDifficulty"<<endl;
        getline(cin, paymentDifficulty);
        cout<<"Enter rank_totalPaid"<<endl;
        getline(cin, rank_totalPaid);
        cout<<"Enter rank_wordRate"<<endl;
        getline(cin, rank_wordRate);
        cout<<"Enter rank_daysToBePaid"<<endl;
        getline(cin, rank_daysToBePaid);
        cout<<"Enter rank_paymentDifficulty"<<endl;
        getline(cin, rank_paymentDifficulty);
        
        file<<Library_Identifier<<","<<Electronic_Copy_Available<<","<<Issue_Status<<","<<Checked_Out_Date_And_Time<<","<<Issue_Duration<<","<<publication<<","<<rank<<","<<totalPaid<<","<<wordRate<<","<<daysToBePaid<<","<<paymentDifficulty<<","<<rank_totalPaid<<","<<rank_wordRate<<","<<rank_daysToBePaid<<","<<rank_paymentDifficulty<<endl;

        cout<<"Item added successfully."<<endl;
        file.close();
}

void LibraryStaff :: Add_Electronic_Newspaper(){
                    
    string File_Name = "Data/Modified/Electronic_Newspaper.csv";
    ofstream file(File_Name, ios::app); 
    
    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    int physical_location = 10000;    
    string Name, Library_Identifier= Generate_Library_Identifier("ELC", physical_location), Physical_Copy_Available ;

    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier << endl;
    cout<<"Enter Physical_Copy_Available"<<endl;
    getline(cin, Physical_Copy_Available);
    cout<<"Enter Name"<<endl;
    getline(cin, Name);

    file<<Library_Identifier<<","<<Physical_Copy_Available<<","<<Name<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_Physical_Newspaper(){
                        
    string File_Name = "Data/Modified/Physical_Newspapers.csv";
    ofstream file(File_Name, ios::app); 
    
    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }
    
    int physical_location = 10000;
    string Name, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration ;
    Library_Identifier= Generate_Library_Identifier("PHY", physical_location);
    
    cout<<"The auto-generated Library_Identifier is "<< Library_Identifier<< endl;
    cout<<"Enter Electronic_Copy_Available"<<endl;
    getline(cin, Electronic_Copy_Available);
    cout<<"Enter Issue_Status"<<endl;
    getline(cin, Issue_Status);
    cout<<"Enter Checked_Out_Date_And_Time"<<endl;
    getline(cin, Checked_Out_Date_And_Time);
    cout<<"Enter Issue Duration"<<endl;
    getline(cin, Issue_Duration);
    cout<<"Enter Name"<<endl;
    getline(cin, Name);

    file<<Library_Identifier<<","<<Electronic_Copy_Available<<","<<Issue_Status<<","<<Checked_Out_Date_And_Time<<","<<Issue_Duration<<","<<Name<<endl;

    cout<<"Item added successfully."<<endl;
    file.close();
}

void LibraryStaff :: Add_New_Item(){
    int selection, start=1, stop=5;
    cout<<"------------------------------------------"<<endl;
    cout<<"****Add New Item Menu****"<<endl;
    cout<<"------------------------------------------"<<endl;
    do {
        cout<<"What type of item do you want to add?"<<endl;
        cout<<"1. Book"<<endl;
        cout<<"2. Journal"<<endl;
        cout<<"3. Magazine"<<endl;
        cout<<"4. Newspapers"<<endl;
        cout<<"5. Exit Menu"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                int choice, start=1, stop=2;
                cout<<"What type of book do you want to add?"<<endl;
                cout<<"1. Electronic Book"<<endl;
                cout<<"2. Physical Book"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Add_Electronic_Book();
                            break;
                            }
                    case 2: {
                            Add_Physical_Book();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 2: {
                int choice, start=1, stop=2;
                cout<<"What type of journal do you want to add?"<<endl;
                cout<<"1. Electronic Journal"<<endl;
                cout<<"2. Physical Journal"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Add_Electronic_Journal();
                            break;
                            }
                    case 2: {
                            Add_Physical_Journal();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 3: {
                int choice, start=1, stop=2;
                cout<<"What type of magazine do you want to add?"<<endl;
                cout<<"1. Electronic Magazine"<<endl;
                cout<<"2. Physical Magazine"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Add_Electronic_Magazine();
                            break;
                            }
                    case 2: {
                            Add_Physical_Magazine();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 4: {
                int choice, start=1, stop=2;
                cout<<"What type of newspaper do you want to add?"<<endl;
                cout<<"1. Electronic Newspaper"<<endl;
                cout<<"2. Physical Newspaper"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Add_Electronic_Newspaper();
                            break;
                            }
                    case 2: {
                            Add_Physical_Newspaper();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 5: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
}



void LibraryStaff :: Delete_Electronic_Book() {
    string File_Name = "Data/Modified/Electronic_Books.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the book to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string Library_Identifier;
        stringstream input_string(row1); 
        getline(input_string, Library_Identifier, ',');
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }
        
        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}

void LibraryStaff :: Delete_Physical_Book(){
    string File_Name = "Data/Modified/Physical_Books.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the book to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string book_id_in_file, goodreads_book_id, best_book_id, work_id,books_count,isbn,isbn13,authors,original_publication_year,original_title,title,language_code,average_rating,ratings_count,work_ratings_count,work_text_reviews_count,ratings_1,ratings_2,ratings_3,ratings_4,ratings_5,image_url,small_image_url, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ',');
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}

void LibraryStaff :: Delete_Electronic_Journal(){
    string File_Name = "Data/Modified/Electronic_Journals.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the journal to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string Topic_in_file, Library_Identifier, Physical_Copy_Available;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ','); 
        
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}

void LibraryStaff :: Delete_Physical_Journal(){
    string File_Name = "Data/Modified/Physical_Journals.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the journal to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string Topic_in_file, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ','); 
        
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}

void LibraryStaff :: Delete_Electronic_Magazine(){
    string File_Name = "Data/Modified/Electronic_Magazines.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the magazine to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string publication_in_file, rank, totalPaid, wordRate, daysToBePaid, paymentDifficulty, rank_totalPaid, rank_wordRate, rank_daysToBePaid, rank_paymentDifficulty, Library_Identifier, Physical_Copy_Available;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ',');

        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }

        
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;

}

void LibraryStaff :: Delete_Physical_Magazine(){
    string File_Name = "Data/Modified/Physical_Magazines.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the magazine to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string publication_in_file, rank, totalPaid, wordRate, daysToBePaid, paymentDifficulty, rank_totalPaid, rank_wordRate, rank_daysToBePaid, rank_paymentDifficulty, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ',');

        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;

}

void LibraryStaff :: Delete_Electronic_Newspaper(){
    string File_Name = "Data/Modified/Electronic_Newspaper.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the newspaper to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string Name_in_file, Library_Identifier, Physical_Copy_Available;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ','); 
        
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}

void LibraryStaff :: Delete_Physical_Newspaper(){
    string File_Name = "Data/Modified/Physical_Newspapers.csv";

    string Library_Identifier_to_delete;
    while (true) {
        cout<<"Enter the Library_Identifier of the newspaper to be deleted: ";
        getline(cin, Library_Identifier_to_delete);
        if (Is_Valid_Library_Identifier(Library_Identifier_to_delete)) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid Library_Identifier." << endl;
        }
    }

    ifstream file1(File_Name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row1;
    while (getline(file1, row1)) { 
        bool is_row_to_delete = false;
        string Name_in_file, Library_Identifier, Electronic_Copy_Available, Issue_Status, Checked_Out_Date_And_Time, Issue_Duration;
        stringstream input_string(row1); 
        
        getline(input_string, Library_Identifier, ','); 
        
        if (Library_Identifier == Library_Identifier_to_delete) { 
            is_row_to_delete = true;
        }

        if (is_row_to_delete) { 
            continue;
        } else {
            file2<<row1<<endl;
        }
        
    }

    file1.close();
    file2.close();

    remove(File_Name.c_str()); //Delete the original file
    rename("Data/temp.csv", File_Name.c_str()); //Rename the temp file to the original file name

    cout<<"Item deleted successfully."<<endl;
}


void LibraryStaff :: Delete_Item(){
    int selection , start=1, stop=5;
    cout<<"------------------------------------------"<<endl;
    cout<<"****Delete Item Menu****"<<endl;
    cout<<"------------------------------------------"<<endl;
    do {
        cout<<"Entry of what type of item do you want to delete?"<<endl;
        cout<<"1. Book"<<endl;
        cout<<"2. Journal"<<endl;
        cout<<"3. Magazine"<<endl;
        cout<<"4. Newspapers"<<endl;
        cout<<"5. Exit Menu"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                int choice, start=1, stop=2;
                cout<<"Entry of what type of book do you want to delete?"<<endl;
                cout<<"1. Electronic Book"<<endl;
                cout<<"2. Physical Book"<< endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Delete_Electronic_Book();
                            break;
                            }
                    case 2: {
                            Delete_Physical_Book();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 2: {
                int choice, start=1, stop=2;
                cout<<"Entry of what type of journal do you want to delete?"<<endl;
                cout<<"1. Electronic Journal"<<endl;
                cout<<"2. Physical Journal"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Delete_Electronic_Journal();
                            break;
                            }
                    case 2: {
                            Delete_Physical_Journal();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 3: {
                int choice, start=1, stop=2;
                cout<<"Entry of what type of magazine do you want to delete?"<<endl;
                cout<<"1. Electronic Magazine"<<endl;
                cout<<"2. Physical Magazine"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Delete_Electronic_Magazine();
                            break;
                            }
                    case 2: {
                            Delete_Physical_Magazine();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 4: {
                int choice, start=1, stop=2;
                cout<<"Entry of what type of newspaper do you want to delete?"<<endl;
                cout<<"1. Electronic Newspaper"<<endl;
                cout<<"2. Physical Newspaper"<<endl;
                choice = Get_Valid_Choice(start, stop);
                switch(choice){
                    case 1: {
                            Delete_Electronic_Newspaper();
                            break;
                            }
                    case 2: {
                            Delete_Physical_Newspaper();
                            break;
                            }
                    default:{ 
                            cout<<"Invalid choice."<<endl;
                            break;
                            }
                }
                break;
                }
        case 5: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);

}

void LibraryStaff :: Manage_Inventory_Menu(){
    int selection,start=1,stop=3;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Manage Inventory ****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Add New Item"<<endl;
        cout<<"2. Delete Item"<<endl;
        cout<<"3. Exit Menu"<<endl;
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                Add_New_Item();
                break;
                }
        case 2: {
                Delete_Item();
                break;
                }
        case 3: {
                break;
                }
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}

void LibraryStaff :: View_Requests_Logs(){
    string File_Name = "Data/Requests_Log.csv";
    ifstream file(File_Name);
    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }
    string row;
    while (getline(file, row)) { 
        cout<<row<<endl;
    }
    file.close();
}

void LibraryStaff :: View_Purchase_Recommendations(){
    string File_Name = "Data/Purchase_Recommendations.csv";
    ifstream file(File_Name);
    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }
    string row;
    while (getline(file, row)) { 
        cout<<row<<endl;
    }
    file.close();
}

void LibraryStaff :: LibraryStaff_Menu(){
    int selection,start=1,stop=8;
    cout<<"---------------------------------"<<endl;
    cout<<"**** Library Staff Menu****"<<endl;
    cout<<"---------------------------------"<<endl;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Print Catalogue"<<endl;
        cout<<"2. Search Inventory"<<endl;
        cout<<"3. Manage Users"<<endl;
        cout<<"4. Manage Inventory"<<endl;
        cout<<"5. View Requests Logs"<<endl;
        cout<<"6. View Purchase Recommendations"<<endl;
        cout<<"7. View Borrow Logs"<<endl;
        cout<<"8. Exit Menu"<<endl; 
        selection = Get_Valid_Choice(start, stop);
        switch (selection) {
        case 1: {
                Print_Catalogue_Menu();
                break;
                }
        case 2: {
                string where_to_search = Get_Search_File();
                string data_to_search = Get_Search_Item();
                cout<<"Query is "<<data_to_search<<" in "<<where_to_search<<endl;
                Search_Inventory(where_to_search, data_to_search);
                cout<<"Search complete."<<endl;
                Requests_Log(Access_User_Id(), where_to_search, data_to_search, Get_Date_Time() ); //Add to requests log
                break;
                }
        case 3: {
                Manage_Users_Menu();
                break;
                }
        case 4: {
                Manage_Inventory_Menu();
                break;
                }
        case 5: {
                View_Requests_Logs();
                break;
                }
        case 6: {
                View_Purchase_Recommendations();
                break;
                }
        case 7: {
                View_Borrow_Logs();
                break;
                }
        case 8: {
                break;
                }
        
        default:{
                cout<<"Invalid choice."<<endl;
                break;
                }
        }
    } while (selection!=stop);
    
    return;
}


