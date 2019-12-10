#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

void die(string s = "INVALID INPUT!") {
    cout << s << endl;
    exit(EXIT_FAILURE);
}

//Holds a record for a single species of Pokemon, such as Pikachu
class Pokemon {
  public:
    Pokemon() {};
    //YOU: Add member variable ints for each of the following:
    int index = 0;
    //index - what index it is in the pokedex
    string name = "" ;
    //name (this is a string not an int)
    int hp = 0;
    //hp - how much damage it takes before dying^H^H^H^H^H^H fainting
    int attack = 0;
    //attack - this number gets multiplied by the move's power to determine damage
    int defense = 0;
    //defense - incoming damage gets divided by this number
    int speed = 0;
    //speed - whichever pokemon has the highest speed attacks first, flip a coin on a tie
    int special = 0;
    //special - like attack and defense both, but for special moves
    //Note: this is also the order the data is ordered in the file
    //YOU: Add member variables of type string for type1 and type2
    string type1 = "";
    string type2 = "";
    Pokemon(int tempIndex, string tempName, int tempHp, int tempAttack, int tempDefense, int tempSpeed, int tempSpecial, string tempType1, string tempType2) {
        index = tempIndex;
        name = tempName;
        hp = tempHp;
        attack = tempAttack;
        defense = tempDefense;
        speed = tempSpeed;
        special = tempSpecial;
        type1 = tempType1;
        type2 = tempType2;
    }
    };
vector<Pokemon> pokemon_db; //Holds all pokemon known to mankind

//This function reads from the "pokemon.txt" file in the directory and loads the data into the pokemon_db global vector
//Each row has: pokemon number, name, hp, etc.
void load_pokemon_db(string filename = "pokemon.txt", string filename2 = "types.txt") {
    ifstream ins(filename);
    if (!ins) die("Couldn't load file "s + filename);
    ifstream ins2(filename2);
    if (!ins2) die("Couldn't load file"s + filename2);
    while (ins and ins2) {
        Pokemon tempPoke;
        int skip = 0;
        string skip1 = "";
        ins >> tempPoke.index;
        if (!ins) break;
        // Temporary Vector to manipulate lines
        vector<string> tempVec;
        string temp1 = "";
        getline(ins, temp1);
        stringstream ss(temp1);

        while (ss) {
            if (!ss) break;
            string temp2;
            ss >> temp2;
            if (ss) tempVec.push_back(temp2);
        }
        tempPoke.special = stoi(tempVec.back());
        tempVec.pop_back();
        tempPoke.speed = stoi(tempVec.back());
        tempVec.pop_back();
        tempPoke.defense = stoi(tempVec.back());
        tempVec.pop_back();
        tempPoke.attack = stoi(tempVec.back());
        tempVec.pop_back();
        tempPoke.hp = stoi(tempVec.back());
        tempVec.pop_back();
        int pokeName = 0;   
                if (tempVec.size() == 1) {
            //cerr << "one Name\n";
            tempPoke.name = tempVec.back();
        }// pokemon_db.push_back(tempPoke);
        else {
            string name2;
            for (string s : tempVec)
                name2 += s + " ";
            name2.pop_back();
            tempPoke.name = name2;
            pokeName = tempVec.size();
        }

        string tempTypes;

        getline(ins2, tempTypes);
        stringstream str(tempTypes);

        str >> skip;
        str >> skip1;
        if (pokeName)
            for (int i = 0; i < pokeName - 1; i++)
                str >> skip1;

        str >> tempPoke.type1;
        if (str) str >> tempPoke.type2;
        else tempPoke.type2 = "";

        //variable of the class type Pokemon
        pokemon_db.push_back(tempPoke);


    }
//int index, string name, string type, string category, int PP, int power, int accuracy
}
class Move {
  public:
    Move() {};
    //YOU: Add member variable for each of these:
    int index = 0;
    string name = "";
    string type = "";
    string category = "";
    int PP = 0;
    int power = 0;
    int accuracy = 0;                     
        Move(int tempIndex, string tempName, string tempType, string tempCategory, int tempPP, int tempPower, int tempAccuracy) {
        index = tempIndex;
        name = tempName;
        type = tempType;
        category = tempCategory;
        PP = tempPP;
        power = tempPower;
        accuracy = tempAccuracy;
    }
};
vector<Move> move_db;

//Reads all moves from moves.txt into move_db
//Be sure to discard all status moves
void load_move_db(string filename = "moves.txt") {
    ifstream ins(filename);
    if (!ins) die("Couldn't load "s + filename);
    while (ins) {
        Move movetemp;

        string temp;
        getline(ins, temp);
        stringstream ss(temp);

        ss >> movetemp.index;
        getline(ss, temp, '\t');
        getline(ss, temp, '\t');
        movetemp.name = temp;

        ss >> movetemp.type;
        ss >> movetemp.category;

        if (movetemp.category == "Status") continue;

        ss >> movetemp.PP;
        ss >> movetemp.power;
        ss >> movetemp.accuracy;
        //YOU: Push it back into the move_db

        move_db.push_back(movetemp);


        //YOU: Read from the file, make a temp Move with all the data read in
    }
}           

//PART 2
//This conducts a one versus one battle between two pokemon of your choice
void battle_mode() {
    cout << "Enter your Pokemon's Index #" << endl;
    int index = 0;
    cin >> index;
    if (!cin || index < 1 || index > int (pokemon_db.size())) die();
    Pokemon poke1 = pokemon_db.at(index - 1);
    cout << "Choose moves for " << poke1.name << endl;
    cout << "Enter the moves' Index number" << endl;
    bool not_done = true;
    vector<Move> poke1_moves;
    //cin >> index;

    while (not_done) {
        cin >> index;
        if (index == -1) not_done = false;
        else if (!cin || index < 1 || index > int (move_db.size())) not_done = false;
        else poke1_moves.push_back(move_db.at(index - 1));
        //cout this part
    }




    //Pick a Pokemon and a move for team one
    //Pick a Pokemon and a move for team two
    //Whichever Pokemon has the higher speed goes first
    //Have them do damage to each other based on their move * power * type modifier
    //Target Pokémon reduces damage based on its defense or special defense
}
//PART 2
void explore_mode() {
}

int main() {
    srand(0); //Fixed seed - don't change this
    system("figlet POKEMON");
    system("figlet ++ and \\#");
    cout << "Do you want to use the Gen1 Pokémon? (Type \"NO\" for no, anything else for yes.)\n";
    string answer;
    getline(cin, answer);
    for (char &c : answer) c = toupper(c); //Uppercaseify
    string filename1, filename2;
    if (answer == "NO") {
        cout << "Please enter the two files containing the Pokémon and types for the Pokémon.\n";
        cin >> filename1 >> filename2;
        load_pokemon_db(filename1, filename2);
    } else
        load_pokemon_db();

    /* Debug the load - uncomment this to see everything
       for (Pokemon p : pokemon_db) {
       cerr << "Pokedex Entry " << p.index << ": " << p.name << " hp: " << p.hp << " attack: " << p.attack;
       cerr << " defense: " << p.defense << " speed: " << p.speed << " special: " << p.special;
       cerr << " type1: " << p.type1 << " type2: " << p.type2 << endl;
       }
       */

    string filename3;
    if (answer == "NO") {
        //cout << "Please enter the two files containing the moves for your Pokémon.\n";
        cout << "Please enter the file containing the moves for your Pokémon.\n";
        cin >> filename3;
        load_move_db(filename3);
    } else
        load_move_db();

    /*
    // DEBUG the load - uncomment this to see the results
    for (Move m : move_db) {
    if (m.index == 0) continue;
    cerr << "Move Index " << m.index << ": " << m.name << " " << " type: " << m.type << " category: " << m.category << " PP: " << m.PP << " power: " << m.power << " accuracy: " << m.accuracy << "%\n";
    }
    */
       cout << "Do you want to\n1) Print Pokémon Data?\n2) Print Move Data?\n3) Pokemon Battle (1v1)\n4) Explore the World?\n";
    int choice = 0;
    cin >> choice;
    if (!cin || choice < 1 || choice > 4) die();
    if (choice == 1) {
        cout << "Please enter the Pokedex number of the Pokémon whose data you want to print:\n";
        int index = 0;
        cin >> index;
        if (!cin || index < 1) die();
        //  Pokemon p = pokemon_db.at(index + 1); //Pokedex starts at 1, this only works for Gen1 Pokémon
        Pokemon p;
        for (const Pokemon &poke : pokemon_db) if (index == poke.index) p = poke;
        cout << "Pokedex Entry " << p.index << ": " << p.name << " hp: " << p.hp << " attack: " << p.attack;
        cout << " defense: " << p.defense << " speed: " << p.speed << " special: " << p.special;
        cout << " type1: " << p.type1 << " type2: " << p.type2 << endl;
    } else if (choice == 2) {
        cout << "Please enter the move number of the move whose data you want to print:\n";
        int index = 0;
        cin >> index;
        if (!cin) die();
        Move m;
        for (const Move &mo : move_db) if (index == mo.index) m = mo;
        if (m.name == "Error") cout << "No move loaded with that index.\n";
        else
            cout << "Move Index " << m.index << ": " << m.name << " " << " type: " << m.type << " category: " << m.category << " PP: " << m.PP << " power: " << m.power << " accuracy: " << m.accuracy << "%\n";
    }
    if (choice == 3) battle_mode(); //PART 2
    else explore_mode(); //PART 2
}