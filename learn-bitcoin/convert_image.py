import requests
from io import BytesIO
from PIL import Image

url = "https://www.citypng.com/public/uploads/preview/hd-bitcoin-neon-logo-png-701751694780290nio2bsvy7r.png"
headers = {'User-Agent': 'Mozilla/5.0'}

try:
    response = requests.get(url, headers=headers, timeout=10)
    img = Image.open(BytesIO(response.content)).convert("RGBA")

    aspect_ratio = img.height / img.width
    new_width = 48
    new_height = int(new_width * aspect_ratio * 0.48)
    img = img.resize((new_width, new_height))

    formatted_lines = []
    for y in range(new_height):
        line_str = ""
        for x in range(new_width):
            r, g, b, a = img.getpixel((x, y))
            if a < 30 or (r < 40 and g < 40 and b < 40):
                line_str += " "
            else:
                line_str += f"[#{r:02x}{g:02x}{b:02x}]█[/]"
        formatted_lines.append(line_str)

    art = "\n".join(formatted_lines)
except Exception as e:
    print(f"Error fetching URL: {e}")
    # Fallback neon art if network blocks
    art = "[#ff9500]      .----------------.      \n     (     ▄██▄   ▄██▄       )   [_] _     _ _ _             \n     (     █████   █████   )   | |__ (_) |_| | ___  _ __ \n     (     ▀█████ [#ff9500] [#ffb703]█████▀   )   | '_ \\| | __| |/ _ \\| '_ \\\n     (      ▀██▀   ▀██▀      )   | |_) | | |_| | (_) | | | |\n      '----------------'       |_.__/|_|\\__|_|\\___/|_| |_|[/]"

with open("game/tui_scenes.py", "w") as f:
    f.write(f'''PIXEL_SATOSHI = \"\"\"
      [?]      
     [o_o]     
    /|___|\\    
     |   |     
    /     \\    
\"\"\"

BITCOIN_LOGO_ART = \"\"\"
{art}
\"\"\"

MEME_QUOTES = [
    "\"Few understand this.\" — Anonymous Node Operator",
    "\"Not your keys, not your coins.\" — Ancient Satoshi Proverb",
    "\"Stay humble, stack sats.\" — Mempool Philosopher",
    "\"Laser eyes activated. Processing block #890241.\" — Miner #42",
    "\"Have fun staying fiat.\" — Full Node Elite"
]
''')

print("Successfully generated and updated game/tui_scenes.py!")
