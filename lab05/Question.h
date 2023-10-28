#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

#include "Answer.h"
#include <vector>

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;
public:
    Question() = default;

    const string &getText() const { return text; }
    const vector<Answer> &getAnswers() const { return answers; }
    void setText(const string &text) { Question::text = text; }
    void setAnswers(const vector<Answer> &answers) { Question::answers = answers; }
};

#endif //LAB5_QUESTION_H
