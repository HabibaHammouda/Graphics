/*
Comments here
*/

// Include the necessary libraries
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <iostream>
#include <math.h>

// Define Globals (if needed)
////////////////////////////////////////////////////////////FUNCTION OF PIG NOSE OUTLINE/////////////////////////////////////
void drawPigNoseOutline()
{
	glLineWidth(6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //left half of the shape
	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(42.5, 42.5, 0.0);
		glVertex3f(45.0, 45.5, 0.0);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(50.0, 45.5, 0.0);
		glVertex3f(51.25, 53.5, 0.0);
		glVertex3f(50.0, 50.5, 0.0);
		glVertex3f(42.5, 53.5, 0.0);
		glVertex3f(45.0, 50.5, 0.0);
		glVertex3f(42.5, 42.5, 0.0);
		glVertex3f(45.0, 45.5, 0.0);
	glEnd();
	/////////////this is the mirror////////////

	glLineWidth(6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //right half of the shape
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(52.5, 45.5, 0.0);
		glVertex3f(60.0, 42.5, 0.0);
		glVertex3f(57.5, 45.5, 0.0);
		glVertex3f(60.0, 53.5, 0.0);
		glVertex3f(57.5, 50.5, 0.0);
		glVertex3f(51.25, 53.5, 0.0);
		glVertex3f(52.5, 50.5, 0.0);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(52.5, 45.5, 0.0);
	glEnd();
}

////////////////////////////////////////////////////////////FUNCTION OF PIG NOSE FILL/////////////////////////////////////
void drawPigNoseFill()
{
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //left half of the shape
	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(42.5, 42.5, 0.0);
		glVertex3f(45.0, 45.5, 0.0);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(50.0, 45.5, 0.0);
		glVertex3f(51.25, 53.5, 0.0);
		glVertex3f(50.0, 50.5, 0.0);
		glVertex3f(42.5, 53.5, 0.0);
		glVertex3f(45.0, 50.5, 0.0);
		glVertex3f(42.5, 42.5, 0.0);
		glVertex3f(45.0, 45.5, 0.0);
	glEnd();
	/////////////this is the mirror////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //right half of the shape
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(52.5, 45.5, 0.0);
		glVertex3f(60.0, 42.5, 0.0);
		glVertex3f(57.5, 45.5, 0.0);
		glVertex3f(60.0, 53.5, 0.0);
		glVertex3f(57.5, 50.5, 0.0);
		glVertex3f(51.25, 53.5, 0.0);
		glVertex3f(52.5, 50.5, 0.0);
		glVertex3f(51.25, 42.5, 0.0);
		glVertex3f(52.5, 45.5, 0.0);
	glEnd();
}

////////////////////////////////////////////////////////////FUNCTION OF PIG FACE OUTLINE/////////////////////////////////////
void drawPigFaceOutline()
{
	glLineWidth(6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(35.0 + 1, 35.0 + 3, 0.0);
		glVertex3f(65.0 + 1, 35.0 + 3, 0.0);
		glVertex3f(35.0 + 1, 60.0 + 3, 0.0);
		glVertex3f(65.0 + 1, 60.0 + 3, 0.0);
	glEnd();
}
////////////////////////////////////////////////////////////FUNCTION OF PIG FACE FILL/////////////////////////////////////
void drawPigFace()
{
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(35.0 + 1, 35.0 + 3, 0.0);
		glVertex3f(65.0 + 1, 35.0 + 3, 0.0);
		glVertex3f(35.0 + 1, 60.0 + 3, 0.0);
		glVertex3f(65.0 + 1, 60.0 + 3, 0.0);
	glEnd();
}

////////////////////////////////////////////////////////////FUNCTION OF NOSE BLACK BACKGROUND/////////////////////////////////////
void drawNoseBackground()
{
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(45.0, 45.0, 0.0);
		glVertex3f(60.0, 45.0, 0.0);
		glVertex3f(45.0, 48 + 5.0, 0.0);
		glVertex3f(60.0, 48.0 + 5, 0.0);
	glEnd();
}

////////////////////////////////////////////////////////////FUNCTION OF EYES/////////////////////////////////////
void drawEyes()
{
	//left eye
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(42.0, 55.0 + 2, 0.0);
		glVertex3f(45.0, 55.0 + 2, 0.0);
		glVertex3f(42.0, 58.0 + 2, 0.0);
		glVertex3f(45.0, 58.0 + 2, 0.0);
	glEnd();

	//right eye
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(57.0, 55.0 + 2, 0.0);
		glVertex3f(60.0, 55.0 + 2, 0.0);
		glVertex3f(57.0, 58.0 + 2, 0.0);
		glVertex3f(60.0, 58.0 + 2, 0.0);
	glEnd();
}

////////////////////////////////////////////////////////////FUNCTION OF PUPILS/////////////////////////////////////
void drawPupil()
{
	//left eye
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(44.0, 57.0 + 2, 0.0);
		glVertex3f(45.0, 57.0 + 2, 0.0);
		glVertex3f(44.0, 58.0 + 2, 0.0);
		glVertex3f(45.0, 58.0 + 2, 0.0);
	glEnd();

	//right eye 
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(59.0, 57.0 + 2, 0.0);
		glVertex3f(60.0, 57.0 + 2, 0.0);
		glVertex3f(59.0, 58.0 + 2, 0.0);
		glVertex3f(60.0, 58.0 + 2, 0.0);
	glEnd();
}
////////////////////////////////////////////////////////////FUNCTION OF EARS/////////////////////////////////////
void drawEarsFill()
{
	//left ear
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(30.0 + 0.6, 60.0 + 2.6, 0.0);
		glVertex3f(35.0 + 0.6, 60.0 + 2.6, 0.0);
		glVertex3f(30.0 + 0.6, 65.0 + 2.6, 0.0);
		glVertex3f(35.0 + 0.6, 65.0 + 2.6, 0.0);
	glEnd();
	
	//right ear
	glLineWidth(1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(65.0 + 1.4, 60.0 + 2.6, 0.0);
		glVertex3f(70.0 + 1.4, 60.0 + 2.6, 0.0);
		glVertex3f(65.0 + 1.4, 65.0 + 2.6, 0.0);
		glVertex3f(70.0 + 1.4, 65.0 + 2.6, 0.0);
	glEnd();
}

void drawEarsOutline()
{
	//left ear
	glLineWidth(6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(30.0 + 0.6, 60.0 + 2.6, 0.0);
		glVertex3f(35.0 + 0.6, 60.0 + 2.6, 0.0);
		glVertex3f(30.0 + 0.6, 65.0 + 2.6, 0.0);
		glVertex3f(35.0 + 0.6, 65.0 + 2.6, 0.0);
	glEnd();

	//right ear
	glLineWidth(6);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(65.0 + 1.4, 60.0 + 2.6, 0.0);
		glVertex3f(70.0 + 1.4, 60.0 + 2.6, 0.0);
		glVertex3f(65.0 + 1.4, 65.0 + 2.6, 0.0);
		glVertex3f(70.0 + 1.4, 65.0 + 2.6, 0.0);
	glEnd();
}

// display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0); //set the color
	drawPigFaceOutline(); //function of pig face outline

	glColor3f(1.0, 0.753, 0.796); //set the color to pink
	drawPigFace(); //function of pig face

	glColor3f(0.0, 0.0, 0.0); //set the color
	drawNoseBackground();

	glColor3f(0.0, 0.0, 0.0); //set the color
	drawPigNoseOutline(); //function of pig nose  

	glColor3f(1.0, 0.753, 0.796); //set the color to pink
	drawPigNoseFill(); //function of pig face

	glColor3f(0.0, 0.0, 0.0); //set the color
	drawEyes();

	glColor3f(1.0, 1.0, 1.0); //set the color
	drawPupil();

	glColor3f(0.0, 0.0, 0.0); //set the color
	drawEarsOutline();
	
	glColor3f(1.0, 0.753, 0.796); //set the color to pink
	drawEarsFill();

	glFlush();
}

// Initialization routine.
void setup()
{
	glClearColor(0.5, 0.5, 0.5, 0.0); //setting the background colour to grey 
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
	glutInitWindowPosition(300, 40);

	glutCreateWindow("Pig.cpp");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();

	return 0;
}