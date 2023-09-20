# OOPD_Assign2
This is a repository containing files for OOPD Assignment 2.

Command to run the program: 
```
g++ LMS.cpp functions.cpp classes.cpp -o LMS.exe
```

Command to run Makefile:

```
make 
```

## Structure and Protocols

-----Users----------------------------------------------------------------

1. Student:

    ****Login**** [STU12345, Password@1]

        -> Print Catalogue
        -> Search Inventory
        -> Borrow Items
        -> Recommend a Purchase


2. Faculty
   
    ****Login**** [FAC12345, Password@1]

       -> Print Catalogue
       -> Search Inventory
       -> Borrow Items
       -> Recommend a Purchase

3. Guest
  
        -> Print Catalogue
        -> Search Inventory

5. Library_Staff
 
    ****Login**** [EMP12345, Password@1]
   
        -> Print Catalogue
        -> Search Inventory
        -> Manage Users
              $ View Current Users
              $ Add New User
              $ Delete_User
        -> Manage Inventory
              $ Add New Item
              $ Delete Item
        -> View Requests Logs
        -> View Purchase Recommendations
        -> View Borrow Logs


----Items----------------------------------------------------

1. Books
   
    1.1 Physical_Copy
   
    1.2 Electronic_Copy
   
2. Magazines

   1.1 Physical_Copy

   1.2 Electronic_Copy
  
3. Journals

   1.1 Physical_Copy

   1.2 Electronic_Copy

4. Newspapers

   1.1 Physical_Copy

   1.2 Electronic_Copy

% Setup Files

    -> Library_Identifier is always the first column of any file



----Utility Functions--------------------------------

% Generate_Setup_Files

      -> Physical_Copy
      
              $ Library_Identifier
              $ Physical_Location
              $ Electronic_Copy_Available: Available/ Unavailable
              $ Issue_Status: Available/ Checked_out
              $ Checked_Out_Date_And_Time
              $ Issue Duration
          
      -> Electronic_Copy
      
              $ Library_Identifier
              $ Physical_Copy_Available: Available/ Unavailable
      


----Protocols-------------------------------- 

% User_ID
  
      -> Same as Institute Roll number for students and Employee ID for Faculty and Library_Staff
      -> Nomenclature: 3 upper case letters followed by a 5-digit number
          $ Student: STU12345
          $ Faculty: FAC12345
          $ Library_Staff: EMP12345
      -> Must be unique
      -> Must be present in the database (If getting logged in)

% Password

    -> 8-15 letters long
    -> Nomenclature: Must contain at least one letter, digit, and a special character
    

% Library_Identifier

    -> Nomenclature: 3 letters followed by a 5-digit number
    
        $ Physical_Copy: PHY12345
        $ Electronic_Copy: ELC12345
    
    -> Must be unique
    -> For Physical Copies: The 5-digit number is the stack number of the item in the library [Physical Location]
    
% Borrow_Items:

    -> Student: 1 month
    -> Faculty: 6 months
