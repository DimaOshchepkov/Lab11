// Lab11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Cstring.h"

using namespace std;

template <typename T1, typename T2>
void printMap(std::map<T1, T2> m);

int main()
{
    enum TASK { CLEAN, REPLACE, TELEGRAM, TEXT, ENTRY, CLEAN_TEXT, POLINDROM, CONVER_DOT, };

    char str[100] = { '\0' }, find = ' ';
    const char* const number[] = { "1)replace", "2)telegram", "3)text",
        "4)entry","5)cleanText","6)polindrom", "7)convertDot", "end"};
    int z;
    while (true)
    {
        for (int i = 0; number[i] != "end"; i++)
            printf_s("%s\n", number[i]);
        scanf_s("%d", &z);
        while (getchar() != '\n');
        switch (z)
        {
        case TASK::REPLACE: {
            char c1, c2;
            printf_s("Input string = ");
            gets_s(str);
            printf_s("c1, c2 = ");
            scanf_s("%c", &c1);
            while (getchar() != '\n');
            scanf_s("%c", &c2);
            while (getchar() != '\n');
            replaceC(str, c1, c2);
            printf_s("%s\n", str);
            break;
        }
        case TASK::TELEGRAM: {
            int price;
            printf_s("Input prince = ");
            scanf_s("%d", &price);
            while (getchar() != '\n');
            printf_s("Input string = ");
            gets_s(str);
            int answer = countWord(str) * price;
            printf_s("%d\n", answer);
            break;
        }
        case TASK::TEXT: {
            printf_s("Input string = ");
            gets_s(str);
            const char* N3[] = { "AS_SENTENCE = 1", "TOLOWER = 2", "TOUPPER = 3", "BEGIN_WORD_UP = 4",
                "CHANGE_REGISTR = 5", "CLOSE = 6", "\0" };
            for (int i = 0; N3[i] != "\0"; i++)
                printf_s("%s\n", N3[i]);
            enum N3 { AS_SENTENCE = 1, TOLOWER, TOUPPER, BEGIN_WORD_UP, CHANGE_REGISTR, CLOSE };
            int zz;
            bool isOpen = true;
            while (isOpen) {
                scanf_s("%d", &zz);
                while (getchar() != '\n');
                switch (zz)
                {
                case N3::AS_SENTENCE:
                    printf_s("%s\n", asSentens(str));
                    break;
                case N3::TOLOWER:
                    printf_s("%s\n", tolower(str));
                    break;
                case N3::TOUPPER:
                    printf_s("%s\n", toupper(str));
                    break;
                case N3::BEGIN_WORD_UP:
                    printf_s("%s\n", beginWordUp(str));
                    break;
                case N3::CHANGE_REGISTR:
                    printf_s("%s\n", changeRegistr(str));
                    break;
                case N3::CLOSE:
                    isOpen = false;
                    break;
                }
            }
        }
            break;
        case TASK::ENTRY: {
            printf_s("Input string = ");
            gets_s(str);
            map<char, int> voc = vocabulary(str);
            printMap(voc);
            printf_s("%s\n", street(str));
            break;
        }
        case TASK::CLEAN_TEXT: {
            printf_s("Input string = ");
            gets_s(str);
            cleanT c = cleanText(str);
            printf_s("%s\ncount del space = %d\ncount insert space = %d\n", c.newStr, c.countDelSpace, c.countInsSpace);
            break;
            
        }
        case TASK::POLINDROM: {
            printf_s("Input string = ");
            gets_s(str);
            const char* t = delSpacePunctAndUp(str);
            printf_s("String = %s\n", t);
            (isPolindrom(t)) ? printf_s("It is polindrom\n") : printf_s("It is not polindrom\n");
            break;
        }
        case TASK::CONVER_DOT: {
            printf_s("Input string = ");
            gets_s(str);
            char dot = '.';
            char dotReplace[] = "dot";
            const char* t = convertDot(str, dot, dotReplace);
            printf_s("%s\n", t);
            break;
        }
        }
        /*cout << "Do you want clean consol?(input " << TASK::CLEAN << ")\n";
        cin >> z;
        if (z == TASK::CLEAN)
            system("cls");*/
    }
}

template <typename T1, typename T2>
void printMap(std::map<T1, T2> m)
{
    for (auto it = m.begin(); it != m.end(); it++)
        std::cout << it->first << ' ' << it->second << '\n';
};


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
