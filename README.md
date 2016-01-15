# 3D-Graphics-Engine
This is a 3-D graphics engine made for my stupid no good graphics practical.

#BUILDING PROCEDURE
You need to get the graphics.h file from Turbo C++
Other than that ,the files should build in any decent IDE
(I personally used the CodeBlocks IDE for this)

The functionality of this engine includes: 

#Feature List

#Starting The Game
Game g;

#Drawing 2D scalar shapes which include
##Lines
g.line(x1,y1,x2,y2,COLOR);

##Ellipses
g.ellipse(a,b,xCenter,yCenter,COLOR);

##Circles
g.circle(int xCenter,int yCenter,int radius,int COLOR);

##Polygons
Polygon p(points,COLOR) 
The variable points is a vector of a Struct named Point. It contains the x,y and z data items

Displaying the Polygon
p.display();

#Drawing curves

Curve c;

You can draw two types of curves

1) Hermite Curve
c.drawHermiCurve(Point a1,Point at1,Point a2,Point at2,double COLOR)

2) Bezier Curves
c.drawBezierCurve (Point a1,Point a2,Point a3,Point a4,int COLOR)



#Colouring
Colour c(Polygons polygon,int COLOR,int flag)

You can use scanfill for colouring
c.seedfill(Point point,int COLOR)



#3D object
Cuboid 'cuboid *cub1 = new cuboid(size);`

Size gives the size of a side of a cube, use scaling and rotation for further positioning Hidden face elimination is included in the working

cub1->setcolors(color1,color2,color3,color4,color5,color6);

Set the colors for the faces of cube

cub1->view_z_color(color);

View the figure with faces filled with corresponding color, here color parameter is the color of edges
cub1->view_z(color);

View the figure without filled colors, here color parameter is for edge color
cub1->rotatez(angle);
rotate along z axis
cub1->scale(xscale,yscale,zscale);
scaling
delete cub1

Removes object from screen
cub1->rotatex(angle);
rotate along x axis
cub1->rotatey(angle);
rotate along y axis

#Pull Requests to make the engine better aremost welcome
I'll look the proposed changes over and push them in if they're good.
