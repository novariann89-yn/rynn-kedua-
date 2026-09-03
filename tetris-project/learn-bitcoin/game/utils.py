import time
import sys
import termios
import tty
from rich.console import Console
from rich.panel import Panel
from rich.text import Text

console = Console()

def print_banner():
    title = Text("⚡ SATOSHI'S QUEST: ODYSSEY THROUGH THE BLOCKCHAIN ⚡", style="bold yellow")
    subtitle = Text("An Interactive CLI Adventure based on your Bitcoin Learning Notes", style="cyan italic")
    panel = Panel(Text.assemble(title, "\n", subtitle), border_style="bright_blue", padding=(1, 2))
    console.print(panel)

def typewriter(text, style="white", delay=0.01):
    for char in text:
        console.print(char, style=style, end="")
        time.sleep(delay)
    console.print()

def pause():
    console.print("\n[dim]Press Enter to continue...[/dim]", end="")
    input()
    console.clear()

def print_chapter_header(chapter_num, title):
    console.clear()
    header_text = Text(f"CHAPTER {chapter_num}: {title}", style="bold magenta")
    console.print(Panel(header_text, border_style="magenta", padding=(1, 2)))
    console.print()

def select_option(prompt_text, options):
    """
    Interactive arrow-key selector using terminal raw mode.
    options: list of strings
    Returns the index of the selected option (0-indexed).
    """
    selected_idx = 0
    num_options = len(options)
    
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    
    # Print initial prompt spacing
    console.print(f"[bold cyan]{prompt_text}[/bold cyan]")
    for i in range(num_options):
        console.print("")
    console.print("[dim](Use Up/Down arrows to navigate, Enter to select)[/dim]")
    
    # Move cursor back up to the start of options
    total_lines_up = num_options + 2
    sys.stdout.write(f"\033[{total_lines_up}A")
    sys.stdout.flush()
    
    try:
        tty.setraw(fd)
        while True:
            # Render options
            for i, opt in enumerate(options):
                sys.stdout.write("\r\033[K")
                if i == selected_idx:
                    sys.stdout.write(f"\033[32m\033[1m  ➔ {opt}\033[0m\r\n")
                else:
                    sys.stdout.write(f"      {opt}\r\n")
            sys.stdout.write("\r\033[K\033[2m  (Use Up/Down arrows, press Enter to select)\033[0m")
            sys.stdout.flush()
            
            # Read keypress
            ch = sys.stdin.read(1)
            if ch == '\x1b':
                ch2 = sys.stdin.read(1)
                ch3 = sys.stdin.read(1)
                if ch2 == '[':
                    if ch3 == 'A': # Up arrow
                        selected_idx = (selected_idx - 1) % num_options
                    elif ch3 == 'B': # Down arrow
                        selected_idx = (selected_idx + 1) % num_options
            elif ch == '\r' or ch == '\n':
                break
            elif ch == '\x03': # Ctrl+C
                raise KeyboardInterrupt
                
            # Move cursor back up for redraw
            sys.stdout.write(f"\033[{num_options}A")
            sys.stdout.flush()
            
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        # Move cursor down past the rendered block
        sys.stdout.write(f"\033[{num_options + 1}B\r\n")
        sys.stdout.flush()
        
    return selected_idx
