/*
Workshop 1 - Part II
Full Name   : Vinh Nhan
Seneca email: vnhan1@myseneca.ca
Student ID  : 171452212
Date        :

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "File.h"
#include "quiz.h"

using namespace std;

namespace sdds {

    int noOfQuestions = 0;
    int noOfAnswers = 0;
   


    FILE* sfptr = nullptr;

    bool openFileForRead(const char* filename) {
        sfptr = fopen(filename, "r");
        return sfptr != NULL;
    }

    void closeFile() {
        if (sfptr) fclose(sfptr);
    }

    //bool freadQuiz(Quiz quiz, int noOfQuestions, int noOfAnswers) {
    //    /*bool success = fscanf(sfptr, "%[^,],%d,%d\n",
    //        rec->m_title, &rec->m_quantity, &flag) == 3;
    //    rec->m_bought = !!flag;
    //    return success;*/

    //    //one big loop to read questions, another nested loop while reading a question to read the answers

    //   /* quizzer::Question question = { {0} };
    //    quizzer::Answer answer = { {0} };*/


    //    /*while ( noOfQuestions < quizzer::MAX_QUESTIONS &&
    //            fscanf(sfptr, "%4s %s\n", question.type, question.questionText) == 2) {
    //        strcpy((quiz->question[noOfQuestions].type), question.type);
    //        strcpy((quiz->question[noOfQuestions].questionText), question.questionText);

    //        while (noOfAnswers < quizzer::MAX_ANSWERS &&
    //            fscanf(sfptr, "%3s %s\n", answer.type, answer.answerText) == 2) {
    //            strcpy((quiz->question[noOfQuestions].answer[noOfAnswers].answerText), answer.answerText);
    //            strcpy((quiz->question[noOfQuestions].answer[noOfAnswers].type), answer.type);
    //        };
    //    }*/
    //    return true;
    //    
    //}

    bool freadQuestion(Question* question) {
        bool success = fscanf(sfptr, "%4[^\n] %1024[^\n]\n", question->type, question->questionText);
        
        return success;
    }

    bool freadAnswer(Answer* answer) {
        bool success = fscanf(sfptr, "%3[^\n] %128[^\n]\n", answer->type, answer->answerText);
        cout << "Answer" << success << endl;
        return success;
    }

    /*bool freadNewline() {
        char newline;
        bool success = false;
        fscanf(sfptr, "%c", &newline);

        if (newline == '\n') success = true;
        return success;
    }*/

    
}



