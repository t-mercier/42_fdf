### 42_fdf

<a href="https://imgbb.com/"><img src="https://i.ibb.co/dcKc4HY/fdf-grade.png" alt="fdf-grade" border="0"></a>

#### Overview
`42_fdf` is a wireframe map generator that renders 3D landscapes from .fdf files. It's a project developed in pure C, utilizing the MinilibX library, focusing on window management and pixel manipulation techniques.

#### Controls
- **Usage On/Off**: Space
- **Close Window**: Esc
- **Move**: Arrow Keys
- **Zoom**: Mouse Scroll
- **Depth**: +/-
- **Flatten**: /
- **Rotation (Z, Y, X Axes)**: Q/W, A/S, Z/X
- **Rotate All Axes**: Page Up/Page Down
- **Color Switch**: 1-8
- **Motion Color**: 9
- **Blink Color**: 0
- **Reverse Color**: Right Shift

#### Installation and Usage
1. Clone the repository.
2. Compile with `make`.
3. Run `./fdf maps/<map.fdf>`.

#### Features
- Generates wireframe representations of relief landscapes.
- Handles .fdf format files for input data.
- Implements color management and transformations like zoom, translation, rotation, and Z-axis scaling.

#### Learning Objectives
- Mastering window management.
- Understanding of pixel-level rendering.
- Familiarization with 3D representation and transformations.

#### Technologies
- Language: C
- Graphics Library: MinilibX

#### Contribution
This project was developed by Timothée Mercier as part of the 42 programming curriculum. Contributions, suggestions, and feedback are welcome.
