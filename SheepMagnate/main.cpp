#include <iostream>
#include "sheeps.h"
#include "clients.h"

using namespace std;

// Очистить экран и вывести меню
void printMenu(Client clients[], int clientsSize, Sheep sheeps[], int sheepsSize, int countOfMoney, double countOfWool, double countOfMeat, int mode = 1)
{
    switch (mode)
    {
    case 1:
        cout << "Баланс: " << countOfMoney << " руб.\n" << "Запасы шерсти: " << countOfWool << " кг" << endl
            << "Запасы мяса: " << countOfMeat << " кг" << endl << endl;

        cout << "Список заказов: " << ((!clientsSize) ? "-\n" : "\n");
        printClients(clients, clientsSize, 0);

        // Выводим всех овец
        cout << endl;
        printSheeps(sheeps, sheepsSize);
        cout << endl;

        break;

    case 2:
        cout << "Баланс: " << countOfMoney << " руб.\n" << "Запасы шерсти: " << countOfWool << " кг" << endl
            << "Запасы мяса: " << countOfMeat << " кг" << endl << endl;

        cout << "Список заказов:\n";
        printClients(clients, clientsSize, 1);
        cout << endl;

        break;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    srand(time(0));

    // Переменная, хранящая код выхода из игры (для отслеживания концовок)
    short gameCode = 0;

    // Массив овец
    int sheepsSize = 5;
    Sheep* sheeps = new Sheep[sheepsSize];

    int clientsSize = rand() % 3 + 2;

    // Массив клиентов
    Client* clients = new Client[clientsSize];

    // Кол-во шерсти на складе в кг
    double countOfWool = 0.0;

    // Кол-во мяса на складе в кг
    double countOfMeat = 0.0;

    // Кол-во денег
    int countOfMoney = 10000;

    // Переменная для хранения выбора пользователя
    // Будет использоваться в каждом выборе далее
    short cmd;

    printWithDelay("В этой игре тебе предстоит целый месяц ухаживать за овцами и баранами на ферме своего друга, который уехал", 50);
    printWithDelay(" в командировку на весь Январь.", 50);
    Sleep(500);
    printWithDelay(" У тебя будет всё необходимое: дом, загон со скотом, приспособление для их стрижки, ведь если шерсти на животном", 50);
    printWithDelay(" будет слишком много, оно может умереть, и скотобойня.", 50);
    Sleep(500);
    printWithDelay(" Ферма твоего друга имеет хорошую репутацию, и где-то раз в пять дней у тебя будет появляться новый заказ от клиента.", 50);
    Sleep(500);
    printWithDelay(" Также, раз в пять дней тебе на ферму будут привозить новое животное.", 50);
    Sleep(1000);
    printWithDelay(" Ну что, ты готов?", 50);

    cout << endl;
    cin.ignore();

    printWithDelay("Отлично!", 50);
    Sleep(500);
    printWithDelay(" Правила простые: в день можно стричь максимум трёх животных и отправлять на скотобойню максимум двух.", 50);
    Sleep(500);
    printWithDelay(" Также у тебя в загоне может быть минимум два животных (если они не умрут сами конечно).", 50);
    Sleep(500);
    printWithDelay(" Постарайся не растерять свои деньги к концу месяца, ведь счета за коммунальные услуги никого не щадят.", 50);
    Sleep(500);
    printWithDelay(" Ах да, и не забывай, что мясо на складе быстро портится.", 50);
    
    cout << endl;
    cin.ignore();

    for (int i = ToDay.day - 1; i < ToDay.__daysInMonth__(); i++)
    {
        // Очищаем вывод консоли (только на Windows)
        system("cls");

        // Выводим дату с задержкой 100 мс между символами
        printWithDelay("Сегодня: " + ToDay.print(), 100);

        cout << endl << endl;

        // Выводим меню
        printMenu(clients, clientsSize, sheeps, sheepsSize, countOfMoney, countOfWool, countOfMeat);

        int cmdSheerSize = 0;

        // Массив для хранения номеров овец для стрижки
        int* cmdSheer = new int[cmdSheerSize];

        // Стрижём 3 овцы
        for (int j = 0; j < 3; j++)
        {
            // Проверка на кол-во овец
            if (sheepsSize <= j)
                break;

            printWithDelay("Введите номер животного для стрижки (0 чтобы закончить): ", 25);
            cin >> cmd;

            if (cmd)
            {
                // Было ли животное уже подстрижено
                bool isSheerFlag = 0;

                for (int k = 0; k < cmdSheerSize; k++)
                {
                    if (cmd - 1 == cmdSheer[k])
                    {
                        isSheerFlag = 1;

                        break;
                    }
                }

                if (isSheerFlag)
                {
                    cout << "Это животное уже было подстрижено" << endl;
                    j--;
                    continue;
                }
                else
                    arrayAddEl(cmdSheer, cmdSheerSize, cmd - 1);

                double woolPlus = sheeps[cmd - 1].sheer() / 1000.0;

                cout << "В запасы добавлено " << woolPlus << " кг шерсти" << endl;

                countOfWool += woolPlus;
            }
            else
                break;
        }

        delete[] cmdSheer;

        // Если овец больше 2
        if (sheepsSize > 2) //------------------- 2
        {
            // Очищаем вывод консоли (только на Windows)
            system("cls");

            // Выводим дату
            cout << "Сегодня: " << ToDay.print() << endl << endl;

            // Выводим меню
            printMenu(clients, clientsSize, sheeps, sheepsSize, countOfMoney, countOfWool, countOfMeat);

            int cmdKillSize = 0;

            // Массив для хранения номеров овец на убой
            int* cmdKill = new int[cmdKillSize];

            // Убиваем 2 овцы (или 1 овцу если овец 3)
            for (int j = 0; j < ((sheepsSize == 3) ? 1 : 2); j++) // ------ 2
            {
                printWithDelay("Введите номер животного на убой (0 чтобы закончить): ", 25);
                cin >> cmd;

                if (cmd)
                {
                    // Было ли животное уже отправлено на убой до этого
                    bool isKillFlag = 0;

                    for (int k = 0; k < cmdKillSize; k++)
                    {
                        if (cmd - 1 == cmdKill[k])
                        {
                            isKillFlag = 1;

                            break;
                        }
                    }

                    if (isKillFlag)
                    {
                        cout << "Это животное уже пошло на убой" << endl;
                        j--;
                        continue;
                    }
                    else
                        arrayAddEl(cmdKill, cmdKillSize, cmd - 1);

                    double woolPlus = sheeps[cmd - 1].sheer() / 1000.0;
                    double meatPlus = (sheeps[cmd - 1].sheepWeight - woolPlus) * __random__(2450, 3505) / 10000;

                    cout << "В запасы добавлено " << meatPlus << " кг мяса" << endl;
                    countOfMeat += meatPlus;

                    cout << "В запасы добавлено " << woolPlus << " кг шерсти" << endl;
                    countOfWool += woolPlus;
                }
                else
                    break;
            }

            // Удаляем овец по индексам из массива cmdKill
            arrayDeleteElsByIndexes(sheeps, sheepsSize, cmdKill, cmdKillSize);

            delete[] cmdKill;
        }

        // Кол-во заказов, которые можно завершить
        int countOfCompletableOrders = isAnyClientCompletable(clients, clientsSize, countOfMeat, countOfWool);

        if (countOfCompletableOrders)
        {
            // Очищаем вывод консоли (только на Windows)
            system("cls");

            // Выводим дату
            cout << "Сегодня: " << ToDay.print() << endl << endl;

            // Выводим меню
            printMenu(clients, clientsSize, sheeps, sheepsSize, countOfMoney, countOfWool, countOfMeat, 2);
            
            int cmdOrderSize = 0;

            // Массив для хранения номеров выбранных заказов
            int* cmdOrder = new int[cmdOrderSize];

            // Выполняем заказы
            while(countOfCompletableOrders > 0)
            {
                printWithDelay("Введите номер заказа чтобы выполнить его (0 чтобы закончить): ", 25);
                cin >> cmd;

                if (cmd)
                {
                    // Был ли выбран заказ уже до этого
                    bool isAlreadyComplete = 0;

                    for (int k = 0; k < cmdOrderSize; k++)
                    {
                        if (cmd - 1 == cmdOrder[k])
                        {
                            isAlreadyComplete = 1;

                            break;
                        }
                    }

                    if (isAlreadyComplete)
                    {
                        cout << "Этот заказ уже выполнен" << endl;

                        continue;
                    }

                    if (clients[cmd - 1].order.orderType)
                    {
                        if (clients[cmd - 1].order.order > countOfMeat)
                        {
                            cout << "Вы не можете выполнить этот заказ. У Вас слишком мало мяса" << endl;
                        }
                        else
                        {
                            countOfMoney += clients[cmd - 1].order.money;
                            countOfMeat -= clients[cmd - 1].order.order;

                            arrayAddEl(cmdOrder, cmdOrderSize, cmd - 1);
                            countOfCompletableOrders--;
                        }
                    }
                    else
                    {
                        if (clients[cmd - 1].order.order > countOfWool)
                        {
                            cout << "Вы не можете выполнить этот заказ. У Вас слишком мало шерсти" << endl;
                        }
                        else
                        {
                            countOfMoney += clients[cmd - 1].order.money;
                            countOfWool -= clients[cmd - 1].order.order;

                            arrayAddEl(cmdOrder, cmdOrderSize, cmd - 1);
                            countOfCompletableOrders--;
                        }
                    }
                }
                else
                    break;
            }

            // Удаляем выполненные заказы по индексам из массива cmdOrder
            arrayDeleteElsByIndexes(clients, clientsSize, cmdOrder, cmdOrderSize);

            delete[] cmdOrder;
        }

        // Обновляем день
        ToDay.switchDay();

        // Обновляем список заказов
        updateClients(clients, clientsSize);

        // Обновляем данные овец
        updateSheeps(sheeps, sheepsSize);

        // Если овец не осталось, то проигрыш
        if (!sheepsSize)
        {
            gameCode = 1;

            break;
        }

        // Ежедневно списываем от 500 до 1000 (или от 500 до countOfMoney, если
        // баланс меньше 1000) на расходы если баланс не нулевой
        if (countOfMoney > 1000)
            countOfMoney -= __random__(500, 1000);
        else
            countOfMoney = 0;

        // Ежедневно портится от 1 до 3 кг мяса
        // Если мяса меньше 3, то мясо = 0
        if (countOfMeat < 3)
            countOfMeat = 0.0;
        else
            countOfMeat -= __random__(100, 300) / 100.0;

        //Каждый пятый день добавляем овцу и клиента
        if (i && !((i + 1) % 5))
        {
            arrayAddEl(sheeps, sheepsSize, Sheep{});
            arrayAddEl(clients, clientsSize, Client{});
        }
    }

    delete[] sheeps;
    delete[] clients;

    if (!countOfMoney)
        gameCode = 2;

    switch (gameCode)
    {
    case 0:
        system("cls");

        printWithDelay("Поздравляю, ты смог продержаться целый месяц в таких условиях, да ещё и денег подзаработал!", 75);
        printWithDelay("......", 1000);

        system("cls");
        break;
    case 1:
        system("cls");

        printWithDelay("Ты проиграл! В следующий раз запомни, что нужно стричь своих овец", 75);
        printWithDelay("......", 1000);

        system("cls");
        break;
    case 2:
        system("cls");

        printWithDelay("Ты проиграл! Как можно было растерять все свои деньги с такими-то расходами?", 75);
        printWithDelay("......", 1000);

        system("cls");
        break;
    }

    return 0;
}