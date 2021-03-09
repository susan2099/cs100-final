#ifndef QUIZ_ELEMENT_H 
#define QUIZ_ELEMENT_H 

#include <iostream>

class QuizElement
{
    public:

    virtual void display(bool includeAnswer, std::ostream& out = std::cout ) = 0;
    virtual void do_quiz(std::ostream& out = std::cout, std::istream& in = std::cin) = 0;
};

#endif // QUIZ_ELEMENT_H 
