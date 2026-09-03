import random
from rich.markup import escape
from textual.app import App, ComposeResult
from textual.containers import Horizontal, Vertical, VerticalScroll
from textual.widgets import Header, Footer, Static, Button
from textual.binding import Binding

from game.tui_scenes import PIXEL_SATOSHI, BITCOIN_LOGO_ART, MEME_QUOTES
from game.tui_chapters import CHAPTERS_DATA

class SatoshiQuestApp(App):
    CSS = """
    Screen {
        background: #090d16;
        color: #e2e8f0;
    }
    
    Header {
        background: #0f172a;
        color: #38bdf8;
        text-style: bold;
        dock: top;
    }
    
    Footer {
        background: #0f172a;
        color: #94a3b8;
    }

    #sidebar {
        width: 34;
        background: #0f172a;
        border-right: heavy #38bdf8;
        padding: 1 2;
    }

    #main-content {
        padding: 1 2;
        background: #0b1120;
        border: solid #1e293b;
        height: 100%;
    }

    #story-scroll {
        height: 1fr;
        margin-bottom: 1;
    }

    .panel-title {
        color: #f59e0b;
        text-style: bold;
        margin-bottom: 1;
    }

    .stat-box {
        background: #1e293b;
        color: #38bdf8;
        padding: 1;
        margin-bottom: 1;
        border: round #334155;
    }

    .meme-box {
        background: #1e1b4b;
        color: #c084fc;
        padding: 1;
        margin-bottom: 1;
        border: round #4c1d95;
    }

    Button {
        background: #1e293b;
        color: #38bdf8;
        border: tall #38bdf8;
        margin-top: 1;
        width: 100%;
        height: 3;
    }

    Button:hover {
        background: #38bdf8;
        color: #0f172a;
    }

    #story-card {
        background: #0f172a;
        border: heavy #334155;
        padding: 2;
        width: 100%;
    }
    """

    BINDINGS = [
        Binding("q", "quit", "Quit Game", priority=True),
        Binding("r", "reset", "Restart Quest"),
    ]

    def __init__(self):
        super().__init__()
        self.satoshis = 5000
        self.ram_mb = 128
        self.server_active = False
        self.current_ch_idx = -1  # -1 for intro, 0-4 for chapters, 5 for victory
        self.score_msg = ""
        self.current_meme = random.choice(MEME_QUOTES)

    def compose(self) -> ComposeResult:
        yield Header(show_clock=True)
        with Horizontal():
            with Vertical(id="sidebar"):
                yield Static("[bold #f59e0b]⚡ DASHBOARD[/bold #f59e0b]", classes="panel-title")
                yield Static(self.get_stats_text(), id="stats-widget", classes="stat-box")
                yield Static("[bold #c084fc]🧠 LORE & MEMES[/bold #c084fc]", classes="panel-title")
                yield Static(self.current_meme, id="meme-widget", classes="meme-box")
                yield Static("\n[dim]Shortcuts:\n[Q] Quit Game\n[R] Restart Quest[/dim]")
            with Vertical(id="main-content"):
                with VerticalScroll(id="story-scroll"):
                    yield Static(self.render_story_text(), id="story-card")
                with Vertical(id="button-container"):
                    # Buttons will be dynamically mounted here
                    pass
        yield Footer()

    def get_stats_text(self) -> str:
        server_str = "ON (-server=1)" if self.server_active else "OFF"
        ch_display = f"{self.current_ch_idx + 1}/5" if 0 <= self.current_ch_idx < 5 else ("Intro" if self.current_ch_idx == -1 else "Completed")
        return (
            f"Sats: {self.satoshis} sats\n"
            f"RAM Cache: {self.ram_mb} MB\n"
            f"RPC Server: {server_str}\n"
            f"Stage: {ch_display}"
        )

    def render_story_text(self) -> str:
        if self.current_ch_idx == -1:
            logo = BITCOIN_LOGO_ART
            return (
                f"[bold #f59e0b]⚡ SATOSHI'S QUEST: ODYSSEY THROUGH THE BLOCKCHAIN ⚡[/bold #f59e0b]\n\n"
                f"{logo}\n"
                f"[cyan]Pixel Satoshi Profile:[/cyan]\n{escape(PIXEL_SATOSHI)}\n"
                f"[dim]An elite terminal RPG representing your Bitcoin learning journey from Obsidian notes.[/dim]\n\n"
                f"[green]{self.score_msg}[/green]"
            )
        elif 0 <= self.current_ch_idx < len(CHAPTERS_DATA):
            ch = CHAPTERS_DATA[self.current_ch_idx]
            opts_display = "\n".join([f"  [cyan]{opt[0]}[/cyan]" for opt in ch["options"]])
            return (
                f"[bold magenta]{ch['title']}[/bold magenta]\n\n"
                f"[yellow]📖 Lore:[/yellow] {ch['lore']}\n"
                f"[blue]🧠 Obsidian Note Applied:[/blue] [italic]{ch['obsidian_note']}[/italic]\n\n"
                f"[bold]Challenge:[/bold] {ch['question']}\n\n"
                f"{opts_display}\n\n"
                f"[bold green]{self.score_msg}[/bold green]"
            )
        else:
            return (
                f"[bold green]🎉 ODYSSEY COMPLETED SUCCESSFULLY! 🎉[/bold green]\n\n"
                f"You have mastered Bitcoin cryptography, Bitcoin Knots server flags, RAM caching, Proof-of-Work mining, and consensus rules!\n\n"
                f"[yellow]Final Stored Satoshis:[/yellow] {self.satoshis} sats\n\n"
                f"[dim]You are now an elite full node operator. Click Reset below or press [R] to replay.[/dim]"
            )

    async def on_mount(self):
        await self.refresh_ui()

    async def refresh_ui(self):
        # Update sidebar stats
        try:
            self.query_one("#stats-widget", Static).update(self.get_stats_text())
            self.query_one("#meme-widget", Static).update(self.current_meme)
        except Exception:
            pass

        # Update story text
        try:
            self.query_one("#story-card", Static).update(self.render_story_text())
        except Exception:
            pass

        # Update buttons in button-container
        btn_container = self.query_one("#button-container", Vertical)
        await btn_container.remove_children()

        if self.current_ch_idx == -1:
            await btn_container.mount(Button("🚀 Start Satoshi's Quest", id="action-start", variant="primary"))
        elif 0 <= self.current_ch_idx < len(CHAPTERS_DATA):
            ch = CHAPTERS_DATA[self.current_ch_idx]
            for opt_text, _ in ch["options"]:
                key = opt_text[0]
                await btn_container.mount(Button(f"Select {key}: {opt_text[3:]}", id=f"opt_{key}"))
        else:
            await btn_container.mount(Button("🔄 Restart Quest", id="action-restart", variant="success"))

        self.call_after_refresh(self._snap_story_top)

    def _snap_story_top(self):
        try:
            self.query_one("#story-scroll", VerticalScroll).scroll_home(animate=False)
        except Exception:
            pass

    async def on_button_pressed(self, event: Button.Pressed) -> None:
        btn_id = event.button.id
        if btn_id == "action-start":
            self.current_ch_idx = 0
            self.score_msg = ""
            self.current_meme = random.choice(MEME_QUOTES)
            await self.refresh_ui()
        elif btn_id == "action-restart":
            self.current_ch_idx = -1
            self.satoshis = 5000
            self.server_active = False
            self.ram_mb = 128
            self.score_msg = "Quest reset."
            self.current_meme = random.choice(MEME_QUOTES)
            await self.refresh_ui()
        elif btn_id and btn_id.startswith("opt_"):
            chosen_key = btn_id.split("_")[1]
            ch = CHAPTERS_DATA[self.current_ch_idx]
            correct = False
            for opt_text, is_corr in ch["options"]:
                if opt_text.startswith(chosen_key) and is_corr:
                    correct = True
                    break

            if correct:
                self.satoshis += 1500
                if self.current_ch_idx == 1:
                    self.server_active = True
                elif self.current_ch_idx == 2:
                    self.ram_mb = 256
                self.score_msg = f"✔ {ch['success_msg']}"
                self.current_ch_idx += 1
                self.current_meme = random.choice(MEME_QUOTES)
                await self.refresh_ui()
            else:
                self.score_msg = "❌ Incorrect choice! Review your Obsidian notes and try again."
                await self.refresh_ui()

    async def action_reset(self):
        self.current_ch_idx = -1
        self.satoshis = 5000
        self.server_active = False
        self.ram_mb = 128
        self.score_msg = "Quest reset via shortcut [R]."
        self.current_meme = random.choice(MEME_QUOTES)
        await self.refresh_ui()

if __name__ == "__main__":
    app = SatoshiQuestApp()
    app.run()
