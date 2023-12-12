#include <iostream>
#include <fstream>
#include "ExamManager.h"

using namespace std;

int main() {
    ExamManager examManager;

    // read student data
    examManager.readStudentData("names.txt");

    // reading grades from the different subjects
    examManager.readGrades("hungarian.txt", "Hungarian");
    examManager.readGrades("romanian.txt", "Romanian");
    examManager.readGrades("math.txt", "Math");

    // calculate average
    examManager.calculateAverages();

    // print the successful student who graduated
    examManager.printSuccessfulStudents();

    return 0;
}