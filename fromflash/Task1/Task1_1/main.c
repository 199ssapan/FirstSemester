#include <stdio.h>
#include <locale.h>
#include <Windows.h>

int main(void) {
    setlocale(LC_ALL, "ru-RU");
    printf_s("Hello world!\n������ ���!\n");
    system("pause");
    return 0;
}