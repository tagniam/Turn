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
* In your terminal, make sure you are in the `Turn` directory.
* For the right generator see [Visual Studio Generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators)
* To build with Visual Studio 16 2019 run the following commands:

    ```shell
    $ cmake -S . -B build -G "Visual Studio 15 2017"
    $ cmake --build build
    ```
* Start the game by running `build\Turn.exe`.

Alternative: Generate solution with CMake and build with Visual Studio

* Run CMake on the `Turn` directory to generate a `.sln` solution file for Visual Studio. You can find a tutorial [here](https://cmake.org/runningcmake/).

    ```shell
    $ cmake -S . -B build -G "Visual Studio 15 2017"
    ```

* Run Visual Studio and open the generated `.sln` solution file.
* Build the project by clicking `Build` -> `Build Solution`.
* Start the game by clicking the green Run button in the toolbar.

#### Mac/Linux
* In your terminal, make sure you are in the `Turn` directory.
* Run the following commands:

    ```shell
    $ cmake -S . -B build
    $ cmake --build build
    ```
* Start the game by running `./build/Turn`.

### Playing
See the game manual located in the [wiki](https://github.com/tagniam/Turn/wiki).

## Contributing
* Please read over the [Code of Conduct](https://github.com/tagniam/Turn/blob/master/CODE_OF_CONDUCT.md) before contributing!

## License
* This project is licensed under the MIT License - see the LICENSE file for details.

