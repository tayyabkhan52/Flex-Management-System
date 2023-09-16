#include "Header.h"




//PERSON CLASS
Person::Person() {
    //default values
    firstName = "N/A";
    lastName = "N/A";
    address = "N/A";
    gender = "N/A";
    qualification = "N/A";
    contactNo = 0;
    registrationDate = "N/A";
    departmentName = "N/A";

}
Person::Person(string FN, string LN, string A, string G, string Q, int CN, string RD, string DN) {
    firstName = FN;
    lastName = LN;
    address = A;
    gender = G;
    qualification = Q;
    contactNo = CN;
    registrationDate = RD;
    departmentName = DN;
}
string Person::getFirstName() const {
    return firstName;
}
string Person::getLastName() const {
    return lastName;
}
string Person::getAddress() const {
    return address;
}
string Person::getGender() const {
    return gender;
}
string Person::getQualification() const {
    return qualification;
}
int Person::getContactNo() const {
    return contactNo;
}
string Person::getRegistrationDate() const {
    return registrationDate;
}
string Person::getDepartmentName() const {
    return departmentName;
}

// Setters
void Person:: setFirstName(string FN) {
    firstName = FN;
}
void Person::setLastName(string LN) {
    lastName = LN;
}
void Person::setAddress(string A) {
    address = A;
}
void Person::setGender(string G) {
    gender = G;
}
void Person::setQualification(string Q) {
    qualification = Q;
}
void Person::setContactNo(int CN) {
    contactNo = CN;
}
void Person::setRegistrationDate(string RD) {
    registrationDate = RD;
}
void Person::setDepartmentName(string DN) {
    departmentName = DN;
}

// STUDENT CLASS

Student::Student() {
    //default values
    sId = "N/A";
    bloodGroup = "N/A";
    feeStatus = "N/A";
    marks = 0;
}
string Student::getStudentId() const {
    return sId;
}
string Student::getBloodGroup() const {
    return bloodGroup;
}
string Student::getFeeStatus() const {
    return feeStatus;
}
int Student::getMarks() const {
    return marks;
}
string Student::getFullName() const {
    return firstName + " " + lastName;
}

// Setters
void Student:: setStudentId(string SID) {
    sId = SID;
}
void Student:: setBloodGroup(string BG) {
    bloodGroup = BG;
}
void Student::setFeeStatus(string FS) {
    feeStatus = FS;
}
void Student::setMarks(int M) {
    marks = M;
}
ostream& operator<<(ostream& os, const Student& student) {
    os << student.getFirstName() << ","
        << student.getLastName() << ","
        << student.getAddress() << ","
        << student.getGender() << ","
        << student.getQualification() << ","
        << student.getContactNo() << ","
        << student.getRegistrationDate() << ","
        << student.getDepartmentName() << ","
        << student.getStudentId() << ","
        << student.getBloodGroup() << ","
        << student.getFeeStatus() << ","
        << student.getMarks() << endl;
    return os;
}



//TEACHER CLASS
Teacher::Teacher() {
    //default values
    tId = "N/A";
    userName = "N/A";
    password = "N/A";
}
// Getters
string Teacher::getTeacherId() const {
    return tId;
}
string Teacher::getUserName() const {
    return userName;
}
string Teacher::getPassword() const {
    return password;
}
//get full name
string Teacher::getFullName() const {
    return firstName + " " + lastName;
}
int Teacher:: getSalary() const {
    return salary;
}
// Setters
void Teacher:: setSalary(double S) {
    salary = S;
}
void Teacher:: setTeacherId(string TID) {
    tId = TID;
}
void Teacher:: setUserName(string UN) {
    userName = UN;
}
void Teacher:: setPassword(string P) {
    password = P;
}

//teachers
ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << teacher.getFirstName() << ","
        << teacher.getLastName() << ","
        << teacher.getAddress() << ","
        << teacher.getGender() << ","
        << teacher.getQualification() << ","
        << teacher.getContactNo() << ","
        << teacher.getRegistrationDate() << ","
        << teacher.getDepartmentName() << ","
        << teacher.getTeacherId() << ","
        << teacher.getUserName() << ","
        << teacher.getPassword() << ","
        << teacher.getSalary() << "," << endl;
    return os;
}

void AdminModule::addTeacher(Teacher* teachers, int& size, const int maxSize) {

    if (size < maxSize) {
        Teacher t;

        cout << "Enter First Name";
        string firstName;
        cin >> firstName;
        t.setFirstName(firstName);

        cout << "Enter Last Name: ";
        string lastName;
        cin >> lastName;
        t.setLastName(lastName);

        cout << "Enter Address: ";
        cin.ignore(); // ignore any remaining input from previous input operation
        string address;
        getline(cin, address); // read a whole line of input
        t.setAddress(address);

        cout << "Enter Gender: ";
        string gender;
        getline(cin, gender);
        t.setGender(gender);

        cout << "Enter Qualification: ";
        string qualification;
        getline(cin, qualification);
        t.setQualification(qualification);

        cout << "Enter Contact Number: ";
        long long int contactNo;
        while (true) {
            cin >> contactNo;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer: ";
            }
            else {
                break;
            }
        }
        t.setContactNo(contactNo);

        cout << "Enter Registration Date (dd/mm/yyyy): ";
        string registrationDate;
        cin >> registrationDate;
        t.setRegistrationDate(registrationDate);

        string departmentName;
        int choice1;
        string tId;
        bool validChoice = false;

        cout << "Select Department: " << endl;
        cout << "1. Computer Science" << endl;
        cout << "2. Software Engineering" << endl;
        cout << "3. Business" << endl;
        cout << "4. Social Sciences" << endl;

        while (!validChoice) {
            cin >> choice1;
            switch (choice1) {
            case 1:
                tId = "CS-" + to_string(size + 1);
                t.setTeacherId(tId);
                departmentName = "Computer Science";
                //set department name using setter
                t.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 2:
                tId = "SE-" + to_string(size + 1);
                t.setTeacherId(tId);
                departmentName = "Software Engineering";
                t.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 3:
                tId = "B-" + to_string(size + 1);
                t.setTeacherId(tId);
                departmentName = "Business";
                t.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 4:
                tId = "SS-" + to_string(size + 1);
                t.setTeacherId(tId);
                departmentName = "Social Sciences";
                t.setDepartmentName(departmentName);
                validChoice = true;
                break;
            default:
                cout << "Invalid choice. Please select a valid department:" << endl;
                break;
            }
        }

        cout << "Selected department: " << departmentName << endl;
        cin.ignore();

        cout << "Enter Username: ";
        string userName;
        cin >> userName;
        t.setUserName(userName);
        fstream file;
        file.open("passwords.txt", ios::app);
        file <<userName <<endl;
        file.close();

        cout << "Enter Password: ";
        string password;
        cin >> password;
        t.setPassword(password);
        file.open("passwords.txt", ios::app);
        file << password << endl;
        file.close();

        cout << "Enter Salary: ";
        double salary;
        cin >> salary;
        t.setSalary(salary);

        // adding the student to the array of students
        teachers[size] = t;
        size++;

        // Save the new student data to the file
        ofstream outFile("teachers.txt", ios::app);
        if (outFile.is_open()) {
            outFile << t;
            outFile.close();
        }
        else {
            cout << "Error: Unable to open file for writing.\n";
        }

        cout << "Teacher added successfully.\n";
    }
    else {
        cout << "Error: Maximum number of students reached.\n";
    }

}
void AdminModule::addStudent(Student* students, int& size, const int maxSize) {
    if (size < maxSize) {
        Student s;

        cout << "Enter First Name: ";
        string firstName;
        cin >> firstName;
        s.setFirstName(firstName);

        cout << "Enter Last Name: ";
        string lastName;
        cin >> lastName;
        s.setLastName(lastName);

        cout << "Enter Address: ";
        cin.ignore(); // ignore any remaining input from previous input operation
        string address;
        getline(cin, address); // read a whole line of input
        s.setAddress(address);

        cout << "Enter Gender: ";
        string gender;
        getline(cin, gender);
        s.setGender(gender);

        cout << "Enter Qualification: ";
        string qualification;
        getline(cin, qualification);
        s.setQualification(qualification);

        cout << "Enter Contact Number: ";
        long long int contactNo;
        while (true) {
            cin >> contactNo;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer: ";
            }
            else {
                break;
            }
        }
        s.setContactNo(contactNo);

        cout << "Enter Registration Date (dd/mm/yyyy): ";
        string registrationDate;
        cin >> registrationDate;
        s.setRegistrationDate(registrationDate);

        string departmentName;
        int choice1;
        string sId;
        bool validChoice = false;

        cout << "Select Department: " << endl;
        cout << "1. Computer Science" << endl;
        cout << "2. Software Engineering" << endl;
        cout << "3. Business" << endl;
        cout << "4. Social Sciences" << endl;

        while (!validChoice) {
            cin >> choice1;
            switch (choice1) {
            case 1:
                sId = "CS-" + to_string(size + 1);
                s.setStudentId(sId);
                departmentName = "Computer Science";
                //set department name using setter
                s.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 2:
                sId = "SE-" + to_string(size + 1);
                s.setStudentId(sId);
                departmentName = "Software Engineering";
                s.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 3:
                sId = "B-" + to_string(size + 1);
                s.setStudentId(sId);
                departmentName = "Business";
                s.setDepartmentName(departmentName);
                validChoice = true;
                break;
            case 4:
                sId = "SS-" + to_string(size + 1);
                s.setStudentId(sId);
                departmentName = "Social Sciences";
                s.setDepartmentName(departmentName);
                validChoice = true;
                break;
            default:
                cout << "Invalid choice. Please select a valid department:" << endl;
                break;
            }
        }

        cout << "Selected department: " << departmentName << endl;
        cin.ignore();
        cout << "Enter Blood Group: ";
        string bloodGroup;
        getline(cin, bloodGroup);
        s.setBloodGroup(bloodGroup);

        cout << "Enter Fee Status: ";
        string feeStatus;
        getline(cin, feeStatus);
        s.setFeeStatus(feeStatus);

        cout << "Enter Marks: ";
        int marks;
        cin >> marks;
        s.setMarks(marks);

        // adding the student to the array of students
        students[size] = s;
        size++;

        // Save the new student data to the file
        ofstream outFile("students.txt", ios::app);
        if (outFile.is_open()) {
            outFile << s;
            outFile.close();
        }
        else {
            cout << "Error: Unable to open file for writing.\n";
        }

        cout << "Student added successfully.\n";
    }
    else {
        cout << "Error: Maximum number of students reached.\n";
    }
}
//display all students function 
void AdminModule::displayStudents(Student* students, int& size) {
    // Clear the contents of the students array so that the data is not duplicated from existing data
    for (int i = 0; i < size; i++) {
        students[i] = Student();
    }
    size = 0;

    // Open the file for reading
    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    // Read student data from the file and store it in the array
    try {
        while (inFile.good()) {
            string line;
            getline(inFile, line);
            if (!line.empty()) {
                stringstream ss(line);
                string firstName, lastName, address, gender, qualification, registrationDate, departmentName, sId, bloodGroup, feeStatus;
                int contactNo, marks;
                getline(ss, firstName, ',');
                getline(ss, lastName, ',');
                getline(ss, address, ',');
                getline(ss, gender, ',');
                getline(ss, qualification, ',');
                ss >> contactNo;
                ss.ignore();
                getline(ss, registrationDate, ',');
                getline(ss, departmentName, ',');
                getline(ss, sId, ',');
                getline(ss, bloodGroup, ',');
                getline(ss, feeStatus, ',');
                ss >> marks;

                Student newStudent(firstName, lastName, address, gender, qualification, contactNo, registrationDate, departmentName, sId, bloodGroup, feeStatus, marks);
                students[size] = newStudent;
                size++;
            }
        }
    }
    catch (const exception& e) {
        cout << "Error occurred while reading file: " << e.what() << endl;
        inFile.close();
        return;
    }

    // Display options menu
    int choice = 0;
    do {
        cout << "Select an option:\n";
        cout << "1. Display all students\n";
        cout << "2. Display students in a department\n";
        cout << "3. Display a specific student by ID\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            // Display all students
        {
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << left << setw(15) << "Student ID" << setw(25) << "Name" << setw(25) << "Department Name" << setw(15) << "Gender" << setw(20) << "Qualification" << setw(15) << "Contact No" << setw(20) << "Registration Date" << setw(15) << "Blood Group" << setw(15) << "Fee Status" << setw(10) << "Marks" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            for (int i = 0; i < size; i++) {
                cout << left << setw(15) << students[i].getStudentId() << setw(25) << students[i].getFullName() << setw(25) << students[i].getDepartmentName() << setw(15) << students[i].getGender() << setw(20) << students[i].getQualification() << setw(15) << students[i].getContactNo() << setw(20) << students[i].getRegistrationDate() << setw(15) << students[i].getBloodGroup() << setw(15) << students[i].getFeeStatus() << setw(10) << students[i].getMarks() << endl;
            }
            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            break;
        }
        case 2:
            // Display students in a department
        {  string deptName;
        cout << "Enter the name of the department:\n";
        cin.ignore();
        getline(cin, deptName);
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(15) << "Student ID" << setw(25) << "Name" << setw(25) << "Department Name" << setw(15) << "Gender" << setw(20) << "Qualification" << setw(15) << "Contact No" << setw(20) << "Registration Date" << setw(15) << "Blood Group" << setw(15) << "Fee Status" << setw(10) << "Marks" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            if (students[i].getDepartmentName() == deptName) {
                cout << left << setw(15) << students[i].getStudentId() << setw(25) << students[i].getFullName() << setw(25) << students[i].getDepartmentName() << setw(15) << students[i].getGender() << setw(20) << students[i].getQualification() << setw(15) << students[i].getContactNo() << setw(20) << students[i].getRegistrationDate() << setw(15) << students[i].getBloodGroup() << setw(15) << students[i].getFeeStatus() << setw(10) << students[i].getMarks() << endl;
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        cout << endl;
        break;
        }
        case 3:
        {  // Display a specific student by ID
            string studentId;
            cout << "Enter the ID of the student:\n";
            cin >> studentId;
            for (int i = 0; i < size; i++) {
                if (students[i].getStudentId() == studentId) {
                    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

                    cout << "Student ID: " << students[i].getStudentId() << endl;
                    cout << "Name: " << students[i].getFullName() << endl;
                    cout << "Department Name: " << students[i].getDepartmentName() << endl;
                    cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";

                    cout << left << setw(20) << "Address" << setw(10) << "Gender" << setw(20) << "Qualification" << setw(15) << "Contact No" << setw(20) << "Registration Date" << setw(15) << "Blood Group" << setw(15) << "Fee Status" << setw(10) << "Marks" << endl;
                    cout << left << setw(20) << students[i].getAddress() << setw(10) << students[i].getGender() << setw(20) << students[i].getQualification() << setw(15) << students[i].getContactNo() << setw(20) << students[i].getRegistrationDate() << setw(15) << students[i].getBloodGroup() << setw(15) << students[i].getFeeStatus() << setw(10) << students[i].getMarks() << endl;
                    cout << endl;
                    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";

                    break;
                }
            }
            break;
        }
        case 4:
            // Exit the function
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    // Close the file
    inFile.close();
}
//display all teachers function
void AdminModule::displayTeachers(Teacher* teachers, int& size) {
    // Clear the contents of the students array so that the data is not duplicated from existing data
    for (int i = 0; i < size; i++) {
        teachers[i] = Teacher();
    }
    size = 0;

    // Open the file for reading
    ifstream inFile("teachers.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    // Read student data from the file and store it in the array
    try {
        while (inFile.good()) {
            string line;
            getline(inFile, line);
            if (!line.empty()) {
                stringstream ss(line);
                string firstName, lastName, address, gender, qualification, registrationDate, departmentName, tId, userName, password;
                int contactNo, salary;
                getline(ss, firstName, ',');
                getline(ss, lastName, ',');
                getline(ss, address, ',');
                getline(ss, gender, ',');
                getline(ss, qualification, ',');
                ss >> contactNo;
                ss.ignore();
                getline(ss, registrationDate, ',');
                getline(ss, departmentName, ',');
                getline(ss, tId, ',');
                getline(ss, userName, ',');
                getline(ss, password, ',');
                ss >> salary;


                // Create a new student object and add it to the array of students by calling the parametrised constructor
                Teacher newteacher(firstName, lastName, address, gender, qualification, contactNo, registrationDate, departmentName, tId, userName, password, salary);
                teachers[size] = newteacher;
                size++;
            }
        }
    }
    catch (const exception& e) {
        cout << "Error occurred while reading file: " << e.what() << endl;
        inFile.close();
        return;
    }

    // Close the file
    inFile.close();

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Teacher ID" << setw(25) << "Name" << setw(25) << "Department Name" << setw(15) << "Gender" << setw(20) << "Qualification" << setw(15) << "Contact No" << setw(20) << "Registration Date" << setw(15) << "User Name" << setw(15) << "Password" << setw(15) << "Salary" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << teachers[i].getTeacherId() << setw(25) << teachers[i].getFullName() << setw(25) << teachers[i].getDepartmentName() << setw(15) << teachers[i].getGender() << setw(20) << teachers[i].getQualification() << setw(15) << teachers[i].getContactNo() << setw(20) << teachers[i].getRegistrationDate() << setw(15) << teachers[i].getUserName() << setw(15) << teachers[i].getPassword() << setw(15) << teachers[i].getSalary() << endl;
    }
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    system("PAUSE");
    system("CLS");

}
void AdminModule::editStudent(Student* students, int& size) {
    // Read student data from the file if the students array is empty
    if (size == 0) {
        // Open the file for reading
        ifstream inFile("students.txt");
        if (!inFile.is_open()) {
            cout << "Unable to open file.\n";
            return;
        }

        // Read student data from the file and store it in the array
        try {
            while (inFile.good()) {
                string line;
                getline(inFile, line);
                if (!line.empty()) {
                    stringstream ss(line);
                    string firstName, lastName, address, gender, qualification, registrationDate, departmentName, sId, bloodGroup, feeStatus;
                    int contactNo, marks;
                    getline(ss, firstName, ',');
                    getline(ss, lastName, ',');
                    getline(ss, address, ',');
                    getline(ss, gender, ',');
                    getline(ss, qualification, ',');
                    ss >> contactNo;
                    ss.ignore();
                    getline(ss, registrationDate, ',');
                    getline(ss, departmentName, ',');
                    getline(ss, sId, ',');
                    getline(ss, bloodGroup, ',');
                    getline(ss, feeStatus, ',');
                    ss >> marks;

                    Student newStudent(firstName, lastName, address, gender, qualification, contactNo, registrationDate, departmentName, sId, bloodGroup, feeStatus, marks);
                    students[size] = newStudent;
                    size++;
                }
            }
        }
        catch (const exception& e) {
            cout << "Error occurred while reading file: " << e.what() << endl;
            inFile.close();
            return;
        }
    }

    // Display a list of all registered students
    cout << "List of registered students:\n";
    for (int i = 0; i < size; i++) {
        cout << "Student ID: " << students[i].getStudentId() << " Name: " << students[i].getFullName() << endl;
    }

    // Get the ID of the student to edit
    string studentId;
    cout << "Enter the Student ID of the student to edit: ";
    cin >> studentId;

    // Find the student with the specified ID and update their information
    for (int i = 0; i < size; i++) {
        if (students[i].getStudentId() == studentId) {
            string firstName, lastName, address, feeStatus;
            int contactNo;

            // Get the updated information from the user
            cout << "Enter the updated information for the student:\n";
            cout << "First Name: ";
            cin >> firstName;
            cout << "Last Name: ";
            cin >> lastName;
            cout << "Address: ";
            cin >> address;
            cout << "Fee Status: ";
            cin >> feeStatus;
            while (feeStatus != "Paid" && feeStatus != "Unpaid") {
                cout << "Invalid fee status. Please enter 'Paid' or 'Unpaid': ";
                cin >> feeStatus;
            }
            cout << "Contact No: ";
            cin >> contactNo;

            // Update the student's information
            students[i].setFirstName(firstName);
            students[i].setLastName(lastName);
            students[i].setAddress(address);
            students[i].setFeeStatus(feeStatus);
            students[i].setContactNo(contactNo);

            // Write the updated information to the file
            ofstream outFile("students.txt");
            if (!outFile.is_open()) {
                cout << "Unable to open file.\n";
                return;
            }
            try {
                for (int j = 0; j < size; j++) {
                    outFile << students[j].getFirstName() << ","
                        << students[j].getLastName() << ","
                        << students[j].getAddress() << ","
                        << students[j].getGender() << ","
                        << students[j].getQualification() << ","
                        << students[j].getContactNo() << ","
                        << students[j].getRegistrationDate() << ","
                        << students[j].getDepartmentName() << ","
                        << students[j].getStudentId() << ","
                        << students[j].getBloodGroup() << ","
                        << students[j].getFeeStatus() << ","
                        << students[j].getMarks() << endl;
                }
            }
            catch (const exception& e) {
                cout << "Error occurred while writing to file: " << e.what() << endl;
                outFile.close();
                return;
            }
            outFile.close();

            // Display the updated information of the edited student
            cout << "Student information updated.\n";
            cout << "Updated information for student with ID " << studentId << ":\n";
            cout << "Name: " << students[i].getFullName() << endl;
            cout << "Address: " << students[i].getAddress() << endl;
            cout << "Fee Status: " << students[i].getFeeStatus() << endl;
            cout << "Contact No: " << students[i].getContactNo() << endl;

            return;
        }
    }

    // If the specified student ID was not found, display an error message
    cout << "Student with ID " << studentId << " not found.\n";
}
void AdminModule::editTeacher(Teacher* teachers, int& size) {
    if (size == 0)
    {
        //read teacher data from the file if the teacher array is empty
        ifstream inFile("teachers.txt");
        if (!inFile.is_open())
        {
            cout << "Unable to open file.\n";
            return;
        }

        // Read teacher data from the file and store it in the array
        try {
            while (inFile.good()) {
                string line;
                getline(inFile, line);
                if (!line.empty()) {
                    stringstream ss(line);
                    string firstName, lastName, address, gender, qualification, registrationDate, departmentName, tId, userName, password;
                    int contactNo, salary;
                    getline(ss, firstName, ',');
                    getline(ss, lastName, ',');
                    getline(ss, address, ',');
                    getline(ss, gender, ',');
                    getline(ss, qualification, ',');
                    ss >> contactNo;
                    ss.ignore();
                    getline(ss, registrationDate, ',');
                    getline(ss, departmentName, ',');
                    getline(ss, tId, ',');
                    getline(ss, userName, ',');
                    getline(ss, password, ',');
                    ss >> salary;


                    // Create a new student object and add it to the array of students by calling the parametrised constructor
                    Teacher newteacher(firstName, lastName, address, gender, qualification, contactNo, registrationDate, departmentName, tId, userName, password, salary);
                    teachers[size] = newteacher;
                    size++;
                }
            }
        }
        catch (const exception& e) {
            cout << "Error occurred while reading file: " << e.what() << endl;
            inFile.close();
            return;
        }

        // Close the file
        inFile.close();
    }

    // Display a list of all registered teachers
    cout << "List of registered teachers:\n";
    for (int i = 0; i < size; i++) {
        cout << "Teacher ID: " << teachers[i].getTeacherId() << " Name: " << teachers[i].getFullName() << endl;
    }

    // Get the ID of the teacher to edit
    string teacherId;
    cout << "Enter the Teacher ID of the teacher to edit: ";
    cin >> teacherId;

    // Find the teacher with the specified ID and update their information
    for (int i = 0; i < size; i++)
    {
        if (teachers[i].getTeacherId() == teacherId) {
            string  address, qualification;
            int contactNo = 0;
            double salary = 0;

            // Get the updated information from the user
            cout << "Enter the updated information for the student:\n";
            cout << "Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Qualification: ";
            cin >> qualification;
            cout << "Contact No: ";
            cin >> contactNo;
            cout << "Salary: ";
            cin >> salary;


            // Update the student's information
            teachers[i].setAddress(address);
            teachers[i].setQualification(qualification);
            teachers[i].setContactNo(contactNo);
            teachers[i].setSalary(salary);

            // Write the updated information to the file
            ofstream outFile("teachers.txt");
            if (!outFile.is_open()) {
                cout << "Unable to open file.\n";
                return;
            }
            try {
                for (int j = 0; j < size; j++) {
                    outFile << teachers[j].getFirstName() << ","
                        << teachers[j].getLastName() << ","
                        << teachers[j].getAddress() << ","
                        << teachers[j].getGender() << ","
                        << teachers[j].getQualification() << ","
                        << teachers[j].getContactNo() << ","
                        << teachers[j].getRegistrationDate() << ","
                        << teachers[j].getDepartmentName() << ","
                        << teachers[j].getTeacherId() << ","
                        << teachers[j].getUserName() << ","
                        << teachers[j].getPassword() << ","
                        << teachers[j].getSalary() << endl;
                }
            }
            catch (const exception& e) {
                cout << "Error occurred while writing to file: " << e.what() << endl;
                outFile.close();
                return;
            }
            outFile.close();

            // Display the updated information of the edited student
            cout << "Student information updated.\n";
            cout << "Updated information for student with ID " << teacherId << ":\n";
            cout << "Name: " << teachers[i].getFullName() << endl;
            cout << "Address: " << teachers[i].getAddress() << endl;
            cout << "Salary: " << teachers[i].getSalary() << endl;
            cout << "Contact No: " << teachers[i].getContactNo() << endl;

            return;
        }
    }
}


//TEACHER MODULE

void TeacherModule::addCourse(const string& course) {
    courses.push_back(course);
}
void TeacherModule:: addAttendance(const string& date, char status) {
    AttendanceData attendanceData;
    attendanceData.date = date;
    attendanceData.status = status;
    attendance.push_back(attendanceData);   
}
void TeacherModule:: addMarks(int mark, int index) {
    if (index >= 0 && index < courses.size()) {
        if (index >= marks.size()) {
            marks.resize(index + 1, -1);
        }
        marks[index] = mark;
    }
}
void TeacherModule:: addGrade(const string & grade, int index) {
    if (index >= 0 && index < courses.size()) {
        if (index >= grades.size()) {
            grades.resize(index + 1, "-");
        }
        grades[index] = grade;
    }
}
void TeacherModule:: printInfo() const {
   
     cout << "\nName: " << name << endl;
    cout << "Attendance:" << endl;
    cout << setw(15) << left << "Date" << setw(10) << "Status" << endl;
    cout << setw(25) << setfill('-') << "" << setfill(' ') << endl;
    for (const AttendanceData& data : attendance) {
        cout << setw(15) << left << data.date << setw(10) << data.status << endl;
    }
    cout << endl;

    cout << setw(15) << left << "Courses" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << setw(25) << setfill('-') << "" << setfill(' ') << endl;
    for (size_t i = 0; i < courses.size(); i++) {
        cout << setw(15) << left << courses[i] << setw(10) << marks[i] << setw(10) << grades[i] << endl;
    }
    cout << endl;
}
void TeacherModule:: addTeacherTimetable(const vector<Lecture>& lectures) {
    cout << "Teacher Timetable:" << endl;
    cout << setw(15) << left << "Lecture" << setw(15) << "Date" << setw(10) << "Time" << endl;
    cout << setw(45) << setfill('-') << "" << setfill(' ') << endl;
    for (const Lecture& lecture : lectures) {
        cout << setw(15) << left << lecture.name << setw(15) << lecture.date << setw(10) << lecture.time << endl;
    }
    cout << endl;
}
void addStudent(vector<TeacherModule>& students, const string& name) {
    TeacherModule newStudent;
    newStudent.setName(name);
    students.push_back(newStudent);
}
void addCourse(TeacherModule& student, const string& course) {
    student.addCourse(course);
}
void uploadAttendance(TeacherModule& student, const string& date, char status) {
    student.addAttendance(date, status);
}
void uploadMarks(TeacherModule& student, int mark, int index) {
    student.addMarks(mark, index);
}
void uploadGrades(TeacherModule& student, const string& grade, int index) {
    student.addGrade(grade, index);
}

TeacherModule* selectStudentByName(vector<TeacherModule>& students, const string& name) {
    for (TeacherModule& student : students) {
        if (student.getName() == name) {
            return &student;
        }
    }

    return nullptr;
}
void saveDataToFile(const vector<TeacherModule>& students, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const TeacherModule& student : students) {
            outFile << "Name: " << student.getName() << endl;
            outFile << "Courses:" << endl;
            for (const string& course : student.getCourses()) {
                outFile << course << endl;
            }
            outFile << "Attendance:" << endl;
            for (const AttendanceData& data : student.getAttendance()) {
                outFile << data.date << " " << data.status << endl;
            }
            outFile << "Marks:" << endl;
            for (int mark : student.getMarks()) {
                outFile << mark << endl;
            }
            outFile << "Grades:" << endl;
            for (const string& grade : student.getGrades()) {
                outFile << grade << endl;
            }
            outFile << endl;
        }
        outFile.close();
        cout << "Data saved to file: " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file " << filename << endl;
    }
}
void readDataFromFile(const string& filename, vector<TeacherModule>& students) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    students.clear(); // Clear the existing student data

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.substr(0, 6) == "Name: ") {
            TeacherModule student;
            student.setName(line.substr(6));

            // Read courses
            getline(inputFile, line); // Skip the "Courses:" line
            while (getline(inputFile, line) && line.substr(0, 11) != "Attendance:") {
                student.addCourse(line);
            }

            // Read attendance
            while (getline(inputFile, line) && line.substr(0, 6) != "Marks:") {
                if (line.empty()) {
                    continue;
                }
                istringstream iss(line);
                string date;
                char status;
                iss >> date >> status;
                uploadAttendance(student, date, status); // Use the uploadAttendance function to add attendance data
            }

            // Read marks
            while (getline(inputFile, line) && line.substr(0, 7) != "Grades:") {
                if (line.empty()) {
                    continue;
                }
                int mark = stoi(line);
                student.addMarks(mark, student.getMarks().size());
            }

            // Read grades
            while (getline(inputFile, line) && !line.empty()) {
                student.addGrade(line, student.getGrades().size());
            }

            students.push_back(student);
        }
    }

    inputFile.close();
}

