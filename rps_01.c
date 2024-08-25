// Rock, paper, scissors
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const char shapes[] = {'r', 'p', 's'};

int isshape(char s)
{
    for (int i = 0; i < 3; i++)
        if (tolower(s) == shapes[i])
            return 1;
    return 0;
}

int main()
{
    char user, computer;

    srand(time(NULL));

    while (1)
    {
        printf("Allowed shapes: (r)ock , (p)aper, (s)cissors\n");

        printf("Your shape: ");
        scanf(" %c", &user);

        while (getchar() != '\n')
            ;

        if (!isshape(user))
        {
            printf("Invalid shape!\n");
            continue;
        }

        computer = shapes[rand() % 3];
        printf("Computer: %c\n", computer);

        if (user == computer)
            printf("Draw!");
        else if (
            (user == 'r' && computer == 's') || (user == 'p' && computer == 'r') || (user == 's' && computer == 'p'))
            printf("You won the game!");
        else
            printf("You lost the game!");

        putchar('\n');
    }

    return 0;
}
