# 🎮 Brick Breaker - Game Project

A classic **Brick Breaker** game implementation in C++ using the CMU Graphics Library. This project demonstrates object-oriented design principles, collision detection, and game state management.

---

## 📋 Table of Contents

- [Features](#features)
- [Project Architecture](#project-architecture)
- [Project Structure](#project-structure)
- [System Requirements](#system-requirements)
- [Installation & Setup](#installation--setup)
- [Building the Project](#building-the-project)
- [How to Play](#how-to-play)
- [Controls](#controls)
- [Game Mechanics](#game-mechanics)
- [Design Patterns](#design-patterns)
- [Contributing](#contributing)

---

## ✨ Features

### Core Gameplay
- ✅ **Classic Brick Breaker Mechanics** - Bounce the ball to destroy bricks
- ✅ **Multiple Brick Types** - Normal, Hard, Rock, Bomb, Prism, and Power bricks
- ✅ **Paddle Control** - Move and position paddle to reflect the ball
- ✅ **Physics System** - Ball reflection and collision detection
- ✅ **Lives System** - Start with 3 lives, lose one when ball falls

### Game Modes
- 🎨 **Design Mode** - Customize brick layouts before playing
- 🎯 **Play Mode** - Classic brick-breaking gameplay
- 💾 **Save/Load** - Save custom levels and load them later

### Power-ups & Collectables
- 🌪️ **Wind Glide** - Paddle moves faster
- 📏 **Wide Paddle** - Paddle becomes wider for easier blocking
- 🔥 **Fireball** - Ball ignores brick collision
- ↩️ **Reverse Paddle** - Paddle controls are reversed

### UI Elements
- 📊 **Score Tracking** - Earn points by destroying bricks
- ⏱️ **Timer** - Track elapsed game time
- ❤️ **Lives Display** - Visual heart indicators
- 📢 **Status Bar** - Real-time game notifications

---

## 🏗️ Project Architecture

### Design Pattern: **Object-Oriented Design**

The project follows a hierarchical class structure:

```
drawable (Base: Rendering)
    ↓
collidable (Physics: Collision Detection)
    ├── Ball (Game Entity)
    ├── Paddle (Player Control)
    ├── Brick (Obstacle)
    │   ├── normalBrick
    │   ├── hardBrick
    │   ├── RockBrick
    │   ├── bombBrick
    │   ├── BrismBrick
    │   └── PowerBrick
    └── Collectable (Power-ups)
        ├── WindGlide
        ├── WidePaddle
        ├── fireball
        └── ReversePaddle
```

### Key Components

| Component | Responsibility |
|-----------|-----------------|
| **game** | Central game engine, state management, event loop |
| **Ball** | Ball physics, movement, collision |
| **Paddle** | Paddle movement, collision with ball, active effects |
| **grid** | Brick matrix management, collision detection |
| **toolbar** | UI buttons and game mode controls |
| **drawable** | Base rendering interface |
| **collidable** | Collision detection and physics |

---

## 📁 Project Structure

```
CIE202-project-final-master/
│
├── src/                              # All source code
│   ├── main.cpp                      # Program entry point
│   │
│   ├── Core/                         # Game engine & configuration
│   │   ├── game.h                    # Main game class declaration
│   │   ├── game.cpp                  # Game logic implementation
│   │   ├── gameConfig.h              # Global game configuration
│   │   └── DEFS.h                    # Global definitions & enums
│   │
│   ├── Base/                         # Abstract base classes
│   │   ├── drawable.h / .cpp         # Base rendering class
│   │   └── collidable.h / .cpp       # Collision detection + Paddle
│   │
│   ├── GameObjects/                  # Game entities
│   │   ├── ball.h / .cpp             # Ball physics & behavior
│   │   ├── Bricks.h / .cpp           # All brick type implementations
│   │   └── collactable.h / .cpp      # Power-ups & collectables
│   │
│   └── UI/                           # User interface
│       ├── toolbar.h / .cpp          # UI toolbar & icon buttons
│       └── grid.h / .cpp             # Brick grid management
│
├── CMUgraphicsLib/                   # Graphics rendering library
│   ├── CMUgraphics.h / .cpp          # Core graphics API
│   ├── keypads.h                     # Keyboard input management
│   ├── mousequeue.h                  # Mouse input handling
│   └── [Other library files]
│
├── images/                           # Game assets
│   ├── Bricks/                       # Brick textures
│   ├── collectables/                 # Power-up icons
│   └── ToolbarIcons/                 # UI button icons
│
├── Shapes/                           # Utility shape rendering
│
├── CIE202-project.sln                # Visual Studio solution
├── CIE202-project.vcxproj            # VC++ project configuration
│
├── load.txt                          # Default level configuration
├── savefile.txt                      # Saved level data
├── REORGANIZATION_GUIDE.md           # Folder structure documentation
└── README.md                         # This file
```

---

## 🔧 System Requirements

### Minimum Requirements
- **OS:** Windows 7 or later
- **Compiler:** Visual Studio 2015 or newer (with C++11 support)
- **RAM:** 512 MB
- **Disk Space:** 50 MB

### Dependencies
- **CMU Graphics Library** - Included in project
- **Windows API** - For graphics and input handling
- **C++ Standard Library** - STL containers and algorithms

---

## 📥 Installation & Setup

### Step 1: Clone or Download
```bash
# Clone the repository
gh repo clone nadamohamed1230/brick-breaker-oop-cpp
```

### Step 2: Open Project in Visual Studio
```
File → Open → Project/Solution
Navigate to: CIE202-project.sln
```

### Step 3: Configure Include Paths
In Visual Studio:
1. Right-click project → **Properties**
2. Go to **VC++ Directories**
3. Add to **Include Directories:**
   ```
   ./CMUgraphicsLib
   ./src
   ```

### Step 4: Verify Build Configuration
- Select **Debug** or **Release** configuration
- Platform: **Win32**

---

## 🔨 Building the Project

### Option 1: Visual Studio IDE
1. Press **Ctrl + Shift + B** to build solution
2. Or: Build → Build Solution

### Option 2: Command Line (CMake - if configured)
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Output
- **Debug:** `Debug/CIE202-project.exe`
- **Release:** `Release/CIE202-project.exe`

---

## 🎮 How to Play

### Game Startup
1. Run the executable
2. Game launches in **Design Mode**
3. The window shows a toolbar at the top and empty grid below

### Design Mode (Level Creation)
1. Click toolbar icons to add different brick types
2. **Click grid cells** to place bricks
3. **Right-click** to stop placing bricks
4. Icons available:
   - Normal Brick (1 hit)
   - Hard Brick (3 hits)
   - Rock Brick (indestructible)
   - Bomb Brick (destroys adjacent bricks)
   - Prism Brick (5 points)
   - Power Brick (drops power-ups)

### Play Mode
1. Click the **Play** button to start
2. Press **SPACEBAR** to launch the ball
3. Use **LEFT/RIGHT ARROW KEYS** to move the paddle
4. Destroy all bricks to win
5. Game ends when lives reach 0

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| **SPACE** | Launch/Release ball |
| **LEFT ARROW** | Move paddle left |
| **RIGHT ARROW** | Move paddle right |
| **LEFT MOUSE CLICK** | Place brick (Design Mode) / Select toolbar (Play Mode) |
| **RIGHT MOUSE CLICK** | Stop placing bricks / Cancel action |

### Toolbar Buttons

| Button | Mode | Action |
|--------|------|--------|
| Brick Icons | Design | Add brick types |
| 💾 Save | Design | Save current level |
| 🗑️ Delete | Design | Remove bricks |
| ▶️ Play | Design | Start game with current level |
| ⏸️ Pause | Play | Pause the game |
| ▶️ Continue | Play | Resume paused game |
| ⏹️ Stop | Play | Return to Design Mode |
| ⏱️ Timer | Play | Display elapsed time |
| 📊 Score | Play | Display current score |
| ❌ Exit | Both | Quit game |

---

## 🎲 Game Mechanics

### Scoring System
| Action | Points |
|--------|--------|
| Destroy Normal Brick | 1 point |
| Destroy Hard Brick | 1 point per hit |
| Destroy Rock Brick | 0 points (indestructible) |
| Destroy Bomb Brick | Bonus (clears nearby) |
| Destroy Prism Brick | 5 points |
| Collect Power-up | Bonus effect |

### Collision Detection
- **Ball-Paddle:** Ball reflects based on collision point
- **Ball-Brick:** Ball bounces off brick surface
- **Ball-Screen:** Ball reflects at screen boundaries
- **Collectable-Paddle:** Activates power-up effect

### Physics
- Ball uses vector-based movement
- Reflection calculated based on collision angles
- Paddle width affects ball trajectory
- Power-ups modify paddle behavior temporarily (60-120 seconds)

### Lives System
- Start with **3 lives**
- Lose 1 life when ball falls below paddle
- Game Over when lives = 0
- Victory when all destructible bricks destroyed

---

## 🏛️ Design Patterns

### 1. **Inheritance Hierarchy**
```cpp
drawable (base)
    └── collidable (intermediate)
        ├── ball
        ├── brick (abstract)
        │   ├── normalBrick
        │   ├── hardBrick
        │   └── ...
        └── Collectable
            ├── WindGlide
            └── ...
```

### 2. **Factory Pattern (Brick & Collectable Creation)**
```cpp
switch(brickType) {
    case BRK_NRM:
        brick = new normalBrick(...);
        break;
    // ...
}
```

### 3. **State Pattern (Game Modes)**
```cpp
enum MODE { MODE_DSIGN, MODE_PLAY };
```

### 4. **Observer Pattern (Collision Callbacks)**
```cpp
void collisionAction() override;  // Pure virtual function
```

---

## 🔄 Game Loop Flow

```
1. INITIALIZATION
   ├── Create window
   ├── Initialize toolbar
   ├── Create grid
   ├── Create ball & paddle
   └── Set up collectables array

2. MAIN LOOP
   ├── READ INPUT
   │   ├── Mouse clicks on toolbar
   │   └── Keyboard input (arrows, space)
   │
   ├── UPDATE STATE
   │   ├── Move ball
   │   ├── Check collisions
   │   ├── Handle power-ups
   │   └── Update score/lives
   │
   └── RENDER
       ├── Clear screen
       ├── Draw grid
       ├── Draw ball & paddle
       ├── Draw collectables
       ├── Update status bar
       └── Refresh display

3. GAME END
   ├── Check win condition
   ├── Check lose condition
   └── Return to Design Mode or Exit
```

---

## 👥 Contributing

### Code Style Guidelines
- Use **camelCase** for variables and functions
- Use **PascalCase** for classes
- Add comments for complex logic
- Keep functions under 50 lines when possible
- Use meaningful variable names

### To Extend the Project

#### Adding New Brick Type:
1. Create class in `GameObjects/Bricks.h`
2. Inherit from `brick` class
3. Implement `collisionAction()` and `type()`
4. Add to `BrickType` enum
5. Add creation case in `grid::addBrick()`

#### Adding New Power-up:
1. Create class in `GameObjects/collactable.h` (inherit from `Collectable`)
2. Implement `draw()`, `collisionAction()`, `move()`
3. Add to `CollectableType` enum
4. Update `game::pCollactable()` factory method

---

## 📝 File Size Reference

| Component | Files | Lines of Code |
|-----------|-------|----------------|
| Core | 4 | ~600 |
| Base | 4 | ~400 |
| GameObjects | 6 | ~800 |
| UI | 4 | ~600 |
| CMU Graphics | 10+ | 5000+ |
| **Total** | **28+** | **~7400+** |

---

## 🐛 Known Issues & Limitations

- Rock Bricks cannot be destroyed (by design)
- Power-up collision only on paddle (not stored)
- Max 50 concurrent collectables
- Screen resolution fixed at 1200x600
- No multiplayer mode
- No difficulty levels (only custom level design)

---

## 🎓 Learning Outcomes

This project demonstrates:
- ✅ Object-Oriented Programming (OOP) principles
- ✅ Inheritance and polymorphism
- ✅ Collision detection algorithms
- ✅ Game state management
- ✅ Event-driven programming
- ✅ Physics simulation (reflection, velocity)
- ✅ Memory management (dynamic allocation/deallocation)
- ✅ File I/O operations (save/load levels)

---

## 📚 References & Resources

- **CMU Graphics Library Documentation:** See `CMUgraphicsLib/Manual.txt`
- **C++ Reference:** https://cplusplus.com/
- **Game Development:** https://www.gamedev.net/

---

## 📄 License

This project is provided for educational purposes as part of the CIE202 course.

---

## 👨‍💻 Authors & Acknowledgments

- **Project:** CIE202 - Brick Breaker Game
- **Developers:** Nada Mohamed Alfeky, Dolagy George, Mariam Mostafa
- **Institution:** Zewail City University of Science and Technology
- **Course:** CIE202 - Object-Oriented Programming

---

## 📞 Support & Contact

**Project Developers:**
- **Lead Developer:** Nada Mohamed Alfeky
- **Email:** s-nada.alfeky@zewailcity.edu.eg
- **GitHub Repository:** https://github.com/nadamohamed1230/brick-breaker-oop-cpp

**For issues or questions:**
1. Visit the GitHub repository
2. Check `REORGANIZATION_GUIDE.md` for project structure details
3. Review comments in source files
4. Consult CMU Graphics Library documentation

---

**Last Updated:** April 10, 2026  
**Version:** 2.0 (Reorganized)  
**Build Status:** Ready to Compile

---


**Enjoy the game! 🎮**
