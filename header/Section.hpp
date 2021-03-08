#include "QuizElement.hpp"
#include <vector>
#include <string>
#include <iostream>
#ifndef SECTION_H 
#define SECTION_H 

class Section : QuizElement
{
private:
    std::string SectionName;
    std::vector<QuizElement*> ChildElements;

public:
    Section(std::string sectionName, std::vector<QuizElement*> childElements){
        SectionName = sectionName;
        ChildElements = childElements;
    }

    virtual void display(bool includeAnswer){


        std::cout << "----Displaying Section" << SectionName;
        if (includeAnswer) {
            std::cout << " with answers";
        }
        std::cout << "----" << std::endl;

        for (auto element : ChildElements){
            element->display(includeAnswer);
        }
        std::cout << "----End of Section----" << SectionName << std::endl;

    };
    virtual void do_quiz(){
        std::cout << "----Starting Quiz Section----" << SectionName << std::endl;
        for (auto element : ChildElements){
            element->do_quiz();
        }
        std::cout << "----End of Quiz Section----" << SectionName << std::endl;
    }
};

#endif // SECTION_H 
