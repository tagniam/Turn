#include "../../include/Common.h"
#include "../../include/EnemyTypes/Wizard.h"

Wizard::Wizard() {
    name = "Wizard";
    ExperienceAmount = 80;
    CoinsDrop = Common::RandomInt(30, 79);
}

EnemyType Wizard::GetType() {
    return etWizard;
}

int Wizard::ReturnDamage() {
    return Common::RandomInt(20, 49);
}

int Wizard::ReturnRiskAttackDamage() {
    int selector = Common::RandomInt(0, 5);
    switch (selector) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 8;
        break;
    case 4:
    case 5:
        return 20;
        break;
    default:
        return 1;
        break;
    }
}

int Wizard::ReturnHealAmount() {
    return Common::RandomInt(10, 30);
}

std::string Wizard::GetIntro() {
    return "All hails Fireballs !!";
}
