# cub3D

![C](https://img.shields.io/badge/Language-C-A8B9CC?style=flat-square&logo=c&logoColor=white)
![42 Network](https://img.shields.io/badge/42-Network-black?style=flat-square&logo=42)
![Linux](https://img.shields.io/badge/Platform-Linux-FCC624?style=flat-square&logo=linux&logoColor=black)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-blue?style=flat-square)
![Raycasting](https://img.shields.io/badge/Rendering-Raycasting-orange?style=flat-square)

## Overview

cub3D is a first-person 3D graphical engine written in C as part of the **1337 Coding School — 42 Network** curriculum, inspired by the classic Wolfenstein 3D game.

The project uses raycasting to transform a two-dimensional map into an interactive, textured 3D environment, rendered using MiniLibX.

It provides practical experience with computer graphics, mathematics, geometry, memory management, event handling, and real-time rendering.

## Features

### Mandatory

- Real-time 3D rendering using raycasting
- Direction-based wall textures
- Configurable floor and ceiling colors
- Player movement and camera rotation
- Wall collision detection
- Map parsing and validation
- XPM texture loading
- Keyboard and window event handling

### Bonus

- Circular minimap
- Mouse-controlled camera rotation
- Interactive doors
- Sky texture
- Animated weapon
- Enhanced visual experience

## Rendering Pipeline

The application transforms a 2D map into a first-person 3D environment through the following stages:

```text
.cub Scene File
       │
       ▼
Parsing & Validation
       │
       ▼
Player & Texture Initialization
       │
       ▼
Raycasting
       │
       ▼
Wall Intersection & Distance Calculation
       │
       ▼
Fish-eye Correction
       │
       ▼
Texture Mapping
       │
       ▼
Frame Rendering
       │
       ▼
MiniLibX Window
```

The renderer casts rays across a 60-degree field of view, calculates horizontal and vertical wall intersections, determines the nearest intersection, and corrects projected distances to prevent fish-eye distortion.

The resulting distances are used to calculate wall heights and render textured vertical slices into an off-screen image before displaying the final frame.

## Getting Started

### Requirements

- Linux operating system
- C compiler (`cc`)
- GNU Make
- X11 development libraries
- MiniLibX for Linux

### Install Dependencies

On Debian or Ubuntu:

```bash
sudo apt update
sudo apt install build-essential libx11-dev libxext-dev
```

### Install MiniLibX

If MiniLibX is not already included in the repository:

```bash
git clone https://github.com/42Paris/minilibx-linux.git
make -C minilibx-linux
```

MiniLibX must be located in the `minilibx-linux/` directory at the repository root.

### Build

Compile the mandatory version:

```bash
make
```

Compile the bonus version:

```bash
make bonus
```

The included `libft` library is built automatically.

### Run

Launch the mandatory version:

```bash
./cub3D maps/test.cub
```

Launch the bonus version:

```bash
./cub3D_bonus maps/dungeon.cub
```

The program accepts exactly one `.cub` scene file.

Run the executables from the repository root to ensure relative texture and asset paths are resolved correctly.

## Controls

| Input | Mandatory | Bonus |
|---|---|---|
| `W` / `S` | Move forward / backward | Move forward / backward |
| `A` / `D` | Strafe left / right | Strafe left / right |
| Left / Right arrows | Rotate camera | — |
| Mouse movement | — | Rotate camera |
| `E` | — | Open or close a nearby door |
| Left mouse button | — | Play weapon animation |
| `Esc` | Exit | Exit |
| Window close button | Exit | Exit |

## Map Configuration

Each `.cub` file contains wall texture paths, floor and ceiling colors, and a two-dimensional map.

### Example

```text
NO textures/N.xpm
SO textures/S.xpm
WE textures/W.xpm
EA textures/E.xpm

F 30,30,30
C 120,170,220

1111111
1000001
10N0001
1000001
1111111
```

### Configuration Identifiers

| Identifier | Description |
|---|---|
| `NO` | North-facing wall texture |
| `SO` | South-facing wall texture |
| `WE` | West-facing wall texture |
| `EA` | East-facing wall texture |
| `F` | Floor RGB color |
| `C` | Ceiling RGB color |

### Map Symbols

| Symbol | Description |
|---|---|
| `1` | Wall |
| `0` | Walkable space |
| `N` | Player facing north |
| `S` | Player facing south |
| `E` | Player facing east |
| `W` | Player facing west |
| `D` | Interactive door (bonus only) |
| Space | Empty padding outside the map |

### Map Validation Rules

- The map must be fully enclosed by walls.
- Exactly one player spawn must exist.
- All required configuration identifiers must appear exactly once.
- RGB values must be between `0` and `255`.
- Texture files must use the `.xpm` extension.
- Invalid map characters are rejected.

## Project Structure

```text
cub3D/
├── mandatory/
├── bonus/
├── libraries/
│   ├── libft/
│   └── getline/
├── minilibx-linux/
├── maps/
├── textures/
├── Makefile
└── README.md
```

| Directory | Responsibility |
|---|---|
| `mandatory/` | Core parser, raycasting engine, renderer, and movement |
| `bonus/` | Extended rendering and interactive features |
| `libraries/libft/` | Custom C utility functions |
| `libraries/getline/` | Scene file reading |
| `minilibx-linux/` | Graphics library |
| `maps/` | Valid and invalid test scenes |
| `textures/` | Wall, door, sky, splash, and weapon assets |

## Makefile Commands

| Command | Description |
|---|---|
| `make` | Build the mandatory version |
| `make bonus` | Build the bonus version |
| `make clean` | Remove object files |
| `make fclean` | Remove generated files and executables |
| `make re` | Rebuild the mandatory version |

## Technical Concepts

Throughout this project, we explored:

- Raycasting algorithms
- Trigonometry and vector mathematics
- Coordinate systems
- Horizontal and vertical ray intersections
- Distance correction and 3D projection
- Texture mapping
- Pixel manipulation
- Real-time rendering
- Collision detection
- Keyboard and mouse event handling
- File parsing and validation
- Dynamic memory management

## Technologies

- **C** — Core application and rendering logic
- **MiniLibX** — Window management and graphics rendering
- **X11** — Linux windowing system
- **Makefile** — Build automation
- **Libft** — Custom C utility library

## Authors

Developed collaboratively by:

- **Bouhcine Amezouar** — `bamezoua` — [GitHub](https://github.com/BouhcineAmezouar7) · [Portfolio](https://bamezoua.vercel.app/)
- **Youssef Bounite** — `ybounite` — [GitHub](https://github.com/ybounite/)

---

Developed as part of the **1337 Coding School — 42 Network** curriculum.
