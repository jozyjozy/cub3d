# Cub3D Project

The **Cub3D** project is part of the **École 42** curriculum. In this project, you will create a **3D engine** using **raycasting**. The goal is to develop a simple 3D game engine where you can navigate through a world represented by a 2D map, similar to early 3D games like **Doom** or **Wolfenstein 3D**.

This project will test your understanding of computer graphics, algorithms, and mathematics, and will involve creating a game engine from scratch in **C**.

## Project Description

In the **Cub3D** project, you will create a 3D world based on a 2D map and render it using **raycasting**. Raycasting is a technique where rays are cast from the player's position to the walls, and the intersections are projected onto the screen, creating the illusion of 3D space. The result is a simple 3D world where you can walk around, see walls, and interact with the environment.

### Key Components:
- **Raycasting**: The heart of the engine, used to render the 3D world by calculating the distance between rays and walls.
- **2D Map**: A map representing the environment in a grid-like structure, where each grid cell is either empty or a wall.
- **Player Controls**: Movement controls for the player, allowing them to walk, turn, and look around.
- **Texture Mapping**: Applying textures to the walls to give the illusion of 3D surfaces.
- **Projection**: Displaying the 3D world on the 2D screen with proper perspective.

## Features

- **Raycasting Engine**: Uses raycasting to simulate a 3D world from a 2D map.
- **Player Movement**: Supports moving the player around in the 3D world, including turning and moving forward/backward.
- **Wall Textures**: Renders walls with textures, giving depth and realism to the environment.
- **Floor and Ceiling Rendering**: Renders the floor and ceiling with a flat color or texture.
- **Mouse and Keyboard Controls**: User input for player control, including movement and view direction adjustments.
- **Minimalistic 3D World**: A grid-based map with walls and open spaces to explore.

## Technologies Used

- **C**: The project is implemented in the C programming language.
- **MinilibX**: A graphics library used for rendering, drawing images, and handling user input (keyboard and mouse).
- **Math Functions**: Various mathematical operations are used for raycasting and geometry calculations.
- **Linux OS**: The project is designed to be compiled and run on a Linux system, using the gcc compiler.
