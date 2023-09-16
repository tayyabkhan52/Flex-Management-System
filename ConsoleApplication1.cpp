#include"Header.h"

//this is the login function that takes in a username and password and an object of type T and
//returns true if the username and password match the username and password of the object
template <class T>
bool login(string user, string pass, T& obj) {
    
    ifstream file("passwords.txt");
    string username, password;
    while (file >> username >> password) {
        if (obj.getUsername() == username && obj.getPassword() == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
    return ("Hello");
}


int main() {
    int mainChoice;
    cout << "***********************************" << endl;
    cout << "*     FLEX MANAGEMENT SYSTEM      *" << endl;
    cout << "***********************************" << endl;
    cout << "*   Press 1 to login as admin     *" << endl;
    cout << "*   Press 2 to login as teacher   *" << endl;
    cout << "*   Press 3 to login as student   *" << endl;
    cout << "***********************************" << endl;
    cin >> mainChoice;
    switch (mainChoice) {

    case 1:
    {const int MAX_STUDENTS = 100; // Maximum number of students that can be stored
    Student* students = new Student[MAX_STUDENTS]; // Array of students
    int sizeStudents = 0; // Number of students currently stored

    //Max number of teachers that can be stored
    const int MAX_TEACHERS = 100;
    Teacher* teachers = new Teacher[MAX_TEACHERS];
    int sizeTeachers = 0;

    system("CLS");
    AdminModule admin;
    string username, password;
    cout << "***********************************" << endl;
    cout << "*          LOGIN PORTAL           *" << endl;
    cout << "***********************************" << endl;
    do {
        cout << "Enter username: ";
        cin >> username;
        admin.setUsername(username);
        cout << "Enter password: ";
        cin >> password;
        admin.setPassword(password);
        if (!login(admin.getUsername(), admin.getPassword(), admin)) {
            cout << "Invalid username or password" << endl;
        }
    } while (!login(admin.getUsername(), admin.getPassword(), admin));

    cout << "Login Successful" << endl;
    system("PAUSE");
    system("CLS");
    while (true) {
        cout << "*******************************" << endl;
        cout << "*    ADMINSTRATION MODULE     *" << endl;
        cout << "*******************************" << endl;
        cout << "* 1. Add teacher              *" << endl;
        cout << "* 2. Add student              *" << endl;
        cout << "* 3. Edit teacher             *" << endl;
        cout << "* 4. Edit student             *" << endl;
        cout << "* 5. View all students        *" << endl;
        cout << "* 6. View all teachers        *" << endl;
        cout << "* 7. Exit                     *" << endl;
        cout << "*******************************" << endl;
        cout << "Enter your choice: ";
        int choice = 0;
        cin >> choice;

        switch (choice) {

        case 1:
        {
            admin.addTeacher(teachers, sizeTeachers, MAX_TEACHERS);
            system("CLS");
            break;
        }
       
        case 2:
            admin.addStudent(students, sizeStudents, MAX_STUDENTS);
            system("CLS");
            break;
        case 3:
            admin.editTeacher(teachers, sizeTeachers);
            system("CLS");
            break;
        case 4:
            admin.editStudent(students, sizeStudents);
            system("CLS");
            break;
        case 5:
            admin.displayStudents(students, sizeStudents);
            system("CLS");

            break;
        case 6:
            admin.displayTeachers(teachers, sizeTeachers);
           
            break;
        case 7:
            exit(0);
            break;
        }

        cout<<"This is a test for aggregation and composition"<<endl;
        cout<<students[0].getFullName()<<endl;
    }
    break;
    }

    case 2:
    {
        system("CLS");
        TeacherModule teacher;
        string username, password;
        cout << "***********************************" << endl;
        cout << "*          LOGIN PORTAL           *" << endl;
        cout << "***********************************" << endl;
        do {
            cout << "Enter username: ";
            cin >> username;
            teacher.setUserName(username);
            cout << "Enter password: ";
            cin >> password;
            teacher.setPassword(password);
            if (!login(teacher.getUsername(), teacher.getPassword(), teacher)) {
                cout << "Invalid username or password" << endl;
            }
        } while (!login(teacher.getUsername(), teacher.getPassword(), teacher));

        vector<TeacherModule> students;
        readDataFromFile("teachermodule.txt", students);

        while (true) {

            cout << "Menu:" << endl;
            cout << "1. Add a student" << endl;
            cout << "2. Add course for a student" << endl;
            cout << "3. Upload attendance for a student" << endl;
            cout << "4. Upload marks for a student" << endl;
            cout << "5. Upload grades for a student" << endl;
            cout << "6. Print information of all students" << endl;
            cout << "7. Save data to file" << endl;
            cout << "8. Display Time Table" << endl;
            cout << "9. Exit" << endl;

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                addStudent(students, name);
                break;
                system("CLS");
            }
            case 2: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                TeacherModule* student = selectStudentByName(students, name);
                if (student != nullptr) {
                    string course;
                    cout << "Enter course name: ";
                    getline(cin, course);
                    addCourse(*student, course);
                }
                else {
                    cout << "Student not found!" << endl;
                }
                break;
                system("CLS");
            }
            case 3: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                TeacherModule* student = selectStudentByName(students, name);
                if (student != nullptr) {
                    string date;
                    char status;
                    cout << "Enter attendance date: ";
                    cin.ignore(); // Add this line
                    getline(cin, date);
                    cout << "Enter attendance status (P/A): ";
                    cin >> status;
                    uploadAttendance(*student, date, status);
                }
                else {
                    cout << "Student not found!" << endl;
                }
                break;
                system("CLS");
            }

            case 4: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                TeacherModule* student = selectStudentByName(students, name);
                if (student != nullptr) {
                    int mark, index;
                    cout << "Enter mark: ";
                    cin >> mark;
                    cout << "Enter course index: ";
                    cin >> index;
                    uploadMarks(*student, mark, index);
                }
                else {
                    cout << "Student not found!" << endl;
                }
                break;
                system("CLS");
            }
            case 5: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                TeacherModule* student = selectStudentByName(students, name);
                if (student != nullptr) {
                    string grade;
                    int index;
                    cout << "Enter grade: ";
                    cin >> grade;
                    cout << "Enter course index: ";
                    cin >> index;
                    uploadGrades(*student, grade, index);
                }
                else {
                    cout << "Student not found!" << endl;
                }
                break;
                system("CLS");
            }
            case 6: {
                for (const TeacherModule& student : students) {
                    student.printInfo();
                    cout << endl;
                }
                break;
                system("CLS");
            }
            case 7: {
                saveDataToFile(students, "teachermodule.txt");
                cout << "Data saved to file successfully." << endl;
                break;
                system("CLS");
            }
            case 8: {
                vector<Lecture> teacherTimetable = {
            {"Math", "2023-05-12", "10:00 AM"},
            {"Science", "2023-05-14", "11:30 AM"},
            {"History", "2023-05-16", "09:45 AM"}
                };
                cout << endl;
                cout << "Teacher Timetable:" << endl;
                for (const Lecture& lecture : teacherTimetable) {
                    cout << lecture.name << setw(25) << lecture.date << setw(25) << lecture.time << endl;
                }
            }
            case 9: {
                return 0;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
                system("CLS");
            }
            }

            cout << endl;
        }
    }
    case 3:
    {
        cout << "TO BE ADDED!";
        /*system("CLS");
        StudentModule student;
        string username, password;
        cout << "***********************************" << endl;
        cout << "*          LOGIN PORTAL           *" << endl;
        cout << "***********************************" << endl;
        do {
            cout << "Enter username: ";
            cin >> username;
            student.setUserName(username);
            cout << "Enter password: ";
            cin >> password;
            student.setPassword(password);
            if (!login(student.getUserName(), student.getPassword(), student)) {
                cout << "Invalid username or password" << endl;
            }
        } while (!login(student.getUserName(), student.getPassword(), student));
        cout << "Login Successful" << endl;
        system("PAUSE");
        system("CLS");
        int choice = 0;
        cout << "*******************************" << endl;
        cout << "*    STUDENT  MODULE          *" << endl;
        cout << "*******************************" << endl;
        cout << "* 1. View Attendance          *" << endl;
        cout << "* 2. View Grades              *" << endl;
        cout << "* 3. View Marks               *" << endl;
        cout << "* 4. View Fee Status          *" << endl;
        cout << "* 4. View Registered Courses  *" << endl;
        cout << "===============================" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            student.viewAttendance();
            break;
        case 2:
            student.viewGrades();
            break;
        case 3:
            student.viewMarks();
            break;
        case 4:
            student.viewFeeStatus();
            break;

        case 5:
            student.viewRegisteredCourses();
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        break;*/
    }
    }
}

