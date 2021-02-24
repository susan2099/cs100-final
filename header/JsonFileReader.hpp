#ifndef _JSONSTRATEGY_
#define _JSONSTRATEGY_
#include "QuestionBankReader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
class JsonStrategy: QuestionBankReader {
   public:
	std::vec<QuizElement>GetQuestions(string filename) {
		std::vector<QuizElement> JsonVector;
		std::ifstream json(filename);
		QuizElement individualQuestion;
		while(!json.eof()) {
			jsonVector.push_back(getline(filename, individualQuestion));
		}
		json.close();
		return jsonVector[]; 
};

#endif
