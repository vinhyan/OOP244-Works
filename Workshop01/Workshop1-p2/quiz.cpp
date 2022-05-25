/*
Workshop 1 - Part II
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <string.h>
#include "quiz.h"
#include "File.h"
#include "Utils.h"

using namespace sdds;
using namespace std;

namespace quizzer {

	Quiz quiz = { {0} };
	int noOfQuestions = 0;
	int noOfAnswers = 0;

	int i, j;

	int LoadQuiz(const char* filename)
	{
		Question question = { {0} };
		Answer answer = { {0} };
		//Answer empAnswer = { {0} };

		int result = 1;
		//char newline;

		if (sdds::openFileForRead(filename)) {
			result = 0;

			//Read questions
			while (	noOfQuestions < MAX_QUESTIONS &&
					sdds::freadQuestion(&question) )
			{
				
				//Read answers
				while (noOfAnswers < MAX_ANSWERS && 
						sdds::freadAnswer(&answer))
				{
					question.answer[noOfAnswers] = answer;
					noOfAnswers++;

					//answer = empAnswer;
				};

				quiz.question[noOfQuestions] = question;
				noOfQuestions++;
			};

			sdds::closeFile();
		};

		for (i = 0; i < MAX_QUESTIONS; i++) {
			cout << "Q" << i + 1 << "  " << quiz.question[i].type <<  quiz.question[i].questionText << endl;
			for (j = 0; j < MAX_ANSWERS; j++) {
				//cout << "AT" << j + 1 << " " << quiz.question[i].answer[j].type << endl;
				cout << "A" << j + 1 << "  " << quiz.question[i].answer[j].type << quiz.question[i].answer[j].answerText << endl;
			}
		}

		return result;
	}

	int IsQuizValid()
	{
		int result = 0, correctAns = 0;
		int i, j;
		//Question question = { {0} };
		//  A quiz is considered valid if it has at least 5 questions
		//  and each question is correct (multiple-choice questions have
		//  exactly one correct answer, and multiple-answer questions
		//  have at least one correct answer.
		if (noOfQuestions >= 5) {
			for (i = 0; i < noOfQuestions; i++)
			{
				for (j = 0; j < noOfAnswers; j++)
				{
					if (strcmp(quiz.question[noOfQuestions].answer[noOfAnswers].type,
						"[X]") == 0)
					{
						correctAns++;
					}
				}

				if ((strcmp(quiz.question[noOfQuestions].type, "{mc}") == 0) &&
					correctAns == 1)
				{
					result = 1;
				}
				else if ((strcmp(quiz.question[noOfQuestions].type, "{ma}") == 0) &&
					correctAns > 1)
				{
					result = 1;
				}
			}
		 }

		//  For each question in the quiz, print to screen "Question X -> OK" or
		//  "Question X -> ERROR" if the question is valid or it contains some error.
		

		return result;
	}

	int HasMoreQuestions()
	{
		return 0;
	}

	void ShowNextQuestion()
	{

	}

	void ShowQuizResults()
	{

	}


}

