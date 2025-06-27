#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to set the cursor position in the console
void g(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

// Function to display the Hangman based on remaining attempts
void display_hangman(int attempts, int n) {
    switch (attempts) {
    case 7:
        for (int i = 0; i < n; i++) {
            g(59, 20 + i); printf("  +---+\n");
        }
        break;
    case 6:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("      |\n");
        g(59, 23); printf("      |\n");
        g(59, 24); printf("      |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 5:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf("      |\n");
        g(59, 24); printf("      |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 4:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf("  |   |\n");
        g(59, 24); printf("      |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 3:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf(" /|   |\n");
        g(59, 24); printf("      |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 2:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf(" /|\\  |\n");
        g(59, 24); printf("      |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 1:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf(" /|\\  |\n");
        g(59, 24); printf(" /    |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    case 0:
        printf("\033[1;32m");
        g(59, 20); printf("  +---+\n");
        g(59, 21); printf("  |   |\n");
        g(59, 22); printf("  O   |\n");
        g(59, 23); printf(" /|\\  |\n");
        g(59, 24); printf(" / \\  |\n");
        g(59, 25); printf("      |\n");
        g(59, 26); printf("=========\n");
        printf("\033[0m");
        break;
    default:
        break;
    }
}

// Main game logic
int game(int n, char producing_hints[10][100], int word_length, char word_find[], char guessed_word[],char game_name[]) {
    printf("\x1B[2J");
    printf("\x1B[H");
    printf("%50s",game_name);
    g(70, 4); printf("------------------------------------");
    g(70, 5); printf("| Enter 7 for knowing your hints   |");
    g(70, 6); printf("------------------------------------");

    int attempts = 6;
    int correct_one = 0;

    while (attempts > 0) {
        printf("\n\n\t\t\t");

        for (int i = 0; i < word_length; i++) {
            printf(" %c", guessed_word[i]);
        }

        char user_letter;
        g(5, 3); printf("ENTER YOUR LETTER: ");
        scanf(" %c", &user_letter);

        if (user_letter == '7') {
            for (int i = 0; i < n; i++) {
                g(5, 4 + i+1); printf("HINT %d: %s", i + 1, producing_hints[i]);
            }
            continue;
        }

        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word_find[i] == user_letter && guessed_word[i] == '_') {
                guessed_word[i] = user_letter;
                correct_one++;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            attempts--;
            g(5, 5); printf("WRONG! ATTEMPTS LEFT: %d", attempts);
            display_hangman(attempts, n);
        }

        if (correct_one == word_length) {
            g(5, 10); printf("CONGRATULATIONS! YOU FOUND THE WORD: %s", word_find);

            printf("\n\n\n");
            return 1;
        }

        if (attempts == 0) {
            g(5, 10); printf("GAME OVER! THE WORD WAS: %s", word_find);
            printf("\n\n\n");
        }
    }

    return 0;
}

int main()
{
    int game_info, n = 0;
    char game_name[100], word_find[100], producing_hints[10][100];

    hang:
    printf("%50.1f HELLO HANGMAN",1.0);
    g(40, 6); printf(" >> ENTER 7 TO START ");
    g(40, 8); printf(" >> ENTER 0 TO QUIT      : ");
    scanf("%d", &game_info);

    if (game_info == 7) {
        printf("\x1B[2J");
        printf("\x1B[H");

        printf("\x1B[2J");  //for clear terminal
        printf("\x1B[H");   //to move cursor for top-left for starting
        printf("%50.1f HANGMAN",1.0);
        printf("\033[1;34m");
        g(85,15);printf("___________");
        g(85,16);printf("|_________|");
        printf("\033[0m");
        g(6,4);printf("ENTER YOUR GAME SUBJECT :");
        scanf("%s",game_name);
        fflush(stdin);

        g(6,7);printf("[ Enter your word to be found ]");


        for(int i=0;i<=6;i++)
        {
            printf("\033[1;32m");
            g(90,15-i);printf("|");
            printf("\033[0m");
        }

        g(6, 6); printf("ENTER THE WORD : ");
        scanf("%s", word_find);

        int word_length = strlen(word_find);
        char guessed_word[word_length + 1];
        memset(guessed_word, '_', word_length);
        guessed_word[word_length] = '\0';
        g(85,8);printf("+-----+");

        g(6, 9); printf("TRY TO GIVE THEM ANY HINTS ?(y/n):");
        char hint;
        scanf(" %c", &hint);

        if (hint == 'y' || hint == 'Y') {
            g(6, 11); printf("ENTER THE NUMBER OF HINTS: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                g(6, 12 + i); printf("ENTER HINT %d: ", i + 1);
                scanf(" %[^\n]", producing_hints[i]);
            }
        }

        game(n, producing_hints, word_length, word_find, guessed_word,game_name);
    } else if (game_info == 0) {
        g(25, 7); printf("Better play next time!");
        return 1;
    } else {
        g(40, 17); printf("PLEASE ENTER A VALID INPUT!");
        goto hang;
    }

    return 0;
}
