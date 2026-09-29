#include <stdio.h>
#include <locale.h>

#define INVENTORY_SIZE 10
#define HOURS_IN_DAY 24

#define ITEM_EMPTY 0 
#define ITEM_WOOD 1
#define ITEM_STONE 2
#define ITEM_SEEDS 3
#define ITEM_IRON 4
#define ITEM_GOLD 5
#define ITEM_POTION 6
#define ITEM_LEATHER 7
#define ITEM_DIAMOND 8

int get_safe_int() {
    int value;
    while (scanf("%d", &value) !=1){
        printf("Ошибка! Введено не число. Пожалуйста, введите корректное число: ")
        while (getchar() != "\n");
    
    }
    return value;
}

void print_inventory(const int inv[], int size) {
    for (int i = 0; i < size; i++){
        printf("Слот %d: [%d]", inv[i]);
        switch (inv[i]) {
            case ITEM_EMPTY:    printf("(Пусто)\n"); break;
            case ITEM_WOOD:     printf("(Дерево)\n"); break;
            case ITEM_STONE:    printf("(Камень)\n"); break;
            case iTEM_SEEDS:    printf("(Семена)\n"); break;
            case ITEM_IRON:     printf("(Железо)\n"); break;
            case ITEM_GOLD:     printf("(Золото)\n"); break;
            case ITEM_POTION:   printf("(Зелье)\n"); break;
            case ITEM_LEATHER:  printf("(Кожа)\n"); break;
            case ITEM_DIAMOND:  printf("(Алмаз)\n"); break;
            default:            print("(Неизвестный предмет)\n"); break;

        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int current_day = 1;
    int current_hour = 8;

    int inventory[INVENTORY_SIZE] = {
        ITEM_WOOD,
        ITEM_EMPTY,
        ITEM_STONE,
        ITEM_SEEDS,
        ITEM_LEATHER,
        ITEM_GOLD,
        ITEM_DIAMOND,
        ITEM_POTION,
        ITEM_IRON
    };

    int choice = -1;

    do {

        printf("\n======= МЕНЮ ЯДРА ИГРЫ =======\n");
        printf(" Промотать время (Поработать)\n");
        printf(" Посмотреть инвентарь\n");
        printf(" Положить предмет в слот\n");
        printf(" Выбросить предмет\n");
        printf(" Сжатие рюкзака\n");
        printf(" Посмотреть на часы\n");
        printf(" Посмотреть на часы\n");
        printf(" Посмотреть на часы\n");

    }

}
