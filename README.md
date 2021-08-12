# FarOut
An Open Source 2D Space Game Library for SFML 

Amila Ferron, Mack Foggia, Taylor Noah, and Jeffrey Jernstrom 2021

## Overview

This repository contains a library that extends SFML to provide functionality to create simple 2D space-themed games. It includes a data structure of scenes, methods for navigation between the scenes, menu creation, and graphical elements including a ship, astronomical bodies, and an infinite background of stars.

### Context Control System

The "Context Control System" addresses the need for a game's overall structure and manages game resources at the highest level. It provides basic "system calls" for the scenes, switches between scenes, and generates the main game loop. 

### Graphics

Scenes are populated with a collection of example game objects and graphical elements. Game objects include a ship, alien ship, and other objects potentially found in space and are made using SFML's graphics module including sprites, shapes, and textures. 
### Data

Scenes are organized in a data structure and information for each session stored externally.


## Build Instruction

### Linux

Clone the FarOut repo to your local machine
~~~
git clone https://github.com/SpaceGameTeam/FarOut <destination>
~~~

Download and install SFML <a href=https://www.sfml-dev.org/tutorials/2.5/start-linux.php>here</a>.

Run the provided Makefile in project directory then run the executable.
~~~
>make FarOut

>./FarOut
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


## Project Roadmap

### Prototype

The project demo will consist of a single scene where a ship is controlled by a player to move across a starfield background encountering other game objects. This will be completed by the end of week 3.

### Minimum Viable Product

A completed project will include, at least, a "Context Control System" to navigate through the scenes, multiple levels of play, menus, a looping background of stars, a ship, and another game object of our choosing. This will be completed by the end of week 6.

### Post-class Plans

After the course is completed, the range of characters and game objects will be expanded and features will be added to allow saving a user's games and information and move into to multi-player networking.


## Related Works

[ÖbEngine](https://github.com/ObEngine/ObEngine) is a free and open-source 2D game engine.

[Vigilante](https://github.com/gamepopper/Vigilante-Game-Framework) Framework (or VFrame for short) is a high level framework built to run with SFML to make 2D games with basic 3D rendering.

[The Nero Game Engine version II](https://github.com/NeroGames/Nero-Game-Engineu), is a Professional 2D Game Engine built around SFML and Box2D.

[xygine](https://github.com/fallahn/xygine) 2D Game Engine Framework built around SFML.

[SFML Utils](https://github.com/Krozark/SFML-utils) provides extra utilities to the SFML library for game development.

[SDL](https://www.libsdl.org/) Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

We found a few other projects scattered about, but they are incomplete and inactive.

## Acknowledgments 

[SFML](https://github.com/SFML/SFML) is a simple, fast, cross-platform and object-oriented multimedia API. It provides access to windowing, graphics, audio and network. It is written in C++, and has bindings for various languages such as C, .Net, Ruby, and Python.

Thank you to Bart Massey, especially with debugging.