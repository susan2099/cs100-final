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
	std::vector<JsonQuestionStructure> ChildElements; // For sections
};

QuizElement* to_quiz_element(const JsonQuestionStructure& question){
	QuizElement *element;

	std::cout << "Reading an element, {" << question.Description << ", " << question.Answer << "}" << std::endl;
	std::string type = question.QuestionType;
	if (type == "MC"){
		element = new MultipleChoiceQuestion(question.Description, question.Answer);
	} else if (type == "TF"){
		element = new TrueFalseQuestion(question.Description, question.Answer);
	} else if (type == "Fill"){
		element = new FillInTheBlankQuestion(question.Description, question.Answer);
	} else if (type == "Section") {
		std::vector<QuizElement*> childElements;
		for (auto childElement : question.ChildElements){
			std::cout << "Pushing Child Element to section" << std::endl;
			childElements.push_back(to_quiz_element(childElement));
		}
		element = new Section(question.Description, childElements);
	} else {
		perror("Question type in the json file is invalid");
	}

	return element;
}

void from_json(const json& j, JsonQuestionStructure& q) {
	j.at("QuestionType").get_to(q.QuestionType);
	j.at("Description").get_to(q.Description);
	j.at("Answer").get_to(q.Answer);
	if (j.contains("ChildElements")){
		std::cout << "Has Child Item" << std::endl;
		std::flush(std::cout);
		q.ChildElements = j.at("ChildElements").get<std::vector<JsonQuestionStructure>>();

		std::cout << "Found a node with " << q.ChildElements.size() << " elements" << std::endl;
	}  
}

void to_json(json& j, const JsonQuestionStructure q) {
	perror("unimplemented");
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
			jsonVector.push_back(to_quiz_element(question));
		}


		return jsonVector;
	};
};
#endif
