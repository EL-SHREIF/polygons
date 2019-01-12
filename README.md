# polygons
<h2>Project Description</h2>
<p>It is required to develop a program to do operations on polygons data. The program use a defined string format to represent polygons. All polygons will be in one line input. For example:
Polygons=[(1,1),(4,1),(4,5),(1,5);(3,4),(6,4),(6,12),(3,12)]</p>


<h2>Polygons Data</h2>
<p>The Polygons line contains a list of polygons data separated by ‘;’. Fields of a Polygon is represented by a set of points separated by ‘,’. The number of polygons are up to 1000 polygon. Each polygon has up to 100 points.</p>
<h3>Definition of Redundant Point</h3>
<p>A redundant point is a point of the polygon points that can be deleted without change in the polygon shape. Like 
(1,1),(2,1),(4,1),(4,3),(1,3)
(1,2),(4,2),(4,2),(4,8),(1,8)
(1,2),(4,2),(4,2),(4,2),(4,8),(1,8)
In the second case two neighbor identical points any one of them can be redundant (you should select only the second one). If more than two points are identical and follow each other, all of them are redundant except the first point of them.</p>
<h3>Intersecting Polygons</h3>
Intersecting Polygons are polygons sharing common area, side, or point(s).
<h3>Connected Polygons</h3>
Two Connected Polygons are polygons that are intersecting or polygons which have path from one to the other through intersecting polygons.
<h2>Operations</h2>
When the program start, the user enters one Polygons Line in the defined above format then followed by one or more operations from the below table (each operation in a line). The program ends when it reads Quit operation.
 
