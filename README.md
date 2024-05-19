# **3D ASCII Renderer for OBJ Files**

## Overview
This tool is designed to render 3D objects from OBJ files into ASCII art directly on your console/terminal.
It leverages simple yet effective graphics programming techniques to project and display 3D models in a two-dimensional ASCII format. 
Users can load any `.obj` file and see it rendered dynamically with support for basic rotational interactions using the keyboar (only left and right for now).

## Features
- **File Loading:** Ability to load any `.obj` file, as long as its named "yourModel.obj" (i have included the one i used.)
- **Real-time ASCII Rendering:** Converts 3D models into ASCII representation in real time.
- **Interactive Controls:** Rotate the object left or right using the arrow keys for different perspectives.
- **Console-based Visualization:** Utilizes the terminal to display ASCII art, optimizing for simplicity and performance.

## How It Works
- **Vector Operations:** Handles basic vector operations like subtraction, cross product, and normalization.
- **Rotation and Projection:** Implements functions to rotate the model around the y-axis and project 3D coordinates to 2D.
- **Rendering Loop:** Continuously updates the rendering on the console, providing a dynamic view of the 3D model and clears the console to get rid of trailing.

## Dependencies
- Standard C++ libraries: 
- `<iostream>`
- `<fstream>`
- `<sstream>`
- `<vector>`
- `<cmath>`
- `<string>`

## Planned Updates
- **Deferred Shading Implementation:** Upgrade the renderer to simulate realistic lighting and shadows using deferred shading techniques, enhancing visual depth and realism.
- **OpenGL Integration:** Integrate the renderer with OpenGL to leverage hardware acceleration and improve rendering efficiency.
- **Advanced Projection Algorithms:** Implement more sophisticated projection algorithms to enhance the accuracy and detail of the ASCII art output. (cope)
- **Interactive Features Enhancement:** Expand control options to include scaling and more complex rotational maneuvers, providing a more interactive user experience.

## Demonstration
- Here's a brief look at what rendering an OBJ file in ASCII looks like in the console: (obj from belnder's mesh collection!)

![Alt text](https://i.imgur.com/vJvYzRd.gif) (gif takes some time loading.)

![Alt text](https://i.imgur.com/vJN0VEi.gif)

## license
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute it.

#### this is an old project from my old github which was hacked.
