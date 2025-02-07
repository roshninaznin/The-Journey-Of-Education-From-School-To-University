# The Journey of Education: From School to University 🎓🚍
![Total Scene](https://github.com/user-attachments/assets/c6710822-c4a7-4461-8aa4-7fb4ca9db0c6)



## Overview
The Journey of Education is an interactive OpenGL + GLUT simulation that visually represents a student's academic journey from school to university.

The project includes:

- Five dynamic scenes (School, College, University, Classroom, Transition)
- User-controlled buses (Yellow & Blue) for student transportation 🚍
- Gradient color effects
- Background music & sound effects 
- Keyboard & Mouse interactions for smooth control

The simulation follows a structured flow where students travel via buses, attend class, and finally graduate 🎓.



## Scenes & Flow

To experience the full journey, follow this sequence:

![Scene One by one](https://github.com/user-attachments/assets/c2c17a18-5b40-4681-8ec6-dec129b39ddb)

- Transaction Scene (Welcome) 
    - Press 1 → Displays a Welcome Message
- School Area 
    - Press 2 → Displays the School Scene
- Classroom (Rain Rain Rhyme) 
    - Press 5 → Displays "Rain Rain Go Away" text
- School Area Again (Bus Control Required) 
    - Press 2 → Control the Yellow Bus to let student to the bus
- Transaction Scene
    - Press 1 → Displays a "School to College" message
- College Area (Bus Control Required) 
    - Press 3 → Control the Yellow Bus to let student to the college
- Classroom (SCIENCE) 
    - Press 5 → Displays "SCIENCE" text
- College Area Again (Bus Control Required) 
    - Press 3 → Control the bus for student to the bus
- Transaction Scene
    - Press 1 → Displays a "College to University" message
- University (Bus Control Required) 
    - Press 4 → Control the Yellow Bus to let student to the university
- Classroom (Computer Graphics) 
    - Press 5 → Displays "Computer Graphics" text
- University Again (Graduation Scene) 
    - Press 4 → Shows graduated students 
- Transaction Scene (Thank You) 
    - Press 1 → Displays a "Thank You" message



## Controls

 - Scene Selection
   Press the following keys for different scenes:
   - 1 → Transaction (Welcome Scene)
   - 2 → School Area
   - 3 → College Area
   - 4 → University
   - 5 → Classroom
     
 - Bus Controls
   - 🚌 Yellow Bus (For Student Transport)
       - Press 6 → Yellow Bus Stops
       - Right Click Mouse → Move Yellow Bus Right
   - 🚌 Blue Bus (For Student Transport)
      - 7 → Blue Bus Stops
      - Left Click Mouse → Move Blue Bus Left


## Installation

1. Installation & Running the Project
  -  Clone the Repository
Clone the repository to your local machine:

```bash
    git clone https://github.com/roshninaznin/The-Journey-Of-Education-From-School-To-University
```
2. Then navigate to the project folder:

```bash
cd The-Journey-Of-Education-From-School-To-University
```

3. Prerequisites
Make sure you have the following installed:
  - CodeBlocks (or any C++ IDE with OpenGL support)
  - OpenGL & GLUT (for rendering graphics)
    
4. Setting Up CodeBlocks for OpenGL
   - Open CodeBlocks and go to Settings → Compiler
   - Under the Linker Settings tab, add the following libraries:
```bash
-lglut32 -lglu32 -lopengl32
```
Ensure your GLUT header files are included in your project directory.

5. Adding Music Files 
     - Go to your project's bin/Debug folder.
     - Paste the .wav music file in the folder.
This ensures the music plays correctly when you run the project.

6.  Running the Project
    - Open the project in CodeBlocks.
    - Click on Build and Run (or press F9).
Enjoy the educational journey from school to university! 🎓🚍🎶

  
## Built With
This project was built using the following technologies and tools:
  - C++ - The core programming language for the project.
  - CodeBlocks - The IDE used for development.
  - OpenGL - Graphics rendering for visual scenes.
  - GLUT - Library used for window management and user input handling.
  - .wav - Music format used for adding sound to the project.


## Contact

For more information, please contact:  

**Naznin Akter Roshmny** 
- Email: roshninaznin202@gmail.com
- Phone: 01956494298
