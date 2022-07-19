#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>

using namespace std;

int* stack1, * stack2, * stack3, top1 = 0,
top2 = 0, top3 = 0, element, m;

void push(int start) {
    if (start == 1) {
        for (int i = top1 - 1; i >= 0; i--)
            stack1[i + 1] = stack1[i];

        stack1[0] = element;
        top1++;
    }

    if (start == 2) {
        for (int i = top2 - 1; i >= 0; i--)
            stack2[i + 1] = stack2[i];

        stack2[0] = element;
        top2++;
    }

    if (start == 3) {
        for (int i = top3 - 1; i >= 0; i--)
            stack3[i + 1] = stack3[i];

        stack3[0] = element;
        top3++;
    }
}

void pop(int start) {
    if (start == 1)
    {
        element = stack1[0];
        for (int i = 0; i <= top1 - 1; i++) {
            stack1[i] = stack1[i + 1];
            if (i == top1 - 1)
                stack1[i] = 0;
        }
        top1--;
    }

    if (start == 2)
    {
        element = stack2[0];
        for (int i = 0; i <= top2 - 1; i++) {
            stack2[i] = stack2[i + 1];
            if (i == top2 - 1)
                stack2[i] = 0;
        }
        top2--;
    }

    if (start == 3)
    {
        element = stack3[0];
        for (int i = 0; i <= top3 - 1; i++) {
            stack3[i] = stack3[i + 1];
            if (i == top3 - 1)
                stack3[i] = 0;
        }
        top3--;
    }
}

void Input() {
    cout << "   Исходный   " << "Промежуточный " << "   Конечный  " << endl;
    for (int i = 0; i < m; i++) {
        if (i < top1)
            cout << setw(7) << stack1[i];
        else cout << setw(7) << 0;
        if (i < top2)
            cout << setw(14) << stack2[i];
        else cout << setw(14) << 0;
        if (i < top3)
            cout << setw(14) << stack3[i] << endl;
        else cout << setw(14) << 0 << endl;
    }
}

void Hanoi_Tower(int m, int start, int destination, int buffer)
{
    int operation = 0;
    if (m == 0)
    {
        return;
    }
    Hanoi_Tower(m - 1, start, buffer, destination);
    cout << start << " -> " << destination << endl;
    cout << endl;
    pop(start);
    push(destination);
    Input();
    Hanoi_Tower(m - 1, buffer, destination, start);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int start = 1, destination = 3, buffer = 2;

metka:
    cout << "Количество дисков не должно привышать 10!" << endl;
    cout << "Введите количество дисков: "; cin >> m;
    if (m > 10) {
        system("CLS");
        goto metka;
    }
    stack1 = new int[m];
    stack2 = new int[m];
    stack3 = new int[m];

    for (int i = 0; i < m; i++) {
        element = m - i;
        push(start);
    }

    Input();

    Hanoi_Tower(m, start, destination, buffer);
    cout << "Число операций: " << pow(2, m) - 1;
    delete[] stack1;
    delete[] stack2;
    delete[] stack3;
    return 0;
}
