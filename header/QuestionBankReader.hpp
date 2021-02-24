#ifndef _QUESTION_BANK_READER
#define _QUESTION_BANK_READER
#include "QuizElement.hpp"


class QuestionBankReader {
    public:
	std::vector<QuizElement> GetQuestions(std::string fileName);
};

#endif //QUESTION_BANK_READER
