# DIY Arduino HOTAS Flight Deck ✈️

![Status](https://img.shields.io/badge/Status-Work%20In%20Progress-red)
![License](https://img.shields.io/badge/License-GPLv3-blue)

A customisable DIY flight deck designed for computers (exp.personal computers and laptops) that implements HOTAS (Hands-On-Throttle-And-Stick), rudder, etc., built with an Arduino Pro Micro, along with several rotary sensors and buttons. This flight deck aims to be compatible with ALL flight simulators that accept standard axes and button inputs from a typical USB HIB Game Controller.

##  Motivation: Why Build This? 💡

This is a personal project born out of a desire for a more rewarding and educational challenge. Instead of simply buying a commercial, entry-level plastic joystick or dropping a massive amount of money on a high-end retail HOTAS system, I wanted to design and build my own from scratch. 

Prior to starting this project, I had **no prior experience with C++ programming or hardware electronics modules**. Every step of this build represents a completely fresh learning curve.

By building this flight deck myself, I am able to:
* **Maximize Cost-Efficiency:** Creating a fully functional multi-axis controller for a fraction of retail price using affordable, accessible maker components.
* **Enrich My ICT & Engineering Knowledge:** Gaining hands-on, practical experience with embedded hardware systems, C++ micro-controller programming, USB HID architecture, 3D mechanical design/CAD modeling and circuit routing.
* **Bridge Theory with Reality:** Applying core Information and Communication Technology (ICT) concepts directly to a tangible, physical piece of engineering.
* **Achieve Complete Customization:** Building a tailored physical layout designed exactly around the desktop flight simulation experiences I enjoy.
---

##  Project Status & Roadmap 🔨

❗️This project is **actively under development**! Here is where things stand:

 - [x] **Electronics Proof of Concept:** Wired up the Arduino Pro Micro, rotary potentiometers, and buttons on a temporary breadboard rig.
 - [x] **Prototype Firmware:** Wrote basic test code to verify the Arduino compiles hardware signals and reads pin states correctly.
 - [x] **Hardware Validation:** Completed initial prototype testing to ensure the basic wiring, test code, and sensor inputs work flawlessly. Successfully flight-tested and calibrated axes in **GeoFS** and **Infinite Flight** via Map Connect v2. 
 - [ ] **System Design & Blueprinting:** Drafting the comprehensive mechanical concept for how the entire ecosystem (throttle quadrant, joystick mechanism, and rudder pedals) integrates together.
 - [ ] **Dimensions & Layout:** Finalizing physical measurements, clearances, and ergonomic spacing requirements.
 - [ ] **3D Modeling & CAD:** Designing structural housings, pivot linkages, and control surfaces in Onshape for future fabrication.
---

##  Hardware & Component List 🕹️

The project currently uses the following hardware stack:
 - **Microcontroller:** **Arduino Pro Micro (ATmega32U4 chip)** — Chosen for its native USB HID capabilities to act as a direct plug-and-play joystick.
 - **Inputs:** **贝科姆 (Beckham) Rotation Sensor Modules** (3-pin)(Analog Axes for throttles, pitch, roll, yaw, brakes, etc.) & **贝科姆 (Beckham) Tactile Push Button Modules (KY-004)**
 - **Prototyping:** **Full-Size (830 Tie-Point/Hole) Solderless Breadboard**, **DuPont Jumper wires** **(M-M,M-F)**, and an improvised cardboard stabilizing bracket for hardware validation.

---

##  Software & Connectivity 💻

* **Language:** Arduino **(C++)** using the **`joystick`** library (by Matthew Hehr) to emulate a generic USB game controller.
* **Connection:** **Direct USB HID interface** — no external network bridge or driver software required for desktop simulators.

---

##  Acknowledgements & Credits 🙌

* Project concept, physical wiring, hardware improvisation, and flight testing executed by me.
* Core USB HID joystick code drafting, component selection advice assisted by **Gemini (Google AI)** as a development co-pilot.
