#ifndef _QUESTION_BANK_READER
#define _QUESTION_BANK_READER
#include "QuizElement.hpp"
#include <vector>
#include <string>

using namespace std;

class QuestionBankReader {
    public:
	vector<QuizElement*> GetQuestions(string fileName);
	//vector<int> GetQuestions(string fileName);
};

#endif //QUESTION_BANK_READER
