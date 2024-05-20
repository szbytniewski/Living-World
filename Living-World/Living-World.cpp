#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "Game Menu:\n";
    std::cout << "1. Make a turn\n";
    std::cout << "2. Save game\n";
    std::cout << "3. Load last saved game\n";
    std::cout << "4. Show organisms data\n";
    std::cout << "5. Exit\n";
}

int main() {
    World world(10, 10); // Creating a world with dimensions 10x10
    Organism organism(3, 2, { 1,1 });
    Plant plant(3,2,{ 0,0 });
    Animal animal(3, 2, { 8,8 });

    world.addOrganism(&organism);
    world.addOrganism(&plant);
    world.addOrganism(&animal);
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
            world.writeWorld("saved_game.bin"); // Save game
            std::cout << "Game saved.\n";
            break;
        case 3:
            world.readWorld("saved_game.bin"); // Load last saved game
            std::cout << "Last saved game loaded.\n";
            std::cout << "World:\n" << world.toString() << std::endl;
            break;
        case 4:
            world.printOrganismsInfo();
            break;
        case 5:
            exitGame = true; // Exit game
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}