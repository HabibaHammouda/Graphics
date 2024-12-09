/*
Computer Graphics: Assignment 2
Team 8
Members: Habiba Walid Hammouda, Mahy Elhelw, Mayar Ayman, Youssef Gamal

Statement:
- Use triangular strips to draw the double annulus (a square/rectangle with
2 empty rectangular/square spaces) shown (shape 1).
- Use the least number of triangular strips and least number of
new vertices on the boundaries.
- Use triangular fan to draw a disc (filled circle) (shape 2)
- Use the mentioned 2 objects along with other objects of
your choice to construct a meaningful 2D scene.
*/

// Include the necessary libraries

#define _USE_MATH_DEFINES 

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <iostream>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////GLOBALS/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////GLOBALS OF THE SUN//////////////////////////////////////////////////
static float NumSegments = 1000; // The number of segments to approximate the circles

static float R_SUN = 8.0; // The radius of the sun
static float X_SUN = 15.0; // x-coordinate of center of sun
static float Y_SUN = 85.0; // y-coordinate of center of sun

///////////////////////////////////////////////////////////////GLOBALS OF THE CLOUD//////////////////////////////////////////////////

//////////////////////////////////////////CLOUD 1 (LEFT) START/////////////////////////////////////////

//////////////////////////////////CENTRE CIRCLE///////////////////////////////////////
static float R_CLOUD = 5.0; // The radius of the cloud
static float X_CLOUD= 40.0; // x-coordinate of center of cloud
static float Y_CLOUD = 85.0; // y-coordinate of center of cloud

////////////////////////////////////LEFT SMALLER CIRCLE///////////////////////////////
static float R1_CLOUD = 4.0; // The radius of the cloud
static float X1_CLOUD = 35.0; // x-coordinate of center of cloud
static float Y1_CLOUD = 84.0; // y-coordinate of center of cloud

////////////////////////////////////RIGHT SMALLER CIRCLE///////////////////////////////

static float R2_CLOUD = 4.0; // The radius of the cloud
static float X2_CLOUD = 45.0; // x-coordinate of center of cloud
static float Y2_CLOUD = 84.0; // y-coordinate of center of clou

//////////////////////////////////////////CLOUD 1 (LEFT) END/////////////////////////////////////////

///////////////////////////////////////////CLOUD 2 (RIGHT) START//////////////////////////////////////

////////////////////////////////////CENTRE CIRCLE///////////////////////////////
static float R3_CLOUD = 5.0; // The radius of the cloud
static float X3_CLOUD = 80.0; // x-coordinate of center of cloud
static float Y3_CLOUD = 85.0; // y-coordinate of center of cloud

////////////////////////////////////LEFT SMALLER CIRCLE///////////////////////////////
static float R4_CLOUD = 4.0; // The radius of the cloud
static float X4_CLOUD = 74.0; // x-coordinate of center of cloud
static float Y4_CLOUD = 84.0; // y-coordinate of center of cloud

////////////////////////////////////RIGHT SMALLER CIRCLE///////////////////////////////

static float R5_CLOUD = 4.0; // The radius of the cloud
static float X5_CLOUD = 86.0; // x-coordinate of center of cloud
static float Y5_CLOUD = 84.0; // y-coordinate of center of cloud


///////////////////////////////////////////////////////////////////GLOBALS OF WHEELS//////////////////////////////////////////////////////////

//Note: "drawing wheel 1.2" means drawing for train number 1 wheel number 2
static float R_WHEEL = 2.0; // Radius of wheel (constant for all wheels)

static float X_W11 = 16.0; // x-coordinate of center of wheel 1.1
static float Y = 11.0; // y-coordinate of center of wheel (constant for all wheels)

static float X_W12 = 26.0; // x-coordinate of center of wheel 1.2
static float X_W21 = 36.0; // x-coordinate of center of wheel 2.1
static float X_W22 = 46.0; // x-coordinate of center of wheel 2.2
static float X_W31 = 56.0; // x-coordinate of center of wheel 3.1
static float X_W32 = 66.0; // x-coordinate of center of wheel 3.2
static float X_W41 = 76.0; // x-coordinate of center of wheel 4.1
static float X_W42 = 86.0; // x-coordinate of center of wheel 4.2

///////////////////////////////////////////////////////////////GLOBALS OF THE TREE//////////////////////////////////////////////////
static float NumSegments_TREE = 1000; // The number of segments to approximate the tree
static float R_TREE = 15.0; // Radius of center of tree
static float X_TREE = 73.0; // x-coordinate of center of tree
static float Y_TREE = 62.0; // Y-coordinate of center of tree

static float R1_TREE = 10.0; // Radius of center of tree
static float X1_TREE = 20.0; // x-coordinate of center of tree
static float Y1_TREE = 55.0; // Y-coordinate of center of tree

///////////////////////////////////////////////////////////////GLOBAL OF THE HILL//////////////////////////////////////////////////
static int VerticesNum_HILL = 800; // Number of vertices on one half of the parabola to form hills

///////////////////////////////////////////////////////////////GLOBAL OF THE SMOKE//////////////////////////////////////////////////
static float NumSegments_SMOKE = 500; // The number of segments to approximate the smoke
static float R1_SMOKE = 1.0 ; // Radius of center of smoke
static float X_SMOKE = 13.0; // x-coordinate of center of smoke (same for both)
static float Y1_SMOKE = 27.0; // Y-coordinate of center of smoke
static float R2_SMOKE = 0.7; // Radius of center of smoke
static float Y2_SMOKE = 30.0; // Y-coordinate of center of smoke


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////FUNCTION TO DRAW THE TRAIN/////////////////////////////////////
void drawTrain()
{
	////////////////////////////////////////////////////////////Train 1 (driver)//////////////////////////////////////////////////
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(10.5, 12.5, 0.0);
		glVertex3f(21.0, 12.5, 0.0);
		glVertex3f(10.5, 19.0, 0.0);
		glVertex3f(21.0, 19.0, 0.0);
	glEnd();
	/////////////this is the mirror////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //right half of the shape

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(19.25, 12.5, 0.0); 
		glVertex3f(21.25, 18.5, 0.0);
		glVertex3f(29.25, 12.5, 0.0); 
		glVertex3f(27.25, 18.5, 0.0);
		glVertex3f(29.25, 26.5, 0.0);
		glVertex3f(27.25, 24.5, 0.0);
		glVertex3f(19.25, 26.5, 0.0);
		glVertex3f(21.25, 24.5, 0.0);
		glVertex3f(19.25, 12.5, 0.0); 
		glVertex3f(21.25, 18.5, 0.0);
	glEnd();

	////////////////////////////////////////////////////DRIVER POLE////////////////////////////////////////////
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(12.3, 19.0, 0.0);
		glVertex3f(14.0, 19.0, 0.0);
		glVertex3f(12.0, 23.0, 0.0);
		glVertex3f(14.3, 23.0, 0.0);
	glEnd();


	///////////////////////////////////////////////////////CONNECTION BETWEEN TRAIN 1 AND 2///////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(28.0, 16.0, 0.0);
		glVertex3f(34.0, 16.0, 0.0);
		glVertex3f(28.0, 18.0, 0.0);
		glVertex3f(34.0, 18.0, 0.0);
	glEnd();

	////////////////////////////////////////////////////////////Train 2//////////////////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(32.5, 12.5, 0.0);
		glVertex3f(35.0, 15.5, 0.0);
		glVertex3f(41.25, 12.5, 0.0);
		glVertex3f(40.0, 15.5, 0.0);
		glVertex3f(41.25, 23.5, 0.0);
		glVertex3f(40.0, 20.5, 0.0);
		glVertex3f(32.5, 23.5, 0.0);
		glVertex3f(35.0, 20.5, 0.0);
		glVertex3f(32.5, 12.5, 0.0);
		glVertex3f(35.0, 15.5, 0.0);
	glEnd();
	/////////////this is the mirror////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //right half of the shape

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(41.25, 12.5, 0.0);
		glVertex3f(42.5, 15.5, 0.0);
		glVertex3f(50.0, 12.5, 0.0);
		glVertex3f(47.5, 15.5, 0.0);
		glVertex3f(50.0, 23.5, 0.0);
		glVertex3f(47.5, 20.5, 0.0);
		glVertex3f(41.25, 23.5, 0.0);
		glVertex3f(42.5, 20.5, 0.0);
		glVertex3f(41.25, 12.5, 0.0);
		glVertex3f(42.5, 15.5, 0.0);
	glEnd();
	///////////////////////////////////////CONNECTION BETWEEN TRAIN 2 AND TRAIN 3/////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(50.0, 16.0, 0.0);
		glVertex3f(54.0, 16.0, 0.0);
		glVertex3f(50.0, 18.0, 0.0);
		glVertex3f(54.0, 18.0, 0.0);
	glEnd();
	////////////////////////////////////////////////////////////Train 3//////////////////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(52.5, 12.5, 0.0);
		glVertex3f(55.0, 15.5, 0.0);
		glVertex3f(61.25, 12.5, 0.0);
		glVertex3f(60.0, 15.5, 0.0);
		glVertex3f(61.25, 23.5, 0.0);
		glVertex3f(60.0, 20.5, 0.0);
		glVertex3f(52.5, 23.5, 0.0);
		glVertex3f(55.0, 20.5, 0.0);
		glVertex3f(52.5, 12.5, 0.0);
		glVertex3f(55.0, 15.5, 0.0);
	glEnd();
	/////////////this is the mirror////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //right half of the shape

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(61.25, 12.5, 0.0);
		glVertex3f(62.5, 15.5, 0.0);
		glVertex3f(70.0, 12.5, 0.0);
		glVertex3f(67.5, 15.5, 0.0);
		glVertex3f(70.0, 23.5, 0.0);
		glVertex3f(67.5, 20.5, 0.0);
		glVertex3f(61.25, 23.5, 0.0);
		glVertex3f(62.5, 20.5, 0.0);
		glVertex3f(61.25, 12.5, 0.0);
		glVertex3f(62.5, 15.5, 0.0);
	glEnd();

	////////////////////////////CONNECTION BETWEEN TRAIN 3 AND TRAIN 4/////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(70.0, 16.0, 0.0);
		glVertex3f(74.0, 16.0, 0.0);
		glVertex3f(70.0, 18.0, 0.0);
		glVertex3f(74.0, 18.0, 0.0);
	glEnd();
	////////////////////////////////////////////////////////////Train 4//////////////////////////////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
		glVertex3f(72.5, 12.5, 0.0);
		glVertex3f(75.0, 15.5, 0.0);
		glVertex3f(81.25, 12.5, 0.0);
		glVertex3f(80.0, 15.5, 0.0);
		glVertex3f(81.25, 23.5, 0.0);
		glVertex3f(80.0, 20.5, 0.0);
		glVertex3f(72.5, 23.5, 0.0);
		glVertex3f(75.0, 20.5, 0.0);
		glVertex3f(72.5, 12.5, 0.0);
		glVertex3f(75.0, 15.5, 0.0);
	glEnd();
	/////////////this is the mirror////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //right half of the shape

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(81.25, 12.5, 0.0);
		glVertex3f(82.5, 15.5, 0.0);
		glVertex3f(90.0, 12.5, 0.0);
		glVertex3f(87.5, 15.5, 0.0);
		glVertex3f(90.0, 23.5, 0.0);
		glVertex3f(87.5, 20.5, 0.0);
		glVertex3f(81.25, 23.5, 0.0);
		glVertex3f(82.5, 20.5, 0.0);
		glVertex3f(81.25, 12.5, 0.0);
		glVertex3f(82.5, 15.5, 0.0);
	glEnd();

}

///////////////////////////////////////////////////////////////FUNCTION TO SMOKE FROM DRIVER'S TRAIN/////////////////////////////////////
void drawSmoke()
{
	//first circle (larger)
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(X_SMOKE, Y1_SMOKE);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_SMOKE + R1_SMOKE * cos(angle);
		float y = Y1_SMOKE + R1_SMOKE * sin(angle);

		glVertex2f(x, y);
	}
	glEnd();

	//second circle (smaller)
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(X_SMOKE, Y2_SMOKE);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_SMOKE + R2_SMOKE * cos(angle);
		float y = Y2_SMOKE + R2_SMOKE * sin(angle);

		glVertex2f(x, y);
	}
	glEnd();

}


///////////////////////////////////////////////////////////////FUNCTION TO DRAW THE PATH/////////////////////////////////////
void drawPath()
{
	glColor3f(0.2, 0.2, 0.2); //set the color of the path
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(100.0, 0.0, 0.0);
		glVertex3f(0.0, 9.0, 0.0);
		glVertex3f(100.0, 9.0, 0.0);
	glEnd();
}
///////////////////////////////////////////////////////////////FUNCTION TO DRAW THE SUN/////////////////////////////////////
void drawSun()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X_SUN, Y_SUN);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_SUN + R_SUN * cos(angle);
		float y = Y_SUN + R_SUN * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();
}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW THE WHEELS/////////////////////////////////////
void drawWheel()
{
	//Note: "drawing wheel 1.2" means drawing for train number 1 wheel number 2

	////////////////////////////////////////////////////////////Train 1 Wheels//////////////////////////////////////////////////

	//drawing wheel 1.1
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W11, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W11 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	//drawing wheel 1.2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W12, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W12 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	////////////////////////////////////////////////////////////Train 2 Wheels//////////////////////////////////////////////////

	//drawing wheel 2.1
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W21, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W21 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	//drawing wheel 2.2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W22, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W22 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	////////////////////////////////////////////////////////////Train 3 Wheels//////////////////////////////////////////////////

	//drawing wheel 3.1
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W31, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W31 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	//drawing wheel 3.2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W32, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W32 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	////////////////////////////////////////////////////////////Train 4 Wheels//////////////////////////////////////////////////

//drawing wheel 4.1
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W41, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W41 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	//drawing wheel 4.2
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_W42, Y);

	for (int i = 0; i <= NumSegments; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_W42 + R_WHEEL * cos(angle);
		float y = Y + R_WHEEL * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}
void drawCloud()
{
	////////////////////////////////////////////////////CLOUD 1 START///////////////////////////////////////////////

	//////////////////////////////////////CENTER CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X_CLOUD, Y_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X_CLOUD + R_CLOUD * cos(angle);
		float y = Y_CLOUD + R_CLOUD* sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();

	//////////////////////////////////////LEFT CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X1_CLOUD, Y1_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X1_CLOUD + R1_CLOUD * cos(angle);
		float y = Y1_CLOUD+ R1_CLOUD * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();
	//////////////////////////////////////RIGHT CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X2_CLOUD, Y2_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X2_CLOUD + R2_CLOUD * cos(angle);
		float y = Y2_CLOUD + R2_CLOUD * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();
	//////////////////////////////////////////////////////////CLOUD 1 END/////////////////////////////////////////////

	/////////////////////////////////////////////////////////CLOUD 2 START/////////////////////////////////////////
	
	//////////////////////////////////////CENTER CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X3_CLOUD, Y3_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X3_CLOUD + R3_CLOUD * cos(angle);
		float y = Y3_CLOUD + R3_CLOUD * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();

	//////////////////////////////////////LEFT CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X4_CLOUD, Y4_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X4_CLOUD + R4_CLOUD * cos(angle);
		float y = Y4_CLOUD + R4_CLOUD * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();
	//////////////////////////////////////RIGHT CIRCLE/////////////////////////
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);

	// Specify the center vertex of the fan
	glVertex2f(X5_CLOUD, Y5_CLOUD);

	// Loop through the segments and specify the vertices on the circle
	for (int i = 0; i <= NumSegments; i++)
	{
		// Calculate the angle and the coordinates of the vertex
		float angle = i * 2.0 * M_PI / NumSegments;
		float x = X5_CLOUD + R5_CLOUD * cos(angle);
		float y = Y5_CLOUD + R5_CLOUD * sin(angle);

		// Specify the vertex
		glVertex2f(x, y);
	}
	glEnd();
	
	///////////////////////////////////////////////////CLOUD 2 END///////////////////////////////////////
}
///////////////////////////////////////////////////FUNCTION TO DRAW SIGN//////////////////////////////////////////////////
void drawSign()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(100.0, 0.0, 0.0);
		glVertex3f(0.0, 32.0, 0.0);
		glVertex3f(100.0, 32.0, 0.0);
	glEnd();

}

///////////////////////////////////////////////////FUNCTION TO DRAW TREE//////////////////////////////////////////////////
void drawTree()
{
	////////////////////////////////////TREE 1 (RIGHT)
	
	//tree branch
	glColor3f(0.3, 0.1, 0.1); //set the color of the tree branch
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(71.0, 9.0, 0.0);
		glVertex3f(75.0, 9.0, 0.0);
		glVertex3f(71.0, 60.0, 0.0);
		glVertex3f(75.0, 60.0, 0.0);
	glEnd();

	//tree leaves (green circle)
	glColor3f(0.0, 0.5, 0.0); //set the color of the tree leaves
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X_TREE, Y_TREE);

	for (int i = 0; i <= NumSegments_TREE; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments_TREE;
		float x = X_TREE + R_TREE * cos(angle);
		float y = Y_TREE + R_TREE * sin(angle);

		glVertex2f(x, y);
	}
	glEnd();

	////////////////////////////////////TREE 2 (LEFT)

	//tree branch
	glColor3f(0.3, 0.1, 0.1); //set the color of the tree branch
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(18.0, 9.0, 0.0);
		glVertex3f(22.0, 9.0, 0.0);
		glVertex3f(18.0, 45.0, 0.0);
		glVertex3f(22.0, 45.0, 0.0);
	glEnd();

	//tree leaves (green circle)
	glColor3f(0.0, 0.5, 0.0); //set the color of the tree leaves
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(X1_TREE, Y1_TREE);

	for (int i = 0; i <= NumSegments_TREE; i++)
	{
		float angle = i * 2.0 * M_PI / NumSegments_TREE;
		float x = X1_TREE + R1_TREE * cos(angle);
		float y = Y1_TREE + R1_TREE * sin(angle);

		glVertex2f(x, y);
	}
	glEnd();
}
/////////////////////////////////////////////////////FUNCTION TO DRAW HILL///////////////////////////////////////////
void drawHill() //Note for programmers: this function may be used in further projects as an island in a different scene, and one might add a palm tree to it (using triangular strips)
{
	float colors[][3] = {
		 {0.011f, 0.462f, 0.239f},
		 {0.098f, 0.525f, 0.263f},
		 {0.278f, 0.576f, 0.341f},
		 {0.816f, 0.949f, 0.518f},
		 {0.369f, 0.655f, 0.204f}
	};

	glBegin(GL_TRIANGLE_FAN);
	for (int i = -VerticesNum_HILL; i <= VerticesNum_HILL; ++i)
	{
		glVertex3f(48.0 + 30.0 * (float)i / VerticesNum_HILL, 50 + -50.0 * (float)(i * i) / (VerticesNum_HILL * VerticesNum_HILL), 0.0);
		for (int i = 0; i < 5; ++i)
		{
			glColor3fv(colors[i]);

		}
	}
	glEnd();

}
void drawHill2()
{
	float colors[][3] = {
		 {0.011f, 0.462f, 0.239f},
		 {0.098f, 0.525f, 0.263f},
		 {0.278f, 0.576f, 0.341f},
		 {0.816f, 0.949f, 0.518f},
		 {0.369f, 0.655f, 0.204f}
	};

	glBegin(GL_TRIANGLE_FAN);
	for (int i = -VerticesNum_HILL; i <= VerticesNum_HILL; ++i)
	{
		glVertex3f(10.0 + 30.0 * (float)i / VerticesNum_HILL, 70.0 + -70.0 * (float)(i * i) / (VerticesNum_HILL * VerticesNum_HILL), 0.0);
		for (int i = 0; i < 5; ++i)
		{
			glColor3fv(colors[i]);

		}
	}
	glEnd();

}
void drawHill3()
{
	float colors[][3] = {
		 {0.011f, 0.462f, 0.239f},
		 {0.098f, 0.525f, 0.263f},
		 {0.278f, 0.576f, 0.341f},
		 {0.816f, 0.949f, 0.518f},
		 {0.369f, 0.655f, 0.204f}
	};

	glBegin(GL_TRIANGLE_FAN);
	for (int i = -VerticesNum_HILL; i <= VerticesNum_HILL; ++i)
	{
		glVertex3f(86.0 + 30.0 * (float)i / VerticesNum_HILL, 70.0 + -70.0 * (float)(i * i) / (VerticesNum_HILL * VerticesNum_HILL), 0.0);
		for (int i = 0; i < 5; ++i)
		{
			glColor3fv(colors[i]);

		}
	}
	glEnd();

}

///////////////////////////////////////////////////////////////FUNCTION TO DRAW CEIL AND FLOOR OF TRAIN////////////////////////////////
void drawCeilofTrain() {
	glColor3f(0.0, 0.0, 1.0);
	////////////////////////////////////////////////////ceil of train1//////////////////////////////////////////


	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
	glVertex3f(18.5, 26, 0.0);
	glVertex3f(30, 26, 0.0);
	glVertex3f(18.5, 27.5, 0.0);
	glVertex3f(30, 27.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////ceil of train2//////////////////////////////////////////


	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
	glVertex3f(32, 23, 0.0);
	glVertex3f(50.5, 23, 0.0);
	glVertex3f(32, 24.5, 0.0);
	glVertex3f(50.5, 24.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////ceil of train3//////////////////////////////////////////
	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
	glVertex3f(52, 23, 0.0);
	glVertex3f(70.5, 23, 0.0);
	glVertex3f(52, 24.5, 0.0);
	glVertex3f(70.5, 24.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////ceil of train4//////////////////////////////////////////
	glBegin(GL_TRIANGLE_STRIP); //left half of the shape
	glVertex3f(71.75, 23, 0.0);
	glVertex3f(90.5, 23, 0.0);
	glVertex3f(71.75, 24.5, 0.0);
	glVertex3f(90.5, 24.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////DRIVER////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(12, 23.0, 0.0);
	glVertex3f(14.3, 23.0, 0.0);
	glVertex3f(12.0, 24.5, 0.0);
	glVertex3f(14.3, 24.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////floor train1////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(10, 11, 0.0);
	glVertex3f(29.5, 11, 0.0);
	glVertex3f(10, 12.5, 0.0);
	glVertex3f(29.5, 12.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////floor train2////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(32, 11, 0.0);
	glVertex3f(50.5, 11, 0.0);
	glVertex3f(32, 12.5, 0.0);
	glVertex3f(50.5, 12.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////floor train3////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(52, 11, 0.0);
	glVertex3f(70.5, 11, 0.0);
	glVertex3f(52, 12.5, 0.0);
	glVertex3f(70.5, 12.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////floor train4////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(72, 11, 0.0);
	glVertex3f(90.5, 11, 0.0);
	glVertex3f(72, 12.5, 0.0);
	glVertex3f(90.5, 12.5, 0.0);
	glEnd();
	////////////////////////////////////////////////////frame train1////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(10, 12.5, 0.0);
	glVertex3f(11, 12.5, 0.0);
	glVertex3f(10, 19, 0.0);
	glVertex3f(11, 19, 0.0);
	glEnd();

}

/////////////////////////////////////////////////////FUNCTION TO DISPLAY///////////////////////////////////////////
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.5, 0.0); //set the color of the hill
	drawHill();

	glColor3f(0.0, 0.5, 0.0); //set the color of the hill
	drawHill2();

	glColor3f(0.0, 0.5, 0.0); //set the color of the hill
	drawHill3();

	//colors of leaf and branch are different, so color function is placed in drawTree function
	drawTree();
	
	glColor3f(0.9, 0.9, 0.9); //set the color of the welcome sign
	drawSign();

	glColor3f(0.5, 0.0, 0.0); //set the color of the double annulus (train)
	drawTrain(); //function of train

	glColor3f(0.9, 0.9, 0.0); //set the color of the sun
	drawSun(); //function of shape  

	glColor3f(1.0, 1.0, 1.0); //set the color of the cloud
	drawCloud(); //function of shape  
	
	glColor3f(0.2, 0.2, 0.2); //set the color of the path
	drawPath();

	glColor3f(0.0, 0.3, 0.3); //set the color of the ceil of train
	drawCeilofTrain();

	glColor3f(0.0, 0.0, 0.0); //set the color of the wheel
	drawWheel(); //function of shape  

	glColor3f(0.2, 0.2, 0.2); //set the color of the ceil of train
	drawSmoke();

	glFlush();
}

///////////////////////////////////////////////////////////////FUNCTION OF OpenGL window reshape/////////////////////////////////////
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

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

	glutInitWindowSize(700, 600);
	glutInitWindowPosition(500, 20);

	glutCreateWindow("2D Scene: Train Landscape.cpp");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glClearColor(0.0, 0.8, 0.9, 0.0); //setting the background colour (sky)
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