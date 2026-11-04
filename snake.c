#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 30
#define HEIGHT 20
#define MAX_SNAKE_LENGTH (WIDTH * HEIGHT)

typedef struct
{
    int x;
    int y;
} Point;

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

static Point snake[MAX_SNAKE_LENGTH];
static int snake_length;
static Point food;
static Direction direction;

static int is_snake_at(int x, int y)
{
    int i;

    for (i = 0; i < snake_length; i++)
    {
        if (snake[i].x == x && snake[i].y == y)
        {
            return 1;
        }
    }

    return 0;
}

static int place_food(void)
{
    int empty_cells = WIDTH * HEIGHT - snake_length;
    int target;
    int x;
    int y;

    if (empty_cells <= 0)
    {
        return 0;
    }

    target = rand() % empty_cells;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (!is_snake_at(x, y))
            {
                if (target == 0)
                {
                    food.x = x;
                    food.y = y;
                    return 1;
                }
                target--;
            }
        }
    }

    return 0;
}

static void draw_game(int score)
{
    int x;
    int y;
    int i;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD origin = {0, 0};

    SetConsoleCursorPosition(console, origin);
    printf("+");
    for (x = 0; x < WIDTH; x++)
    {
        printf("-");
    }
    printf("+\n");

    for (y = 0; y < HEIGHT; y++)
    {
        printf("|");
        for (x = 0; x < WIDTH; x++)
        {
            char cell = ' ';

            if (snake[0].x == x && snake[0].y == y)
            {
                cell = 'O';
            }
            else
            {
                for (i = 1; i < snake_length; i++)
                {
                    if (snake[i].x == x && snake[i].y == y)
                    {
                        cell = 'o';
                        break;
                    }
                }

                if (food.x == x && food.y == y)
                {
                    cell = '*';
                }
            }

            printf("%c", cell);
        }
        printf("|\n");
    }

    printf("+");
    for (x = 0; x < WIDTH; x++)
    {
        printf("-");
    }
    printf("+\n");
    printf("Score: %d    Move: arrow keys or WASD    Quit: Q\n", score);
    fflush(stdout);
}

static void change_direction(int key)
{
    if ((key == 'w' || key == 'W' || key == 72) && direction != DOWN)
    {
        direction = UP;
    }
    else if ((key == 's' || key == 'S' || key == 80) && direction != UP)
    {
        direction = DOWN;
    }
    else if ((key == 'a' || key == 'A' || key == 75) && direction != RIGHT)
    {
        direction = LEFT;
    }
    else if ((key == 'd' || key == 'D' || key == 77) && direction != LEFT)
    {
        direction = RIGHT;
    }
}

int main(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    COORD result_position;
    int score = 0;
    int game_over = 0;
    int won = 0;

    srand((unsigned int)time(NULL));

    snake_length = 3;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[0].x - 2;
    snake[2].y = snake[0].y;
    direction = RIGHT;

    if (!place_food())
    {
        return 1;
    }

    cursor_info.dwSize = 100;
    cursor_info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &cursor_info);
    system("cls");

    printf("Snake game! Press any key to start...");
    fflush(stdout);
    _getch();
    system("cls");

    while (!game_over)
    {
        Point next = snake[0];
        int growing;
        int collision = 0;
        int i;
        int delay;

        if (_kbhit())
        {
            int key = _getch();

            if (key == 0 || key == 224)
            {
                key = _getch();
            }

            if (key == 'q' || key == 'Q')
            {
                break;
            }
            change_direction(key);
        }

        if (direction == UP)
        {
            next.y--;
        }
        else if (direction == DOWN)
        {
            next.y++;
        }
        else if (direction == LEFT)
        {
            next.x--;
        }
        else
        {
            next.x++;
        }

        growing = next.x == food.x && next.y == food.y;

        if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT)
        {
            collision = 1;
        }
        else
        {
            for (i = 0; i < snake_length; i++)
            {
                if (!growing && i == snake_length - 1)
                {
                    continue;
                }
                if (snake[i].x == next.x && snake[i].y == next.y)
                {
                    collision = 1;
                    break;
                }
            }
        }

        if (collision)
        {
            game_over = 1;
            break;
        }

        for (i = growing ? snake_length : snake_length - 1; i > 0; i--)
        {
            snake[i] = snake[i - 1];
        }
        snake[0] = next;

        if (growing)
        {
            snake_length++;
            score += 10;
            if (!place_food())
            {
                won = 1;
                game_over = 1;
            }
        }

        draw_game(score);
        delay = 150 - score;
        if (delay < 60)
        {
            delay = 60;
        }
        Sleep((DWORD)delay);
    }

    result_position.X = 0;
    result_position.Y = HEIGHT + 3;
    SetConsoleCursorPosition(console, result_position);
    if (won)
    {
        printf("You win! Final score: %d\n", score);
    }
    else if (game_over)
    {
        printf("Game over! Final score: %d\n", score);
    }
    else
    {
        printf("Game quit. Final score: %d\n", score);
    }

    cursor_info.bVisible = TRUE;
    SetConsoleCursorInfo(console, &cursor_info);
    printf("Press any key to exit...");
    _getch();
    return 0;
}
