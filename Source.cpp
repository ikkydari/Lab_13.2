#include <stdio.h>
#include <iostream>
using namespace std;

#define Z 5                               // ��������� ������������ � ���������������
#define SQR(x) (x) * (x)                  // ������ � ���������� � ���������� �������� �����
// ������ ���������� ���������� � ���� �����
#define MAX(y, z) ((y) > (z)) ? (y) : (z) // ������ �� ������� �����
#define MIN(y, z) ((y) < (z)) ? (y) : (z) // ������ �� ������� �����
#define MINUS(y, z) (y - z)
// ��������� ����������� �� �������� ������ �����
#define PRINTI(w)           \
    puts("control output"); \
    printf(#w "=%d\n", w)
// ��������������� ������ ����������� ������� '\'
// ������ '#' ��������������� ��� �ᒺ������ �����
// ��������� ����������� �� �������� ������� �����
#define PRINTR(w)     \
    puts("rezult :"); \
    printf(#w "=%f\n", (float)w)

// ����� �����, ������� �������
#define SQCIRLE(r) (3.14 * SQR(r))
int main()
{
    puts("Lab 13.2. Using macros and preprocessing directive");
    int a, b,  // ���� ��� ����������
        right, // �������� �����
        left,  // ������� �����
        minim; // ����������� � ����� �����
    char ch;   // ������� �� ������������ ��������� ��������
    puts("define maximum of two numbers");
    puts("Input 2 integer numbers");
    scanf("%d", &a); // �������� �����
    PRINTI(a);       // ������ ��������� �����
    scanf("%d", &b);
    PRINTI(b);
    do
    {
#if Z <= 1 // ���� ����� �������,
        // �� ������ �������� � ����� �����
        left = MINUS(a, b); // ������ ���������� �������� �����
        PRINTI(left);
        right = MINUS(b, Z);
        PRINTI(right);
        minim = MIN(left, right); // ����� ��������� � ���� �����
        PRINTR(minim);            // ������ ��������� ����������
#else                             // ���������� ���� ������� ��������, ���� N >= 10
        {
            left = SQR(MINUS(a, Z)); // ������ ���������� �������� �����
            PRINTI(left);
            right = MINUS(a, b);
            PRINTI(right);
            minim = MIN(left, right); // ����� ��������� � ���� �����
            PRINTR(minim);            // ������ ��������� ����������
        }
#endif                            // ���������� ����� ������ ���������
        puts("Repeat? y /n ");
        cin >> ch;
    } while (ch == 'y');
    return 0;
}