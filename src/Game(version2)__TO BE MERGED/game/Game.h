#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
    Game();
    void handleEvent(const sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture groundTexture;
    sf::Sprite groundSprite;
    std::vector<sf::Sprite> buildings;  // To hold placed building sprites
    sf::Texture buildingTexture;         // Texture for the building
};

#endif // GAME_H
