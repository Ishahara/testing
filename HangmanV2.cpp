#include <bits/stdc++.h>
using namespace std;

//List of words
const string WORD_LIST[] = {"dog", "cat", "human", "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
 
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

//List of figures
const string FIGURE[] = {
    "\n +---+\n |   |\n     |\n     |\n     |\n     |\n=======\n", // 0
    "\n +---+\n |   |\n O   |\n     |\n     |\n     |\n=======\n", // 1
    "\n +---+\n |   |\n O   |\n |   |\n     |\n     |\n=======\n", // 2
    "\n +---+\n |   |\n O   |\n/|   |\n     |\n     |\n=======\n", // 3
    "\n +---+\n |   |\n O   |\n/|\\ |\n     |\n     |\n=======\n", // 4
    "\n +---+\n |   |\n O   |\n/|\\ |\n/    |\n     |\n=======\n", // 5
    "\n +---+\n |   |\n O   |\n/|\\ |\n/\\  |\n     |\n=======\n"  // 6
};

const int MAX_BAD_GUESSES = 7;

//Function to choose a random word from the list
string chooseWord() {
    srand(time(0)); 
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex]; 
}

//Function to check if the guessed word contains the guessed letter
bool contains(string secretWord, char guess) {
    return secretWord.find(guess) != string::npos;
}

//Function to update the guessed word with the guessed letter
string update(string guessedWord, string secretWord, char guess) {
    for (size_t i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}

//Function to render the game
void renderGame(string guessedWord, int badGuessCount) {
    cout << FIGURE[badGuessCount] << endl;
    cout << "Word: " << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

//Function to read a guess from the player
char readAGuess() {
    char guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

//Main function
int main() {
    string secretWord = chooseWord();
    string guessedWord(secretWord.length(), '-');
    int badGuessCount = 0;

// Game loop: continue until the player wins or reaches max bad guesses
    do {
        renderGame(guessedWord, badGuessCount);
        char guess = readAGuess();
        if (contains(secretWord, guess)) {
            guessedWord = update(guessedWord, secretWord, guess);
        } else {
            badGuessCount++;
        }
    } while (badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);
    
    renderGame(guessedWord, badGuessCount);
    
    if (badGuessCount < MAX_BAD_GUESSES)
        cout << "Congratulations! You win!" << endl;
    else
        cout << "You lost. The correct word was: " << secretWord << endl;
    
    return 0;
}

