/*
Workshop 1 - Part II
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        : 

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef sdds_quiz_h
#define sdds_quiz_h

namespace sdds {
	const int MAX_ANSWER_CHAR = 128;
	const int MAX_QUESTION_CHAR = 1024;
	const int MAX_ANSWERS = 10;
	const int MAX_QUESTIONS = 60;

	struct Answer {
		char answerText[MAX_ANSWER_CHAR + 1];
		char type[3 + 1];
	};

	struct Question {
		char type[4 + 1];
		char questionText[MAX_QUESTION_CHAR + 1];
		Answer answer[MAX_ANSWERS];
	};

	struct Quiz {
		Question question[MAX_QUESTIONS];
		int accumScore;
		bool hasTaken;
	};
}

namespace quizzer {

	int LoadQuiz(const char* filename);

	int IsQuizValid();

	int HasMoreQuestions();

	void ShowNextQuestion();

	void ShowQuizResults();


}



















#endif // !sdds_quiz_h