# FdF
École 42 assignment in C - 3D points and lines plotting

### About this project
* This is a solo project of [École 42](https://42.fr)
* FdF stands for "Fils de Fer" in French or wireframe in English.
* The objective is to take the map and plot its points and lines in at least 2 types of 3D projection.
* In this project, I set a default projection to isometric projection and if you rotate it, you will get parallel projection.

![thailand](/screenshot/thailand.png?raw=true)

### The map
* The map contain a list of coordinates.
* The horizontal position corresponds to its axis.
* The vertical position corresponds to its ordinate.
* The value corresponds to its altitude.

![map](/screenshot/map.png?raw=true)

### How to run the program
* (I use MinilibX from the school system and don't have the library in this repo.)
* Run Makefile to create executable "fdf"
	```
	make
	```
* Usage
	```
	./fdf [map]
	```
* I included some sample maps in the folder "maps". To run it.
	```
	./fdf maps/42.fdf
	```

![42](/screenshot/42.png?raw=true)

### Bonus
* The color goes from blue to green according to the magnitude.
* X-axis rotation with key 5 and 8.
* Y-axis rotation with key 4 and 6.
* Z-axis rotation with key 7 and 9.
* Adjust height level with key 2 and 3.
* Zoom in and out with key + and -.
* Move the map with arrow keys.
* The object is default to the center of the viewpoint.
* Also using image instead of pixel in MiniLibX to gain more performance (if you count it as a bonus.)

### The algorithm I used
* I used Bresenham's line algorithm for line plotting.
* I used basic trigonometry in 3D rotation.