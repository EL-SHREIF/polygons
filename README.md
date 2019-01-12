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
 
<h1>FUNCTIONS:</h1>
<table style="width:100%">
  <tr>
       <th><p align="center">
           Number_Polygons
        </p>
    </th>
        <th><p align="center">
          Print the number of polygons.
    </th>
  </tr>
  <tr>
       <th><p align="center">
           Total_Number_Points
        </p>
    </th>
        <th><p align="center">
          Print the total number of points in all polygons.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Minimum_X
        </p>
    </th>
        <th><p align="center">
         Print the minimum X value of all points.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Maximum_X
        </p>
    </th>
        <th><p align="center">
         Print the maximum X value of all points
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Minimum_Y
        </p>
    </th>
        <th><p align="center">
          Print the minimum Y value of all points.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Maximum_Y
        </p>
    </th>
        <th><p align="center">
          Print the maximum Y value of all points
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Enclosing_Rectangle
        </p>
    </th>
        <th><p align="center">
          Print the minimum Enclosing Rectangle that includes all polygons inside it.
    </th>
  </tr>
  <tr>
       <th><p align="center">
           Total_Redundant_Points
        </p>
    </th>
        <th><p align="center">
          The number of Redundant points in all polygons
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Quit
        </p>
    </th>
        <th><p align="center">
          End program
    </th>
  </tr>
 
 <tr>
       <th><p align="center">
          Polygon_Points n
        </p>
    </th>
        <th><p align="center">
          List all points of the nth polygon (neglecting redundant points) n start from 1 (1 means the first polygon) output should be in the same format of input polygons string i.e. 
(1,1),(4,1),(4,2),(1,2)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Point_Polygons (2,1)
        </p>
    </th>
        <th><p align="center">
          List all polygons IDs (ID is 1 for the first polygon, 2 for the second polygon,...)  of polygons that have the point (2,1) in their points list 
The output is a comma separated IDs of polygons having the point like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Polygons_Points More n
        </p>
    </th>
        <th><p align="center">
          List Polygons having more than n points excluding redundant points where n is an integer.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Polygons_Points Less n
        </p>
    </th>
        <th><p align="center">
         List Polygons having less than n points excluding redundant points where n is an integer.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Polygons_Points Equal n
        </p>
    </th>
        <th><p align="center">
          List Polygons having exactly n points excluding redundant points where n is an integer.
The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Points_Polygons More n
        </p>
    </th>
        <th><p align="center">
          List all Points that are in the list of more than n polygons where n is an integer.The output is a comma separated points like
(3,2),(4,1)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Points_Polygons Less n
        </p>
    </th>
        <th><p align="center">
          List all Points that are in the list of less than n polygons where n is an integer.The output is a comma separated points like
(3,2),(4,1)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Points_Polygons Equal n
        </p>
    </th>
        <th><p align="center">
          List all Points that are in the list of less than n polygons where n is an integer.The output is a comma separated points like
(3,2),(4,1)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Polygon_Perimeter n
        </p>
    </th>
        <th><p align="center">
          Print the perimeter of the nth polygon.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          List_Triangles
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that are triangles.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
 <tr>
       <th><p align="center">
          List_Rectangles
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that are rectangles.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
   <tr>
       <th><p align="center">
          List_Trapezoid
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that are trapezoid.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
   <tr>
       <th><p align="center">
          Inside_Rectangle (1,2),(1,5),(6,5),(6,1)
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that are inside the given rectangle.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
   <tr>
       <th><p align="center">
          Inside_Circle (1,2),5
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that are inside the given Circle (Center, radius in the format (1,2),5 ).The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
   <tr>
       <th><p align="center">
          Polygon_Area n
        </p>
    </th>
        <th><p align="center">
          Print the polygon area of the nth polygon
    </th>
  </tr>
  <tr>
       <th><p align="center">
         Polygons_Area_Range minArea,maxArea
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that have area <= minArea and >=maxArea.The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Polygons_Enclosing_Point (1,2)
        </p>
    </th>
        <th><p align="center">
          List all Polygon IDs of polygons that have the point (1,2) inside it (or on its boundaries).The output is a comma separated IDs of polygons like
2,4,6,10
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Is_Intersecting i,j
        </p>
    </th>
        <th><p align="center">
          Print TRUE if ith polygon intersects the jth polygon
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Intersecting_Group 3,5,6
        </p>
    </th>
        <th><p align="center">
          Print TRUE if the list of polygon are all intersecting with each other (each one is intersecting with all other polygons)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Largest_Intersecting_Pair
        </p>
    </th>
        <th><p align="center">
         Print the two IDs of polygons that are intersecting and having the largest sum of area.The output is a comma separated IDs of polygons like 2,4
    </th>
  </tr>
  <tr>
       <th><p align="center">
         Largest_Rectangle_Inside n
        </p>
    </th>
        <th><p align="center">
         Print the largest rectangle that can inside the nth polygon.output should be in the same format of input polygons string i.e. 
(1,1),(4,1),(4,2),(1,2)
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Largest_Circle_Inside n
        </p>
    </th>
        <th><p align="center">
          Print the largest circle that can inside the nth polygon.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Is_Connected i,j
        </p>
    </th>
        <th><p align="center">
          Print TRUE if ith polygon is connected to the jth polygon
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Is_Connected_Group 1,2,5
        </p>
    </th>
        <th><p align="center">
          Print TRUE if all polygon in the list are connected.
    </th>
  </tr>
  <tr>
       <th><p align="center">
          Maximum_Intersecting_Group
        </p>
    </th>
        <th><p align="center">
          List polygon IDs forming the largest set of polygons that are intersecting (any ID should intersect with All other IDs in the list)
    </th>
  </tr>
  <tr>
       <th><p align="center">
         Maximum_Connected_Group
        </p>
    </th>
        <th><p align="center">
          List polygon IDs forming the largest set of polygons that are connected directly or indirectly (through another polygon)
    </th>
  </tr>
</table>
## Table of Contents

#### [Class point]
 - **Summary:** simple class of a point and some functions doing on it .
 
#### [Class Polygon]
 - **Summary:** a polygon made from some points with some functions on it.
 
#### [MAIN]
 - **Summary:** it deals with the user to take input and call the functions and return the output to print it .
 - **Keywords:** Consol application
 
<h2>[Also given a word file of sample input and the expected output ]</h2>
