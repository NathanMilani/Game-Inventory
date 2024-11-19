// GameInventory.cpp : This file contains GameInventory code Implementation
// Class assignment for Program 3
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "GameInventory.h"

GameInventory::GameInventory()
{
    maxCapacity = 10;
    length = 0;
    curPos = 0;
    items = new ItemType[maxCapacity];
    cout << "2024 CS220-00\n";
}

GameInventory::GameInventory(int Capacity)
{
    maxCapacity = Capacity;
    length = 0;
    curPos = 0;
    items = new ItemType[maxCapacity];
    cout << "Welcome to World Champions of Gaming, our CEO Nathan Milani is the crazy about coding!\n\n";
}

GameInventory::GameInventory(GameInventory& copy)
{
    if (copy.maxCapacity <= 0)
    {
        maxCapacity = 0;
    }
    else
    {
        maxCapacity = copy.maxCapacity;
        length = copy.length;
        curPos = copy.curPos;
        items = new ItemType[maxCapacity];
        std::copy(copy.items, copy.items + length, items);
    }
}

GameInventory::~GameInventory()
{
    delete[] items;
}

bool GameInventory::PutItem(ItemType item)
{
    bool added = false;  // Flag to track if the item was successfully added
    bool found = false;  // Flag to track if the item already exists in the inventory
    ItemType existingItem = GetItem(item, found);  // Check if the item already exists

    if (!found)  // If the item does not exist, add it
    {
        int index = 0;  // Initialize the index to start searching through the list

        // Find the correct position for the new item (to maintain sorted order)
        while (index < length && items[index] < item)
        {
            index++;  // Increment index until the correct position is found
        }

        // Check if there is space to add the item
        if (!IsFull())
        {
            // Shift all items to the right to make space for the new item
            for (int shift = length; shift > index; shift--)
            {
                items[shift] = items[shift - 1];  // Shift each item one position to the right
            }

            // Insert the new item at the correct index and update the list's length
            items[index] = item;
            length++;
            added = true;

            // Output the details of the added item (SKU and title)
            string title = "";
            item.GetData(title);  // Get the title of the item
            cout << "\nAdded: at pos " << index << ": SKU: " << item.GetData()  // Print position and SKU
                << ", title: " << title;
                 
        }
    }
    else
    {
        string title = "";
        item.GetData(title);  // Get the title of the item
        cout << "\nTitle: " << title << " Item already present;\n";  // Output a message if the item already exists in the list
    }

    return added;  // Return whether the item was added successfully
}


ItemType GameInventory::GetItem(ItemType target, bool& found)
{
    // Perform a binary search to find the target item
    int binaryIndex = BinarySearch(target, 0, length - 1);
    ItemType result;

    // Check if the item was found
    if (binaryIndex != -1)
    {
        found = true;  // Item found
        result = items[binaryIndex];  // Retrieve the found item
        //cout << "\nFound SKU: " << target.GetData() << " at position " << binaryIndex << "\n";
    }
    else
    {
        found = false;  // Item not found
        result = ItemType();  // Return a default ItemType object
    }

    return result;  // Return the found item or default object
}

int GameInventory::BinarySearch(ItemType target, int low, int high)
{
    // Base case: If the low index exceeds high, the item is not found
    if (low > high)
    {
        return -1;
    }

    cout << " search pos " << low << " to " << high << "; ";  // Output current search range
    int mid = (low + high) / 2;  // Calculate the middle index

    // Check if the middle item is the target
    if (items[mid] == target)
    {
        return mid;  // Return the index of the found item
    }
    else if (items[mid] < target)
    {
        // Recur on the right half
        return BinarySearch(target, mid + 1, high);
    }
    else
    {
        // Recur on the left half
        return BinarySearch(target, low, mid - 1);
    }
}

bool GameInventory::DeleteItem(ItemType item)
{
    bool found = false;  // Flag to track if the item was found for deletion
    int binary = BinarySearch(item, 0, length - 1);  // Perform binary search for the item

    // If the item is found
    if (binary != -1)
    {
        found = true;  // Item was found
        // Shift items to the left to remove the found item
        for (int index = binary; index < length - 1; index++)
        {
            items[index] = items[index + 1];  // Shift each item one position to the left
        }

        length--;  // Decrease the length of the inventory
        string title;
        item.GetData(title);  // Get the title of the deleted item
        cout << "\nDeleted: " << title << " at pos: " << binary << "\n";  // Output the deletion info
    }

    return found;  // Return whether the item was found and deleted
}

void GameInventory::ResetList()
{
    curPos = 0;  // Reset the current position for item iteration
}

void GameInventory::MakeEmpty()
{
    delete[] items;  // Free the existing items array
    items = new ItemType[maxCapacity];  // Allocate a new array of ItemType
    length = 0;  // Reset the length to zero
    ResetList();  // Reset the current position
}

void GameInventory::PrintList()
{
    if (length == 0)
    {
        cout << "Nothing to print\n";  // Output if the inventory is empty
    }
    else
    {
        cout << "\n\nPrint List:\n";  // Header for printing the list
        // Iterate through the inventory and print each item's details
        for (int index = 0; index < length; ++index)
        {
            string title;
            items[index].GetData(title);  // Get the title of the item
            cout << "SKU: " << items[index].GetData() << ", title: " << title << "\n";  // Print SKU and title
        }
        cout << "List length = " << length << "\n";  // Print the current length of the inventory
    }
}

ItemType GameInventory::GetNext()
{
    ItemType result;

    // Check if the current position is within the length of the inventory
    if (curPos < length)
    {
        result = items[curPos];  // Retrieve the item at the current position
        curPos++;  // Move to the next position for the next call
    }
    else
    {
        result = ItemType();  // Return a default ItemType object if at end of the list
    }

    return result;  // Return the retrieved item or default object
}

int GameInventory::GetLength()
{
    return length;  // Return the current length of the inventory
}

bool GameInventory::IsFull()
{
    return length == maxCapacity;  // Check if the inventory is full
}
