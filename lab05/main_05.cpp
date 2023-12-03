#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"
#include <iostream>


using namespace std;

int main(int argc, char **argv) {

//    Quiz quiz("Quiz 1", "quiz.txt");
//    cout << quiz.getNumQuestions() << endl;
////    for(int i = 0; i < quiz.getNumQuestions(); i++) {
////        cout << (i + 1) << "." << quiz.getQuestion(i).getText() << endl;
////    }
//
//    for(int i = 0; i < quiz.getNumQuestions(); i++){
//        cout << (i + 1) << "." << quiz.getQuestion(i).getText() << endl;
//        for(int j = 0; j < quiz.getQuestion(i).getAnswers().size(); j++){
//            cout << quiz.getQuestion(i).getAnswers()[j].getText() << endl;
//        }
//    }

    // lab_7

    User users[] = { User("Peter"), User("Kati") };
    Quiz quizzes[] = { Quiz("cpp1", argv[1]), Quiz("cpp2", argv[2]) };

    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);

    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.play();
            cout << "Name: " << game.getUser().getName() << ", score: " <<
                 game.getScore() << endl << endl;
        }
    }

    cout << endl << "****************" << endl;
    cout << "Users' results:" << endl;
    for (int i = 0; i < num_users; ++i) {
        cout << users[i] << endl;
    }
    cout << "****************" << endl;
    return 0;



    return 0;
}