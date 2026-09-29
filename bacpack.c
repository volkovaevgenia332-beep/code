#include <stdio.h>
#include <locale.h>

// защита от магических чисел
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

// общее кол-во уникальных предметов
#define TOTAL_UNIQUE_ITEMS 9

// защита от неправильного ввода(дурака)
int get_safe_int() {
    int value;
    while (scanf("%d", &value) !=1) {
        printf("Ошибка! Введено не число. Пожалуйста, введите корректное число: ");
        while (getchar() != "\n");
    
    }
    return value;
}

// вывод содержимого рюкзака на экран
void print_inventory(const int inv[], int size) {
    for (int i = 0; i < size; i++){
        printf("Слот %d: [%d]", inv[i]);
        switch (inv[i]) {
            case ITEM_EMPTY:    printf("(Пусто)\n"); break;
            case ITEM_WOOD:     printf("(Дерево)\n"); break;
            case ITEM_STONE:    printf("(Камень)\n"); break;
            case ITEM_SEEDS:    printf("(Семена)\n"); break;
            case ITEM_IRON:     printf("(Железо)\n"); break;
            case ITEM_GOLD:     printf("(Золото)\n"); break;
            case ITEM_POTION:   printf("(Зелье)\n"); break;
            case ITEM_LEATHER:  printf("(Кожа)\n"); break;
            case ITEM_DIAMOND:  printf("(Алмаз)\n"); break;
            default:            print("(Неизвестный предмет)\n"); break;

        }
    }
}

// основная функция
int main() {
    setlocale(LC_ALL, "Russian");

    // игровое время по умолчанию
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
        printf(" Посмотреть на часы\n");
        printf(" Промотать время (Поработать)\n");
        printf(" Посмотреть инвентарь\n");
        printf(" Положить предмет в слот\n");
        printf(" Выбросить предмет\n");
        printf(" Любимый ресурс\n");
        printf(" Выход\n");
        printf(" Выберите действие\n");

        choice = get_safe_int();
        printf("\n");

        switch(choice) {
            case 0:
                printf("ПОКА\n");
                break;
            case 1:
                printf("Время", current_day, current_hour);
                break;
            case 2:{
                printf("сколько работать");
                int hours_to_work = get_safe_int();

                if (hours_to_work < 0) {
                    printf("ошибка времени");
                } else {
                    current_hour += hours_to_work;
                    current_day += current_hour / HOURS_IN_DAY;
                    current_hour = current_hour % HOURS_IN_DAY;
                    printf("время перемотано");
                }
                break;
            }
            case 3:
            printf("инвентарь");
            print_inventory(inventory, INVENTORY_SIZE);
            break;

            case 4: {
                printf("введите слот", INVENTORY_SIZE - 1);
                int slot_index = get_safe_int();

                if (slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    printf("ошибка вы дурак", INVENTORY_SIZE - 1);
                    break;
                }

                printf("введите айди предмета");
                int item_id = get_safe_int();

                if (item_id < 0 || item_id > ITEM_DIAMOND) {
                    printf("ошибка вы дурак");
                } else {
                    inventory[slot_index] = item_id;
                    printf("предмет помещен в слот", slot_index);
                }
                break;
            }
            
            case 5: {
                printf("индекс слота для очистки", INVENTORY_SIZE - 1);
                int slot_index = get_safe_int();

                if (slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    printf("ошибка вы дурак");    
                } else {
                    inventory[slot_index] = ITEM_EMPTY;
                    printf("слот очищен", slot_index);
                }
                break;
            }
            case 6: {
                printf("любими ресурс");
                printf("текущий  массив инв");
                print_inventory(inventory, INVENTORY_SIZE);

                // массив счетчик
                int counts[TOTAL_UNIQUE_ITEMS] = {0};

                // подсчет сколько раз встречается предмет
                for (int i = 0; < INVENTORY_SIZE; i++) {
                    int current_id = inventory[i];
                    
                    //игнор пустых слотов
                    if (current_id != ITEM_EMPTY) {
                        counts[current_id]++;
                    }
                }

                // поиск максимума
                int max_slots = 0; // колво любим слотов
                int favourite_id = -1; // ид любим предмета

                for (int id = 1; id < TOTAL_UNIQUE_ITEMS; id++) {
                    if (counts[id] > max_slots) {
                        max_slots = counts[id];
                        favourite_id = id
                    }
                }

                // вывод результата
                printf("результат анализа");
                if (favourite_id == -1 || max_clots == 0){
                    printf("пусто и любими ресурса нет");
                } else {
                    printf("любими предмет:", favourite_id);

                    printf("название предмета: ");
                    switch (favourite_id) {
                        case ITEM_WOOD:     printf("(Дерево)\n"); break;
                        case ITEM_STONE:    printf("(Камень)\n"); break;
                        case ITEM_SEEDS:    printf("(Семена)\n"); break;
                        case ITEM_IRON:     printf("(Железо)\n"); break;
                        case ITEM_GOLD:     printf("(Золото)\n"); break;
                        case ITEM_POTION:   printf("(Зелье)\n"); break;
                        case ITEM_LEATHER:  printf("(Кожа)\n"); break;
                        case ITEM_DIAMOND:  printf("(Алмаз)\n"); break;
                    }
                    printf("", max_slots);
                }
                break;
            }

            default:
                printf("неверный пункт меню");
                break;
        }
        
    } while (choice !=0);

    return 0;

}
