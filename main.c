#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char name[50];
    printf("Welcome to the Mystery Mansion!\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from the input

    printf("\nHello, %s! You've entered the Mystery Mansion.\n", name);
    printf("Your adventure starts now...\n");

    printf("\nYou find yourself in a dark corridor.\n");
    printf("There are three doors in front of you: A, B, and C.\n");

    char choice;
    printf("Enter your choice (A/B/C): ");
    scanf(" %c", &choice);
    clear_input_buffer();

    if (choice == 'A') {
        printf("\nYou've entered Room A.\n");
        printf("There's a riddle written on the wall:\n");
        printf("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?\n");

        char answer[50];
        printf("Enter your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0'; // Remove the newline character from the input

        if (strcasecmp(answer, "echo") == 0) {
            printf("Correct! The door opens, and you move to the next room.\n");
        } else {
            printf("Wrong answer! You're trapped in the room forever.\n");
            return 0;
        }
    } else if (choice == 'B') {
        printf("\nYou've entered Room B.\n");
        printf("In this room, you see a table with a locked box on top of it.\n");
        printf("There's a note that reads: 'To unlock the box, find the key in the painting.'\n");

        printf("\nYou notice three paintings on the wall: 1, 2, and 3.\n");
        int painting_choice;
        printf("Which painting do you want to examine (1/2/3)? ");
        scanf("%d", &painting_choice);
        clear_input_buffer();

        if (painting_choice == 2) {
            printf("You found the key behind the painting! You unlock the box and find a valuable gem inside.\n");
            printf("Congratulations, %s! You've completed the Mystery Mansion adventure!\n", name);
        } else {
            printf("The painting feels loose, but there's no key behind it.\n");
            printf("Suddenly, the room starts to shake, and debris falls from the ceiling, trapping you inside.\n");
            return 0;
        }
    } else if (choice == 'C') {
        printf("\nYou've entered Room C.\n");
        printf("This room is filled with mirrors and illusions.\n");
        printf("You see your reflection in each mirror, but one of them is different from the others.\n");

        int correct_mirror = 2; // Randomly choose the correct mirror (1, 2, or 3)
        int chosen_mirror;
        printf("Which mirror is different (1/2/3)? ");
        scanf("%d", &chosen_mirror);
        clear_input_buffer();

        if (chosen_mirror == correct_mirror) {
            printf("Correct! You've chosen the right mirror. The door to the next room opens.\n");
        } else {
            printf("Wrong mirror! Suddenly, the mirrors shatter, and you're surrounded by broken glass.\n");
            printf("Thankfully, you're not hurt, but you're unable to proceed further.\n");
            return 0;
        }
    } else {
        printf("Invalid choice! You're too confused to continue the adventure.\n");
        return 0;
    }

    return 0;
}
