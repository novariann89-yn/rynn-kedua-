/*
 * C LANGUAGE LEARNING PROGRAM
 * Contains ALL C statements and concepts in an executable format
 * Compile: gcc -Wall -Wextra -Wno-unused-variable -std=c11 learn.c -o learn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// ============================================================================
// 1. PREPROCESSOR DIRECTIVES
// ============================================================================

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define GREET(name) printf("Hello, %s!\n", name)

// ============================================================================
// 2. GLOBAL VARIABLES (static at file scope)
// ============================================================================

static int global_count = 0;
extern int external_var;  // Defined later in this file

// ============================================================================
// 3. ENUMERATIONS
// ============================================================================

typedef enum {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
} Weekday;

typedef enum {
    RED = 1, GREEN = 2, BLUE = 4
} Color;

// ============================================================================
// 4. STRUCTURES
// ============================================================================

struct Point {
    int x;
    int y;
};

typedef struct {
    char name[50];
    int age;
    float score;
} Person;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ============================================================================
// 5. UNION
// ============================================================================

union Data {
    int i;
    double d;
    char str[20];
};

// ============================================================================
// 6. FUNCTION PROTOTYPES
// ============================================================================

void demo_if_else(int n);
void demo_switch(int choice);
void demo_for_loop(int n);
void demo_while_loop(int n);
void demo_do_while(int n);
int demo_function(int a, int b);
int demo_recursive(int n);
void demo_swap(int *a, int *b);
void demo_pointers(void);
void demo_arrays(void);
void demo_structures(void);
void demo_dynamic_memory(void);
void demo_file_io(void);
void demo_ternary(void);
void demo_bitwise(void);
void demo_type_casting(void);
void demo_generic(void);
void demo_goto(void);
void demo_break_continue(void);

// ============================================================================
// MAIN FUNCTION - Demonstrates ALL C statements
// ============================================================================

int main(void) {
    printf("========================================\n");
    printf("C LANGUAGE ALL STATEMENTS DEMONSTRATION\n");
    printf("========================================\n\n");

    // -----------------------------------------------------------------------
    // PREPROCESSOR DEMONSTRATION
    // -----------------------------------------------------------------------
    printf("=== 1. PREPROCESSOR DIRECTIVES ===\n");
    printf("PI = %.5f\n", PI);
    printf("SQUARE(5) = %d\n", SQUARE(5));
    GREET("Student");
    printf("\n");

    // -----------------------------------------------------------------------
    // 2. VARIABLE DECLARATIONS - ALL DATA TYPES
    // -----------------------------------------------------------------------
    printf("=== 2. VARIABLE DECLARATIONS (All Data Types) ===\n");
    
    char ch = 'A';
    signed char sch = -127;
    unsigned char uch = 255;
    
    short sh = -32768;
    unsigned short ush = 65535;
    
    int integer = 2147483647;
    unsigned int uinteger = 4294967295U;
    long lng = 9223372036854775807L;
    unsigned long ulng = 18446744073709551615UL;
    long long llng = 9223372036854775807LL;
    unsigned long long ullng = 18446744073709551615ULL;
    
    float flt = 3.14159f;
    double dbl = 3.141592653589793;
    long double ldbl = 3.141592653589793238L;
    
    bool boolean = true;
    
    printf("char: %c\n", ch);
    printf("signed char: %d, unsigned char: %u\n", sch, uch);
    printf("short: %d, unsigned short: %u\n", sh, ush);
    printf("int: %d, unsigned int: %u\n", integer, uinteger);
    printf("long: %ld, unsigned long: %lu\n", lng, ulng);
    printf("long long: %lld, unsigned long long: %llu\n", llng, ullng);
    printf("float: %.6f, double: %.15f\n", flt, dbl);
    printf("bool: %d\n", boolean);
    printf("\n");

    // -----------------------------------------------------------------------
    // 3. STATIC VARIABLES (function scope)
    // -----------------------------------------------------------------------
    printf("=== 3. STATIC VARIABLES ===\n");
    
    void show_static(void) {
        static int count = 0;
        count++;
        printf("Static count: %d\n", count);
    }
    
    show_static();
    show_static();
    show_static();
    printf("\n");

    // -----------------------------------------------------------------------
    // 4. GLOBAL VARIABLE
    // -----------------------------------------------------------------------
    printf("=== 4. GLOBAL VARIABLE ===\n");
    printf("global_count = %d\n", global_count);
    printf("external_var = %d\n", external_var);
    printf("\n");

    // -----------------------------------------------------------------------
    // 5. OPERATORS - ALL TYPES
    // -----------------------------------------------------------------------
    printf("=== 5. OPERATORS ===\n");
    
    int a = 20, b = 8;
    printf("a=%d, b=%d\n", a, b);
    
    // Arithmetic
    printf("Arithmetic: a+b=%d, a-b=%d, a*b=%d, a/b=%d, a%%b=%d\n",
           a+b, a-b, a*b, a/b, a%b);
    
    // Relational
    printf("Relational: a>b=%d, a<b=%d, a==b=%d, a!=b=%d\n",
           a>b, a<b, a==b, a!=b);
    
    // Logical
    printf("Logical: (a>10 && b<10)=%d, (a>10 || b<5)=%d, !(a==b)=%d\n",
           (a>10 && b<10), (a>10 || b<5), !(a==b));
    
    // Bitwise
    printf("Bitwise: a&b=%d, a|b=%d, a^b=%d, ~a=%d, a<<1=%d, a>>1=%d\n",
           a&b, a|b, a^b, ~a, a<<1, a>>1);
    
    // Assignment
    int c = a;
    c += b;  printf("c += b: %d\n", c);
    c -= b;  printf("c -= b: %d\n", c);
    c *= 2;  printf("c *= 2: %d\n", c);
    c /= 2;  printf("c /= 2: %d\n", c);
    c %= 3;  printf("c %%= 3: %d\n", c);
    
    // Ternary
    int max = (a > b) ? a : b;
    printf("Ternary: max(a,b) = %d\n", max);
    
    // Comma
    int x, y, z;
    z = (x = 5, y = 10, x + y);
    printf("Comma operator: z = %d\n", z);
    
    // sizeof
    printf("sizeof(int) = %zu, sizeof(double) = %zu\n", sizeof(int), sizeof(double));
    printf("\n");

    // -----------------------------------------------------------------------
    // 6. IF-ELSE STATEMENT
    // -----------------------------------------------------------------------
    printf("=== 6. IF-ELSE STATEMENT ===\n");
    demo_if_else(15);
    demo_if_else(5);
    demo_if_else(10);
    printf("\n");

    // -----------------------------------------------------------------------
    // 7. SWITCH STATEMENT
    // -----------------------------------------------------------------------
    printf("=== 7. SWITCH STATEMENT ===\n");
    demo_switch(1);
    demo_switch(2);
    demo_switch(3);
    demo_switch(99);
    printf("\n");

    // -----------------------------------------------------------------------
    // 8. FOR LOOP
    // -----------------------------------------------------------------------
    printf("=== 8. FOR LOOP ===\n");
    demo_for_loop(5);
    printf("\n");

    // -----------------------------------------------------------------------
    // 9. WHILE LOOP
    // -----------------------------------------------------------------------
    printf("=== 9. WHILE LOOP ===\n");
    demo_while_loop(5);
    printf("\n");

    // -----------------------------------------------------------------------
    // 10. DO-WHILE LOOP
    // -----------------------------------------------------------------------
    printf("=== 10. DO-WHILE LOOP ===\n");
    demo_do_while(5);
    printf("\n");

    // -----------------------------------------------------------------------
    // 11. BREAK AND CONTINUE
    // -----------------------------------------------------------------------
    printf("=== 11. BREAK AND CONTINUE ===\n");
    demo_break_continue();
    printf("\n");

    // -----------------------------------------------------------------------
    // 12. GOTO STATEMENT
    // -----------------------------------------------------------------------
    printf("=== 12. GOTO STATEMENT ===\n");
    demo_goto();
    printf("\n");

    // -----------------------------------------------------------------------
    // 13. FUNCTIONS
    // -----------------------------------------------------------------------
    printf("=== 13. FUNCTIONS ===\n");
    int sum = demo_function(10, 20);
    printf("demo_function(10, 20) = %d\n", sum);
    
    int fact = demo_recursive(5);
    printf("demo_recursive(5) = %d\n", fact);
    
    int p1 = 100, p2 = 200;
    printf("Before swap: p1=%d, p2=%d\n", p1, p2);
    demo_swap(&p1, &p2);
    printf("After swap: p1=%d, p2=%d\n", p1, p2);
    printf("\n");

    // -----------------------------------------------------------------------
    // 14. ARRAYS
    // -----------------------------------------------------------------------
    printf("=== 14. ARRAYS ===\n");
    demo_arrays();
    printf("\n");

    // -----------------------------------------------------------------------
    // 15. POINTERS
    // -----------------------------------------------------------------------
    printf("=== 15. POINTERS ===\n");
    demo_pointers();
    printf("\n");

    // -----------------------------------------------------------------------
    // 16. STRUCTURES
    // -----------------------------------------------------------------------
    printf("=== 16. STRUCTURES ===\n");
    demo_structures();
    printf("\n");

    // -----------------------------------------------------------------------
    // 17. UNION
    // -----------------------------------------------------------------------
    printf("=== 17. UNION ===\n");
    union Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);
    data.d = 3.14;
    printf("data.d = %.2f\n", data.d);
    strcpy(data.str, "Union Test");
    printf("data.str = %s\n", data.str);
    printf("union size: %zu bytes\n", sizeof(union Data));
    printf("\n");

    // -----------------------------------------------------------------------
    // 18. DYNAMIC MEMORY ALLOCATION
    // -----------------------------------------------------------------------
    printf("=== 18. DYNAMIC MEMORY ALLOCATION ===\n");
    demo_dynamic_memory();
    printf("\n");

    // -----------------------------------------------------------------------
    // 19. FILE I/O
    // -----------------------------------------------------------------------
    printf("=== 19. FILE I/O ===\n");
    demo_file_io();
    printf("\n");

    // -----------------------------------------------------------------------
    // 20. TYPE CASTING
    // -----------------------------------------------------------------------
    printf("=== 20. TYPE CASTING ===\n");
    demo_type_casting();
    printf("\n");

    // -----------------------------------------------------------------------
    // 21. ENUMERATIONS
    // -----------------------------------------------------------------------
    printf("=== 21. ENUMERATIONS ===\n");
    Weekday today = WEDNESDAY;
    printf("Today is weekday number: %d\n", today);
    
    Color col = GREEN;
    printf("Color GREEN = %d\n", col);
    printf("\n");

    // -----------------------------------------------------------------------
    // 22. EXTERNAL VARIABLE
    // -----------------------------------------------------------------------
    printf("=== 22. EXTERNAL VARIABLE ===\n");
    printf("external_var from main = %d\n", external_var);
    printf("\n");

    // -----------------------------------------------------------------------
    // 23. TYPEDEF
    // -----------------------------------------------------------------------
    printf("=== 23. TYPEDEF ===\n");
    Person p = {"Alice", 25, 95.5};
    printf("Person: %s, Age: %d, Score: %.1f\n", p.name, p.age, p.score);
    printf("\n");

    // -----------------------------------------------------------------------
    // 24. COMPOUND LITERALS (C99)
    // -----------------------------------------------------------------------
    printf("=== 24. COMPOUND LITERALS (C99) ===\n");
    int *arr = (int[]){1, 2, 3, 4, 5};
    printf("Compound array: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    
    Person person = (Person){"Bob", 30, 88.0};
    printf("Compound struct: %s, Age: %d\n", person.name, person.age);
    printf("\n");

    // -----------------------------------------------------------------------
    // 25. _GENERIC (C11)
    // -----------------------------------------------------------------------
    printf("=== 25. _GENERIC (C11) ===\n");
    demo_generic();
    printf("\n");

    // -----------------------------------------------------------------------
    // 26. CONDITIONAL COMPILATION
    // -----------------------------------------------------------------------
    printf("=== 26. CONDITIONAL COMPILATION ===\n");
    #ifdef __STDC_VERSION__
        printf("C Standard Version: %ld\n", __STDC_VERSION__);
    #else
        printf("Standard version not defined\n");
    #endif
    
    #if defined(__linux__)
        printf("Platform: Linux\n");
    #elif defined(_WIN32)
        printf("Platform: Windows\n");
    #elif defined(__APPLE__)
        printf("Platform: Apple\n");
    #else
        printf("Platform: Unknown\n");
    #endif
    printf("\n");

    // -----------------------------------------------------------------------
    // 27. SIZEOF WITH STRUCTURES
    // -----------------------------------------------------------------------
    printf("=== 27. SIZEOF OPERATOR ===\n");
    struct Point pt = {10, 20};
    printf("sizeof(struct Point) = %zu\n", sizeof(struct Point));
    printf("sizeof(Person) = %zu\n", sizeof(Person));
    printf("sizeof(Node) = %zu\n", sizeof(Node));
    printf("\n");

    // -----------------------------------------------------------------------
    // 28. CHARACTER FUNCTIONS
    // -----------------------------------------------------------------------
    printf("=== 28. CHARACTER FUNCTIONS ===\n");
    char test_char = 'a';
    printf("isupper('A') = %d\n", isupper('A'));
    printf("islower('a') = %d\n", islower('a'));
    printf("isdigit('5') = %d\n", isdigit('5'));
    printf("toupper('a') = %c\n", toupper(test_char));
    printf("tolower('B') = %c\n", tolower('B'));
    printf("\n");

    // -----------------------------------------------------------------------
    // 29. STRING FUNCTIONS
    // -----------------------------------------------------------------------
    printf("=== 29. STRING FUNCTIONS ===\n");
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    printf("strlen(\"Hello\") = %zu\n", strlen(str1));
    printf("strcmp(\"Hello\", \"World\") = %d\n", strcmp(str1, str2));
    strcpy(str1, str2);
    printf("strcpy: str1 = %s\n", str1);
    strcat(str1, "!");
    printf("strcat: str1 = %s\n", str1);
    printf("\n");

    // -----------------------------------------------------------------------
    // 30. MEMORY OPERATIONS
    // -----------------------------------------------------------------------
    printf("=== 30. MEMORY OPERATIONS ===\n");
    char buffer[20];
    memset(buffer, 'X', 5);
    buffer[5] = '\0';
    printf("memset: %s\n", buffer);
    
    int numbers[5] = {1, 2, 3, 4, 5};
    int new_nums[5];
    memcpy(new_nums, numbers, 5 * sizeof(int));
    printf("memcpy: ");
    for (int i = 0; i < 5; i++) printf("%d ", new_nums[i]);
    printf("\n");
    printf("\n");

    // -----------------------------------------------------------------------
    // 31. EXIT AND RETURN
    // -----------------------------------------------------------------------
    printf("=== 31. EXIT FUNCTIONS ===\n");
    printf("This demo runs normally and returns 0\n");
    printf("exit() could be called with: exit(0) or exit(1)\n");
    printf("\n");

    // -----------------------------------------------------------------------
    // 32. LINKAGE (static function - internal linkage)
    // -----------------------------------------------------------------------
    printf("=== 32. STATIC FUNCTION (Internal Linkage) ===\n");
    printf("Static functions are only visible in this file.\n");
    printf("\n");

    return 0;
}

// ============================================================================
// FUNCTION DEFINITIONS
// ============================================================================

void demo_if_else(int n) {
    printf("Testing n = %d:\n", n);
    
    if (n > 10) {
        printf("  n is greater than 10\n");
    } else if (n == 10) {
        printf("  n equals 10\n");
    } else {
        printf("  n is less than 10\n");
    }
    
    // Nested if
    if (n > 0) {
        if (n % 2 == 0) {
            printf("  n is positive and even\n");
        } else {
            printf("  n is positive and odd\n");
        }
    }
}

void demo_switch(int choice) {
    switch (choice) {
        case 1:
            printf("Choice 1: Start\n");
            break;
        case 2:
            printf("Choice 2: Stop\n");
            break;
        case 3:
            printf("Choice 3: Pause\n");
            break;
        default:
            printf("Choice %d: Unknown\n", choice);
            break;
    }
}

void demo_for_loop(int n) {
    printf("For loop from 0 to %d:\n", n-1);
    for (int i = 0; i < n; i++) {
        printf("  i = %d\n", i);
    }
}

void demo_while_loop(int n) {
    printf("While loop from 0 to %d:\n", n-1);
    int i = 0;
    while (i < n) {
        printf("  i = %d\n", i);
        i++;
    }
}

void demo_do_while(int n) {
    printf("Do-while loop from 0 to %d:\n", n-1);
    int i = 0;
    do {
        printf("  i = %d\n", i);
        i++;
    } while (i < n);
}

int demo_function(int a, int b) {
    return a + b;
}

int demo_recursive(int n) {
    if (n <= 1) return 1;
    return n * demo_recursive(n - 1);
}

void demo_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demo_arrays(void) {
    // 1D array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("1D Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 2D array
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("2D Array (2x3):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // String
    char str[] = "Hello, World!";
    printf("String: %s\n", str);
    printf("String length: %zu\n", strlen(str));
}

void demo_pointers(void) {
    int var = 42;
    int *ptr = &var;
    
    printf("Variable: var = %d\n", var);
    printf("Address of var: %p\n", (void*)&var);
    printf("Pointer holds: %p\n", (void*)ptr);
    printf("Dereferenced pointer: *ptr = %d\n", *ptr);
    
    // Pointer arithmetic
    int arr[3] = {10, 20, 30};
    int *p = arr;
    printf("\nPointer arithmetic:\n");
    printf("  p = %p, *p = %d\n", (void*)p, *p);
    printf("  p+1 = %p, *(p+1) = %d\n", (void*)(p+1), *(p+1));
    printf("  p+2 = %p, *(p+2) = %d\n", (void*)(p+2), *(p+2));
    
    // Pointer to pointer
    int **ptr_to_ptr = &ptr;
    printf("\nPointer to pointer:\n");
    printf("  **ptr_to_ptr = %d\n", **ptr_to_ptr);
}

void demo_structures(void) {
    struct Point origin = {0, 0};
    struct Point point1 = {10, 20};
    
    printf("struct Point:\n");
    printf("  origin: (%d, %d)\n", origin.x, origin.y);
    printf("  point1: (%d, %d)\n", point1.x, point1.y);
    
    // Using typedef struct
    Person students[2] = {
        {"Charlie", 20, 88.5},
        {"Diana", 22, 92.0}
    };
    
    printf("\nPerson array:\n");
    for (int i = 0; i < 2; i++) {
        printf("  %s: Age %d, Score %.1f\n", students[i].name, students[i].age, students[i].score);
    }
    
    // Linked list with struct
    Node *head = malloc(sizeof(Node));
    if (head != NULL) {
        head->data = 100;
        head->next = NULL;
        printf("\nLinked list node: data=%d\n", head->data);
        free(head);
    }
}

void demo_dynamic_memory(void) {
    printf("malloc example:\n");
    int *arr = malloc(5 * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < 5; i++) {
            arr[i] = (i + 1) * 10;
            printf("  arr[%d] = %d\n", i, arr[i]);
        }
        free(arr);
        printf("  Memory freed\n");
    }
    
    printf("\ncalloc example:\n");
    int *arr2 = calloc(5, sizeof(int));
    if (arr2 != NULL) {
        printf("  Initial values (all zeros):\n");
        for (int i = 0; i < 5; i++) {
            printf("  arr2[%d] = %d\n", i, arr2[i]);
        }
        free(arr2);
    }
    
    printf("\nrealloc example:\n");
    int *arr3 = malloc(3 * sizeof(int));
    if (arr3 != NULL) {
        for (int i = 0; i < 3; i++) arr3[i] = i + 1;
        printf("  Before realloc: 3 elements\n");
        arr3 = realloc(arr3, 5 * sizeof(int));
        if (arr3 != NULL) {
            for (int i = 3; i < 5; i++) arr3[i] = i + 1;
            printf("  After realloc: 5 elements\n");
            for (int i = 0; i < 5; i++) {
                printf("  arr3[%d] = %d\n", i, arr3[i]);
            }
        }
        free(arr3);
    }
}

void demo_file_io(void) {
    // Write to file
    FILE *fp = fopen("/tmp/demo.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "Line 1: Hello File!\n");
        fprintf(fp, "Line 2: Number = %d\n", 42);
        fprintf(fp, "Line 3: Float = %.2f\n", 3.14);
        fclose(fp);
        printf("Written to /tmp/demo.txt\n");
    }
    
    // Read from file
    fp = fopen("/tmp/demo.txt", "r");
    if (fp != NULL) {
        char line[100];
        printf("Reading /tmp/demo.txt:\n");
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("  %s", line);
        }
        fclose(fp);
    }
    
    // Binary file
    fp = fopen("/tmp/binary.bin", "wb");
    if (fp != NULL) {
        int data[] = {1, 2, 3, 4, 5};
        fwrite(data, sizeof(int), 5, fp);
        fclose(fp);
        printf("\nWrote binary file with 5 integers\n");
    }
    
    fp = fopen("/tmp/binary.bin", "rb");
    if (fp != NULL) {
        int buffer[5];
        fread(buffer, sizeof(int), 5, fp);
        printf("Read binary file: ");
        for (int i = 0; i < 5; i++) printf("%d ", buffer[i]);
        printf("\n");
        fclose(fp);
    }
}

void demo_type_casting(void) {
    int a = 10;
    float b = 3.0f;
    
    printf("Implicit casting (widening):\n");
    float result = a + b;
    printf("  %d + %.1f = %.1f\n", a, b, result);
    
    printf("\nExplicit casting (narrowing):\n");
    float c = 10.75f;
    int truncated = (int)c;
    printf("  (int)%.2f = %d\n", c, truncated);
    
    printf("\nAvoiding integer division:\n");
    float div_result = (float)a / b;
    printf("  (float)%d / %.1f = %.2f\n", a, b, div_result);
    
    printf("\nCast during function call:\n");
    printf("  isdigit('5'): %d\n", isdigit((int)'5'));
}

void demo_generic(void) {
    // _Generic selection
    #define MY_TYPE(x) _Generic((x), \
        int: "int", \
        float: "float", \
        double: "double", \
        char*: "char*", \
        default: "other" \
    )
    
    printf("Type selection:\n");
    printf("  Type of 42: %s\n", MY_TYPE(42));
    printf("  Type of 3.14f: %s\n", MY_TYPE(3.14f));
    printf("  Type of 3.14: %s\n", MY_TYPE(3.14));
    printf("  Type of \"text\": %s\n", MY_TYPE("text"));
}

void demo_goto(void) {
    printf("Demonstrating goto:\n");
    
    printf("  Step 1\n");
    printf("  Step 2\n");
    
    goto skip_steps;
    
    printf("  This line will NOT be executed\n");
    printf("  This also will NOT be executed\n");
    
skip_steps:
    printf("  jumped here using goto!\n");
    printf("  Step 3 (after jump)\n");
}

void demo_break_continue(void) {
    printf("Demonstrating break and continue:\n");
    printf("  Loop with continue (skipping 3) and break (at 7):\n");
    
    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            printf("    Skipping i=%d (continue)\n", i);
            continue;
        }
        if (i == 7) {
            printf("    Breaking at i=%d\n", i);
            break;
        }
        printf("    i = %d\n", i);
    }
}

// ============================================================================
// EXTERNAL VARIABLE DEFINITION
// ============================================================================

int external_var = 999;

// ============================================================================
// END OF FILE
// ============================================================================