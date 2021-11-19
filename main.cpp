#include "battleship.h"

void PrintGrid(string grid[11][11], string gridName){
    cout << gridName << endl;
    char alphaCoord[10] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int row = 0; row <= 10; row++){
        if(row == 0){
            cout << "   ";
        }
        else {
            cout << row << "  ";
        }
        for(int col = 0; col < 10; col++){
            if(row == 0){
                if(col == 10){
                    continue;
                }
                cout << alphaCoord[col]  << "   ";
                continue;
            }
            cout << grid[row][col] << "   ";
        }
        cout<<endl;
    }
}
void checkSquare(string grid[11][11], int x, int y, string type){
    if(grid[x][y] != "~"){
        cout <<"Please re-enter coordiantes for your " <<type << " ship that do not overlap with another ship."<<endl;
        exit(0);
    }
}
int validBounds(string direction, int coordNum, int size, string type, string coordinate){
    if(direction == "VD" && coordNum == 10 ||direction == "VD" && coordNum == 9 && size > 2
       ||direction == "VD" && coordNum == 8 && size > 3 ||direction == "VD" && coordNum == 7 && size > 4 ){
      //  cout << "The " << type << " cannot be placed at "<<coordinate<<" with a direction of " <<direction <<" please re-enter valid coordinates or direction." <<endl;
        return 0;
    }
    if(direction == "VU" && coordNum == 1 ||direction == "VU" && coordNum == 2 && size > 2 ||
       direction == "VU" && coordNum == 3 && size > 3 || direction == "VU" && coordNum == 4 && size > 4 ){
    //    cout << "The " << type << " cannot be placed at "<<coordinate<<" with a direction of " <<direction <<" please re-enter valid coordinates or direction." <<endl;
        return 0;
    }
    if(direction == "HL" && coordinate[0] == 'A' || direction == "HL" && coordinate[0] == 'B' && size > 2 ||
       direction == "HL" && coordinate[0] == 'C' && size > 3  ||  direction == "HL" && coordinate[0] == 'D' && size > 4){
     //   cout << "The " << type << " cannot be placed at "<<coordinate<<" with a direction of " <<direction <<" please re-enter valid coordinates or direction." <<endl;
        return 0;
    }
    if(direction == "HR" && coordinate[0] == 'J' || direction == "HR" && coordinate[0] == 'I' && size > 2 ||
       direction == "HR" && coordinate[0] == 'H' && size > 3  ||  direction == "HR" && coordinate[0] == 'G' && size > 4){
    //    cout << "The " << type << " cannot be placed at "<<coordinate<<" with a direction of " <<direction <<" please re-enter valid coordinates or direction." <<endl;
        return 0;
    }
    if(direction == "none"){
        return 0;
    }
    return 1;
}
void gridSetUp(string grid[11][11], vector<Ship>shipPlacements){
    string coordinate = "none";
    string direction = "none";
    string type = "none";
    int coordNum = -1;
    int size = 0;
    for(int i = 0; i < shipPlacements.size(); i++){
        coordinate = shipPlacements[i].GetShipStartPosition();
        type = shipPlacements[i].GetShipType();
        direction = shipPlacements[i].GetShipDirection();
        size = shipPlacements[i].GetShipSize();
        if(coordinate.size() == 3){
            coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
        }
        else{
            coordNum = coordinate[1]-48;
        }
       if(validBounds(direction, coordNum, size, type, coordinate) == 0) {
           exit(0);
       }
        if(coordinate.size() == 3){
            coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
        }
        else{
            coordNum = coordinate[1]-48;
        }

        if(coordinate[0] == 'A'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-0, type);
                    grid[coordNum][0-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 0+i, type);
                    grid[coordNum][0+i] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 0, type);
                    grid[coordNum+i][0] = type[0];
                }
                continue;
            }
            else{
               cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
        }
        if(coordinate[0] == 'B'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-1, type);
                    grid[coordNum][1-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 1+i, type);
                    grid[coordNum][1+i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 1, type);
                    grid[coordNum-i][1] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 1, type);
                    grid[coordNum+i][1] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'C'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-2, type);
                    grid[coordNum][2-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 2+i, type);
                    grid[coordNum][2+i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 2, type);
                    grid[coordNum-i][2] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 2, type);
                    grid[coordNum+i][2] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'D'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-3, type);
                    grid[coordNum][3-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 3+i, type);
                    grid[coordNum][3+i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 3, type);
                    grid[coordNum-i][3] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 3, type);
                    grid[coordNum+i][3] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'E'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-4, type);
                    grid[coordNum][4-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 4+i, type);
                    grid[coordNum][4+i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 4, type);
                    grid[coordNum-i][4] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 4, type);
                    grid[coordNum+i][4] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'F'){
             if(direction == "HL" ){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-5, type);
                    grid[coordNum][5-i] = type[0];
                }
                continue;
            }
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 5+i, type);
                    grid[coordNum][5+i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 5, type);
                    grid[coordNum-i][5] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 5, type);
                    grid[coordNum+i][5] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'G'){
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-6, type);
                    grid[coordNum][6+i] = type[0];
                }
                continue;
            }
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-6, type);
                    grid[coordNum][6-i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 6, type);
                    grid[coordNum-i][6] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 6, type);
                    grid[coordNum+i][6] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'H'){
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 7+i, type);
                    grid[coordNum][7+i] = type[0];
                }
                continue;
            }
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 7-i, type);
                    grid[coordNum][7-i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 7, type);
                    grid[coordNum-i][7] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 7, type);
                    grid[coordNum+i][7] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'I'){
            if(direction == "HR"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, 8+i, type);
                    grid[coordNum][8+i] = type[0];
                }
                continue;
            }
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-8, type);
                    grid[coordNum][8-i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 8, type);
                    grid[coordNum-i][8] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 8, type);
                    grid[coordNum+i][8] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] == 'J'){
            if(direction == "HL"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum, i-9, type);
                    grid[coordNum][9-i] = type[0];
                }
                continue;
            }
            if(direction == "VU"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum-i, 9, type);
                    grid[coordNum-i][9] = type[0];
                }
                continue;
            }
            if(direction == "VD"){
                for(int i = 0; i < size; i++){
                    checkSquare(grid, coordNum+i, 9, type);
                    grid[coordNum+i][9] = type[0];
                }
                continue;
            }
            else{
                cout << "The direction: " << direction << " is not a correct direction please reset your ship placements correctly." <<endl;
            }
            continue;
        }
        if(coordinate[0] != 'A' && coordinate[0] != 'B' && coordinate[0] != 'C' && coordinate[0] != 'D' && coordinate[0] != 'E'
        && coordinate[0] != 'F' && coordinate[0] != 'G' && coordinate[0] != 'H' && coordinate[0] != 'I' && coordinate[0] != 'J'){
            cout << "The coordinate you entered started with an invalid letter, you will need to reenter your start positions with valid letters."<<endl;
            exit(0);
        }
    }
    PrintGrid(grid, "COMPUTER RANDOM");
}
void HumanPlayerShipInit(BattleFieldGrid& battleGrid){
    fstream inFS;
    string filename;
    string type = "none";
    string startPos = "none";
    string direction = "none";
    vector<Ship> computerShips;
    string line;
    int commaOne = -1;
    int commaTwo = -1;
    int size = 0;

    cout << "Please enter the full name of the csv file: "<<endl;
    getline(cin, filename);
    inFS.open("/Users/zachary/PP/C++2021/CSC2330FinalProject/ship_placement.csv");

    while (!inFS.eof() && inFS.good()) {
        if (!inFS.fail()) {
            getline(inFS, line,'\r');
            commaOne = -1;
            commaTwo = -1;
           int endLine = line.find('\n');
           if(endLine != string::npos){
               line.erase(line.begin()+endLine);
           }
            for(int i = 0; i < line.size(); i++){
                if(line[i] == ','){
                    if(commaOne != -1 && commaTwo!=-1){
                        cout << "Please check to make sure your CSV file is the form {shipType, position, direction}." << endl;
                        exit(EXIT_FAILURE);
                    }
                    if(commaOne == -1){
                        commaOne = i;
                        continue;
                    }
                    if(commaOne != -1 && commaTwo == -1){
                        commaTwo = i;
                        continue;
                    }
                }
            }
            type = line.substr(0, commaOne);
            startPos = line.substr(commaOne+1,2);
            direction = line.substr(commaTwo+1, 2);
            if(type == "Carrier"){
                size = 5;
            }
            if(type == "Battleship"){
                size = 4;
            }
            if(type == "Cruiser"){
                size = 3;
            }
            if(type == "Submarine"){
                size = 3;
            }
            if(type == "Destroyer"){
                size = 2;
            }
            Ship newShip(type, startPos, direction, size);
            computerShips.push_back(newShip);
        }
    }
    if (!inFS.eof()) {
        cout << "Error reading Reviews.txt." << endl;
        exit(EXIT_FAILURE);
    }
    gridSetUp(battleGrid.battleFieldGrid, computerShips);
}
void ComputerPlayerShipInit(string grid[11][11]){
    vector<Ship> computerShipSetUp;
    vector<string> possiblDirections = {"HL", "HR", "VU", "VD"};
    vector<string> takenCoords;
    string coordinate = "none";
    string direction = "none";
    char ranLetter;
    string ranNumber="none";
    int coordNum = -1;
     coordinate = "none";
     direction = "none";

    while(validBounds(direction, coordNum, 5, "Carrier", coordinate)== 0){
        srand((unsigned int)time(NULL));
        ranNumber = to_string(rand() % 10);
        ranLetter = 'A' + rand() % 10;
        coordinate = ranLetter + ranNumber;
        direction = possiblDirections[rand() % 4];
        if(coordinate.size() == 3){
            coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
        }
        else{
            coordNum = coordinate[1]-48;
        }
    }
    takenCoords.push_back(coordinate);
    for(int i = 1; i < 5; i++){
        if(direction == "VU"){
            takenCoords.push_back(coordinate[0]+to_string((coordinate[1]-48-i)));
        }
        if(direction == "VD"){
            takenCoords.push_back(coordinate[0]+to_string((coordinate[1]-48+i)));
        }
        if(direction == "HR"){
            coordinate[0] = static_cast<char>(coordinate[0] + 1);
            takenCoords.push_back( coordinate[0]+ to_string((coordinate[1]-48)));
        }
        if(direction == "HL"){
            coordinate[0] = static_cast<char>(coordinate[0] - 1);
            takenCoords.push_back(coordinate[0] + to_string((coordinate[1]-48-i)));
        }
    }
    Ship carrier("Carrier", coordinate, direction, 5);
    computerShipSetUp.push_back(carrier);

    while(std::find(takenCoords.begin(), takenCoords.end(), coordinate) != takenCoords.end()) {
        direction = "none";
        coordNum = -1;
        while(validBounds(direction, coordNum, 4, "BattleShip", coordinate)!= 1){
            srand((unsigned int)time(NULL));
                ranNumber = to_string(rand() % 10);
                ranLetter = 'A' + rand() % 10;
                coordinate = ranLetter + ranNumber;
                direction = possiblDirections[rand() % 4];
            if(coordinate.size() == 3){
                coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
            }
            else{
                coordNum = coordinate[1]-48;
            }
            }
    }
    takenCoords.push_back(coordinate);
    for(int i = 0; i < 5; i++){
        if(direction == "VU"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48-i)));
        }
        if(direction == "VD"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48+i)));
        }
        if(direction == "HR"){
            takenCoords.push_back(to_string(coordinate[0]++)+to_string((coordinate[1]-48)));
        }
        if(direction == "HL"){
            takenCoords.push_back(to_string(coordinate[0]--)+to_string((coordinate[1]-48-i)));
        }
    }
    Ship battleShip("BattleShip", coordinate, direction, 4);
    computerShipSetUp.push_back(battleShip);


    while(std::find(takenCoords.begin(), takenCoords.end(), coordinate) != takenCoords.end()) {
        direction = "none";
        coordNum = -1;
        while (validBounds(direction, coordNum, 3, "Cruiser", coordinate) != 1) {
            srand((unsigned int)time(NULL));
            ranNumber = to_string(rand() % 10);
            ranLetter = 'A' + rand() % 10;
            coordinate = ranLetter + ranNumber;
            direction = possiblDirections[rand() % 4];
            if(coordinate.size() == 3){
                coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
            }
            else{
                coordNum = coordinate[1]-48;
            }
        }
    }
        takenCoords.push_back(coordinate);
        for(int i = 0; i < 5; i++){
            if(direction == "VU"){
                takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48-i)));
            }
            if(direction == "VD"){
                takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48+i)));
            }
            if(direction == "HR"){
                takenCoords.push_back(to_string(coordinate[0]++)+to_string((coordinate[1]-48)));
            }
            if(direction == "HL"){
                takenCoords.push_back(to_string(coordinate[0]--)+to_string((coordinate[1]-48-i)));
            }
        }
        Ship cruiser("Cruiser", coordinate, direction, 3);
        computerShipSetUp.push_back(cruiser);

    while(std::find(takenCoords.begin(), takenCoords.end(), coordinate) != takenCoords.end()) {
        direction = "none";
        coordNum = -1;
        while (validBounds(direction, coordNum, 3, "Submarine", coordinate) != 1) {
            srand((unsigned int)time(NULL));
            ranNumber = to_string(rand() % 10);
            ranLetter = 'A' + rand() % 10;
            coordinate = ranLetter + ranNumber;
            direction = possiblDirections[rand() % 4];
            if(coordinate.size() == 3){
                coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
            }
            else{
                coordNum = coordinate[1]-48;
            }
        }
    }
    takenCoords.push_back(coordinate);
    for(int i = 0; i < 5; i++){
        if(direction == "VU"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48-i)));
        }
        if(direction == "VD"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48+i)));
        }
        if(direction == "HR"){
            takenCoords.push_back(to_string(coordinate[0]++)+to_string((coordinate[1]-48)));
        }
        if(direction == "HL"){
            takenCoords.push_back(to_string(coordinate[0]--)+to_string((coordinate[1]-48-i)));
        }
    }
    Ship submarine("Submarine", coordinate, direction, 3);
    computerShipSetUp.push_back(submarine);

    while(std::find(takenCoords.begin(), takenCoords.end(), coordinate) != takenCoords.end()) {
        direction = "none";
        coordNum = -1;
        while (validBounds(direction, coordNum, 2, "Destroyer", coordinate) != 1) {
            srand((unsigned int)time(NULL));
            ranNumber = to_string(rand() % 10);
            ranLetter = 'A' + rand() % 10;
            coordinate = ranLetter + ranNumber;
            direction = possiblDirections[rand() % 4];
            if(coordinate.size() == 3){
                coordNum = 10; //subtracting 48 to realign with correct ASCII value when I convert int to char
            }
            else{
                coordNum = coordinate[1]-48;
            }
        }
    }
        takenCoords.push_back(coordinate);
    for(int i = 0; i < 5; i++){
        if(direction == "VU"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48-i)));
        }
        if(direction == "VD"){
            takenCoords.push_back(to_string(coordinate[0])+to_string((coordinate[1]-48+i)));
        }
        if(direction == "HR"){
            takenCoords.push_back(to_string(coordinate[0]++)+to_string((coordinate[1]-48)));
        }
        if(direction == "HL"){
            takenCoords.push_back(to_string(coordinate[0]--)+to_string((coordinate[1]-48-i)));
        }
    }
        Ship destroyer("Destroyer", coordinate, direction, 2);
        computerShipSetUp.push_back(destroyer);
        gridSetUp(grid, computerShipSetUp);
}



void GamePlay(string humanBattleGrid[11][11],string humanFiringGrid[11][11], string computerBattleField[11][11], string computerFiringGrid[11][11])
{
    int randNum = rand() % 100000;
    string coordinate;
    bool winner = false;
    string computerCoordinate;
    if(randNum % 2 == 0) {
        cout << "Human player enter coordinates to fire at: " << endl;
        getline(cin, coordinate);
    }
    else{
        //get random computer coordinates.
    }
        while(winner  == false){
            cout << "Human player enter coordinates to fire at: " << endl;
            getline(cin, coordinate);
//            if(computerFiringGrid == )
//            cout << "Computer selected: " << computerCoordinate;
        }
}
int main() {
    //Creates and instantiates all Grids with coord system
    FiringGrid humanFiringGrid;
    FiringGrid computerFiringGrid;
    BattleFieldGrid humanBattleFieldGrid;
    BattleFieldGrid computerBattleFieldGrid;
   // PrintGrid(humanBattleFieldGrid.battleFieldGrid, "Human Battle Grid");
  //  HumanPlayerShipInit(humanBattleFieldGrid);
    ComputerPlayerShipInit(computerBattleFieldGrid.battleFieldGrid);
    //PrintGrid(humanBattleFieldGrid.battleFieldGrid, "Computer Battle Grid");
   // GamePlay(humanBattleFieldGrid.battleFieldGrid, humanFiringGrid.firingGrid, computerBattleFieldGrid.battleFieldGrid, computerFiringGrid.firingGrid);
}
