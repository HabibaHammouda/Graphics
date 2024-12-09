/*
Requirement: Draw the leaf shown. Try to make it as similar as you can.
*/

// Include the necessary libraries
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>

// Globals 
static int NumofVertices_PARABOLA = 500; // Number of vertices on one half of the parabola.

///////////////////////////////////////////////////////////////FUNCTION TO DRAW LEFT PARABOLA/////////////////////////////////////

void drawParabolaLeft() 
{
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	for (int i = -NumofVertices_PARABOLA; i <= NumofVertices_PARABOLA; ++i)
	{
		glVertex3f(40.0 + 10.0 * (float)(i * i) / (NumofVertices_PARABOLA * NumofVertices_PARABOLA), 50.0 + 17.0 * (float)i / NumofVertices_PARABOLA, 0.0);
	}
	glEnd();
}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW RIGHT PARABOLA/////////////////////////////////////

void drawParabolaRight()
{
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	for (int i = -NumofVertices_PARABOLA; i <= NumofVertices_PARABOLA; ++i)
	{
		glVertex3f(60.0 + -10.0 * (float)(i * i) / (NumofVertices_PARABOLA * NumofVertices_PARABOLA), 50.0 + 17.0 * (float)i / NumofVertices_PARABOLA, 0.0);
	}
	glEnd();
}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW MIDDLE STEM/////////////////////////////////////

void drawParabolaMiddle() 
{
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	for (int i = -NumofVertices_PARABOLA; i <= NumofVertices_PARABOLA; ++i)
	{
		glVertex3f(52.0 + -2.0 * (float)(i * i) / (NumofVertices_PARABOLA * NumofVertices_PARABOLA), 50.0 + 17.0 * (float)i / NumofVertices_PARABOLA, 0.0);
	}
	glEnd();
}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW TIP END/////////////////////////////////////

void drawParabolaTip()
{
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	for (int i = -600; i <= 70; ++i)
	{
		glVertex3f(50.0 + 2.0 * (float)(i * i) / (NumofVertices_PARABOLA * NumofVertices_PARABOLA), 33.0 + 5.0 * (float)i / NumofVertices_PARABOLA, 0.0);
	}
	glEnd();
}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW LINES INSIDE THE LEAF/////////////////////////////////////

void drawLines()
{
	glLineWidth(2);
	glBegin(GL_LINES);
	////////////////////Right side/////////////////////
	//first line
	glVertex3f(51.0, 38.0, 0.0);
	glVertex3f(58.5, 43.0, 0.0);
	//second line
	glVertex3f(51.7, 44.0, 0.0);
	glVertex3f(60.0, 49.3, 0.0);
	//third line
	glVertex3f(51.8, 51.0, 0.0);
	glVertex3f(59.0, 56.5, 0.0);
	//fourth line
	glVertex3f(51.7, 58.0, 0.0);
	glVertex3f(56.0, 61.2, 0.0);

	////////////////////Left side/////////////////////
	//first line
	glVertex3f(51.0, 38.0, 0.0);
	glVertex3f(42.0, 43.0, 0.0);
	//second line
	glVertex3f(51.7, 44.0, 0.0);
	glVertex3f(40.0, 49.3, 0.0);
	//third line
	glVertex3f(51.8, 51.0, 0.0);
	glVertex3f(41.5, 56.2, 0.0);
	//fourth line
	glVertex3f(51.7, 58.0, 0.0);
	glVertex3f(44.2, 61.4, 0.0);

	glEnd();
	
}
////////////////////////////////////////////////////////////////START OF DEFUALT FUNCTIONS/////////////////////////////////////////////

///////////////////////////////////////////////////////////////FUNCTION TO DISPLAY/////////////////////////////////////
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.5, 0.0); //set the color of the shape to be green
	drawParabolaLeft(); //function of left parabola
	
	glColor3f(0.0, 0.5, 0.0); //set the color of the shape to be green
	drawParabolaRight(); //function of right parabola

	glColor3f(0.0, 0.5, 0.0); //set the color of the shape to be green
	drawParabolaMiddle(); //function of middle shoot 

	glColor3f(0.0, 0.5, 0.0); //set the color of the shape to be green
	drawParabolaTip(); //function of end tip of leaf

	glColor3f(0.0, 0.5, 0.0); //set the color of the shape to be green
	drawLines(); //function of lines inside the leaf

	glFlush();
}

///////////////////////////////////////////////////////////////FUNCTION OF OpenGL window reshape/////////////////////////////////////
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); //you can edit this to change projections

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
///////////////////////////////////////////////////////////////FUNCTION OF INITIALIZATION/////////////////////////////////////
void setup(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(600, 600); //you can edit this to change window size
	glutInitWindowPosition(300, 50); //you can edit this to change window position

	glutCreateWindow("Flat Leaf.cpp");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glClearColor(0.9, 0.9, 0.9, 0.0); //setting the background colour (default light grey)
}

////////////////////////////////////////////////////////////////////MAIN FUNCTION/////////////////////////////////////
int main(int argc, char** argv)
{
	glewExperimental = GL_TRUE;
	glewInit();

	setup(argc, argv);

	glutMainLoop();

	return 0;
}