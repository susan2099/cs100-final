#ifndef _JSONSTRATEGY_
#define _JSONSTRATEGY_
#include "QuestionBankReader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "QuizElement.hpp"
#include "Question.hpp"
#include "Section.hpp"
#include <vector>
#include "QuestionBankReader.hpp"


using json = nlohmann::json;


struct JsonQuestionStructure {
	std::string QuestionType;
	std::string Description;
	std::string Answer;
};

void to_json(json& j, const JsonQuestionStructure& q) {
    j = json{{"QuestionType", q.QuestionType}, {"Description", q.Description}, {"Answer", q.Answer}};
}

void from_json(const json& j, JsonQuestionStructure& q) {
	j.at("QuestionType").get_to(q.QuestionType);
	j.at("Description").get_to(q.Description);
	j.at("Answer").get_to(q.Answer);
}


class JsonStrategy : QuestionBankReader
{
public:
	std::vector<QuizElement *> GetQuestions(std::string filename)
	{
		std::ifstream input(filename);
		json j;
		input >> j;

		std::vector<JsonQuestionStructure> questions = j.get<std::vector<JsonQuestionStructure>>();
		std::vector<QuizElement *> jsonVector;
		for (auto question : questions){

			QuizElement* element;
			
			std::string type = question.QuestionType;
			if (type == "MC"){
				element = new MultipleChoiceQuestion(question.Description, question.Answer);
			} else if (type == "TF"){
				element = new TrueFalseQuestion(question.Description, question.Answer);
			} else if (type == "Fill"){
				element = new FillInTheBlankQuestion(question.Description, question.Answer);
			} else {
				perror("Question type in the json file is invalid");
			}

			jsonVector.push_back(element);
		}


		return jsonVector;
	};
};
#endif
