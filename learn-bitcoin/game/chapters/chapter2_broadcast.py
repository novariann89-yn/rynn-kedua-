from rich.panel import Panel
from game.utils import print_chapter_header, typewriter, pause, console, select_option
from game.state import player

def run():
    print_chapter_header(2, "The Broadcast & Node Diagnostics (Bitcoin Knots)")
    
    typewriter("You burst out of the wallet into the P2P Gossip Network as a broadcasted transaction.")
    typewriter("To survive and find your way to a miner, you must interface with your local **Bitcoin Knots Node**.\n")
    pause()

    console.print(Panel(
        "[bold cyan]Obsidian Note Refresher ([italic]Exploring Bitcoin Knots[/italic]):[/bold cyan]\n"
        "• [yellow]Headless (`bitcoind`):[/yellow] JSON-RPC server is [bold green]ON by default[/bold green] (`-server=1`).\n"
        "• [yellow]Graphical (`bitcoin-qt`):[/yellow] JSON-RPC server is [bold red]OFF by default[/bold red] (`-server=0`).\n"
        "• [yellow]Cookie Auth:[/yellow] Generates a `.cookie` file in your data directory so `bitcoin-cli` authenticates automatically.\n"
        "• [yellow]Daemon Mode:[/yellow] `bitcoind -daemon` detaches the node from your shell session, writing logs to `debug.log`.",
        title="[bold]Node Operations & RPC[/bold]",
        border_style="cyan"
    ))
    pause()

    typewriter("Challenge 1: **The GUI vs Headless RPC Trap**")
    typewriter("You switched from headless `bitcoind` to the graphical desktop app (`bitcoin-qt`) to watch pretty graphics.")
    typewriter("Suddenly, `bitcoin-cli getblockchaininfo` fails with: [red]Connection refused / RPC server disabled.[/red]")
    typewriter("According to your Obsidian notes, why did this happen and how do you fix it?\n")

    options = [
        "bitcoin-qt turns off RPC by default (-server=0); you must explicitly pass -server or enable it.",
        "bitcoin-cli is corrupted; you must reinstall the CLI tool.",
        "The .cookie file was deleted by your antivirus."
    ]

    while True:
        choice_idx = select_option("Select the correct reason & fix:", options)
        if choice_idx == 0:
            player.server_enabled = True
            console.print("\n[bold green]Spot on![/bold green] As documented in your notes: `bitcoind` has `-server=1` by default, whereas `bitcoin-qt` defaults to `-server=0`.")
            player.save()
            break
        else:
            console.print("\n[bold red]Incorrect![/bold red] Remember: graphical desktop apps turn off the RPC server by default for security.")
            pause()

    pause()
    typewriter("Challenge 2: **Auditing Active RPC Commands**")
    typewriter("Your terminal is cluttered, and you suspect an automated script is spamming RPC requests to your node.")
    typewriter("According to your high-yield diagnostic notes, what `bitcoin-cli` command lists all active JSON-RPC commands and how long they have been executing?\n")

    options = [
        "bitcoin-cli getactivejobs",
        "bitcoin-cli getrpcinfo",
        "bitcoin-cli showconnections"
    ]

    while True:
        choice_idx = select_option("Select diagnostic command:", options)
        if choice_idx == 1:
            player.daemon_mode = True
            console.print("\n[bold green]Correct![/bold green] `bitcoin-cli getrpcinfo` inspects active JSON-RPC commands and execution durations.")
            player.save()
            break
        else:
            console.print("\n[bold red]Wrong command![/bold red] Check your Obsidian notes under Section 3 (OS vs Bitcoin Node Level).")
            pause()

    pause()
    typewriter("Challenge 3: **Diagnostic Toolkit Unlocked (`bitcoin-cli`)**")
    typewriter("You verify your node health using the exact commands from your Obsidian notes:")
    
    console.print("\n-> Running [yellow]bitcoin-cli getblockchaininfo[/yellow]...")
    console.print("[dim]Result: block height 890,240 | verification progress: 99.99% | sync status: healthy[/dim]")
    
    console.print("\n-> Running [yellow]bitcoin-cli getmempoolinfo[/yellow]...")
    console.print("[dim]Result: size: 45,000 txs | bytes: 32,000,000 | maxmempool: 300MB[/dim]")

    player.unlocked_tools.extend(["getblockchaininfo", "getnetworkinfo", "getmempoolinfo", "getrpcinfo", "getpeerinfo", "getbestblockhash"])
    player.satoshis += 2500
    player.save()

    typewriter("\nYou have mastered Bitcoin Knots RPC configuration, cookie auth, and node diagnostics directly from your notes!")
    pause()
