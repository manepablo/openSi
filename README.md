# openSi: A User-Friendly Platform for VLSI Design and Verification

Welcome to the openSi GitHub Repository! Our mission is to create a modern, user-friendly platform for VLSI design and verification. The accessibility of tools for chip design is often limited by high licensing fees, proprietary restrictions, and a steep learning curve. While free, open-source alternatives exist, they can be challenging to set up and lack user-friendly interfaces. openSi aims to bridge this gap, providing an open-source solution that is accessible to individuals, educational institutions, and small companies alike. Our goal is to lower the barriers to entry in chip design, fostering innovation and independence from proprietary software.

## Project Vision

openSi seeks to offer a single installer that deploys the software along with all necessary dependencies. We envision the possibility of including a preselection of available open-source PDKs (Process Design Kits), chosen by the user to streamline the setup process.

## Get Involved

We are at the initial stages of forming a team and outlining the software composition. Your ideas, suggestions, and contributions are invaluable to us. If you are interested in contributing to the project or have ideas to share, please don't hesitate to reach out. You can [email me](mailto:maneapaul@gmail.com) or request to become a contributor to this project.

## Software Composition

openSi will integrate various new and existing EDA (Electronic Design Automation) tools. Below are some components we are considering, based on preliminary research. Note that these are initial suggestions, and we welcome further input from the community.

### PDK Tools

- **[open_PDK](https://github.com/RTimothyEdwards/open_pdks)**: A tool for managing PDKs. Currently, SkyWater and GlobalFoundries PDKs are open source. We hope to see more PDKs available in the future, including those for more modern nodes.
- **[kiCAD_PDK](https://github.com/lethalbit/kicad-pdk-libs)**: A PDK management tool for KiCad, providing library support for various design kits.

### Schematic Design

- **KiCad**: An open-source tool for schematic entry and PCB design, with potential for analog VLSI design. We plan to fork KiCad to specialize it for analog VLSI design, leveraging its existing tools and community support.

### Simulator GUI

- The GUI for simulation could integrate aspects of the LTspice interface, known for its user-friendly design, while incorporating the necessary features for analog design such as corner analysis, Monte Carlo simulations, and sweeps.

### SPICE Simulation

- **[ngspice](https://github.com/ngspice/ngspice)**: An open-source SPICE simulator for analog electronic simulations.

### Layout

- **Magic**: A starting point for layout design, albeit dated. We propose forking and modernizing Magic. Incorporating elements from KiCad's PCB layout tool could be considered, though layout design will not be our initial focus.
