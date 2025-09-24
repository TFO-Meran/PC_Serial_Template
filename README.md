# SampleProject_CPP
..a sample project structure for cpp programming with VSCode, CMake and MinGW, suitable for Linux, Windows and Mac platforms.



This Repo was created specifically for **TFO-MERAN(O)** - a high school in South-Tyrol, Italy. It is a **work-in-progress for teaching purposes** and has no ambitions for completeness or absolute perfection.
However, everyone is encouraged to use it and to make proposals for improvements.

Happy programming!


## PREREQUISITES
You need have a working installation of VSCode and the following extensions:
1.  C/C++ from Microsoft
2.  C/C++ Extension Pack from Microsoft
3.  CMake Tools from Microsoft

Also, you need to have 
- [MinGW](https://www.mingw-w64.org/downloads/) 
- [CMake](https://cmake.org/download/) 

installed and accessible through the PATH-variable.

You should also have a working GIT-environment.

## GETTING STARTED
### Start new Project:
After cloning the sample project, you should first change the project name. This can be achieved by editing the "CMakeLists.txt" and changing the first argument in the project() call.

Example:

`project(MyProgram VERSION 0.1.0)` -> "MyProgram" becomes the Project Name

After this, you should call the ">CMake: Delete Cache and Reconfigure" function by pressing F1 or Ctrl+Shift+P and selecting the corresponding entry.
