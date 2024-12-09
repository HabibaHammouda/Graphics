/*
Assignment 4
You’re required to create a simple interactive game, where the user drives a car
around obstacles to reach the target.

Scenario:
- The user can use up, down, right and left keys to drive the car forward, backward, turn
right and turn left respectively. The car and camera should move together.

- The obstacles should be 4 cubes distributed in the scene for the user to drive around and
avoid. If the car hits an obstacle, the car stops and a message ‘You Lose !’ appears up
the screen.
- If the car touches the target, the car stops and a message ‘You Win !’ appears up the screen.

//Note: our team is only of 2 members, so we were allowed to skip the reset part of the assignment
*/

#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <E:\CodProj\CarVideoGame\glm-0.9.7.5\glm\glm/glm.hpp>
#include <E:\CodProj\CarVideoGame\glew-1.10.0-win32\glew-1.10.0\include\GL/glew.h>
#include <E:\CodProj\CarVideoGame\freeglut-MSVC-2.8.1-1.mp\freeglut\include\GL/freeglut.h> 

#define ROWS 4 // Number of rows of obstacles
#define COLUMNS 3 // Number of columns of obstacles
#define FILL_PROBABILITY 100 // Percentage probability that a particular row-column slot will be 
// filled with an asteroid. It should be an integer between 0 and 100.

// Globals
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24; // Font selection
static int width, height; // Size of the OpenGL window
static float angle = 0.0; // Angle of the car
static float xVal = 0.0, zVal = 0.0; // Co-ordinates of the car
static int isCollideObstacle = 0; // Is there collision between the car and an obstacle? (lose)
static int isCollideTarget = 0; // Is there collision between the car and the target? (win)
static unsigned int car; // Display lists base index.
static int frameCount = 0; // Number of frames

float R1 = 15.0;  // radius of the target's last circle (4) to check collision
float R2 = 5.0;  // radius of the car's bounded sphere to check collision

// Routine to draw a bitmap character string
void writeBitmapString(void* font, const char* string)
{
	const char* c;

	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Obstacle class
class Obstacle
{
public:
	Obstacle();
	Obstacle(float x, float y, float z, float r);
	float getCenterX() { return centerX; }
	float getCenterY() { return centerY; }
	float getCenterZ() { return centerZ; }
	float getRadius() { return radius; }
	void drawObstacle();

private:
	float centerX, centerY, centerZ, radius;
};

// Obstacle default constructor.
Obstacle::Obstacle()
{
	centerX = 0.0;
	centerY = 0.0;
	centerZ = 0.0;
	radius = 0.0; // Indicates no Obstacle exists in the position.
}

// Asteroid constructor.
Obstacle::Obstacle(float x, float y, float z, float r)
{
	centerX = x;
	centerY = y;
	centerZ = z;
	radius = r;
}

// Function to draw obstacles
void Obstacle::drawObstacle()
{
	if (radius > 0.0) // if Obstacle exists
	{
		glPushMatrix();
		glTranslatef(centerX, centerY, centerZ);
		glLineWidth(1.0); //border width set to be thick
		glColor3f(0.0, 0.0, 1.0); //blue obstacles
		glutSolidCube(5.0); //obstacle
		glColor3f(0.0, 0.0, 0.0); //black border
		glutWireCube(5.01); //border;
		glPopMatrix();
	}
}

Obstacle arrayObstacles[ROWS][COLUMNS]; // Global array of Obstacles.

//function to draw the target
void drawTarget()
{
	glPushMatrix();

	//circle 0
	glPushMatrix();
	glTranslatef(0.0, 0.0, -200.0);
	glScalef(2.0, 2.0, 2.0); //doubling the size of the target, for a more user-friendly UI
	glScalef(1.0, 1.0, 0.02); //0.2 or 0.02 3ala 7asab el zoom (to be edited later) 
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(12.5, 30, 30);

	//circle 1
	glTranslatef(0.0, 0.0, 40.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(10.0, 30, 30);

	//circle 2
	glTranslatef(0.0, 0.0, 40.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(7.5, 30, 30);

	//circle 3
	glTranslatef(0.0, 0.0, 40.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(5.0, 30, 30);

	//circle 4
	glTranslatef(0.0, 0.0, 30.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(2.5, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

//function to draw the car
void drawCar()
{
	glPushMatrix();

	//smaller and upper part of the car
	glPushMatrix();
	//glColor3f(0.737255, 0.560784, 0.560784); //pink color
	glColor3f(0.7, 0.09, 0.09); //scarlet color
	glTranslatef(0.0, -2.0, 0.0);
	glScalef(0.5 * 0.5, 0.4 * 0.4 * 0.5, 1.0 * 0.5);
	glutSolidCube(10.0);
	glColor3f(0.0, 0.0, 0.0); //black border
	glLineWidth(3.0); //border width set to be thick
	glutWireCube(10.1); //border around the car
	glPopMatrix();

	//larger and lower part of the car
	glPushMatrix();
	glTranslatef(0.0, -3.0, 0.0);
	glScalef(1.0 * 0.5, 0.5 * 0.3 * 0.5, 1.5 * 0.5);
	glColor3f(0.7, 0.09, 0.09); //scarlet color
	glutSolidCube(10.0);
	glColor3f(0.0, 0.0, 0.0); //black color
	glLineWidth(3.0); //border width set to be thick
	glutWireCube(10.1); //border around the car
	glPopMatrix();

	//////////////////////wheels of the car/////////////////////////////

	//wheel 1 (front left)
	glPushMatrix();
	glTranslatef(-3.0, -3.5, -3.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.5, 1.5, 30, 30);
	glPopMatrix();

	//wheel 2 (front right)
	glPushMatrix();
	glTranslatef(3.0, -3.5, -3.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.5, 1.5, 30, 30);
	glPopMatrix();

	//wheel 3 (back left)
	glPushMatrix();
	glTranslatef(-3.0, -3.5, 3.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.5, 1.5, 30, 30);
	glPopMatrix();

	//wheel 4 (back right) 
	glPushMatrix();
	glTranslatef(3.0, -3.5, 3.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.5, 1.5, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

// Routine to count the number of frames drawn every second.
void frameCounter(int value)
{
	if (value != 0) // No output the first time frameCounter() is called (from main()).
		std::cout << "FPS = " << frameCount << std::endl;
	frameCount = 0;
	glutTimerFunc(1000, frameCounter, 1);
}

// Initialization routine.
void setup(void)
{
	int i, j;

	//drawing the car
	car = glGenLists(1);
	glNewList(car, GL_COMPILE);
	drawCar();
	glEndList();

	// Initialize global arrayObstacles.
	for (j = 0; j < COLUMNS; j++)
		for (i = 0; i < ROWS; i++)
			if (rand() % 100 < FILL_PROBABILITY)
				// If rand()%100 >= FILL_PROBABILITY the default constructor asteroid remains in the slot 
				// which indicates that there is no obstacle there because the default's radius is 0.
			{
				// Position the obstacles depending on if there is an even or odd number of columns
				// so that the car faces the middle of the obstacle field.
				if (COLUMNS % 2) // Odd number of columns.
					arrayObstacles[i][j] = Obstacle(30.0 * (-COLUMNS / 2 + j), 0.0, -40.0 - 30.0 * i, 3.0);
				else // Even number of columns.
					arrayObstacles[i][j] = Obstacle(15 + 30.0 * (-COLUMNS / 2 + j), 0.0, -40.0 - 30.0 * i, 3.0);
			}

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.74902, 0.847059, 0.847059, 0.0); //light blue background color

	glutTimerFunc(0, frameCounter, 0); // Initial call of frameCounter().
}

// Function to check if two spheres centered at (x1,y1,z1) and (x2,y2,z2) with
// radius r1 and r2 intersect.
int checkSpheresIntersection(float x1, float y1, float z1, float r1,
	float x2, float y2, float z2, float r2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= (r1 + r2) * (r1 + r2));
}

// Function to check if the spacecraft collides with an obstacle when the center of the base
// of the craft is at (x, 0, z) and it is aligned at an angle a to to the -z direction.
// Collision detection is approximate as instead of the car we use a bounding sphere.
int ObstacleCarCollision(float x, float z, float a)
{
	int i, j;

	// Check for collision with each obstacle
	for (j = 0; j < COLUMNS; j++)
		for (i = 0; i < ROWS; i++)
			if (arrayObstacles[i][j].getRadius() > 0) // If obstacle exists.
				if (checkSpheresIntersection(x - 5 * sin((M_PI / 180.0) * a), 0.0,
					z - 10 - 5 * cos((M_PI / 180.0) * a), 5.0,
					arrayObstacles[i][j].getCenterX(), arrayObstacles[i][j].getCenterY(),
					arrayObstacles[i][j].getCenterZ(), arrayObstacles[i][j].getRadius()))
					return 1;
	return 0;
}

// Function to check if the car collides with the target when the center of the base
// of the car is at (x, 0, z) and it is aligned at an angle a to to the -z direction.
// Collision detection is approximate as instead of the car we use a bounding sphere.
int targetCarCollision(float x, float z, float a)
{
	int i, j;

	// Check for collision with target
	for (j = 0; j < COLUMNS; j++)
		for (i = 0; i < ROWS; i++)
			if (arrayObstacles[i][j].getRadius() > 0) // If target exists.
				if (checkSpheresIntersection(x - 5 * sin((M_PI / 180.0) * a), 0.0,
					z - 30 - 5 * cos((M_PI / 180.0) * a), 7.0,
					arrayObstacles[i][j].getCenterX(), arrayObstacles[i][j].getCenterY(),
					arrayObstacles[i][j].getCenterZ() + 20, arrayObstacles[i][j].getRadius()))
					return 1;
	return 0;
}

// Drawing routine.
void drawScene(void)
{
	frameCount++; // Increment number of frames every redraw.

	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Write text in isolated (i.e., before gluLookAt) translate block.
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0); //text in black color
	glRasterPos3f(-28.0, 25.0, -30.0); //positioning the text
	if (isCollideObstacle) writeBitmapString((void*)font, "You Lose!");
	if (isCollideTarget) writeBitmapString((void*)font, "You Win!");
	glPopMatrix();

	// positioning the camera so it moves with the car
	gluLookAt(xVal - 10 * sin((M_PI / 180.0) * angle),
		2.0,
		zVal - 10 * cos((M_PI / 180.0) * angle),
		xVal - 11 * sin((M_PI / 180.0) * angle),
		2.0,
		zVal - 11 * cos((M_PI / 180.0) * angle),
		0.0,
		1.0,
		0.0);

	// Draw car
	glPushMatrix();
	glTranslatef(xVal, 0.0, zVal - 20); //positioning the car in front of the camera, to make it visibile
	glCallList(car);
	glPopMatrix();

	// Draw all the obstacles in arrayobstacles.
	for (j = 0; j < COLUMNS; j++)
		for (i = 0; i < ROWS; i++)
			arrayObstacles[i][j].drawObstacle();

	// Draw target 
	drawTarget();

	glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 250.0);
	glMatrixMode(GL_MODELVIEW);

	// Pass the size of the OpenGL window.
	width = w;
	height = h;
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	float tempxVal = xVal, tempzVal = zVal, tempAngle = angle;

	// Compute next position.
	if (key == GLUT_KEY_LEFT) tempAngle = angle + 2.0;
	if (key == GLUT_KEY_RIGHT) tempAngle = angle - 2.0;
	if (key == GLUT_KEY_UP)
	{
		tempxVal = xVal - sin(angle * M_PI / 180.0);
		tempzVal = zVal - cos(angle * M_PI / 180.0);
	}
	if (key == GLUT_KEY_DOWN)
	{
		tempxVal = xVal + sin(angle * M_PI / 180.0);
		tempzVal = zVal + cos(angle * M_PI / 180.0);
	}

	// Angle correction.
	if (tempAngle > 360.0) tempAngle -= 360.0;
	if (tempAngle < 0.0) tempAngle += 360.0;

	// Move car to next position only if there will not be collision with an obstacle.
	if (!ObstacleCarCollision(tempxVal, tempzVal, tempAngle))
	{
		isCollideObstacle = 0;
		xVal = tempxVal;
		zVal = tempzVal;
		angle = tempAngle;
	}
	else
		isCollideObstacle = 1;

	// Check collision with target
	glm::vec3 carPosition = glm::vec3(tempxVal, 0.0, tempzVal);
	glm::vec3 targetPosition = glm::vec3(0.0, 0.0, -150.0); // Assuming the target position
	float distanceToTarget = glm::length(carPosition - targetPosition);
	if (distanceToTarget <= R1 + R2)
		isCollideTarget = 1; // Collision detected with sphere (target)
	else
		isCollideTarget = 0;

	glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press the left/right arrow keys to turn the craft." << std::endl
		<< "Press the up/down arrow keys to move the craft." << std::endl;
}

// Main routine.
int main(int argc, char** argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("Car Game: Assignment 4.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
