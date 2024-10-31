#include "Map.h"
#include <iostream>
#include <iomanip>

Map::Map(int width, int height) : width(width), height(height) {
    if(this->width < 10){
        this->width = 10;
    }

    if(this->height < 10){
        this->height = 10;
    }
    
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

bool Map::change(string newName, int xCoord, int yCoord){
     if (xCoord >= 0 && xCoord < width && yCoord >= 0 && yCoord < height && newName != "") {
        if (tiles[xCoord][yCoord] != "") {
            tiles[xCoord][yCoord] = newName;
            return true;
        } else {        //if EMPTY
            return false;
        }
    }
    return false;   //out of bounds or the name is EMPTY
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
                cout << "| ";

                if(tiles[i][j].at(0) == 'C'){       //COMMERCIAL BUILDING
                    cout << BLUE;
                }else if (tiles[i][j].at(0) == 'I') //INDUSTRIAL BUILDING
                {
                   cout << RED;
                }else if (tiles[i][j].at(0) == 'R')     //RESIDENTIAL BUILDING
                {
                   cout << BLUE;
                }else if (tiles[i][j].at(0) == 'U') //UTILITY BUILDING    
                {
                   cout << ORANGE;
                }else {
                    cout << RESET; // Reset in case of an unexpected type
                }
                cout << tiles[i][j];    //display object on map
                cout << RESET;      //reset colour back to white or whatever the terminal text color was
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

int Map::getNumComponents(){
    int i = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (tiles[i][j] != "") {
                i++;
            }
        }
    }
    return i;
}
