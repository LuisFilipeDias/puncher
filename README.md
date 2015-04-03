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

* **Linux**: using standard QT process & buildsystem;
* **Windows**: using qmake from command line. For more information follow the cross-compilation tips below;

## Motivation

This project came to address a specific need from the maintainer to log the working hours at the office. 

There was no existing application that met the specific requirements at the time, so that's why this project came to be.

The motivation to log the hours comes not from company policies but from the need to self-manage the working hours (and to discourage too much extra-hours).

## Installation

To install just clone the project into your machine, and launch the .pro file from the QT Creator;

## Tests

No unit-tests have been specified yet.

## Contributors

* Luis Filipe Ribeiro Dias

All contacts are available @ www.luisfilipedias.tk

To contribute just fork this project and then make a pull request whenever there are significative changes to merge the development branch into the master.

## License

**GNU General Public License v3.0**

The GNU General Public License is a free, copyleft license for software and other kinds of works.

## Cross-compilation tips

To cross-compile on **Linux** targeting **windows**, use MXE: http://mxe.cc/.

**Instructions:**

* Get it:

> git clone -b stable https://github.com/mxe/mxe.git

* Install build dependencies

* Build Qt 5 for Windows:

> cd mxe && make qt

* This will first build its dependencies and the cross-build tools; It should take less than an hour on a fast machine with decent internet access.
Due to the new modular nature of Qt 5, various major Qt components are now in different tarballs. The one selected above, qtbase, should give you enough functionality to run ordinary GUI apps, which is all I needed for my own (smallish) app.
If you want to build all of Qt 5 instead, you'll need to run make qt5 (instead of make qtbase). Note that it will take a lot longer to complete, so be sure that you need the extra functionality.

> export PATH=<mxe root>/usr/bin:$PATH

* Get to the directory of your app, and run the Qt Makefile generator tool:

> <mxe root>/usr/bin/i686-w64-mingw32.static-qmake-qt5

* You should find the binary in the ./release directory:

> wine release/foo.exe


(**Copyright**: http://stackoverflow.com/questions/10934683/how-do-i-configure-qt-for-cross-compilation-from-linux-to-windows-target)
