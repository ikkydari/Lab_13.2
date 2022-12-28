#include <stdio.h>
#include <iostream>
using namespace std;

#define Z 5                               // директива препроцесора – макровизначення
#define SQR(x) (x) * (x)                  // макрос з параметром – визначення квадрата числа
// макрос визначення найбільшого з двох чисел
#define MAX(y, z) ((y) > (z)) ? (y) : (z) // макрос як умовний вираз
#define MIN(y, z) ((y) < (z)) ? (y) : (z) // макрос як умовний вираз
#define MINUS(y, z) (y - z)
// виведення повідомлення та значення цілого числа
#define PRINTI(w)           \
    puts("control output"); \
    printf(#w "=%d\n", w)
// використовується символ продовження макроса '\'
// символ '#' використовується для об’єднання рядків
// виведення повідомлення та значення дійсного числа
#define PRINTR(w)     \
    puts("rezult :"); \
    printf(#w "=%f\n", (float)w)

// площа круга, вкладені макроси
#define SQCIRLE(r) (3.14 * SQR(r))
int main()
{
    puts("Lab 13.2. Using macros and preprocessing directive");
    int a, b,  // змінні для розрахунків
        right, // допоміжна змінна
        left,  // квадрат числа
        minim; // максимальне з трьох чисел
    char ch;   // відповідь чи продовжувати виконання програми
    puts("define maximum of two numbers");
    puts("Input 2 integer numbers");
    scanf("%d", &a); // введення числа
    PRINTI(a);       // макрос виведення числа
    scanf("%d", &b);
    PRINTI(b);
    do
    {
#if Z <= 1 // якщо умова істинна,
        // то шукаємо максимум з трьох чисел
        left = MINUS(a, b); // макрос визначення квадрату числа
        PRINTI(left);
        right = MINUS(b, Z);
        PRINTI(right);
        minim = MIN(left, right); // пошук максимуму з двох чисел
        PRINTR(minim);            // макрос виведення результату
#else                             // компілювати іншу частину програми, якщо N >= 10
        {
            left = SQR(MINUS(a, Z)); // макрос визначення квадрату числа
            PRINTI(left);
            right = MINUS(a, b);
            PRINTI(right);
            minim = MIN(left, right); // пошук максимуму з двох чисел
            PRINTR(minim);            // макрос виведення результату
        }
#endif                            // завершення блоку умовної компіляції
        puts("Repeat? y /n ");
        cin >> ch;
    } while (ch == 'y');
    return 0;
}