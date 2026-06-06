#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    int numCourses;

    cout << "===== CGPA Calculator =====" << endl;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<float> grades(numCourses);
    vector<int> credits(numCourses);

    float totalGradePoints = 0;
    int totalCredits = 0;

    // Input Course Details
    for (int i = 0; i < numCourses; i++) {

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courseNames[i];

        cout << "Enter grade point: ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    // Calculate GPA / CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display Results
    cout << "\n===== Student Result =====" << endl;

    cout << left
         << setw(15) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits"
         << setw(15) << "Grade Points"
         << endl;

    for (int i = 0; i < numCourses; i++) {

        float gradePoints = grades[i] * credits[i];

        cout << left
             << setw(15) << courseNames[i]
             << setw(15) << grades[i]
             << setw(15) << credits[i]
             << setw(15) << gradePoints
             << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << fixed << setprecision(2);

    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}