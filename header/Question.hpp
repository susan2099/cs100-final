#include "QuizElement.hpp"
#include <string>

class Question : public QuizElement 
{
    protected:
    std::string answer;
    public:

    Question(std::string answer){
        this->answer = answer;
    }

    virtual bool IsAnswerCorrect(std::string input) = 0;
    virtual std::string get_answer()
    {
        return answer;
    }
};