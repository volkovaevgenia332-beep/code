#include <stdio.h>
#include <locale.h>

#define INVENTORY_SIZE 10
#define HOURS_IN_DAY 24

#define ITEM_EMPTY 0 
#define ITEM_WOOD 1
#define ITEM_STONE 2
#define iTEM_SEEDS 3
#define ITEM_IRON 4
#define ITEM_GOLD 5
#define ITEM_POTION 6
#define ITEM_LEATHER 7
#define ITEM_DIAMOND 8

int get safe int() {
    int value;
    while (scanf("%d", &value) !=1){
        printf("Ошибка! Введено не число. Пожалуйста, введите корректное число: ")
        while (getchar() != "\n");
    
    }
    return value;
}
