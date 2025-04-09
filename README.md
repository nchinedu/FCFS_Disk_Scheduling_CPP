# FCFS Disk Scheduling Simulator

A C++ implementation of the First-Come-First-Serve (FCFS) disk scheduling algorithm. This program simulates how disk requests are processed in the order they arrive, calculating and visualizing the total seek time and movement patterns.

## Features

- FCFS disk scheduling simulation
- Interactive menu-driven interface
- Custom input support
- Visual representation of disk head movement
- Detailed statistics (total and average seek time)
- Input validation and error handling
- Configurable disk size

## Prerequisites

To compile and run this program, you need:
- C++ compiler (GCC recommended)
- Basic command line knowledge

## Installation

1. Clone the repository or download the source code
2. Navigate to the project directory
3. Compile the program using:
```bash
g++ main.cpp -o disk_scheduler.exe
```
4. Run the executable:
```bash
./disk_scheduler.exe
```

## Usage

1. Upon running the program, you will be presented with a menu.
2. Choose option 1 to input disk requests interactively.
3. Enter the number of requests and their positions.
4. Choose option 2 to simulate FCFS disk scheduling.
5. The program will display the total seek time and movement patterns.

