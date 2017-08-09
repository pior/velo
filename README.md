# Velo: smart rear light for bikes

## Hardware

- Arduino Nano
- WS2812 leds (2 x 8 leds)
- Vibration sensor
- LDR + 10K
- Lipo 600MAh
- Lipo charger + step-up

Case:

- 3D printed (STL to come)
- PLA for box
- Polycarbonate for transparent panel
- Velcro straps to hold the prototype

## Progress

- First prototype for the case
- Electronics is installed, fully wired
- First iteration of the code

Roadmap:

- Integrate TaskScheduler lib
- Find right approach about energy / lipo protection
- Improve case (rethink placement, 100% PC, nicer form-factor)
- Feature: brake light
- Feature: low battery warning
- Feature: day mode

## Development

First install PlatformIO Core: [docs](http://docs.platformio.org/en/latest/installation.html)

Clone the project:

    $ git clone git@github.com:pior/velo.git

Build:

    $ pio run

Upload:

    $ pio run -t upload
