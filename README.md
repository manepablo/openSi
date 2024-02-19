# openSi: A User-Friendly Platform for VLSI Design and Verification

Welcome to the openSi GitHub Repository! Our mission is to forge a modern, user-friendly platform for VLSI design and verification. The journey into chip design is often hindered by steep licensing fees, proprietary barriers, and a challenging learning curve. Despite the existence of free, open-source alternatives, their setup complexity and lack of user-friendly interfaces can be daunting. openSi is here to bridge this gap, offering an open-source solution that's accessible to individuals, educational institutions, and small companies. Our aim is to dismantle the barriers to entry in chip design, promoting innovation and independence from proprietary software.

## Project Vision

openSi is committed to delivering a seamless installation process that bundles the software with all necessary dependencies. We're exploring the potential to include a selection of available open-source PDKs (Process Design Kits), allowing users to tailor the setup to their needs.

## Get Involved

At the foundation of openSi is a growing team, currently outlining the software composition. We value your insights, suggestions, and contributions immensely. We’re on the lookout for VLSI engineers familiar with the necessary tools and software-savvy individuals eager to contribute. If you're interested in joining our project or have ideas to share, we'd love to hear from you. [Email me](mailto:maneapaul@gmail.com) or request to become a project contributor. Together, let's democratize chip design!

## Software Composition

openSi aims to integrate a variety of new and existing EDA (Electronic Design Automation) tools. Here are some initial components under consideration:

### PDK Tools

- **[open_PDK](https://github.com/RTimothyEdwards/open_pdks)**: Manages PDKs, with SkyWater and GlobalFoundries PDKs currently open source. We hope that in the future the range of available PDKs, even at more modern nodes will increase.
- **[kiCAD_PDK](https://github.com/lethalbit/kicad-pdk-libs)**: A KiCad-based PDK management tool, enhancing library support for various design kits.

### Schematic Design

- **KiCad**: We plan to fork this powerful open-source tool for schematic entry and PCB design, tailoring it for analog VLSI design and leveraging its tools and community.

#### Netlist Entry

- Netlists can be generated using KiCad or through Python-based tools like [pySpice](https://github.com/PySpice-org/PySpice) for automated netlist generation.

### OpenSi Simulator

- Our GUI for simulation will draw inspiration from LTspice’s user-friendly design, incorporating key features for analog design such as corner analysis, Monte Carlo simulations, and sweeps. KiCad's GUI tools may also be adapted for simulation.
- The OpenSi simulator will be fully controllable via a Python interface for hardware testing and testbench generation.
- A Python-based calculator will be available within the simulator for modifying simulation outputs.
- Export options, including CSV, will be available for easy post-processing of simulation results.

### SPICE Simulation

- **[ngspice](https://github.com/ngspice/ngspice)**: An open-source SPICE simulator ideal for analog electronic simulations.

### Layout

- **Magic**: While dated, Magic serves as a starting point for layout design. We propose modernizing Magic, potentially integrating aspects of KiCad’s PCB layout tool, although layout design is not our immediate priority.

## Required Steps (Preliminary)

1. Automate the compilation and installation of open_pdk tools, making them accessible through a forked version of KiCad or a new tool.
2. Adapt KiCad for VLSI design by refining the GUI and stripping unnecessary PCB design features while introducing new functionalities.
3. Enhance KiCad's simulation GUI with advanced features for analog design, maintaining support for ngspice.
