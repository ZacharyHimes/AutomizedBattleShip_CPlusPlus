#include "battleship.h"


 BattleFieldGrid::BattleFieldGrid() {
    for(int row = 0; row < 11; row++){
        for(int col = 0; col < 11; col++){
            battleFieldGrid[row][col] = "~";
        }
    }
 }

FiringGrid::FiringGrid(){
    for (int row = 0; row < 11; row++){
        for(int col = 0; col < 11; col++){
            firingGrid[row][col] = '~';
        }
    }
}
Ship::Ship(string type, string position, string direction, int size){
    shipType = type;
    shipStartPosition = position;
    shipDirection = direction;
    shipSize = size;
}
string Ship::GetShipType(){
    return shipType;
}
int Ship::GetShipSize(){
    return shipSize;
}
string Ship::GetShipStartPosition(){
    return shipStartPosition;
}
string Ship::GetShipDirection(){
    return shipDirection;
}