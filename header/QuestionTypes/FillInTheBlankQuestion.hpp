#include "../QuizElement.hpp"
#include "../Question.hpp"
#include <iostream>

class FillInTheBlankQuestion : public Question
{
    public:
    FillInTheBlankQuestion(std::string description, std::string answer) : Question(description, answer){}

    bool IsAnswerCorrect(std::string input){
        return input == answer;
    }

    virtual void display(bool includeAnswer, std::ostream& out = std::cout){
        out << description << std::endl;
        if (includeAnswer) out << "Answer:" << answer << std::endl;
    }


    virtual int do_quiz(std::ostream& out = std::cout, std::istream& in = std::cin){
        out << "Fill in the blank:" << std::endl;
        display(false, out);
        std::string result;
        in >> result;
        bool isCorrect = IsAnswerCorrect(result);
        if (isCorrect){
            out << "Correct" << std::endl;
            return 1;
        } else {
            out << "Incorrect" << std::endl;
            return 0;
        }
    }
};
