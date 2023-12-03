#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include "Question.h"

class Quiz{
private:
    string name;
    vector<Question> questions;
public:
    Quiz(const string name, const string &filename);
    const Question &getQuestion(int index) const;
    int getNumQuestions() const { return questions.size(); }
    string getName(){ return this->name; }
};

#endif //LAB5_QUIZ_H
