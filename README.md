# Forest Fire Simulation in C++ with Qt

## Objectives / Introduction

This project aims to create an interactive forest fire simulation using the C++ programming language and the Qt library for the graphical interface. Forest fires are complex natural phenomena that pose challenges in terms of understanding and management. This simulation will allow us to explore the behavior of fire propagation in different environments and conditions.

![Capt2ure](https://github.com/Lxvxo/Forest-fire-propagation-in-C-/assets/113984090/d077e9d7-575b-4fd5-8d37-8648322de6da)

## Grid Implementation

The simulation grid represents the forest area where the fire spreads. It is implemented using C++ classes and is capable of managing different cell states (trees, fire, ashes, etc.).

## Interface Implementation (window, render_area)

The graphical interface of the simulation is created with Qt. It consists of a main window and a rendering area where the forest grid is displayed. At the start of the simulation, the rendering area shows a forest with only trees.

## Random Grid Generation

The forest grid is randomly generated with different terrain configurations. This step allows observing how fire propagation varies depending on the initial distribution of cells (trees, lakes, rocks, etc.).

## Cell Behavior

Grid cells react differently depending on their state and that of their neighbors. For example, a tree catches fire if it is in contact with another tree on fire, and it turns into ashes after burning.

## Ignition of Fire

A method is implemented to ignite the fire in the simulation. This step allows observing how fire spreads in the forest and how it affects surrounding cells.

## Shortest Path Finding

A breadth-first search algorithm is used to find the shortest path between a tree and a fire. This helps understand how fires spread in different directions and which areas of the forest are most vulnerable.

## Questions

At the end of the report, questions can be asked to encourage reflection on the simulation results and possible improvements or extensions of the project.

## Conclusion

This project demonstrates how computer simulation can be used to study and understand complex natural phenomena such as forest fires. By using an object-oriented programming approach in C++ and leveraging the graphical features of the Qt library, we were able to create an interactive and visually informative simulation.
