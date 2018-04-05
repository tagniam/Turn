# Turn
Turn is a basic turn-based RPG game written in C++ for Windows. 
11

## History
I wrote this game almost 5 years ago, and uploading it to GitHub was my first experience with open source. Now, I want to give back to the community for [Hacktoberfest 2017](https://hacktoberfest.digitalocean.com/) and encourage everyone, regardless of programming skills or knowledge, to contribute! :)  

## Screenshots

![Battle screen](screenshots/battle.png)
![Menu screen](screenshots/menu.png)

## How To Play

Turn is a turn-based RPG game. Create your character and start playing. For playing you have to choose what to do by typing the corresponding number. You can perform actions and use items.

### Actions
* **Attack**: Regular attack
* **Risk Attack**: Attack deals more damage, but with a chance of missing
* **Heal**: Restore an amount of your HP
* **Flee**: Run away from battle

### Items
* **Bombs**: Deals 50HP to your opponent with no chance of missing
* **Arrows**: Deals 10-15HP to your opponent with no chance of missing
* **Potion**: Replenishes your HP to 100
* **Whetstone**: Restores your weapon's sharpness.

### Player Classes
| Name     | Attack Damage | Risk Attack Damage | Healing Amount |
|----------|---------------|--------------------|----------------|
| Warrior  |      0-20     |        0-20        |      1-10      |
| Rogue    |      7-12     |        1-10        |      6-12      |
| Healer   |      5-10     |        5-10        |      7-15      |
| Debugger |      100      |         100        |       100      |
| Saitama  |    9999999    |       9999999      |     9999999    |

### Enemy Types
| Name        | Attack Damage | Risk Attack Damage | Healing Amount | Experience Amount | Coins Drop |
|-------------|---------------|--------------------|----------------|-------------------|------------|
| Crab        |      1-10     |        2-15        |      1-11      |         20        |    0-49    |
| Giant Crab  |      7-14     |        0-20        |      5-11      |        100        |    0-99    |
| Squid       |      1-10     |        2-15        |      1-11      |         20        |    0-49    |
| Giant Squid |      7-14     |        0-20        |      5-11      |         50        |    0-99    |
| Lich        |      5-24     |        2-30        |      5-29      |        100        |   50-149   |

## Getting Started
### Prerequisites
* Note: Turn only supports Windows at the moment  

## Contributing
* Before working on an issue, make sure you comment on it to claim it. This prevents two people working on the same issue at the same time.

## License
* This project is licensed under the MIT License - see the LICENSE file for details.

