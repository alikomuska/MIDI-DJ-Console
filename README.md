# 🎛️ DIY MIDI DJ Console

```{=html}
<p align="center">
```
`<img src="./images/midi-dj-console.png" alt="DIY MIDI DJ Console" width="520">`{=html}
```{=html}
</p>
```
```{=html}
<p align="center">
```
`<b>`{=html}A custom-built MIDI DJ controller --- designed, wired,
programmed, and iterated from scratch.`</b>`{=html}
```{=html}
</p>
```
```{=html}
<p align="center">
```
`<img src="https://img.shields.io/badge/Project-DIY%20Hardware-111111?style=for-the-badge">`{=html}
`<img src="https://img.shields.io/badge/MIDI-Controller-e31b23?style=for-the-badge">`{=html}
`<img src="https://img.shields.io/badge/Status-In%20Development-555555?style=for-the-badge">`{=html}
```{=html}
</p>
```

------------------------------------------------------------------------

## 🎚️ What is this?

This project is my take on a **DIY MIDI DJ console**.

Instead of buying a finished controller, I'm building the whole thing
myself --- from the physical controls and electronics to the firmware
and MIDI communication.

The goal is simple:

> **Build a controller that feels like a real DJ instrument, while
> keeping complete control over the hardware and software.**

The current design combines buttons, illuminated controls, rotary
inputs, and faders in a compact custom layout.

------------------------------------------------------------------------

## 🔴⚫ The Console

The controller is built around a deliberately minimal **black + red**
aesthetic.

The physical interface currently includes:

-   🎛️ **Faders** for continuous control
-   🔘 **Buttons / push controls** for triggering actions
-   💡 **LED feedback** for visual state
-   🎚️ **Rotary controls** for parameter manipulation
-   🎹 **MIDI communication** for connecting the controller to DJ/music
    software

The exact control mapping is still evolving as the hardware and software
develop.

------------------------------------------------------------------------

## 🧠 How it works

At a high level:

``` text
┌─────────────────────┐
│     Physical UI     │
│ Buttons • Knobs •   │
│ LEDs • Faders       │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   Microcontroller   │
│                     │
│ Read inputs         │
│ Handle state        │
│ Drive LEDs          │
│ Generate MIDI       │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│      MIDI OUT       │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   DJ / Music App    │
└─────────────────────┘
```

The interesting part is making the physical controls and software behave
like one instrument.

------------------------------------------------------------------------

## 🛠️ Project Goals

This project is being built with a few goals in mind:

-   Build a **fully custom MIDI controller**
-   Learn more about embedded hardware and MIDI
-   Create a layout that actually makes sense for DJing
-   Add useful visual feedback
-   Keep the firmware modular and easy to extend
-   Experiment with different control mappings
-   Eventually use the controller for real mixing / live performance

------------------------------------------------------------------------

## 🚧 Current Status

**Work in progress.**

The hardware and control layout are still being developed, so things
will change.

Some parts of the project are experimental by design. The controller is
as much a learning project as it is a finished piece of hardware.

### Roadmap

-   [ ] Finalize physical control layout
-   [ ] Complete input handling
-   [ ] Implement MIDI messages
-   [ ] Add LED feedback / state management
-   [ ] Build reliable debouncing and filtering
-   [ ] Test every control independently
-   [ ] Integrate with DJ software
-   [ ] Improve enclosure / physical finish
-   [ ] Document the electronics
-   [ ] Perform a full live-mixing test

------------------------------------------------------------------------

## 📁 Repository Structure

The repository will eventually contain something along these lines:

``` text
.
├── firmware/       # Microcontroller code
├── hardware/       # Schematics, PCB / wiring information
├── enclosure/      # Mechanical design / 3D files
├── docs/           # Project notes and documentation
└── README.md
```

------------------------------------------------------------------------

## 🧪 Why build one?

Commercial DJ controllers are great.

But building one yourself means you get to decide **exactly** what every
control does.

It also turns a DJ controller into a much more interesting engineering
project:

**electronics + embedded programming + MIDI + mechanical design +
UI/UX**

That's the part I'm interested in.

------------------------------------------------------------------------

## 📸 Current Prototype

```{=html}
<p align="center">
```
`<img src="./images/midi-dj-console.png" alt="Current MIDI DJ console prototype" width="600">`{=html}
```{=html}
</p>
```
> This is the current prototype. The design, control mapping, and
> hardware are expected to evolve as development continues.

------------------------------------------------------------------------

## 🔮 Future Ideas

Some ideas I'm considering for later versions:

-   Custom MIDI mapping profiles
-   Multiple operating modes
-   More advanced LED effects
-   OLED / display feedback
-   Improved fader mechanisms
-   Custom PCB
-   Modular control sections
-   A proper enclosure
-   Preset storage
-   Integration with custom DJ software

------------------------------------------------------------------------

## 🤝 Contributions

This is primarily a personal build and learning project, but ideas,
suggestions, and technical discussion are welcome.

If you spot something interesting, have a better approach, or want to
discuss MIDI hardware, feel free to open an issue.

------------------------------------------------------------------------

## ⭐ If you like DIY hardware...

Give the project a ⭐ and follow along as the controller evolves.

**One button at a time. One MIDI message at a time. 🎛️**
