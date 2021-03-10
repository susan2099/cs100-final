#ifndef QUESTION_H
#define QUESTION_H

#include "QuizElement.hpp"
#include <string>

class Question : public QuizElement
{
protected:
    std::string description;
    std::string answer;

public:
    Question(std::string description, std::string answer)
    {
        this->description = description;
        this->answer = answer;
    }
    virtual bool IsAnswerCorrect(std::string input) = 0;
    virtual std::string get_answer()
    {
        return answer;
    }
    virtual int total_score()
    {
        return 1;
    }
};

#endif
