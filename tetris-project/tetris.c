#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 10
#define HEIGHT 20

int board[HEIGHT][WIDTH] = {0};
int score = 0;
int lines_cleared = 0;
int level = 1;

int shapes[7][4][4] = {
    {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}}, // I
    {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}, // J
    {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}, // L
    {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}, // O
    {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}, // S
    {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}, // T
    {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}}  // Z
};

const char* colors[] = {
    "\x1b[96m", // Cyan (I)
    "\x1b[94m", // Blue (J)
    "\x1b[38;5;208m", // Orange (L)
    "\x1b[93m", // Yellow (O)
    "\x1b[92m", // Green (S)
    "\x1b[95m", // Purple (T)
    "\x1b[91m"  // Red (Z)
};
#define RESET "\x1b[0m"

int cur_shape, cur_x, cur_y;
int cur_matrix[4][4];
int next_shape;

struct termios orig_termios;

void reset_terminal_mode() {
    tcsetattr(0, TCSANOW, &orig_termios);
    printf("\x1b[?25h"); // Show cursor
}

void set_noncanonical_mode() {
    struct termios raw;
    tcgetattr(0, &orig_termios);
    atexit(reset_terminal_mode);
    raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &raw);
    fcntl(0, F_SETFL, O_NONBLOCK);
    printf("\x1b[?25l"); // Hide cursor
}

int kbhit() {
    char ch;
    int nread = read(0, &ch, 1);
    if (nread == 1) return ch;
    return 0;
}

void spawn_piece() {
    cur_shape = next_shape;
    next_shape = rand() % 7;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            cur_matrix[i][j] = shapes[cur_shape][i][j];
    cur_x = WIDTH / 2 - 2;
    cur_y = 0;
}

int check_collision(int x, int y, int matrix[4][4]) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(matrix[i][j]) {
                int nx = x + j;
                int ny = y + i;
                if(nx < 0 || nx >= WIDTH || ny >= HEIGHT) return 1;
                if(ny >= 0 && board[ny][nx]) return 1;
            }
        }
    }
    return 0;
}

void merge_piece() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(cur_matrix[i][j]) {
                if(cur_y + i >= 0)
                    board[cur_y + i][cur_x + j] = cur_shape + 1;
            }
        }
    }
}

void clear_lines() {
    int cleared = 0;
    for(int i=HEIGHT-1; i>=0; i--) {
        int full = 1;
        for(int j=0; j<WIDTH; j++) {
            if(!board[i][j]) { full = 0; break; }
        }
        if(full) {
            cleared++;
            for(int k=i; k>0; k--) {
                for(int j=0; j<WIDTH; j++) {
                    board[k][j] = board[k-1][j];
                }
            }
            for(int j=0; j<WIDTH; j++) board[0][j] = 0;
            i++;
        }
    }
    if(cleared > 0) {
        lines_cleared += cleared;
        score += cleared * 100 * level;
        level = 1 + lines_cleared / 10;
    }
}

void rotate_matrix() {
    int temp[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            temp[j][3-i] = cur_matrix[i][j];
    
    if(!check_collision(cur_x, cur_y, temp)) {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                cur_matrix[i][j] = temp[i][j];
    }
}

// Super Mario Pixel Character States
// 0: Super Mario (Happy/Scoring), 1: Luigi (Teasing/High Stack), 2: Bowser (Laughing/Game Over)
const char* char_names[3] = { "MARIO", "LUIGI", "BOWSER" };
const char* char_expressions[3][4] = {
    {
        " [M] ",
        "( ^◡^ )",
        " <YA!> ",
        "WHOO!"
    },
    {
        " [L] ",
        "( ⌐■_■ )",
        " <HMM> ",
        "MAMA.."
    },
    {
        " [B] ",
        "( >▽< )",
        " <BWA> ",
        "NOOB!"
    }
};

void draw() {
    printf("\x1b[H"); // Home cursor
    
    printf("\x1b[1;36m╔═════════════════════════════════════════╗\x1b[0m\n");
    printf("\x1b[1;36m║\x1b[0m       \x1b[1;33m*** RETRO TETRIS ARCADE ***\x1b[0m       \x1b[1;36m║\x1b[0m\n");
    printf("\x1b[1;36m╠════════════════════╦════════════════════╣\x1b[0m\n");

    int temp_board[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++)
        for(int j=0; j<WIDTH; j++)
            temp_board[i][j] = board[i][j];
            
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(cur_matrix[i][j]) {
                int ny = cur_y + i;
                int nx = cur_x + j;
                if(ny >= 0 && ny < HEIGHT && nx >= 0 && nx < WIDTH) {
                    temp_board[ny][nx] = cur_shape + 1;
                }
            }
        }
    }

    // Determine character moods based on stack height and score
    // Char 1 (Above Score): Mood based on score gain
    // Char 2 (Above Lines): Mood based on overall stack height
    // Char 3 (Above Controls): Mood based on danger/teasing
    int max_stack_height = 0;
    for(int j=0; j<WIDTH; j++) {
        for(int i=0; i<HEIGHT; i++) {
            if(board[i][j]) {
                if((HEIGHT - i) > max_stack_height) max_stack_height = HEIGHT - i;
                break;
            }
        }
    }

    int mood1 = (score > 0) ? 0 : 1; // Happy if scoring
    int mood2 = (max_stack_height > 10) ? 1 : 0; // Teasing if stack gets high
    int mood3 = (max_stack_height > 14) ? 2 : 0; // Laughing/Noob if danger zone

    for(int i=0; i<HEIGHT; i++) {
        printf("\x1b[1;36m║\x1b[0m");
        for(int j=0; j<WIDTH; j++) {
            if(temp_board[i][j]) {
                int col = temp_board[i][j] - 1;
                printf("%s██%s", colors[col], RESET);
            } else {
                printf(" \x1b[90m·\x1b[0m");
            }
        }
        printf("\x1b[1;36m║\x1b[0m");

        // Side Panel (HUD with Pixel Characters)
        if(i == 0)      printf(" NEXT:          \x1b[1;36m║\x1b[0m");
        else if(i >= 1 && i <= 3) {
            printf(" ");
            int ni = i - 1;
            for(int nj=0; nj<4; nj++) {
                if(shapes[next_shape][ni][nj]) {
                    printf("%s██%s", colors[next_shape], RESET);
                } else {
                    printf("  ");
                }
            }
            printf("     \x1b[1;36m║\x1b[0m");
        }
        else if(i == 5)  printf(" %s [%s\x1b[0m] \x1b[1;36m║\x1b[0m", char_names[0], char_expressions[mood1][0]);
        else if(i == 6)  printf(" \x1b[1;32m%-6d\x1b[0m  %s  \x1b[1;36m║\x1b[0m", score, char_expressions[mood1][1]);
        else if(i == 9)  printf(" %s [%s\x1b[0m] \x1b[1;36m║\x1b[0m", char_names[1], char_expressions[mood2][0]);
        else if(i == 10) printf(" \x1b[1;36m%-6d\x1b[0m  %s  \x1b[1;36m║\x1b[0m", lines_cleared, char_expressions[mood2][1]);
        else if(i == 13) printf(" %s [%s\x1b[0m]\x1b[1;36m║\x1b[0m", char_names[2], char_expressions[mood3][0]);
        else if(i == 14) printf(" C:Move %s \x1b[1;36m║\x1b[0m", char_expressions[mood3][1]);
        else if(i == 15) printf(" W:Rot S:Drop   \x1b[1;36m║\x1b[0m");
        else if(i == 16) printf("                \x1b[1;36m║\x1b[0m");
        else if(i == 17) printf(" LEVEL: \x1b[1;33m%-2d\x1b[0m      \x1b[1;36m║\x1b[0m", level);
        else             printf("                \x1b[1;36m║\x1b[0m");

        printf("\n");
    }
    printf("\x1b[1;36m╚════════════════════╩════════════════════╝\x1b[0m\n");
    printf(" Press \x1b[1;31mQ\x1b[0m to Quit.\n");
}

int main() {
    srand(time(NULL));
    set_noncanonical_mode();
    next_shape = rand() % 7;
    spawn_piece();

    int drop_counter = 0;
    while(1) {
        int ch = kbhit();
        if(ch) {
            if(ch == 'q' || ch == 'Q') break;
            if(ch == 'a' || ch == 'A') {
                if(!check_collision(cur_x - 1, cur_y, cur_matrix)) cur_x--;
            }
            if(ch == 'd' || ch == 'D') {
                if(!check_collision(cur_x + 1, cur_y, cur_matrix)) cur_x++;
            }
            if(ch == 's' || ch == 'S') {
                if(!check_collision(cur_x, cur_y + 1, cur_matrix)) cur_y++;
            }
            if(ch == 'w' || ch == 'W') {
                rotate_matrix();
            }
        }

        int speed_threshold = 20 - (level * 2);
        if(speed_threshold < 4) speed_threshold = 4;

        if(drop_counter > speed_threshold) {
            if(!check_collision(cur_x, cur_y + 1, cur_matrix)) {
                cur_y++;
            } else {
                merge_piece();
                clear_lines();
                spawn_piece();
                if(check_collision(cur_x, cur_y, cur_matrix)) {
                    printf("\x1b[H\x1b[J");
                    printf("\n\n   \x1b[1;31m[BOWSER]: BWAHAHAHA! GAME OVER, U NOOB!\x1b[0m\n");
                    printf("   Final Score: \x1b[1;32m%d\x1b[0m\n\n", score);
                    break;
                }
            }
            drop_counter = 0;
        }

        draw();
        usleep(30000); // 30ms for smooth rendering
        drop_counter++;
    }

    reset_terminal_mode();
    return 0;
}
