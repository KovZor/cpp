#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Quiz.h"

using namespace std;

const Question &Quiz::getQuestion(int index) const {
    if( index < 0 || index >= questions.size() ){
        throw out_of_range("Invalid index!");
    }
    return questions[index];
}

Quiz::Quiz(const string name, const string &filename){
    this->name = name;
    ifstream file(filename);

    if( !file ){
        throw invalid_argument("File not found!");
    }

    string line;
    Question question;
    vector<Answer> answers;

    while( getline(file, line) ){
        switch( line[0] ){
            case 'Q':
                question.setText( line.substr(2) );
                answers.clear();
                break;
            case 'A':
                answers.push_back( Answer(line.substr(2)) );
                break;
            default:
                istringstream iss( line );
                int value;

                while( iss >> value ){
                    answers[value-1].setCorrect(true);
                }
                question.setAnswers( answers );
                questions.push_back( question );
        }
    }
}
