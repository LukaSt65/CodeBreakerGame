#include <iostream>
#include <ctime>
using namespace std; 

void PrintIntroduction(int Difficulty){
    //Print message to the terminal
    cout <<"\n\nThe player is in an abandoned laboratory where they've discovered a safe with a three-digit code. \n";
    cout << "You must decipher hidden clues in the room to uncover the correct code and open the safe before triggering the security alarm"<<endl;
    cout << "LEVEL: " << Difficulty << endl;

}

bool PlayGame(int Difficulty){
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntroduction(Difficulty);

    //Print CodeSum and CodeProduct to the terminal
    cout << "+ There are three numbers in a code" << endl;
    cout << "+ The codes add up to: "  << CodeSum << endl;
    cout << "+ The codes multiply to give: " << CodeProduct << endl;


    //Store player guess
    int GuessA, GuessB, GuessC;;
    cin >> GuessA >> GuessB >> GuessC;
    cout << "You entered: " << GuessA << GuessB << GuessC << endl;
    cout << endl;

    int GuessSum, GuessProduct;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;
    
    //Check if the players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "Level passed!" << endl;
        return true;
    }
    else{
        cout << "You LOSE! Try again!" << endl;
        return false;
    }
}

int main(){
    
    srand(time(NULL)); //creates new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // clears any errors
        cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    cout << "Congratulations you opened the safe without triggering an alarm ";

    return 0;
}