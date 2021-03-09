#ifndef _QUESTION_BANK_READER
#define _QUESTION_BANK_READER
#include "QuizElement.hpp"
#include <vector>
#include <string>

using namespace std;

class QuestionBankReader {
    public:
		virtual vector<QuizElement*> GetQuestions(string fileName) = 0;
};

#endif //QUESTION_BANK_READER
