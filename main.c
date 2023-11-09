#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "questions.h"

static char userChoice;
static double score = 0; // Changed score to double
static size_t currentQuestionIndex = 0;
static int attemptCount = 0;
static int totalAttempts = 0;
static const int maxAttempts = 2;

void ask_question() {
    const QuizQuestion* currentQuestion = &quizQuestions[currentQuestionIndex];

    printf("%s\n", currentQuestion->question);
    printf("=========================\n"
           "%s\n\n"
           "Q or q: to exit the program\n"
           "=========================\n", currentQuestion->choices);
    attemptCount = 0; // Reset attempt count for each question

    printf("Enter your choice: ");
    if (scanf(" %c", &userChoice) != 1) { // Error-checking for scanf
        printf("Invalid input. Please try again.\n");
        return;
    }

    switch (toupper(userChoice)) {
        case 'Q':
            printf("Are you sure you want to exit the program? All progress will be lost. Press y to confirm or any other key to continue: ");
            char confirmExit;
            if (scanf(" %c", &confirmExit) != 1) { // Error-checking for scanf
                printf("Invalid input. Please try again.\n");
                return;
            }
            if (toupper(confirmExit) == 'Y') {
                printf("Program terminated.\n");
                printf("Final score: %.1f\n", score); // Display score with one decimal place
                printf("Total attempts: %d\n", totalAttempts);
                exit(0);
            }
            return;
        default:
            if(toupper(userChoice) == currentQuestion->correctAnswer) {
                printf("Good answer!\n");
                if(attemptCount == 0)
                    score += 2;
                else
                    score += 0.5;  // Increment the score by 0.5 if answered correctly after more than one attempt
                // Move to the next question
                if(currentQuestionIndex < questionCount - 1) {
                    currentQuestionIndex++;
                } else { // If all questions have been answered, print final score and terminate
                    printf("Well done! You've answered all the questions.\n");
                    printf("Final score: %.1f\n", score); // Display score with one decimal place
                    printf("Total attempts: %d\n", totalAttempts);
                    exit(0);
                }
            } else {
                printf("Incorrect answer.\n");
                if(attemptCount >= maxAttempts - 1) { // If max attempts reached, move to the next question
                    currentQuestionIndex++;
                }
            }
            break;
    }
    totalAttempts += attemptCount; // Increment total attempts
    attemptCount++; // Increment attempt count for the current question
    printf("Current score: %.1f\n=========================\n", score); // Display score with one decimal place
}

int main() {
    printf("QUIZ OF THE DAY\n");
    printf("=========================\n");

    while (true) {
        if (currentQuestionIndex >= questionCount) {
            printf("Well done! You've answered all the questions.\n");
            printf("Final score: %.1f\n", score); // Display score with one decimal place
            printf("Total attempts: %d\n", totalAttempts);
            exit(0);
        }
        ask_question();
    }

    return 0;
}
