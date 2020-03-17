# Turn: Hacktober 'n' Slash [![Build Status](https://travis-ci.org/tagniam/Turn.svg?branch=master)](https://travis-ci.org/tagniam/Turn)
Turn is a turn-based terminal RPG game written in C++. Contributions are encouraged, especially during [Hactkoberfest](https://hacktoberfest.digitalocean.com/)!

## Screenshots

![Battle screen](screenshots/battle.png)
![Menu screen](screenshots/menu.png)

## Getting Started
### Prerequisites
* CMake (https://cmake.org)
* SDL2 (https://www.libsdl.org/) for Mac/Linux users
  * Install with `brew install sdl2` for Mac users
  * Install with `sudo apt install libsdl2-dev libsdl2-mixer-dev` for Linux users

### Cloning
Clone this project by running `git clone https://github.com/tagniam/Turn.git` in your terminal.

### Building & Running
#### Windows
* Run CMake on the `Turn` directory to generate a `.sln` solution file for Visual Studio. You can find a tutorial [here](https://cmake.org/runningcmake/).
* Run Visual Studio and open the generated `.sln` solution file.
* Build the project by clicking `Build` -> `Build Solution`.
* Start the game by clicking the green Run button in the toolbar.

#### Mac/Linux
* In your terminal, make sure you are in the `Turn` directory.
* Run the following commands:

    ```shell
    $ cmake .
    $ make
    ```
* Start the game by running `./Turn`.

### Playing
See the game manual located in the [wiki](https://github.com/tagniam/Turn/wiki).

## Contributing
* Before working on an issue, make sure you comment on it to claim it. This prevents two people working on the same issue at the same time.

## License
* This project is licensed under the MIT License - see the LICENSE file for details.

