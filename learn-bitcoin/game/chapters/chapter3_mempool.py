from rich.panel import Panel
from game.utils import print_chapter_header, typewriter, pause, retry_pause, console, select_option
from game.state import player

def run():
    print_chapter_header(3, "Mempool Purgatory & Resource Consumption")
    
    typewriter("You arrive in the node's **Memory Pool (Mempool)** — a chaotic waiting room for unconfirmed transactions.")
    typewriter("Network congestion is spiking! Fees are rising to 45 sat/vB, and your transaction is stuck at 10 sat/vB.\n")
    pause()

    console.print(Panel(
        "[bold yellow]Obsidian Note Refresher ([italic]Exploring Bitcoin Knots[/italic]):[/bold yellow]\n"
        "• [cyan]Does `-server` use significant RAM?[/cyan] No! It's just a lightweight HTTP listener using negligible memory (a few KB to MB).\n"
        "• [cyan]What consumes RAM?[/cyan] 1) UTXO Cache (`-dbcache`) to prevent constant disk reads. 2) The Mempool (`-maxmempool`) default 300MB limit.\n"
        "• [cyan]Mempool Diagnostics:[/cyan] `bitcoin-cli getmempoolinfo` and `bitcoin-cli getrawmempool`.",
        title="[bold]Memory & Mempool Dynamics[/bold]",
        border_style="yellow"
    ))
    pause()

    typewriter("Challenge 1: **The JSON-RPC RAM Myth**")
    typewriter("An inexperienced node operator panics: [red]'Oh no! I enabled `-server` for my RPC tool, my server RAM is going to max out!'[/red]")
    typewriter("According to your Obsidian notes, how much RAM does enabling `-server` actually consume?\n")
    
    options = [
        "Massive amounts of RAM because it hosts the entire blockchain database in memory.",
        "Negligible amount (a few kilobytes to megabytes) because it's just a lightweight HTTP listener.",
        "Exactly 300 megabytes, locked rigidly."
    ]

    while True:
        choice_idx = select_option("Select the correct RAM impact:", options)
        if choice_idx == 1:
            player.ram_mb = 150
            console.print("\n[bold green]Correct![/bold green] As noted in your Obsidian notes: `-server` is just a lightweight HTTP listener using negligible memory.")
            player.save()
            break
        else:
            console.print("\n[bold red]Incorrect![/bold red] Check Section 2 of your notes: `-server` does not hog RAM.")
            retry_pause()

    pause()
    typewriter("Challenge 2: **Identifying Real RAM Consumers & Mempool Pressure**")
    typewriter("Your node is warning of high disk read latency during transaction validation. What parameter configures the UTXO database cache in RAM to prevent constant disk reads?\n")
    
    options = [
        "-dbcache",
        "-servercache",
        "-diskbypass=true"
    ]

    while True:
        choice_idx = select_option("Select the correct parameter:", options)
        if choice_idx == 0:
            console.print("\n[bold green]Success![/bold green] `-dbcache` caches the unspent transaction output database in RAM as specified in your notes.")
            player.satoshis += 3000
            player.save()
            break
        else:
            console.print("\n[bold red]Incorrect parameter![/bold red] Review Section 2 of your Obsidian notes.")
            retry_pause()

    pause()
    typewriter("You optimize your node resources, escape the Mempool, and get selected by a miner! Advancing to Chapter 4...\n")
    pause()
