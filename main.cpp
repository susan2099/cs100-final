#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include <vector>

int main(int argc, char** argv){
    TrueFalseQuestion question("The Capitol is in Washington D.C.","True");
    MultipleChoiceQuestion question2("What year is it? A: 2020, B: 2021, C:2022, D:1900","B");
    FillInTheBlankQuestion question3("What is Caesar's first name?","Julius");

    std::vector<QuizElement*> sectionElements {&question, &question2, &question3};
    Section SectionOne("Section One",sectionElements);
    SectionOne.display(true);
    SectionOne.do_quiz();
}