#include <stdio.h>
#include <locale.h>

// защита от магических чисел
#define INVENTORY_SIZE 10
#define HOURS_IN_DAY 24

// список предметов в игре
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
        while (getchar() != '\n');
    
    }
    return value;
}

// вывод содержимого рюкзака на экран
void print_inventory(const int inv[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Слот %d: [%d]", i, inv[i]);
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
            default:            printf("(Неизвестный предмет)\n"); break;

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
        printf(" 1. Посмотреть на часы\n");
        printf(" 2. Промотать время (Поработать)\n");
        printf(" 3. Посмотреть инвентарь\n");
        printf(" 4. Положить предмет в слот\n");
        printf(" 5. Выбросить предмет\n");
        printf(" 6. Любимый ресурс\n");
        printf(" 7. Выход\n");
        printf("Выберите действие: \n");

        choice = get_safe_int();
        printf("\n");

        switch(choice) {
            case 7:
                printf("Завершение работы программы. До встречи в игре!\n");
                break;
            case 1:
                printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
                break;
            case 2:{
                printf("Сколько часов вы хотите поработать? ");
                int hours_to_work = get_safe_int();

                if (hours_to_work < 0) {
                    printf("Ошибка! Время работы не может быть отрицательным.\n");
                } else {
                    current_hour += hours_to_work;
                    current_day += current_hour / HOURS_IN_DAY;
                    current_hour = current_hour % HOURS_IN_DAY;
                    printf("Вы успешно поработали! Время перемотано.\n");
                }
                break;
            }
            case 3:
                printf("===== Содержимое инвентаря =====\n");
                print_inventory(inventory, INVENTORY_SIZE);
                break;

            case 4: {
                printf("Введите индекс слота (от 0 до %d): ", INVENTORY_SIZE - 1);
                int slot_index = get_safe_int();

                if (slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    printf("Ошибка! Неверный индекс. Допустимый диапазон: 0 - %d\n", INVENTORY_SIZE - 1);
                    break;
                }

                printf("Введите айди предмета (1-Дерево, 2-Камень, 3-Семена, 4-Железо, 5-Золото, 6-Зелье, 7-Кожа, 8-Алмаз):");
                int item_id = get_safe_int();

                if (item_id < 0 || item_id > ITEM_DIAMOND) {
                    printf("Ошибка! Предмета с таким id не существует.\n");
                } else {
                    inventory[slot_index] = item_id;
                    printf("Предмет успешно помещен в слот %d. \n", slot_index);
                }
                break;
            }
            
            case 5: {
                printf("Введите индекс слота для очистки (от 0 до %d): ", INVENTORY_SIZE - 1);
                int slot_index = get_safe_int();

                if (slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    printf("Ошибка! Неверный индекс слота. \n");    
                } else {
                    inventory[slot_index] = ITEM_EMPTY;
                    printf("Слот %d очищен. \n", slot_index);
                }
                break;
            }
            case 6: {
                printf("=== Поиск любимого ресурса ===\n");
                printf("Текущий  массив инвентаря: \n");
                print_inventory(inventory, INVENTORY_SIZE);

                // массив счетчик
                int counts[TOTAL_UNIQUE_ITEMS] = {0};

                // подсчет сколько раз встречается предмет
                for (int i = 0; i < INVENTORY_SIZE; i++) {
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
                        favourite_id = id;
                    }
                }

                // вывод результата
                printf("\n Результат анализа: \n");
                if (favourite_id == -1 || max_slots == 0){
                    printf("Рюкзак пуст! Любимый предмет не найден.\n");
                } else {
                    printf("Любимый ресурс имеет id: [%d]\n", favourite_id);

                    // вывод текстового названия предмета
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
                    printf("Количество занимаемых слотов: %d\n", max_slots);
                }
                break;
            }

            default:
                printf("Неверный пункт меню! Выберите число от 1 до 7. \n");
                break;
        }
        
    } while (choice !=0);

    return 0;

}
