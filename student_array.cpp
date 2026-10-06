#include <iostream>
#include <string>
using namespace std;

// max number of students
const int MAX_STUDENTS = 20;

// structure to hold student information
struct Student {
    string registrationNumber;
    string name;
    int marks;
};

// Function  to add student
void addStudent(Student students[], int& count) {
    if (count >= MAX_STUDENTS) {
        cout << "\nCannot add more students. Maximum limit reached.\n" << endl;
        return;
    }

    cout << "Enter registration number: ";
    cin >> students[count].registrationNumber;
    cout << "Enter Student name: ";
    cin.ignore(); // to ignore the newline character left in the buffer
    getline(cin, students[count].name);
    cout << "Enter marks: ";
    cin >> students[count].marks;

    count++;
    cout << "Student added successfully!" << endl;
};

// function to delete student
void deleteStudent(Student students[], int& count) {
    if (count == 0) {
        cout << "\nNo students to delete.\n" << endl;
        return;
    }

    string regNo;
    cout << "Enter registration number of the student to delete: ";
    cin >> regNo;

    int position = -1;

    // Search for the student by registration number
    for (int i = 0; i < count; i++) {
        if (students[i].registrationNumber == regNo) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "\nStudent not found.\n" << endl;
        return;
    }

    // Shift students to fill the gap
    for (int i = position; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;
    cout << "\nStudent deleted successfully.\n" << endl;
}

// function to update student's marks
void updateStudentMarks(Student students[], int count) {
    if (count == 0) {
        cout << "\nNo students to update.\n" << endl;
        return;
    }

    string regNo;
    cout << "Enter registration number of the student to update marks: ";
    cin >> regNo;

    for (int i = 0; i < count; i++) {
        if (students[i].registrationNumber == regNo) {
            cout << "Enter new marks: ";
            cin >> students[i].marks;
            cout << "\nMarks updated successfully.\n" << endl;
            return;
        }
    }
    cout << "\nStudent not found.\n" << endl;
}   

// function to search for a student
void searchStudent(Student students[], int count) {
    if (count == 0) {
        cout << "\nNo students to search.\n" << endl;
        return;
    }

    cout << "Enter registration number of the student to search: ";
    string regNo;
    cin >> regNo;

    for (int i = 0; i < count; i++) {
        if (students[i].registrationNumber == regNo) {
            cout << "\nStudent found:\n";
            cout << "Registration Number: " << students[i].registrationNumber << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }
    cout << "\nStudent not found.\n" << endl;
}

// function to display all students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "\nNo students to display.\n" << endl;
        return;
    }        

    cout << "\n==================== All Students ====================\n";

    for (int i = 0; i < count; i++) {
        cout << "Registration Number: " << students[i].registrationNumber << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << "-----------------------------------------------------\n";
    }
}

// Main function
int main() {
    Student students[MAX_STUDENTS];
    int count = 0; // current number of students
    int choice;

    do {
        cout << "\n==================== Student Management System ====================\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student Marks\n";
        cout << "4. Search Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                deleteStudent(students, count);
                break;
            case 3:
                updateStudentMarks(students, count);
                break;
            case 4:
                searchStudent(students, count);
                break;
            case 5:
                displayStudents(students, count);
                break;
            case 6:
                cout << "\nExiting the program.\n" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n" << endl;
        }
    } while (choice != 6);

    return 0;
}