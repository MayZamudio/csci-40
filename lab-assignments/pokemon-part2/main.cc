//ZAMUDIO & JENSEN
#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void die(string s = "INVALID INPUT!") {
    cout << s << endl;
    exit(EXIT_FAILURE);
}
void end() {
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
//      if (!ins) break;
        move_db.push_back(movetemp);
        //cerr << movetemp.name << endl;
        //YOU: Read from the file, make a temp Move with all the data read in
    }
    move_db.pop_back();
}


//One way to convert from type name to row number in the type_system.txt file
int lookup_type(string s) {
    if (s == "Normal") return 0;
    else if (s == "Fighting") return 1;
    else if (s == "Flying") return 2;
    else if (s == "Poison") return 3;
    else if (s == "Ground") return 4;
    else if (s == "Rock") return 5;
    else if (s == "Bug") return 6;
    else if (s == "Ghost") return 7;
    else if (s == "Steel") return 8;
    else if (s == "Fire") return 9;
    else if (s == "Water") return 10;
    else if (s == "Grass") return 11;
    else if (s == "Electric") return 12;
    else if (s == "Psychic") return 13;
    else if (s == "Ice") return 14;
    else if (s == "Dragon") return 15;
    else if (s == "Dark") return 16;
    else if (s == "Fairy") return 17;
    //Etc...
    else
        return 1;
}


vector<vector<float>> types_multiplier(18, vector<float>(18, 0));

void load_type_multipliers(string filename = "type_system.txt") {
    ifstream ins(filename);

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            ins >> types_multiplier[i][j];
        }
    }
    /*  for (auto x : types_multiplier) {
            for (auto y : x) {
                cout << y << "\t";
            }
            cout << endl;
        }*/
}
int flipCoin() {
    int randNumb;
    randNumb = rand() % 2;
    return randNumb;
}

//PART 2
//This conducts a one versus one battle between two pokemon of your choice
void battle_mode() {
    cout << endl;
    system("figlet -f smblock PLAYER 1  | lolcat"); //prints title to the screen
    cout << " ϞϞ(๑⚈ ․̫ ⚈๑)∩ " << endl;
    cout << "\n Enter PLAYER ONE's Pokemon Index #" << endl;
    int index = 0;
    cin >> index;
    if (!cin || index < 1 || index > pokemon_db.back().index) die();
    Pokemon poke1;
    for (size_t i = 0; i < pokemon_db.size(); i++) {
        if (index == pokemon_db.at(i).index) {
            poke1 = pokemon_db.at(i);
        }
    }
    cout << "\n Choose up to 4 moves for:\n ";// << poke1.name/* << " with speed of: " << poke1.speed << " with a type of " << poke1.type1 << " and "  << poke1.type2*/ << endl;
    cout << endl;
    /*  for (Move c : move_db) {
            cout << c.index << endl;
        }*/
    string pokemon1 = "pokemon --pokemon "s + poke1.name + " | lolcat";
    system(pokemon1.c_str());
    cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
    bool not_done = true;

    vector<Move> poke1_moves;
    while (poke1_moves.size() < 4 && not_done) {
        cin >> index;
        //  if (index == -1) not_done = false;
        if (!cin || index < 1 || index > move_db.back().index) break; //not_done = false;

        else {
            for (size_t i = 0; i < move_db.size(); i++) {
                if (index == move_db.at(i).index) {
                    poke1_moves.push_back(move_db.at(i));
                }
            }
            /*  cout << "\n You chose to give " << poke1.name << " the following moves:" << endl;
                for (Move m : poke1_moves) {
                    cout <<  " " << m.index << " Name: " << m.name << endl;
                }*/
            //  poke1_moves.push_back(move_db.at(index - 1));
        }//cout this part to make sure temp moves vector is loading correctly
    }
    cout << "\n You chose to give " << poke1.name << " the following moves:" << endl;
    for (Move m : poke1_moves) {
        if (m.index == 0) continue;
        cout <<  " 🔹" << m.index <<  ".) " << m.name << endl;
    }
    // IF NO MOVES WERE CHOSEN
    if (poke1_moves.empty()) {
        for (Move i : move_db)
            if (i.index == 165) {
                poke1_moves.push_back(i);
                cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
            }
        cout << "\n You chose to give " << poke1.name << " the following moves:" << endl;
        for (Move m : poke1_moves) {
            if (m.index == 0) continue;
            cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
        }
    }

    //SECOND POKEMON
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    cout << endl;
    system("figlet -f smblock PLAYER 2  | lolcat"); //prints title to the screen
    cout << " Ϟ(๑⚈ ․̫ ⚈๑)~ ː̗̤ː̖́.• ξ(^ω^)ξ " << endl;
    cout << "\n Enter PLAYER TWO's Pokemon Index #" << endl;
//  int index = 0;
    cin >> index;
    if (!cin || index < 1 || index > pokemon_db.back().index) die();
    Pokemon poke2;
    for (size_t i = 0; i < pokemon_db.size(); i++) {
        if (index == pokemon_db.at(i).index) {
            poke2 = pokemon_db.at(i);
        }
    }
    cout << "\n Choose up to 4 moves for:\n ";
    string pokemon2 = "pokemon --pokemon "s + poke2.name + " | lolcat";
    system(pokemon2.c_str());
    cout << " Enter the Moves' Index number;  Enter -1 when done" << endl;
    bool not_done1 = true;
    vector<Move> poke2_moves;
    while (poke2_moves.size() < 4 && not_done1) {
        cin >> index;
        if (!cin || index < 1 || index > move_db.back().index) break;
        else {
            for (size_t j = 0; j < move_db.size(); j++) {
                if (index == move_db.at(j).index) {
                    poke2_moves.push_back(move_db.at(j));
                }
                //poke2_moves.push_back(move_db.at(index2 - 1));
                //if (poke2_moves.size() >= 4) not_done1 = false;
            }
        }
    }
       cout << "\n You chose to give " << poke2.name << " the following moves:" << endl;
    for (Move m : poke2_moves) {
        if (m.index == 0) continue;
        cout <<  " 🔹" << m.index <<  ".) " << m.name << endl;
    }
    if (poke2_moves.empty()) {
        for (Move i : move_db)
            if (i.index == 165) {
                poke2_moves.push_back(i);
                cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
            }
        cout << "\n You chose to give " << poke2.name << " the following moves:" << endl;
        for (Move m : poke2_moves) {
            if (m.index == 0) continue;
            cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
        }
    }  //if no moves

//Whichever Pokemon has the higher speed goes first
//If speed is equal to each other  use rand()

    Pokemon *active = &poke1;
    Pokemon *inactive = &poke2;
    vector<Move> *active_moves = &poke1_moves;

    if (poke2.speed == poke1.speed) {
//      cout << "\n Your ish is equal to each other" << endl;
        int randNumb = 0;
        randNumb = flipCoin();
        if (randNumb == 1) {
            active = &poke1;
            inactive = &poke2;
            active_moves = &poke1_moves;
        } else {
            active = &poke2;
            inactive = &poke1;
            active_moves = &poke2_moves;
        }
//      cout << " randNumb was: " << randNumb << " " << active->name << endl;
    }
    if (poke2.speed > poke1.speed) {
        active = &poke2;
        inactive = &poke1;
        active_moves = &poke2_moves;
    }
        cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet BATTLE  | lolcat"); //prints title to the screen
    cout << " (ง'̀-'́)ง " << endl;
    cout << "\n ✳ " << active->name << " goes first.\n";

    load_type_multipliers();

    while (active->hp > 0) {
        cout << "\n Select a move from the list\n";
        cout << endl;
        for (size_t i = 0; i < active_moves->size(); i++) {
            cout <<  " 🔹"  << active_moves->at(i).index <<  ".) "  << active_moves->at(i).name << endl;
        }
        int choice;
        cin >> choice;
        if (!cin || choice < 0) die();
        Move active_move;
        for (size_t i = 0; i < active_moves->size(); i++) {
            if (choice == active_moves->at(i).index) {
                active_move = active_moves->at(i);
            }
        }
        cout << "\n (╯°□°)╯︵◓" << endl;
        cout << "\n " << active->name << " is attacking " << inactive->name << " with a move of " << active_move.name << endl;
        int damage = 1;
        damage *= active_move.power * active->attack / (inactive->defense) ;
        damage *= types_multiplier[lookup_type(active->type1)][lookup_type(inactive->type1)];
        damage *= types_multiplier[lookup_type(active->type2)][lookup_type(inactive->type2)];
        damage *= (active->type1 == active_move.type ? 1.5 : 1);
        damage *= (active->type2 == active_move.type ? 1.5 : 1);

        cout << "\n (。_°)☆ " << endl;
        cout << "\n " << inactive->name << " takes damage of " << damage << " and the hp goes from " << inactive->hp << " to ";
        inactive->hp -= damage;
        cout << inactive->hp << endl;
        if (active->name == poke1.name) {
            active = &poke2;
            inactive = &poke1;
            active_moves = &poke2_moves;
        } else {
            active = &poke1;
            inactive = &poke2;
            active_moves = &poke1_moves;

        }
    }
        cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet VICTORY!!!!! | lolcat");
    cout << "\n ";
    string pokemonWin = "pokemon --pokemon "s + inactive->name + " | lolcat";
    system(pokemonWin.c_str());
    cout << endl;
    cout << " 🏆 " << inactive->name << " has defeated " << active->name << " !!!" << endl;
    cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
    cout << endl;
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    end();
//Have them do damage to each other based on their move * power * type modifier
//Target Pokémon reduces damage based on its defense or special defense
}


//PART 2
/*Extra Credit:
An extra letter grade is available for implementing an "adventure mode"
in which the player starts with one of four basic Pokémon and battles
other, randomly generated, Pokémon over time. The player can either
run away or fight it. If they fight it and win, it gets added to their
roster of Pokémon they can use in a fight. If they lose, they die.*/
void explore_mode() {
    system("toilet -f smblock Poke World --filter border:metal"); //prints title to the screen
    cout << "        ϞϞ(๑⚈ ․̫ ⚈๑)∩ " << endl;
    cout << "\n Choose your Pokemon:" << endl;
    cout << "\n 1.) Bulbasaur 2.) Ivysaur  3.) Venasaur 4.) Charmander" << endl;
    int choice = 0;
    cin >> choice;
    int index = 0;
    vector<Pokemon> pokemon_party;
    if (!cin || choice < 1 || choice > 4) die();
    Pokemon mainPoke = pokemon_db.at(choice - 1);
    pokemon_party.push_back(mainPoke);
    cout << "\n You chose: \n" << endl;
    string pokeExp = "pokemon --pokemon "s + mainPoke.name + " | lolcat";
    system(pokeExp.c_str());
    //Random Pokemon Selector
    int randomIndex = rand() % pokemon_db.size();
    Pokemon battlePoke = pokemon_db.at(randomIndex);
    int input = 0;
    cout << "\n You see: " <</* battlePoke.index << ".) " <<*/ battlePoke.name << endl;
    cout << "\n Ϟ(๑⚈ ․̫ ⚈๑)~ ː̗̤ː̖́.• ξ(^ω^)ξ " << endl;
    cout << "\n 1. Fight it 🤺 " << endl;
    cout << "\n 2. Runaway 🏃 " << endl;
    cout << "\n> ";
    cin >>  input;
    if (!cin || input < 1 || input > 2) die();
    if (input == 1) {
        cout << "\n Choose up to 4 moves for:\n " << mainPoke.name << endl;
        cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
        bool not_done = true;
        vector<Move> poke_moves;
        while (poke_moves.size() < 4 && not_done) {
            cin >> index;
            if (!cin || index < 1 || index > move_db.back().index) break;

            else {
                for (size_t i = 0; i < move_db.size(); i++) {
                    if (index == move_db.at(i).index) {
                        poke_moves.push_back(move_db.at(i));
                    }
                }
            }
        }
        cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
        for (Move m : poke_moves) {
            if (m.index == 0) continue;
            cout <<  " 🔹" << m.index << ".) " << m.name << endl;
        }
               if (poke_moves.empty()) {
            for (Move i : move_db)
                if (i.index == 165) {
                    poke_moves.push_back(i);
                    cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                }
            cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
            for (Move m : poke_moves) {
                if (m.index == 0) continue;
                cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
            }
        }

        cout << "\n Choose up to 4 moves for:\n " << battlePoke.name << endl;
        cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
        bool not_done1 = true;
        int index = 0;
        vector<Move> poke1_moves;
        while (poke1_moves.size() < 4 && not_done1) {
            cin >> index;
            if (!cin || index < 1 || index > move_db.back().index) break;
            else {
                for (size_t i = 0; i < move_db.size(); i++) {
                    if (index == move_db.at(i).index) {
                        poke1_moves.push_back(move_db.at(i));
                    }
                }
            }
        }
        cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
        for (Move m : poke1_moves) {
            if (m.index == 0) continue;
            cout <<  " 🔹" << m.index << ".) " << m.name << endl;
        }
        if (poke1_moves.empty()) {
            for (Move i : move_db)
                if (i.index == 165) {
                    poke1_moves.push_back(i);
                    cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                }
            cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
            for (Move m : poke1_moves) {
                if (m.index == 0) continue;
                cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
            }
        }
        Pokemon *active = &mainPoke;
        Pokemon *inactive = &battlePoke;
        vector<Move> *active_moves = &poke_moves;
        if (battlePoke.speed > mainPoke.speed) {
            active = &battlePoke;
            inactive = &mainPoke;
            active_moves = &poke1_moves;
        }
                cout << endl;
        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
        system("figlet BATTLE  | lolcat"); //prints title to the screen
        cout << " (ง'̀-'́)ง " << endl;
        cout << "\n ✳ " << active->name << " goes first.\n";

        load_type_multipliers();

        while (active->hp > 0) {
            cout << "\n Select a move from the list\n";
            cout << endl;
            for (size_t i = 0; i < active_moves->size(); i++) {
                cout <<  " 🔹"  << active_moves->at(i).index <<  ".) "  << active_moves->at(i).name << endl;
            }
            int choice;
            cin >> choice;
            if (!cin || choice < 0) die();
            Move active_move;
            for (size_t i = 0; i < active_moves->size(); i++) {
                if (choice == active_moves->at(i).index) {
                    active_move = active_moves->at(i);
                }
            }
            cout << "\n (╯°□°)╯︵◓" << endl;
            cout << "\n " << active->name << " is attacking " << inactive->name << " with a move of " << active_move.name << endl;
            int damage = 1;
            damage *= active_move.power * active->attack / (inactive->defense) ;
            damage *= types_multiplier[lookup_type(active->type1)][lookup_type(inactive->type1)];
            damage *= types_multiplier[lookup_type(active->type2)][lookup_type(inactive->type2)];
            damage *= (active->type1 == active_move.type ? 1.5 : 1);
            damage *= (active->type2 == active_move.type ? 1.5 : 1);

            cout << "\n (。_°)☆ " << endl;
            cout << "\n " << inactive->name << " takes damage of " << damage << " and the hp goes from " << inactive->hp << " to ";
            inactive->hp -= damage;
            cout << inactive->hp << endl;
            if (active->name == mainPoke.name) {
                active = &battlePoke;
                inactive = &mainPoke;
                active_moves = &poke1_moves;
            } else {
                active = &mainPoke;
                inactive = &battlePoke;
                active_moves = &poke_moves;

            }
        }
                cout << endl;
        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
        system("figlet VICTORY!!!!! | lolcat");
        cout << "\n ";
        string pokemonWin = "pokemon --pokemon "s + inactive->name + " | lolcat";
        system(pokemonWin.c_str());
        cout << endl;
        cout << " 🏆 " << inactive->name << " has defeated " << active->name << " !!!" << endl;
        cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
        cout << endl;
        cout << endl;
        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
        Pokemon winner = *inactive;
        Pokemon loser = *active;
        if (winner.index == mainPoke.index) {
// ROUND 2 OF POKEMON EXPLORE
            cout << "\n " << mainPoke.name << " won the battle!!!" << endl;
            cout << "\n Gotta Cath Em All!!" << endl;
            pokemon_party.push_back(battlePoke);
            cout << "\n You now have: " << endl;
            for (Pokemon a : pokemon_party) {
                cout <<  " 🔹 " << a.name << endl;
            }
            cout << "\n Choose your Pokemon:" << endl;
            cout << "\n 1.) " << pokemon_party.at(0).name << " 2.) " << pokemon_party.at(1).name << endl;
            int choice2 = 0;
            cin >> choice2;
            if (!cin || choice2 < 1 || choice2 > 2) die();
            Pokemon mainPoke = pokemon_party.at(choice2 - 1);
            cout << "\n You chose: \n" << endl;
            string pokeExp = "pokemon --pokemon "s + mainPoke.name + " | lolcat";
            system(pokeExp.c_str());
            //Random Pokemon Selector
            int randomIndex = rand() % pokemon_db.size();
            Pokemon battlePoke = pokemon_db.at(randomIndex);
            int input = 0;
            cout << "\n You see: " <</* battlePoke.index << ".) " <<*/ battlePoke.name << endl;
            cout << "\n Ϟ(๑⚈ ․̫ ⚈๑)~ ː̗̤ː̖́.• ξ(^ω^)ξ " << endl;
            cout << "\n 1. Fight it 🤺 " << endl;
            cout << "\n 2. Runaway 🏃 " << endl;
            cout << "\n> ";
            cin >>  input;
            if (!cin || input < 1 || input > 2) die();
            if (input == 1) {
                cout << "\n Choose up to 4 moves for:\n " << mainPoke.name << endl;
                cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
                bool not_done = true;
                int index = 0;
                vector<Move> poke_moves;
                while (poke_moves.size() < 4 && not_done) {
                    cin >> index;
                    if (!cin || index < 1 || index > move_db.back().index) break; //not_done = false;
                         else {
                        for (size_t j = 0; j < move_db.size(); j++) {
                            if (index == move_db.at(j).index) {
                                poke_moves.push_back(move_db.at(j));
                            }
                        }
                    }
                }
                cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
                for (Move m : poke_moves) {
                    if (m.index == 0) continue;
                    cout <<  " 🔹" << m.index << ".) " << m.name << endl;
                }
                if (poke_moves.empty()) {
                    for (Move i : move_db)
                        if (i.index == 165) {
                            poke_moves.push_back(i);
                            cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                        }
                    cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
                    for (Move m : poke_moves) {
                        if (m.index == 0) continue;
                        cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
                    }
                }

                cout << "\n Choose up to 4 moves for:\n " << battlePoke.name << endl;
                cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
                bool not_done1 = true;
                vector<Move> poke1_moves;
                while (poke1_moves.size() < 4 && not_done1) {
                    cin >> index;
                    if (!cin || index < 1 || index > move_db.back().index) break;
                    else {
                        for (size_t i = 0; i < move_db.size(); i++) {
                            if (index == move_db.at(i).index) {
                                poke1_moves.push_back(move_db.at(i));
                            }
                        }

                    }
                }
                cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
                for (Move m : poke1_moves) {
                    if (m.index == 0) continue;
                    cout <<  " 🔹" << m.index << ".) " << m.name << endl;
                }
                                if (poke1_moves.empty()) {
                    for (Move i : move_db)
                        if (i.index == 165) {
                            poke1_moves.push_back(i);
                            cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                        }
                    cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
                    for (Move m : poke1_moves) {
                        if (m.index == 0) continue;
                        cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
                    }
                }
                Pokemon *active = &mainPoke;
                Pokemon *inactive = &battlePoke;
                vector<Move> *active_moves = &poke_moves;
                if (battlePoke.speed > mainPoke.speed) {
                    active = &battlePoke;
                    inactive = &mainPoke;
                    active_moves = &poke1_moves;
                }
                cout << endl;
                cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                system("figlet BATTLE  | lolcat"); //prints title to the screen
                cout << " (ง'̀-'́)ง " << endl;
                cout << "\n ✳ " << active->name << " goes first.\n";

                load_type_multipliers();

                while (active->hp > 0) {
                    cout << "\n Select a move from the list\n";
                    cout << endl;
                    for (size_t i = 0; i < active_moves->size(); i++) {
                        cout <<  " 🔹"  << active_moves->at(i).index <<  ".) "  << active_moves->at(i).name << endl;
                    }
                    int choice;
                    cin >> choice;
                    if (!cin || choice < 0) die();
                    Move active_move;
                    for (size_t i = 0; i < active_moves->size(); i++) {
                        if (choice == active_moves->at(i).index) {
                            active_move = active_moves->at(i);
                        }
                    }
                    cout << "\n (╯°□°)╯︵◓" << endl;
                    cout << "\n " << active->name << " is attacking " << inactive->name << " with a move of " << active_move.name << endl;
                    int damage = 1;
                    damage *= active_move.power * active->attack / (inactive->defense) ;
                    damage *= types_multiplier[lookup_type(active->type1)][lookup_type(inactive->type1)];
                    damage *= types_multiplier[lookup_type(active->type2)][lookup_type(inactive->type2)];
                    damage *= (active->type1 == active_move.type ? 1.5 : 1);
                    damage *= (active->type2 == active_move.type ? 1.5 : 1);
                    
                    cout << "\n (。_°)☆ " << endl;
                    cout << "\n " << inactive->name << " takes damage of " << damage << " and the hp goes from " << inactive->hp << " to ";
                    inactive->hp -= damage;
                    cout << inactive->hp << endl;
                    if (active->name == mainPoke.name) {
                        active = &battlePoke;
                        inactive = &mainPoke;
                        active_moves = &poke1_moves;
                    } else {
                        active = &mainPoke;
                        inactive = &battlePoke;
                        active_moves = &poke_moves;

                    }
                }
                cout << endl;
                cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                system("figlet VICTORY!!!!! | lolcat");
                cout << "\n ";
                string pokemonWin = "pokemon --pokemon "s + inactive->name + " | lolcat";
                system(pokemonWin.c_str());
                cout << endl;
                cout << " 🏆 " << inactive->name << " has defeated " << active->name << " !!!" << endl;
                cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
                cout << endl;
                cout << endl;
                cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                Pokemon winner = *inactive;
                Pokemon loser = *active;
                if (winner.index == mainPoke.index) {
// ROUND 3 OF POKEMON EXPLORE
                    cout << "\n " << mainPoke.name << " won the battle!!!" << endl;
                    cout << "\n Gotta Cath Em All!!" << endl;
                    pokemon_party.push_back(battlePoke);
                    cout << "\n You now have: " << endl;
                    for (Pokemon a : pokemon_party) {
                        //  if (a.index == 0) continue;
                        cout <<  " 🔹 " << a.name << endl;
                    }
                    cout << "\n Choose your Pokemon:" << endl;
                    cout << "\n 1.) " << pokemon_party.at(0).name << " 2.) " << pokemon_party.at(1).name << " 3.) " << pokemon_party.at(2).name << endl;
                    int choice = 0;
                    cin >> choice;
                    if (!cin || choice < 1 || choice > 3) die();
                    Pokemon mainPoke = pokemon_party.at(choice - 1);
                    cout << "\n You chose: \n" << endl;
                    string pokeExp = "pokemon --pokemon "s + mainPoke.name + " | lolcat";
                    system(pokeExp.c_str());
                    //Random Pokemon Selector
                                        int randomIndex = rand() % pokemon_db.size();
                    Pokemon battlePoke = pokemon_db.at(randomIndex);
                    int input = 0;
                    cout << "\n You see: " <</* battlePoke.index << ".) " <<*/ battlePoke.name << endl;
                    cout << "\n Ϟ(๑⚈ ․̫ ⚈๑)~ ː̗̤ː̖́.• ξ(^ω^)ξ " << endl;
                    cout << "\n 1. Fight it 🤺 " << endl;
                    cout << "\n 2. Runaway 🏃 " << endl;
                    cout << "\n> ";
                    cin >>  input;
                    if (!cin || input < 1 || input > 2) die();
                    if (input == 1) {
                        cout << "\n Choose up to 4 moves for:\n " << mainPoke.name << endl;
                        cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
                        bool not_done = true;
                        vector<Move> poke_moves;
                        while (poke_moves.size() < 4 && not_done) {
                            cin >> index;
                            if (!cin || index < 1 || index > move_db.back().index) break;
                            else {
                                for (size_t k = 0; k < move_db.size(); k++) {
                                    if (index == move_db.at(k).index) {
                                        poke_moves.push_back(move_db.at(k));
                                    }
                                }
                            }
                        }
                        cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
                        for (Move m : poke_moves) {
                            if (m.index == 0) continue;
                            cout <<  " 🔹" << m.index << ".) " << m.name << endl;
                        }
                        if (poke_moves.empty()) {
                            for (Move i : move_db)
                                if (i.index == 165) {
                                    poke_moves.push_back(i);
                                    cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                                }
                            cout << "\n You chose to give " << mainPoke.name << " the following moves:" << endl;
                            for (Move m : poke_moves) {
                                if (m.index == 0) continue;
                                cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
                            }
                        }
                                               cout << "\n Choose up to 4 moves for:\n " << battlePoke.name << endl;
                        cout << "\n Enter the Moves' Index number; Enter -1 when done" << endl;
                        bool not_done1 = true;
                        vector<Move> poke1_moves;
                        while (poke1_moves.size() < 4 && not_done1) {
                            cin >> index;
                            if (!cin || index < 1 || index > move_db.back().index) break;
                            else {
                                for (size_t i = 0; i < move_db.size(); i++) {
                                    if (index == move_db.at(i).index) {
                                        poke1_moves.push_back(move_db.at(i));
                                    }
                                }
                            }

                        }
                        cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
                        for (Move m : poke1_moves) {
                            if (m.index == 0) continue;
                            cout <<  " 🔹" << m.index << ".) " << m.name << endl;
                        }
                        if (poke1_moves.empty()) {
                            for (Move i : move_db)
                                if (i.index == 165) {
                                    poke1_moves.push_back(i);
                                    cout << "\n Since you didn't choose anything, you've been given: " << i.name << endl;
                                }
                            cout << "\n You chose to give " << battlePoke.name << " the following moves:" << endl;
                            for (Move m : poke1_moves) {
                                if (m.index == 0) continue;
                                cout <<  " 🔹" << m.index << ".) " << m.name << "  🔸Power: " << m.power <<  endl;
                            }
                        }
                        Pokemon *active = &mainPoke;
                        Pokemon *inactive = &battlePoke;
                        vector<Move> *active_moves = &poke_moves;
                        if (battlePoke.speed > mainPoke.speed) {
                            active = &battlePoke;
                            inactive = &mainPoke;
                            active_moves = &poke1_moves;
                        }
                        cout << endl;
                        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                        system("figlet BATTLE  | lolcat"); //prints title to the screen
                        cout << " (ง'̀-'́)ง " << endl;
                        cout << "\n ✳ " << active->name << " goes first.\n";

                        load_type_multipliers();
                                                while (active->hp > 0) {
                            cout << "\n Select a move from the list\n";
                            cout << endl;
                            for (size_t i = 0; i < active_moves->size(); i++) {
                                cout <<  " 🔹"  << active_moves->at(i).index <<  ".) "  << active_moves->at(i).name << endl;
                            }
                            int choice;
                            cin >> choice;
                            if (!cin || choice < 0) die();
                            Move active_move;
                            for (size_t i = 0; i < active_moves->size(); i++) {
                                if (choice == active_moves->at(i).index) {
                                    active_move = active_moves->at(i);
                                }
                            }
                            cout << "\n (╯°□°)╯︵◓" << endl;
                            cout << "\n " << active->name << " is attacking " << inactive->name << " with a move of " << active_move.name << endl;
                            int damage = 1;
                            damage *= active_move.power * active->attack / (inactive->defense) ;
                            damage *= types_multiplier[lookup_type(active->type1)][lookup_type(inactive->type1)];
                            damage *= types_multiplier[lookup_type(active->type2)][lookup_type(inactive->type2)];
                            damage *= (active->type1 == active_move.type ? 1.5 : 1);
                            damage *= (active->type2 == active_move.type ? 1.5 : 1);

                            cout << "\n (。_°)☆ " << endl;
                            cout << "\n " << inactive->name << " takes damage of " << damage << " and the hp goes from " << inactive->hp << " to ";
                            inactive->hp -= damage;
                            cout << inactive->hp << endl;
                            if (active->name == mainPoke.name) {
                                active = &battlePoke;
                                inactive = &mainPoke;
                                active_moves = &poke1_moves;
                            } else {
                                active = &mainPoke;
                                inactive = &battlePoke;
                                active_moves = &poke_moves;

                            }
                        }
                        cout << endl;
                        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                        system("figlet VICTORY!!!!! | lolcat");
                        cout << "\n ";
                        string pokemonWin = "pokemon --pokemon "s + inactive->name + " | lolcat";
                        system(pokemonWin.c_str());
                        cout << endl;
                        cout << " 🏆 " << inactive->name << " has defeated " << active->name << " !!!" << endl;
                        cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
                        cout << endl;
                        cout << endl;
                        cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
                        Pokemon winner = *inactive;
                        Pokemon loser = *active;
                                                if (winner.index == mainPoke.index) {
                            cout << "\n " << mainPoke.name << " won the battle!!!" << endl;
                            cout << "\n Gotta Cath Em All!!" << endl;
                            pokemon_party.push_back(battlePoke);
                            cout << "\n You now have: " << endl;
// ROUND 4 OF POKEMON EXPLORE
                            for (Pokemon a : pokemon_party) {
                                //  if (a.index == 0) continue;
                                cout <<  " 🔹 " << a.name << endl;
                            }
                            cout << endl;
                            string pokemon = "pokemon --pokemon "s + pokemon_party.at(0).name + " | lolcat";
                            system(pokemon.c_str());
                            string pokemon1 = "pokemon --pokemon "s + pokemon_party.at(1).name + " | lolcat";
                            system(pokemon1.c_str());
                            string pokemon2 = "pokemon --pokemon "s + pokemon_party.at(2).name + " | lolcat";
                            system(pokemon2.c_str());
                            string pokemon3 = "pokemon --pokemon "s + pokemon_party.at(3).name + " | lolcat";
                            system(pokemon3.c_str());
                            cout << endl;
                            system("figlet -f smblock ISSA PARTAYYYY!!!!  | lolcat");
                        } else
                            cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
                        cout << endl;
                        end();

//Have them do damage to each other based on their move * power * type modifier

                    } else if (input == 2) {
                        cout << "\n 🏃 You try to run " << endl;
                        cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
                        cout << endl;
                        cout << endl;
                        exit(0);
                    }



                } else
                    cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
                cout << endl;
                end();

//Have them do damage to each other based on their move * power * type modifier

            } else if (input == 2) {
                cout << "\n 🏃 You try to run " << endl;
                cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
                cout << endl;
                cout << endl;
                exit(0);
            }
        } else
            cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
        cout << endl;
        end();
    } else if (input == 2) {
        cout << "\n 🏃 You try to run " << endl;
        cout << "\n ☠ You have been killed by " << battlePoke.name << " ☠ " << endl;
        cout << endl;
        cout << endl;
        exit(0);
    }
}

int main() {
//  srand(0);//Fixed seed - don't change this*/
    srand(time(0));
    system("figlet POKEMON  | lolcat"); //prints title to the screen
    system("figlet ++ and \\#  | lolcat"); //prints title to the screen
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
//      Pokemon p = pokemon_db.at(index + 1); //Pokedex starts at 1, this only works for Gen1 Pokémon
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
    } else if (choice == 3) battle_mode(); //PART 2
    else explore_mode(); //PART 2
}