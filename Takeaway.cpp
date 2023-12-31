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

using namespace std;

int main() {
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

    while (userCommand != "exit") {

        std::cout << "\n" << "Enter a command: ";

        getline(cin, userCommand);
        char *cstr = new char[userCommand.length() + 1];
        strcpy(cstr, userCommand.c_str());

        char *token;
        token = strtok(cstr, " ");

        while (token != NULL) {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        string command = parameters[0];
        parameters.erase(parameters.begin());

        if (command.compare("menu") == 0) {
            cout << menu.toString();
        } else if (command.compare("add") == 0) {

            // find out how many items have been listed in the arguments and add them to the order
            // e.g. add 1 5 9

            // todo --> add in something where if no parameters don't add anything and show an error

            for (const string &parameter: parameters) {
                Item *choice = menu.getItem(stoi(parameter));
                std::cout << "Adding " << choice->getName() << " to order." << std::endl;
                order.add(choice);
            }

        } else if (command.compare("remove") == 0) {

            // todo --> add in something where if no parameters don't remove anything and show an error

            for (const string &parameter: parameters) {
                int position = stoi(parameter);
                Item *choice = menu.getItem(position);
                std::cout << "Removing " << choice->getName() << " from order." << std::endl;
                order.remove(position);
            }

        } else if (command.compare("checkout") == 0) {

            std::cout << order.toString() << std::endl;
            std::cout << "\n" << "Printing Receipt to receipt.txt!" << std::endl;
            // make it so they can choose to print or if they don't want to print it doesn't print
            order.printReceipt();

        } else if (command.compare("help") == 0) {
            cout << "The available commands are:" << "\n" <<
                    "menu - Displays the Takeaway Menu." << "\n" <<
                    "add [INDEX] - Adds an Item to the Order." << "\n" <<
                    "remove [INDEX] - Removes an Item from the Order." << "\n" <<
                    "checkout - Displays your Total Order and prints a receipt." << "\n" <<
                    "help - Opens this menu." << "\n" <<
                    "exit - Leave the program." << endl;
        } else {
            cout << "Unknown command. Type 'help' for a list of available commands." << endl;
        }

        parameters.clear();

    }

    cout << "Press any key to quit...";
    std::getchar();

}