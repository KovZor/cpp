#include "QuizGame.h"

void QuizGame::play() {
    cout << user.getName() << ": Please answer the following questions:\n" << endl;

    int rightChoice;

    for (int i = 0; i < quiz.getNumQuestions(); ++i) {
        const Question &question = quiz.getQuestion(i);

        cout << "Question " << (i + 1) << ": " << question.getText() << endl;

        for (int j = 0; j < question.getAnswers().size(); ++j) {
            cout << (1 + j) << ". " << question.getAnswers()[j].getText() << endl;
            if( question.getAnswers()[j].isCorrect() ){
                rightChoice = j + 1;
            }
        }

        int userChoice;
        cout << "Your choice: ";
        cin >> userChoice;

        if( userChoice == rightChoice ){
            user.addScore( getQuiz().getName(), 1.0);
        }
        cout << endl;
    }
}
