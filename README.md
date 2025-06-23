# 🪟 Glass Bridge Game

A suspenseful terminal-based game written in C++ where players must choose between two glass panels — one tempered, one annealed — to cross a bridge. The wrong choice results in a player being sacrificed. Inspired by the psychological thrill of survival games.

## 🎮 Game Description

You begin with **10 players** and face a bridge made of **18 pairs** of glass panels — one on the **left**, one on the **right** in each pair. Only **one side** per pair is safe. Your goal? Get as many players across as possible.

Each turn, you’ll choose **Left (L)** or **Right (R)**. A correct guess lets the player cross safely. A wrong guess costs a life.

Choose wisely. Your choices are final. No second chances.

## 🛠️ Features

- Randomized bridge layout each game
- Visual representation of the bridge and player positions
- Decreasing player count with each failed step
- Win or lose conditions based on survival

## 📦 File Structure

```bash
glass_bridge_game.cpp   # Main game logic
README.md               # Game instructions and description
