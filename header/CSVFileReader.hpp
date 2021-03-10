#ifndef __CSV_FILE_READER_HPP__
#define __CSV_FILE_READER_HPP__

#include <fstream>
#include <vector>
#include "QuestionBankReader.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "Question.hpp"

using namespace std;

class CSVFileReader : public QuestionBankReader {
    public:
	/*~CSVFileReader() {	// destructor
    	    while (CSVFileQuestions.size() > 0) {
        	delete CSVFileQuestions.back();             // delete the pointer
        	CSVFileQuestions.pop_back();
    	    }
	} */
	std::vector<QuizElement*> GetQuestions(string filename) {
	    std::vector<QuizElement*> CSVFileQuestions; // initialize empty vector
	    //QuizElement* individualQuestion; // = new Question();
	    std::ifstream quizFile(filename);	// open file	    

	    while (!quizFile.eof()) { // end of file not reached
		// add a count to number every question?
		// file set up: TYPE, description, answer
		string questionLine;
		std::getline(quizFile, questionLine);
		//std::cout << questionLine << std::endl << std::endl;

		std::stringstream ss(questionLine);
		
		std::string type, desc, answer;
		std::getline(ss, type, ',');
		std::getline(ss, desc, ',');		 
		std::getline(ss, answer, ',');

		//std::cout << type << "   " << desc << "   " << answer << std::endl;

		if (type == "MC") {
		    CSVFileQuestions.push_back(new MultipleChoiceQuestion(desc, answer));
		}
		else if (type == "TF") {
		    CSVFileQuestions.push_back(new TrueFalseQuestion(desc, answer));
		}
		else if (type == "Fill") {
		    CSVFileQuestions.push_back(new FillInTheBlankQuestion(desc, answer));
		}
		// else ==> error message?
	    }
	    //std::cout << CSVFileQuestions.size() << endl;
	    return CSVFileQuestions;	// return the filled vector
	}
};

 #endif
