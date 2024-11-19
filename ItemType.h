// ItemType.h : This file contains ItemType code Declorations
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022
#pragma once
#include <iostream>
#include <string>
using namespace std;

class ItemType
{
private:

	string sku = "";
	string gameTitle = "";

public:

	ItemType();
	ItemType(string storeSku, string title);
	~ItemType();

	bool operator<(ItemType& less);
	bool operator>(ItemType& greater);
	bool operator==(ItemType& equal);
	string GetData();
	string GetData(string& skuVal);
	void SetData(string setSku, string setGametitle);
	void PrintInfo();
};


