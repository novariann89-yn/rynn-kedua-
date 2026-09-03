import re
import time
import sys
from rich.console import Console
from rich.panel import Panel
from rich.prompt import Prompt
from rich.text import Text

console = Console()

def print_banner():
    title = Text("⚡ SATOSHI'S QUEST: ODYSSEY THROUGH THE BLOCKCHAIN ⚡", style="bold yellow")
    subtitle = Text("An Interactive CLI Adventure based on your Bitcoin Learning Notes", style="cyan italic")
    panel = Panel(Text.assemble(title, "\n", subtitle), border_style="bright_blue", padding=(1, 2))
    console.print(panel)

def typewriter(text, style="", delay=0.01):
    # Normalize markdown-ish bold into rich markup, then type it out
    # character by character while honoring markup styles.
    text = re.sub(r"\*\*(.+?)\*\*", r"[bold]\1[/bold]", text)
    try:
        rich_text = Text.from_markup(text)
    except Exception:
        rich_text = Text(text)
    if style:
        rich_text.style = style
    plain = rich_text.plain

    def char_style(i):
        parts = [rich_text.style] if rich_text.style else []
        for start, end, span_style in rich_text.spans:
            if start <= i < end and span_style:
                parts.append(str(span_style))
        return " ".join(parts)

    for i, ch in enumerate(plain):
        console.print(ch, style=char_style(i) or None, end="")
        time.sleep(delay)
    console.print()

def pause():
    console.print("\n[dim]Press Enter to continue...[/dim]", end="")
    input()
    console.clear()

def retry_pause():
    # Non-clearing pause so the question stays on screen for another attempt.
    console.print("\n[dim]Press Enter to try again...[/dim]", end="")
    input()
    console.print()

def print_chapter_header(chapter_num, title):
    console.clear()
    header_text = Text(f"CHAPTER {chapter_num}: {title}", style="bold magenta")
    console.print(Panel(header_text, border_style="magenta", padding=(1, 2)))
    console.print()

def _select_option_fallback(prompt_text, options):
    console.print(f"[bold cyan]{prompt_text}[/bold cyan]")
    for i, opt in enumerate(options):
        console.print(f"  [cyan][{i + 1}][/cyan] {opt}")
    while True:
        choice = Prompt.ask("Enter number", choices=[str(i + 1) for i in range(len(options))], default="1")
        return int(choice) - 1

def select_option(prompt_text, options):
    """
    Interactive arrow-key selector using terminal raw mode.
    options: list of strings
    Returns the index of the selected option (0-indexed).
    Falls back to numbered input when stdin is not a TTY.
    """
    selected_idx = 0
    num_options = len(options)

    try:
        import termios
        import tty
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
    except Exception:
        return _select_option_fallback(prompt_text, options)

    width = console.width
    render_opts = [opt[: max(10, width - 10)] for opt in options]

    # Print prompt, reserve one line per option, then a hint line.
    console.print(f"[bold cyan]{prompt_text}[/bold cyan]")
    for _ in range(num_options):
        sys.stdout.write("\n")
    sys.stdout.write("\x1b[2m  (Use Up/Down arrows to navigate, Enter to select)\x1b[0m")
    sys.stdout.flush()

    # Move cursor up onto the first option row (below the prompt).
    sys.stdout.write(f"\033[{num_options}A\r")
    sys.stdout.flush()

    try:
        tty.setraw(fd)
        while True:
            for i, opt in enumerate(render_opts):
                sys.stdout.write("\r\033[K")
                if i == selected_idx:
                    sys.stdout.write(f"\033[32m\033[1m  ➔ {opt}\033[0m\r\n")
                else:
                    sys.stdout.write(f"      {opt}\r\n")
            sys.stdout.write("\r\033[K\033[2m  (Use Up/Down arrows, press Enter to select)\033[0m")
            sys.stdout.flush()

            ch = sys.stdin.read(1)
            if ch == '\x1b':
                ch2 = sys.stdin.read(1)
                ch3 = sys.stdin.read(1)
                if ch2 == '[':
                    if ch3 == 'A':  # Up arrow
                        selected_idx = (selected_idx - 1) % num_options
                    elif ch3 == 'B':  # Down arrow
                        selected_idx = (selected_idx + 1) % num_options
            elif ch in ('\r', '\n'):
                break
            elif ch == '\x03':  # Ctrl+C
                raise KeyboardInterrupt
            elif ch in ('1', '2', '3', '4', '5', '6', '7', '8', '9'):
                idx = int(ch) - 1
                if idx < num_options:
                    selected_idx = idx
                    break

            # Redraw: move back up to the first option row.
            sys.stdout.write(f"\033[{num_options}A")
            sys.stdout.flush()
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        # Cursor sits at the hint row; drop to the next line for follow-up output.
        sys.stdout.write("\r\n")
        sys.stdout.flush()

    return selected_idx
