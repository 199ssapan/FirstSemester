/*
Разобьем наше приложение для парковки из предыдущего занятия на модули.
Выделим отдельные логические части кода:
Автомобиль
Клиент
Парковка
Интерфейс приложения

Выделим каждую логическую часть в отдельный модуль.
Таким образом ориентироваться в коде становится проще.

Конечно, при желании можно было бы выбрать и другое разбиение
этого кода на модули, подумайте: каким образом это сделали бы вы?
*/
#include "ParkingApp.h"

int main(void) {
    struct Parking myParking;
    initParking(&myParking);
    while (mainMenu(&myParking));

    return 0;
}
