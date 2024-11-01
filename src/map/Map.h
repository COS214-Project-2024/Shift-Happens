#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
//########################
// Define color codes
//########################
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;5;208m"
#define CYAN "\033[36m"



using namespace std;

class Map
{
private:
    vector<vector<string>> tiles;   //components
    int width, height;

public:
    Map(int width, int height);

    bool add(const string& component, int xCoord, int yCoord);

    bool remove(int xCoord, int yCoord);

    bool change(string newName, int xCoord, int yCoord);

    string getComponent(int xCoord, int yCoord) const;

    void render() const;

    //##
    vector<vector<string>> getComponents(); //return the tiles/components in map
    vector<pair<string,string>> upgraded_tiles;  //upgraded components
    int getWidth();
    int getHeight();
    int getNumComponents();
};

#endif
