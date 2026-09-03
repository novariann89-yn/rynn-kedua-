import json
import os

SAVE_FILE = os.path.join(os.path.dirname(os.path.dirname(__file__)), "savegame.json")

class PlayerState:
    def __init__(self):
        self.name = "Satoshi-Tx #8332"
        self.satoshis = 50000
        self.ram_mb = 128
        self.max_ram = 300
        self.server_enabled = False
        self.daemon_mode = False
        self.unlocked_tools = []
        self.current_chapter = 1
        self.inventory = []
        self.load()

    def status_summary(self):
        return (
            f"[bold cyan]Player:[/bold cyan] {self.name} | "
            f"[bold green]Satoshis:[/bold green] {self.satoshis} sats | "
            f"[bold yellow]RAM Cache:[/bold yellow] {self.ram_mb}/{self.max_ram}MB | "
            f"[bold magenta]Server Mode:[/bold magenta] {'ON (-server=1)' if self.server_enabled else 'OFF'} | "
            f"[bold blue]Daemon:[/bold blue] {'Active (-daemon)' if self.daemon_mode else 'Foreground'}"
        )

    def save(self):
        data = {
            "name": self.name,
            "satoshis": self.satoshis,
            "ram_mb": self.ram_mb,
            "max_ram": self.max_ram,
            "server_enabled": self.server_enabled,
            "daemon_mode": self.daemon_mode,
            "unlocked_tools": self.unlocked_tools,
            "current_chapter": self.current_chapter,
            "inventory": self.inventory
        }
        try:
            with open(SAVE_FILE, "w") as f:
                json.dump(data, f, indent=4)
        except Exception:
            pass

    def load(self):
        if os.path.exists(SAVE_FILE):
            try:
                with open(SAVE_FILE, "r") as f:
                    data = json.load(f)
                    self.name = data.get("name", self.name)
                    self.satoshis = data.get("satoshis", self.satoshis)
                    self.ram_mb = data.get("ram_mb", self.ram_mb)
                    self.max_ram = data.get("max_ram", self.max_ram)
                    self.server_enabled = data.get("server_enabled", self.server_enabled)
                    self.daemon_mode = data.get("daemon_mode", self.daemon_mode)
                    self.unlocked_tools = data.get("unlocked_tools", self.unlocked_tools)
                    self.current_chapter = data.get("current_chapter", self.current_chapter)
                    self.inventory = data.get("inventory", self.inventory)
            except Exception:
                pass

player = PlayerState()
