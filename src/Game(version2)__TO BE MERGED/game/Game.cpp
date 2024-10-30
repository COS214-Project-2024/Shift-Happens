#include "Game.h"

Game::Game() {
    // Load the ground texture
    if (!groundTexture.loadFromFile("../assets/ground.png")) {
        throw std::runtime_error("Failed to load ground texture from ../assets/ground.png");
    }
    groundSprite.setTexture(groundTexture);
    
    // Load the building texture
    if (!buildingTexture.loadFromFile("../assets/apartment.png")) {
        throw std::runtime_error("Failed to load building texture from ../assets/apartment.png");
    }
}

void Game::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Create a new building sprite and place it where the mouse was clicked
            sf::Sprite buildingSprite;
            buildingSprite.setTexture(buildingTexture);
            buildingSprite.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            buildings.push_back(buildingSprite);
        }
    }
}

void Game::update() {
    // Update game logic here (if needed)
}

void Game::draw(sf::RenderWindow& window) {
    // Draw the ground sprite
    window.draw(groundSprite);
    
    // Draw all placed buildings
    for (const auto& building : buildings) {
        window.draw(building);
    }
}
