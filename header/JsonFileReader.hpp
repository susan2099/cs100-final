#ifndef _JSONSTRATEGY_
#define _JSONSTRATEGY_
#include "QuestionBankReader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
class JsonStrategy: QuestionBankReader {
   public:
		std::vector<QuizElement*>GetQuestions(std::string filename) {
		std::vector<QuizElement*> JsonVector;
		std::ifstream json(filename);
		QuizElement* individualQuestion;
		while(!json.eof()) {
			//This doesn't look like JSON yet
			//Here is what JSON looks like: https://www.w3schools.com/whatis/whatis_json.asp
			jsonVector.push_back(getline(filename, individualQuestion));
		}
		json.close();
		return jsonVector; 
};

#endif
