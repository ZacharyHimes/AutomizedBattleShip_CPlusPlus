#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include<stdlib.h>
#include <map>

using namespace std;

class BattleFieldGrid{
    public:
        string battleFieldGrid[11][11];
        BattleFieldGrid();
        void SetBattleFieldGrid();
        string GetBattleFieldGrid();
};

class FiringGrid{
public:
    string firingGrid[11][11];
    FiringGrid();
    void SetFiringGrid();
    FiringGrid GetFiringGrid();
};

class Ship{
    private:
        string shipType = "none";
        string shipStartPosition = "none";
        string shipDirection = "none";
        int shipSize = -1;
        bool sunk = false;
    public:
        Ship(string, string, string, int);
        string GetShipType();
        string GetShipStartPosition();
        string GetShipDirection();
        int GetShipSize();
};