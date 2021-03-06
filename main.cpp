#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include <vector>
#include "header/QuestionBankReader.hpp"
#include "header/CSVFileReader.hpp"

int main(int argv, char** argc){
    std::string filename = "example.csv";
    CSVFileReader CSV;
    CSV.GetQuestions(filename);

    return 0;
}
