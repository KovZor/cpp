#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H

#include <string>

using namespace std;

class Answer {
private:
    string text;
    bool correct;
public:
    Answer(string text = "", bool correct = false) : text(text), correct(correct) {};

    const string &getText() const{
        return text;
    }

    void setText(const string &text){
        this->text = text;
    }

    bool isCorrect() const{
        return correct;
    }

    void setCorrect(bool correct){
        this->correct = correct;
    }

};

#endif //LAB5_ANSWER_H
