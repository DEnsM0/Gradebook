# Gradebook Project

**Note:** The program interface is implemented in Ukrainian.

This repository contains the source code and documentation for a course project developed during my first year at the university as part of an Object-Oriented Programming (OOP) course. The project implements the functionality of a "Gradebook," allowing users to manage and record exams for students.

## Project Description

In this course project, I chose a program to manage a gradebook. The software allows users to input, display, save to a file, and load from a file exam data using C++ and Object-Oriented Programming principles.

### System Overview

The project focuses on modeling entities related to student exams in a gradebook. The key entities include students, professors, exams, and the gradebook itself. The interaction between these entities is structured in a hierarchical manner. For example, exams contain information about specific tests, including details about the professor and student. The gradebook, in turn, holds instances of exams.

### UML Diagram

![UML_view][UML_view]

### Relevance

The program's relevance lies in its application to educational institutions. Streamlining the evaluation process enhances the efficiency of teachers, especially in remote learning scenarios.

## Task Statement

The problem statement required a thorough analysis of the subject domain, defining entities, attributes, and functions. The development of the object-oriented "Gradebook" software involved several stages, such as:

1. Creating an interface (`Interface`) with virtual methods.
2. Establishing an abstract class (`UniversityMember`) with a 'depart' (department) field and defining default, copy, and parameterized constructors, virtual destructor, getter, and setter methods.
3. Implementing a derived class (`Professor`) with 'surname' and 'pos' (position) fields, and overloading input, output, and assignment operators.
4. Creating a derived class (`Student`) with 'surname' and 'group' fields, and similar operator overloads.
5. Developing a class (`Exam`) with fields such as 'subject,' 'hours,' 'date,' and 'mark,' and appropriate operator overloads.
6. Introducing an abstract exception class (`Exception`) and derived classes (`DateExc`, `MarkExc`, `HoursExc`).
7. Constructing a template class (`Gradebook<C>`) for storing and managing an array of exams.
8. Designing an iterator class (`Iterator`) for working with arrays of objects.
9. Establishing a user-friendly interface for ease of program usage.
10. Implementing a polymorphic cluster in the class hierarchy based on virtual methods for displaying data on the console, inputting data from the console, and converting data to string format using late binding.

## Program Structure

The program comprises 10 .cpp files and 12 header files, including pairs of files describing class declarations and implementations (e.g., `UniversityMember.h`, `UniversityMember.cpp`, `Student.h`, `Student.cpp`, `Professor.h`, `Professor.cpp`, `Exam.h`, `Exam.cpp`, `Menu.h`, `Menu.cpp`, `Exception.h`, `Exception.cpp`, `DateExc.h`, `DateExc.cpp`, `MarkExc.h`, `MarkExc.cpp`, `Hours.h`, `Hours.cpp`). The main header file, `Header.h`, is used for including all necessary external libraries. Additionally, the interface file, `Interface.h`, and the template class file, `Gradebook.h`, are included.

### Program Structure Description

The program's structure is outlined as follows:

1. **Interface and Header Files:** Initially, the project included the creation of the interface (`Interface`) with three pure virtual functions. The main header file (`Header.h`) was introduced to accommodate external libraries necessary for project implementation.

2. **Base Class - `UniversityMember`:** The base class `UniversityMember` was created with required fields, constructors, virtual destructor, overloaded assignment operators, and input/output operators. Getters and setters were also implemented for the corresponding field.

3. **Derived Class - `Student`:** Similar to the base class, the `Student` class was created, inheriting from `UniversityMember`. It included overridden functions from the `Interface` interface.

4. **Derived Class - `Professor`:** The `Professor` class, also inheriting from `UniversityMember`, had its own fields and methods, such as a group of fields, getters, and setters. Function overrides were implemented as well.

5. **Class - `Exam`:** The `Exam` class, derived from both `Student` and `Professor` classes, combined fields and methods from both. It included specific fields for the subject, exam date, and type. Diamond inheritance was implemented with `UniversityMember`.

6. **Template Class - `Gradebook<C>`:** This container class for type `C` (utilized for type `Exam`) included methods such as `push_back`, `pop_back`, `empty` check, `clean` for container clearance, and `size` for returning the actual container size. Additionally, `print` and `printSort` methods were implemented for console output.

7. **Iterator Class - `Iterator`:** Created for convenient interaction with the `Gradebook<C>` class.

8. **User Interface - `Menu`:** This class simplified user interaction, providing an interface for creating menu items and assigning specific actions to each. A structure, `MenuItem`, was used to store actions as `std::function<void()>`. Console handling with Win32 API was employed for menu item display.

### Getting Started

To start the project, follow these steps:

1. Clone the repository to your local machine using the following command:

    ```bash
    git clone https://github.com/DEnsM0/Gradebook
    ```

    Replace `your-username` with your GitHub username.

2. Navigate to the project directory.

3. Explore the source code, documentation, and UML diagram to understand the project structure.

### Project History

This project was developed during the summer semester of 2022.

Happy coding!

[UML_view]:https://imgur.com/a/gRF43ns