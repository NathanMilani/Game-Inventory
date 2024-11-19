// Program 3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "GameInventory.h"

int main()
{
    GameInventory inventory(6);
    ItemType game1("IT1___WW", "Wild Walker");
    ItemType game2("IT5___SV", "Stardew Valley");
    ItemType game3("IT2_Pkmn", "Pikmin");
    ItemType game4("IT4___ER", "Elden Ring");
    ItemType game5("IT3__Ftn", "Fortnite");


    cout << "\033[32mAdding the items to the list\n\033[0m";

    inventory.PutItem(game1);
    inventory.PutItem(game2);
    inventory.PutItem(game3);
    inventory.PutItem(game4);
    inventory.PutItem(game5);
    inventory.PutItem(game5);



    inventory.PrintList();

    cout << "\n\n\033[32mGetItem(item4)\n\033[0m";
    bool found = true;
    inventory.GetItem(game4, found);

    cout << "\n\n\033[32mDelete item\n\033[0m";
    inventory.DeleteItem(game4);

    cout << "\n\n\033[32mUpdated list after Deletion:\033[0m";
    inventory.PrintList();

    return 0;
}


