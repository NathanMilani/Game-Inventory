#pragma once
// GameInventory.h : This file contains GameInventory code Declorations
// Class assignment for Program 3
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022
#include "ItemType.h"

using namespace std;

class GameInventory
{
private:
	int maxCapacity = 0;
	ItemType* items = NULL;
	int length = 0;
	int curPos = 0;
	
	int BinarySearch(ItemType target, int low, int high);
public:
	GameInventory();
	GameInventory(int maxCapacity);
	GameInventory(GameInventory& copy);
	~GameInventory();

	bool PutItem(ItemType item);
	ItemType GetItem(ItemType target, bool& found);
	bool DeleteItem(ItemType target);
	void ResetList();
	void MakeEmpty();
	void PrintList();
	ItemType GetNext();
	int GetLength();
	bool IsFull();
};


