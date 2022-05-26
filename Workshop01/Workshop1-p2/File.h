/*
Workshop 1 - Part II
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        :

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef sdds_File_H
#define sdds_File_H

//#include "quiz.h"

namespace sdds {

	struct Question; 
	struct Answer;

	bool openFileForRead(const char* filename);

	void closeFile();

	//bool freadQuiz(Quiz quiz, int noOfQuestions, int noOfAnswers);

	bool freadQuestion(Question* question);

	bool freadAnswer(Answer* answer);

	//bool freadNewline();

}



#endif // !sdds_File_H