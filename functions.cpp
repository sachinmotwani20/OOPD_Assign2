
//Header Files
#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit()
#include <windows.h> //To use Sleep() in windows 
#include <cstdlib> //To use random number generator

using namespace std;

#include "functions.h"

/*Definition of Functions*/

void Welcome()
{
    Sleep(1000); //Delay for 1 second
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Welcome to Library and Information Center"<<endl;
    cout<<"Indraprastha Institute of Information Technology-Delhi (IIIT-D)"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}   

string Generate_Library_Identifier(string copy_type, int& physical_location){
    string physical_location_string = to_string(physical_location);
    string library_identifier = copy_type + physical_location_string;
    
    //If library_identifier is already present in any file, increment physical_location and try again
    if (Check_File_Exists("Data/Modified/Electronic_Books.csv")){
        ifstream file("Data/Modified/Electronic_Books.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Physical_Books.csv")){
        ifstream file("Data/Modified/Physical_Books.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Electronic_Magazines.csv")){
        ifstream file("Data/Modified/Electronic_Magazines.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Physical_Magazines.csv")){
        ifstream file("Data/Modified/Physical_Magazines.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Electronic_Journals.csv")){
        ifstream file("Data/Modified/Electronic_Journals.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Physical_Journals.csv")){
        ifstream file("Data/Modified/Physical_Journals.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Electronic_Newspapers.csv")){
        ifstream file("Data/Modified/Electronic_Newspapers.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    if (Check_File_Exists("Data/Modified/Physical_Newspapers.csv")){
        ifstream file("Data/Modified/Physical_Newspapers.csv");
        string row;
        while(getline(file, row)){
            stringstream input_string(row);
            string data;
            int column_number = 0;
            if (column_number == 0){
                while(getline(input_string, data, ',')){
                    column_number++;
                    if (data==library_identifier){
                        physical_location++;
                        return Generate_Library_Identifier(copy_type, physical_location);
                    }
                }
            }
        }
        file.close();
    }

    physical_location++;
    return library_identifier;
}

bool Check_File_Exists(string file_path){
    ifstream file(file_path);
    return file.good();
}

bool Is_Valid_Library_Identifier(string& library_identifier){
    if (library_identifier.length() != 6) {
        return false;
    }
    if (toupper(library_identifier[0]) == 'E' || toupper(library_identifier[0]) == 'P') {
        if (islower(library_identifier[0])){
            library_identifier[0]=toupper(library_identifier[0]);
        }
        if (toupper(library_identifier[1]) == 'L' || toupper(library_identifier[1]) == 'H') {
            if (islower(library_identifier[1])){
                library_identifier[1]=toupper(library_identifier[1]);
            }
            if (toupper(library_identifier[2]) == 'C' || toupper(library_identifier[2]) == 'Y') {
                if (islower(library_identifier[2])){
                    library_identifier[2]=toupper(library_identifier[2]);
                }
                if (isdigit(library_identifier[3]) && isdigit(library_identifier[4]) && isdigit(library_identifier[5])) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Generate_Setup_Files(string original_books_file_path, string original_magazines_file_path, string original_journals_file_path, int& physical_location){
    //Generate CSVs
    ifstream book_original(original_books_file_path);
    ifstream magazine_original(original_magazines_file_path);
    ifstream journal_original(original_journals_file_path);

    // Check if the input file can be opened
    if (!book_original.is_open()) {
        cout << "Error opening input file: " << original_books_file_path << endl;
        cout<<"Please check if the file exists."<<endl;
        Exit_Protocol(); //Exit the program
    } else if (!magazine_original.is_open()) {
        cout << "Error opening input file: " << original_magazines_file_path << endl;
        cout<<"Please check if the file exists."<<endl;
        Exit_Protocol(); //Exit the program
    } else if (!journal_original.is_open()) {
        cout << "Error opening input file: " << original_journals_file_path << endl;
        cout<<"Please check if the file exists."<<endl;
        Exit_Protocol(); //Exit the program
    } else {
        cout<<"Setup in Progress..."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Electronic_Books.csv")) {        
        cout<<"Electronic_Books.csv already exists."<<endl;
    } else {
        ofstream book_electronic("Data/Modified/Electronic_Books.csv");
        string row;
        bool is_header = true;

        while(getline(book_original, row)) {
            
            if (is_header) {
                
                //Electronic Books
                book_electronic << "Library_Identifier" << ','; 
                book_electronic << row << ',';
                book_electronic << "Physical_Copy_Available" << endl; 
                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Electronic Books
            book_electronic << Generate_Library_Identifier("ELC", physical_location) << ","; //Library Identifier
            book_electronic << row << ","; 
            book_electronic << "Available" << endl; //Status

        }
        book_electronic.close();
        cout<<"Electronic_Books.csv generated."<<endl;
    }


    if (Check_File_Exists("Data/Modified/Physical_Books.csv")) {        
        cout<<"Physical_Books.csv already exists."<<endl;
    } else {
        ofstream book_physical("Data/Modified/Physical_Books.csv");
        string row;
        bool is_header = true;

        while(getline(book_original, row)) {
            
            if (is_header) {
                
                //Physical Books
                book_physical << "Library_Identifier" << ','; 
                book_physical << row << ','; 
                book_physical << "Electronic_Copy_Available" << ','; 
                book_physical << "Issue_Status" << ','; 
                book_physical << "Checked_Out_Date_And_Time" << ','; 
                book_physical << "Issue_Duration" << endl; 

                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Physical Books
            book_physical << Generate_Library_Identifier("PHY", physical_location) << ","; //Library Identifier
            book_physical << row << ","; //Paste the entire row
            book_physical << "Available" << ","; //Electronic Copy Status
            book_physical << "Available" << ","; //Issue Status
            book_physical << "N/A" << ","; //Checked Out Date and Time
            book_physical << "N/A" << endl; //Return Date and Time

        }
        book_physical.close();
        cout<<"Physical_Books.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Electronic_Magazines.csv")) {        
        cout<<"Electronic_Magazines.csv already exists."<<endl;
    } else {
        ofstream magazine_electronic("Data/Modified/Electronic_Magazines.csv");
        string row;
        bool is_header = true;

        while(getline(magazine_original, row)) {
            
            if (is_header) {
                
                //Electronic Magazines
                magazine_electronic << "Library_Identifier" << ','; 
                magazine_electronic << row << ',';
                magazine_electronic << "Physical_Copy_Available" << endl; 

                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Electronic Magazines
            magazine_electronic << Generate_Library_Identifier("ELC", physical_location) << ","; //Library Identifier
            magazine_electronic << row << ","; 
            magazine_electronic << "Available" << endl; //Status

        }
        magazine_electronic.close();
        cout<<"Electronic_Magazines.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Physical_Magazines.csv")) {        
        cout<<"Physical_Magazines.csv already exists."<<endl;
    } else {
        ofstream magazine_physical("Data/Modified/Physical_Magazines.csv");
        string row;
        bool is_header = true;

        while(getline(magazine_original, row)) {
            
            if (is_header) {
                
                //Physical Magazines
                magazine_physical << "Library_Identifier" << ','; 
                magazine_physical << row << ','; 
                magazine_physical << "Electronic_Copy_Available" << ','; 
                magazine_physical << "Issue_Status" << ','; 
                magazine_physical << "Checked_Out_Date_And_Time" << ','; 
                magazine_physical << "Issue_Duration" << endl; 

                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Physical Magazines 
            magazine_physical << Generate_Library_Identifier("PHY", physical_location) << ","; //Library Identifier
            magazine_physical << row << ","; //Paste the entire row
            magazine_physical << "Available" << ","; //Electronic Copy Status
            magazine_physical << "Available" << ","; //Issue Status
            magazine_physical << "N/A" << ","; //Checked Out Date and Time
            magazine_physical << "N/A" << endl; //Return Date and Time

        }
        magazine_physical.close();
        cout<<"Physical_Magazines.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Electronic_Journals.csv")) {        
        cout<<"Electronic_Journals.csv already exists."<<endl;
    } else {
        ofstream journal_electronic("Data/Modified/Electronic_Journals.csv");
        string row;
        bool is_header = true;

        while(getline(journal_original, row)) {
            
            if (is_header) {
                
                //Electronic Journals
                journal_electronic << "Library_Identifier" << ','; 
                journal_electronic << "Topic" << ',';
                journal_electronic << "Physical_Copy_Available" << endl; 

                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Electronic Journals
            journal_electronic << Generate_Library_Identifier("ELC", physical_location) << ","; //Library Identifier
            journal_electronic << row << ","; 
            journal_electronic << "Available" << endl; //Status

        }
        journal_electronic.close();
        cout<<"Electronic_Journals.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Physical_Journals.csv")) {        
        cout<<"Physical_Journals.csv already exists."<<endl;
    } else {
        ofstream journal_physical("Data/Modified/Physical_Journals.csv");
        string row;
        bool is_header = true;

        while(getline(journal_original, row)) {
            
            if (is_header) {
                
                //Physical Journals
                journal_physical << "Library_Identifier" << ','; 
                journal_physical << "Topic" << ',';
                journal_physical << "Electronic_Copy_Available" << ','; 
                journal_physical << "Issue_Status" << ','; 
                journal_physical << "Checked_Out_Date_And_Time" << ','; 
                journal_physical << "Issue_Duration" << endl; 

                is_header = false;
                continue;
            }

            string temp_string = ""; //Empty string for temporarily storing non-string data types
            stringstream input_string(row); //To parse the data read into the string
            
            //Physical Journals
            journal_physical << Generate_Library_Identifier("PHY", physical_location) << ","; //Library Identifier
            journal_physical << row << ","; //Paste the entire row
            journal_physical << "Available" << ","; //Electronic Copy Status
            journal_physical << "Available" << ","; //Issue Status
            journal_physical << "N/A" << ","; //Checked Out Date and Time
            journal_physical << "N/A" << endl; //Return Date and Time

        }
        journal_physical.close();
        cout<<"Physical_Journals.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Electronic_Newspaper.csv")){
        cout<<"Electronic_Newspaper.csv already exists."<<endl;
    } else {
        ofstream newspaper_electronic("Data/Modified/Electronic_Newspaper.csv");
        
        newspaper_electronic << "Library_Identifier" << ','; 
        newspaper_electronic << "Name" << ',';
        newspaper_electronic << "Physical_Copy_Available" << endl; 
        
        newspaper_electronic.close();

        cout<<"Electronic_Newspaper.csv generated."<<endl;
    }

    if (Check_File_Exists("Data/Modified/Physical_Newspaper.csv")){
        cout<<"Physical_Newspaper.csv already exists."<<endl;
    } else {
        ofstream newspaper_physical("Data/Modified/Physical_Newspaper.csv");
        
        //Physical Newspaper
        newspaper_physical << "Library_Identifier" << ','; 
        newspaper_physical << "Name" << ',';
        newspaper_physical << "Electronic_Copy_Available" << ','; 
        newspaper_physical << "Issue_Status" << ','; 
        newspaper_physical << "Checked_Out_Date_And_Time" << ','; 
        newspaper_physical << "Issue_Duration" << endl; 
        
        newspaper_physical.close();
        cout<<"Physical_Newspaper.csv generated."<<endl;
    }

}

string Create_Login_Credentials(string user_type, string user_id, string password){
    string login_credentials = user_type + ',' + user_id + ',' + password;
    return login_credentials;
}

void Generate_Login_Credentials(){
    if (Check_File_Exists("Data/Login_Credentials.csv")) {        
        cout<<"Login_Credentials.csv already exists."<<endl;
    } else {
        ofstream login_credentials("Data/Login_Credentials.csv");
        string row;
    
              
        //Header Row
        login_credentials << "User_Type" << ',';
        login_credentials << "User_Id" << ',';
        login_credentials << "Password" << endl; 
 
        //Student Login Credentials         
        login_credentials << Create_Login_Credentials("STU", "STU12345", "Password@1") << endl; 

        //Faculty Login Credentials
        login_credentials << Create_Login_Credentials("FAC", "FAC12345", "Password@1") << endl;

        //Library Staff Login Credentials
        login_credentials << Create_Login_Credentials("EMP", "EMP12345", "Password@1") << endl; 

        login_credentials.close();
        cout<<"Login_Credentials.csv generated."<<endl;
    }
}

void Generate_Purchase_Recommendations(){
    if (Check_File_Exists("Data/Purchase_Recommendations.csv")) {        
        cout<<"Purchase_Recommendations.csv already exists."<<endl;
    } else {
        ofstream purchase_recommendations("Data/Purchase_Recommendations.csv");
        string row;
    
              
        //Header Row
        purchase_recommendations << "User_Id" << ',';
        purchase_recommendations << "Date & Time" << ',';
        purchase_recommendations << "Item Type" << ',';
        purchase_recommendations << "Item Name" << ',';
        purchase_recommendations << "Item Author"<<',';
        purchase_recommendations << "Item Publisher"<<',';
        purchase_recommendations << "Item ISBN"<<endl;

        purchase_recommendations.close();
        cout<<"Purchase_Recommendations.csv generated."<<endl;
    }
}

void Generate_Borrow_Record(){
    if (Check_File_Exists("Data/Borrow_Record.csv")) {        
        cout<<"Borrow_Record.csv already exists."<<endl;
    } else {
        ofstream borrow_record("Data/Borrow_Record.csv");
        string row;
    
              
        //Header Row
        borrow_record << "User_Id" << ',';
        borrow_record << "Issue Date & Time" << ',';
        borrow_record << "Issue Duration" << ',';
        borrow_record << "Library Identifier of the Issued Item" << ',';

        borrow_record.close();
        cout<<"Borrow_Record.csv generated."<<endl;
    }
}


bool Is_Valid_Choice(string& input, int start, int stop){

    int decimal_count = 0; //For checking any decimal point
    bool digit_found = false; //For checking if any non-digit entity is entered

    for (char c : input) { //Run though the 'for' loop for every character in the string 'input' 
        if (isdigit(c)) {
            digit_found = true;
        } else if (c == '.') {
            decimal_count++;
            if (decimal_count > 0) {
                cout<<"Decimal point found. Choice must be a whole number."<<endl;
                return false; 
            }
        } else if (c == '-') {
            cout<<"Negative choice found. Choice must be a whole number."<<endl;
            return false;      
        } else {
            cout<<"Invalid character(s) found. Choice must be a whole number."<<endl;
            return false; 
        }
    }

    if (!digit_found) {
        cout<<"No digits found."<<endl;
        return false; // No digits found
    }

    int value = stoi(input);
    return ((value >= start) && (value<=stop)); // Check if value is greater than start and less than stop

}

int Get_Valid_Choice(int start, int stop){
    string choice;
    while (true) {
        cout << "Choice: ";
        getline(cin, choice); 

        if (Is_Valid_Choice(choice, start, stop)) {
            return stoi(choice);
        } else {
            cout << "Invalid input. Please enter a valid choice in digits (between "<<start<<" & "<<stop<<") only." << endl;
        }
    }
}

void Print_Items(string File_Name){
    ifstream file(File_Name);

    if (!file.is_open()) {
        cout<<"Error: File '"<<File_Name<<"' not found."<<endl;
        return;
    }

    string row;
    int row_number = 0;
    while (getline(file, row)) {
        row_number++;
        stringstream input_string(row);
        string data;
        int column_number = 0;
        while (getline(input_string, data, ',')) {
            column_number++;
            if (column_number == 1) {
                cout<<row_number<<". "<<data<<endl;
            }
        }
    }
    file.close();
    return;
    
}



void Print_Catalogue_Menu(){
    int option, electronic_or_not;
    cout<<"Welcome to the Catalogue Menu."<<endl;
    cout<<"What would you like to surf (A list will be printed)?"<<endl;
    cout<<"1. Books"<<endl;
    cout<<"2. Journals"<<endl;
    cout<<"3. Magazines"<<endl;
    cout<<"4. Newspapers"<<endl;
    cout<<"5. Exit Menu"<<endl;
    option = Get_Valid_Choice(1,5);
    switch (option) {
        case 1: { 
                cout<<"You have selected 'books'."<<endl;
                cout<<"Do you want to see the list of available electronic or physical books?"<<endl;
                cout<<"1. Electronic"<<endl;
                cout<<"2. Physical"<<endl;
                electronic_or_not = Get_Valid_Choice(1,2);
                switch (electronic_or_not) {
                    case 1: { 
                            Print_Items("Electronic_Books.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    case 2: { 
                            Print_Items("Physical_Books.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    default: 
                        cout<<"Invalid choice."<<endl;
                        break;
                    }
                break;
                }
        case 2: { 
                cout<<"You have selected 'journals'."<<endl;
                cout<<"Do you want to see the list of available electronic or physical journals?"<<endl;
                cout<<"1. Electronic"<<endl;
                cout<<"2. Physical"<<endl;
                electronic_or_not = Get_Valid_Choice(1,2);
                switch (electronic_or_not) {
                    case 1: { 
                            Print_Items("Electronic_Journals.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    case 2: { 
                            Print_Items("Physical_Journals.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    default: 
                        cout<<"Invalid choice."<<endl;
                        break;
                    }
                break;
                }
        case 3: { 
                cout<<"You have selected 'magazines'."<<endl;
                cout<<"Do you want to see the list of available electronic or physical magazines?"<<endl;
                cout<<"1. Electronic"<<endl;
                cout<<"2. Physical"<<endl;
                electronic_or_not = Get_Valid_Choice(1,2);
                switch (electronic_or_not) {
                    case 1: { 
                            Print_Items("Electronic_Magazines.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    case 2: { 
                            Print_Items("Physical_Magazines.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    default: 
                        cout<<"Invalid choice."<<endl;
                        break;
                    }
                break;
                }
        case 4: { 
                cout<<"You have selected 'newspapers'."<<endl;
                cout<<"Do you want to see the list of available electronic or physical newspapers?"<<endl;
                cout<<"1. Electronic"<<endl;
                cout<<"2. Physical"<<endl;
                electronic_or_not = Get_Valid_Choice(1,2);
                switch (electronic_or_not) {
                    case 1: { 
                            Print_Items("Electronic_Newspapers.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    case 2: { 
                            Print_Items("Physical_Newspapers.csv");
                            cout<<"List ends here."<<endl;
                            break;
                            }
                    default: 
                        cout<<"Invalid choice."<<endl;
                        break;
                    }
                break;
                }
        case 5: { 
                cout<<"Exiting Catalogue Menu."<<endl;
                break;
                }
        default: 
            cout<<"Invalid choice."<<endl;
            break;
        }
}

string Get_Search_File(){
    int option;
    while (true){
        cout<<"What would you like to search in?"<<endl;
        cout<<"1. Books"<<endl;
        cout<<"2. Journals"<<endl;
        cout<<"3. Magazines"<<endl;
        cout<<"4. Newspapers"<<endl;
        option = Get_Valid_Choice(1,4);
        switch (option) {
            case 1: { 
                    cout<<"You have selected 'books'."<<endl;
                    cout<<"Do you want to search in the list of available electronic or physical books?"<<endl;
                    cout<<"1. Electronic"<<endl;
                    cout<<"2. Physical"<<endl;
                    if (Get_Valid_Choice(1,2) == 1) {
                        return "Data/Modified/Electronic_Books.csv";
                    } else {
                        return "Data/Modified/Physical_Books.csv";
                    }
                    break;
                    }
            case 2: { 
                    cout<<"You have selected 'journals'."<<endl;
                    cout<<"Do you want to search in the list of available electronic or physical journals?"<<endl;
                    cout<<"1. Electronic"<<endl;
                    cout<<"2. Physical"<<endl;
                    if (Get_Valid_Choice(1,2) == 1) {
                        return "Data/Modified/Electronic_Journals.csv";
                    } else {
                        return "Data/Modified/Physical_Journals.csv";
                    }
                    break;
                    }
            case 3: { 
                    cout<<"You have selected 'magazines'."<<endl;
                    cout<<"Do you want to search in the list of available electronic or physical magazines?"<<endl;
                    cout<<"1. Electronic"<<endl;
                    cout<<"2. Physical"<<endl;
                    if (Get_Valid_Choice(1,2) == 1) {
                        return "Data/Modified/Electronic_Magazines.csv";
                    } else {
                        return "Data/Modified/Physical_Magazines.csv";
                    }
                    break;
                    }
            case 4: { 
                    cout<<"You have selected 'newspapers'."<<endl;
                    cout<<"Do you want to search in the list of available electronic or physical newspapers?"<<endl;
                    cout<<"1. Electronic"<<endl;
                    cout<<"2. Physical"<<endl;
                    if (Get_Valid_Choice(1,2) == 1) {
                        return "Data/Modified/Electronic_Newspapers.csv";
                    } else {
                        return "Data/Modified/Physical_Newspapers.csv";
                    }
                    break;
                    }
            default: 
                cout<<"Invalid choice."<<endl;
                return "";
                break;
            }
        }

    return "";
    
}

string Get_Search_Column(string File_Name){
    if (File_Name=="Data/Modified/Electronic_Books.csv"){
        cout<<"What would you like to search by?"<<endl;
        cout<<"1. Title"<<endl;
        cout<<"2. Author"<<endl;
        cout<<"3. ISBN"<<endl;        
        int choice = Get_Valid_Choice(1,3);
        switch(choice){
            case 1: return "title";
            case 2: return "authors";
            case 3: return "isbn";
        }
    } else if (File_Name=="Data/Modified/Physical_Books.csv"){
        cout<<"What would you like to search by?"<<endl;
        cout<<"1. Title"<<endl;
        cout<<"2. Author"<<endl;
        cout<<"3. ISBN"<<endl;             
        int choice = Get_Valid_Choice(1,3);
        switch(choice){
            case 1: return "title";
            case 2: return "authors";
            case 3: return "isbn";
        }
    } else if (File_Name=="Data/Modified/Electronic_Journals.csv"){
        return "Topic";
    } else if (File_Name=="Data/Modified/Physical_Journals.csv"){
        return "Topic";
    } else if (File_Name=="Data/Modified/Electronic_Magazines.csv"){
        return "publication";
    } else if (File_Name=="Data/Modified/Physical_Magazines.csv"){
        return "publication";
    } else if (File_Name=="Data/Modified/Electronic_Newspapers.csv"){
        return "Name";
    } else if (File_Name=="Data/Modified/Physical_Newspapers.csv"){
        return "Name";
    } else {
        cout<<"Error: File '"<<File_Name<<"' not found."<<endl;
        return "";
    }

}

string Get_Search_Item(){
    string search_item;
    cout<<"Enter the search term: ";
    getline(cin, search_item);
    return search_item;
}


void Search_Inventory(string File_Name,  string Search_Column, string Search_Term){

    ifstream file(File_Name);

    if (!file.is_open()) {
        cout<<"Error: File '"<<File_Name<<"' not found."<<endl;
        return;
    }

    string row, row_header;
    int row_number = 0;
    int found=0;
    bool header_printed=false;

    while (getline(file, row)) {
        if (row_number==0){
            row_header=row;
        }
        row_number++;
        stringstream input_string(row);
        string data;
        int column_number = 0;
        while (getline(input_string, data, ',')) {
            column_number++;
            if (column_number == 1) {
                if (data == Search_Term) {
                    if (header_printed==false){
                        cout<<"Search Results:"<<endl;
                        cout<< row_header <<endl;
                        header_printed=true;
                    }
                    cout<<row_number<<". "<<row<<endl;
                    found++;
                }
            }
        }
    }
    if (found==0){
        cout<<"No results found."<<endl;
    } else {
        cout<<"Found "<<found<<" result(s)."<<endl;
    }
    file.close();        
}

string Get_Date_Time(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string Date_Time = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return Date_Time;
}

void Requests_Log(string User_Id,string File_Name,  string Search_Column, string Search_Term, string Date_Time){
    
    if (Check_File_Exists("Data/Requests_Log.csv")) {        
        ofstream file("Data/Requests_Log.csv", ios::app);
        file<<User_Id<<","<<File_Name<<","<<Search_Column<<","<<Search_Term<<","<<Date_Time<<endl;
        file.close();
    } else {
        ofstream file("Data/Requests_Log.csv");
        file<<"User_Id"<<","<<"File_Name"<<","<<"Search_Column"<<","<<"Search_Term"<<","<<"Date_Time"<<endl;
        file<<User_Id<<","<<File_Name<<","<<Search_Column<<","<<Search_Term<<","<<Date_Time<<endl;
        file.close();
    }

    cout<<"The query has been logged."<<endl;
}


string Get_Library_Identifier(){
    string Library_Identifier;
    while (true) {
        cout<<"Enter the Library Identifier: ";
        getline(cin, Library_Identifier);
        if (Is_Valid_Library_Identifier(Library_Identifier)) {
            break;
        } else {
            cout<<"Invalid Library Identifier. Please enter a valid Library Identifier."<<endl;
        }
    }
    return Library_Identifier;
}

bool Is_Present_In_File(string File_Name, string Library_Identifier){
    ifstream file(File_Name);

    if (!file.is_open()) {
        cout<<"Error: File '"<<File_Name<<"' not found."<<endl;
        return false;
    }

    string row;
    while (getline(file, row)) {
        stringstream input_string(row);
        string data;
        while (getline(input_string, data, ',')) {
                if (data == Library_Identifier) {
                    file.close();
                    return true;
                }
            }
    }
    file.close();
    return false;
}


string Find_File(string library_identifier){
    string File_EBook = "Data/Modified/Electronic_Books.csv";
    string File_PBook = "Data/Modified/Physical_Books.csv";
    string File_EJournal = "Data/Modified/Electronic_Journals.csv";
    string File_PJournal = "Data/Modified/Physical_Journals.csv";
    string File_EMagazine = "Data/Modified/Electronic_Magazines.csv";
    string File_PMagazine = "Data/Modified/Physical_Magazines.csv";
    string File_ENewspaper = "Data/Modified/Electronic_Newspapers.csv";
    string File_PNewspaper = "Data/Modified/Physical_Newspapers.csv";

    if (Is_Present_In_File(File_EBook, library_identifier)){
        return File_EBook;
    } else if (Is_Present_In_File(File_PBook, library_identifier)){
        return File_PBook;
    } else if (Is_Present_In_File(File_EJournal, library_identifier)){
        return File_EJournal;
    } else if (Is_Present_In_File(File_PJournal, library_identifier)){
        return File_PJournal;
    } else if (Is_Present_In_File(File_EMagazine, library_identifier)){
        return File_EMagazine;
    } else if (Is_Present_In_File(File_PMagazine, library_identifier)){
        return File_PMagazine;
    } else if (Is_Present_In_File(File_ENewspaper, library_identifier)){
        return File_ENewspaper;
    } else if (Is_Present_In_File(File_PNewspaper, library_identifier)){
        return File_PNewspaper;
    } else {
        return "";
    }

    return "";
    
}

string Get_Issue_Duration(string u_id, string l_identifier){
    if (l_identifier[0]=='E') {//Electronic Item
        return "N/A";
    } else { //Physical Item
        if (u_id[0]=='S'){//Student
            return "1 Month";
        } else { //Faculty
            return "6 Months";
        }
    } 

    return "1 Month";
}

void Update_Borrow_Record(string u_id, string issue_d_t, string issue_duration, string l_identifier){
    if (Check_File_Exists("Data/Borrow_Record.csv")) {        
        ofstream file("Data/Borrow_Record.csv", ios::app);
        file<<u_id<<","<<issue_d_t<<","<<issue_duration<<","<<l_identifier<<endl;
        file.close();
    } else {
        ofstream file("Data/Borrow_Record.csv");
        file<<"User_Id"<<","<<"Issue_Date_And_Time"<<","<<"Issue_Duration"<<","<<"Library_Identifier"<<endl;
        file<<u_id<<","<<issue_d_t<<","<<issue_duration<<","<<l_identifier<<endl;
        file.close();
    }
}

void Update_Borrowed_Item_File(string u_id,  string i_d_t, string i_duration, string l_identifier, string f_name){
    ifstream file1(f_name);
    ofstream file2("Data/temp.csv"); 

    if (!file1.is_open()) {
        cout << "Error opening user database file: " << f_name << endl;
    }

    if (l_identifier[0]=='E'){
        return ;
    } 

    else{
        string row;
        string row_number=0;
        while (getline(file1, row)){
            stringstream input_string(row);
            string data;
            while (getline(input_string, data, ',')) {
                if (data == l_identifier) {
                    file2<<l_identifier<<",";
                    if (f_name=="Data/Modified/Physical_Books.csv"){
                        string temp;
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //book_id
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //goodreads_book_id
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //best_book_id
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //work_id
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //books_count
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //isbn
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //isbn13
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //authors
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //original_publication_year
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //original_title
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //title
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //language_code
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //average_rating
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_count
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //work_ratings_count
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //work_text_reviews_count
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_1
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_2
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_3
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_4
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //ratings_5
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //image_url
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //small_image_url
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Electronic_Copy_Available
                        getline(input_string, temp, ',');
                        file2<<"Checked Out"<<","; //Issue_Status
                        getline(input_string, temp, ',');
                        file2<<i_d_t<<","; //Checked_Out_Date_And_Time
                        getline(input_string, temp, ',');
                        file2<<i_duration<<endl; //Issue_Duration
                    }
                    else if (f_name=="Data/Modified/Physical_Journals.csv"){
                        string temp;
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Topic
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Electronic_Copy_Available
                        getline(input_string, temp, ',');
                        file2<<"Checked Out"<<","; //Issue_Status
                        getline(input_string, temp, ',');
                        file2<<i_d_t<<","; //Checked_Out_Date_And_Time
                        getline(input_string, temp, ',');
                        file2<<i_duration<<endl; //Issue_Duration
                    }
                    else if (f_name=="Data/Modified/Physical_Magazines.csv"){
                        string temp;
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Publication
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //rank
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //totalPaid
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //wordRate
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //daysToBePaid
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //paymentDifficulty
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //rank_totalPaid
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //rank_wordRate
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //rank_daysToBePaid
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //rank_paymentDifficulty
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Electronic_Copy_Available
                        getline(input_string, temp, ',');
                        file2<<"Checked Out"<<","; //Issue_Status
                        getline(input_string, temp, ',');
                        file2<<i_d_t<<","; //Checked_Out_Date_And_Time
                        getline(input_string, temp, ',');
                        file2<<i_duration<<endl; //Issue_Duration
                    }
                    else { //Physical Newspaper
                        string temp;
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Name
                        getline(input_string, temp, ',');
                        file2<<temp<<","; //Electronic_Copy_Available
                        getline(input_string, temp, ',');
                        file2<<"Checked Out"<<","; //Issue_Status
                        getline(input_string, temp, ',');
                        file2<<i_d_t<<","; //Checked_Out_Date_And_Time
                        getline(input_string, temp, ',');
                        file2<<i_duration<<endl; //Issue_Duration
                    }
                } else {
                    file2<<row<<endl;
                }
            }
        }
    }

    file1.close();
    file2.close();
    remove(f_name.c_str());
    rename("Data/temp.csv", f_name.c_str());

    cout<<"Borrow Successful. Happy Reading!"<<endl;        
}

void View_Borrow_Logs(){
    ifstream file("Data/Borrow_Record.csv");

    if (!file.is_open()) {
        cout<<"Error: File 'Data/Borrow_Record.csv' not found."<<endl;
        return;
    }

    string row;
    while (getline(file, row)) {
        cout<<row<<endl;
    }
    file.close();
    return;
}

void Exit_Protocol(){
    Sleep(1000); //Delay for 1 second
    cout<<"Thank you for using the Library and Information Center of IIIT-Delhi."<<endl;
    cout<<"Hope you let us serve you again soon. Toodles!"<<endl;
    Sleep(2000); //Delay for 2 seconds
    abort(); //Exit the program
}
