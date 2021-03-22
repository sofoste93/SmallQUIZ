#include <stdio.h>
#include <stdbool.h>


/**
 * =======================================
 * switch-case statement in C
 * Making multiple decisions with
 * switch-statement
 * written by (c) sofoste
 * @return
 * ======================================
 */

static char userChoice;
static bool quit = false;

int main() {
    //A small Game Quiz
    //char userChoice;

    printf("QUIZ OF THE DAY\n");
    printf("=========================\n");
    printf("According to the Bible [A.B.C.D] can be called a christian (choose one): \n");
    printf("================================================\n"
           "\t A: Joseph the son of Israel(Jacob)\n"
           "\t B: Jesus the carpenter of Nazareth\n"
           "\t C: John the author of the book of Revelation\n"
           "\t D: None of them\n"

           "\t Q or 0: to exit the program \n"
           "================================================\n");

    do{
        printf("Enter your choice: ");
        scanf("%c", &userChoice);
        //switch-case
        switch (userChoice) {
            case 'A':
                printf("I would say that Joseph didn't known anything\n"
                     "about christianity before..\n"
                     "So answer not accepted\n");
                break;
            case 'B':
                printf("I think Jesus is just a carpenter, the Designer of\n"
                     "all the christians..don't you think so?\n"
                     "Answer not accepted..\n");
                break;
            case 'C':
                printf("Because of Jesus John, a fellow disciple became a christian\n"
                     "since he started to live like Jesus-Christ\n"
                     "GOOD ANSWER!");
                break;
            case 'D':
                printf("PLEASE CONSIDER READ YOUR BIBLE BEFORE STARTING THIS QUIZ.\n");
                break;
            case 'Q':
            case '0':
                printf("Good bye!");
                break;
            default:
                /*puts("The Bible is not just a book - it content can\n"
                     "lead you to the Truth - it can lead you to God.\n");*/
                printf("\n> INVALID INPUT!!! :<\n");
        }

    } while (!quit);

    printf("=========================\n");
    printf("Program terminated.");

    return 0;
}
