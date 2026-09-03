CHAPTERS_DATA = [
    {
        "num": 1,
        "title": "Chapter 1: The Genesis (Keys, Signatures, & Wallets)",
        "lore": "You wake up as a raw potential transaction in the dark entropy void. Rumor has it that if you lose your private key, you join the sacred burnt coins of Satoshi's vault.",
        "obsidian_note": "Public Key Cryptography & secp256k1 Elliptic Curve math.",
        "question": "How is your Public Key derived from your Private Key?",
        "options": [
            ("A) Divide private key by 2 and hash with MD5", False),
            ("B) Elliptic Curve Multiplication (secp256k1 generator point G)", True),
            ("C) Random number generator guess", False)
        ],
        "success_msg": "Correct! Mathematical magic ensures private keys remain secret forever. [+1,000 sats]"
    },
    {
        "num": 2,
        "title": "Chapter 2: The Broadcast & Bitcoin Knots (-server)",
        "lore": "You are broadcast into the P2P Gossip network. To query your status, your node needs its JSON-RPC server enabled.",
        "obsidian_note": "bitcoind -server=1 turns on JSON-RPC. .cookie file handles auto-auth. bitcoind -daemon runs silently in the background.",
        "question": "What flag turns on the JSON-RPC server in Bitcoin Knots / Core?",
        "options": [
            ("A) --enable-rpc-all", False),
            ("B) bitcoind -server", True),
            ("C) bitcoin-cli --start-server", False)
        ],
        "success_msg": "Success! JSON-RPC port is open and `.cookie` generated. Diagnostic tools unlocked! [+2,000 sats]"
    },
    {
        "num": 3,
        "title": "Chapter 3: Mempool Purgatory & RAM Cache (-dbcache)",
        "lore": "Network congestion spikes! Mempool fills up with 45,000 pending transactions. You're stuck at the bottom of the fee queue.",
        "obsidian_note": "-dbcache stores UTXO database in RAM to avoid disk read bottlenecks. Default mempool is 300MB.",
        "question": "Which parameter configures the UTXO database cache in RAM?",
        "options": [
            ("A) -dbcache=450", True),
            ("B) -ramlimit=4GB", False),
            ("C) -cachestore=true", False)
        ],
        "success_msg": "Optimized! RAM cache prevents disk thrashing. You use Replace-by-Fee (RBF) to bump your fee! [+3,000 sats]"
    },
    {
        "num": 4,
        "title": "Chapter 4: The Crucible (Mining & Proof-of-Work)",
        "lore": "A miner picks you up into a candidate block. Now comes the SHA-256 energy grind.",
        "obsidian_note": "Miners adjust the 'Nonce' repeatedly until the hash meets the difficulty target (leading zeros).",
        "question": "What cryptographic hash function powers Bitcoin's Proof-of-Work?",
        "options": [
            ("A) MD5", False),
            ("B) SHA-256", True),
            ("C) RSA-2048", False)
        ],
        "success_msg": "Valid hash found! Proof-of-work locked in. [+5,000 sats]"
    },
    {
        "num": 5,
        "title": "Chapter 5: Immutability & Consensus",
        "lore": "Your block is mined! But a competing chain fork appears. Whose side are nodes on?",
        "obsidian_note": "Longest Chain Rule / Most Cumulative Work Rule dictates consensus validity.",
        "question": "How do Bitcoin nodes resolve competing block forks?",
        "options": [
            ("A) The chain with the most accumulated Proof-of-Work (Most Work Rule)", True),
            ("B) The chain that arrived first in local time", False),
            ("C) Random coin toss by full nodes", False)
        ],
        "success_msg": "Consensus achieved! 6 confirmations reached. Your transaction is permanently immutable! 🎉"
    }
]
