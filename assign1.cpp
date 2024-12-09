/*
* Computer Graphics: Assignment 1
Team 8, members: Habiba Walid Hammouda, Mahy Elhelw, Mayar Ayman, Youssef Gamal

Statement:
Draw a 2D scene that makes sense using at least 2 other primitive types besides GL_POLYGON.
- Use different colors that serve the scene.
- Your scene should include at least 5 objects. The objects should be of reasonable sizes and positions.
(examples for what an object could mean: a house is 1 object, a car is 1 object, a sun is 1 object, ….. Etc). You
can create any objects of your choice.
- Add comments to explain your code.

Brainstorming ideas for scene:
-Pyramids
-Ocean
-House and car
-Boat in sea(final)
*/

#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Globals.
// Draw a polygon with vertices at equal angles apart on a circle.
// with center at (X, Y) and radius R
static int numVertices = 100; // Number of vertices on circle.
float t = 0; // Angle parameter.
int i;
///////////////////////////////////////////////////////////////////CLOUD1 (LEFT) START///////////////////////////////////////////////////

////////////////////////////////////CENTRE CIRCLE///////////////////////////////
static float R = 5.0; // Radius of circle.
static float X = 40.0; // X-coordinate of center of circle.
static float Y = 90.0; // Y-coordinate of center of circle.

////////////////////////////////////LEFT SMALLER CIRCLE///////////////////////////////

static float R1 = 4.0; // Radius of circle.
static float X1 = 35.0; // X-coordinate of center of circle.
static float Y1 = 88.0; // Y-coordinate of center of circle.

////////////////////////////////////RIGHT SMALLER CIRCLE///////////////////////////////

static float R2 = 4.0; // Radius of circle.
static float X2 = 45.0; // X-coordinate of center of circle.
static float Y2 = 88.0; // Y-coordinate of center of circle.

//////////////////////////////////////////////////////////////////CLOUD1 (LEFT) END///////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////CLOUD2 (RIGHT) START///////////////////////////////////////////////////
////////////////////////////////////CENTRE CIRCLE///////////////////////////////
static float R3 = 5.0; // Radius of circle.
static float X3 = 80.0; // X-coordinate of center of circle.
static float Y3 = 90.0; // Y-coordinate of center of circle.

////////////////////////////////////LEFT SMALLER CIRCLE///////////////////////////////

static float R4 = 4.0; // Radius of circle.
static float X4 = 74.0; // X-coordinate of center of circle.
static float Y4 = 88.0; // Y-coordinate of center of circle.

////////////////////////////////////RIGHT SMALLER CIRCLE///////////////////////////////

static float R5 = 4.0; // Radius of circle.
static float X5 = 86.0; // X-coordinate of center of circle.
static float Y5 = 88.0; // Y-coordinate of center of circle.

//////////////////////////////////////////////////////////////////CLOUD2 (RIGHT) END///////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////SUN START///////////////////////////////////////////////////

static float R6 = 7.0; // Radius of circle.
static float X6 = 12.0; // X-coordinate of center of circle.
static float Y6 = 90.0; // Y-coordinate of center of circle.

//////////////////////////////////////////////////////////////////SUN END///////////////////////////////////////////////////

//drawing routine of squares/rectangles (polygon)
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	////////////////////////////////////////THE SEA////////////////////////////////
	
	//setting a relaxing blue color for the sea
	glColor3f(0.0, 0.0, 1.0);

	//drawing the sea (rectangle)
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(100.0, 30.0, 0.0);
	glVertex3f(0.0, 30.0, 0.0);
	glEnd();

	////////////////////////////////////////THE BOAT CRIB////////////////////////////////

	//setting the black color for the boat crib
	glColor3f(0.0, 0.0, 0.0); //to be edited to brown later

	//drawing the boat crib (rectangle)
	glBegin(GL_POLYGON);
	glVertex3f(30.0, 30.0, 0.0);
	glVertex3f(70.0, 30.0, 0.0);
	glVertex3f(70.0, 40.0, 0.0);
	glVertex3f(30.0, 40.0, 0.0);
	glEnd();

	////////////////////////////////////////THE BOAT POLE////////////////////////////////
	
	//setting the black color for the boat crib
	glColor3f(0.0, 0.0, 0.0); //to be edited to brown later

	//drawing the boat crib (rectangle)
	glBegin(GL_POLYGON);
	glVertex3f(50.0, 35.0, 0.0);
	glVertex3f(52.0, 35.0, 0.0);
	glVertex3f(52.0, 75.0, 0.0);
	glVertex3f(50.0, 75.0, 0.0);
	glEnd();

	////////////////////////////////////////THE BOAT FLAG////////////////////////////////

	//drawing the boat flag (triangle)
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(50.0, 75.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(50.0, 50.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(40.0, 50.0, 0.0);

	glEnd();

	/////////////////////////////////////////////DRAW FISH 1 START//////////////////////////////////
	//drawing fish 1 body (triangle)
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.0, 0.0);
	glVertex3f(25.0, 15.0, 0.0);
	glVertex3f(25.0, 5.0, 0.0);
	glVertex3f(30.0, 10.0, 0.0);

	glEnd();
	
	//drawing fish 1 tail (triangle)
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.0, 0.0);
	glVertex3f(23.0, 8.0, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	glVertex3f(23.0, 12.0, 0.0);
	glColor3f(0, 0.0, 0.4);
	glVertex3f(25.0, 10.0, 0.0);

	glEnd();
	/////////////////////////////////////////////DRAW FISH 1 END//////////////////////////////////
	
	/////////////////////////////////////////////DRAW FISH 2 START//////////////////////////////////
	//drawing fish 2 body (triangle)
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.0, 0.0);
	glVertex3f(80.0, 28.0, 0.0);
	glVertex3f(80.0, 18.0, 0.0);
	glVertex3f(86.0, 23.0, 0.0);

	glEnd();

	//drawing fish 2 tail (triangle)
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.0, 0.0);
	glVertex3f(77.0, 26.0, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	glVertex3f(77.0, 20.0, 0.0);
	glColor3f(0, 0.0, 0.4);
	glVertex3f(80.0, 23.0, 0.0);

	glEnd();
	/////////////////////////////////////////////DRAW FISH 2 END//////////////////////////////////

	
	////////////////////////////////////////////////////CLOUD 1 START///////////////////////////////////////////////

	//////////////////////////////////////CENTER CIRCLE LOOP/////////////////////////
	glColor3f(1.0, 1.0, 1.0); //set color of cloud (white)
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();

	//////////////////////////////////////LEFT CIRCLE/////////////////////////

	glColor3f(1.0, 1.0, 1.0); //set color of cloud (white)
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X1 + R1 * cos(t), Y1 + R1 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();

	//////////////////////////////////////RIGHT CIRCLE/////////////////////////
	glColor3f(1.0, 1.0, 1.0); //set color of cloud (white)
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X2 + R2 * cos(t), Y2 + R2 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();
	///////////////////////////////////////////CLOUD 1 END/////////////////////////////////
	
	///////////////////////////////////////////CLOUD 2 START/////////////////////////////////
		//////////////////////////////////////CENTER CIRCLE LOOP/////////////////////////
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X3 + R3 * cos(t), Y3 + R3 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();

	//////////////////////////////////////LEFT CIRCLE/////////////////////////

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X4 + R4 * cos(t), Y4 + R4 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();

	//////////////////////////////////////RIGHT CIRCLE/////////////////////////
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X5 + R5 * cos(t), Y5 + R5 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();
	///////////////////////////////////////////CLOUD 2 END/////////////////////////////////

	///////////////////////////////////////////SUN START/////////////////////////////////

	glBegin(GL_LINE_LOOP);
	//glPointSize(1.0); // Set point size so that the outline is visible
	glColor3f(0.0, 0.5, 1.0); //outline color 
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X6 + R6 * cos(t), Y6 + R6 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X6 + R6 * cos(t), Y6 + R6 * sin(t), 0.0);
		t += 2 * M_PI / numVertices;
	}
	glEnd();
	///////////////////////////////////////////SUN END/////////////////////////////////


	///////////////////////////////////////////////////HUMAN START////////////////////////////////////////
	//drawing human head (sphere)
	glPushMatrix();
	glTranslatef(60.0, 64.0, 0.0); //move to the position of the head
	glScalef(3.0, 3.0, 0.0); //scale to the size of the head
	glColor3f(1.0, 0.8, 0.6); //set the skin color
	glutSolidSphere(1.0, 20, 20); //draw the sphere
	glPopMatrix();

	//drawing human body (cube)
	glPushMatrix();
	glTranslatef(60.0, 55.0, 0.0); //move to the position of the body
	glScalef(7.0, 10.0, 0.0); //scale to the size of the body
	glColor3f(0.7, 0.0, 0.1); //set the shirt color
	glutSolidCube(1.0); //draw the cube
	glPopMatrix();

	//drawing human left arm (cube)
	glPushMatrix();
	glTranslatef(55.0, 55.0, 0.0); //move to the position of the left arm
	glRotatef(-30.0, 0.0, 0.0, 1.0); //rotate the arm
	glScalef(3.0, 10.0, 0.0); //scale to the size of the arm
	glColor3f(0.7, 0.0, 0.1); //set the shirt color
	glutSolidCube(1.0); //draw the cube
	glPopMatrix();

	//drawing human right arm (cube)
	glPushMatrix();
	glTranslatef(65.0, 55.0, 0.0); //move to the position of the right arm
	glRotatef(30.0, 0.0, 0.0, 1.0); //rotate the arm
	glScalef(3.0, 10.0, 0.0); //scale to the size of the arm
	glColor3f(0.7, 0.0, 0.1); //set the shirt color
	glutSolidCube(1.0); //draw the cube
	glPopMatrix();

	//drawing human left leg (cube)
	glPushMatrix();
	glTranslatef(58.0, 42.0, 0.0); //move to the position of the left leg
	glScalef(3.0, 15.0, 0.0); //scale to the size of the leg
	glColor3f(0.0, 0.0, 0.0); //set the pants color
	glutSolidCube(1.0); //draw the cube
	glPopMatrix();

	//drawing human right leg (cube)
	glPushMatrix();
	glTranslatef(62.0, 42.0, 0.0); //move to the position of the right leg
	glScalef(3.0, 15.0, 0.0); //scale to the size of the leg
	glColor3f(0.0, 0.0, 0.0); //set the pants color
	glutSolidCube(1.0); //draw the cube
	glPopMatrix();
	///////////////////////////////////////////////////HUMAN END////////////////////////////////////////
	
	glFlush();
}

// Initialization routine.
void setup(void)
{
	//setting the colour of the sky (blue)
	glClearColor(0.0, 0.5, 1.0, 0.0); 
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("assign1.cpp");

	glutDisplayFunc(draw);
	glutReshapeFunc(resize);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
