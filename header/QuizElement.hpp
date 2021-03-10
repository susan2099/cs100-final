#ifndef QUIZ_ELEMENT_H 
#define QUIZ_ELEMENT_H 

#include <iostream>

class QuizElement
{

    public:
    virtual ~QuizElement() = default;
    virtual void display(bool includeAnswer, std::ostream& out = std::cout ) = 0;
    virtual int do_quiz(std::ostream& out = std::cout, std::istream& in = std::cin) = 0;
    virtual int total_score() = 0;
};

#endif // QUIZ_ELEMENT_H 
