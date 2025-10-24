```text
 _  _  ____                      _                   
| || ||___ \ _   ___  ___       | | ___  _ __   __ _ 
| || |_ __) (_) / __|/ _ \ _____| |/ _ \| '_ \ / _` |
|__   _/ __/ _  \__ \ (_) |_____| | (_) | | | | (_| |
   |_||_____(_) |___/\___/      |_|\___/|_| |_|\__, |
                                               |___/    
```

### **Overview**

A 2D top-down game built using the MiniLibX graphical library

---

### **Learnings**
- How to use Minilibx graphic library
- Map validation techniques (e.g., Flood Fill)
- How to turn spritesheet images into animation

---

### **About**

👉 [**Project requirement**](https://github.com/Mecha-Coder/42-so-long/blob/main/demo/en.subject.pdf)

This is a simple 2D game where the player controls an avatar using the keyboard. The goal is to collect all collectibles and reach the exit door to finish the level.

The game includes:
- Collision detection — players cannot walk through walls.
- Collectible tracking — the exit unlocks only after collecting all items.
- Enemies — colliding with one ends the game

Before rendering, the program reads and validates the game map (a .ber text file). During validation, it ensures the map follows specific rules such as having valid walls, paths, and objects. After validation, the program uses MiniLibX to load textures and render the game environment.

---

### **Demo**

![demo](https://github.com/Mecha-Coder/42-so-long/blob/main/demo/demo.gif)

---

### **How to run**

System requirement: **Debian/Ubuntu/WSL2**


```bash
# Install dependencies
sudo apt-get install libx11-dev libxext-dev libbsd-dev libxrandr-dev libxfixes-dev

# Clone the repository
git clone https://github.com/Mecha-Coder/42-so-long
cd 42-so-long

# Compile the program
make bonus

# Launch the game and specify the map
# Try different maps from the maps/good folder
./so_long ./maps/bonus/map_bonus.ber
```

---

### **Resource**
- https://harm-smits.github.io/42docs/libs/minilibx
