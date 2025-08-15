# Squid Game: Glass Bridge (C)

A terminal-based C implementation of the **"Glass Bridge" game** from Squid Game. Players try to cross a glass bridge by stepping only on safe panels. The game features colored text, a life system, and interactive gameplay for a fun console experience.

---

## Table of Contents
- [About the Game](#about-the-game)
- [Rules](#rules)
- [Gameplay](#gameplay)
- [Requirements](#requirements)
- [How to Play](#how-to-play)
- [Author](#author)

---

## About the Game

This is a console game written in C. Inspired by the **Glass Bridge** game from Squid Game, three players (A, B, and C) attempt to cross a bridge composed of glass panels. Some panels are broken, and stepping on a broken panel costs a life and returns the player to the start.

---

## Rules

1. The bridge has **4 rows** and **10 columns** of glass panels.
2. Players are named **A**, **B**, and **C**.
3. Each player has **3 lives**.
4. Stepping on a **broken glass panel** causes the player to lose 1 life and return to the start.
5. Players with **0 lives** cannot continue.
6. The goal is to reach the **FINISH** line safely.

---

## Gameplay

- Safe panels are selected randomly.
- Broken panels are marked as **K** in red.
- Player positions are shown in **yellow**.
- Players take turns moving from column 1 to 10.
- If a player falls, others may advance based on game logic.

---

## Requirements

- A C compiler (GCC, Clang, or similar)
- Terminal or console capable of ANSI color codes

---

## How to Play

1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/squid-game-glass-bridge-c.git
2. Compile the program:

````bash
gcc glass_bridge.c -o glass_bridge

````
3. Run the game:

````bash
./glass_bridge

````
Follow the on-screen instructions. Press ENTER to progress through turns and see the bridge.

Author
---
Omer Cevher

Email: omerc3v@gmail.com GitHub: https://github.com/CevherOmer

Notes
---
This is a terminal-based game, so it is best played in a console window.

The game uses ANSI escape codes for colors, so make sure your terminal supports them.
