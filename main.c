#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "questions.h"

static char userChoice;
static int score = 0;
static size_t currentQuestionIndex = 0;

void ask_question() {
    const QuizQuestion* currentQuestion = &quizQuestions[currentQuestionIndex];

    printf("%s\n", currentQuestion->question);
    printf("=========================\n"
           "%s\n\n"
           "Q or q to exit the program\n"
           "=========================\n", currentQuestion->choices);

    printf("Enter your choice: ");
    scanf(" %c", &userChoice); // add space to ignore leading whitespaces

    switch (toupper(userChoice)) {  // Using toupper() function to avoid case sensitiveness
        case 'Q':
            printf("Are you sure you want to exit the program? All progress will be lost. Press y to confirm or any other key to continue: ");
            char confirmExit;
            scanf(" %c", &confirmExit);
            if (toupper(confirmExit) == 'Y') {  // Using toupper() here too
                printf("Program terminated.\n");
                printf("Final score: %d\n", score);
                exit(0);
            }
            return;
        default:
            if(toupper(userChoice) == currentQuestion->correctAnswer) {
                printf("Good answer!\n");
                score++;
                // Move to the next question
                if(currentQuestionIndex < questionCount - 1) {
                    currentQuestionIndex++;
                }
            } else {
                printf("Incorrect answer.\n");
            }
    }
    // Print current score
    printf("Current score: %d\n=========================\n", score);
}

int main() {
    printf("QUIZ OF THE DAY\n");
    printf("=========================\n");

    while (true) {
        ask_question();
    }

    return 0;
}