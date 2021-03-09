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
    std::vector<QuizElement *> ChildElements;

public:
    Section(std::string sectionName, std::vector<QuizElement *> childElements)
    {
        SectionName = sectionName;
        ChildElements = childElements;
    }

    virtual void display(bool includeAnswer, std::ostream& out = std::cout){
        out << "----Displaying Section" << SectionName;
        if (includeAnswer) {
            out << " with answers";
        }
        out << "----" << std::endl;
        for (auto element : ChildElements){
            element->display(includeAnswer, out);
        }
        out << "----End of Section----" << SectionName << std::endl;
    };

    virtual int total_score()
    {
        int totalScore = 0;
        for (auto element : ChildElements)
        {
            totalScore += element->do_quiz();
        }
        return totalScore;
    }

    virtual int do_quiz(std::ostream& out = std::cout, std::istream& in = std::cin){
        out << "----Starting Quiz Section----" << SectionName << std::endl;
        int total = 0;
        for (auto element : ChildElements){
            total += element->do_quiz(out, in);
        }
        out << "----End of Quiz Section----" << SectionName << std::endl;
        return total;
    }
};

#endif // SECTION_H 
