#include "../QuizElement.hpp"
#include "../Question.hpp"

class TrueFalseQuestion : public Question
{
    TrueFalseQuestion(std::string answer) : Question(answer){}

    bool IsAnswerCorrect(std::string input){
    }
};