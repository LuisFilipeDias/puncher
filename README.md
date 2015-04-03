# Clock Puncher

## Synopsis

**Clock Puncher** is a small and simple program to log the working hours at the office.

It has 5 different views:

* **Main**: start/edit/reset the clock. A small display indicates the hours counted so far;
* **Calendar [hotkey 1]**: see/change the daily hours for any past date, using the calendar app;
* **Raw [hotkey 2]**: inspect the raw data - debugging feature;
* **Weekly stats [hotkey 3]**: check the weekly hours in a graph display. Total hours, average hours and working days are also available;
* **Monthly stats [hotkey 4]** same as the weekly graph, but shows results on a monthly basis

This program can be built both for:

* Linux, using standard QT process & buildsystem;
* Windows, using qmake from command line. For more information following the cross-compilation tips in a section below;

## Code Example

Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Motivation

This project came to address a specific need from the maintainer to log the working hours at the office. 

There was no existing application that met the specific requirements at the time, so that's why this project came to be.

The motivation to log the hours comes not from company policies but from the need to self-manage the working hours (and to discourage too much extra-hours).


## Installation

Provide code examples and explanations of how to get the project.

## API Reference

Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.

## Tests

Describe and show how to run the tests with code examples.

## Contributors

* Luis Filipe Ribeiro Dias

all contacts available @ www.luisfilipedias.tk

To contribute:

## License

A short snippet describing the license (MIT, Apache, etc.)


## Cross-compilation tips

To cross-compile from linux to windows, use MXE: http://mxe.cc/

It uses qmake. Instructions can be found here: http://stackoverflow.com/questions/10934683/how-do-i-configure-qt-for-cross-compilation-from-linux-to-windows-target
