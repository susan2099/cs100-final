#ifndef __JSON_TEST_HPP__
#define __JSON_TEST_HPP__

#include "gtest/gtest.h"

#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/Section.hpp"
#include <vector>
#include "header/QuestionBankReader.hpp"
#include "header/JsonFileReader.hpp"

TEST(JsonStrategy, AcceptEmptyQuiz) {
	std::string filename = "jsonTestFiles/test1.json";
	JsonStrategy json;
	std::vector<QuizElement*> qVec;
	qVec = json.GetQuestions(filename);

	Section Section("Section One", qVec);
	std::stringstream out;
	Section.display(true, out); 
	std::string output = "----Displaying Section \"Section One\" with answers----\n----End of Section----Section One\n";
	EXPECT_EQ(out.str(), output);
}

TEST(JsonStrategy, EveryQuestionTypeQuiz) {
        std::string filename = "jsonTestFiles/test2.json";
        JsonStrategy json;
        std::vector<QuizElement*> qVec;
	qVec = json.GetQuestions(filename);

        Section Section("Space Quiz", qVec);
        std::stringstream out;
        Section.display(true, out);
        std::string output = "----Displaying Section \"Space Quiz\" with answers----\nWhat is the largest planet in the solar system? A: Saturn; B: Mercury; C: Jupiter\nAnswer:C\nThe sun is a _____.\nAnswer:star\nVenus is the closest to Earth in size.\nAnswer:True\n----End of Section----Space Quiz\n";
        EXPECT_EQ(out.str(), output);
}

TEST(JsonStrategy, NoAnswerOutputQuiz) {
        std::string filename = "jsonTestFiles/test2.json";
        JsonStrategy json;
        std::vector<QuizElement*> qVec;
        qVec = json.GetQuestions(filename);

        Section Section("Main", qVec);
        std::stringstream out;
        Section.display(false, out);
        std::string output = "----Displaying Section \"Main\"----\nWhat is the largest planet in the solar system? A: Saturn; B: Mercury; C: Jupiter\nThe sun is a _____.\nVenus is the closest to Earth in size.\n----End of Section----Main\n";
        EXPECT_EQ(out.str(), output);
}

TEST(JsonStrategy, ParseSections) {
        std::string filename = "jsonTestFiles/test3.json";
        JsonStrategy json;
        std::vector<QuizElement*> qVec;
        qVec = json.GetQuestions(filename);

        Section Section("Space Quiz", qVec);
        std::stringstream out;
        Section.display(false, out);
        std::string output = "----Displaying Section \"Space Quiz\"----\n----Displaying Section \"History Section\"----\nWas the sky always blue?\n----End of Section----History Section\n----End of Section----Space Quiz\n";
        EXPECT_EQ(out.str(), output);
}



#endif // __JSON_TEST_HPP__
