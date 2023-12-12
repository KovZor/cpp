#include <fstream>
#include <iostream>
#include <algorithm>
#include "ExamManager.h"

using namespace std;

// definitions

void ExamManager::readStudentData(const string &filename) {
    ifstream file(filename);
    if ( !file.is_open() ) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    int id;
    string firstName, lastName;
    while ( file >> id >> firstName >> lastName ) {
        students.emplace_back(id, firstName, lastName);
    }

    file.close();
}

void ExamManager::readGrades(const string &filename, const string &subject) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    int id;
    double grade;
    while ( file >> id >> grade ) {
        auto it = find_if(students.begin(), students.end(), [id](const Student &student) {
            return student.getId() == id;
        });

        if ( it != students.end() ) {
            it->addGrade(subject, grade);
        }
    }

    file.close();
}

void ExamManager::calculateAverages() {
    for (auto &student : students) {
        student.computeAverage();
    }
}

void ExamManager::printSuccessfulStudents() {
    int successfulCount = 0;
    for (const auto &student : students) {
        bool allFives = all_of(student.getGrades().begin(), student.getGrades().end(),
                               [](const auto &grade) { return grade.second == 5.0; });

        if ( allFives && student.getAverage() >= 6.0 ) {
            // cout << student << endl;
            successfulCount++;
        }
    }

    cout << "Number of successful students: " << successfulCount << endl;
}