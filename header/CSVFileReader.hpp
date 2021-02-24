#ifndef __CSV_FILE_READER_HPP__
#define __CSV_FILE_READER_HPP__

#include <fstream>
#include <vector>
#include "QuestionBankReader.hpp"

class CSVFileReader : QuestionBankReader {
    public:
	std::vec<QuizElement> GetQuestions(string filename) {
	    std::vec<QuizElement> CSVFileQuestions; // initialize empty vector
	    QuizElement individualQuestion;
	    std::ifstream quizFile(filename);	// open file	    

	    while (!quizFile.eof()) { // end of file not reached
		// add a count to number every question?
		CSVFileQuestions.push_back(std::getline(filename, individualQuestion));
	    }
	    return CSVFileQuestions;	// return the filled vector
	}
};

#endif
