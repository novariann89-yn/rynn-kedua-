#include <stdio.h>
#include <math.h>

int main() {
    for (int angle = 0; angle < 360; angle += 30) {
        double rad = angle * M_PI / 180.0;

        double x = cos(rad);
        double y = sin(rad);

        printf("Sudut %d -> (%.2f, %.2f)\n", angle, x, y);
    }

    return 0;
}
