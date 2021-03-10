# Quiz Maker
Authors: [Susan Noori](https://github.com/susan2099), [Lunette Si](https://github.com/lunettesi), [Henry Moore](https://github.com/hmoorerg)

## Project Description
### Why is it important or interesting to you?
It is important, when it comes to creating and grading, that quizzes are efficient. Sometimes, when taking online quizzes, connectivity issues arise and the student loses all of their progress. By allowing teachers to directly upload the test file, the student can answer it no matter where they are without needing high-speed internet, alleviating this issue. Additionally, this quiz maker can also be used for fun events like trivia games, where the questions are more focused on interesting facts. 
### What languages/tools/technologies do you plan to use?
We will be using C++ for our project. We also ended up using the  nlohmann/json with approval from the professor in order to speed up parsing development. 
### What will be the input/output of your project?
First, a teacher user will input a file including all of the questions and the accepted answers. The questions can be multiple choice, true/false, and free response; for all questions except free response, the correct answer would also be included. Then, a student user can take the uploaded quiz. Each question will be displayed, and once the user types in their answer, the next question would show up, until the quiz is finished. Once the quiz is completed, the program will then display all the questions again, this time with both the user's answers and the correct answer.
### What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
One of the design patterns we will be using is the Composite pattern. Our problem is that the application will have to split questions into different sections. By using the composite pattern, we can draw questions outside of sections in the same way that we draw questions inside of sections by calling the draw method that will exist in the section class and question class. It will also allow us to easily create new kinds of questions by simply adding a new class to the project. This design pattern is a good solution because it will play a major role in reducing coupling in our design, allowing for changes in the future if necessary.

The other design pattern we will use is the Strategy Pattern. We chose this pattern so we can make question pools using a variety of file types (such as JSON or CSV) by just using the strategy interface and not change the rest of the core logic. Because there are multiple file types that can contain our quiz questions, it is essential that we do not write repetitive code for the implementation of our file types. A Strategy Pattern solves this issue by making it simple to call the certain file which calls that file reader and uses the question bank from that file. Although the project will currently only use the strategy pattern to handle CSV and JSON filetypes, in the future this pattern would give us the opportunity to create different file types that contain question banks to make the quiz maker more flexible for users.

## Class Diagram
 We will be using the Composite pattern (at the top of the diagram) as well as the Strategy pattern (below the composite pattern on the diagram) in this project. 

The composite pattern will allow us to separate the quiz into different sections or even subsections. A section can be placed anywhere a question can be placed, allowing complete flexibility in how quizzes are organized.

The strategy pattern allows for more flexibility in terms of file formats. We plan to accept multiple file formats and with the strategy pattern we can inject a class that handles the file format that the user wishes to use. This will allow us to support CSV and JSON files with the opportunity to easily extend to more formats in the future.

 ![Class Diagram](FinalProjectDiagram.png)
 
 ## Screenshots
 .csv filetype input:
 
![Screen Shot 2021-03-09 at 7 27 07 PM](https://user-images.githubusercontent.com/76899884/110572165-c1264200-810d-11eb-9c6a-5f7154273ef9.png)

.csv filetype output:

![Screen Shot 2021-03-09 at 7 47 38 PM](https://user-images.githubusercontent.com/76899884/110676379-bceb3a80-8188-11eb-96d2-e22ecbdc4e18.png)

.json filetype input:

![Screen Shot 2021-03-09 at 7 27 42 PM](https://user-images.githubusercontent.com/76899884/110572172-c4b9c900-810d-11eb-872e-c9cfbe41ad74.png)

.json filetype output:

![Screen Shot 2021-03-09 at 7 48 05 PM](https://user-images.githubusercontent.com/76899884/110676415-ca082980-8188-11eb-969c-a38050e9fe44.png)

 ## Installation/Usage
 First, the user will clone the github repository recursively on their IDE or command line using "git clone --recursive https://github.com/cs100/final-project-final-project-hmoor011-susan2099-lsi001.git". Alternatively, the user can simply clone the repository using "git clone https://github.com/cs100/final-project-final-project-hmoor011-susan2099-lsi001.git", then run "git submodule update --init --recursive" to pull the modules after the repository has been cloned.
 Then, the user will run "cmake3 ." followed by "make". This will allow to user to finally run the tests.
 Lastly, the user can run the units tests using "./test" and check the quiz using "./quiz 'filename'.json" or "./quiz 'filename'.csv"
 In the main file, the user will also need to choose whether or not they would like to see the quiz's answers before taking the quiz, which can be done with a switch from 'true' to 'false', or vice versa, in the section's display function.

 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
We tested the QuizElement types by testing the display and running the quiz using stringstreams.

We then tested the section types by creating a mock of the QuizElement type that allowed us to check that the `display()` and `do_quiz()` function were being called on all of the child elements when they are called on the Section object.

Lastly we tested the QuestionBankReaders by making them pull questions from their respective test files and testing that the proper output was generated
 
