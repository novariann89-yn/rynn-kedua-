#!/usr/bin/env python3
import sys
import os
from rich.panel import Panel
from rich.prompt import Prompt
from game.utils import print_banner, typewriter, pause, console
from game.state import player, SAVE_FILE
from game.chapters import chapter1_genesis, chapter2_broadcast, chapter3_mempool, chapter4_mining, chapter5_consensus, chapter6_lightning

def main_menu():
    while True:
        console.clear()
        print_banner()
        console.print(Panel(player.status_summary(), border_style="bright_blue"))
        
        console.print("\n[bold cyan]Select an Option:[/bold cyan]")
        console.print("  [1] Start / Resume Satoshi's Quest (Chapters 1-6)")
        console.print("  [2] View Inventory, Unlocked Notes & bitcoin-cli Sandbox")
        console.print("  [3] Reset Progress / New Game")
        console.print("  [4] Exit")
        
        choice = Prompt.ask("\nChoose option", choices=["1", "2", "3", "4"], default="1")
        
        if choice == "1":
            play_game()
        elif choice == "2":
            show_inventory_and_cli()
        elif choice == "3":
            if Prompt.ask("[red]Are you sure you want to reset your progress?[/red]", choices=["y", "n"], default="n") == "y":
                if os.path.exists(SAVE_FILE):
                    os.remove(SAVE_FILE)
                player.__init__()
                console.print("[green]Progress reset successfully![/green]")
                pause()
        elif choice == "4":
            console.print("[yellow]Goodbye! Keep stacking sats and learning bitcoin.[/yellow]")
            sys.exit(0)

def play_game():
    # Chapter 1
    if player.current_chapter <= 1:
        chapter1_genesis.run()
        player.current_chapter = 2
        player.save()
    
    # Chapter 2
    if player.current_chapter <= 2:
        chapter2_broadcast.run()
        player.current_chapter = 3
        player.save()
        
    # Chapter 3
    if player.current_chapter <= 3:
        chapter3_mempool.run()
        player.current_chapter = 4
        player.save()
        
    # Chapter 4
    if player.current_chapter <= 4:
        chapter4_mining.run()
        player.current_chapter = 5
        player.save()
        
    # Chapter 5
    if player.current_chapter <= 5:
        chapter5_consensus.run()
        player.current_chapter = 6
        player.save()

    # Chapter 6 (Lightning Network & L2)
    if player.current_chapter <= 6:
        chapter6_lightning.run()
        player.current_chapter = 7  # Completed all
        player.save()
        
    console.print("\n[bold green]🏆 You have completed all chapters of Satoshi's Quest & Lightning Odyssey! 🏆[/bold green]")
    pause()

def show_inventory_and_cli():
    while True:
        console.clear()
        console.print(Panel("[bold yellow]Your Bitcoin Learning, Inventory & Diagnostic Toolkit[/bold yellow]", border_style="yellow"))
        console.print(f"• [cyan]Current Chapter:[/cyan] {player.current_chapter}/7")
        console.print(f"• [cyan]Satoshis Earned:[/cyan] {player.satoshis} sats")
        console.print(f"• [cyan]Server Mode (-server):[/cyan] {'Enabled' if player.server_enabled else 'Disabled'}")
        console.print(f"• [cyan]Daemon Mode (-daemon):[/cyan] {'Active' if player.daemon_mode else 'Inactive'}")
        console.print(f"• [cyan]RAM Cache (-dbcache):[/cyan] {player.ram_mb}MB")
        
        console.print("\n[bold]Unlocked Inventory Items & Tools:[/bold]")
        if not player.inventory and not player.unlocked_tools:
            console.print("  [dim]No items yet. Play the game to unlock tools and keys![/dim]")
        for item in player.inventory:
            console.print(f"  - [green]{item}[/green]")
        for tool in player.unlocked_tools:
            console.print(f"  - [yellow]{tool}[/yellow]")

        console.print("\n[bold cyan]Interactive bitcoin-cli Simulator Sandbox:[/bold cyan]")
        if player.unlocked_tools:
            console.print("[dim]Unlocked commands:[/dim] " + ", ".join(f"[yellow]{t}[/yellow]" for t in player.unlocked_tools))
        console.print("Type any unlocked command (e.g. [yellow]getblockchaininfo[/yellow], [yellow]getmempoolinfo[/yellow]), or type [bold]back[/bold] to return to menu.")

        cmd = Prompt.ask("\nbitcoin-cli / lncli").strip()
        if cmd.lower() in ["back", "exit", "quit"]:
            break
        elif not cmd:
            continue
        else:
            # Only commands genuinely unlocked through chapters may run.
            unlocked_names = set()
            for tool in player.unlocked_tools:
                unlocked_names.add(tool)
                for part in tool.split():
                    unlocked_names.add(part)
            if cmd in unlocked_names or f"bitcoin-cli {cmd}" in unlocked_names:
                console.print(f"\n[green]Executing simulation for:[/green] bitcoin-cli {cmd}")
                if "blockchain" in cmd:
                    console.print(Panel("Block Height: 890,245 | Best Hash: 00000000000000000003b... | Difficulty: 84.2T | Chain: main", title="getblockchaininfo"))
                elif "mempool" in cmd:
                    console.print(Panel("Size: 32,450 txs | Bytes: 24,100,000 | Usage: 280MB / 300MB max | Min Fee: 22 sat/vB", title="getmempoolinfo"))
                elif "network" in cmd:
                    console.print(Panel("Version: 26.00 (Bitcoin Knots) | Subversion: /Satoshi:26.0/ | Connections: 12 peers", title="getnetworkinfo"))
                elif "payinvoice" in cmd:
                    console.print(Panel("Payment routed via 3 hops in 42ms | Fee: 1 sat | Preimage: f4a9...c21b", title="lncli payinvoice"))
                else:
                    console.print(Panel(f"Command executed successfully against local node (-server=1). Response: {{'result': 'success', 'satoshis': {player.satoshis}}}", title=cmd))
                pause()
            else:
                if player.unlocked_tools:
                    console.print(f"\n[red]Error: '{cmd}' is not unlocked yet. Unlock it by progressing through the chapters![/red]")
                else:
                    console.print(f"\n[red]Error: '{cmd}' not recognized. Play Chapter 2+ to unlock bitcoin-cli diagnostics tools![/red]")
                pause()

if __name__ == "__main__":
    try:
        main_menu()
    except KeyboardInterrupt:
        console.print("\n[yellow]Game exited safely. See you next time![/yellow]")
        sys.exit(0)
