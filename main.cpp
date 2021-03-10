#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include <vector>
#include "header/QuestionBankReader.hpp"
#include "header/CSVFileReader.hpp"
//#include "header/JsonFileReader.hpp"

int main(int argc, char** argv){
    //std::string filename = "example.csv";
    std::string filename = argv[1];
    CSVFileReader CSV;
    std::vector<QuizElement*> qVec;

    if ((filename.substr(filename.length() - 4, filename.length())) == ".csv") {
	CSVFileReader CSV;
	qVec = CSV.GetQuestions(filename);
    }/*
    else if ((filename.substr(filename.length() - 5, filename.length())) == ".json") {
	JsonFileReader JSON;
	qVec = JSON.GetQuestions(filename);
    }*/
    else {
	std::cout << "Invalid filetype. Please submit a different quiz." << std::endl;
    }

    //std::vector<QuizElement*> qVec = CSV.GetQuestions(filename);

    Section SectionOne("Main", qVec);
    SectionOne.display(true);
    SectionOne.do_quiz();

    return 0;
}
