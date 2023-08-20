#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    int rollNumber;
};

class StudentDataManagement {
private:
    Student students[MAX_STUDENTS];
    int numStudents;

public:
    StudentDataManagement() {
        numStudents = 0;
    }

    void addStudent() {
        if (numStudents >= MAX_STUDENTS) {
            cout << "Maximum number of students reached." << endl;
            return;
        }

        Student student;
        cout << "Enter student name: ";
        cin >> student.name;
        cout << "Enter student roll number: ";
        cin >> student.rollNumber;

        students[numStudents++] = student;
        cout << "Student added successfully." << endl;
    }

    void viewStudents() {
        if (numStudents == 0) {
            cout << "No students found." << endl;
            return;
        }

        cout << "Student List:" << endl;
        for (int i = 0; i < numStudents; ++i) {
            cout << "Name: " << students[i].name << ", Roll Number: " << students[i].rollNumber << endl;
        }
    }

    void searchStudent() {
        if (numStudents == 0) {
            cout << "No students found." << endl;
            return;
        }

        string searchName;
        cout << "Enter student name to search: ";
        cin >> searchName;

        for (int i = 0; i < numStudents; ++i) {
            if (students[i].name == searchName) {
                cout << "Student found." << endl;
                cout << "Name: " << students[i].name << ", Roll Number: " << students[i].rollNumber << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void updateStudent() {
        if (numStudents == 0) {
            cout << "No students found." << endl;
            return;
        }

        string searchName;
        cout << "Enter student name to update: ";
        cin >> searchName;

        for (int i = 0; i < numStudents; ++i) {
            if (students[i].name == searchName) {
                cout << "Enter new student name: ";
                cin >> students[i].name;
                cout << "Enter new roll number: ";
                cin >> students[i].rollNumber;
                cout << "Student updated successfully." << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void deleteStudent() {
        if (numStudents == 0) {
            cout << "No students found." << endl;
            return;
        }

        string searchName;
        cout << "Enter student name to delete: ";
        cin >> searchName;

        for (int i = 0; i < numStudents; ++i) {
            if (students[i].name == searchName) {
                for (int j = i; j < numStudents - 1; ++j) {
                    students[j] = students[j + 1];
                }
                numStudents--;
                cout << "Student deleted successfully." << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }
};

int main() {
    StudentDataManagement dataManagement;
    int choice;

    do {
        cout << "----- Student Data Management -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1:
                dataManagement.addStudent();
                break;
            case 2:
                dataManagement.viewStudents();
                break;
            case 3:
                dataManagement.searchStudent();
                break;
            case 4:
                dataManagement.updateStudent();
                break;
            case 5:
                dataManagement.deleteStudent();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}