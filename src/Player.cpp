#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>

#include "../include/Common.h"
#include "../include/Player.h"
#include "../include/Console.h"
#include "../include/ItemTypes.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/prettywriter.h"
#include "../include/rapidjson/reader.h"
#include "../include/rapidjson/filereadstream.h"

using namespace std;
using namespace Common;
using namespace rapidjson;

#define SKIP_TURN -2

Player::Player(void) {
    // Initialize default sounds, attackRange should be
    // the result range of the ReturnDamage method in the child class
    // Child constructor should call SetSoundInfo with appropriate stuff
    SoundInfo info;
    info.attackRange = std::make_pair(1, 1);
    SetSoundInfo(info);
}

void Player::SaveGame() {
    StringBuffer s;
    PrettyWriter<StringBuffer> writer(s);

    string g(1, gender);

    writer.StartObject();
    writer.Key("Player Type");
    writer.Int(player_type);
    writer.Key("Name");
    writer.String(name.c_str());
    writer.Key("Gender");
    writer.String(g.c_str());
    writer.Key("Level");
    writer.Int(level);
    writer.Key("Experience");
    writer.Int(experience);
    writer.Key("Health");
    writer.Int(health);
    writer.Key("Arrows");
    writer.Int(arrows);
    writer.Key("Bombs");
    writer.Int(bombs);
    writer.Key("Potions");
    writer.Int(potions);
    writer.Key("Whetstones");
    writer.Int(whetstones);
    writer.Key("Weapon Sharpness");
    writer.Int(weaponsharpness);
    writer.Key("Coins");
    writer.Int(coins);
    writer.EndObject();
    
    ofstream WriteD;
    WriteD.open("data.json");
    if (WriteD.is_open()) {
        WriteD << s.GetString() << endl;
    } else {
        cout << "Error opening savegame data (data.json)." << endl;
    }
    ofstream WriteData;
    WriteData.open("data.txt");
    if (WriteData.is_open()) {
        WriteData << player_type << endl
                  << name << endl
                  << gender << endl
                  << level << endl
                  << experience << endl
                  << health << endl
                  << arrows << endl
                  << bombs << endl
                  << potions << endl
                  << whetstones << endl
                  << weaponsharpness << endl
                  << coins;
        WriteData.close();
    } else {
        cout << "Error opening savegame data (data.txt)." << endl;
    }
}

void Player::SetPlayerData() {
    // Primarily initializes default values at the beginning of the game.
    FILE* pFile = fopen("data.json", "rb");
    if (pFile) {
        char buffer[65536];
        FileReadStream is(pFile, buffer, sizeof(buffer));
        Document playerData;
        playerData.ParseStream<0, UTF8<>, FileReadStream>(is);
        if (playerData.HasParseError())
        {
            cout << "Parse unsuccessful" << endl;
        }
        else
        {
            cout << "Parse successful" << endl;
        }

        assert(playerData.IsObject());

        player_type = playerData["Player Type"].GetInt();
        cout << "Player type gotten" << endl;
        name = playerData["Name"].GetString();
        gender = *(playerData["Gender"].GetString());
        level = playerData["Level"].GetInt();
        experience = playerData["Experience"].GetInt();
        health = playerData["Health"].GetInt();
        arrows = playerData["Arrows"].GetInt();
        bombs = playerData["Bombs"].GetInt();
        potions = playerData["Potions"].GetInt();
        whetstones = playerData["Whetstones"].GetInt();
        weaponsharpness = playerData["Weapon Sharpness"].GetInt();
        coins = playerData["Coins"].GetInt();
    } else {
        cout << "Error opening savegame data (data.json)." << endl;
    }

    // ReadData.open("data.txt");
    // if (ReadData.is_open())	{
    //     ReadData >> player_type;
    //     ReadData.ignore();       // Ignore rest of line ready for getline
    //     getline(ReadData, name);
    //     ReadData >> gender;
    //     ReadData >> level;
    //     ReadData >> experience;
    //     ReadData >> health;
    //     ReadData >> arrows;
    //     ReadData >> bombs;
    //     ReadData >> potions;
    //     ReadData >> whetstones;
    //     ReadData >> weaponsharpness;
    //     ReadData >> coins;
    //     ReadData.close();
    // } else {
    //     cout << "Error opening savegame data (data.txt)." << endl;
    // }
}

int Player::Action() {
    // Returns the amount of attack points the player gives.
    // Also the main battle screen.
    int choice = 0;
    // Displays the inventory.
    DisplayInventory();
    // Gives player a list of moves to choose from.
    cout << "Choose your move:" << endl
         << "1) Attack" << endl
         << "2) Risk Attack" << endl
         << "3) Bow and Arrow" << endl
         << "4) Heal" << endl << endl
         << "5) Use Bomb" << endl
         << "6) Use Potion" << endl
         << "7) Use Whetstone" << endl
         << "0) Get me out of here!" << endl << endl;
    while (true) {
        choice = input();
        int damage = 0;
        // Evaluates player's choice.
        switch (choice) {
        case 0:
            return Flee();
        case 1:
            // Player generically attacks.
            damage = GenericAttack();
            PlayPrimaryAttack(damage);
            return damage;
        case 2:
            // Player takes a risk and attacks.
            damage = RiskAttack();
            PlayPrimaryAttack(damage);
            return damage;
        case 3:
            // Player shoots their bow.
            if (arrows > 0) {
                PlaySecondaryAttack();
                return BowAndArrow();
            } else {
                cout << "No arrows in the inventory!" << endl;
                Sleep(SLEEP_MS);
                return SKIP_TURN;
            }
        case 4:
            // Player heals, no damage is done to enemy.
            PlayHeal();
            Heal();
            return 0;
        case 5:
            // Player throws a bomb.
            // Does not execute if there are no bombs in the inventory.
            if (bombs > 0) {
                PlayBomb();
                return UseBomb();
            } else {
                cout << "No bombs in the inventory!" << endl;
                return SKIP_TURN;
            }
        case 6:
            // Player drinks a potion.
            // Does not execute if there are no potions in the inventory.
            if (potions > 0) {
                PlayPotion();
                UsePotion();
                return 0;
            } else {
                cout << "No potions in the inventory!" << endl;
                return SKIP_TURN;
            }
        case 7:
            // Player sharpens their weapon with a whetstone.
            // Does not execute if there are no whetstones in inventory.
            // No damage is done to the enemy.
            if (whetstones > 0) {
                PlaySharpen();
                UseWhetstone();
                return 0;
            } else {
                cout << "No whetstones in the inventory!" << endl;
                return SKIP_TURN;
            }
        default:
            // Generically attacks by default if player's choice does not equal above cases.
            return GenericAttack();
        }
    }
}

void Player::UseItem() {
    // Use item from inventory
    int choice = 0;
    while (true) {
        ClearScreen();
        // Displays the inventory.
        DisplayInventory();
        // Gives player a list of moves to choose from.
        cout << "Choose which item use:" << endl
             << "1) Use Potion" << endl
             << "2) Use Whetstone" << endl
             << "0) Quit" << endl << endl;
        choice = input();
        // Evaluates player's choice.
        switch (choice) {
        case 0:
            return;
        case 1:
            // Player drinks a potion.
            // Does not execute if there are no potions in the inventory.
            if (potions > 0) {
                UsePotion();
                Sleep(SLEEP_MS);
            } else {
                cout << "No potions in the inventory!" << endl;
                Sleep(SLEEP_MS);
            }
            break;
        case 2:
            // Player sharpens their weapon with a whetstone.
            // Does not execute if there are no whetstones in inventory.
            // No damage is done to the enemy.
            if (whetstones > 0) {
                UseWhetstone();
                Sleep(SLEEP_MS);
            } else {
                cout << "No whetstones in the inventory!" << endl;
                Sleep(SLEEP_MS);
            }
            break;
        default:
            cout<<"Item not present in the inventory!"<<endl;
            Sleep(SLEEP_MS);
            break;
        }
    }
}

void Player::AddToInventory(pair<string, int> drop) {
    if (drop.second == 0) {
        return;
    }
    cout << "You have gained: " << endl;
    if (drop.first == "arrows") {
        arrows += drop.second;
        cout << "[" << drop.second << "] arrows" << endl;
    }
    if (drop.first == "bombs") {
        bombs += drop.second;
        cout << "[" << drop.second << "] bombs" << endl;
    }
    if (drop.first == "potions") {
        potions += drop.second;
        cout << "[" << drop.second << "] potions" << endl;
    }
    if (drop.first == "whetstones") {
        whetstones += drop.second;
        cout << "[" << drop.second << "] whetstones" << endl;
    }
    if (drop.first == "coins") {
        coins += drop.second;
        cout << "[" << drop.second << "] coins" << endl;
    }
    cout << endl;
}

void Player::AddStoreItemToInventory(ITEMTYPE type, int amount) {
    // Adds items bought to total items.
    switch (type) {
    case ITEMTYPE::ARROWS:
        arrows += amount;
        break;
    case ITEMTYPE::BOMB:
        bombs += amount;
        break;
    case ITEMTYPE::POTION:
        potions += amount;
        break;
    case ITEMTYPE::WHETSTONE:
        whetstones += amount;
        break;
    }
}

bool Player::RemoveStoreItemFromInventory(ITEMTYPE type, int amount) {
    // Removes sold items from the inventory.
    switch (type) {
    case ITEMTYPE::ARROWS:
        if (arrows >= amount) {
            arrows -= amount;
            return true;
        }
        break;
    case ITEMTYPE::BOMB:
        if (bombs >= amount) {
            bombs -= amount;
            return true;
        }
        break;
    case ITEMTYPE::POTION:
        if (potions >= amount) {
            potions -= amount;
            return true;
        }
        break;
    case ITEMTYPE::WHETSTONE:
        if (whetstones >= amount) {
            whetstones -= amount;
            return true;
        }
        break;
    }
    // Invalid action (insufficient items)
    return false;
}

void Player::DisplayHUD(Enemy *_Enemy) {
    // Displays player's name and health bar. Enemy object is used to print name on the same line as player name for aesthetics.
    // Prints player's name.
    cout << endl;
    ColourPrint(name, Console::DarkGrey);
    // Tabs to make room for enemy's name.
    if (name.length() > 5) {
        cout << "\t\t\t";
    } else {
        cout <<" \t\t\t";
    }
    // Prints enemy name.
    ColourPrint(_Enemy->GetName(), Console::DarkGrey);
    cout << endl;
    DisplayHealthBar();
}

void Player::ReplenishHealth() {
    // Adds health points after player has defeated an enemy.
    if (health <= 0) {
        health = 100;
    } else {
        health += 30;
        if (health > 100) {
            health = 100;
        }
    }
}

void Player::AddExperience(int xp) {
    // Adds points to the player's experience and levels player up.
    // Adds experience from passed in integer to local class variable experience.
    experience += xp;
    // Evaluates if experience is higher than 99, which means a level up is in order.
    if (experience>99) {
        // Experience is set to 0.
        experience = 0;
        // Player is leveled up.
        level+=1;
        // Sets level cap to 50, player cannot level higher than that.
        if (level >= 50) {
            level = 50;
        }
        // Alerts player that they have leveled up.
        cout << "You leveled up! Now you are level " << level << "!" << endl;
        Sleep(SLEEP_MS);
    }
}

void Player::LoseExperience(int xp) {
    // Deducts points from the player's experience and de-levels player.
    // Deducts experience from passed in integer to local class variable experience.
    experience -= xp;
    // Evaluates if experience is less than 0.
    if (experience<0) {
        // Experience is deducted continuing from the experience which de-leveled the player (hard to explain...)
        experience = 100-(0-experience);
        // De-levels player.
        level-=1;
        // Checks any glitches and sets player level to 1 if level is below 1 or above 50.
        // Also resets experience points.
        if (level<1 || level>50) {
            level=1;
            experience = 0;
        }
        // Alerts the player that they have de-leveled.
        else {
            cout << "You de-leveled back to level " << level << "..." << endl;
            Sleep(SLEEP_MS);
        }
    }
}

void Player::AddCoins(int c) {
    coins += c;
}

void Player::LoseCoins(int c) {
    coins -= c;
    if (coins < 0) {
        coins = 0;
    }
}

void Player::DisplayInventory() {
    // Checks valid weapon sharpness.
    if (weaponsharpness < 0) {
        weaponsharpness = 0;
    }
    // Simply prints the player's inventory.
    PrintDivider('*', '-', " INVENTORY ");
    PrintXPBar("Level ", level, "", "", experience, "/100 xp");
    PrintClass();
    PrintDivider('+', '-', "");
    PrintInventoryItem("Arrows: [", arrows, "]");
    PrintInventoryItem("Potions: [", potions, "]");
    PrintInventoryItem("Bombs: [", bombs, "]");
    PrintInventoryItem("Whetstones: [", whetstones, "]");
    PrintInventoryItem("Weapon sharpness: [", weaponsharpness, "%]");
    PrintInventoryItem("Wealth: [", coins, "] coins");
    PrintDivider('*', '-', "");
}

int Player::GetCoins() {
    return coins;
}

int Player::GenericAttack() {
    int damage = ReturnDamage();
    DeductDamage(damage);
    ColourPrint(name, Console::DarkGrey);
    if (gender == 'M') {
        cout << " attacks! He deals ";
    } else {
        cout << " attacks! She deals ";
    }
    ColourPrint(to_string(damage), Console::Red);
    cout << " damage points!" << endl;
    if (damage>0) {
        WeakenWeapon(2);
    }
    return damage;
}

int Player::RiskAttack() {
    int damage = ReturnRiskAttackDamage();
    DeductDamage(damage);
    ColourPrint(name, Console::DarkGrey);
    cout << " takes a risk and attack! It deals ";
    ColourPrint(to_string(damage), Console::Red);
    cout << " damage points!" << endl;
    if (damage>0) {
        WeakenWeapon(4);
    }
    return damage;
}

void Player::WeakenWeapon(int impact) {
    if (impact >= 0) {
        weaponsharpness -= impact + Common::RandomInt(0, 4);
    } else {
        weaponsharpness -= Common::RandomInt(0, 4);
    }
    if (weaponsharpness < 0) {
        weaponsharpness = 0;
    }
}

int Player::BowAndArrow() {
    int damage = ReturnBowDamage();
    ColourPrint(name, Console::DarkGrey);
    if (gender == 'M') {
        cout << " shoots his bow! He deals ";
    } else {
        cout << " shoots her bow! She deals ";
    }
    Console::GetInstance().SetColour(Console::EColour::Red);
    cout << damage;
    Console::GetInstance().SetColour(Console::EColour::Default);
    cout << " damage points!" << endl;
    return damage;
}

void Player::UseWhetstone() {
    weaponsharpness=100;
    ColourPrint(name, Console::DarkGrey);
    if (gender == 'M') {
        cout << " sharpened his weapon!" << endl;
    } else {
        cout << " sharpened her weapon!" << endl;
    }
    whetstones--;
}

void Player::UsePotion() {
    health=100;
    ColourPrint(name, Console::DarkGrey);
    cout << " drank a healing potion!" << endl;
    potions--;
}

int Player::UseBomb() {
    ColourPrint(name, Console::DarkGrey);
    cout << " hurls a bomb! It deals ";
    ColourPrint("50", Console::Red);
    cout << " damage points!" << endl;
    bombs--;
    return 50;
}

void Player::DeductDamage(int& damage) {
    if (weaponsharpness<=75&&weaponsharpness>50) {
        damage-=1;
    } else if (weaponsharpness<=50&&weaponsharpness>30) {
        damage-=4;
    } else if (weaponsharpness<=30&&weaponsharpness>20) {
        damage-=5;
    } else if (weaponsharpness<=20&&weaponsharpness>10) {
        damage-=6;
    } else if (weaponsharpness<=10) {
        damage-=7;
    }
    if (damage<0) {
        damage=0;
    }
}

int Player::ReturnBowDamage() {
    if (arrows < 1) {
        return 0;
    }
    arrows--;
    return Common::RandomInt(10, 15);
}

int Player::Flee() {
    ColourPrint(name, Console::DarkGrey);
    cout << " chooses to flee!" << endl;
    return -1;
}

void Player::PrintInventoryItem(string preText, int itemCount, string postText) {
    size_t countLength = 0, countCopy = itemCount;
    // Calculate length of itemCount
    do {
        countLength++;
        countCopy /= 10;
    } while (countCopy);
    // Subtract space used in line (4 spaces for front and back dash/space combos, length of start and end text, length of itemCount) from the total available width
    size_t freeSpace = 35 - 4 - preText.length() - postText.length() - countLength;
    // Create a string with the appropriate number of spaces to make the line meet required width
    string spaces(freeSpace, ' ');
    // Print the line
    cout << "| " << preText << itemCount << postText << spaces << " |" << endl;
}

void Player::PrintXPBar(string preText1, int level, string postText1, string preText2, int experience, string postText2) {
    size_t countLength = 0, levelCopy = level, experienceCopy = experience;
    // Calculate length of level and experience
    do {
        countLength++;
        levelCopy /= 10;
    } while (levelCopy);
    do {
        countLength++;
        experienceCopy /= 10;
    } while (experienceCopy);
    // Subtract space used in line (4 spaces for front and back dash/space combos, length of start and end text, length of level and experience) from the total available width
    size_t freeSpace = 35 - 4 - preText1.length() - postText1.length() - preText2.length() - postText2.length() - countLength;
    // Create a string with the appropriate number of spaces to make the line meet required width
    string spaces(freeSpace, ' ');
    // Print the line
    cout << "| " << preText1 << level << postText1 << spaces << preText2 << experience << postText2 << " |" << endl;
}

void Player::PrintDivider(char edge, char filler, string centerText) {
    // Subtract space used in line (2 spaces for edge symbols, length of centerText) from the total available width
    size_t freeSpace = 35 - 2 - centerText.length();
    size_t frontSpace = freeSpace/2;
    size_t rearSpace = freeSpace - frontSpace;
    // Create a the front and rear filler string
    string frontFiller(frontSpace, filler);
    string rearFiller(rearSpace, filler);
    // Print the line
    cout << edge << frontFiller << centerText << rearFiller << edge << endl;
}
void Player::PrintClass() {           //print the player class in inventory format
    int freespace = 35;               //freespace is the amount of blank space in the beginning, backspace is the amount of blankspace after class name print
    int backspace = 0;
    std::cout << "| ";                //begin
    switch (player_type) {            // get class type and ouput the class name, class type variable is used (declaration located in player.h)
    case 1:                           //following comments are applied to all cases
        std::cout << "Warrior";       //output class name
        backspace = freespace - 10;   //get the amount of blank filler needed
        break;
    case 2:
        std::cout << "Rogue";
        backspace = freespace - 8;
        break;
    case 3:
        std::cout << "Healer";
        backspace = freespace - 9;
        break;
    case 4:
        std::cout << "Debugger";
        backspace = freespace -11;
        break;
    case 5:
        std::cout << "Saitama";
        backspace = freespace - 10;
        break;
    default:                       //default makes it warrior in accordance to character creation
        std::cout << "Warrior";
        backspace = freespace - 10;
        break;
    }
    string rear(backspace, ' ');     //create blank string for filler
    std::cout << rear << "|\n";      //output the filler and end
}
