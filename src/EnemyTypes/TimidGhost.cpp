#include "../../include/Common.h"
#include "../../include/EnemyTypes/TimidGhost.h"

TimidGhost::TimidGhost() {
    name = "Timid Ghost";
    ExperienceAmount = Common::RandomInt(10, 19);
    CoinsDrop = Common::RandomInt(1, 5);
}

EnemyType TimidGhost::GetType() {
    return etTimidGhost;
}

int TimidGhost::ReturnDamage() {
    int damage = Common::RandomInt(0, 2);
    int chance = Common::RandomInt(0, 1); // 50% chance
    if (chance == 0) {
        // TimidGhost musters courage
        damage += 5;
    }
    return damage;
}

int TimidGhost::ReturnRiskAttackDamage() {
    int chance = Common::RandomInt(0, 4);
    if (chance == 0) {
        return 10; // 20% chance
    } else {
        return 0;
    }
}

int TimidGhost::ReturnHealAmount() {
    return 2;
}

std::string TimidGhost::GetIntro() {
    int choice = Common::RandomInt(0, 1);
    if (choice == 0) {
        return "The room is brightly lit from all sides, but a shadow creeps up behind you...";
    } else {
        return "It approaches you slowly, as if mustering courage...";
    }
}
