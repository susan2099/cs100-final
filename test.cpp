#include "gtest/gtest.h"
#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include "CSVTest.hpp"
#include "JsonTest.hpp"

class QuestionMock : public Question {
  private:
    void MarkFunctionCalled(){
      WasFunctionCalled = true;
    }
  
  public:
      QuestionMock() : Question("",""){}

      bool WasFunctionCalled = false;

    bool IsAnswerCorrect(std::string input){
        return true;
    }

    virtual void display(bool includeAnswer, std::ostream& out = std::cout){
        MarkFunctionCalled();
    }


    virtual int do_quiz(std::ostream& out = std::cout, std::istream& in = std::cin){
        MarkFunctionCalled();
        return 1;
    }
};

TEST(Section, RunsDisplayOnChildElements)
{
  std::stringstream out;
  QuestionMock* mock = new QuestionMock();
  std::vector<QuizElement*> mockItem;
  mockItem.push_back(mock);
  Section section("Section 1", mockItem);

  section.display(false,out);
  EXPECT_TRUE(mock->WasFunctionCalled);
}

TEST(Section, RunsDoQuizOnChildElements)
{
  std::istringstream in;
  std::stringstream out;
  QuestionMock* mock = new QuestionMock();
  std::vector<QuizElement*> mockItem;
  mockItem.push_back(mock);
  Section section("Section 1", mockItem);

  section.do_quiz(out, in);
  EXPECT_TRUE(mock->WasFunctionCalled);
}

TEST(FillInTheBlankQuestion, DisplayQuestion)
{
  std::stringstream out;
  std::istringstream in;

  FillInTheBlankQuestion question("Description", "Answer");

  question.display(false, out);

  EXPECT_EQ(out.str(), "Description\n");
}

TEST(FillInTheBlankQuestion, CheckTrueAnswer)
{
  std::stringstream out;
  std::istringstream in("Answer\n");

  FillInTheBlankQuestion question("Description", "Answer");

  EXPECT_EQ(question.do_quiz(out, in), 1);
}

TEST(FillInTheBlankQuestion, MarkIncorrectAnswer)
{
  std::stringstream out;
  std::istringstream in("NotTheAnswer\n");

  FillInTheBlankQuestion question("Description", "Answer");

  EXPECT_EQ(question.do_quiz(out, in), 0);
}


TEST(FillInTheBlankQuestion, MarkLongAnswer)
{
  std::stringstream out;
  std::istringstream in("abcdefghijklmnopqrstuvwxyz\n");

  FillInTheBlankQuestion question("Description", "Answer");

  EXPECT_EQ(question.do_quiz(out, in), 0);
}


TEST(MultipleChoiceQuestion, DisplayQuestion)
{
  std::stringstream out;
  std::istringstream in;

  MultipleChoiceQuestion question("A,B,C,D", "A");

  question.display(false, out);

  EXPECT_EQ(out.str(), "A,B,C,D\n");
}

TEST(MultipleChoiceQuestion, CheckTrueAnswer)
{
  std::stringstream out;
  std::istringstream in("A\n");

  MultipleChoiceQuestion question("A,B,C,D", "A");

  EXPECT_EQ(question.do_quiz(out, in), 1);
}

TEST(MultipleChoiceQuestion, MarkIncorrectAnswer)
{
  std::stringstream out;
  std::istringstream in("\n");

  MultipleChoiceQuestion question("A,B,C,D", "A");

  EXPECT_EQ(question.do_quiz(out, in), 0);
}

TEST(MultipleChoiceQuestion, MarkNoAnswerChoice) {
  std::stringstream out;
  std::istringstream in("P\n");

  MultipleChoiceQuestion question("A,B,C,D", "A");
  
  EXPECT_EQ(question.do_quiz(out, in), 0);
}

TEST(TrueFalseQuestion, DisplayQuestion)
{
  std::stringstream out;
  std::istringstream in;

  TrueFalseQuestion question("Is water blue?", "True");

  question.display(false, out);

  EXPECT_EQ(out.str(), "Is water blue?\n");
}

TEST(TrueFalseQuestion, CheckTrueAnswer)
{
  std::stringstream out;
  std::istringstream in("True\n");

  TrueFalseQuestion question("Is water blue", "True");

  EXPECT_EQ(question.do_quiz(out, in), 1);
}

TEST(TrueFalseQuestion, MarkIncorrectAnswer)
{
  std::stringstream out;
  std::istringstream in("False\n");

  TrueFalseQuestion question("Is water blue", "True");

  EXPECT_EQ(question.do_quiz(out, in), 0);
}

TEST(TrueFalseQuestion, MarkNoAnswerChoice ) {
  std::stringstream out;
  std::istringstream in("Hi\n");

  TrueFalseQuestion question("Is water blue", "True");

  EXPECT_EQ(question.do_quiz(out, in), 0);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
