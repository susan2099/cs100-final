#ifndef QUIZ_ELEMENT_H 
#define QUIZ_ELEMENT_H 

class QuizElement
{
    public:
    virtual void display(bool includeAnswer) = 0;
    virtual int do_quiz() = 0;
    virtual int total_score() = 0;
};

#endif // QUIZ_ELEMENT_H 
