import hashlib
import random
from rich.panel import Panel
from rich.prompt import Prompt
from game.utils import print_chapter_header, typewriter, pause, console
from game.state import player

def run():
    print_chapter_header(4, "The Crucible (Mining & Proof-of-Work)")
    
    typewriter("You have entered a miner's workspace. Your transaction is packed into a candidate block.")
    typewriter("To anchor your block into history, the miner must solve the **Proof-of-Work (PoW)** puzzle using SHA-256.\n")
    pause()

    console.print(Panel(
        "[bold magenta]Mining Mechanics:[/bold magenta]\n"
        "• [cyan]SHA-256:[/cyan] A cryptographic hash function producing a 256-bit fingerprint.\n"
        "• [cyan]Nonce:[/cyan] An arbitrary number miners tweak repeatedly until the resulting hash falls below the current network [yellow]Target Difficulty[/yellow] (starts with required leading zeros).\n"
        "• [cyan]Energy & Hashrate:[/cyan] Millions of hashes per second computed to secure the ledger.",
        title="[bold]Proof-of-Work[/bold]",
        border_style="magenta"
    ))
    pause()

    typewriter("Challenge: **The Nonce Mining Simulator**")
    typewriter("The miner needs a hash starting with [bold yellow]'00'[/bold yellow] to win the block reward.")
    typewriter("Let's test your hashing skills! Guess or simulate finding a matching nonce.")

    block_data = "Block#890241:TxPayload:Satoshi"
    target_prefix = "00"

    attempts = 0
    while True:
        nonce_input = Prompt.ask("\nEnter an integer Nonce to try hashing", default=str(random.randint(1, 1000)))
        try:
            nonce = int(nonce_input)
        except ValueError:
            console.print("[red]Please enter a valid integer.[/red]")
            continue

        combined = f"{block_data}:{nonce}".encode()
        h = hashlib.sha256(combined).hexdigest()
        attempts += 1

        console.print(f"  Attempt {attempts} | Nonce: {nonce} -> Hash: [cyan]{h}[/cyan]")

        if h.startswith(target_prefix):
            console.print(f"\n[bold green]SUCCESS! [/bold green] Found valid hash starting with '{target_prefix}' in {attempts} attempts!")
            console.print(f"Winning Hash: [yellow]{h}[/yellow]")
            break
        else:
            console.print("[dim]Hash didn't meet target difficulty. Try another nonce![/dim]")

    player.satoshis += 5000
    pause()
    typewriter("Block mined successfully! Your transaction is now embedded in the newly forged block. Advancing to Chapter 5...\n")
    pause()
