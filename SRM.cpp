
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int rollNo;
    string name;
    float marks;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// Add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\nStudent record limit reached!\n";
        return;
    }

    Student s;

    cout << "\nEnter Roll Number: ";
    if (!(cin >> s.rollNo) || s.rollNo <= 0) {
        cout << "Invalid roll number!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Check for duplicate roll number
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == s.rollNo) {
            cout << "Roll number already exists!\n";
            return;
        }
    }

    cout << "Enter Student Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);

    if (s.name.empty()) {
        cout << "Name cannot be empty!\n";
        return;
    }

    cout << "Enter Marks (0-100): ";
    if (!(cin >> s.marks) || s.marks < 0 || s.marks > 100) {
        cout << "Invalid marks! Marks must be between 0 and 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    students[studentCount] = s;
    studentCount++;

    cout << "\nStudent record added successfully!\n";
}

// Display all student records
void displayStudents() {
    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n========== STUDENT RECORDS ==========\n";
    cout << "Roll No.\tName\t\tMarks\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        cout << students[i].rollNo << "\t\t"
             << students[i].name << "\t\t"
             << students[i].marks << '\n';
    }
}

// Search student using Linear Search
void searchStudent() {
    if (studentCount == 0) {
        cout << "\nNo records available to search.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to Search: ";

    if (!(cin >> roll)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << students[i].rollNo << '\n';
            cout << "Name       : " << students[i].name << '\n';
            cout << "Marks      : " << students[i].marks << '\n';
            return;
        }
    }

    cout << "\nStudent record not found.\n";
}

// Sort records using Bubble Sort
void sortStudents() {
    if (studentCount < 2) {
        cout << "\nNot enough records to sort.\n";
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "\nRecords sorted by roll number successfully!\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Sort Records by Roll Number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                sortStudents();
                break;

            case 5:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please select 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}
