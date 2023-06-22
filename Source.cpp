#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h> 
using namespace std;



//Declaring variale
string  username, pass, mail;
char  Response;
int option, numCourse, numstd;
string cCode, cTitle, cInstructor, cSchedule;
string fName, lName, cId, sId;
int i = 0, j;

struct Course {
    string courseCode, courseTitle, courseInstructor, courseSchedule;
};
struct Student {
    string firstName, lastName, courseId, studentId, email, password;
};


void title();
void admin_logOut();
void admin_exit();
void admin_main_menu();
void AddCourseData();
void CourseDetails();
void Student_reg();
void Student_Data();
void CompanyDetails();
void course_search();
void student_search();
void UpdateCourseData();



int main() {

    title();
    cout << "\n\n\t  First You must login to gain access....." << endl;
    cout << "\n\n\t\t1. Login" << endl;
    cout << "\t\t2. View Company Details" << endl;
    cout << "\t\t3. Exit" << endl;
    cout << "\n\n\t\tChoose an option: ";
    cin >> option;

    switch (option) {
    case 1:
        cout << "\n\n\t\tUsername: ";
        cin >> username;
        cout << "\t\tPassword: ";
        char ch;
        pass = "";
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') { // Handle backspace
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b"; // Erase the last character
                }
            }
            else {
                pass.push_back(ch);
                cout << '*'; // Display an asterisk instead of the actual character
            }
        }
        if (username == "admin" && pass == "1234")
        {
            printf("\033[32m ");
            cout << "\n\n\t\tYou Successfully Logged In " << endl;
            printf("\033[0m ");

            system("pause");
            system("cls");
            admin_main_menu();
        }

        else {
            cout << "\n\n\t\t";
            printf("\033[31m Invalid Username or password\n");
            printf("\033[0m ");
            system("pause");
            system("cls");
            main();
        }
        break;

    case 2:

        CompanyDetails();
        break;

    case 3:
        cout << "\n\tDo you want exit? (y/n) : ";
        cin >> Response;

        if (Response == 'Y' || Response == 'y')//start Selection
        {
            cout << "\n\n\t\t\t----------------------------- " << endl;
            cout << "\t\t\tThank you for joining with us " << endl;
            cout << "\t\t\t----------------------------- \n\n" << endl;
            exit(1);

        }
        else
        {
            system("cls");
            main();
        }

    default:
        printf("\033[41m \t\tInvalid Input!\n");
        printf("\033[0m ");
        cout << "\n\n\t\t" << endl;

        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        system("pause");
        system("cls");
        main();
        break;
    }
}
void title() {
    cout << "\t\t* ========================================================== *" << endl;
    cout << "\t\t|                                                            |" << endl;
    cout << "\t\t|                         WELCOME TO                         |" << endl;
    cout << "\t\t|-----------------||Master Mind Institute||------------------|" << endl;
    cout << "\t\t|                                                            |" << endl;
    cout << "\t\t* ========================================================== *" << endl;
    cout << endl;
    cout << endl;
}

void CompanyDetails() {
    system("cls");
    title();
    cout << "\n\n\n\t\t  | O |                                     | O |" << endl;
    cout << "\t\t  |   |- - - - - - - - - - - - - - - - - - -|   |" << endl;
    cout << "\t\t  | O |                                     | O |" << endl;
    cout << "\t\t  |   |        Welcome to Master Mind       |   |" << endl;
    cout << "\t\t  | O |                                     | O |" << endl;
    cout << "\t\t  |   |    Address: No.120, Colombo Road,   |   |" << endl;
    cout << "\t\t  | O |             Dehiwala, Srilanka.     | O |" << endl;
    cout << "\t\t  |   |                                     |   |" << endl;
    cout << "\t\t  | O |         Phone: 0117627353           | O |" << endl;
    cout << "\t\t  |   |                                     |   |" << endl;
    cout << "\t\t  | O |     Email: materMaind@email.com     | O |" << endl;
    cout << "\t\t  |   |                                     |   |" << endl;
    cout << "\t\t  | O |      Website: masaterMaind.lk       | O |" << endl;
    cout << "\t\t  |   |                                     |   |" << endl;
    cout << "\t\t  | O |- - - - - - - - - - - - - - - - - - -| O |" << endl;
    cout << "\t\t  |   |                                     |   |" << endl;
    cout << "\n\n\t\tGo back to main menu(y/n)-";
    cin >> Response;
    if (Response == 'y' || Response == 'Y')
    {
        system("pause");
        system("cls");
        main();//calling function

    }
    else  if (Response == 'n' || Response == 'N')
    {
        system("cls");
        title();
        CompanyDetails();
    }
    else
    {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m GO Back to Main Menu ");
        system("pause");
        system("cls");
        main();//calling function
    }
}

void admin_main_menu() {

    title();
    cout << "\n\n\t\t------------------ | Main Menu |---------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\tSelect Your Option here " << endl;
    cout << endl;
    cout << "\n\t\t\t1).Add Course Details " << endl;
    cout << "\n\t\t\t2).View All Training Program " << endl;
    cout << "\n\t\t\t3).Student Registration " << endl;
    cout << "\n\t\t\t4).View Student Details " << endl;
    cout << "\n\t\t\t5).Search Course Details " << endl;
    cout << "\n\t\t\t6).Search Student Details " << endl;
    cout << "\n\t\t\t7).log out " << endl;
    cout << "\n\t\t\t8).Exit " << endl;


    cout << "\n\t\t\tInput your option: ";
    cin >> option;

    switch (option) {
    case 1:
        system("cls");
        title();
        AddCourseData();

        printf("\033[32m ");
        cout << "\n\t\tSuccsessfully Added Course Details..!!" << endl;
        printf("\033[0m ");
        cout << "\nBack to Main Menu ";


        system("pause");
        system("cls");
        admin_main_menu();
        break;

    case 2:

        CourseDetails();
        break;

    case 3:

        Student_reg();
        break;

    case 4:

        Student_Data();
        break;

    case 5:

        course_search();
        break;

    case 6:

        student_search();
        break;

    case 7:

        admin_logOut();
        break;

    case 8:

        admin_exit();
        break;

    default:
        printf("\033[41m \t\tInvalid Input!\n");
        printf("\033[0m ");

        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        system("pause");
        system("cls");
        admin_main_menu();
        break;
    }

    //  return 0;
}

void admin_exit() {

    cout << "\n\tDo you want exit? (y/n) : ";
    cin >> Response;

    if (Response == 'Y' || Response == 'y')//start Selection
    {
        exit(1);
    }
    else
    {
        system("cls");
        admin_main_menu();
    }
}

void admin_logOut() {


    cout << "\n\t\t Do you realy want to log out (y/n): ";
    cin >> Response;

    if (Response == 'Y' || Response == 'y')//start Selection
    {
        system("cls");
        main();//calling function

    }
    else
    {
        system("cls");
        admin_main_menu();
    }
}

void AddCourseData() {
    system("cls");
    title();

    cout << "\n\t\t--------------Add Course Details-----------------" << endl;
    cout << "\n\n\t\t\tHow many Courses do you want to add -  ";
    cin >> numCourse;

    if (!cin.good() || numCourse <= 0) {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m ");
        cin.clear();
        cin.ignore();
        system("pause");
        system("cls");
        AddCourseData();
    }
    else {
        ofstream outFile("CourseData.txt", ios::app);
        if (!outFile.is_open()) {
            // Error opening file code
        }
        else {
            for (int i = 0; i < numCourse; i++) {
                Course course;

                cout << "\n\t\tEnter course code: ";
                cin >> course.courseCode;

                // Check if course code already exists
                ifstream inFile("CourseData.txt");
                string existingCode;
                bool codeExists = false;

                while (getline(inFile, existingCode)) {
                    if (existingCode == course.courseCode) {
                        codeExists = true;
                        break;
                    }
                }

                inFile.close();

                if (codeExists) {
                    cout << "\n\t\tCourse code already exists. Please enter a different code." << endl;
                    i--; // Decrement i to repeat the iteration and ask for a different code
                    continue;
                }

                outFile << course.courseCode << endl;

                cout << "\t\tEnter course title: ";
                cin.ignore();
                getline(cin, course.courseTitle);
                outFile << course.courseTitle << endl;

                cout << "\t\tEnter course instructor: ";
                cin >> course.courseInstructor;
                outFile << course.courseInstructor << endl;

                cout << "\t\tEnter course time duration: ";
                cin.ignore();
                getline(cin, course.courseSchedule);
                outFile << course.courseSchedule << endl;
            }

            outFile.close();

            // Success message and menu navigation code
        }
    }
}

void CourseDetails() {
    system("cls");
    title();
    cout << "\n\t\t-------------- Course Details -----------------" << endl;

    // filestream variable file
    ifstream infile;
    infile.open("CourseData.txt", ios::in);// open file for read


    // Check if file is empty
    if (infile.peek() == ifstream::traits_type::eof()) {
        cout << "\n\tData Not Found!\n" << endl;
    }
    else {
        // Read data from file
        infile >> cCode >> cTitle >> cInstructor >> cSchedule;
        while (!infile.eof()) {
            // Display course data
            cout << "\n\t\tCode:" << cCode << endl;
            infile >> cCode;
            cout << "\t\tCourse title:" << cTitle << endl;
            infile >> cTitle;
            cout << "\t\tInstructor:" << cInstructor << endl;
            infile >> cInstructor;
            cout << "\t\tCourse time duration:" << cSchedule << endl;
            infile >> cSchedule;
        }
    }

    // Close the opened file
    infile.close();


    cout << "\n\tGo back to main menu(y/n)- ";
    cin >> Response;
    if (Response == 'y' || Response == 'Y')
    {
        system("pause");
        system("cls");
        admin_main_menu();
    }
    else  if (Response == 'n' || Response == 'N')
    {
        system("cls");
        title();
        CourseDetails();
    }
    else
    {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m GO Back to Main Menu ");
        system("pause");
        system("cls");
        admin_main_menu();
    }
}

void Student_reg() {
    system("cls");
    title();

    cout << "\n\t\t--------------Student Registration Form-----------------" << endl;
    cout << "\n\n\t\t\tHow many student do you want to register -  ";
    cin >> numstd;

    if (!cin.good() || numstd <= 0) {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m ");
        cin.clear();
        cin.ignore();
        system("pause");
        system("cls");
        Student_reg();
    }
    else {
        ofstream outFile("StudentData.txt", ios::app); // open file in append mode
        if (!outFile.is_open()) {
            cout << "\n\t\tError opening file for writing." << endl;
            return;
            cout << "\n\tGo back to main menu(y/n)- ";
            cin >> Response;
            if (Response == 'y' || Response == 'Y')
            {
                system("pause");
                system("cls");
                admin_main_menu();
            }
            else  if (Response == 'n' || Response == 'N') {
                system("cls");
                title();
                Student_reg();
            }
            else
            {
                printf("\033[41m \t\tInvalid Input!");
                printf("\033[0m GO Back to Main Menu  ");
                system("pause");
                system("cls");
                admin_main_menu();
            }
        }
        else {
            for (int i = 0; i < numstd; i++) {
                Student student;

                cout << "\n\t\tEnter Student ID: ";
                cin >> student.studentId;

                // Check if student ID already exists
                ifstream inFile("StudentData.txt");
                string existingID;
                bool idExists = false;

                while (getline(inFile, existingID)) {
                    if (existingID == student.studentId) {
                        idExists = true;
                        break;
                    }
                }

                inFile.close();

                if (idExists) {
                    cout << "\n\t\tStudent ID already exists. Please enter a different ID." << endl;
                    i--; // Decrement i to repeat the iteration and ask for a different ID
                    continue;
                }

                outFile << student.studentId << endl;

                cout << "\t\tEnter first name: ";
                cin >> student.firstName;
                outFile << student.firstName << endl;

                cout << "\t\tEnter last name: ";
                cin.ignore();
                getline(cin, student.lastName);
                outFile << student.lastName << endl;

                cout << "\t\tEnter course code: ";
                getline(cin, student.courseId);
                outFile << student.courseId << endl;

                cout << "\t\tEnter email: ";
                getline(cin, student.email);
                outFile << student.email << endl;

                cout << "\t\tEnter password: ";
                getline(cin, student.password);
                outFile << student.password << endl;
            }

            outFile.close();

            printf("\033[32m ");
            cout << "\n\t\tRegistration successful!" << endl;
            printf("\033[0m ");

            cout << "\n\tGo back to main menu(y/n)- ";
            cin >> Response;
            if (Response == 'y' || Response == 'Y')
            {
                system("pause");
                system("cls");
                admin_main_menu();
            }
            else  if (Response == 'n' || Response == 'N') {
                system("cls");
                title();
                Student_reg();
            }
            else
            {
                printf("\033[41m \t\tInvalid Input!");
                printf("\033[0m GO Back to Main Menu  ");
                system("pause");
                system("cls");
                admin_main_menu();
            }
        }
    }
}

void Student_Data() {
    system("cls");
    title();
    cout << "\n\t\t-------------- Student Details -----------------" << endl;

    // filestream variable file
    ifstream infile;
    infile.open("StudentData.txt", ios::in);// open file for read

    // Check if file is empty
    if (infile.peek() == ifstream::traits_type::eof()) {
        cout << "\n\tData Not Found!\n" << endl;
    }
    else {
        infile >> sId >> fName >> lName >> cId >> mail >> pass;
        while (!infile.eof())// again and again read the data from the file and display it.
        {
            cout << "\n\t\tStudent Id:" << sId << endl;
            infile >> sId;
            cout << "\t\tStudent First Name:" << fName << endl;
            infile >> fName;
            cout << "\t\tLast Name:" << lName << endl;
            infile >> lName;
            cout << "\t\tcourse Code: " << cId << endl;
            infile >> cId;
            cout << "\t\tEmail: " << mail << endl;
            infile >> mail;
            cout << "\t\tPasssword: " << pass << endl;
            infile >> pass;

        }
        // close the opened file.
        infile.close();
    }



    cout << "\n\tGo back to main menu(y/n)- ";
    cin >> Response;
    if (Response == 'y' || Response == 'Y')
    {
        system("pause");
        system("cls");
        admin_main_menu();
    }
    else  if (Response == 'n' || Response == 'N')
    {
        system("cls");
        title();
        Student_Data();
    }
    else
    {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m GO Back to Main Menu ");
        system("pause");
        system("cls");
        admin_main_menu();
    }



}

void course_search()
{
    system("cls");
    title();

    string find;
    ifstream t2("CourseData.txt");

    cout << "\n\t\tEnter Course ID to be displayed: ";
    cin >> find;

    cout << endl;
    int found = 0;

    string line;
    while (getline(t2, line))
    {
        if (line == find)
        {
            found = 1;
            printf("\033[32m ");
            cout << "\n\n\t\tCourse Is Available-->>" << endl;
            printf("\033[0m ");
            cout << "\t\tCourse ID: " << line << endl;
            getline(t2, line);
            cout << "\t\tCourse Name: " << line << endl;
            getline(t2, line);
            cout << "\t\tLecture Name: " << line << endl;
            getline(t2, line);
            cout << "\t\tCourse Duration: " << line << endl;
            break;
        }
    }

    t2.close();

    if (found == 0)
    {
        cout << "\n\t\tNo Record Found" << endl;
    }

    cout << "\n\tGo back to the main menu (y/n): ";
    cin >> Response;

    if (Response == 'y' || Response == 'Y')
    {
        system("pause");
        system("cls");
        admin_main_menu();
    }
    else if (Response == 'n' || Response == 'N')
    {
        system("cls");
        title();
        course_search();
    }
    else
    {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m GO Back to Main Menu  ");
        system("pause");
        system("cls");
        admin_main_menu();
    }
}

void student_search()
{
    system("cls");
    title();

    string find;
    ifstream t2("StudentData.txt");

    cout << "\n\t\tEnter Student ID to be displayed: ";
    cin >> find;

    cout << endl;
    int found = 0;

    string line;
    while (getline(t2, line))
    {
        if (line == find)
        {
            found = 1;
            printf("\033[32m ");
            cout << "\n\n\tData Found-->>" << endl;
            printf("\033[0m ");
            cout << "\t\Student ID: " << line << endl;
            getline(t2, line);
            cout << "\t\Student First Name: " << line << endl;
            getline(t2, line);
            cout << "\t\Student Last Name: " << line << endl;
            getline(t2, line);
            cout << "\t\Course Id: " << line << endl;
            getline(t2, line);
            cout << "\t\Student email: " << line << endl;
            getline(t2, line);
            cout << "\t\Student Password: " << line << endl;
            break;
        }
    }

    t2.close();

    if (found == 0)
    {
        cout << "\n\t\tNo Record Found" << endl;
    }

    cout << "\n\tGo back to the main menu (y/n): ";
    cin >> Response;

    if (Response == 'y' || Response == 'Y')
    {
        system("pause");
        system("cls");
        admin_main_menu();
    }
    else if (Response == 'n' || Response == 'N')
    {
        system("cls");
        title();
        student_search();
    }
    else
    {
        printf("\033[41m \t\tInvalid Input!");
        printf("\033[0m GO Back to Main Menu  ");
        system("pause");
        system("cls");
        admin_main_menu();
    }
}

