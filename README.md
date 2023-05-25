# Shape Parser
## Getting Started
- Author: Nguyen Hoang Phuc
- Summary descriptions: An application to parse data of shape from file .txt and print it to screen.
- Technologies: OOP, Static-link library, Dynamic-link library, Design Pattern (Singleton, Strategy, Factory, Prototype, Builder, Mapper), MVC model, SOLID.  
- Version: 
  - Visual Studio 2022 (V143)
  - ISO C++20 Standard

## About Project
- Project using OOP concept, with application architecture following MVC pattern. 
- This project can dynamically injection of shape, which mean you can write more type of shape (ofcourse you must be create DLL project in this solution) with out rebuild all solution. Just build your dependencies and program will work perfectly.
- Directry tree:
```
ShapeParser: 
  |-- Exception (static library)
  |-- utils (static library)
  |-- ShapeParser
  |      |-- Controller (IParser, IConverter, Factory)
  |      |-- Model (IShape)
  |      |-- View (Printer, IStrategy)
  |-- [Another shape DLL project]
```

- You must be config the export file dll of new shape following this format:
```
api-shape-$(solution_name).dll
```

## About source code
- Structure of input data (you can change whatever format you want and adjust the Regex pattern in class ShapeParser):
```
[Shape 1]: [shape attribute 1], [shape attribute 2],....
[Shape 2]: [shape attribute 1], [shape attribute 2],....
....
```
More detail:
```
[Shape]: Now program can parse Circle, Triangle, Square, Rectangle. You can write more shape by your self by adding another DLL project for this solution
[Shape attribute i]: 
  - Square: a=[value]
  - Triangle: a=[value], b=[value], c=[value]
  - Circle: r=[value]
  - Rectangle: w=[value], h=[value]
```

## Limitation
- Because of I'm using DLL in C++ so I'm not able to manage memory as well. There are many way to prevent memory leak (like using smart pointer, change state of code..) I'll update later.

## Author and References

- If you wanna replicate this project or catch any problem, contact to me:
>Outlook: 21120530@student.hcmus.edu.vn

- If you use this repository for your project in University, please cite me with information as below:

```
Nguyen Hoang Phuc, Falcuty of Information Technology, VNU - Ho Chi Minh University of Science
```
