# Tetris Vibe Edition (Terminal + Web Dual Stack)

This repository contains two high-quality versions of our Retro Tetris Arcade game:

1. **Terminal C Edition (`tetris.c`)**
   - High performance, pure C, raw-mode terminal graphics with ANSI colors, side HUD, and dynamic pixel characters with mood updates and `"HAHAHAHAHAH U NOOB"` game over handling.
   
2. **Web Browser Edition (`index.html`)**
   - Built with modern HTML5 Canvas, CSS3 retro arcade styling, smooth grid rendering, and interactive pixel characters with speech bubbles and expressions directly in your browser.

## How to Play

### Terminal Version
```bash
gcc tetris.c -o tetris
./tetris
```
*Controls:*
- **A / D**: Move Left / Right
- **W**: Rotate
- **S**: Soft Drop
- **Q**: Quit

### Web Version
You can open `index.html` directly in any web browser or serve it locally:
```bash
python3 -m http.server 8080
```
Then visit `http://localhost:8080/` in your browser.

*Controls:*
- **Arrow Left / Right**: Move
- **Arrow Up**: Rotate
- **Arrow Down**: Soft Drop
- **Spacebar**: Hard Drop
