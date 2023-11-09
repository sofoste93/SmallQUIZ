#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stddef.h>

typedef struct {
    const char* question;
    const char* choices;
    char correctAnswer;
} QuizQuestion;

static const QuizQuestion quizQuestions[] = {
        {"According to the Bible [A.B.C.D] can be called a christian: ",
         "\t A: Joseph the son of Israel(Jacob)\n"
         "\t B: Jesus the carpenter of Nazareth\n"
         "\t C: John the author of the book of Revelation\n"
         "\t D: None of them\n", 'C'},

        {"Which planet is known as the Red Planet? ",
         "\t A: Jupiter\n"
         "\t B: Mars\n"
         "\t C: Venus\n"
         "\t D: Mercury\n", 'B'},

        {"Which is the largest ocean on Earth? ",
         "\t A: Atlantic Ocean\n"
         "\t B: Indian Ocean\n"
         "\t C: Arctic Ocean\n"
         "\t D: Pacific Ocean\n", 'D'},

        {"Which element has the symbol 'Na'? ",
         "\t A: Nitrogen\n"
         "\t B: Nickel\n"
         "\t C: Neon\n"
         "\t D: Sodium\n", 'D'},

        {"Which animal is known as the 'Ship of the Desert'? ",
         "\t A: Camel\n"
         "\t B: Donkey\n"
         "\t C: Horse\n"
         "\t D: Elephant\n", 'A'},

        {"In computer science, what does 'GUI' stand for? ",
         "\t A: General User Interface\n"
         "\t B: Graphical User Interface\n"
         "\t C: Grand User Interface\n"
         "\t D: Guide User Interface\n", 'B'}
};

static const size_t questionCount = sizeof(quizQuestions) / sizeof(QuizQuestion);

#endif