from rich.panel import Panel
from game.utils import print_chapter_header, typewriter, pause, console, select_option
from game.state import player

def run():
    print_chapter_header(6, "The Lightning Network & Layer 2 Scaling")
    
    typewriter("You have mastered the Base Layer (L1), but high throughput requires Instant, Low-Fee Micropayments.")
    typewriter("Welcome to [bold yellow]Layer 2 (The Lightning Network)[/bold yellow], where smart contracts and bidirectional payment channels bypass blockchain congestion.\n")
    pause()

    console.print(Panel(
        "[bold cyan]Lightning Network Mechanics:[/bold cyan]\n"
        "• [yellow]Payment Channels:[/yellow] 2-of-2 multisig funding transactions on-chain. Off-chain updates happen instantly and cheaply via cryptographic state updates.\n"
        "• [yellow]HTLC (Hash Time-Locked Contracts):[/yellow] Enables trustless multi-hop routing across a mesh network without knowing intermediary nodes.\n"
        "• [yellow]Watchtowers:[/yellow] Guardian nodes watching the blockchain to penalize malicious channel closers.",
        title="[bold]Layer 2 Scaling[/bold]",
        border_style="cyan"
    ))
    pause()

    typewriter("Challenge: **Opening a Payment Channel & Routing**")
    typewriter("You want to send 1,000 sats instantly across 3 nodes to a merchant without waiting for block confirmations.")
    typewriter("What smart contract script mechanism locks funds with cryptographic hashes and time limits to ensure trustless routing?")
    
    options = [
        "OP_CHECKSEQUENCEVERIFY alone",
        "HTLC (Hash Time-Locked Contract)",
        "OP_RETURN message broadcast"
    ]

    while True:
        choice_idx = select_option("Select the correct protocol mechanism:", options)
        if choice_idx == 1:
            console.print("\n[bold green]Correct![/bold green] HTLCs use cryptographic hashes and time locks to guarantee atomic routing across multiple payment channels securely.")
            player.inventory.append("Lightning Node Channel & HTLC Voucher")
            player.satoshis += 5000
            player.unlocked_tools.extend(["lightning-cli getinfo", "lncli payinvoice"])
            player.save()
            break
        else:
            console.print("\n[bold red]Incorrect![/bold red] HTLCs are essential for trustless multi-hop Lightning routing.")
            pause()

    pause()
    typewriter("🎉 **SATOSHI'S QUEST GRAND FINALE!** 🎉")
    typewriter("You have journeyed from raw cryptographic keys (Chapter 1), through node broadcasting and mempools (Chapters 2-3), mined proof-of-work (Chapter 4), achieved consensus (Chapter 5), and scaled into the Lightning Network (Chapter 6)!")
    typewriter(f"Final Score: [bold green]{player.satoshis} Satoshis[/bold green] | Unlocked Tools: {len(player.unlocked_tools)} Bitcoin/Lightning CLI Commands.")
    player.current_chapter = 7 # Fully completed
    player.save()
    pause()
