#include <cs50.h>
#include <stdio.h>

int main()
{
    int height = get_int("how high you want the pyramid to be? ");

    while (height < 1 || height > 8)
    {
        height = get_int("\nInvalid input. Please choose a number between 1-8: ");
    }

    for (int i = 1; i <= height; i++)
    {
        // spaces befor the # to create a "ladder"
        for (int spaces = height - i; spaces > 0; spaces--)
        {
            printf(" ");
        }

        // the # to create rows
        for (int row = i; row > 0; row--)
        {
            printf("#");
        }

        printf("  "); // space between columns

        for (int second_column = 0; second_column < i; second_column++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}