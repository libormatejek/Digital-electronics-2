# Lab 5: Display devices, 7-segment display

### Learning objectives

The purpose of the laboratory exercise is to understand the serial control of four seven-segment displays (SSDs) using a pair of 74595 shift registers. In addition, the goal is to master the use of interrupts in applications with AVR.

![Multi-function shield](Images/arduino_uno_multi-shield_segments.jpg)


## Preparation tasks (done before the lab at home)

Read the [7-segment display tutorial](https://www.electronics-tutorials.ws/blog/7-segment-display-tutorial.html) and find out what is the difference between:
   * Common Cathode 7-segment display (CC SSD)
   * Common Anode 7-segment display (CA SSD)

In the following table, write the binary values of the segments for display 0 to 9 on a common anode 7-segment display.

   | **Digit** | **A** | **B** | **C** | **D** | **E** | **F** | **G** | **DP** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
   | 1 |   |   |   |   |   |   |   |   |
   | 2 |   |   |   |   |   |   |   |   |
   | 3 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |
   | 4 |   |   |   |   |   |   |   |   |
   | 5 |   |   |   |   |   |   |   |   |
   | 6 |   |   |   |   |   |   |   |   |
   | 7 |   |   |   |   |   |   |   |   |
   | 8 |   |   |   |   |   |   |   |   |
   | 9 |   |   |   |   |   |   |   |   |

Use schematic of the [Multi-function shield](../../Docs/arduino_shield.pdf) and find out the connection of seven-segment display. What is the purpose of two shift registers 74HC595?

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;
