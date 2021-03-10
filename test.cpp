#include "gtest/gtest.h"
#include "header/QuizElement.hpp"
#include "header/Question.hpp"
#include "header/QuestionTypes/TrueFalseQuestion.hpp"
#include "header/QuestionTypes/MultipleChoiceQuestion.hpp"
#include "header/QuestionTypes/FillInTheBlankQuestion.hpp"
#include "header/Section.hpp"
#include "CSVTest.hpp"

TEST(FillInTheBlank, DisplayQuestion)
{

  std::stringstream out;
  std::istringstream in;

  FillInTheBlankQuestion question("Description", "Answer");

  question.display(false, out);

  EXPECT_EQ(out.str(), "Description\n");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
