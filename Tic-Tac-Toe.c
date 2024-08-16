#include <stdio.h>
#include <conio.h>

static int row_no[3] = {6, 15, 24};
static int col_no[3] = {12, 15, 18};
static int digo[2] = {15, 15};
static char last_inp = 'X';

void display_res(char matrix[3][3])
{

    for (int i = 0; i <= 18; i++)
    {
        printf("|");
        if (i == 0 || i == 6 || i == 12 || i == 18)
        {
            for (int j = 0; j < 34; j++)
            {
                if (j == 11 || j == 22)
                {
                    printf("|");
                }
                else
                {
                    printf("-");
                }
            }
        }
        else
        {
            for (int j = 0; j < 34; j++)
            {
                if (j == 11 || j == 22)
                {
                    printf("|");
                }
                else if (i == 3 && j == 5)
                {
                    printf("%c", matrix[0][0]);
                }
                else if (i == 3 && j == 17)
                {
                    printf("%c", matrix[0][1]);
                }
                else if (i == 3 && j == 26)
                {
                    printf("%c", matrix[0][2]);
                }
                else if (i == 9 && j == 5)
                {
                    printf("%c", matrix[1][0]);
                }
                else if (i == 9 && j == 17)
                {
                    printf("%c", matrix[1][1]);
                }
                else if (i == 9 && j == 26)
                {
                    printf("%c", matrix[1][2]);
                }
                else if (i == 15 && j == 5)
                {
                    printf("%c", matrix[2][0]);
                }
                else if (i == 15 && j == 17)
                {
                    printf("%c", matrix[2][1]);
                }
                else if (i == 15 && j == 26)
                {
                    printf("%c", matrix[2][2]);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("|\n");
    }
}

void turn_counter()
{
    if (last_inp == '0' || last_inp == 'O' || last_inp == 'o')
    {
        printf("Xs Turn\n");
        last_inp = 'X';
    }
    else
    {
        printf("O s Turn\n");
        last_inp = 'O';
    }
}

void menu()
{
    printf("\t Welcome in Tic-Tac-Toe\n");
flag:
    printf("\t Press X for X and O for O \n");
    scanf("%c", &last_inp);
    if (last_inp != 'X' && last_inp != '0' && last_inp != 'x' && last_inp != 'o' && last_inp != 'O')
    {
        printf("\t Invalid Input !\n");
        printf("\t Please Enter Correct Input\n");
        goto flag;
    }
}

void display(int pos)
{

    for (int i = 0; i <= 18; i++)
    {
        printf("|");
        if (i == 0 || i == 6 || i == 12 || i == 18)
        {
            for (int j = 0; j < 34; j++)
            {
                if (j == 11 || j == 22)
                {
                    printf("|");
                }
                else
                {
                    printf("-");
                }
            }
        }
        else
        {
            for (int j = 0; j < 34; j++)
            {
                if (j == 11 || j == 22)
                {
                    printf("|");
                }
                else if ((i == 3 && (j == 5 || j == 17 || j == 26)) || (i == 9 && (j == 5 || j == 17 || j == 26)) || (i == 15 && (j == 5 || j == 17 || j == 26)))
                {
                    printf("%d", pos);
                    pos++;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("|\n");
    }
}

void input(int last_inp, char matrix[3][3])
{
    int pos, i;

label:
    printf("At what position you want to enter your value ");
    scanf("%d", &pos);
    if (pos < 1 || pos > 9)
    {
        printf("Please enter value between 1 to 9 \n");
        goto label;
    }
    else if (pos >= 1 && pos <= 3)
    {
        i = 0;
        if (matrix[i][pos - 1] == ' ')
        {
            matrix[i][pos - 1] = last_inp;
            row_no[i] -= pos;
            col_no[pos - 1] -= pos;
            if (pos == 1)
            {
                digo[0] -= pos;
            }
            else if (pos == 3)
            {
                digo[1] -= pos;
            }
        }
        else
        {
            printf("You can't enter value at this postion Please choose differnt location \n");
            goto label;
        }
    }
    else if (pos >= 4 && pos <= 6)
    {
        i = 1;
        if (matrix[i][(pos - 1) - 3] == ' ')
        {
            matrix[i][(pos - 1) - 3] = last_inp;
            row_no[i] -= pos;
            col_no[((pos - 1) - 3)] -= pos;
            if (pos == 5)
            {
                digo[0] -= pos;
                digo[1] -= pos;
            }
        }
        else
        {
            printf("You can't enter value at this postion Please choose differnt location\n");
            goto label;
        }
    }
    else if (pos >= 7 && pos <= 9)
    {
        i = 2;
        if (matrix[i][(pos - 1) - (6)] == ' ')
        {
            matrix[i][(pos - 1) - (6)] = last_inp;
            row_no[i] -= pos;
            col_no[(pos - 1) - (6)] -= pos;
            if (pos == 9)
            {
                digo[0] -= pos;
            }
            else if (pos == 7)
            {
                digo[1] -= pos;
            }
        }
        else
        {
            printf("You can't enter value at this postion Please choose differnt location\n");
            goto label;
        }
    }
    display_res(matrix);
}

int row_check(int row, char matrix[3][3])
{
    int count_0 = 0, count_X = 0;

    for (int col = 0; col < 3; col++)
    {
        if (matrix[row][col] == 'X' || matrix[row][col] == 'x')
        {
            count_X++;
        }
        else if (matrix[row][col] == '0' || matrix[row][col] == 'O' || matrix[row][col] == 'o')
        {
            count_0++;
        }
    }
    if (count_0 == 3)
    {
        printf("O wins\n");
        return 1;
    }
    else if (count_X == 3)
    {
        printf("X wins\n");
        return 1;
    }
    return 0;
}

int col_check(int col, char matrix[3][3])
{
    int count_0 = 0, count_X = 0;
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][col] == 'X' || matrix[i][col] == 'x')
        {
            count_X++;
        }
        else if (matrix[i][col] == '0' || matrix[i][col] == 'o' || matrix[i][col] == 'O')
        {
            count_0++;
        }
    }
    if (count_0 == 3)
    {
        printf("O wins\n");
        return 1;
    }
    else if (count_X == 3)
    {
        printf("X wins\n");
        return 1;
    }
    return 0;
}

int right_digo_check(char matrix[3][3])
{
    int count_0 = 0, count_X = 0, i;
    for (i = 0, i; i <= 2; i++)
    {
        if (matrix[i][2 - i] == 'X' || matrix[i][2 - i] == 'x')
        {
            count_X++;
        }
        else if (matrix[i][2 - i] == '0' || matrix[i][2 - i] == 'o' || matrix[i][2 - i] == 'O')
        {
            count_0++;
        }
    }
    if (count_0 == 3)
    {
        printf("O wins\n");
        return 1;
    }
    else if (count_X == 3)
    {
        printf("X wins\n");
        return 1;
    }

    return 0;
}

int left_digo_check(char matrix[3][3])
{
    int count_0 = 0, count_X = 0;
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][i] == 'X' || matrix[i][i] == 'x')
        {
            count_X++;
        }
        else if (matrix[i][i] == '0' || matrix[i][i] == 'o' || matrix[i][i] == 'O')
        {
            count_0++;
        }
    }
    if (count_0 == 3)
    {
        printf("O wins\n");
        return 1;
    }
    else if (count_X == 3)
    {
        printf("X wins\n");
        return 1;
    }
    return 0;
}

int res_check(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (row_no[i] == 0)
        {
            if (row_check(i, matrix) == 1)
            {
                return 1;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (col_no[i] == 0)
        {
            if (col_check(i, matrix) == 1)
            {
                return 1;
            }
        }
    }

    if (digo[0] == 0)
    {
        if (left_digo_check(matrix) == 1)
        {
            return 1;
        }
    }

    if (digo[1] == 0)
    {
        if (right_digo_check(matrix) == 1)
        {
            return 1;
        }
    }

    if (row_no[0] == row_no[1] == row_no[2] == col_no[0] == col_no[1] == col_no[2] == digo[0] == digo[1] == 0)
    {
        return 0;
    }
}

int main()
{
    char matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    int input_count = 0;
    display(1);
    menu();
    for (input_count = 0; input_count < 9; input_count++)
    {

        turn_counter();
        input(last_inp, matrix);
        printf("Press Enter to continue");
        getch();
        system("cls");
        if (input_count >= 4)
        {
            if (res_check(matrix) == 1)
            {
                break;
            }
        }
        else if (input_count == 9 && res_check(matrix) == 0)
        {
            printf("Result Tie");
        }
    }

    display_res(matrix);

    return 0;
}
