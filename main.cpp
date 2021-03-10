#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include <vector>
#include "header/QuestionBankReader.hpp"
#include "header/CSVFileReader.hpp"
#include "header/JsonFileReader.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    if (argc == 2) filename = argv[1];
    else filename = "example.json";


    CSVFileReader CSV;
    std::vector<QuizElement *> qVec;
    if ((filename.substr(filename.length() - 4, filename.length())) == ".csv")
    {
        CSVFileReader CSV;
        qVec = CSV.GetQuestions(filename);
    } 
    else if ((filename.substr(filename.length() - 5, filename.length())) == ".json") {
	    JsonStrategy JSON;
	    qVec = JSON.GetQuestions(filename);
    }
    else
    {
        std::cout << "Invalid filetype. Please submit a different quiz." << std::endl;
    }

    Section SectionOne("Main", qVec);
    SectionOne.display(true);
    int result = SectionOne.do_quiz();
    cout << "Score : " << result << " / " << SectionOne.total_score() << std::endl;

    /*for (auto p : qVec) {
	delete p;
    } 
    qVec.clear();*/

    return 0;
}
