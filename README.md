# FarOut
An Open Source 2D Game Library for SFML 

Amila Ferron, Mack Foggia, Taylor Noah, and Jeffrey Jernstrom 2021


## Overview

FarOut is a library that extends [SFML](https://www.sfml-dev.org/) to make creation of simple 2D games and apps easier. It includes a data type to represent different levels or rooms, called Scenes, and methods for management and navigation between the Scenes. Further, it includes a framework for a data type for objects within Scenes, with collision detection being a planned feature. FarOut also manages the game loop and the window for you, and includes a globally accesible data management system, which in the future will be saved and loaded easily between sessions.

Also included in this repo is an extensive demo of FarOut, in the form of a space game. It features a controllable ship, an AI controlled ship, astronomical bodies, and a starry background. This is here to give you a taste of what is easily attainable using FarOut and SFML.

### Context Control System

The "Context Control System" addresses the need for a game's overall structure and manages game resources at the highest level. It provides basic "system calls" for the scenes, switches between scenes, and generates the main game loop. Scenes that you wish to be actively displayed are pushed onto a stack, so that you can have multiple active scenes. This becomes useful if you wanted to draw a menu on top of an active game scene for example.

### Graphics

Scenes are populated with a collection of example game objects and graphical elements. Game objects in our demo include a ship, alien ship, and other objects potentially found in space and are made using SFML's graphics module including sprites, shapes, and textures. 


## Operation Demo

We've compiled a short video to give you an overview of the project so far, find that [here](youtube.com).

## Project Roadmap

### Prototype

The project demo will consist of a single scene where a ship is controlled by a player to move across a starfield background encountering other game objects. This will be completed by the end of week 3.

### Minimum Viable Product

A completed project will include, at least, a "Context Control System" to navigate through the scenes, multiple levels of play, menus, a looping background of stars, a ship, and another game object of our choosing. This will be completed by the end of week 6.

### Post-class Plans

After the course is completed, the range of characters and game objects will be expanded and features will be added to allow saving a user's games and information and move into to multi-player networking.


## Build Instruction

### Linux

Clone the FarOut repo to your local machine
~~~
git clone https://github.com/SpaceGameTeam/FarOut <destination>
~~~

Download and install SFML <a href=https://www.sfml-dev.org/tutorials/2.5/start-linux.php>here</a>.

<!-- Run the provided Makefile in project directory then run the executable. -->
~~~

Either install on your system with

>make install 

or use the library locally, in which case place the FarOut library subdirectory in the directory with your files.


To include the library, place 

#include "FarOut/FarOut.h"

in your header file.


See the demo with

>make demo

>./demo

<!-- Do we have make run-demo? -->


To uninstall, run

>make uninstall


~~~

### Windows  
These instructions are specifically for use with Microsoft Visual Studio  
The general instructions for SFML can be found [here](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) with useful snapshots.  
1) Download and install the most recent Visula Studio SFML install [here](https://www.sfml-dev.org/download/sfml/2.5.1/)  
2) Open Visual Studio and create a new project.  
3) In the Project pull down, choose the bottom most option. It should be called "[Your Project Name] Properties"  
4) Click the "C/C++" option in the sidebar.  
5) To the right, add the file path of the "include" file of your SFML file to the "Additional Include Directories" and click apply.  
6) In the sidebar click "Linker"  
7) Add the file path of the  "lib" file of your SFML file to the "Additional Library Directories". Click apply.
8) In the side bar under Linker, click "Input".   
9) Add "sfml-graphics.lib", "sfml-system.lib", "sfml-window.lib", and "sfml-audio.lib" into "Additional Libraries". Click apply.  
10) Copy all the .dll files in the "bin" file of your SFML file to your project folder.  
11) In the git pull down, click "clone repository" and enter: "https://github.com/SpaceGameTeam/FarOut.git"  

You should be able to run it now! But Just in case, here are some tips:
- Try both the 32bit and the 64 bit SFML install. The SFML website says use 32bit unless you have good reason to use 64bit.
- Ensure you did not install SFML into a protected folder. It is reccomended to install SFML into C:\.


## Documentation

Our documentation for developers is available in the [wiki](https://github.com/SpaceGameTeam/FarOut/wiki)!


## License

FarOut is available under the MIT License, which you can find in our repo [here](https://github.com/SpaceGameTeam/FarOut/blob/dev/LICENSE).


## Related Works

[ÖbEngine](https://github.com/ObEngine/ObEngine) is a free and open-source 2D game engine.

[Vigilante](https://github.com/gamepopper/Vigilante-Game-Framework) Framework (or VFrame for short) is a high level framework built to run with SFML to make 2D games with basic 3D rendering.

[The Nero Game Engine version II](https://github.com/NeroGames/Nero-Game-Engineu), is a Professional 2D Game Engine built around SFML and Box2D.

[xygine](https://github.com/fallahn/xygine) 2D Game Engine Framework built around SFML.

[SFML Utils](https://github.com/Krozark/SFML-utils) provides extra utilities to the SFML library for game development.

[SDL](https://www.libsdl.org/) Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.


## Acknowledgments 

[SFML](https://github.com/SFML/SFML) is a simple, fast, cross-platform and object-oriented multimedia API. It provides access to windowing, graphics, audio and network. It is written in C++, and has bindings for various languages such as C, .Net, Ruby, and Python. FarOut is built on top of SFML, and some of our class and function designs are inspired by information in the fantastic SFML documentation.

[OneLoneCoder](https://github.com/OneLoneCoder) has created many useful YouTube tutorials on 2D shape collision detection. We implemented his Diagonals based hitbox detection in our project. OneLoneCoder makes other very useful and well presented tutorials on a myriad of programming topics. Check out his [youtube channel](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA)! 

The font used in the demo and for the FPS counter is licensed as freeware and was designed by Wahyu Eka Prasetya! It's called Area Kilometer 50 and can be found [here](https://www.fontspace.com/a-area-kilometer-50-font-f53888).

The starry background used in the demo was made by [Necro-Skeletal](https://www.deviantart.com/necro-skeletal) and can be found [here](https://www.deviantart.com/necro-skeletal/art/Pixelated-Halo-Starfield-313220165).

Thank you for Bart Massey's support, especially with debugging.

## Work Summary

During our class-directed development period, the work was roughly divided as follows. Most design decisions were discussed and contributed to as a team, so this breakdown is mostly concerning actual implementation. 

Amila Ferron -  Demo development (PrototypeScene, Ship, AlienShip, PlanetarySystem, movement), Linux install/include process

Mack Foggia - System implementation (Scene, SystemClass, game loop, window management, FPS counter), demo content (ship movement, starry background)

Jeffrey Jernstrom - Team leader and project organizer, Scene data structures and management, Data Storage module, Menu stuff (in development), Makefile

Taylor Noah - 
