#include <iostream>
#include <stdlib.h>

using namespace std;

void die() {
    exit(EXIT_FAILURE);
}

void nevada();
void curtCobainHouse();
void gunShop();
void stage1();
void stage2();
void stage3();
void stage4(int &cagedAlien, int &element115);
void stage5();
void stage6();
void puzzle3(int &pHealth, int &gHealth);
void puzzle4(int &pHealth, int &gHealth);
void puzzle5();
void area51();
void attackGuard(int &pHealth, int &gHealth);
void attackGuard1(int &pHealth, int &gHealth);
void attackGuard2(int &pHealth, int &gHealth);
void guardDead();
void searchBody();
void missionUpdate();
void end();

int input;
int stages[6] = {1, 0, 0, 0, 0, 0};
string qUpdates;
string qStages;

int main() {

    srand(time(NULL));

    system("figlet AREA 51 RAID"); //prints title to the screen
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input;

    if (!cin) die();
    if (input < 1 || input  > 2) die();
    switch (input) {

    case 1:
        cout << " ✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
        cout << "\n In 2016, 17 year old Harambe was murdered...\n";
        cout << " or assassinated? Harambe was aware of an \n";
        cout << " alien species only known to Curt Cobain.\n";
        cout << " The LIVING Curt Cobain..You (the player)\n";
        cout << " had a personal connection to the enlightened\n";
        cout << " Harambe. You've finally managed to track\n";
        cout << " down Curt Cobain's hidden Laboratory.\n";
        qUpdates = " Mission Assigned";
        qStages = " ✳ Talk to Curt Cobain in his underground alien\n research facility";
        missionUpdate();

        nevada();

    case 2:
        return EXIT_SUCCESS;

    }
}
void nevada() {
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet Nevada"); //prints title to the screen
    cout << "\n You are in the Nevada Desert. Where would you like to go?" << endl;
    cout << "\n 1. Curt Cobain's underground alien research facility" << endl;
    cout << "\n 2. Area 51" << endl;
    cout << "\n 3. Gun Shop" << endl;
    cin >> input;

    switch (input) {

    case 1:
        if (stages[0] == 1) {
            stage6();
        } else
            curtCobainHouse();

    case 2:
        area51();

    case 3:
        gunShop();
    }
}
void curtCobainHouse() {
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet Lab"); //prints title to the screen

    if (stages[0] == 1) {
        cout << "\n Curt: Do you want to avenge HARAMBE'S MURDER!?!\n";
        cout << " There's rumoured to be Lambium ☢️ (synthesized element \n found only in black holes)";
        cout << " laying around as well.\n";
        cout << "\n 1. Anything for HARAMBE!!!" << endl;
        cout << "\n 2. Nah Bruh..." << endl;
        cout << "\n> ";
        cin >> input;
        switch (input) {

        case 1:
            stage1();

        case 2:
            cout << "\n Curt: I'll give you a Heart Shaped Box if you change your mind" << endl;
            cout << "\n ";
            nevada();

        }
    }

    if (stages[1] == 1) {
        stage2();
    }

    if (stages[2] == 1) {
        stage3();
    }

    else {
        int cagedAlien = 0;
        int element115 = 0;
        stage4(cagedAlien, element115);
    }
}
void gunShop() {
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet Gun Shop"); //prints title to the screen
    if (stages[0] == 1) {
        cout << "\n ⛔️ There is a sign on the door that reads 'CLOSED'" << endl;
        cout << "\n (You leave) \n";
        nevada();
    } else {
        cout << "\n Gun Shop Owner: Back again?\n";
        cout << "\n 1. I've never been here??? How important is a background check? I'm kind of in a hurry? " << endl;
        cout << "\n 2. Yes! I can't get enough..." << endl;
        cout << "\n> ";
        cin >> input;
        switch (input) {

        case 1:
            stage5();

        case 2:
            puzzle5();

        }
    }
}
void stage1() {
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet Lab"); //prints title to the screen
    cout << "\n Curt: There's an alien that we need to rescue" << endl;
    cout << " I discovered and contacted an alien race and the government" << endl;
    cout << " kidnapped the representative they sent to speak with me." << endl;
    cout << " They most likely took him to Area 51." << endl;
    cout << " I didn't go inside because nobody knows I am alive" << endl;
    cout << " and I couldn't have word getting out that says otherwise.\n";
    cout << "\n 1. Great! I'll do it!" << endl;
    cout << "\n 2. Aliens aren't my cup of Pennyroyal Tea." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        stages[0] = 0;
        stages[2] = 1;
        cout << "\n Curt: I'll be waiting for you, In Bloom." << endl;
        cout << "\n ";

        qUpdates = " Mission update:";
        qStages = " ✳ Go to the Gun store";
        missionUpdate();

        nevada();

    case 2:
        stages[0] = 0;
        stages[1] = 1;
        cout << "\n Curt: Nevermind." << endl;
        cout << "\n ";
        nevada();

    }
}
void stage2() {

    cout << "\n Curt: Ha! They always come back. Will you rescue my Alien?" << endl;
    cout << "\n 1. Yes, I am ready for this quest." << endl;
    cout << "\n 2. NO!" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        stages[0] = 0;
        stages[1] = 0;
        stages[2] = 1;
        cout << "\n Curt: I'll be waiting for you, In Bloom." << endl;
        cout << "\n ";

        qUpdates = "Mission Update:";
        qStages = " ✳ Go to Area 51, kill the guards, return Alien to Curt Cobain at his secret lab.";
        missionUpdate();

        nevada();

    case 2:
        cout << "\n Curt: Then why are you bothering me again?? Scram." << endl;
        cout << "\n ";
        nevada();

    }
}
void stage3() {

    cout << "\n Curt: Did you rescue the Alien?" << endl;
    cout << "\n 1. Not yet bruh, chill." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n Curt: HURRY UP!!" << endl;
        cout << "\n ";
        nevada();

    }
}

void stage4(int &element115, int &cagedAlien) {

    cout << "\n Curt: Did you rescue the Alien?" << endl;
    cout << "\n 1. Yeah, it was a cakewalk." << endl;
    cout << "\n 2. Yes, but you almost got me killed." << endl;
    cout << "\n> ";
    cin >> input;

    cout << "\n Curt: Cool! I figured you'd be up to the task. By the way, I had some extra Lambium" << endl;
    cout << " lying around that I decided to give you as a reward." << endl;
    cout << "\n ";

    cagedAlien = 0;
    cout << "\n Item(s) returned - Alien" << endl;
    cout << "\n ";

    element115 = element115 + 100;
    cout << "\n Item(s) received - 100g of Lambium" << endl;
    cout << "\n ";

    qUpdates = "Mission complete";
    qStages = " ";
    missionUpdate();

    end();

}
void stage5() {


    cout << "\n 🧙 You know what? You look trustworthy. Solve this and I'll see what I can do.\n";
    cout << "\n 1. Ok, I'll play along.\n";
    cout << " 2. No way 🤬 \n";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n 🧙 What word comes next:\n";
        cout << "\n jangled \n febrifuge \n marbles \n apricot \n mayflower \n jungle \n julienne \n ";
        cout << "\n Choose from: 1) augment, 2) elephant, 3) autumn, 4) juiciest.\n" << endl;
        cin >> input;
        if (!cin) die();
        if (input < 1 || input  > 2) die();
        if (input == 1) {
            int gun;
            gun = 1;
            cout << "\n Oh smart fella... Here's your gun. Make sure not to take it to any gun-free zones\n";
            cout << "\n Item(s) received - Gun" << endl;
            qUpdates = "Mission Update:";
            qStages = " ✳ Go to Area 51, kill the guards, return Alien to Curt Cobain at his secret lab.";
            missionUpdate();
            cout << "\n ";
            nevada();
        } else {
            cout << "\n Nope, Just look at the first few characters of each word.\n";
            stage5();
        }
    case 2:
        nevada();
    }
}
void stage6() {
    cout << "\n  Curt: You remember the code, right?\n";
    cout << "\n 1. Uhmmmm... Of course \n";
    cout << " 2. (Leave) \n";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n Enter Code:\n";
        cout << "\n (Password Hint: Choose the song from your first album.)\n";
        cout << "\n 1. Smells Like Teen Spirit\n 2. Molly's Lips\n 3. Come as You Are\n 4. Sifting" << endl;
        cin >> input;

        if (input == 4) {
            curtCobainHouse();
        } else {
            cout << " WRONG, YOU HAVE 1 MINUTE TO LEAVE BEFORE THE TURRETS WILL FIRE\n";
            stage6();
        }
    case 2:
        nevada();
    }
}
//Puzzles after guards
void puzzle3(int &pHealth, int &gHealth) {

    cout << "\n You've defeated the guards outside. \n";
    cout << "\n You approach the door to the alien holding facility \n";
    cout << " There is a screen with numbers and buttons next to the \n";
    cout << " door, doubtlessly a locking mechanism. Certain sequences \n";
    cout << " of numbers will open the door.\n";

    cout << "\n 1. Continue through the door.\n";
    cout << " 2. Get out of Area 51 \n";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n Enter the next number in the sequence given: \n";
        cout << " 1 1 2 3 5 8 13 21 ❔ \n";
        cout << "\n 1. 42\n 2. 31\n 3. 34\n 4. 40\n";
        cin >> input;
        if (!cin) die();
        if (input < 1 || input  > 4) die();
        if (input == 3) {
            cout << " The door opens, revealing another, more heavily armed guard\n";
            attackGuard(pHealth, gHealth);
        }   else {
            cout << "Try again\n";
            puzzle3(pHealth, gHealth);
        }
    case 2:
        nevada();
    }
}
void puzzle4(int &pHealth, int &gHealth) {
    cout << " ⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋\n";
    cout << "\n You look through the guards's pockets and find his access card which you \n";
    cout << " know opens the room in which the alien is being kept. \n";
    cout << " As you swipe the ID, an LCD screen prompts the following:  \n";
    cout << " \n";

    cout << "\n 1. Continue to aquire access.\n";
    cout << " 2. Give up on the mission. \n";
    cin >> input;
    switch (input) {

    case 1:
        cout << " ⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋⇋\n";
        cout << "\n There are three nodes, two of which are not reporting correctly. \n";
        cout << " To fix the droid's particular system you have to choose the node that is reporting correctly. \n";
        cout << " The nodes read as follows: \n";
        cout << " \n Node 1 reports Node 2 is malfunctioning. \n";
        cout << " \n Node 2 reports Node 3 is malfunctioning. \n";
        cout << " \n Node 3 reports Node 2 is malfunctioning. \n";
        cout << "\n Which Node is reporting correctly ❔ \n";
        cout << "\n 1.) Node 1\n 2.) Node 2\n 3.) Node 3\n 4.) It's all messed up \n";
        cin >> input;
        if (!cin) die();
        if (input < 1 || input  > 4) die();
        if (input == 2) {
            cout << "\n The door opens, revealing the alien! \n";
            searchBody();
        }   else {
            cout << "Try again\n";
            puzzle4(pHealth, gHealth);
        }
    case 2:
        nevada();
    }
}
void puzzle5() {

    cout << "\n Alright are you ready for the next one? \n";

    cout << "\n 1. Kill some time and play.\n";
    cout << " 2. (Leave) \n";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n Tommorrow Is Neither Wednesday Nor Thursday. \n";
        cout << "\n Yesterday Was Not Friday Or Saturday. \n";
        cout << "\n Today Is Not Thursday Nor Monday Nor Sunday. \n";
        cout << "\n What Day Is Today? \n";

        cout << "\n 1.) Monday\n 2.) Tuesday\n 3.) Wednesday\n 4.) Thursday\n 5.) Friday\n";
        cin >> input;
        if (!cin) die();
        if (input < 1 || input  > 5) die();
        if (input == 5) {
            cout << " We have a smart one here!\n";
            nevada();
        }   else {
            cout << "Try again\n";
            puzzle5();
        }
    case 2:
        nevada();
    }
}
void area51() {
    cout << "☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢\n";
    system("figlet Area 51"); //prints title to the screen
    int pHealth;
//  int pDamage;
    int gHealth;
    int gDamage;
    int turn;

    if (stages[0] == 1 || stages[1] == 1 || stages[3] == 1 || stages[4] == 1) {
        cout << "\n 🥺 You see a lot of guards giving you dirty looks. \n    You don't want to raise suspicion s you leave.";
        cout << "\n ";
        nevada();

    } else

        cout << "\n Guard: this is a restricted area! Leave immediately!" << endl;
    cout << "\n 1. 🦍🦍🦍🦍 FOR HARAMBE!!!🦍🦍🦍🦍 (attack)." << endl;
    cout << "\n 2. Okay, okay, I'm leaving!" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        cout << "\n Guard: Ha! We killed that ape because he knew too much!" << endl;
        cout << "\n ";

        pHealth = rand() % 40 + 80;
        gHealth = rand() % 20 + 40;

        turn = rand() % 2;

        if (turn == 1) {
            cout << "\n The guard has the first turn." << endl;
            cout << "\n ";

            gDamage = rand() % 5 + 10;

            pHealth = pHealth - gDamage;
            cout << "\n The guard attacks you for " << gDamage << " damage!" << endl;
            cout << "\n ";

        }

        else {
            cout << "\n You have the first turn." << endl;
            cout << "\n ";
        }

        attackGuard1(pHealth, gHealth);

    case 2:
        cout << "\n Smart." << endl;
        cout << "\n ";
        nevada();

    }
}

void attackGuard(int &pHealth, int &gHealth) {

    cout << "✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯\n";
    system("figlet Final Battle"); //prints title to the screen

    int pDamage;
    int gDamage;

    if (stages[5] == 1) {
        pDamage = rand() % 10 + 1;
        gDamage = rand() % 10 + 1;
    } else {
        pDamage = rand() % 10 + 10;
        gDamage = rand() % 10 + 10;
    }
    cout << "\n ❇ Your health: " << pHealth << endl;
    cout << "\n Guard health:  " << gHealth << endl;
    cout << "\n What do you do ?" << endl;
    cout << "\n 1. Attack the guard" << endl;
    cout << "\n 2. Attempt to flee" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {
          case 1:
        gHealth = gHealth - pDamage;
        cout << "\n You attack the guard for " << pDamage << " damage!" << endl;
        cout << "\n ";

        if (gHealth < 1) {
            cout << "\n ☠ You have killed the guard! ☠ " << endl;
            cout << "\n ";
            guardDead();
        }

        pHealth = pHealth - gDamage;
        cout << "\n The guard attacks you for " << gDamage << " damage!" << endl;
        cout << "\n ";

        if (pHealth < 1) {
            cout << "\n ☠ You have been killed by the guard! ☠ " << endl;
            cout << "\n ";
            exit(0);
        }

        attackGuard(pHealth, gHealth);

    case 2:
        cout << "\n Can't escape!" << endl;
        cout << "\n ";
        attackGuard(pHealth, gHealth);

    }
}
//test
void attackGuard1(int &pHealth, int &gHealth) {

    cout << "✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯\n";
    system("figlet 1st Battle"); //prints title to the screen
    int pDamage;
    int gDamage;


    if (stages[5] == 1) {
        int gun;
        gun = 1;
        pDamage = rand() % 5 + 15;
        gDamage = rand() % 5 + 10;
    } else
        pDamage = rand() % 5 + 10;
    gDamage = rand() % 5 + 10;

    cout << "\n ❇ Your health: " << pHealth << endl;
    cout << "\n Guard health:  " << gHealth << endl;
    cout << "\n What do you do ?" << endl;
    cout << "\n 1. Attack the guard" << endl;
    cout << "\n 2. Attempt to flee" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        gHealth = gHealth - pDamage;
        cout << "\n You attack the guard for " << pDamage << " damage!" << endl;
        cout << "\n ";

        if (gHealth < 1) {
            cout << "\n ☠ You have killed the guard! ☠ " << endl;
            cout << "\n You have achieved level 2!";
            attackGuard2(pHealth, gHealth);

        }

        pHealth = pHealth - gDamage;

        cout << "\n The guard attacks you for " << gDamage << " damage!" << endl;
        cout << "\n ";
        if (pHealth < 1) {
            cout << "\n ☠ You have been killed by the guard! ☠ " << endl;
            cout << "\n ";
            exit(0);
        }

        attackGuard1(pHealth, gHealth);
    case 2:
        cout << "\n Can't escape!" << endl;
        cout << "\n ";
        attackGuard1(pHealth, gHealth);

    }
}
void attackGuard2(int &pHealth, int &gHealth) {
    cout << "✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯✯\n";
    system("figlet 2nd Battle"); //prints title to the screen

    int pDamage;
    int gDamage;
    pHealth += 100;
    gHealth += 80;
    if (stages[0] == 1) {
        int gun;
        gun = 1;
        pDamage = rand() % 10 + 50;
    } else
        pDamage = rand() % 10 + 10;
    gDamage = rand() % 5 + 10;

    cout << "\n ❇ Your health: " << pHealth << endl;
    cout << "\n Guard health:  " << gHealth << endl;
    cout << "\n What do you do ?" << endl;
    cout << "\n 1. Attack the guard" << endl;
    cout << "\n 2. Attempt to flee" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        gHealth = gHealth - pDamage;
        cout << "\n You attack the guard for " << pDamage << " damage!" << endl;
        cout << "\n ";

        if (gHealth < 1) {
            cout << "\n ☠ You have killed the guard! ☠ " << endl;
            cout << "\n ";
            cout << "You have achieved level 3!" << endl;
            puzzle3(pHealth, gHealth);
        }

        pHealth = pHealth - gDamage;

        cout << "\n The guard attacks you for " << gDamage << " damage!" << endl;
        cout << "\n ";
        if (pHealth < 1) {
            cout << "\n ☠ You have been killed by the guard! ☠ " << endl;
            cout << "\n ";
            system("figlet GAME OVER");
            exit(0);
        }
        puzzle3(pHealth, gHealth);
        
    case 2:
        cout << "\n Can't escape!" << endl;
        cout << "\n ";
        attackGuard2(pHealth, gHealth);

    }
}
//test
void guardDead() {
    int pHealth;
    int gHealth;
    qUpdates = "Mission Update:";
    qStages = " ✳ Check the guard for keys...";
    missionUpdate();

    cout << "\n What would you like to do?" << endl;
    cout << "\n 1. Search the guard's body." << endl;
    cout << "\n 2. Flee." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

    case 1:
        puzzle4(pHealth, gHealth);

    case 2:
        nevada();

    }
}

void searchBody() {

    int element115 = 0;
    int cagedAlien = 0;

    element115 = element115 + 20;
    cagedAlien = 1;
    stages[2] = 0;
    stages[3] = 1;

    cout << "\n Items received - Alien 👽, 20g Lambium ☢️" << endl;
    cout << "\n ";

    qUpdates = "Mission Update:";
    qStages = " ✳ Return to Curt's lab";
    missionUpdate();

    return;

}
void missionUpdate() {

    cout << "\n 👽 " << qUpdates << " - Area 51 Raid 👽" << endl;
    cout << "\n ";

    if (qStages != " ") {
        cout << "\n " << qStages << endl;
        cout << "\n ";
    }

    return;

}

void end() {

    system("figlet VICTORY!!!!!");
    cout << "\n ";
    die();
}