#ifndef _QUESTION_BANK_READER
#define _QUESTION_BANK_READER
#include "QuizElement.hpp"

public interface ImportStrategy {
	std::vec<QuizElement> GetQuestions(string fileName);
};

#endif //QUESTION_BANK_READER
