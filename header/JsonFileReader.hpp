#ifndef _JSONSTRATEGY_
#define _JSONSTRATEGY_
#include "QuestionBankReader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
class JsonStrategy : QuestionBankReader
{
public:
	std::vector<QuizElement *> GetQuestions(std::string filename)
	{
		std::vector<QuizElement *> jsonVector;

		

		return jsonVector;
	};
};
#endif
