/*
Assignment 3: You’re required to animate a man throwing a ball at a wall.
Scenario: The man rotates/swings his arm and throws the ball. The ball hits the wall and bounces off, to
hit the ground. Try to make the ball motion look as real as possible. (hint: see projectile motion)

- The scene should be in 3D.
- Draw a ground and a wall.
- The animation should start/stop as the user presses space bar. If the animation ends, pressing space
bar should be able to replay it.
- The whole scene including the man’s body should be proportional.
- The user should be able to rotate the scene in different directions using x,X,y,Y,z,Z

Bonus: Animating the ball bouncing a few times after falling on the ground, to make it look more realistic.
*/

///////////////////////////////////////////////////////////////////////////////////
// Interaction:
// Press space to toggle between animation on and off
// Press x, X, y, Y, z, Z to turn the objects and rotate the scene
// Press r to reset
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h> 

// Globals
static int isAnimate = 0; // Animated? (determined with space bar key input from user)
static int animationPeriod = 100; // Time interval between frames
float t = 0.0; // time parameter (incremented in 'animate' function)

float g = 0.2; // gravitational accelaration
float r = 2.0; // radius of the ball

float h1 = 3.6; // horizontal component of initial velocity in animation 1 (wall)
float v1 = 1.4; // vertical component of initial velocity in animation 1 (wall)

float h2 = 1.0; // horizontal component of initial velocity in animation 2 (ground)
float v2 = 0.2; // vertical component of initial velocity in animation 2 (ground)

float dist_x; // horizontal distance traveled by the ball
float dist_y; // vertical distance traveled by the ball

float dist_x1; // horizontal distance traveled by the ball after collision with the wall
float dist_y1; // vertical distance traveled by the ball after collision with the ground

float dist_wall = 10.0 + r * 2; // horizontal distance to the wall 

float dist_x_ground = -10.0; // horizontal distance to the ground
float dist_y_ground = -11.0; // vertical distance to the ground

float initial_x; // x of the ball's initial position
float initial_y; // y of the ball's initial position

//Bouncing related parameters (bonus)
float dist_x_bounce; // horizontal distance traveled by the ball after bouncing
float dist_y_bounce; // vertical distance traveled by the ball after bouncing
float hb = 3.6; // horizontal component of initial velocity for bouncing
float vb = 1.4; // vertical component of initial velocity for bouncing

//Angles to rotate objects
float Xangle = 0.0;
float Yangle = 0.0;
float Zangle = 0.0;

// Drawing routine
void drawScene(void)
{
    glPushMatrix(); //start of the large push/pop matrix 
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Place scene in frustum
    glTranslatef(-10.0, 0.0, -30.0);

    // Rotating the scene
    glRotatef(Xangle, 1.0, 0.0, 0.0);
    glRotatef(Yangle, 0.0, 1.0, 0.0);
    glRotatef(Zangle, 0.0, 0.0, 1.0);

    // drawing ground 
    // note: this is not the most efficient way to draw the ground, it was simply
    // a systematic error and it was 'fixed' with error carried forward from the wall
    glPushMatrix();
    //glColor3f(0.0, 0.4, 0.0); //green color for the grass 
    glColor3f(0.13, 0.37, 0.31); //green color for the grass 
    glScalef(1.5, 10.0, 10.0); //scaling the ground
    glTranslatef(10.0 + r * 2, 0.0, 0.0); //to initialze position of the ground
    glScalef(11.0, 1.0, 1.0); //scaling the ground 
    glTranslatef(-0.5, -5.24 + 1.6, 0.0); //to initialze position of the ground
    glutSolidCube(5.0);
    glPopMatrix();

    // drawing wall 
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(1.0, 10.0, 10.0); //scaling the wall
    glTranslatef(20.0 + r * 2, 0.15, 0.0); //to initialze position of the wall
    glutSolidCube(r);
    glPopMatrix();
    
    // before collision with wall
    if (dist_x < dist_wall || dist_x == dist_wall)
    {
        //initial position
        initial_x = r * 2;
        initial_y = 0.0;

        // Apply equations of motion to transform sphere
        dist_x = h1 * t;
        dist_y = v1 * t - (g / 2.0) * t * t;

        glPushMatrix();
        glTranslatef(dist_x, dist_y, 0.0); //to MOVE the ball (animation)
        glTranslatef(initial_x, initial_y, 0.0); //to initialze position of the ball

        // drawing the ball towards the wall
        glColor3f(1.0, 0.1, 0.0); //orange as a basketball
        glRotatef(90.0, 1.0, 0.0, 0.0); //to initialze position of the ball
        glutWireSphere(r + 1.0, 20, 20); //using 'wire' just as a draft to show that it is 3D
        glPopMatrix();
    }

    //after collision with wall
    if (dist_x > dist_wall)
    {
        //initial position after it hits the wall (just before collision)
        initial_x = dist_x - r * 3;
        initial_y = r * 1.2;

        // Apply equations of motion to transform sphere
        dist_x1 = h2 * t; 
        dist_y1 = v2 * t - (g / 2.0) * t * t + initial_y;

        glPushMatrix();
        glTranslatef(dist_x - dist_x1, dist_y1, 0.0); //to MOVE the ball (animation)
        glTranslatef(initial_x, initial_y, 0.0); //to initialze position of the ball

        // drawing the ball to rebound from the wall
        glColor3f(1.0, 0.1, 0.0); //orange as a basketball
        glRotatef(90.0, 1.0, 0.0, 0.0); //to initialze position of the ball
        glutWireSphere(r + 1.0, 20, 20); //using 'wire' just as a draft to show that it is 3D
        glPopMatrix();

        //collision with the ground
        if (dist_y1 < dist_y_ground)
        {
            isAnimate = 0; // set to stop animation for now, to be edited later for bonus law fih wa2t :)
            /*
             
            //initial position for bouncing
            initial_x = dist_x - r * 3;
            initial_y = dist_y_ground;

            // Apply equations of motion to transform sphere
            dist_x_bounce = hb * t;
            dist_y_bounce = vb * t - (g / 2.0) * t * t + initial_y;

            glPushMatrix();
            glTranslatef(-dist_x_bounce, dist_y_bounce, 0.0); //to MOVE the ball (animation)
            glTranslatef(dist_x_ground, dist_y_ground, 0.0); //to initialze position of the ball

            // drawing the ball bouncing
            glColor3f(0.0, 0.0, 1.0);
            glRotatef(90.0, 1.0, 0.0, 0.0); //to initialze position of the ball
            glutWireSphere(r, 20, 20); //using 'wire' just as a draft to show that it is 3D
            glPopMatrix();

            /*

            // Apply equations of motion to transform sphere
            

            glPushMatrix();
            glTranslatef(dist_x - dist_x1, dist_y1, 0.0); //to MOVE the ball (animation)
            glTranslatef(initial_x, initial_y, 0.0); //to initialze position of the ball

            // drawing the ball to rebound from the wall
            glColor3f(0.0, 0.0, 1.0);
            glRotatef(90.0, 1.0, 0.0, 0.0); //to initialze position of the ball
            glutWireSphere(r, 20, 20); //using 'wire' just as a draft to show that it is 3D
            glPopMatrix();

            */

            //*/
        }
    }

    glutSwapBuffers();

    glPopMatrix(); //end of the large push/pop matrix 
}

// Timer function for semi-automatic animation (using space bar by the user)
void animate(int value)
{
    if (isAnimate)
    {
        t += 0.4;

        glutPostRedisplay();
        glutTimerFunc(animationPeriod, animate, 1);
    }
}

// Initialization routine.
void setup(void)
{
    /*
    //////////////////////////////////////setting up the 3D illusion of the ball//////////////////
    // Material property vectors.
    float matSpec[] = { 0.0, 1.0, 1.0, 1.0 };
    float matShine[] = { 50.0 };
    float matAmbAndDif[] = { 0.0, 0.1, 1.0, 1.0 };

    // Light property vectors.
    float lightAmb[] = { 0.0, 0.1, 1.0, 1.0 };
    float lightDifAndSpec[] = { 0.0, 0.1, 1.0, 1.0 };
    float lightPos[] = { 0.0, 7.0, 3.0, 0.0 };
    float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

    // Material properties of the objects.
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matAmbAndDif);

    // Light0 properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Poperties of the ambient light.
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

    glEnable(GL_LIGHTING); // Enable lighting calculations.
    glEnable(GL_LIGHT0); // Enable particular light source.
    glEnable(GL_DEPTH_TEST); // Enable depth testing.

    glEnable(GL_NORMALIZE); // Enable automatic normalization of normals.
    */

    //glClearColor(0.14, 0.14, 0.56, 0.0); //setting background color to navy blue (night sky)
    //glClearColor(0.3, 0.3, 0.3, 0.0); //setting background color to light grey
    glClearColor(0.196078, 0.6, 0.8, 0.0); //setting background color to blue
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine (input from user)
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case ' ': // Space bar controls start/stop of animation
        if (isAnimate) 
            isAnimate = 0; // Stop animation if it's already running
        else {
            if (t >= 5.0) // Check if animation has ended
            { 
                // Animation has ended, so reset parameters
                t = 0.0;
                dist_x = 0.0;
                dist_y = 0.0;
            }
            isAnimate = 1; // Start animation
            animate(1);
        }
        break;
    case 'r':
        isAnimate = 0;
        t = 0.0;
        initial_x = r * 2;
        initial_y = 0.0;
        dist_x = 0.0;
        dist_y = 0.0;
        Xangle = 0.0;
        Yangle = 0.0;
        Zangle = 0.0;
        glutPostRedisplay();
        break;
    case 'x':
        Xangle += 5.0;
        if (Xangle > 360.0) Xangle -= 360.0;
        glutPostRedisplay();
        break;
    case 'X':
        Xangle -= 5.0;
        if (Xangle < 0.0) Xangle += 360.0;
        glutPostRedisplay();
        break;
    case 'y':
        Yangle += 5.0;
        if (Yangle > 360.0) Yangle -= 360.0;
        glutPostRedisplay();
        break;
    case 'Y':
        Yangle -= 5.0;
        if (Yangle < 0.0) Yangle += 360.0;
        glutPostRedisplay();
        break;
    case 'z':
        Zangle += 5.0;
        if (Zangle > 360.0) Zangle -= 360.0;
        glutPostRedisplay();
        break;
    case 'Z':
        Zangle -= 5.0;
        if (Zangle < 0.0) Zangle += 360.0;
        glutPostRedisplay();
        break;
    default:
        break;
    }
    // Check if animation ended and reset animation parameters
    if (t > 5.0) {
        isAnimate = 0;
        t = 0.0;
        initial_x = r * 2;
        initial_y = 0.0;
    }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    std::cout << "Interaction: " << std::endl
        << "Press space to toggle between animation on and off." << std::endl
        << "Press x, X, y, Y, z, Z to turn the objects." << std::endl
        << "Press r to reset." << std::endl; //to be edited later, as mentioned before in the code
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ball hits the wall.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}