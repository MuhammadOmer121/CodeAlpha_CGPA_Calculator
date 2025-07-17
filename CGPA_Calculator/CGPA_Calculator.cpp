#include <iostream>
#include <string>
using namespace std;

class CGPA {
    int noOfCourses;
    string* nameOfCourses;
    string* grade;
    int* cr;
    int totalCredits = 0;
    double cgpa=0.00;
    double* gradePoints;
    double totalgradePoints = 0.00;
public:
    CGPA(int nofC) {
        noOfCourses = nofC;
        nameOfCourses = new string[noOfCourses];
        grade = new string[noOfCourses];
        cr = new int[noOfCourses];
        gradePoints = new double[noOfCourses];
    }

    void input() {
        for (int i = 0; i < noOfCourses; i++) {
            cout << "Enter Name of Course " << (i + 1) << ": ";
            getline(cin, nameOfCourses[i]);
            cout << "Enter Credit Hours for "<< nameOfCourses[i]<<": ";
            cin >> cr[i];
            cin.ignore();
            cout << "Enter grade for " << nameOfCourses[i] << ": ";
            getline(cin,grade[i]);

            if (grade[i].size() <= 2) {
                if (grade[i] == "A+") {
                    gradePoints[i] = 4.00;
                }
                else if (grade[i] == "A") {
                    gradePoints[i] = 3.70;
                }
                else if (grade[i] == "B+") {
                    gradePoints[i] = 3.30;
                }
                else if (grade[i] == "B") {
                    gradePoints[i] = 3.00;
                }
                else if (grade[i] == "B-") {
                    gradePoints[i] = 2.70;
                }
                else if (grade[i] == "C+") {
                    gradePoints[i] = 2.30;
                }
                else if (grade[i] == "C") {
                    gradePoints[i] = 2.00;
                }
                else if (grade[i] == "C-") {
                    gradePoints[i] = 1.70;
                }
                else if (grade[i] == "D") {
                    gradePoints[i] = 1.00;
                }
                else {
                    gradePoints[i] = 0.00;
                }
            }
            else {
                cout << "Invalid Input! " << endl;
            }
        }   
    }

    void calculation() {
        for (int i = 0; i < noOfCourses; i++)
        {
            totalCredits += cr[i]; //each credit is added to total
            totalgradePoints += (gradePoints[i] * cr[i]);

            cgpa = (totalgradePoints / totalCredits);
        }
    }
    void display() {
        for (int i = 0; i < noOfCourses; i++)
        {
            cout << nameOfCourses[i] << "   " << cr[i] << "   " << grade[i] << "   " << gradePoints[i] << endl;
        }
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalgradePoints << endl;
        cout << "GPA: " << cgpa << endl;
    }
    void release() {
        if (nameOfCourses) {
            delete[] nameOfCourses;
            nameOfCourses = nullptr;
        }
        if (grade) {
            delete[] grade;
            grade = nullptr;
        }
        if (cr) {
            delete[] cr;
            cr = nullptr;
        }
        if (gradePoints) {
            delete[] gradePoints;
            gradePoints = nullptr;
        }
    }
    ~CGPA() {
        release();
    }
};
int main()
{
    {
        int tc;
        cout << "Enter total number of courses: ";
        cin >> tc;
        cin.ignore();
        CGPA c(tc);
        c.input();
        c.calculation();
        c.display();
    }
}

