/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <windows.h>
#include <limits>

using namespace std;

int main()
{
	// todo -> better way for utf8?
	SetConsoleOutputCP(CP_UTF8);

	string userCommand;
	vector<string> parameters;

	// list all files in current directory
	system("dir");

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	std::cout << "Welcome to the Takeaway Ordering System! Type `help` to start!" << std::endl;

	while (userCommand != "exit")
	{

		std::cout << "\n" << "Enter a command: ";

		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];
		parameters.erase(parameters.begin());

		if (command == "menu")
		{

			cout << "1. Display menu\n2. Sort menu by price (ascending)\n3. Sort menu by price (descending)\n";
			int option;

			try
			{
				cin >> option;
			}
			catch (const std::invalid_argument& e)
			{
				cout << "Invalid option. Returning to main menu!\n";
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

			switch (option)
			{
			case 1:
				// do nothing - Executed below, just for intuitiveness for the user.
				break;
			case 2:
				menu.sortByPrice(true);
				cout << "Menu sorted by price in ascending order:\n" << menu.toString();
				break;
			case 3:
				menu.sortByPrice(false);
				cout << "Menu sorted by price in descending order:\n" << menu.toString();
				break;
			default:
				cout << "Invalid option. Returning to main menu!\n";
				break;  // Repeat the loop for a valid option
			}

			cout << menu.toString() << endl;

		}
		else if (command == "add")
		{

			if (parameters.empty())
			{
				cout << "Invalid Arguments! please use add <number> to add to your order!" << endl;
				cout << "Example: add 1 5 9" << endl;
				continue;
			}

			for (const string& parameter : parameters)
			{

				int position;
				try
				{
					position = stoi(parameter);
				}
				catch (const std::invalid_argument& e)
				{
					cout << parameter << " is not a valid number! Skipping...\n";
					continue;
				}

				Item* choice = menu.getItem(position);

				if (choice == nullptr)
				{
					cout << "Invalid Item! Please choose a valid item from the menu!" << endl;
					continue;
				}

				std::cout << "Adding " << choice->getName() << " to order." << std::endl;
				order.add(choice);
			}

		}
		else if (command == "remove")
		{

			if (parameters.empty())
			{
				cout << "Invalid Arguments! please use remove <number> to remove to your order!" << endl;
				cout << "Example: remove 1 5 9" << endl;
				continue;
			}

			for (const string& parameter : parameters)
			{

				int position;
				try
				{
					position = stoi(parameter);
				}
				catch (const std::invalid_argument& e)
				{
					cout << parameter << " is not a valid number! Skipping...\n";
					continue;
				}

				Item* choice = order.getItem(position);

				if (choice == nullptr)
				{
					cout << "Invalid Item! Please choose a valid item from the order!" << endl;
					continue;
				}

				std::cout << "Removing " << choice->getName() << " from order." << std::endl;
				order.remove(position);
			}

		}
		else if (command == "checkout")
		{

			std::cout << order.toString() << std::endl;

			char response;
			std::cout << "Do you want to place your order? Type 'y' to confirm, or 'n' to modify: ";
			std::cin >> response;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

			if (response == 'y' || response == 'Y')
			{
				std::cout << "\nPrinting Receipt to receipt.txt!" << std::endl;
				order.printReceipt();
			}
			else if (response == 'n' || response == 'N')
			{
				std::cout << "\nReturning to menu!" << std::endl;
			}

		}
		else if (command == "order")
		{
			std::cout << order.toString() << std::endl;
		}
		else if (command == "help")
		{
			cout << "The available commands are:" << "\n" <<
				 "menu - Displays the Takeaway Menu." << "\n" <<
				 "add <index> - Adds an Item to the Order." << "\n" <<
				 "remove <index> - Removes an Item from the Order." << "\n" <<
				 "checkout - Displays your Total Order and prints a receipt." << "\n" <<
				 "order - Displays your current Order." << "\n" <<
				 "help - Opens this menu." << "\n" <<
				 "exit - Leave the program." << endl;
		}
		else if (command == "exit")
		{
			// prevention of unknown command error
		}
		else
		{
			cout << "Unknown command. Type 'help' for a list of available commands." << endl;
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}