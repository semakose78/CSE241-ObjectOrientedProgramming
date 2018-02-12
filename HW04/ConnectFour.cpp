//sema köse
//141044002
//HW04

#include "ConnectFour.h"
using namespace std;


/*Cell operator++();
        Cell operator++(int);
        Cell operator--();
        Cell operator--(int);*/

int ConnectFour::numberOfLivingCells = 0;
int ConnectFour::loaded = 0;

bool ConnectFour::Cell::operator==(const Cell& other)const {
    if((getColumn()==other.getColumn())
       && (getRow()==other.getRow())
       && (getSituation() == other.getSituation()))
        return true;
    else
        return false;
}



inline void ConnectFour::Cell::setColumn(int column) {
    Cell::column = column;
}

inline void ConnectFour::Cell::setRow(int row) {
    Cell::row = row;
}

inline void ConnectFour::Cell::setSituation(int st) {
    situation = st;
}

void ConnectFour::setWidth(int width) {
    ConnectFour::width = width;
}

void ConnectFour::setHeight(int height) {
    ConnectFour::height = height;
}

ConnectFour::Cell::Cell(int st){
    situation = st;
}
ConnectFour::Cell::Cell(char col, int row){
    setColumn(col);
    setRow(row);
}
ConnectFour::Cell::Cell(){
    setColumn(0);
    setRow(0);
};
ConnectFour::ConnectFour() {
    setWidth(5);
    setHeight(5);

    gameBoard = new Cell*[width];
    for (int i = 0; i < width; ++i)
        gameBoard[i] = new Cell[width];

}

ConnectFour::ConnectFour(int w, int h) {
    setWidth(w);
    setHeight(h);

    gameBoard = new Cell*[height];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[width];
}

ConnectFour::ConnectFour(const string filename) {
    ifstream in;
    char ch;
    int row=0, column=0;
    height = 0;
    in.open(filename);
    if(in){
        in.get(ch);
        do{
            width = 0;
            while (ch != '\n') {
                ++width;
                in.get(ch);
            }
            in.get(ch);
            ++height;

        }while(!in.eof());
    }
    in.close();

    gameBoard = new Cell*[height];
    for(int i=0; i<height; ++i)
        gameBoard[i] = new Cell[width];

    //displayBoard();

    in.open(filename);
    if(in){
        in.get(ch);
        do{
            column = 0;
            while (ch != '\n') {
                if(ch=='*')
                    gameBoard[row][column].setSituation(0);
                if(ch==' ')
                    gameBoard[row][column].setSituation(3);
                ++column;
                in.get(ch);
            }
            in.get(ch);
            ++row;

        }while(!in.eof());
    }
    in.close();
}

void ConnectFour::setSingleOrMulti() {
    //cout<<"Oyun modu seçiniz: ";
    cin>>singleOrMulti;
    //cout<<endl;
    while((singleOrMulti != 'M') && (singleOrMulti != 'S')){
        //cerr<<"Oyun modu geçerli değil!"<<endl; //if the input is not valid, ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        //cout<<"Oyun modu seçiniz: ";
        cin>>singleOrMulti;
        cout<<endl;
    }
}

void ConnectFour::setFileName(){
    cin>>fileNameBoard;
}

int ConnectFour::setTheBoardSize(){ // gets the board size from user

    cout << "En giriniz: ";
    cin >> width;
    cout<<endl;

    while(width<4){
        cerr<<"En değeri geçerli değil!"<<endl; //if the input is not valid, ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "En giriniz: ";
        cin >> width;
        cout<<endl;
    }

    cout << "Boy giriniz: ";
    cin >> height;
    cout<<endl;

    while(height<4){
        cerr<<"Boy değeri geçerli değil!"<<endl; //if the input is not valid, ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Boy giriniz: ";
        cin >> height;
        cout<<endl;
    }
    return 0;
}

void ConnectFour::setTheGamingMode(){ // gets the gaming mode (player vs player or computer vs player) from user

    char modeAsChar = '\0';
    //cout << "player | computer: ";
    cin >> modeAsChar;
    //cout<<endl;

    if(modeAsChar == 'P')
        playerOrComputer = 1;
    else if(modeAsChar == 'C')
        playerOrComputer = 2;
    else{
        //cerr << "Lütfen geçerli bir mod seçiniz" << endl; //if input is not valid ask again recursively
        cin.clear();
        cin.ignore(1000, '\n');
        setTheGamingMode();
    }
}

void ConnectFour::fillTheBoardWithZeros(){ // initializes the board with '.'
    for(int i = 0; i<getHeight(); i++){
        for(int j = 0; j< getWidth(); j++){
            gameBoard[i][j].setSituation(0);
        }
    }
}

void ConnectFour::displayBoard() {
    int t = 1;
    if(loaded == 1)
        loaded = 0;
    for(int k=65; k<(65+width); k++) //print the column letters first
        cout<<(char)k;
    cout<<endl;
    for(int i = 0; i< height; i++){
        //if(t<10)
        //    cout<<t<<' ';
        //else
        //    cout<<t;
        for(int j = 0; j< width; j++){
            if(gameBoard[i][j].getSituation() == 0)
                cout << ".";
            else if(gameBoard[i][j].getSituation() == 1)
                cout << "x";
            if(gameBoard[i][j].getSituation() == 2)
                cout << "o";
            if(gameBoard[i][j].getSituation() == 3)
                cout << " ";
        }
        cout<<endl;
        ++t;
    }
    cout<<endl;
}

void ConnectFour::createTheBoard(){ //creates the board with given nxn size using malloc

    //if(loaded==1)
    //   cout<<"The board size is : "<<width<<endl;
    gameBoard = new Cell*[height];
    for (int i = 0; i < height; ++i)
        gameBoard[i] = new Cell[width];
}

string ConnectFour::getColumnHelper(string player, int* inputType){ // gets the column from user

    string input = "\0";
    char column = '\0';

    //cout << player <<": ";
    cin >> input;
    //cout<< "last : "<<input;
    if(!input.empty()){
        if(!checkIfItsAFileCommand(input)){
        *inputType = 0;
        column = input[0];
        if(((int)column)<65 || (((int)column)>(64+getWidth()) && ((int)column)<97) //check if the move is valid
           || ((int)column)>(96+getWidth())){

            //cerr << "Hamle geçerli değil!" <<endl;
            //exit(1);
            cin.clear();
            cin.ignore(1000, '\n');
            getColumnHelper(player, inputType);
        }
        return input; // return column as letter
        }
        else{
            *inputType = 1;
            return input;
        }
    }else
        exit(0);
    
}


int ConnectFour::getRowHelper(char column){ // finds an empty row in a column
    int row = 0;
    int i = 0;
    for(i=(height-1); i>=0; --i){
        if((int)(column)<97){
            if(gameBoard[i][(int)(column-65)].getSituation() == 0)
                    break;
        }
        else if((int)(column)>=97){
            if(gameBoard[i][(int)(column-97)].getSituation() == 0)
                    break;
        }
    }
    row = i;
    return row; // return the row for move
}

void ConnectFour::getInputFromPlayer(string player, string& input, char* column, int* row){ //gets the column as an input and finds an empty row in that column
    int inputType = 0;
    input = getColumnHelper(player, &inputType); //get the column
    //cout<<input<<endl;
    if(inputType == 0){
        *column = input[0];
        *row = getRowHelper(*column); //calculate the row
        if(*row<0){
            cout<<endl<<"There is no room for that move in this column!"<<endl; //check if there is any cells for move
            getInputFromPlayer(player, input, column, row);
        }
    }
    else{
        //cout<<"here"<<endl;
        fileOperations(input);
    }
}

ConnectFour ConnectFour::fileOperations(const string& input){

    string filename;
    cin >> filename;
    ConnectFour newGame;

    if(input.compare("SAVE")==0){
        //cout<<"save file detected"<<endl
        writeTo(filename);
    }
    else if(input.compare("LOAD")==0){
        //cout<<"load file detected"<<endl;
        loaded = 1;
        readFrom(filename);

    }
    return newGame;
}

bool ConnectFour::checkIfItsAFileCommand(const string command){

    //cout<<command<<endl;

    if(command == "LOAD" || command == "SAVE")
        return true;
    else
        return false;
}

void ConnectFour::writeTo(const string& filename){
    ofstream outFile;
    outFile.open(filename);
    if(outFile){
        outFile << singleOrMulti << endl;
        outFile << height << endl;
        outFile << width << endl;
        outFile << playerOrComputer << endl;
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                outFile << gameBoard[i][j].getSituation();
            }
            outFile << endl;
        }
    }else{
        cerr<<"File couldn't opened for SAVE"<<endl;
    }
    outFile.close();
}

void ConnectFour::readFrom(const string& filename){
    ifstream inFile;
    string temp;
    int st = 0;
    char ch;

    inFile.open(filename);
    if(inFile){
        inFile >> singleOrMulti;
        inFile >> height;
        inFile >> width;
        inFile >> playerOrComputer;
        createTheBoard();
        if(playerOrComputer==1)
            cout<<"The gaming mode is Player vs Player"<<endl;
        else if(playerOrComputer==2)
            cout<<"The gaming mode is Player vs Computer"<<endl;
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                inFile >> ch;
                st = ((int) ch)-48;
                gameBoard[i][j].setSituation(st);
            }

            //inFile >> ch;
        }
        //displayBoard();
        //open the file and init the board and print to the screen
    }else{
        cerr<<"File couldn't opened for LOAD"<<endl;
    }

    inFile.close();
}


void ConnectFour::play(int* rowInput, int* columnInput, char playerSign){ // user acts
    string input = "\0";
    char column = '\0';
    int row = 0;
    string player;

    if(playerSign == 'o')
        player = "P2";
    else
        player = "P1";

    getInputFromPlayer(player, input, &column, &row); // get a letter for column and row

    *rowInput = row;

    if(input.compare("SAVE") == 0){
        cout<<"Game saved successfully!"<<endl;
        play(rowInput, columnInput, playerSign);
    }else if(input.compare("LOAD") == 0){
        cout<<"Game loaded successfully!"<<endl;
        //player(newBoard, boardSizeHelper, rowInput, columnInput, playerSign);
    }else if(((int)column) < 97){ //if it's a lowercase letter
        *columnInput = (int)column-65; // 65 is decimal value for 'a' in ASCII table
        if(gameBoard[row][((int)column)-65].getSituation() == 0) //if the move is legal
        {
            if(playerSign == 'o')
                gameBoard[row][((int)column)-65].setSituation(2); //put the sign to that cell
            else
                gameBoard[row][((int)column)-65].setSituation(1); //put the sign to that cell
        }

        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            play(rowInput, columnInput, playerSign);
        }
        ++numberOfLivingCells;
    } else if(((int)column) >= 97){ //if it's a uppercase letter
        *columnInput = (int)column-97; // 97 is decimal value for 'A' in ASCII table
        if(gameBoard[row][((int)column)-97].getSituation() == 0) //if the move is legal
        {
            if(playerSign == 'o')
                gameBoard[row][((int)column)-97].setSituation(2); //put the sign to that cell
            else
                gameBoard[row][((int)column)-97].setSituation(1); //put the sign to that cell
        }

        else{
            cout<<"This move is not legal! Please try another move"<<endl;
            play(rowInput, columnInput, playerSign);

        }
        ++numberOfLivingCells;
    }
}



int ConnectFour::playerVersusPlayer(){ // player vs player gaming mode

    int row = 0;
    int column = 0;
    int score_1 = 0, score_2 = 0;
    cout<<endl<<"Turn : Player 1"<<endl; // first player
    play(&row, &column, 'x'); // make the move
    if(playerOrComputer == 1 && !loaded){
        displayBoard();
        score_1 = isItAScore(row, column, 'x'); // is it winning?
        displayTheScore(score_1, score_2, playerOrComputer); // display the score
        if(score_1 >= 1){ // if it's winning
            cout<<"Game Over! Player 1 Won!!"<<endl;
            displayBoard();
            displayTheScore(score_1, score_2, playerOrComputer); // display the winning score
            return 1; //end
        }
        cout<<endl<<"Turn : Player 2"<<endl; // second player
        play(&row, &column, 'o'); // make the move
        displayBoard();
        score_2 = isItAScore(row, column, 'o'); // is it winning?
        displayTheScore(score_1, score_2, playerOrComputer); // display the score
        if(score_2 >= 1){ // if it's winning
            cout<<"Game Over! Player 2 Won!!"<<endl;
            displayBoard();
            displayTheScore(score_1, score_2, playerOrComputer); // display the winning score
            return 1; //end
        }
        if(isTheBoardAvailable()) // if the board is available
        {
            cout << "LivingCell: " << getNumberOfLivingCells() << endl;
            //cout<<"single or multi : "<<singleOrMulti<<endl;
            //if(singleOrMulti=='S')
                //playerVersusPlayer(); // turn for another move
        }
        else{  // if the board is not available
            cout<<"Game Over! The Board Is Filled!"<<endl;
            displayBoard();
            cout<<"LivingCell: " << getNumberOfLivingCells()<<endl;
            displayTheScore(score_1, score_2, playerOrComputer); // draw the last version of the score
            return 1; //end
        }
    }else if(playerOrComputer == 1 && loaded){
        displayBoard();
        cout<<"LivingCell: " << getNumberOfLivingCells()<<endl;
        //if(singleOrMulti == 'S')
         //   playerVersusPlayer();
    }
    else{
        cout<<"LivingCell: " << getNumberOfLivingCells()<<endl;
        displayBoard();
        //computerVersusPlayer(newBoard, boardSizeHelper, gamingModeGlob);
    }
    return 0;
}

int ConnectFour::isItAScore(int row, int column, char player){ // calculates the score
    int count = 0;
    int score = 0;
    int sign = 0;

    if(player == 'x')
        sign = 1;
    if(player == 'o')
        sign = 2;

    //vertical
    int i=row;

    while(i>0 && gameBoard[i-1][column].getSituation() == sign){
        --i;
    }
    while(i<height && gameBoard[i][column].getSituation() == sign){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    //horizontal
    count = 0;
    i = column;

    while(i>0 && gameBoard[row][i-1].getSituation() == sign){
        --i;
    }
    while(i<width && gameBoard[row][i].getSituation() == sign){
        ++i;
        ++count;
    }
    if(count>=4)
        ++score;

    //diagonally right up to left bottom
    count = 1;
    i = column;
    int j = row;

    while(i<width && j>0 && (gameBoard[j][i].getSituation() == sign)){
        ++i;
        --j;
        //cout<<count<<"    hereeee"<<endl;
        //cout<<i<<"    hereeee"<<endl;
        //cout<<j<<"    hereeee"<<endl;
        
        //exit(1);
    }
    --i;
    ++j;
    while(i>0 && j<height && (gameBoard[j][i].getSituation() == sign)){

        --i;
        ++j;
        ++count;
        
    }
    if(count>=4)
        ++score;
    

    //diagonally left up to right bottom
    count = 1;
    i = column;
    j = row;

    while(i>0 && j>0 && (gameBoard[j-1][i-1].getSituation() == sign)){
        --i;
        --j;
    }
    ++i;
    ++j;
    while(i<width && j<height && (gameBoard[j][i].getSituation() == sign)){
        ++i;
        ++j;
        ++count;
        //cout<<count<<"    hereeee"<<endl;
        
    }
    if(count>=4)
        ++score;

    return score;
}

bool ConnectFour::isTheBoardAvailable(){ // calculates if there is any empty cell on the board
    bool available = false;
    for(int i= 0; i<height; ++i){
        for(int j = 0; j<width; ++j){
            if(gameBoard[i][j].getSituation() == 0){ // if there is any empty cell return true
                available = true;
                break;
            }
        }
        if(available == true){
            break;
        }
    }
    return available; // return if there is an empty cell or not
}

void ConnectFour::displayTheScore(int player_1 = 0, int player_2_or_computer = 0, int mode = 1){ // displays who's winning
    if(mode == 1){
        cout<<"Player 1 : "<<player_1<<endl;
        cout<<"Player 2 : "<<player_2_or_computer<<endl;
    }else if(mode == 2){
        cout<<"Player 1 : "<<player_1<<endl;
        cout<<"Player 2 : "<<player_2_or_computer<<endl;
    }
    cout<<endl;
}

// calculateCounts is same as the isItAScore function but returns the number of the same letter repeatedly for all odds (like "ooo" - how many o?)

vector<int> ConnectFour::calculateCounts(int row, int column, char player){ // a helper function for bestOdds dunction

    int count = 0;
    int score = 0;
    vector<int> v;
    int sign;

    if(player == 'x')
        sign = 1;
    else if(player == 'o')
        sign = 2;

    //vertical
    int i=row;

    while(i>0 && gameBoard[i-1][column].getSituation() == sign){
        --i;
    }
    ++i;
    while(i<height && gameBoard[i][column].getSituation() == sign){
        ++i;
        ++count;
    }
    v.push_back(count);
    if(count>=4)
        ++score;

    //horizontal
    count = 0;
    i = column;

    while(i>0 && gameBoard[row][i-1].getSituation() == sign){
        --i;
    }
    while(i<width && gameBoard[row][i].getSituation() == sign){
        ++i;
        ++count;
    }
    v.push_back(count);
    if(count>=4)
        ++score;

    //diagonally right up to left bottom
    count = 0;
    i = column;
    int j = row;

    while(i<width && j>0 && gameBoard[j][i].getSituation() == sign){
        ++i;
        --j;
    }
    while(i>0 && j<height && gameBoard[j][i].getSituation() == sign){
        --i;
        ++j;
        ++count;
    }
    v.push_back(count);
    if(count>=4)
        ++score;

    //diagonally left up to right bottom
    count = 0;
    i = column;
    j = row;

    while(i>0 && j>0 && gameBoard[j][i].getSituation() == sign){
        --i;
        --j;
    }
    while(i<width && j<height && gameBoard[j][i].getSituation() == sign){
        ++i;
        ++j;
        ++count;
    }
    v.push_back(count);
    if(count>=4)
        ++score;

    return v;
}

bool ConnectFour::play(){ // computer acts
    int row = 0;
    int column = 0;
    int index = 0;
    index = bestOdds(); // calculate the odds take the best as column
    playHelper(&row, &index, 'o');
    return true;
}

int ConnectFour::bestOdds(){  // calculates all odds for computer and returns the best of them
    int row = 0;
    vector<int> computerOdds;
    vector<int> playerOdds;
    int oddIndexForPlayer = 0;
    int oddIndexForComputer = 0;
    vector<int> checkCountArray;
    int oddComp = 0;
    int oddPly = 0;
    int cntComp = 0;
    int cntPly = 0;
    int min = 0;
    ConnectFour newGame;
    newGame.setWidth(width);
    newGame.setHeight(height);
    newGame.createTheBoard();

    newGame.gameBoard = gameBoard;

    //begin from the first column
    for(int k=0; k<newGame.height; ++k){
        row = getRowHelper(k+65); //get the first available row
        min = k;
        if(row>-1){
            //gameCells[row][index];
            newGame.playHelper(&row, &k, 'o');
            oddComp = newGame.isItAScore(row, k, 'o'); //if it's a score
            if(oddComp >= 1)
                return k; //play for that move, so return that column for play
            else{ //if it's not score
                checkCountArray = newGame.calculateCounts(row, k, 'o'); //calculate how many o's are there for all dimentions and fill an array
                for(int p = 0; p<(countArraySize-1); ++p){ // calculate the biggest value in the countsArray
                    int temp1 = 0;
                    int temp2 = 0;
                    temp1 = checkCountArray[p];
                    temp2 = checkCountArray[p+1];
                    if(temp1 > temp2)
                        cntComp = temp1;
                    else if(temp2>cntComp)
                        cntComp = temp2;
                }
                for(int t=0; t<width; ++t){ //start from the first column
                    row = newGame.getRowHelper(t+65); //calculate the first available cell in that column
                    if(row>-1){
                        newGame.playHelper(&row, &t, 'x'); //play for the foe
                        oddPly = newGame.isItAScore(row, t, 'x'); // is it a score?
                        if(oddPly >= 1){ //if it's a score
                            playerOdds.push_back(1); //put 1 to score array for foe
                        }else{
                            playerOdds.push_back(0); //else put 0 to score array for foe
                            checkCountArray = newGame.calculateCounts(row, t, 'x'); //calculate how many x's are there for all dimentions and fill an array
                            for(int r = 0; r<(countArraySize-1); ++r){ // calculate the biggest value in the countsArray
                                int temp1 = 0;
                                int temp2 = 0;
                                temp1 = checkCountArray[r];
                                temp2 = checkCountArray[r+1];
                                if(temp1 > temp2)
                                    cntPly = temp1;
                                else
                                    cntPly = temp2;
                            }
                            if(cntPly==4) //return the best move for computer
                                return t;
                        }
                    }

                    newGame.playHelper(&row, &t, '.');
                }
            }
            if(cntComp>cntPly) //return the best move for computer
                return k;
        }
        playHelper(&row, &k, '.');
    }
    return min;
}

void ConnectFour::gameInitialization(){
    setTheBoardSize();
    setTheGamingMode();
    createTheBoard();
    fillTheBoardWithZeros();
}

int ConnectFour::computerVersusPlayer(){ // computer vs player gaming mode

    int row = 0;
    int column = 0;
    int index = 0;
    int score_1 = 0, score_2 = 0;
    cout<<endl<<"Turn : Player 1"<<endl; // first player
    play(&row, &column, 'x'); // make the move
    if(playerOrComputer == 2 && !loaded){
        displayBoard(); //draw the board
        score_1 = isItAScore(row, column, 'x'); // is it winning?
        displayTheScore(score_1, score_2); // display the score
        if(score_1 >= 1){ // if it's winning
            cout<<"Game Over! Player Won!!"<<endl;
            displayBoard(); // draw the winning table
            displayTheScore(score_1, score_2); // display the winning score
            return 1; //end
        }
        cout<<endl<<"Turn : Computer"<<endl; // computer

        play(); // make the move
        ++numberOfLivingCells;
        displayBoard(); //draw the board
        cout<<"LivingCell: " << getNumberOfLivingCells()<<endl;
        score_2 = isItAScore(row, index, 'o'); // is it winning?
        displayTheScore(score_1, score_2); // display the score
        if(score_2 >= 1){ // if it's winning
            cout<<"Game Over! Computer Won!!"<<endl;
            displayBoard(); // draw the winning table
            displayTheScore(score_1, score_2); // display the winning score
            return 1; //end
        }
        //if(isTheBoardAvailable()) // if the board is available
        //computerVersusPlayer(); // turn for another move
        if(!isTheBoardAvailable()){
            cout<<"Game Over! The Board Is Filled!"<<endl;
            displayBoard(); // draw the last version of the table
            cout<<"LivingCell: " << getNumberOfLivingCells()<<endl;
            displayTheScore(score_1, score_2); // draw the last version of the score
            return 1; //end
        }
    }else if(playerOrComputer == 2 && loaded){
        loaded = 0;
        displayBoard(); //draw the board
        //computerVersusPlayer();
    }else{
        displayBoard(); //draw the board
        //playerVersusPlayer();
    }
    return 0;
}
void ConnectFour::playHelper(int* rowInput, int* columnInput, char playerSign){
    int row = 0;
    row = getRowHelper((*columnInput)+65);  // calculate the row for the best column odd
    int sign = 0;
    if(playerSign == 'x')
        sign = 1;
    else if(playerSign == 'o')
        sign = 2;
    else if(playerSign == '.')
        sign = 0;
    //if(theBoard[*rowInput][*columnInput] == '.') // if the cell is available
    if(row > -1)
        gameBoard[row][*columnInput].setSituation(sign); // put the sign to that cell
    //displayBoard();
}

int ConnectFour::playGame(){
    int ret = 0;
    //cout<<"asdfasdasd single mıııı : "<<singleOrMultiGlob<<endl;
    if(singleOrMulti == 'S'){
        while(ret==0){
            displayBoard();
            if(getTheGamingMode() == 1)
                ret = playerVersusPlayer();
            else if(getTheGamingMode() == 2)
                ret = computerVersusPlayer();

            //cout<<"asdfasdasd rettttttt : "<<ret<<endl;
        }
    }
    else{
        displayBoard();
        //cout<<"sdfasdasdasdasd "<<getTheGamingMode()<<endl;
        if(getTheGamingMode() == 1)
            ret = playerVersusPlayer();
        else if(getTheGamingMode() == 2)
            ret = computerVersusPlayer();
        return ret;
    }
    return -1;
}

bool ConnectFour::operator==(const ConnectFour &other) const {
    if(getTheGamingMode() == other.getTheGamingMode()
            && getHeight()==other.getHeight()
            && getWidth() == other.getWidth()){
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                if(!(gameBoard[i][j] == other.gameBoard[i][j]))
                    return false;
            }
        }
    }
    return true;
}

bool ConnectFour::operator!=(const ConnectFour &other) const{
    return(!(*this==other));
}
