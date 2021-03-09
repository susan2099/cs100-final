#ifndef QUIZ_ELEMENT_H 
#define QUIZ_ELEMENT_H 

class QuizElement
{
    public:
    virtual void display(bool includeAnswer) = 0;
    virtual void do_quiz() = 0;
};

#endif // QUIZ_ELEMENT_H 
