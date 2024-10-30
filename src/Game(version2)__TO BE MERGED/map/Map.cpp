#include "Map.h"
#include <iostream>
#include <iomanip>

Map::Map(int width, int height) : width(width), height(height) {
    tiles = vector<vector<string>>(width, vector<string>(height, ""));
}

bool Map::add(const string& component, int xCoord, int yCoord) {
    if (xCoord >= 0 && xCoord < width && yCoord >= 0 && yCoord < height) {
        if (tiles[xCoord][yCoord] == "") {
            tiles[xCoord][yCoord] = component;
            return true;
        } else {
            cout << "Tile is occupied at (" << xCoord << ", " << yCoord << ").\n";
        }
    } else {
        cout << "Coordinates are out of bounds.\n";
    }
    return false;
}

bool Map::remove(int xCoord, int yCoord) {
    if (xCoord >= 0 && xCoord < width && yCoord >= 0 && yCoord < height) {
        if (tiles[xCoord][yCoord] != "") {
            tiles[xCoord][yCoord] = "";
            return true;
        } else {
            cout << "No component at (" << xCoord << ", " << yCoord << ") to remove.\n";
        }
    } else {
        cout << "Coordinates are out of bounds.\n";
    }
    return false;
}

string Map::getComponent(int xCoord, int yCoord) const {
    if (xCoord >= 0 && xCoord < width && yCoord >= 0 && yCoord < height) {
        return tiles[xCoord][yCoord];
    }
    return "";
}

void Map::render() const {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (tiles[i][j] == "") {
                cout << "| X ";
            } else {
                cout << "| " << tiles[i][j];
            }
        }
        cout << "|\n";
    }
}

vector<vector<string>> Map::getComponents(){
    return tiles;
}

int Map::getWidth(){
    return this->width;
}

int Map::getHeight(){
    return this->height;
}