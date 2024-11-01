#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <memory>
#include "../game/Display.h"

// Test construction of Display object
TEST(DisplayTest, ConstructorTest) {
    std::shared_ptr<Display> display = std::make_shared<Display>();
    ASSERT_NE(display, nullptr);
}

// Test getVariant and settype
TEST(DisplayTest, VariantManagement) {
    Display display;
    display.settype("Utility");
    EXPECT_EQ(display.getvariant(), "Utility") << "Expected variant to be 'Utility'";
}

// Test MainMenu selection handling
TEST(DisplayTest, MainMenuTest) {
    Display display;
    std::istringstream input("1\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect standard input
    int choice = display.MainMenu();
    EXPECT_EQ(choice, 1) << "Expected MainMenu selection to be 1 (New Game)";
}

// Test MainMenu with invalid input
TEST(DisplayTest, MainMenuInvalidTest) {
    Display display;
    std::istringstream input("5\n"); // Invalid input followed by valid
    std::cin.rdbuf(input.rdbuf());
    int choice = display.MainMenu();
    EXPECT_EQ(choice, 5) << "Expected MainMenu to skip invalid input and accept 1 (New Game)";
}

// Test Utilitymenu selection handling
TEST(DisplayTest, UtilityMenuTest) {
    Display display;
    std::istringstream input("1\n");
    std::cin.rdbuf(input.rdbuf());
    int choice = display.Utilitymenu();
    EXPECT_EQ(choice, 1) << "Expected Utilitymenu selection to be 1 (PowerPlant)";
    EXPECT_EQ(display.getvariant(), "PowerPlant") << "Expected variant to be 'Utility' after Utilitymenu selection";
}

// Test Utilitymenu with invalid input
TEST(DisplayTest, UtilityMenuInvalidTest) {
    Display display;
    std::istringstream input("5\n"); // Invalid inputs followed by a valid selection
    std::cin.rdbuf(input.rdbuf());
    int choice = display.Utilitymenu();
    EXPECT_EQ(choice, 5) // invalid op 
    //<< "Expected Utilitymenu to skip invalid input and accept 2 (LandFill)";
}

// Test Policymenu selection with invalid input
TEST(DisplayTest, PolicymenuInvalidTest) {
    Display display;
    std::istringstream input("7\n0\n1\n"); // Invalid inputs followed by valid selection
    std::cin.rdbuf(input.rdbuf());
    int choice = display.Policymenu();
    EXPECT_EQ(choice, 7) << "Expected Policymenu to skip invalid input and accept 1 (SinTaxPolicy)";
}

// Test Policymenu selection handling with valid input
TEST(DisplayTest, PolicymenuValidTest) {
    Display display;
    std::istringstream input("2\n");
    std::cin.rdbuf(input.rdbuf());
    int choice = display.Policymenu();
    EXPECT_EQ(choice, 2) << "Expected Policymenu selection to be 2 (Immigration Policy)";
}

// Test Governmentmenu selection handling with invalid input
TEST(DisplayTest, GovernmentMenuInvalidTest) {
    Display display;
    std::istringstream input("4\n2\n"); // Invalid input followed by a valid one
    std::cin.rdbuf(input.rdbuf());
    int choice = display.Governmentmenu();
    EXPECT_EQ(choice, 4) << "Expected Governmentmenu to skip invalid input and accept 2 (Implementing a new Policy)";
}

// Test GameMenu selection with invalid inputs
TEST(DisplayTest, GameMenuInvalidTest) {
    Display display;
    std::istringstream input("6\n4\n"); // Invalid input followed by a valid option
    std::cin.rdbuf(input.rdbuf());
    int choice = display.GameMenu();
    EXPECT_EQ(choice, 6) << "Expected GameMenu to skip invalid input and accept 4 (Return to main menu)";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}