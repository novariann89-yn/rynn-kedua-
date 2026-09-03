import random
from rich.panel import Panel
from game.utils import print_chapter_header, typewriter, pause, retry_pause, console, select_option
from game.state import player

def run():
    print_chapter_header(1, "The Genesis (Keys, Signatures, and Wallets)")
    
    typewriter("You wake up in the dark, swirling void of cryptographic entropy.")
    typewriter("You are not yet a coin, nor a ledger entry—you are a raw potential **Transaction Payload**.")
    typewriter("To enter the Bitcoin network and become real, you must first forge your identity using cryptography.\n")
    pause()

    console.print(Panel(
        "[bold green]The Core Concept:[/bold green]\n"
        "Bitcoin uses public-key cryptography (specifically the [yellow]secp256k1[/yellow] elliptic curve).\n"
        "1. [cyan]Private Key:[/cyan] A secret 256-bit number (your master password). Never share this!\n"
        "2. [cyan]Public Key:[/cyan] Derived mathematically from your private key via Elliptic Curve Multiplication.\n"
        "3. [cyan]Address:[/cyan] Hashed version of your public key where people send funds.",
        title="[bold]Cryptographic Primer[/bold]",
        border_style="green"
    ))
    pause()

    typewriter("Challenge 1: **The Key-Pair Harmonizer**")
    typewriter("An intruder daemon is trying to intercept your birth! You must correctly derive your Public Key from your Private Key to lock down your wallet.\n")
    
    options = [
        "Divide the private key by 2 and convert to ASCII.",
        "Multiply your private key with the secp256k1 generator point (G) using Elliptic Curve Multiplication.",
        "Hash your private key with MD5 and append your birthdate."
    ]
    
    while True:
        choice_idx = select_option("Choose the correct cryptographic operation:", options)
        if choice_idx == 1: # Index 1 is B
            console.print("\n[bold green]Correct![/bold green] Elliptic curve multiplication ensures that even if someone knows your public key, they cannot reverse-engineer your private key due to the discrete logarithm problem.")
            player.inventory.append("Valid Public Key & Secp256k1 Signature")
            player.satoshis += 1000
            player.save()
            break
        else:
            console.print("\n[bold red]Incorrect![/bold red] That would compromise your funds or break math! Try again.")
            retry_pause()

    pause()
    typewriter("With your signature secured, you stamp your transaction payload: [yellow]Sig(PrivateKey, TxData)[/yellow].")
    typewriter("You are ready to enter the wild P2P network. Advancing to Chapter 2...\n")
    pause()
