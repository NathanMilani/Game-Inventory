// ItemType.cpp : This file contains ItemType code Implementation
// Class assignment for Program 3
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "ItemType.h"

ItemType::ItemType()
{
	sku = "A000";
	gameTitle = "Space Invaders";
}

ItemType::ItemType(string newSku, string newtitle)
{
	sku = newSku;
	gameTitle = newtitle;
}

ItemType::~ItemType()
{

}

bool ItemType::operator<(ItemType& less)
{
    bool result = false;  // Initialize the result flag to false
    // Compare the SKU of the current object with another ItemType object
    if (sku < less.sku)
    {
        result = true;  // Set result to true if current SKU is less
    }
    return result;  // Return the comparison result
}

bool ItemType::operator>(ItemType& greater)
{
    bool result = false;  // Initialize the result flag to false
    // Compare the SKU of the current object with another ItemType object
    if (sku > greater.sku)
    {
        result = true;  // Set result to true if current SKU is greater
    }
    return result;  // Return the comparison result
}

bool ItemType::operator==(ItemType& equal)
{
    bool result = false;  // Initialize the result flag to false
    // Check if the SKU of the current object is equal to another ItemType object
    if (sku == equal.sku)
    {
        result = true;  // Set result to true if the SKUs are equal
    }
    return result;  // Return the comparison result
}

string ItemType::GetData()
{
    return sku;  // Return the SKU of the item
}

string ItemType::GetData(string& printTitle)
{
    printTitle = gameTitle;  // Set the title reference to the game's title
    return sku;  // Return the SKU of the item
}

void ItemType::SetData(string setSku, string setGametitle)
{
    sku = setSku;  // Set the SKU of the item
    gameTitle = setGametitle;  // Set the title of the game
}

void ItemType::PrintInfo()
{
    // Output the SKU and title of the item
    cout << "SKU: " << sku << ", Title: " << gameTitle;
}
