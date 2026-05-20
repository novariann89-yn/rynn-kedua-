#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define INITIAL_LEN 3
#define DELAY 100000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[WIDTH * HEIGHT];
    int len;
    int dir; // 0=up, 1=right, 2=down, 3=left
} Snake;

typedef struct {
    int x, y;
} Food;

int gameover;
int score;

void init_game(Snake *snake, Food *food) {
    snake->len = INITIAL_LEN;
    snake->dir = 1;
    for (int i = 0; i < snake->len; i++) {
        snake->body[i].x = WIDTH / 2 - i;
        snake->body[i].y = HEIGHT / 2;
    }
    food->x = rand() % (WIDTH - 2) + 1;
    food->y = rand() % (HEIGHT - 2) + 1;
    gameover = 0;
    score = 0;
}

void draw(Snake *snake, Food *food) {
    clear();
    for (int x = 0; x < WIDTH; x++) {
        mvaddch(0, x, '#');
        mvaddch(HEIGHT - 1, x, '#');
    }
    for (int y = 1; y < HEIGHT - 1; y++) {
        mvaddch(y, 0, '#');
        mvaddch(y, WIDTH - 1, '#');
    }
    mvaddch(food->y, food->x, '@');
    for (int i = 0; i < snake->len; i++) {
        if (i == 0)
            mvaddch(snake->body[i].y, snake->body[i].x, 'O');
        else
            mvaddch(snake->body[i].y, snake->body[i].x, 'o');
    }
    mvprintw(HEIGHT + 1, 0, "Score: %d  (Q to quit)", score);
    refresh();
}

int check_collision(Snake *snake, int nx, int ny) {
    if (nx <= 0 || nx >= WIDTH - 1 || ny <= 0 || ny >= HEIGHT - 1)
        return 1;
    for (int i = 0; i < snake->len; i++)
        if (snake->body[i].x == nx && snake->body[i].y == ny)
            return 1;
    return 0;
}

void update(Snake *snake, Food *food) {
    int nx = snake->body[0].x;
    int ny = snake->body[0].y;
    switch (snake->dir) {
        case 0: ny--; break;
        case 1: nx++; break;
        case 2: ny++; break;
        case 3: nx--; break;
    }
    if (check_collision(snake, nx, ny)) {
        gameover = 1;
        return;
    }
    for (int i = snake->len - 1; i > 0; i--)
        snake->body[i] = snake->body[i - 1];
    snake->body[0].x = nx;
    snake->body[0].y = ny;
    if (nx == food->x && ny == food->y) {
        snake->body[snake->len] = snake->body[snake->len - 1];
        snake->len++;
        score += 10;
        food->x = rand() % (WIDTH - 2) + 1;
        food->y = rand() % (HEIGHT - 2) + 1;
    }
}

int main() {
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(0);
    Snake snake;
    Food food;
    init_game(&snake, &food);
    while (!gameover) {
        draw(&snake, &food);
        int ch = getch();
        switch (ch) {
            case KEY_UP:    if (snake.dir != 2) snake.dir = 0; break;
            case KEY_RIGHT: if (snake.dir != 3) snake.dir = 1; break;
            case KEY_DOWN:  if (snake.dir != 0) snake.dir = 2; break;
            case KEY_LEFT:  if (snake.dir != 1) snake.dir = 3; break;
            case 'q':
            case 'Q': gameover = 1; break;
        }
        update(&snake, &food);
        usleep(DELAY);
    }
    mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "GAME OVER");
    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 8, "Final Score: %d", score);
    refresh();
    timeout(-1);
    getch();
    endwin();
    return 0;
}
