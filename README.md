Fractol
Fractol is a visually stunning C program that renders Mandelbrot, Julia, and Burning Ship fractals using the MiniLibX library. This project, optimized for performance and readability, allows users to explore fractals with interactive controls for zooming, panning, color cycling, and dynamic Julia set manipulation. It adheres to the 42 Norminette coding standards and is designed to be lightweight and efficient.
Table of Contents

Features
Installation
Usage
Controls
Project Structure
Contributing
License

Features

Renders three fractal types: Mandelbrot, Julia, and Burning Ship.
Interactive controls for zooming, panning, and color scheme changes.
Dynamic Julia set parameter adjustment via mouse movement.
Optimized for low CPU and memory usage.
Clear instructions displayed on program launch.
Compliant with 42 Norminette standards for clean, maintainable code.

Installation
Prerequisites

A Unix-based system (macOS or Linux).
gcc or clang compiler.
MiniLibX library (macOS version included in the repository).
make utility for building the project.

Steps

Clone the repository:
git clone https://github.com/7ARZAN/fractal-42network.git
cd fractol


Ensure the MiniLibX library is in the project root (included as mlx/).

Compile the program:
make

This generates the fractol executable.


Notes

If MiniLibX is not working, you may need to install additional dependencies (e.g., X11 on Linux).
For macOS, the provided mlx folder should suffice.

Usage
Run the program with one of the following commands:
./fractol 1  # Mandelbrot
./fractol 2  # Julia
./fractol 3  # Burning Ship

For Julia with custom parameters:
./fractol 2 <real> <imag>  # e.g., ./fractol 2 -0.4 0.6

On launch, the program displays instructions for controls.
Example
To explore the Mandelbrot set:
./fractol 1

Use the mouse wheel to zoom and arrow keys to pan.
Controls



Action
Control



Zoom in/out
Mouse wheel up/down


Pan
Arrow keys (↑, ↓, ←, →)


Toggle Julia/Mandelbrot
P key


Reset view
R key


Cycle colors
C key


Increase iterations
Z key


Decrease iterations
N key


Toggle Julia dynamics
Spacebar or left mouse click


Quit
ESC or Q key


Project Structure
fractol/
├── include/
│   └── fractol.h       # Header file with structures and prototypes
├── src/
│   ├── control.c       # Keyboard and mouse event handlers
│   ├── draw.c          # Fractal rendering and pixel calculations
│   ├── main.c          # Program entry and initialization
│   └── utils.c         # Utility functions (parsing, instructions)
├── mlx/                # MiniLibX library (macOS)
├── Makefile            # Build automation
└── README.md           # Project documentation

Contributing
Contributions are welcome! To contribute:

Fork the repository.
Create a feature branch (git checkout -b feature/your-feature).
Commit your changes (git commit -m "Add your feature").
Push to the branch (git push origin feature/your-feature).
Open a pull request.

Please ensure your code follows 42 Norminette standards and includes appropriate tests.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Built with ❤️  by [tarzan]. Inspired by the beauty of fractals and the 42 school's coding challenges.
