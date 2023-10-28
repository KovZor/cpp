#include "Quiz.h"
#include <iostream>


using namespace std;

int main(int argc, char **argv) {

    Quiz quiz("Quiz 1", "quiz.txt");
    cout << quiz.getNumQuestions() << endl;
    for(int i = 0; i < quiz.getNumQuestions(); i++) {
        cout << (i + 1) << "." << quiz.getQuestion(i).getText() << endl;
    }

    for(int i = 0; i < quiz.getNumQuestions(); i++){
        cout << (i + 1) << "." << quiz.getQuestion(i).getText() << endl;
        for(int j = 0; j < quiz.getQuestion(i).getAnswers().size(); j++){
            cout << quiz.getQuestion(i).getAnswers()[j].getText()[j] << endl;
        }
    }


    return 0;
}