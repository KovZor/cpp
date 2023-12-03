#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include <iostream>
#include "Quiz.h"
#include "User.h"

using namespace std;

class QuizGame {
private:
    User& user;
    const Quiz& quiz;
    double score = 0;
public:
    // constructor
    QuizGame(User& user, const Quiz& quiz) : user(user), quiz(quiz){}

    // main function to play the game
    void play();

    // getters
    double getScore() const { return score; }
    User getUser() const { return user; }
    Quiz getQuiz() const { return quiz; }
};

#endif //LAB5_QUIZGAME_H
