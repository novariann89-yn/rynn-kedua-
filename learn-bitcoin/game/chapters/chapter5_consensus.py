from rich.panel import Panel
from game.utils import print_chapter_header, typewriter, pause, retry_pause, console, select_option
from game.state import player

def run():
    print_chapter_header(5, "Immutability (Consensus & Block Confirmation)")
    
    typewriter("Your transaction is in Block #890241, but the journey isn't over.")
    typewriter("In a decentralized system, nodes must independently verify your block and agree on the ledger state.\n")
    pause()

    console.print(Panel(
        "[bold green]Consensus & Security:[/bold green]\n"
        "• [cyan]Confirmations:[/cyan] Each subsequent block mined on top of yours adds 1 confirmation, exponentially increasing security.\n"
        "• [cyan]Longest Chain Rule (Most Cumulative Work):[/cyan] Nodes always follow the valid chain with the most accumulated Proof-of-Work.\n"
        "• [cyan]Trustless Verification:[/cyan] Don't trust, verify (`bitcoind`).",
        title="[bold]Decentralized Consensus[/bold]",
        border_style="green"
    ))
    pause()

    typewriter("Challenge: **The Reorg & Confirmation Race**")
    typewriter("A minor chain split (fork) occurs! Two competing miners found blocks at height 890,241 simultaneously.")
    typewriter("Chain A has 2 confirmations with lower work. Chain B has 1 confirmation with heavier proof-of-work (more cumulative difficulty).")
    typewriter("Which chain does your node's consensus rules accept?")

    options = [
        "Chain A (because it arrived first / has more block count locally).",
        "Chain B (Longest Chain / Most Cumulative Work Rule).",
        "Accept both and double-spend."
    ]

    while True:
        choice_idx = select_option("Select correct consensus action:", options)
        if choice_idx == 1:
            console.print("\n[bold green]Correct![/bold green] Bitcoin nodes measure chain validity by cumulative proof-of-work, not just block count. Chain B wins!")
            player.satoshis += 4000
            player.inventory.append("Six-Confirmation Immutability Seal")
            player.unlocked_tools.append("getchaintips")
            player.save()
            break
        else:
            console.print("\n[bold red]Invalid consensus![/bold red] Remember Satoshi's whitepaper: the longest chain is the one with the most work.")
            retry_pause()

    pause()
    typewriter("🎉 **CONGRATULATIONS!** 🎉")
    typewriter(f"You successfully navigated the P2P network, configured your node with [yellow]bitcoind -server[/yellow], survived mempool congestion, mined PoW, and achieved 6 full block confirmations!")
    typewriter(f"Final Score: [bold green]{player.satoshis} Satoshis[/bold green] secured in permanent immutable history.")
    pause()
