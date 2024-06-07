#include "Position.h"
#include "World.h"
#include "Sheep.h"
#include "Grass.h"
#include "Wolf.h"
#include "Dandelion.h"
#include "Toadstool.h"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "Game Menu:\n";
    std::cout << "1. Make a turn\n";
    std::cout << "2. Show organisms data\n";
    std::cout << "3. Exit\n";
}

int main() {
    World world(10, 10); // Creating a world with dimensions 10x10
    Position pos1(0, 0);
    Position pos2(9, 9);
    Position pos3(9, 0);
    Position pos4(4, 4);
    Position pos5(0, 9);

    Sheep sheep(pos1, 0);
    Grass grass(pos3, 0);
    Toadstool fung(pos4, 0);
    Wolf wolf(pos2, 0);
    Dandelion dande(pos5, 0);

    world.addOrganism(&sheep);
    world.addOrganism(&grass);
    world.addOrganism(&fung);
    world.addOrganism(&wolf);
    world.addOrganism(&dande);

    bool exitGame = false;
    std::cout << "World after turn:\n" << world.toString() << std::endl;

    while (!exitGame) {  
        printMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            world.makeTurn(); // Make a turn
            std::cout << "Turn made.\n";
            std::cout << "World after turn:\n" << world.toString() << std::endl;
            break;
        case 2:
            world.printOrganismsInfo();
            break;
        case 3:
            exitGame = true; // Exit game
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}