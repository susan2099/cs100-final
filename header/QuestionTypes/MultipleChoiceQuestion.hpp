#include "../QuizElement.hpp"
#include "../Question.hpp"
#include <iostream>

class MultipleChoiceQuestion : public Question
{
    public:
    MultipleChoiceQuestion(std::string description, std::string answer) : Question(description, answer){}

    bool IsAnswerCorrect(std::string input){
        return input == answer;
    }

    virtual void display(bool includeAnswer){
        std::cout << description << std::endl;
        if (includeAnswer) std::cout << "Answer:" << answer << std::endl;
    }

    virtual void do_quiz(){
        std::cout << "Which of these choices is correct?" << std::endl;
        display(false);
        std::string result;
        std::cin >> result;
        bool isCorrect = IsAnswerCorrect(result);
        if (isCorrect){
            std::cout << "Correct" << std::endl;
        } else {
            std::cout << "Incorrect" << std::endl;
        }
    }
};