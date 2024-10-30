#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

using namespace std;

class Map
{
private:
    vector<vector<string>> tiles;
    int width, height;

public:
    Map(int width = 25, int height = 25);

    bool add(const string& component, int xCoord, int yCoord);

    bool remove(int xCoord, int yCoord);

    string getComponent(int xCoord, int yCoord) const;

    void render() const;

    //##
    vector<vector<string>> getComponents();
    int getWidth();
    int getHeight();
};

#endif
