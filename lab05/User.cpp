#include "User.h"

int User::counter = 0;

void User::addScore(const string& quizName, double score) {
    scores[quizName] = score;
}

void User::print(ostream& os) const {
    os << "User ID: " << id << endl;
    os << "Name: " << name << endl;
    os << "Scores:" << endl;
    for (const auto& entry : scores) {
        os << entry.first << ": " << entry.second << endl;
    }
}

ostream& operator<<(ostream& os, const User& user) {
    user.print(os);
    return os;
}

double User::getScore(const string& quizName) const {
    return scores.at(quizName);
}
