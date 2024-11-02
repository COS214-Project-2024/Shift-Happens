#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include "../game/Game.h"   // Path to Game class
#include "../game/Display.h"

// Constructor Test
TEST(GameTest, ConstructorTest) {
    Game game;
    EXPECT_EQ(game.getVar(), "");
    EXPECT_EQ(game.getvariantop(), 0);
}

// Setter and Getter Tests for variantop and var
TEST(GameTest, SetAndGetVariantTest) {
    Game game;
    game.setvar("Utility");
    EXPECT_EQ(game.getVar(), "Utility");
}

TEST(GameTest, SetAndGetVariantOpTest) {
    Game game;
    game.setvariantop(3);
    EXPECT_EQ(game.getvariantop(), 3);
}

// MainMenu Tests
TEST(GameTest, MainMenuValidTest) {
    /*Game game;
    std::istringstream input("1\n");  // Simulate choosing "New Game"
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.MainMenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Starting new game..."), std::string::npos)
        << "Expected 'Starting new game...' in output for valid MainMenu input.";*/
}

TEST(GameTest, MainMenuInvalidInputTest) {
  /*  Game game;
    std::istringstream input("5\n3\n");  // Invalid choice, then "3" to exit
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.MainMenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Invalid choice"), std::string::npos)
        << "Expected 'Invalid choice' message in MainMenu.";*/

}

// Testing buldingmenu navigation
TEST(GameTest, BuildingMenuNavigationTest) {
    /*Game game;
    std::istringstream input("5\n");  // Return to main menu option
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.buldingmenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Lets get started with the simulation!"), std::string::npos);*/
}

// UpgradeBuilding with valid input
TEST(GameTest, UpgradeBuildingValidTest) {
  /*  Game game;
    std::istringstream input("3\n");  // Selecting upgrade
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    game.upgradeBuilding();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("You have chosen to upgrade a building."), std::string::npos);*/

}

// Testing invalid entries for display menus
TEST(DisplayTest, InvalidPolicyMenuSelection) {
    Display display;
    std::istringstream input("5\n2\n");  // Invalid entry
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    int policyChoice = display.Policymenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(policyChoice, 5);
    EXPECT_NE(output.find("Invalid entry"), std::string::npos)
        << "Expected 'Invalid entry' message in Policymenu.";
}

TEST(DisplayTest, InvalidTaxMenuSelection) {
    Display display;
    std::istringstream input("6\n3\n");  // Invalid entry 
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    int taxChoice = display.taxMenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(taxChoice, 6);
    EXPECT_NE(output.find("Invalid entry"), std::string::npos)
        << "Expected 'Invalid entry' message in taxMenu.";
}

// Test Display Menus with Valid Input
TEST(DisplayTest, ValidUtilityMenuSelection) {
    Display display;
    std::istringstream input("1\n");  // Select "PowerPlant" in Utility menu
    std::cin.rdbuf(input.rdbuf());

    int choice = display.Utilitymenu();
    EXPECT_EQ(choice, 1);
    EXPECT_EQ(display.getvariant(), "PowerPlant");
}

TEST(DisplayTest, ValidInfrastructureMenuSelection) {
    Display display;
    std::istringstream input("2\n");  // Select "Railway" in Infrastructure menu
    std::cin.rdbuf(input.rdbuf());

    int choice = display.Infrastructuremenu();
    EXPECT_EQ(choice, 2);
    EXPECT_EQ(display.getvariant(), "Railway");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}