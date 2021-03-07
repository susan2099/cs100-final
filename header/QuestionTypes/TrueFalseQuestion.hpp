#include "../QuizElement.hpp"
#include "../Question.hpp"
#include <iostream>

class TrueFalseQuestion : public Question
{
    public:
    TrueFalseQuestion(std::string description, std::string answer) : Question(description, answer){}

    bool IsAnswerCorrect(std::string input){
        return input == answer;
    }

    virtual void display(bool includeAnswer){
        std::cout << description << std::endl;
        if (includeAnswer) std::cout << "Answer:" << answer << std::endl;
    }

    virtual int do_quiz(){
        std::cout << "True or False?:" << std::endl;
        display(false);
        std::string result;
        std::cin >> result;
        bool isCorrect = IsAnswerCorrect(result);
	int score = 0;
        if (isCorrect){
	    score++;
            std::cout << "Correct" << std::endl;
        } else {
            std::cout << "Incorrect" << std::endl;
        }
	return score;
    }
};
