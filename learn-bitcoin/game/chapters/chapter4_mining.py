import hashlib
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
    typewriter("Enter nonce guesses yourself, or just press [bold]Enter[/bold] on an empty input to let the rig auto-mine!")

    block_data = "Block#890241:TxPayload:Satoshi"
    target_prefix = "00"

    def check_nonce(nonce):
        return hashlib.sha256(f"{block_data}:{nonce}".encode()).hexdigest()

    attempts = 0
    while True:
        nonce_input = Prompt.ask("\nEnter an integer Nonce (or empty = auto-mine)", default="")
        if nonce_input.strip() == "":
            # Auto-mine simulation: grind nonces until the target is hit.
            console.print("[dim]ASIC rig engaged — grinding nonces...[/dim]")
            nonce = 0
            h = check_nonce(nonce)
            while not h.startswith(target_prefix):
                nonce += 1
                h = check_nonce(nonce)
                if nonce % 250 == 0:
                    console.print(f"  [dim]hashrate tick | nonces tried: {nonce} | last hash: {h[:16]}...[/dim]")
            attempts += 1
            console.print(f"  Attempt {attempts} | Nonce: {nonce} -> Hash: [cyan]{h}[/cyan]")
            console.print(f"\n[bold green]SUCCESS![/bold green] The rig found a valid hash starting with '{target_prefix}' after {nonce + 1} hashes!")
            console.print(f"Winning Hash: [yellow]{h}[/yellow] | Winning Nonce: {nonce}")
            break

        try:
            nonce = int(nonce_input)
        except ValueError:
            console.print("[red]Please enter a valid integer (or empty for auto-mine).[/red]")
            continue

        h = check_nonce(nonce)
        attempts += 1

        console.print(f"  Attempt {attempts} | Nonce: {nonce} -> Hash: [cyan]{h}[/cyan]")

        if h.startswith(target_prefix):
            console.print(f"\n[bold green]SUCCESS! [/bold green] Found valid hash starting with '{target_prefix}' in {attempts} attempts!")
            console.print(f"Winning Hash: [yellow]{h}[/yellow]")
            break
        else:
            console.print("[dim]Hash didn't meet target difficulty. Try another nonce (or empty = auto-mine)![/dim]")

    player.satoshis += 5000
    pause()
    typewriter("Block mined successfully! Your transaction is now embedded in the newly forged block. Advancing to Chapter 5...\n")
    pause()
