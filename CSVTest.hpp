#ifndef __CSV_TEST_HPP__
#define __CSV_TEST_HPP__

#include "gtest/gtest.h"

#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/Section.hpp"
#include <vector>
#include "header/QuestionBankReader.hpp"
#include "header/CSVFileReader.hpp"

TEST(CSVTest, EmptyQuiz) {
	std::string filename = "csvTestFiles/test1.csv";
	CSVFileReader CSV;
	std::vector<QuizElement*> qVec;
	qVec = CSV.GetQuestions(filename);

	Section Section("Section", qVec);
	std::stringstream out;
	Section.display(true, out); 
	std::string output = "----Displaying SectionSection with answers----\n----End of Section----Section\n";
	EXPECT_EQ(out.str(), output);
}

TEST(CSVTest, EveryQuestionTypeQuiz) {
        std::string filename = "csvTestFiles/test2.csv";
        CSVFileReader CSV;
        std::vector<QuizElement*> qVec;
	qVec = CSV.GetQuestions(filename);

        Section Section(" Space Quiz", qVec);
        std::stringstream out;
        Section.display(true, out);
        std::string output = "----Displaying Section Space Quiz with answers----\nWhat is the largest planet in the solar system? A: Saturn; B: Mercury; C: Jupiter\nAnswer:C\nThe sun is a _____.\nAnswer:star\nVenus is the closest to Earth in size.\nAnswer:true\n----End of Section---- Space Quiz\n";
        EXPECT_EQ(out.str(), output);
}

TEST(CSVTest, ErrorQuestionTypeQuiz) {
        std::string filename = "csvTestFiles/test3.csv";
        CSVFileReader CSV;
        std::vector<QuizElement*> qVec;
        qVec = CSV.GetQuestions(filename);

        Section Section(" Shark Quiz", qVec);
        std::stringstream out;
        Section.display(true, out);
        std::string output = "----Displaying Section Shark Quiz with answers----\nSharks are fish.\nAnswer:true\nWhat is the biggest shark? A: whale shark; B: great white; C: hammerhead\nAnswer:A\nGreat white sharks have ____ teeth.\nAnswer:300\n----End of Section---- Shark Quiz\n";
	EXPECT_EQ(out.str(), output);
}

TEST(CSVTest, FullErrorQuestionTypeQuiz) {
        std::string filename = "csvTestFiles/test1.csv";
        CSVFileReader CSV;
        std::vector<QuizElement*> qVec;
        qVec = CSV.GetQuestions(filename);

        Section Section("Section", qVec);
        std::stringstream out;
        Section.display(true, out);             
        std::string output = "----Displaying SectionSection with answers----\n----End of Section----Section\n";
        EXPECT_EQ(out.str(), output);
}

TEST(CSVTest, NoAnswerOutputQuiz) {
        std::string filename = "csvTestFiles/test2.csv";
        CSVFileReader CSV;
        std::vector<QuizElement*> qVec;
        qVec = CSV.GetQuestions(filename);

        Section Section(" Space Quiz", qVec);
        std::stringstream out;
        Section.display(false, out);
        std::string output = "----Displaying Section Space Quiz----\nWhat is the largest planet in the solar system? A: Saturn; B: Mercury; C: Jupiter\nThe sun is a _____.\nVenus is the closest to Earth in size.\n----End of Section---- Space Quiz\n";
        EXPECT_EQ(out.str(), output);
}

#endif // __CSV_TEST_HPP__
