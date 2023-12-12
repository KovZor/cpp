#ifndef LAB11_EXAMMANAGER_H
#define LAB11_EXAMMANAGER_H

// declarations

#include <vector>
#include "Student.h"

using namespace std;

class ExamManager {
private:
    vector<Student> students;

public:
    void readStudentData( const string &filename );
    void readGrades( const string &filename, const string &subject );
    void calculateAverages();
    void printSuccessfulStudents();
};

#endif //LAB11_EXAMMANAGER_H
