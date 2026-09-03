#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

// Spinning 3D Donut in C
// Classic ASCII art torus renderer

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];

    // Hide cursor
    printf("\033[?25l");
    // Clear screen
    printf("\033[2J");

    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, sizeof(z));

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sinf(i);
                float d = cosf(j);
                float e = sinf(A);
                float f = sinf(j);
                float g = cosf(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cosf(i);
                float m = cosf(B);
                float n = sinf(B);
                float t = c * h * g - f * e;

                int x = (int)(40 + 30 * D * (l * h * m - t * n));
                int y = (int)(12 + 15 * D * (l * h * n + t * m));
                int o = x + 80 * y;

                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));

                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Move cursor to top-left
        printf("\033[H");

        // Print frame with color
        for (k = 0; k < 1761; k++) {
            // Color based on character brightness
            char ch = b[k];
            if (k % 80 == 79) {
                printf("\n");
            } else {
                // ANSI color based on character density
                int brightness = 0;
                const char *chars = ".,-~:;=!*#$@";
                for (int ci = 0; ci < 12; ci++) {
                    if (ch == chars[ci]) {
                        brightness = ci;
                        break;
                    }
                }
                if (ch != ' ') {
                    // Gradient from cyan to magenta to yellow
                    if (brightness < 4)
                        printf("\033[36m%c\033[0m", ch);  // Cyan
                    else if (brightness < 8)
                        printf("\033[35m%c\033[0m", ch);  // Magenta
                    else
                        printf("\033[33m%c\033[0m", ch);  // Yellow
                } else {
                    putchar(' ');
                }
            }
        }

        // Display title
        printf("\033[24;1H\033[1;37m   *** Spinning 3D Donut in C ***   Press Ctrl+C to exit\033[0m");

        A += 0.04;
        B += 0.02;

        // ~30 FPS
        usleep(33000);
    }

    // Show cursor on exit
    printf("\033[?25h");
    return 0;
}
