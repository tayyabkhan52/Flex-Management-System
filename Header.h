#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    string address;
    string gender;
    string qualification;
    int contactNo;
    string registrationDate;
    string departmentName;
public:
    Person();
    Person(string FN, string LN, string A, string G, string Q, int CN, string RD, string DN);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    string getGender() const;
    string getQualification() const;
    int getContactNo() const;
    string getRegistrationDate() const;
    string getDepartmentName() const;



    // Setters
    void setFirstName(string FN);
    void setLastName(string LN);
    void setAddress(string A);
    void setGender(string G);
    void setQualification(string Q);
    void setContactNo(int CN);
    void setRegistrationDate(string RD);
    void setDepartmentName(string DN);
    
};

class Student : public Person {
private:
    string sId;
    string bloodGroup;
    string feeStatus;
    int marks;

public:
    //default constructor
    Student();
    Student(string FN, string LN, string A, string G, string Q, int CN, string RD, string DN, string SID, string BG, string FS, int M) : Person(FN, LN, A, G, Q, CN, RD, DN){
        
            sId = SID;
            bloodGroup = BG;
            feeStatus = FS;
            marks = M;
        
    }
     

    // Getters
    string getStudentId() const;  
    string getBloodGroup() const;
    string getFeeStatus() const;
    int getMarks() const;
    string getFullName() const;

    // Setters
    void setStudentId(string SID);
    void setBloodGroup(string BG);
    void setFeeStatus(string FS);
    void setMarks(int M);
    friend ostream& operator<<(ostream& os, const Student& student);

    //friend istream& operator>>(istream& is, Student& student);
};

class Teacher : public Person {
    string tId;
    string userName;
    string password;
    double salary;

public:
    //default constructor
    Teacher();
    Teacher(string FN, string LN, string A, string G, string Q, int CN, string RD, string DN, string TID, string UN, string P, double S) : Person(FN, LN, A, G, Q, CN, RD, DN) {
        tId = TID;
        userName = UN;
        password = P;
        salary = S;
    }

    // Getters
    string getTeacherId() const;
    string getUserName() const;
    string getPassword() const;
    string getFullName() const;
    int getSalary() const;
    // Setters
    void setSalary(double S);
    void setTeacherId(string TID);
    void setUserName(string UN);
    void setPassword(string P);
    friend ostream& operator<<(ostream& os, const Teacher& teacher);

};

class AdminModule {
    string username;
    string password;
public:
    void addTeacher(Teacher* teachers, int& size, const int maxSize);
    void editStudent(Student* students, int& size);
    void displayStudents(Student* students, int& size);
    void displayTeachers(Teacher* teachers, int& size);
    void addStudent(Student* students, int& size, const int maxSize);
    void editTeacher(Teacher* Teachers, int& size);

    //setter getter
    void setUsername(string UN) {
        username = UN;
    }
    void setPassword(string P) {
        password = P;
    }
    string getUsername() const {
        return username;
    }
    string getPassword() const {
        return password;
    }
};

struct AttendanceData {
    string date;
    char status;
};
struct Lecture {
    string name;
    string date;
    string time;
};

class TeacherModule {
    string username;
    string password;
    string name;
    vector<string> courses;
    vector<AttendanceData> attendance;
    vector<int> marks;
    vector<string> grades;

public:
    // Setter and getter methods

    void setUserName(const string& username) {
        this->username = username;
    }
    string getUsername() const {
        return username;
    }
    void setPassword(const string& password) {
        this->password = password;
    }
    string getPassword() const {
        return password;
    }
    void setName(const string& name) {
        this->name = name;
    }
    string getName() const {
        return name;
    }
    vector<string> getCourses() const {
        return courses;
    }
    vector<AttendanceData> getAttendance() const {
        return attendance;
    }
    vector<int> getMarks() const {
        return marks;
    }
    vector<string> getGrades() const {
        return grades;
    }


    void addCourse(const string& course);
    void addAttendance(const string& date, char status);
    void addMarks(int mark, int index);
    void addGrade(const string& grade, int index);
    void printInfo() const;
    void addTeacherTimetable(const vector<Lecture>& lectures);

    friend void addStudent(vector<TeacherModule>& students, const string& name);
    friend void addCourse(TeacherModule& student, const string& course);
    friend void addCourse(TeacherModule& student, const string& course);
    friend  void uploadAttendance(TeacherModule& student, const string& date, char status);
    friend void uploadMarks(TeacherModule& student, int mark, int index);
    friend void uploadGrades(TeacherModule& student, const string& grade, int index);
    friend TeacherModule* selectStudentByName(vector<TeacherModule>& students, const string& name);
    friend void saveDataToFile(const vector<TeacherModule>& students, const string& filename);
    friend void readDataFromFile(const string& filename, vector<TeacherModule>& students);
};