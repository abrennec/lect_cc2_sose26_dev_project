## Ai- Reflection

### Homework Assignment #2:

#### *Task 1.1*

process + ai usage:
- We discussed how to split functions and if we need to use classes
- Realized member functions need the class name to use member variables
- Splitted up the function and added member functions to the class
- Used Claude for general solution to compaire
- Implemented missing peaces 
- Iteratively tested and debugged the code

#### *Task 1.2*

process:

- looked at old examples and documentation and tried to implement 3D object

Mistakes:
- Wrong ofDrawIcoSphere() parameters: sphere rendered incorrectly
- Missing ofEnableDepthTest(): 3D objects rendered visually wrong
- Missing ofEnableLighting(): light had no visible effect
- Wrong light position: lighting looked flat/invisible
- Missing ofMaterial: lighting did not react properly on objects
- Wrong draw order: 2D grid covered 3D scene
- Depth test active for 2D overlay: pixel grid disappeared
- Double translation of sphere: wrong object positioning -> we kept that since we liked it

Ai usage:
- Explained OpenFrameworks rendering pipeline
- Identified syntax and logic errors 
- Suggested correct draw order and lighting setup
- Helped debug compile/runtime issues
- Generated/refactored code examples
- Explained C++ concepts and OpenFrameworks functions

#### *Task 2.1*

process:
- Brainstorming without AI


#### *Task 2.2—pixel sorting*
- Looking at tutorials
- Looking at old files and documentation
- Trying to implement it on my own
- Suffer from failure and ask AI, since everything else took longer than 10h.

Reflection:

Since this effect required multiple loops and nested functionality, I needed help from AI. I still wrote the code myself instead of simply copying it so I could learn the syntax, and I also asked questions to better understand how it works.