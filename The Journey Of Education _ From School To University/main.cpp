//button pressed
// 1 = Transaction scene
// 2 = School
// 3 = College
// 4 = University
// 5 = Classroom
// 6 = Yellow bus stop
// Mouse right = Yellow bus move
// 7 = Blue bus stop
// Mouse left = Blue bus move



#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

//For object movement
float moveB,moveB1,moveB2, moveC, moveC1,moveC2, moveW, moveY , moveF1, moveM3, moveM4, moveMM2, moveT1, moveT2, moveN3, moveN4 = 0.0f;

//schoolLife
   float moveM2= -10.0f;
   bool movingDown = false;
   bool isVisible = false;

//collegeLife
   float angle = 0.0;
   float moveN = 10.0f;
   bool slideDown = false;
   bool isShown = false;

//universityLife
   bool down = false;
   bool visible = false;
   bool extraObjectVisible = false;

//transactionMiddle
   bool showTitle = true;
   bool showThankYou = false;
   int transitionType = 0;
   bool showTransitionText = false;

//classRoom
   bool isScienceText = false;
   bool isCSEText = false;

//mouseClicked
   bool isRightPaused = false;
   bool isLeftPaused = false;
   bool moveRight = true;

//buttonclicked
   int currentScene = 1;

//sun move
   float timeOfDay = 0.0f;
   float speed = 0.02f;



///function to display text
   void renderBitmapString(float x, float y, void *font, const char *string) {
   glRasterPos2f(x, y);
   while (*string) {
   glutBitmapCharacter(font, *string);
   string++;
    }
}
///function to display circle
    void drawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount) {
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

///function to display turbine
    void drawBlade() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.7, 0.4, 0.4);
    glVertex2f(-0.35, 0);
    glVertex2f(0.35, 0);
    glVertex2f(-2.0, -0.8);
    glEnd();
}
void drawTurbine() {
    glPushMatrix();
    glTranslatef(-20, 24, 0);
    glRotatef(angle, 0, 0, 1);
    for (int i = 0; i < 3; i++) {
        drawBlade();
        glRotatef(120, 0, 0, 1);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20, 24, 0);
    glRotatef(angle, 0, 0, 1);
    for (int i = 0; i < 3; i++) {
        drawBlade();
        glRotatef(120, 0, 0, 1);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-28, 22, 0);
    glRotatef(angle, 0, 0, 1);
    for (int i = 0; i < 3; i++) {
        drawBlade();
        glRotatef(120, 0, 0, 1);
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(28, 22, 0);
    glRotatef(angle, 0, 0, 1);
    for (int i = 0; i < 3; i++) {
        drawBlade();
        glRotatef(120, 0, 0, 1);
    }
    glPopMatrix();
}


///function to display CloudAndBird

void drawCloudAndBird(){
     ///Clouds
    ///Cloud-01
   glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-27.00f, 25.00f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-27.00f, 26.00f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-26.00f, 26.00f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-26.00f, 25.00f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-25.00f, 25.5f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-28.00f, 25.50f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
        glEnd();

    ///cloud-02
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(25.00f, 23.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(25.00f, 24.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(26.00f, 24.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(26.00f, 23.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(27.00f, 23.5f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(24.00f, 23.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

    ///cloud-03
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(10.00f, 25.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(10.00f, 26.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(11.00f, 26.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(11.00f, 25.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(12.00f, 25.5f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(9.00f, 25.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

     ///cloud-04
    glPushMatrix();
    glTranslatef(moveC,0.0f,0.0f);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.00f, 23.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.00f, 24.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-11.00f, 24.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-11.00f, 23.0f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-12.00f, 23.5f, 1.0f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-9.00f, 23.5f, 1.0f, 100);
    glPopMatrix();
    glPopMatrix();
    glEnd();

    /// Birds 1st
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   glLineWidth(0.5);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(-12.0f, 21.0f);
   glVertex2f(-11.95f, 20.5f);
   glVertex2f(-11.95f, 20.5f);
   glVertex2f(-11.5f, 21.0f);
   glEnd();
   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(-11.0f, 22.0f);
   glVertex2f(-10.95f, 21.5f);
   glVertex2f(-10.95f, 21.5f);
   glVertex2f(-10.55f, 22.0f);
   glEnd();
   // Bird 3
    glBegin(GL_LINES);
    glVertex2f(-10.0f, 21.0f);
    glVertex2f(-9.95f, 20.5f);
    glVertex2f(-9.95f, 20.5f);
    glVertex2f(-9.5f, 21.0f);
    glEnd();
    glPopMatrix();

    /// Birds 2nd
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   glLineWidth(0.1);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(11.0f, 21.0f);
   glVertex2f(11.05f, 20.5f);
   glVertex2f(11.05f, 20.5f);
   glVertex2f(11.45f, 21.0f);
   glEnd();

   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(10.0f, 22.0f);
   glVertex2f(10.05f, 21.5f);
   glVertex2f(10.05f, 21.5f);
   glVertex2f(10.45f, 22.0f);
   glEnd();

    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(9.0f, 21.0f);
    glVertex2f(9.05f, 20.5f);
    glVertex2f(9.05f, 20.5f);
    glVertex2f(9.45f, 21.0f);
    glEnd();
    glPopMatrix();

    /// Birds 3rd
   glPushMatrix();
   glTranslatef(0.0f, moveB, 0.0f);
   // Bird 1
   glBegin(GL_LINES);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2f(25.0f, 21.0f);
   glVertex2f(25.05f, 20.5f);
   glVertex2f(25.05f, 20.5f);
   glVertex2f(25.45f, 21.0f);
   glEnd();
   // Bird 2
   glBegin(GL_LINES);
   glVertex2f(24.0f, 22.0f);
   glVertex2f(24.05f, 21.5f);
   glVertex2f(24.05f, 21.5f);
   glVertex2f(24.45f, 22.0f);
   glEnd();
    // Bird 3
    glBegin(GL_LINES);
    glVertex2f(23.0f, 21.0f);
    glVertex2f(23.05f, 20.5f);
    glVertex2f(23.05f, 20.5f);
    glVertex2f(23.45f, 21.0f);
    glEnd();
    glPopMatrix();
}


///function to display Boat
    /// Boat Code
    void drawBoat1() {
    ///Boat 01
    glPushMatrix();
    glTranslatef(moveB1, 0.0f, 0.0f);
    // Body
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(1.8f, 17.4f);
    glVertex2f(2.7f, 16.8f);
    glVertex2f(5.3f, 16.8f);
    glVertex2f(6.2f, 17.4f);
    glEnd();

     // Body
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(4.6f, 17.4f);
    glVertex2f(5.0f, 17.9f);
    glVertex2f(5.4f, 17.4f);
    glEnd();
    // Body
    glColor3f(0.9f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(4.6f, 17.4f);
    glVertex2f(5.0f, 17.9f);
    glVertex2f(2.9f, 17.9f);
    glVertex2f(2.5f, 17.4f);
    glEnd();

    glLineWidth(0.2);
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(2.4f, 17.9f);
    glVertex2f(2.0f, 15.9f);
    glVertex2f(3.9f, 17.9f);
    glVertex2f(3.9f, 18.2f);
    glEnd();

    // Body
    glColor3f(0.9f, 0.6f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(3.1f, 18.2f);
    glVertex2f(3.3f, 19.7f);
    glVertex2f(4.8f, 18.2f);
    glEnd();
    glPopMatrix();

    ///BOAT 02
    glPushMatrix();
    glTranslatef(moveB2, 0.0f, 0.0f);
    // Body
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(2.0f, 16.0f);
    glVertex2f(3.0f, 15.2f);
    glVertex2f(7.0f, 15.2f);
    glVertex2f(8.0f, 16.0f);
    glEnd();
    // Body
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(6.0f, 16.0f);
    glVertex2f(6.5f, 16.5f);
    glVertex2f(7.0f, 16.0f);
    glEnd();
    // Body
    glColor3f(1.0f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(6.0f, 16.0f);
    glVertex2f(6.5f, 16.5f);
    glVertex2f(4.0f, 16.5f);
    glVertex2f(3.5f, 16.0f);
    glEnd();
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(3.0f, 16.8f);
    glVertex2f(2.5f, 14.5f);
    glVertex2f(5.0f, 16.5f);
    glVertex2f(5.0f, 16.8f);
    glEnd();
    // Body
    glColor3f(0.9f, 0.8f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(4.1f, 16.8f);
    glVertex2f(5.6f, 18.5f);
    glVertex2f(5.8f, 16.8f);
    glEnd();
    glPopMatrix();
}



///function to display schoolLife
    void schoolLife() {
    glClear(GL_COLOR_BUFFER_BIT);

    /// SKY
   glBegin(GL_QUADS);
    glColor3f(0.4f, 0.75f, 1.0f);
    glVertex2f(-35.0, 35.0);
    glVertex2f(35.0, 35.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    /// SUN
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(10.40f, 27.00f, 0.8f, 100);

    /// Sea
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.9f, 1.0f);
    glVertex2f(-35.0, 19.0);
    glVertex2f(35.0, 19.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 9.0);
    glVertex2f(-35.0, 15.0);
    glEnd();
    drawBoat1();
    drawCloudAndBird();

    ///green middle ground
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.9f, 0.3f);
    glVertex2f(-35.0, 15.0);
    glVertex2f(35.0, 9.0);
    glColor3f(0.0f, 0.692f, 0.0f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///half  ground
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.9f, 0.4f);
    glVertex2f(-35.0, 12.0);
    glVertex2f(35.0, 3.0);
    glColor3f(0.0f, 0.692f, 0.0f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///upper FOOTBATH
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-35.0, 1.2);
    glVertex2f(35.0, 1.2);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///Road
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.55f, 0.55f);
    glVertex2f(-35.0, 0.0);
    glVertex2f(35.0, 0.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(35.0, -21.0);
    glVertex2f(-35.0, -21.0);
    glEnd();

    /// Gradient Road
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
   glVertex2f(-35.0, -21.0);
   glVertex2f(6.0, -21.0);

    glColor3f(0.0f, 0.792f, 0.0f);

    glVertex2f(5.0, -35.0);
    glVertex2f(-35.0, -35.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(20.0, -21.0);
    glVertex2f(35.0, -21.0);

    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -35.0);
    glVertex2f(19.0, -35.0);
    glEnd();

   ///lower FOOTPATH
     glBegin(GL_QUADS);
    glColor3f(0.45f, 0.45f, 0.45f);
   glVertex2f(6.0, -21.0);
    glVertex2f(5.0, -35.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(4.5, -35.0);
    glVertex2f(5.5, -21.0);
    glEnd();

      glBegin(GL_QUADS);
        glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-35.0, -21.0);
    glVertex2f(6.0, -21.0);
    glVertex2f(5.0, -21.5);
    glVertex2f(-35.0, -21.5);
    glEnd();

    //RIGHT
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(20.0, -21.0);
   glVertex2f(35.0, -21.0);
    glVertex2f(35.0, -21.5);
    glVertex2f(20.0, -21.5);
        glEnd();

      glBegin(GL_QUADS);
        glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(20.0, -21.0);
    glVertex2f(19.0, -35.0);
        glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(19.5, -35.0);
    glVertex2f(20.5, -21.0);
    glEnd();

   ///road break
   //  Gradient Road
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(6.0, -21.0);
    glVertex2f(5.0, -35.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(19.0, -35.0);
    glVertex2f(20.0, -21.0);
    glEnd();

    ///white black zebra crossing

    glLineWidth(10.0);
    glBegin(GL_LINES);
    //yellow
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(-11.1f, -2.5f);
    glVertex2f(-3.1f, -2.5f);
    glVertex2f(-11.2f, -4.5f);
    glVertex2f(-3.2f, -4.5f);
    glVertex2f(-11.3f, -6.5f);
    glVertex2f(-3.3f, -6.5f);
    glVertex2f(-11.4f, -8.5f);
    glVertex2f(-3.4f, -8.5f);
    glVertex2f(-11.5f, -12.5f);
    glVertex2f(-3.5f, -12.5f);
    glVertex2f(-11.6f, -14.5f);
    glVertex2f(-3.6f, -14.5f);
    glVertex2f(-11.7f, -16.5f);
    glVertex2f(-3.7f, -16.5f);
    glVertex2f(-11.8f, -18.5f);
    glVertex2f(-3.8f, -18.5f);
    glEnd();

    ///yellow cross mark
    glLineWidth(1.0);
    glBegin(GL_LINES);
    //side
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-35.0f, -0.5f);
    glVertex2f(35.0f, -0.5f);
    glVertex2f(-35.0, -20.5);
    glVertex2f(6.3, -20.5);
    glVertex2f(6.3, -20.5);
    glVertex2f(5.3, -35.0);
    glVertex2f(19.8, -20.5);
    glVertex2f(35.0, -20.5);
    glVertex2f(19.8, -20.5);
    glVertex2f(18.7, -35.0);
    glEnd();
    glLineWidth(5.0);
    glBegin(GL_LINES);
    //yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-37.0f, -10.5f);
    glVertex2f(-33.0f, -10.5f);
    glVertex2f(-30.0f, -10.5f);
    glVertex2f(-27.0f, -10.5f);
    glVertex2f(-24.0f, -10.5f);
    glVertex2f(-21.0f, -10.5f);
    glVertex2f(-18.0f, -10.5f);
    glVertex2f(-15.0f, -10.5f);
    glVertex2f(-12.0f, -10.5f);
    glVertex2f(-9.0f, -10.5f);
    glVertex2f(-6.0f, -10.5f);
    glVertex2f(-3.0f, -10.5f);
    glVertex2f(0.0f, -10.5f);
    glVertex2f(3.0f, -10.5f);
    glVertex2f(6.0f, -10.5f);
    glVertex2f(9.0f, -10.5f);
    glVertex2f(12.0f, -10.5f);
    glVertex2f(15.0f, -10.5f);
    glVertex2f(18.0f, -10.5f);
    glVertex2f(21.0f, -10.5f);
    glVertex2f(24.0f, -10.5f);
    glVertex2f(27.0f, -10.5f);
    glVertex2f(30.0f, -10.5f);
    glVertex2f(33.0f, -10.5f);
    glVertex2f(36.0f, -10.5f);
    glVertex2f(39.0f, -10.5f);

   ///arrow
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(12.2f, -24.0f);
    glVertex2f(11.8f, -30.0f);
    glVertex2f(12.2f, -24.0f);
    glVertex2f(14.0f, -24.0f);
    glVertex2f(13.1f, -24.5f);
    glVertex2f(14.0f, -24.0f);
    glVertex2f(13.1f, -23.5f);
    glVertex2f(14.0f, -24.0f);
     glVertex2f(20.0f, -5.0f);
    glVertex2f(16.0f, -5.0f);
     glVertex2f(17.5f, -5.5f);
    glVertex2f(16.0f, -5.0f);
    glVertex2f(17.5f, -4.5f);
    glVertex2f(16.0f, -5.0f);
     glVertex2f(-28.0f, -15.0f);
    glVertex2f(-24.0f, -15.0f);
     glVertex2f(-25.5f, -15.5f);
    glVertex2f(-24.0f, -15.0f);
    glVertex2f(-25.5f, -14.5f);
    glVertex2f(-24.0f, -15.0f);
    glEnd();

   ///CIRCLE
    glColor3f(0.7f, 0.8f, 0.5f);
    drawCircle(-33.50, -30.0, 6.0, 100);
    drawCircle(-7.0, -35.0, 6.0, 100);
    drawCircle(34.50, -30.0, 6.0, 100);
    glColor3f(0.3f, 0.792f, 0.0f);
    drawCircle(-33.50, -30.0, 5.5, 100);
    drawCircle(-7.0, -35.0, 5.5, 100);
    drawCircle(34.50, -30.0, 5.5, 100);
    glEnd();
   //RIGHT
   glColor3f(0.8f, 0.9f, 0.6f);
   drawCircle(34.00, -26.0, 0.1, 100);
   drawCircle(34.00, -26.6, 0.1, 100);
   drawCircle(34.5, -26.3, 0.1, 100);
   drawCircle(31.00, -30.0, 0.1, 100);
   drawCircle(31.00, -30.6, 0.1, 100);
   drawCircle(30.5, -30.3, 0.1, 100);
   drawCircle(28.00, -26.0, 0.1, 100);
   drawCircle(28.00, -26.6, 0.1, 100);
   drawCircle(27.5, -26.3, 0.1, 100);
   drawCircle(25.00, -30.0, 0.1, 100);
   drawCircle(25.00, -30.6, 0.1, 100);
   drawCircle(24.5, -30.3, 0.1, 100);

   //LEFT
   drawCircle(-34.00, -26.0, 0.1, 100);
   drawCircle(-34.00, -26.6, 0.1, 100);
   drawCircle(-34.5, -26.3, 0.1, 100);
   drawCircle(-29.00, -30.0, 0.1, 100);
   drawCircle(-29.00, -30.6, 0.1, 100);
   drawCircle(-28.5, -30.3, 0.1, 100);
   drawCircle(-24.00, -26.0, 0.1, 100);
   drawCircle(-24.00, -26.6, 0.1, 100);
   drawCircle(-23.5, -26.3, 0.1, 100);
   drawCircle(-19.00, -30.0, 0.1, 100);
   drawCircle(-19.00, -30.6, 0.1, 100);
   drawCircle(-18.5, -30.3, 0.1, 100);
   drawCircle(-14.00, -26.0, 0.1, 100);
   drawCircle(-14.00, -26.6, 0.1, 100);
   drawCircle(-13.5, -26.3, 0.1, 100);
   drawCircle(-8.00, -30.0, 0.1, 100);
   drawCircle(-8.00, -30.6, 0.1, 100);
   drawCircle(-8.5, -30.3, 0.1, 100);
   drawCircle(-3.00, -26.0, 0.1, 100);
   drawCircle(-3.00, -26.6, 0.1, 100);
   drawCircle(-3.5, -26.3, 0.1, 100);
   drawCircle(2.00, -30.0, 0.1, 100);
   drawCircle(2.00, -30.6, 0.1, 100);
   drawCircle(2.5, -30.3, 0.1, 100);
   glEnd();

    ///school
    //back brown
    glColor3f(0.79f, 0.27f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-13.00, 15.00);
    glVertex2f(-2.00, 15.00);
    glVertex2f(-2.00, 7.00);
    glVertex2f(-13.00, 7.00);
    glEnd();

    //glass in upper brown
    glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-12.50, 14.50);
    glVertex2f(-11.50, 14.50);
    glVertex2f(-11.50, 12.00);
    glVertex2f(-12.50, 12.00);
    glEnd();

     glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-12.50, 10.50);
    glVertex2f(-11.50, 10.50);
    glVertex2f(-11.50, 8.00);
    glVertex2f(-12.50, 8.00);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.5);
    glBegin(GL_LINES);
    glVertex2f(-12.50, 14.50);
    glVertex2f(-11.50, 14.50);
    glVertex2f(-11.50, 14.50);
    glVertex2f(-11.50, 12.00);
    glVertex2f(-11.50, 12.00);
    glVertex2f(-12.50, 12.00);
    glVertex2f(-12.50, 12.00);
    glVertex2f(-12.50, 14.50);

    glVertex2f(-12.50, 10.50);
    glVertex2f(-11.50, 10.50);
    glVertex2f(-11.50, 10.50);
    glVertex2f(-11.50, 8.00);
    glVertex2f(-11.50, 8.00);
    glVertex2f(-12.50, 8.00);
    glVertex2f(-12.50, 8.00);
    glVertex2f(-12.50, 10.50);
    glEnd();

   //middle yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-11.00, 12.00);
    glVertex2f(-2.00, 12.00);
    glVertex2f(-2.00, 10.00);
    glVertex2f(-11.00, 10.00);
    glEnd();

   //glass in lower
     glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-8.50, 14.30);
    glVertex2f(-2.50, 14.30);
    glVertex2f(-2.50, 12.70);
    glVertex2f(-8.50, 12.70);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.5);
    glBegin(GL_LINES);
    glVertex2f(-8.50, 14.30);
    glVertex2f(-2.50, 14.30);
    glVertex2f(-2.50, 14.30);
    glVertex2f(-2.50, 12.70);
    glVertex2f(-2.50, 12.70);
    glVertex2f(-8.50, 12.70);
    glVertex2f(-8.50, 12.70);
    glVertex2f(-8.50, 14.30);

    glVertex2f(-7.50, 14.30);
    glVertex2f(-7.50, 12.70);
    glVertex2f(-6.50, 14.30);
    glVertex2f(-6.50, 12.70);
    glVertex2f(-5.50, 14.30);
    glVertex2f(-5.50, 12.70);
    glVertex2f(-4.50, 14.30);
    glVertex2f(-4.50, 12.70);
    glVertex2f(-3.50, 14.30);
    glVertex2f(-3.50, 12.70);
        glEnd();

    //GLASS2
    glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-8.50, 9.40);
    glVertex2f(-2.50, 9.40);
    glVertex2f(-2.50, 7.00);
    glVertex2f(-8.50, 7.00);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.5);
    glBegin(GL_LINES);
    glVertex2f(-8.50, 9.40);
    glVertex2f(-2.50, 9.40);
    glVertex2f(-2.50, 9.40);
    glVertex2f(-2.50, 7.00);
    glVertex2f(-2.50, 7.00);
    glVertex2f(-8.50, 7.00);
    glVertex2f(-8.50, 7.00);
    glVertex2f(-8.50, 9.40);
    glVertex2f(-8.50, 8.20);
    glVertex2f(-2.50, 8.20);
    glVertex2f(-7.50, 9.40);
    glVertex2f(-7.50, 7.00);
    glVertex2f(-6.50, 9.40);
    glVertex2f(-6.50, 7.00);
    glVertex2f(-5.50, 9.40);
    glVertex2f(-5.50, 7.00);
    glVertex2f(-4.50, 9.40);
    glVertex2f(-4.50, 7.00);
    glVertex2f(-3.50, 9.40);
    glVertex2f(-3.50, 7.00);
    glEnd();
   //gray
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-13.00, 15.00);
    glVertex2f(-2.00, 15.00);
    glVertex2f(-2.00, 15.50);
    glVertex2f(-13.20, 15.50);
    glEnd();
    //left white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-11.00, 15.80);
    glVertex2f(-9.00, 15.80);
    glVertex2f(-9.00, 7.00);
    glVertex2f(-11.00, 7.00);
    glEnd();

    //right white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-2.00, 15.80);
    glVertex2f(0.00, 15.80);
    glVertex2f(0.00, 7.00);
    glVertex2f(-2.00, 7.00);
    glEnd();
    //small brown
    glColor3f(0.79f, 0.27f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0.00, 13.70);
    glVertex2f(3.00, 13.70);
    glVertex2f(3.00, 7.00);
    glVertex2f(0.00, 7.00);
    glEnd();
    //glass in brown
    glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.70, 12.10);
    glVertex2f(2.30, 12.10);
    glVertex2f(2.30, 8.40);
    glVertex2f(0.70, 8.40);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.5);
    glBegin(GL_LINES);
    glVertex2f(0.70, 12.10);
    glVertex2f(2.30, 12.10);
    glVertex2f(2.30, 12.10);
    glVertex2f(2.30, 8.40);
    glVertex2f(2.30, 8.40);
    glVertex2f(0.70, 8.40);
    glVertex2f(0.70, 8.40);
    glVertex2f(0.70, 12.10);

    glVertex2f(0.70, 10.35);
    glVertex2f(2.30, 10.35);
    glVertex2f(1.52, 12.10);
    glVertex2f(1.52, 8.40);
    glEnd();
  //gray
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.00, 13.70);
    glVertex2f(3.00, 13.70);
    glVertex2f(3.10, 14.30);
    glVertex2f(0.00, 14.30);
    glEnd();

   //GLASS LEFT
    glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-10.50, 15.40);
    glVertex2f(-9.65, 15.40);
    glVertex2f(-9.65, 7.20);
    glVertex2f(-10.50, 7.20);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.2);
    glBegin(GL_LINES);
    glVertex2f(-10.50, 15.40);
    glVertex2f(-9.65, 15.40);
    glVertex2f(-9.65, 15.40);
    glVertex2f(-9.65, 7.20);
    glVertex2f(-9.65, 7.20);
    glVertex2f(-10.50, 7.20);
    glVertex2f(-10.50, 7.20);
    glVertex2f(-10.50, 15.40);
    glVertex2f(-10.50, 13.40);
    glVertex2f(-9.65, 13.40);
    glVertex2f(-10.50, 11.40);
    glVertex2f(-9.65, 11.40);
    glVertex2f(-10.50, 9.40);
    glVertex2f(-9.65, 9.40);
        glEnd();

    //right white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-2.00, 15.80);
    glVertex2f(0.00, 15.80);
    glVertex2f(0.00, 7.00);
    glVertex2f(-2.00, 7.00);
    glEnd();

    ///GLASS Right
    glColor3f(0.4f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.50, 15.40);
    glVertex2f(-0.65, 15.40);
    glVertex2f(-0.65, 7.20);
    glVertex2f(-1.50, 7.20);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(.5);
    glBegin(GL_LINES);
    glVertex2f(-1.50, 15.40);
    glVertex2f(-0.65, 15.40);
    glVertex2f(-0.65, 15.40);
    glVertex2f(-0.65, 7.20);
    glVertex2f(-0.65, 7.20);
    glVertex2f(-1.50, 7.20);
    glVertex2f(-1.50, 7.20);
    glVertex2f(-1.50, 15.40);

   glVertex2f(-1.50, 13.40);
    glVertex2f(-0.65, 13.40);
    glVertex2f(-1.50, 11.40);
    glVertex2f(-0.65, 11.40);
    glVertex2f(-1.50, 9.40);
    glVertex2f(-0.65, 9.40);
        glEnd();

    ///Flag
   //green
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f( 3.8, 15.00 );
    glVertex2f( 5.8, 15.00 );
    glVertex2f( 5.8, 13.25 );
    glVertex2f( 3.8, 13.25 );
    glEnd();
    //brown
    glLineWidth(1.50);
    glBegin(GL_LINES);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f( 3.8, 7.00 );
    glVertex2f( 3.8, 15.20 );
    glEnd();
    //red
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(4.8f, 14.15f, 0.40f, 100);
    glEnd();

   ///stair
    glLineWidth(9.00);
    glBegin(GL_LINES);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f( -14.50, 7.00 );
    glVertex2f( 4.90, 7.00 );
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f( -14.70, 6.50 );
    glVertex2f( 5.10, 6.50 );
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f( -14.90, 5.90 );
    glVertex2f( 5.30, 5.90 );
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f( -15.10, 5.20 );
    glVertex2f( 5.50, 5.20 );
    glEnd();

    ///shaheed minar
    //red
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-18.80f, 7.60f, 1.0f, 100);
    glEnd();
    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    //left
    glVertex2f( -21.05, 6.20 );
    glVertex2f( -21.05, 9.00);
    //second left
    glVertex2f( -20.25, 6.20 );
    glVertex2f( -20.25, 9.30 );
    //right
    glVertex2f( -16.47, 6.00 );
    glVertex2f( -16.47, 9.00 );
    //second right
    glVertex2f( -17.25, 6.00 );
    glVertex2f( -17.25, 9.50 );
    //middle
    glVertex2f( -18.98, 6.00 );
    glVertex2f( -18.98, 9.40 );
    glVertex2f( -18.68, 6.00 );
    glVertex2f( -18.68, 9.40 );
    //middle up
    glVertex2f( -18.98, 9.40 );
    glVertex2f( -18.70, 10.35 );
    glVertex2f( -18.68, 9.40 );
    glVertex2f( -18.40, 10.35 );
    glEnd();
    glLineWidth(4.00);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    //left
    glVertex2f( -20.80, 6.00 );
    glVertex2f( -20.80, 9.00 );
    glVertex2f( -20.80, 9.00 );
    glVertex2f( -21.30, 9.00 );
    glVertex2f( -21.30, 9.00);
    glVertex2f( -21.30, 6.00 );
   //second left
    glVertex2f( -20.0, 6.0 );
    glVertex2f( -20.0, 9.30 );
    glVertex2f( -20.0, 9.30 );
    glVertex2f( -20.50, 9.30 );
    glVertex2f( -20.50, 9.30 );
    glVertex2f( -20.50, 6.0 );
    //right
    glVertex2f( -16.20, 6.00 );
    glVertex2f( -16.20, 9.00 );
    glVertex2f( -16.20, 9.00 );
    glVertex2f( -16.70, 9.00 );
    glVertex2f( -16.70, 9.00 );
    glVertex2f( -16.70, 6.00 );
    //second right
    glVertex2f( -17.0, 6.00 );
    glVertex2f( -17.0, 9.50 );
    glVertex2f( -17.0, 9.50 );
    glVertex2f( -17.50, 9.50 );
    glVertex2f( -17.50, 9.50 );
    glVertex2f( -17.50, 6.00 );
    //middle
    glVertex2f( -18.30, 6.00 );
    glVertex2f( -18.30, 9.70 );
    glVertex2f( -19.30, 9.70 );
    glVertex2f( -19.30, 6.00 );
    //middle up
    glVertex2f( -18.30, 9.60 );
    glVertex2f( -18.10, 10.30 );
    glVertex2f( -19.30, 9.60 );
    glVertex2f( -19.10, 10.30 );
    glVertex2f( -18.10, 10.30 );
    glVertex2f( -19.10, 10.30 );
    glEnd();
    glLineWidth(4.00);
    glBegin(GL_LINES);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f( -22.10, 6.00 );
    glVertex2f( -15.60, 6.00 );
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f( -22.20, 5.70 );
    glVertex2f( -15.50, 5.70 );
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f( -22.30, 5.40 );
    glVertex2f( -15.40, 5.40 );
    glEnd();

    ///name of school
    glColor3f(0.6f, 0.0f, 0.3f);
    renderBitmapString(-7.50f, 10.70f, GLUT_BITMAP_HELVETICA_12, "Monipur School");
    glEnd();

///human
 if (isVisible)
    {
glPushMatrix();
glTranslatef(0.0f, moveM2, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-8.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(1.0, 0.5, 0.1);
glBegin(GL_QUADS);
glVertex2f(-8.50, -28.5);
glVertex2f(-7.50, -28.50);
glVertex2f(-7.50, -30.50);
glVertex2f(-8.50, -30.50);
glEnd();
glColor3f(0.2, 0.2, 0.2);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-8.20, -30.50);
glVertex2f(-8.20, -32.50);
glEnd();
glBegin(GL_LINES);
glVertex2f(-7.80, -30.50);
glVertex2f(-7.80, -32.50);
glEnd();

glPopMatrix();
glPopMatrix();

    }

     ///Bus 01
    glPushMatrix();
    glTranslatef(moveW , 0.0f , 0.0f);
    glLineWidth(0.5);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-11.90, -13.50);
    glVertex2f(-7.10, -13.50);
    glVertex2f(-7.00, -14.00);
    glVertex2f(-12.00, -14.00);
    glColor3f(0.7, 0.7, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -14.00);
    glVertex2f(-7.00, -14.00);
    glVertex2f(-7.00, -15.00);
    glVertex2f(-12.00, -15.00);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -15.00);
    glVertex2f(-7.00, -15.00);
    glVertex2f(-7.00, -16.50);
    glVertex2f(-12.00, -16.50);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-11.00f, -14.0f);
    glVertex2f(-11.00f, -15.03f);
    glVertex2f(-10.00f, -14.0f);
    glVertex2f(-10.00f, -15.03f);
    glVertex2f(-9.00f, -14.0f);
    glVertex2f(-9.00f, -15.03f);
    glVertex2f(-8.0f, -14.0f);
    glVertex2f(-8.0f, -15.03f);
    glEnd();

    //wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-7.80f, -16.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-7.80f, -16.30f, 0.25f, 100);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-10.80f, -16.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.80f, -16.30f, 0.25f, 100);
    glEnd();

    glPopMatrix();

    ///Bus 02
    glPushMatrix();
    glTranslatef(moveY, 0.0f , 0.0f);
    glLineWidth(0.5);

    glColor3f(0.1, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(7.10, -2.50);
    glVertex2f(11.90, -2.50);
    glVertex2f(12.00, -3.00);
    glVertex2f(7.00, -3.00);

    glColor3f(0.4, 0.7, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(7.00, -3.00);
    glVertex2f(12.00, -3.00);
    glVertex2f(12.00, -4.00);
    glVertex2f(7.00, -4.00);

    glColor3f(0.1, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(7.00, -4.00);
    glVertex2f(12.00, -4.00);
    glVertex2f(12.00, -5.50);
    glVertex2f(7.00, -5.50);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(11.00f, -3.0f);
    glVertex2f(11.00f, -4.0f);
    glVertex2f(10.00f, -3.0f);
    glVertex2f(10.00f, -4.0f);
    glVertex2f(9.00f, -3.0f);
    glVertex2f(9.00f, -4.0f);
    glVertex2f(8.0f, -3.0f);
    glVertex2f(8.0f, -4.0f);
    glEnd();

    //wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(7.80f, -5.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(7.80f, -5.30f, 0.25f, 100);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(10.80f, -5.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(10.80f, -5.30f, 0.25f, 100);
    glEnd();
    glPopMatrix();

    ///Tree drawing
//1ST RIGHT TREE
glColor3f(0.55f, 0.30, 0.07f);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(34.20, 7.8);
glVertex2f(34.20, 6.6);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(34.20, 8.4f, 0.65f, 100);
drawCircle(34.20, 9.10f, 0.45f, 100);
glEnd();

//2ND RIGHT TREE
glColor3f(0.55f, 0.30, 0.07f);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(27.9, 6.9);
glVertex2f(27.9, 5.7);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(27.9, 7.5f, 0.65f, 100);
drawCircle(27.9, 8.20f, 0.45f, 100);
glEnd();

//3RD LITTLE 01
glColor3f(0.8, 0.3, 0.2);
glLineWidth(2.50);
glBegin(GL_LINES);
glVertex2f(-33.03, 7.6);
glVertex2f(-33.03, 6.4);
glEnd();

glColor3f(0.35f, 0.55f, 0.03f);
drawCircle(-33.03, 8.4f, 0.65f, 100);
drawCircle(-33.03, 9.10f, 0.35f, 100);
glEnd();

//3RD LITTLE 02
glColor3f(0.8, 0.3, 0.2);
glLineWidth(2.50);
glBegin(GL_LINES);
glVertex2f(-30.95, 7.8);
glVertex2f(-30.95, 6.6);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-30.95, 8.4f, 0.65f, 100);
drawCircle(-30.95, 9.10f, 0.35f, 100);
glEnd();

//3RD LITTLE 02
glColor3f(0.8, 0.3, 0.2);
glLineWidth(2.50);
glBegin(GL_LINES);
glVertex2f(-28.95, 7.8);
glVertex2f(-28.95, 6.6);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-28.95, 8.4f, 0.65f, 100);
drawCircle(-28.95, 9.10f, 0.35f, 100);
glEnd();

//2ND LITTLE 01
glColor3f(0.8, 0.3, 0.2);
glLineWidth(3.50);
glBegin(GL_LINES);
glVertex2f(-34.0, 5.8);
glVertex2f(-34.0, 1.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-34.0, 6.4f, 0.90, 100);
drawCircle(-34.0, 7.10f, 0.70, 100);
glEnd();

//2ND LITTLE 02
glColor3f(0.8, 0.3, 0.2);
glLineWidth(3.50);
glBegin(GL_LINES);
glVertex2f(-32.0, 5.8);
glVertex2f(-32.0, 2.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-32.0, 6.4f, 0.90, 100);
drawCircle(-32.0, 7.10f, 0.70, 100);
glEnd();

//2ND LITTLE 03
     glColor3f(0.8, 0.3, 0.2);
glLineWidth(3.50);
glBegin(GL_LINES);
glVertex2f(-30.0, 5.8);
glVertex2f(-30.0, 2.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-30.0, 6.4f, 0.80f, 100);
drawCircle(-30.0, 7.10f, 0.60f, 100);
glEnd();

//2ND LITTLE 04
glColor3f(0.8, 0.3, 0.2);
glLineWidth(3.50);
glBegin(GL_LINES);
glVertex2f(-28.0, 5.8);
glVertex2f(-28.0, 1.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-28.0, 6.4f, 0.80, 100);
drawCircle(-28.0, 7.10f, 0.60, 100);
glEnd();

//1ST LITTLE 01
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-33.0, 1.0);
glVertex2f(-33.0, 3.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-33.00f, 4.00f, 1.0f, 100);
drawCircle(-33.00f, 5.00f, 0.6f, 100);
glEnd();
//1ST LITTLE 02
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-31.0, 1.0);
glVertex2f(-31.0, 3.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-31.00f, 4.00f, 1.0f, 100);
drawCircle(-31.00f, 5.00f, 0.6f, 100);
glEnd();
//1ST LITTLE 03
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-29.0, 1.0);
glVertex2f(-29.0, 3.0);
glEnd();
glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(-29.00f, 4.00f, 1.0f, 100);
drawCircle(-29.00f, 5.00f, 0.6f, 100);
glEnd();

//1ST MIDEUM 01
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(14.0, 1.0);
glVertex2f(14, 3.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(14.00f, 4.00f, 1.0f, 100);
drawCircle(14.0f, 5.00f, 0.6f, 100);
glEnd();
//1ST MIDEUM 02
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(16.0, 1.0);
glVertex2f(16.0, 3.0);
glEnd();

glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(16.00f, 4.00f, 1.0f, 100);
drawCircle(16.00f, 5.00f, 0.6f, 100);
glEnd();
//1ST MIDEUM 03
glColor3f(0.8, 0.3, 0.2);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(18.0, 1.0);
glVertex2f(18.0, 3.0);
glEnd();
glColor3f(0.13f, 0.55f, 0.13f);
drawCircle(18.00f, 4.00f, 1.0f, 100);
drawCircle(18.00f, 5.00f, 0.6f, 100);
glEnd();

//1ST BELOW 01
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(23.0, -21.5);
glVertex2f(23.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(23.00f, -17.5, 1.0f, 100);
drawCircle(23.00f, -16.5, 0.6f, 100);
glEnd();

//1ST BELOW 02
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(25.0, -21.5);
glVertex2f(25.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(25.00f, -17.5, 1.0f, 100);
drawCircle(25.00f, -16.5, 0.6f, 100);
glEnd();

//1ST BELOW 03
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(27.0, -21.5);
glVertex2f(27.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(27.00f, -17.5, 1.0f, 100);
drawCircle(27.00f, -16.5, 0.6f, 100);
glEnd();

//1ST LEFT BELOW 01
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-17.0, -21.5);
glVertex2f(-17.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-17.00f, -17.5, 1.0f, 100);
drawCircle(-17.00f, -16.5, 0.6f, 100);
glEnd();

//1ST LEFT BELOW 02
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-19.0, -21.5);
glVertex2f(-19.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-19.00f, -17.5, 1.0f, 100);
drawCircle(-19.00f, -16.5, 0.6f, 100);
glEnd();

//1ST LEFT BELOW 03
glColor3f(0.9, 0.5, 0.0);
glLineWidth(6.00);
glBegin(GL_LINES);
glVertex2f(-21.0, -21.5);
glVertex2f(-21.0, -18.5);
glEnd();
glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-21.00f, -17.5, 1.0f, 100);
drawCircle(-21.00f, -16.5, 0.6f, 100);
glEnd();

//1ST BELOW RIGHT TREE
glColor3f(0.9, 0.5, 0.0);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(34.20, -20.3 );
glVertex2f(34.20, -21.5 );
glEnd();

glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(34.20, -19.8f, 0.65f, 100);
drawCircle(34.20, -19.0, 0.45f, 100);
glEnd();

//2ND BELOW RIGHT TREE
glColor3f(0.9, 0.5, 0.0);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(32.50, -20.3 );
glVertex2f(32.50, -21.5 );
glEnd();

glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(32.50, -19.8f, 0.65f, 100);
drawCircle(32.50, -19.0, 0.45f, 100);
glEnd();

//1ST BELOW LEFT TREE
glColor3f(0.9, 0.5, 0.0);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(-30.20, -20.3 );
glVertex2f(-30.20, -21.5 );
glEnd();

glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-30.20, -19.8f, 0.65f, 100);
drawCircle(-30.20, -19.0, 0.45f, 100);
glEnd();

//2ND BELOW LEFT TREE
glColor3f(0.9, 0.5, 0.0);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(-28.50, -20.3 );
glVertex2f(-28.50, -21.5 );
glEnd();

glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-28.50, -19.8f, 0.65f, 100);
drawCircle(-28.50, -19.0, 0.45f, 100);
glEnd();

//3RD BELOW LEFT TREE
glColor3f(0.9, 0.5, 0.0);
glLineWidth(3.00);
glBegin(GL_LINES);
glVertex2f(-26.80, -20.3 );
glVertex2f(-26.80, -21.5 );
glEnd();

glColor3f(0.4f, 0.892f, 0.0f);
drawCircle(-26.80, -19.8f, 0.65f, 100);
drawCircle(-26.80, -19.0, 0.45f, 100);
glEnd();

 ///House
     //1ST HOUSE
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
     glVertex2f(32.60, 8.2);
    glVertex2f(33.70, 8.2);
    glVertex2f(33.90, 7.6);
    glVertex2f(32.40, 7.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
     glVertex2f(32.60, 7.6);
    glVertex2f(33.70, 7.6);
    glVertex2f(33.70, 6.5);
    glVertex2f(32.60, 6.5);
    glEnd();

    //LOWER PORTION
    glLineWidth(2.00);
    glBegin(GL_LINES);
glColor3f(0.8f, 0.52f, 0.25f);
    glVertex2f(33.80, 6.4);
    glVertex2f(32.50, 6.4);
    glEnd();

     //WINDOW
     glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.7);
        glVertex2f(33.40, 7.1);
        glVertex2f(32.90, 7.1);
        glVertex2f(32.90, 6.5);
        glVertex2f(33.40, 6.5);
    glEnd();

   //2ND HOUSE
      glBegin(GL_QUADS);
    glColor3f(1.0f, 0.2f, 0.2f);
     glVertex2f(28.40, 7.7);
    glVertex2f(29.50, 7.7);
    glVertex2f(29.70, 7.10);
    glVertex2f(28.20, 7.10);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
     glVertex2f(28.40, 7.10);
    glVertex2f(29.50, 7.10);
    glVertex2f(29.50, 6.0);
    glVertex2f(28.40, 6.0);
    glEnd();

    //LOWER PORTION
    glLineWidth(2.00);
    glBegin(GL_LINES);
glColor3f(0.8f, 0.52f, 0.25f);
    glVertex2f(29.70, 6.0);
    glVertex2f(28.20, 6.0);
    glEnd();

   //WINDOW
     glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.7);
        glVertex2f(29.20, 6.8);
        glVertex2f(28.80, 6.8);
        glVertex2f(28.80, 6.1);
        glVertex2f(29.20, 6.1);
    glEnd();

   //3RD HOUSE
   //UPPER BROWN
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(30.10, 8.00);
    glVertex2f(32.00, 8.00);
    glVertex2f(31.30, 7.00);
    glVertex2f(29.40, 7.00);
    glEnd();
   //LOWER gray
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(29.8, 7.00);
    glVertex2f(29.8, 6.20);
    glVertex2f(31.40, 5.6);
    glVertex2f(31.40, 7.00);
    glEnd();
//RIGHT TRIANGLE gray
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_TRIANGLES);
    glVertex2f(32.00, 8.00);
    glVertex2f(31.30, 7.00);
    glVertex2f(32.50, 7.0);
    glEnd();
//BELOW PART OF TRIANGLE
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(31.40, 7.00);
    glVertex2f(31.40, 5.6);
    glVertex2f(32.30, 6.30);
    glVertex2f(32.30, 7.0);

    glEnd();
    //LINE
    glLineWidth(0.00001);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.5, 0.2);
    glVertex2f(31.30, 5.6);
    glVertex2f(31.30, 7.00);
    glEnd();

//RIGHT BROWN
    glLineWidth(7.00);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex2f(32.00, 8.00);
    glVertex2f(32.50, 7.0);
        glEnd();
    //LOWER PORTION
    glLineWidth(2.00);
    glBegin(GL_LINES);
glColor3f(0.8f, 0.52f, 0.25f);
    glVertex2f(29.65, 6.10);
    glVertex2f(31.40, 5.50);
    glVertex2f(31.40, 5.50);
    glVertex2f(32.48, 6.20);
        glEnd();
    //LOWER WINDOW
    glColor3f(0.0, 0.5, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(31.62, 7.0);
    glVertex2f(32.10, 7.2);
    glVertex2f(32.10, 6.52);
    glVertex2f(31.62, 6.32);
    glEnd();

      //LOWER DOOR
    glColor3f(0.0, 0.5, 0.7);
    glBegin(GL_QUADS);
     glVertex2f(30.35, 6.0);
    glVertex2f(30.35, 6.54);
    glVertex2f(30.95, 6.54);
    glVertex2f(30.95, 5.75);
    glEnd();

//HOUSE BEHIND LINE
     glLineWidth(1.50);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(27.0, 3.00);
    glVertex2f(35.0, 3.0);
     glVertex2f(26.45, 2.00);
    glVertex2f(35.0, 2.0);
    glVertex2f(34.0, 4.00);
    glVertex2f(34.0, 1.0);
    glVertex2f(33.0, 4.00);
    glVertex2f(33.0, 1.0);
    glVertex2f(32.0, 4.00);
    glVertex2f(32.0, 1.0);
    glVertex2f(31.0, 4.00);
    glVertex2f(31.0, 1.0);
     glVertex2f(30.0, 4.00);
    glVertex2f(30.0, 1.0);
     glVertex2f(29.0, 4.00);
    glVertex2f(29.0, 1.0);
     glVertex2f(28.0, 4.00);
    glVertex2f(28.0, 1.0);
        glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(33.70, 4.00);
    glVertex2f(34.30, 4.0);
    glVertex2f(34.0, 4.60);
        glEnd();
        glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(32.70, 4.00);
    glVertex2f(33.30, 4.0);
    glVertex2f(33.0, 4.60);
        glEnd();
        glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(31.70, 4.00);
    glVertex2f(32.30, 4.0);
    glVertex2f(32.0, 4.60);
        glEnd();
        glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(30.70, 4.00);
    glVertex2f(31.30, 4.0);
    glVertex2f(31.0, 4.60);
        glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(29.70, 4.00);
    glVertex2f(30.30, 4.0);
    glVertex2f(30.0, 4.60);
        glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(28.70, 4.00);
    glVertex2f(29.30, 4.0);
    glVertex2f(29.0, 4.60);
        glEnd();
          glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(27.70, 4.00);
    glVertex2f(28.30, 4.0);
    glVertex2f(28.0, 4.60);
        glEnd();

///Human
//second human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(9.00f, 6.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.5, 0.1);
glBegin(GL_QUADS);
glVertex2f(9.45, 5.5);
glVertex2f(8.55, 5.50);
glVertex2f(8.55, 3.50);
glVertex2f(9.45, 3.50);
glEnd();

glColor3f(0.2, 0.2, 0.2);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(9.20, 3.50);
glVertex2f(9.20, 1.30);

glVertex2f(8.80, 3.50);
glVertex2f(8.80, 1.30);
glEnd();
//third human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(8.00f, 6.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.5, 0.1);
glBegin(GL_QUADS);
glVertex2f(8.45, 5.5);
glVertex2f(7.55, 5.50);
glVertex2f(7.55, 3.50);
glVertex2f(8.45, 3.50);
glEnd();

glColor3f(0.2, 0.2, 0.2);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(8.20, 3.50);
glVertex2f(8.20, 1.30);

glVertex2f(7.80, 3.50);
glVertex2f(7.80, 1.30);
glEnd();

//forth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-24.00f, 6.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.5, 0.1);
glBegin(GL_QUADS);
glVertex2f(-24.45, 5.5);
glVertex2f(-23.55, 5.50);
glVertex2f(-23.55, 3.50);
glVertex2f(-24.45, 3.50);
glEnd();

glColor3f(0.2, 0.2, 0.2);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(-24.20, 3.50);
glVertex2f(-24.20, 1.30);

glVertex2f(-23.80, 3.50);
glVertex2f(-23.80, 1.30);
glEnd();
//fifth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-23.00f, 6.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.5, 0.1);
glBegin(GL_QUADS);
glVertex2f(-23.45, 5.5);
glVertex2f(-22.55, 5.50);
glVertex2f(-22.55, 3.50);
glVertex2f(-23.45, 3.50);
glEnd();

glColor3f(0.2, 0.2, 0.2);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(-23.20, 3.50);
glVertex2f(-23.20, 1.30);

glVertex2f(-22.80, 3.50);
glVertex2f(-22.80, 1.30);
glEnd();

    ///Lamp
    //1st
    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-15.0, -21.50);
    glVertex2f(-15.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-15.0, -15.00);
    glVertex2f(-15.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(-15.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(-15.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(-15.0f,-11.50f, 0.35f, 100);
    glEnd();

      if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-15.0f, -12.50f, 0.35f, 100);


        glEnd();
    } else {
        glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(-15.0f,-11.50f, 0.35f, 100);
        glEnd();
    }

    //2nd
     glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -21.50);
    glVertex2f(21.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -15.00);
    glVertex2f(21.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(21.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(21.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();

         if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(21.0f, -12.50f, 0.35f, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();
    }

     //3rd
    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-26.0, 1.00);
    glVertex2f(-26.0, 7.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-26.0, 7.00);
    glVertex2f(-26.0, 12.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(-26.0f, 8.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(-26.0f,9.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(-26.0f,10.50f, 0.35f, 100);
    glEnd();

      if (isLeftPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-26.0f, 9.50f, 0.35f, 100);


        glEnd();
    } else {
        glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(-26.0f,10.50f, 0.35f, 100);
        glEnd();
    }
   //4th
      glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(12.0, 1.00);
    glVertex2f(12.0, 7.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(12.0, 7.00);
    glVertex2f(12.0, 12.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(12.0f, 8.50f, 0.35, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(12.0f,9.50f, 0.35, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(12.0f,10.50f, 0.35, 100);
    glEnd();

         if (isLeftPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(12.0f, 9.50f, 0.35, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(12.0f,10.50f, 0.35, 100);
    glEnd();
    }


glutSwapBuffers();
 }




 ///display function for collegeLife
 void collegeLife() {
    glClear(GL_COLOR_BUFFER_BIT);

 /// Sky
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.75f, 1.0f);
    glVertex2f(-35.0, 35.0);
    glVertex2f(35.0, 35.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///Sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(9.00f, 27.00f, 1.0f, 100);
    glEnd();
    ///cloud and bird
    drawCloudAndBird();
    ///green middle ground
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.9f, 0.4f);
    glVertex2f(-35.0, 0.0);
    glVertex2f(-10.0, 0.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(-15.0, -20.0);
    glVertex2f(-35.0, -20.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.6f, 0.9f, 0.4f);
    glVertex2f(35.0, 0.0);
    glVertex2f(10.0, 0.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(15.0, -20.0);
    glVertex2f(35.0, -20.0);
    glEnd();

    ///basket ball ground
     glBegin(GL_QUADS);
    glColor3f(0.7f, 0.9f, 0.4f);
    glVertex2f(-35.0, -2.0);
    glVertex2f(35.0, -2.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -14.0);
    glVertex2f(-35.0, -14.0);
    glEnd();

     ///busket
    glColor3f(0.8f, 0.9f, 0.6f);
      drawCircle(-35.0, -8.0, 4.0, 100);
      drawCircle(-14.0, -8.0, 4.0, 100);
      drawCircle(-24.3, -8.0, 0.8, 100);
      drawCircle(35.0, -8.0, 4.0, 100);
      drawCircle(14.0, -8.0, 4.0, 100);
      drawCircle(24.3, -8.0, 0.8, 100);
        glColor3f(0.6f, 0.9f, 0.3f);
     drawCircle(-35.0, -8.0, 3.0, 100);
      drawCircle(-14.0, -8.0, 3.0, 100);
       drawCircle(35.0, -8.0, 3.0, 100);
      drawCircle(14.0, -8.0, 3.0, 100);

    glEnd();

    //busket line
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-31.0, -8.0);
    glVertex2f(-18.0, -8.0);
    glVertex2f(-17.50, -2.0);
     glVertex2f(-19.80, -14.0);
     glVertex2f(-28.0, -2.0);
     glVertex2f(-31.0, -14.0);
     glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(31.0, -8.0);
    glVertex2f(18.0, -8.0);
    glVertex2f(17.50, -2.0);
     glVertex2f(19.80, -14.0);
     glVertex2f(28.0, -2.0);
     glVertex2f(31.0, -14.0);
    glEnd();

    ///MIDDLE
     glBegin(GL_QUADS);
    glColor3f(0.4f, 0.9f, 0.3f);
    glVertex2f(-10.0, 0.0);
    glVertex2f(-15.0, -20.0);
    glVertex2f(15.0, -20.0);
    glVertex2f(10.0, 0.0);
    glEnd();

    ///Road
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.55f, 0.55f);
    glVertex2f(-35.0, -20.0);
    glVertex2f(35.0, -20.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(35.0, -35.0);
    glVertex2f(-35.0, -35.0);
    glEnd();
    ///ROAD LINE
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    //Road
    glVertex2f(-35.0, -21.0);
    glVertex2f(35.0, -21.0);
    glEnd();

    ///yellow
    glLineWidth(4.0);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-37.0f, -30.5f);
    glVertex2f(-33.0f, -30.5f);
    glVertex2f(-30.0f, -30.5f);
    glVertex2f(-27.0f, -30.5f);
    glVertex2f(-24.0f, -30.5f);
    glVertex2f(-21.0f, -30.5f);
    glVertex2f(-18.0f, -30.5f);
    glVertex2f(-15.0f, -30.5f);
    glVertex2f(-12.0f, -30.5f);
    glVertex2f(-9.0f, -30.5f);
    glVertex2f(-6.0f, -30.5f);
    glVertex2f(-3.0f, -30.5f);
    glVertex2f(0.0f, -30.5f);
    glVertex2f(3.0f, -30.5f);
    glVertex2f(6.0f, -30.5f);
    glVertex2f(9.0f, -30.5f);
    glVertex2f(12.0f, -30.5f);
    glVertex2f(15.0f, -30.5f);
    glVertex2f(18.0f, -30.5f);
    glVertex2f(21.0f, -30.5f);
    glVertex2f(24.0f, -30.5f);
    glVertex2f(27.0f, -30.5f);
    glVertex2f(30.0f, -30.5f);
    glVertex2f(33.0f, -30.5f);
    glVertex2f(36.0f, -30.5f);
    glVertex2f(39.0f, -30.5f);

   ///arrow
     glColor3f(0.9f, 0.9f, 0.9f);
     glVertex2f(-20.00f, -24.0f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -24.5f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -23.5f);
     glVertex2f(-18.0f, -24.0f);

     glVertex2f(15.0f, -24.0f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -24.5f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -23.5f);
     glVertex2f(17.0f, -24.0f);
    glEnd();

    ///turbine
    glColor3f(0.7, 0.5, 0.4);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-20.0, 24.0);
    glVertex2f(-20.0, 0.0);
    glVertex2f(20.0, 24.0);
    glVertex2f(20.0, 0.0);
    glVertex2f(-28.0, 22.0);
    glVertex2f(-28.0, 0.0);
    glVertex2f(28.0, 22.0);
    glVertex2f(28.0, 0.0);
    glEnd();

    ///building

   //C_BLOCK
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.3f);
    glVertex2f(-33.0, 0.0);
    glVertex2f(-33.0, 16.0);
    glVertex2f(-30.0, 16.0);
    glVertex2f(-30.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.3f);
    glVertex2f(-33.0, 0.0);
    glVertex2f(-33.0, 15.0);
    glVertex2f(-34.0, 15.0);
    glVertex2f(-34.0, 0.0);
    glEnd();
    //ABC HOSPITAL
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.7f, 0.3f);
    glVertex2f(-30.0, 0.0);
    glVertex2f(-30.0, 18.0);
    glVertex2f(-24.0, 18.0);
    glVertex2f(-24.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.7f, 0.3f);
    glVertex2f(-24.0, 0.0);
    glVertex2f(-24.0, 17.0);
    glVertex2f(-23.0, 17.0);
    glVertex2f(-23.0, 0.0);
    glEnd();
//LIBRARY
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 1.0f);
    glVertex2f(-22.0, 0.0);
    glVertex2f(-22.0, 20.0);
    glVertex2f(-18.0, 20.0);
    glVertex2f(-18.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 1.0f);
    glVertex2f(-20.0, 0.0);
    glVertex2f(-20.0, 18.0);
    glVertex2f(-16.0, 18.0);
    glVertex2f(-16.0, 0.0);
    glEnd();
    //HOSTEL
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-16.0, 0.0);
    glVertex2f(-16.0, 16.0);
    glVertex2f(-13.0, 16.0);
    glVertex2f(-13.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-13.0, 0.0);
    glVertex2f(-13.0, 15.0);
    glVertex2f(-12.0, 15.0);
    glVertex2f(-12.0, 0.0);
    glEnd();

    //right building
    ///D BLOCK
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.3f);
    glVertex2f(33.0, 0.0);
    glVertex2f(33.0, 16.0);
    glVertex2f(30.0, 16.0);
    glVertex2f(30.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.3f);
    glVertex2f(33.0, 0.0);
    glVertex2f(33.0, 15.0);
    glVertex2f(34.0, 15.0);
    glVertex2f(34.0, 0.0);
    glEnd();
    //SHOPPING MALL
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.3f, 0.6f);
    glVertex2f(30.0, 0.0);
    glVertex2f(30.0, 18.0);
    glVertex2f(24.0, 18.0);
    glVertex2f(24.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.3f, 0.6f);
    glVertex2f(24.0, 0.0);
    glVertex2f(24.0, 17.0);
    glVertex2f(23.0, 17.0);
    glVertex2f(23.0, 0.0);
    glEnd();
//ACADEMY
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(22.0, 0.0);
    glVertex2f(22.0, 20.0);
    glVertex2f(18.0, 20.0);
    glVertex2f(18.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(20.0, 0.0);
    glVertex2f(20.0, 18.0);
    glVertex2f(16.0, 18.0);
    glVertex2f(16.0, 0.0);
    glEnd();
    //BD BANK
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(16.0, 0.0);
    glVertex2f(16.0, 16.0);
    glVertex2f(13.0, 16.0);
    glVertex2f(13.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(13.0, 0.0);
    glVertex2f(13.0, 15.0);
    glVertex2f(12.0, 15.0);
    glVertex2f(12.0, 0.0);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINES);
    //yellow
    glColor3f(0.9, 0.92f, 0.7);
    glVertex2f(-33.0f, 13.0f);
    glVertex2f(-33.0f, 12.0f);
    glVertex2f(-32.0f, 13.0f);
    glVertex2f(-32.0f, 12.0f);
    glVertex2f(-31.0f, 13.0f);
    glVertex2f(-31.0f, 12.0f);
    glVertex2f(-33.0f, 11.0f);
    glVertex2f(-33.0f, 10.0f);
    glVertex2f(-32.0f, 11.0f);
    glVertex2f(-32.0f, 10.0f);
    glVertex2f(-31.0f, 11.0f);
    glVertex2f(-31.0f, 10.0f);
    glVertex2f(-33.0f, 9.0f);
    glVertex2f(-33.0f, 8.0f);
    glVertex2f(-32.0f, 9.0f);
    glVertex2f(-32.0f, 8.0f);
    glVertex2f(-31.0f, 9.0f);
    glVertex2f(-31.0f, 8.0f);
    glVertex2f(-33.0f, 7.0f);
    glVertex2f(-33.0f, 6.0f);
    glVertex2f(-32.0f, 7.0f);
    glVertex2f(-32.0f, 6.0f);
    glVertex2f(-31.0f, 7.0f);
    glVertex2f(-31.0f, 6.0f);
    glVertex2f(-33.0f, 5.0f);
    glVertex2f(-33.0f, 4.0f);
    glVertex2f(-32.0f, 5.0f);
    glVertex2f(-32.0f, 4.0f);
    glVertex2f(-31.0f, 5.0f);
    glVertex2f(-31.0f, 4.0f);
    glVertex2f(-33.0f, 3.0f);
    glVertex2f(-33.0f, 2.0f);
    glVertex2f(-32.0f, 3.0f);
    glVertex2f(-32.0f, 2.0f);
    glVertex2f(-31.0f, 3.0f);
    glVertex2f(-31.0f, 2.0f);

    glVertex2f(-29.0f, 15.0f);
    glVertex2f(-29.0f, 14.0f);
    glVertex2f(-28.0f, 15.0f);
    glVertex2f(-28.0f, 14.0f);
    glVertex2f(-27.0f, 15.0f);
    glVertex2f(-27.0f, 14.0f);
    glVertex2f(-26.0f, 15.0f);
    glVertex2f(-26.0f, 14.0f);
    glVertex2f(-25.0f, 15.0f);
    glVertex2f(-25.0f, 14.0f);
    glVertex2f(-24.0f, 15.0f);
    glVertex2f(-24.0f, 14.0f);
    glVertex2f(-29.0f, 13.0f);
    glVertex2f(-29.0f, 12.0f);
    glVertex2f(-28.0f, 13.0f);
    glVertex2f(-28.0f, 12.0f);
    glVertex2f(-27.0f, 13.0f);
    glVertex2f(-27.0f, 12.0f);
    glVertex2f(-26.0f, 13.0f);
    glVertex2f(-26.0f, 12.0f);
    glVertex2f(-25.0f, 13.0f);
    glVertex2f(-25.0f, 12.0f);
    glVertex2f(-24.0f, 13.0f);
    glVertex2f(-24.0f, 12.0f);
    glVertex2f(-29.0f, 11.0f);
    glVertex2f(-29.0f, 10.0f);
    glVertex2f(-28.0f, 11.0f);
    glVertex2f(-28.0f, 10.0f);
    glVertex2f(-27.0f, 11.0f);
    glVertex2f(-27.0f, 10.0f);
    glVertex2f(-26.0f, 11.0f);
    glVertex2f(-26.0f, 10.0f);
    glVertex2f(-25.0f, 11.0f);
    glVertex2f(-25.0f, 10.0f);
    glVertex2f(-24.0f, 11.0f);
    glVertex2f(-24.0f, 10.0f);
    glVertex2f(-29.0f, 9.0f);
    glVertex2f(-29.0f, 8.0f);
    glVertex2f(-28.0f, 9.0f);
    glVertex2f(-28.0f, 8.0f);
    glVertex2f(-27.0f, 9.0f);
    glVertex2f(-27.0f, 8.0f);
    glVertex2f(-26.0f, 9.0f);
    glVertex2f(-26.0f, 8.0f);
    glVertex2f(-25.0f, 9.0f);
    glVertex2f(-25.0f, 8.0f);
    glVertex2f(-24.0f, 9.0f);
    glVertex2f(-24.0f, 8.0f);
    glVertex2f(-29.0f, 7.0f);
    glVertex2f(-29.0f, 6.0f);
    glVertex2f(-28.0f, 7.0f);
    glVertex2f(-28.0f, 6.0f);
    glVertex2f(-27.0f, 7.0f);
    glVertex2f(-27.0f, 6.0f);
    glVertex2f(-26.0f, 7.0f);
    glVertex2f(-26.0f, 6.0f);
    glVertex2f(-25.0f, 7.0f);
    glVertex2f(-25.0f, 6.0f);
    glVertex2f(-24.0f, 7.0f);
    glVertex2f(-24.0f, 6.0f);
    glVertex2f(-29.0f, 5.0f);
    glVertex2f(-29.0f, 4.0f);
    glVertex2f(-28.0f, 5.0f);
    glVertex2f(-28.0f, 4.0f);
    glVertex2f(-27.0f, 5.0f);
    glVertex2f(-27.0f, 4.0f);
    glVertex2f(-26.0f, 5.0f);
    glVertex2f(-26.0f, 4.0f);
    glVertex2f(-25.0f, 5.0f);
    glVertex2f(-25.0f, 4.0f);
    glVertex2f(-24.0f, 5.0f);
    glVertex2f(-24.0f, 4.0f);
    glVertex2f(-29.0f, 3.0f);
    glVertex2f(-29.0f, 2.0f);
    glVertex2f(-28.0f, 3.0f);
    glVertex2f(-28.0f, 2.0f);
    glVertex2f(-27.0f, 3.0f);
    glVertex2f(-27.0f, 2.0f);
    glVertex2f(-26.0f, 3.0f);
    glVertex2f(-26.0f, 2.0f);
    glVertex2f(-25.0f, 3.0f);
    glVertex2f(-25.0f, 2.0f);
    glVertex2f(-24.0f, 3.0f);
    glVertex2f(-24.0f, 2.0f);

     glVertex2f(-21.0f, 16.0f);
    glVertex2f(-21.0f, 15.0f);
    glVertex2f(-20.0f, 16.0f);
    glVertex2f(-20.0f, 15.0f);
    glVertex2f(-19.0f, 16.0f);
    glVertex2f(-19.0f, 15.0f);
    glVertex2f(-18.0f, 16.0f);
    glVertex2f(-18.0f, 15.0f);
    glVertex2f(-17.0f, 16.0f);
    glVertex2f(-17.0f, 15.0f);
     glVertex2f(-21.0f, 14.0f);
    glVertex2f(-21.0f, 13.0f);
    glVertex2f(-20.0f, 14.0f);
    glVertex2f(-20.0f, 13.0f);
    glVertex2f(-19.0f, 14.0f);
    glVertex2f(-19.0f, 13.0f);
    glVertex2f(-18.0f, 14.0f);
    glVertex2f(-18.0f, 13.0f);
    glVertex2f(-17.0f, 14.0f);
    glVertex2f(-17.0f, 13.0f);
     glVertex2f(-21.0f, 12.0f);
    glVertex2f(-21.0f, 11.0f);
    glVertex2f(-20.0f, 12.0f);
    glVertex2f(-20.0f, 11.0f);
    glVertex2f(-19.0f, 12.0f);
    glVertex2f(-19.0f, 11.0f);
    glVertex2f(-18.0f, 12.0f);
    glVertex2f(-18.0f, 11.0f);
    glVertex2f(-17.0f, 12.0f);
    glVertex2f(-17.0f, 11.0f);
     glVertex2f(-21.0f, 10.0f);
    glVertex2f(-21.0f, 9.0f);
    glVertex2f(-20.0f, 10.0f);
    glVertex2f(-20.0f, 9.0f);
    glVertex2f(-19.0f, 10.0f);
    glVertex2f(-19.0f, 9.0f);
    glVertex2f(-18.0f, 10.0f);
    glVertex2f(-18.0f, 9.0f);
    glVertex2f(-17.0f, 10.0f);
    glVertex2f(-17.0f, 9.0f);
     glVertex2f(-21.0f, 8.0f);
    glVertex2f(-21.0f, 7.0f);
    glVertex2f(-20.0f, 8.0f);
    glVertex2f(-20.0f, 7.0f);
    glVertex2f(-19.0f, 8.0f);
    glVertex2f(-19.0f, 7.0f);
    glVertex2f(-18.0f, 8.0f);
    glVertex2f(-18.0f, 7.0f);
    glVertex2f(-17.0f, 8.0f);
    glVertex2f(-17.0f, 7.0f);
     glVertex2f(-21.0f, 6.0f);
    glVertex2f(-21.0f, 5.0f);
    glVertex2f(-20.0f, 6.0f);
    glVertex2f(-20.0f, 5.0f);
    glVertex2f(-19.0f, 6.0f);
    glVertex2f(-19.0f, 5.0f);
    glVertex2f(-18.0f, 6.0f);
    glVertex2f(-18.0f, 5.0f);
    glVertex2f(-17.0f, 6.0f);
    glVertex2f(-17.0f, 5.0f);
     glVertex2f(-21.0f, 4.0f);
    glVertex2f(-21.0f, 3.0f);
    glVertex2f(-20.0f, 4.0f);
    glVertex2f(-20.0f, 3.0f);
    glVertex2f(-19.0f, 4.0f);
    glVertex2f(-19.0f, 3.0f);
    glVertex2f(-18.0f, 4.0f);
    glVertex2f(-18.0f, 3.0f);
    glVertex2f(-17.0f, 4.0f);
    glVertex2f(-17.0f, 3.0f);
     glVertex2f(-21.0f, 2.0f);
    glVertex2f(-21.0f, 1.0f);
    glVertex2f(-20.0f, 2.0f);
    glVertex2f(-20.0f, 1.0f);
    glVertex2f(-19.0f, 2.0f);
    glVertex2f(-19.0f, 1.0f);
    glVertex2f(-18.0f, 2.0f);
    glVertex2f(-18.0f, 1.0f);
    glVertex2f(-17.0f, 2.0f);
    glVertex2f(-17.0f, 1.0f);

    glVertex2f(-15.0f, 13.0f);
    glVertex2f(-15.0f, 12.0f);
    glVertex2f(-14.0f, 13.0f);
    glVertex2f(-14.0f, 12.0f);
    glVertex2f(-13.0f, 13.0f);
    glVertex2f(-13.0f, 12.0f);
    glVertex2f(-15.0f, 11.0f);
    glVertex2f(-15.0f, 10.0f);
    glVertex2f(-14.0f, 11.0f);
    glVertex2f(-14.0f, 10.0f);
    glVertex2f(-13.0f, 11.0f);
    glVertex2f(-13.0f, 10.0f);
    glVertex2f(-15.0f, 9.0f);
    glVertex2f(-15.0f, 8.0f);
    glVertex2f(-14.0f, 9.0f);
    glVertex2f(-14.0f, 8.0f);
    glVertex2f(-13.0f, 9.0f);
    glVertex2f(-13.0f, 8.0f);
    glVertex2f(-15.0f, 7.0f);
    glVertex2f(-15.0f, 6.0f);
    glVertex2f(-14.0f, 7.0f);
    glVertex2f(-14.0f, 6.0f);
    glVertex2f(-13.0f, 7.0f);
    glVertex2f(-13.0f, 6.0f);
    glVertex2f(-15.0f, 5.0f);
    glVertex2f(-15.0f, 4.0f);
    glVertex2f(-14.0f, 5.0f);
    glVertex2f(-14.0f, 4.0f);
    glVertex2f(-13.0f, 5.0f);
    glVertex2f(-13.0f, 4.0f);
    glVertex2f(-15.0f, 3.0f);
    glVertex2f(-15.0f, 2.0f);
    glVertex2f(-14.0f, 3.0f);
    glVertex2f(-14.0f, 2.0f);
    glVertex2f(-13.0f, 3.0f);
    glVertex2f(-13.0f, 2.0f);

    //right
    glVertex2f(33.0f, 13.0f);
    glVertex2f(33.0f, 12.0f);
    glVertex2f(32.0f, 13.0f);
    glVertex2f(32.0f, 12.0f);
    glVertex2f(31.0f, 13.0f);
    glVertex2f(31.0f, 12.0f);
    glVertex2f(33.0f, 11.0f);
    glVertex2f(33.0f, 10.0f);
    glVertex2f(32.0f, 11.0f);
    glVertex2f(32.0f, 10.0f);
    glVertex2f(31.0f, 11.0f);
    glVertex2f(31.0f, 10.0f);
    glVertex2f(33.0f, 9.0f);
    glVertex2f(33.0f, 8.0f);
    glVertex2f(32.0f, 9.0f);
    glVertex2f(32.0f, 8.0f);
    glVertex2f(31.0f, 9.0f);
    glVertex2f(31.0f, 8.0f);
    glVertex2f(33.0f, 7.0f);
    glVertex2f(33.0f, 6.0f);
    glVertex2f(32.0f, 7.0f);
    glVertex2f(32.0f, 6.0f);
    glVertex2f(31.0f, 7.0f);
    glVertex2f(31.0f, 6.0f);
    glVertex2f(33.0f, 5.0f);
    glVertex2f(33.0f, 4.0f);
    glVertex2f(32.0f, 5.0f);
    glVertex2f(32.0f, 4.0f);
    glVertex2f(31.0f, 5.0f);
    glVertex2f(31.0f, 4.0f);
    glVertex2f(33.0f, 3.0f);
    glVertex2f(33.0f, 2.0f);
    glVertex2f(32.0f, 3.0f);
    glVertex2f(32.0f, 2.0f);
    glVertex2f(31.0f, 3.0f);
    glVertex2f(31.0f, 2.0f);


     glVertex2f(29.0f, 15.0f);
    glVertex2f(29.0f, 14.0f);
    glVertex2f(28.0f, 15.0f);
    glVertex2f(28.0f, 14.0f);
    glVertex2f(27.0f, 15.0f);
    glVertex2f(27.0f, 14.0f);
    glVertex2f(26.0f, 15.0f);
    glVertex2f(26.0f, 14.0f);
    glVertex2f(25.0f, 15.0f);
    glVertex2f(25.0f, 14.0f);
    glVertex2f(24.0f, 15.0f);
    glVertex2f(24.0f, 14.0f);
    glVertex2f(29.0f, 13.0f);
    glVertex2f(29.0f, 12.0f);
    glVertex2f(28.0f, 13.0f);
    glVertex2f(28.0f, 12.0f);
    glVertex2f(27.0f, 13.0f);
    glVertex2f(27.0f, 12.0f);
    glVertex2f(26.0f, 13.0f);
    glVertex2f(26.0f, 12.0f);
    glVertex2f(25.0f, 13.0f);
    glVertex2f(25.0f, 12.0f);
    glVertex2f(24.0f, 13.0f);
    glVertex2f(24.0f, 12.0f);
    glVertex2f(29.0f, 11.0f);
    glVertex2f(29.0f, 10.0f);
    glVertex2f(28.0f, 11.0f);
    glVertex2f(28.0f, 10.0f);
    glVertex2f(27.0f, 11.0f);
    glVertex2f(27.0f, 10.0f);
    glVertex2f(26.0f, 11.0f);
    glVertex2f(26.0f, 10.0f);
    glVertex2f(25.0f, 11.0f);
    glVertex2f(25.0f, 10.0f);
    glVertex2f(24.0f, 11.0f);
    glVertex2f(24.0f, 10.0f);
    glVertex2f(29.0f, 9.0f);
    glVertex2f(29.0f, 8.0f);
    glVertex2f(28.0f, 9.0f);
    glVertex2f(28.0f, 8.0f);
    glVertex2f(27.0f, 9.0f);
    glVertex2f(27.0f, 8.0f);
    glVertex2f(26.0f, 9.0f);
    glVertex2f(26.0f, 8.0f);
    glVertex2f(25.0f, 9.0f);
    glVertex2f(25.0f, 8.0f);
    glVertex2f(24.0f, 9.0f);
    glVertex2f(24.0f, 8.0f);
    glVertex2f(29.0f, 7.0f);
    glVertex2f(29.0f, 6.0f);
    glVertex2f(28.0f, 7.0f);
    glVertex2f(28.0f, 6.0f);
    glVertex2f(27.0f, 7.0f);
    glVertex2f(27.0f, 6.0f);
    glVertex2f(26.0f, 7.0f);
    glVertex2f(26.0f, 6.0f);
    glVertex2f(25.0f, 7.0f);
    glVertex2f(25.0f, 6.0f);
    glVertex2f(24.0f, 7.0f);
    glVertex2f(24.0f, 6.0f);
    glVertex2f(29.0f, 5.0f);
    glVertex2f(29.0f, 4.0f);
    glVertex2f(28.0f, 5.0f);
    glVertex2f(28.0f, 4.0f);
    glVertex2f(27.0f, 5.0f);
    glVertex2f(27.0f, 4.0f);
    glVertex2f(26.0f, 5.0f);
    glVertex2f(26.0f, 4.0f);
    glVertex2f(25.0f, 5.0f);
    glVertex2f(25.0f, 4.0f);
    glVertex2f(24.0f, 5.0f);
    glVertex2f(24.0f, 4.0f);
    glVertex2f(29.0f, 3.0f);
    glVertex2f(29.0f, 2.0f);
    glVertex2f(28.0f, 3.0f);
    glVertex2f(28.0f, 2.0f);
    glVertex2f(27.0f, 3.0f);
    glVertex2f(27.0f, 2.0f);
    glVertex2f(26.0f, 3.0f);
    glVertex2f(26.0f, 2.0f);
    glVertex2f(25.0f, 3.0f);
    glVertex2f(25.0f, 2.0f);
    glVertex2f(24.0f, 3.0f);
    glVertex2f(24.0f, 2.0f);

    glVertex2f(21.0f, 16.0f);
    glVertex2f(21.0f, 15.0f);
    glVertex2f(20.0f, 16.0f);
    glVertex2f(20.0f, 15.0f);
    glVertex2f(19.0f, 16.0f);
    glVertex2f(19.0f, 15.0f);
    glVertex2f(18.0f, 16.0f);
    glVertex2f(18.0f, 15.0f);
    glVertex2f(17.0f, 16.0f);
    glVertex2f(17.0f, 15.0f);
     glVertex2f(21.0f, 14.0f);
    glVertex2f(21.0f, 13.0f);
    glVertex2f(20.0f, 14.0f);
    glVertex2f(20.0f, 13.0f);
    glVertex2f(19.0f, 14.0f);
    glVertex2f(19.0f, 13.0f);
    glVertex2f(18.0f, 14.0f);
    glVertex2f(18.0f, 13.0f);
    glVertex2f(17.0f, 14.0f);
    glVertex2f(17.0f, 13.0f);
     glVertex2f(21.0f, 12.0f);
    glVertex2f(21.0f, 11.0f);
    glVertex2f(20.0f, 12.0f);
    glVertex2f(20.0f, 11.0f);
    glVertex2f(19.0f, 12.0f);
    glVertex2f(19.0f, 11.0f);
    glVertex2f(18.0f, 12.0f);
    glVertex2f(18.0f, 11.0f);
    glVertex2f(17.0f, 12.0f);
    glVertex2f(17.0f, 11.0f);
     glVertex2f(21.0f, 10.0f);
    glVertex2f(21.0f, 9.0f);
    glVertex2f(20.0f, 10.0f);
    glVertex2f(20.0f, 9.0f);
    glVertex2f(19.0f, 10.0f);
    glVertex2f(19.0f, 9.0f);
    glVertex2f(18.0f, 10.0f);
    glVertex2f(18.0f, 9.0f);
    glVertex2f(17.0f, 10.0f);
    glVertex2f(17.0f, 9.0f);
     glVertex2f(21.0f, 8.0f);
    glVertex2f(21.0f, 7.0f);
    glVertex2f(20.0f, 8.0f);
    glVertex2f(20.0f, 7.0f);
    glVertex2f(19.0f, 8.0f);
    glVertex2f(19.0f, 7.0f);
    glVertex2f(18.0f, 8.0f);
    glVertex2f(18.0f, 7.0f);
    glVertex2f(17.0f, 8.0f);
    glVertex2f(17.0f, 7.0f);
     glVertex2f(21.0f, 6.0f);
    glVertex2f(21.0f, 5.0f);
    glVertex2f(20.0f, 6.0f);
    glVertex2f(20.0f, 5.0f);
    glVertex2f(19.0f, 6.0f);
    glVertex2f(19.0f, 5.0f);
    glVertex2f(18.0f, 6.0f);
    glVertex2f(18.0f, 5.0f);
    glVertex2f(17.0f, 6.0f);
    glVertex2f(17.0f, 5.0f);
     glVertex2f(21.0f, 4.0f);
    glVertex2f(21.0f, 3.0f);
    glVertex2f(20.0f, 4.0f);
    glVertex2f(20.0f, 3.0f);
    glVertex2f(19.0f, 4.0f);
    glVertex2f(19.0f, 3.0f);
    glVertex2f(18.0f, 4.0f);
    glVertex2f(18.0f, 3.0f);
    glVertex2f(17.0f, 4.0f);
    glVertex2f(17.0f, 3.0f);
     glVertex2f(21.0f, 2.0f);
    glVertex2f(21.0f, 1.0f);
    glVertex2f(20.0f, 2.0f);
    glVertex2f(20.0f, 1.0f);
    glVertex2f(19.0f, 2.0f);
    glVertex2f(19.0f, 1.0f);
    glVertex2f(18.0f, 2.0f);
    glVertex2f(18.0f, 1.0f);
    glVertex2f(17.0f, 2.0f);
    glVertex2f(17.0f, 1.0f);


    glVertex2f(15.0f, 13.0f);
    glVertex2f(15.0f, 12.0f);
    glVertex2f(14.0f, 13.0f);
    glVertex2f(14.0f, 12.0f);
    glVertex2f(13.0f, 13.0f);
    glVertex2f(13.0f, 12.0f);
    glVertex2f(15.0f, 11.0f);
    glVertex2f(15.0f, 10.0f);
    glVertex2f(14.0f, 11.0f);
    glVertex2f(14.0f, 10.0f);
    glVertex2f(13.0f, 11.0f);
    glVertex2f(13.0f, 10.0f);
    glVertex2f(15.0f, 9.0f);
    glVertex2f(15.0f, 8.0f);
    glVertex2f(14.0f, 9.0f);
    glVertex2f(14.0f, 8.0f);
    glVertex2f(13.0f, 9.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(15.0f, 7.0f);
    glVertex2f(15.0f, 6.0f);
    glVertex2f(14.0f, 7.0f);
    glVertex2f(14.0f, 6.0f);
    glVertex2f(13.0f, 7.0f);
    glVertex2f(13.0f, 6.0f);
    glVertex2f(15.0f, 5.0f);
    glVertex2f(15.0f, 4.0f);
    glVertex2f(14.0f, 5.0f);
    glVertex2f(14.0f, 4.0f);
    glVertex2f(13.0f, 5.0f);
    glVertex2f(13.0f, 4.0f);
    glVertex2f(15.0f, 3.0f);
    glVertex2f(15.0f, 2.0f);
    glVertex2f(14.0f, 3.0f);
    glVertex2f(14.0f, 2.0f);
    glVertex2f(13.0f, 3.0f);
    glVertex2f(13.0f, 2.0f);

    glEnd();

///human
 glPushMatrix();
    glTranslatef(moveM3,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-28.00f, -1.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-28.45, -1.5);
glVertex2f(-27.55, -1.50);
glVertex2f(-27.55, -3.50);
glVertex2f(-28.45, -3.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(6.50);
glBegin(GL_LINES);
glVertex2f(-28.20, -3.50);
glVertex2f(-28.20, -5.30);

glVertex2f(-27.80, -3.50);
glVertex2f(-27.80, -5.30);
glEnd();
 glColor3f(0.9f, 0.5f, 0.2f);
drawCircle(-27.0, -4.50, 0.5, 100);
glLineWidth(0.01);
glBegin(GL_LINES);
glColor3f(0.9f, 0.9f, 0.7f);
glVertex2f(-27.50, -4.50);
glVertex2f(-26.50, -4.50);
glVertex2f(-27.0, -4.00);
glVertex2f(-27.0, -5.00);
glEnd();
glPopMatrix();
glPopMatrix();

//second human
 glPushMatrix();
    glTranslatef(moveM4,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-19.00f, -5.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-19.45, -5.5);
glVertex2f(-18.55, -5.50);
glVertex2f(-18.55, -7.50);
glVertex2f(-19.45, -7.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(-19.20, -7.50);
glVertex2f(-19.20, -9.30);

glVertex2f(-18.80, -7.50);
glVertex2f(-18.80, -9.30);
glEnd();
glPopMatrix();
glPopMatrix();

    ///COLLEGE
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-14.0, 8.0);
    glVertex2f( 14.0, 8.0);
    glVertex2f(15.5, 4.0);
    glVertex2f(-15.5, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.27f, 0.2f);
    glVertex2f(-14.8, 4.0);
    glVertex2f( 14.8, 4.0);
    glVertex2f(14.8, -6.0);
    glVertex2f(-14.8, -6.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    //yellow
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f( -14.8, -0.5);
    glVertex2f(14.8, -0.5);
        glEnd();

     glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2f(-11.0, 10.0);
    glVertex2f( 11.0, 10.0);
    glVertex2f(12.5, 6.0);
    glVertex2f(-12.5, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.99f, 0.57f, 0.4f);
    glVertex2f(-11.8, 6.0);
    glVertex2f( 11.8, 6.0);
    glVertex2f(11.8, -6.0);
    glVertex2f(-11.8, -6.0);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    //yellow
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f( -11.8, 0.5);
    glVertex2f(11.8, 0.5);
    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3f(0.79f, 0.27f, 0.2f);
    glVertex2f(0, 19.0);
    glVertex2f( 6.0, 12.0);
    glVertex2f(-6.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.27f, 0.2f);
    glVertex2f( -6.0, 12.0);
    glVertex2f( 6.0, 12.0);
    glVertex2f(6.0, -6.0);
    glVertex2f(-6.0, -6.0);
    glEnd();

     glLineWidth(15.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2f( 6.5, 11.0);
    glVertex2f(0, 19.0);
    glVertex2f(0, 19.0);
    glVertex2f(-6.5, 11.0);

    glEnd();

    ///WINDOW
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -14.0, 3.0);
    glVertex2f( -12.5, 3.0);
    glVertex2f( -12.5, 1.0);
    glVertex2f( -14.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -14.0, -2.0);
    glVertex2f( -12.5, -2.0);
    glVertex2f( -12.5, -4.0);
    glVertex2f( -14.0, -4.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 14.0, 3.0);
    glVertex2f( 12.5, 3.0);
    glVertex2f( 12.5, 1.0);
    glVertex2f( 14.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 14.0, -2.0);
    glVertex2f( 12.5, -2.0);
    glVertex2f( 12.5, -4.0);
    glVertex2f( 14.0, -4.0);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -11.0, 4.50);
    glVertex2f( -9.5, 4.50);
    glVertex2f( -9.5, 1.50);
    glVertex2f( -11.0, 1.50);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -8.20, 4.50);
    glVertex2f( -6.7, 4.50);
    glVertex2f( -6.7, 1.50);
    glVertex2f( -8.20, 1.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -11.0, -1.00);
    glVertex2f( -9.5, -1.00);
    glVertex2f( -9.5, -4.00);
    glVertex2f( -11.0, -4.00);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -8.20, -1.00);
    glVertex2f( -6.7, -1.00);
    glVertex2f( -6.7, -4.00);
    glVertex2f( -8.20, -4.00);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 11.0, 4.50);
    glVertex2f( 9.5, 4.50);
    glVertex2f( 9.5, 1.50);
    glVertex2f( 11.0, 1.50);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 8.20, 4.50);
    glVertex2f( 6.7, 4.50);
    glVertex2f( 6.7, 1.50);
    glVertex2f( 8.20, 1.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 11.0, -1.00);
    glVertex2f( 9.5, -1.00);
    glVertex2f( 9.5, -4.00);
    glVertex2f( 11.0, -4.00);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 8.20, -1.00);
    glVertex2f( 6.7, -1.00);
    glVertex2f( 6.7, -4.00);
    glVertex2f( 8.20, -4.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 11.0, -1.00);
    glVertex2f( 9.5, -1.00);
    glVertex2f( 9.5, -4.00);
    glVertex2f( 11.0, -4.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -4.20, -1.0);
    glVertex2f( -2.6, -1.0);
    glVertex2f( -2.6, -6.0);
    glVertex2f( -4.20, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( -0.80, -1.0);
    glVertex2f( 0.80, -1.0);
    glVertex2f( 0.80, -6.0);
    glVertex2f( -0.80, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f( 4.00, -1.0);
    glVertex2f( 2.45, -1.0);
    glVertex2f( 2.45, -6.0);
    glVertex2f( 4.00, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.2f);
    glVertex2f( 6.0, 6.0);
    glVertex2f(-6.0, 6.0);
    glVertex2f(-6.0, 2.0);
    glVertex2f(6.0, 2.0);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f( 6.0, 1.8);
    glVertex2f(-6.0, 1.8);
    glVertex2f( 6.0, 6.2);
    glVertex2f(-6.0, 6.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f(-3.90, 8.3);
    glVertex2f( -2.90, 8.3);
    glVertex2f(-2.90, 11.30);
    glVertex2f( -3.90, 11.30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f(-1.90, 8.3);
    glVertex2f( -0.90, 8.3);
    glVertex2f(-0.90, 11.30);
    glVertex2f( -1.90, 11.30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f(0.80, 8.3);
    glVertex2f( 1.80, 8.3);
    glVertex2f(1.80, 11.30);
    glVertex2f( 0.80, 11.30);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f(2.80, 8.3);
    glVertex2f( 3.80, 8.3);
    glVertex2f(3.80, 11.30);
    glVertex2f( 2.80, 11.30);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-2.90, 11.30);
    glVertex2f( -3.90, 11.30);
     glVertex2f(-0.90, 11.30);
    glVertex2f( -1.90, 11.30);
    glVertex2f(1.80, 11.30);
    glVertex2f( 0.80, 11.30);
   glVertex2f(3.80, 11.30);
    glVertex2f( 2.80, 11.30);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-16.0, -6.4);
    glVertex2f( 16.0, -6.4);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-16.5, -7.2);
    glVertex2f( 16.5, -7.2);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-17.0, -8.0);
    glVertex2f( 17.0, -8.0);
    glColor3f(0.7f, 0.7f, 0.7f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(-17.50, -8.8);
    glVertex2f( 17.50, -8.8);
    glEnd();

    ///LINE
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f( 13.25, 3.0);
    glVertex2f(13.25, 1.0);
    glVertex2f(14.00, 2.0);
    glVertex2f(12.50, 2.0);
    glVertex2f( 13.25, -4.0);
    glVertex2f(13.25, -2.0);
    glVertex2f(14.00, -3.0);
    glVertex2f(12.50, -3.0);
    glVertex2f(-13.25, 3.0);
    glVertex2f(-13.25, 1.0);
    glVertex2f(-14.00, 2.0);
    glVertex2f(-12.50, 2.0);
    glVertex2f(-13.25, -4.0);
    glVertex2f(-13.25, -2.0);
    glVertex2f(-14.00, -3.0);
    glVertex2f(-12.50, -3.0);
    glVertex2f(-10.25, -1.00);
    glVertex2f(-10.25, -4.00);
    glVertex2f(-11.00, -2.50);
    glVertex2f(-9.50, -2.50);
    glVertex2f(10.25, -1.00);
    glVertex2f(10.25, -4.00);
    glVertex2f(11.00, -2.50);
    glVertex2f(9.50, -2.50);
    glVertex2f(10.25, 4.50);
    glVertex2f(10.25, 1.50);
    glVertex2f(11.00, 3.0);
    glVertex2f(9.50, 3.0);
    glVertex2f(-10.25, 4.50);
    glVertex2f(-10.25, 1.50);
    glVertex2f(-11.00, 3.0);
    glVertex2f(-9.50, 3.0);
    glVertex2f(-7.45, 4.50);
    glVertex2f(-7.45, 1.50);
    glVertex2f(-8.20, 3.0);
    glVertex2f(-6.70, 3.0);
    glVertex2f(7.45, 4.50);
    glVertex2f(7.45, 1.50);
    glVertex2f(8.20, 3.0);
    glVertex2f(6.70, 3.0);
    glVertex2f(7.45, -1.00);
    glVertex2f(7.45, -4.00);
    glVertex2f(8.20, -2.50);
    glVertex2f(6.70, -2.50);
    glVertex2f(-7.45, -1.00);
    glVertex2f(-7.45, -4.00);
    glVertex2f(-8.20, -2.50);
    glVertex2f(-6.70, -2.50);
    glVertex2f( 3.20, -1.1);
    glVertex2f( 3.20, -6.0);
    glVertex2f( -3.40, -1.1);
    glVertex2f( -3.40, -6.0);
    glVertex2f( 0.00, -1.1);
    glVertex2f( 0.00, -6.0);

    glEnd();

    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(0.25, -3.50, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-0.25, -3.50, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-3.65, -3.50, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-3.15, -3.50, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(3.45, -3.50, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(2.95, -3.50, 0.09, 100);
    glColor3f(0.4f, 0.4, 0.4);
    drawCircle(0.00, 15.0, 0.75, 100);
    glColor3f(0.6f, 0.9, 1.0);
    drawCircle(0.00, 15.0, 0.7, 100);

    glEnd();

//third human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(18.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(18.45, -0.5);
glVertex2f(17.55, -0.50);
glVertex2f(17.55, -2.50);
glVertex2f(18.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(18.20, -2.50);
glVertex2f(18.20, -4.30);

glVertex2f(17.80, -2.50);
glVertex2f(17.80, -4.30);
glEnd();
//fourth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(17.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(17.45, -0.5);
glVertex2f(16.55, -0.50);
glVertex2f(16.55, -2.50);
glVertex2f(17.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(17.20, -2.50);
glVertex2f(17.20, -4.30);

glVertex2f(16.80, -2.50);
glVertex2f(16.80, -4.30);
glEnd();
//fifth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(9.00f, -7.60, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(9.45, -8.1);
glVertex2f(8.55, -8.10);
glVertex2f(8.55, -10.10);
glVertex2f(9.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(9.20, -10.10);
glVertex2f(9.20, -11.90);

glVertex2f(8.80, -10.10);
glVertex2f(8.80, -11.90);
glEnd();
//sixth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(10.00f, -7.60f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(10.45, -8.1);
glVertex2f(9.55, -8.1);
glVertex2f(9.55, -10.10);
glVertex2f(10.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(10.20, -10.10);
glVertex2f(10.20, -11.90);

glVertex2f(9.80, -10.10);
glVertex2f(9.80, -11.90);
glEnd();

 ///name of school
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-29.0f, 16.3f, GLUT_BITMAP_TIMES_ROMAN_10, "ABC HOSPITAL");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(24.6f, 16.3f, GLUT_BITMAP_TIMES_ROMAN_10, "SHOPPING MALL");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-21.4f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "LIBRARY");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(19.0f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "ACADEMY");
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-15.5f, 14.4f, GLUT_BITMAP_TIMES_ROMAN_10, "HOSTEL");
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(13.3f, 14.4f, GLUT_BITMAP_TIMES_ROMAN_10, "BD BANK");
     glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-32.7f, 14.4f, GLUT_BITMAP_TIMES_ROMAN_10, "C-BLOCK");
     glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(30.4f, 14.4f, GLUT_BITMAP_TIMES_ROMAN_10, "D-BLOCK");
   glColor3f(0.6f, 0.0f, 0.3f);
renderBitmapString(-4.50, 3.50f, GLUT_BITMAP_HELVETICA_18, "Shaheed Anwar College");
    glEnd();

    ///human
 if (isShown)
    {
glPushMatrix();
glTranslatef(0.0f, moveN, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(0.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-0.50, -28.5);
glVertex2f(0.50, -28.50);
glVertex2f(0.50, -30.50);
glVertex2f(-0.50, -30.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-0.19, -30.50);
glVertex2f(-0.19, -32.50);
glEnd();

glBegin(GL_LINES);
glVertex2f(0.21, -30.50);
glVertex2f(0.21, -32.50);
glEnd();

glPopMatrix();
glPopMatrix();
    }

///Bus 01
    glPushMatrix();
    glTranslatef(moveW , 0.0f , 0.0f);
    glLineWidth(0.5);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-11.90, -23.50);
    glVertex2f(-7.10, -23.50);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-12.00, -24.00);

    glColor3f(0.7, 0.7, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -24.00);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-12.00, -25.00);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -25.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-7.00, -26.50);
    glVertex2f(-12.00, -26.50);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-11.00f, -24.0f);
    glVertex2f(-11.00f, -25.05f);
    glVertex2f(-10.00f, -24.0f);
    glVertex2f(-10.00f, -25.05f);
    glVertex2f(-9.00f, -24.0f);
    glVertex2f(-9.00f, -25.05f);
    glVertex2f(-8.0f, -24.0f);
    glVertex2f(-8.0f, -25.05f);
    glEnd();

    //wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-7.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-7.80f, -26.30f, 0.25f, 100);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-10.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.80f, -26.30f, 0.25f, 100);
    glEnd();
    glPopMatrix();

    ///Lamp
    //1st
     glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -21.0);
    glVertex2f(21.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -15.00);
    glVertex2f(21.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(21.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(21.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();

         if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(21.0f, -12.50f, 0.35f, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();
    }

     //2nd
     glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-21.0, -21.0);
    glVertex2f(-21.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-21.0, -15.00);
    glVertex2f(-21.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(-21.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(-21.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(-21.0f,-11.50f, 0.35f, 100);
    glEnd();

         if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-21.0f, -12.50f, 0.35f, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(-21.0f,-11.50f, 0.35f, 100);
    glEnd();
    }
    drawTurbine();
    glutSwapBuffers();
 }




 ///display function for universityLife
 void universityLife() {
    glClear(GL_COLOR_BUFFER_BIT);

 /// Sky
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.75f, 1.0f);
    glVertex2f(-35.0, 35.0);
    glVertex2f(35.0, 35.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    ///Sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(-13.00f, 27.00f, 1.0f, 100);
    glEnd();

    ///clouds and birds
    drawCloudAndBird();

    ///green middle ground
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.9f, 0.4f);
    glVertex2f(-35.0, 0.0);
    glVertex2f(35.0, 0.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -20.0);
    glVertex2f(-35.0, -20.0);
    glEnd();

    ///basket ball ground
     glBegin(GL_QUADS);
    glColor3f(0.7f, 0.9f, 0.4f);
    glVertex2f(-35.0, -2.0);
    glVertex2f(35.0, -2.0);
    glColor3f(0.0f, 0.792f, 0.0f);
    glVertex2f(35.0, -14.0);
    glVertex2f(-35.0, -14.0);
    glEnd();

     ///busket
    glColor3f(0.8f, 0.9f, 0.6f);
      drawCircle(-35.0, -8.0, 4.0, 100);
      drawCircle(-14.0, -8.0, 4.0, 100);
      drawCircle(-24.3, -8.0, 0.8, 100);
      drawCircle(35.0, -8.0, 4.0, 100);
      drawCircle(14.0, -8.0, 4.0, 100);
      drawCircle(24.3, -8.0, 0.8, 100);
    drawCircle(0.0, -8.0, 0.8, 100);
    glColor3f(0.6f, 0.9f, 0.3f);
    drawCircle(-35.0, -8.0, 3.0, 100);
    drawCircle(-14.0, -8.0, 3.0, 100);
    drawCircle(35.0, -8.0, 3.0, 100);
    drawCircle(14.0, -8.0, 3.0, 100);
    glEnd();

 //busket line
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(-31.0, -8.0);
    glVertex2f(-18.0, -8.0);
    glVertex2f(-17.50, -2.0);
     glVertex2f(-19.80, -14.0);
     glVertex2f(-28.0, -2.0);
     glVertex2f(-31.0, -14.0);
    glVertex2f(-31.0, -8.0);
    glVertex2f(31.0, -8.0);
    glVertex2f(17.50, -2.0);
     glVertex2f(19.80, -14.0);
     glVertex2f(28.0, -2.0);
     glVertex2f(31.0, -14.0);
     glVertex2f(-5.0, -2.0);
     glVertex2f(-6.50, -14.0);
     glVertex2f(5.0, -2.0);
     glVertex2f(6.50, -14.0);
    glEnd();

    ///Road
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.55f, 0.55f);
    glVertex2f(-35.0, -20.0);
    glVertex2f(35.0, -20.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(35.0, -35.0);
    glVertex2f(-35.0, -35.0);
    glEnd();
    ///ROAD LINE
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    //Road
    glVertex2f(-35.0, -21.0);
    glVertex2f(35.0, -21.0);
    glEnd();

    ///yellow
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-37.0f, -30.5f);
    glVertex2f(-33.0f, -30.5f);
    glVertex2f(-30.0f, -30.5f);
    glVertex2f(-27.0f, -30.5f);
    glVertex2f(-24.0f, -30.5f);
    glVertex2f(-21.0f, -30.5f);
    glVertex2f(-18.0f, -30.5f);
    glVertex2f(-15.0f, -30.5f);
    glVertex2f(-12.0f, -30.5f);
    glVertex2f(-9.0f, -30.5f);
    glVertex2f(-6.0f, -30.5f);
    glVertex2f(-3.0f, -30.5f);
    glVertex2f(0.0f, -30.5f);
    glVertex2f(3.0f, -30.5f);
    glVertex2f(6.0f, -30.5f);
    glVertex2f(9.0f, -30.5f);
    glVertex2f(12.0f, -30.5f);
    glVertex2f(15.0f, -30.5f);
    glVertex2f(18.0f, -30.5f);
    glVertex2f(21.0f, -30.5f);
    glVertex2f(24.0f, -30.5f);
    glVertex2f(27.0f, -30.5f);
    glVertex2f(30.0f, -30.5f);
    glVertex2f(33.0f, -30.5f);
    glVertex2f(36.0f, -30.5f);
    glVertex2f(39.0f, -30.5f);

   ///arrow
     glColor3f(0.9f, 0.9f, 0.9f);
     glVertex2f(-20.00f, -24.0f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -24.5f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(-18.5f, -23.5f);
     glVertex2f(-18.0f, -24.0f);
     glVertex2f(15.0f, -24.0f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -24.5f);
     glVertex2f(17.0f, -24.0f);
     glVertex2f(16.5f, -23.5f);
     glVertex2f(17.0f, -24.0f);

    glEnd();

    ///round
    glColor3f(0.6f, 0.8f, 0.9f);
    drawCircle(0.0, 27.0, 8.10, 1000);
    glColor3f(0.2f, 0.3f, 0.7);
    drawCircle(0.0, 27.0, 8.0, 1000);
    glLineWidth(2.0);

    glBegin(GL_LINES);
    glColor3f(0.6f, 0.8f, 0.9f);
    glVertex2f(-5.0, 33.5);
    glVertex2f(5.10, 33.5);
    glVertex2f(-7.10, 30.9);
    glVertex2f(7.00, 30.9);
    glVertex2f(-7.90, 28.30);
    glVertex2f(7.90, 28.30);
    glVertex2f(-7.90, 25.80);
    glVertex2f(7.90, 25.80);
    glVertex2f(-7.20, 23.20);
    glVertex2f(7.30, 23.20);
    glVertex2f(-5.0, 20.60);
    glVertex2f(5.0, 20.60);

    glVertex2f(0, 35.0);
    glVertex2f(0, 19.0);
    glVertex2f(-4, 34.0);
    glVertex2f(-2, 19.0);
    glVertex2f(-7, 31.0);
    glVertex2f(-4, 20.0);
    glVertex2f(4, 34.0);
    glVertex2f(2, 19.0);
    glVertex2f(7, 31.0);
    glVertex2f(4, 20.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-15.0, 15.0);
    glVertex2f(0.0, 19.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(-15.0, -2.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(15.0, 15.0);
    glVertex2f(0.0, 19.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(15.0, -2.0);
    glEnd();

    ///aiub building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-35.0, 23.0);
    glVertex2f(-18.0, 20.0);
    glVertex2f(-18.0, -2.0);
    glVertex2f(-35.0, -8.0);
    glEnd();

    glLineWidth(16.50);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 1.0f);
     glVertex2f(-35.0, 5.20);
    glVertex2f(-17.50, 6.70);
    glVertex2f(-17.50, 19.70);
    glVertex2f(-35.0, 20.80);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-35.0, 8.50);
    glVertex2f(-17.50, 8.50);
     glVertex2f(-35.0, 7.00);
    glVertex2f(-17.50, 7.00);
    glVertex2f(-18.50, 24.20);
    glVertex2f(-35.0, 27.90);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
     glVertex2f(-35.0, 18.0);
    glVertex2f(-18.80, 16.50);
    glVertex2f(-18.80, 12.50);
    glVertex2f(-35.0, 13.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-35.0, 2.0);
    glVertex2f(-18.80, 4.0);
    glVertex2f(-18.80, 0.70);
    glVertex2f(-35.0, -4.20);
    glEnd();
   //text window
   glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-9.50, 15.40);
    glVertex2f(9.50, 15.40);
    glVertex2f(9.50, 13.50);
    glVertex2f(-9.50, 13.50);
    glEnd();
    //upper window
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-13.0, 12.0);
    glVertex2f(13.0, 12.0);
    glVertex2f(13.0, 7.0);
    glVertex2f(-13.0, 7.0);
    glEnd();

    //door side window
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-13.0, 5.0);
    glVertex2f(-4.0, 5.0);
    glVertex2f(-4.0, 0.0);
    glVertex2f(-13.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(13.0, 5.0);
    glVertex2f(4.0, 5.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(13.0, 0.0);
    glEnd();

   ///door
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(-3.0, 5.0);
    glVertex2f(3.0, 5.0);
    glVertex2f(3.0, -2.0);
    glVertex2f(-3.0, -2.0);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(-35.0, 10.70);
    glVertex2f(-18.0, 10.70);
     glColor3f(0.5f, 0.5f, 0.9f);
    glVertex2f(-35.0, 15.0);
    glVertex2f(-18.80, 15.0);
    glVertex2f(-35.0, -1.5);
    glVertex2f(-18.80, 2.0);

     ///window
     glVertex2f(-34.0, 17.80);
    glVertex2f(-34.0, 13.0);
      glVertex2f(-28.0, 17.50);
    glVertex2f(-28.0, 12.80);
      glVertex2f(-21.0, 17.0);
    glVertex2f(-21.0, 12.60);
    glVertex2f(-34.0, 2.10);
    glVertex2f(-34.0, -4.10);
    glVertex2f(-28.0, 3.0);
    glVertex2f(-28.0, -2.10);
    glVertex2f(-21.0, 4.0);
    glVertex2f(-21.0, 0.0);
    glVertex2f(-15.0, -2.0);
    glVertex2f(15.0, -2.0);

    //window line
    glVertex2f(-13.0, 9.5);
    glVertex2f(13.0, 9.5);
    glVertex2f(-10.0, 12.0);
    glVertex2f(-10.0, 7.0);
    glVertex2f(-7.0, 12.0);
    glVertex2f(-7.0, 7.0);
    glVertex2f(-4.0, 12.0);
    glVertex2f(-4.0, 7.0);
    glVertex2f(0.0, 12.0);
    glVertex2f(0.0, 7.0);
    glVertex2f(4.0, 12.0);
    glVertex2f(4.0, 7.0);
    glVertex2f(13.0, 9.5);
    glVertex2f(13.0, 9.5);
    glVertex2f(10.0, 12.0);
    glVertex2f(10.0, 7.0);
    glVertex2f(7.0, 12.0);
    glVertex2f(7.0, 7.0);
    glVertex2f(-13.0, 2.5);
    glVertex2f(-4.0, 2.5);
    glVertex2f(13.0, 2.5);
    glVertex2f(4.0, 2.5);
   glVertex2f(-10.0, 5.0);
    glVertex2f(-10.0, 0.0);
    glVertex2f(-7.0, 5.0);
    glVertex2f(-7.0, 0.0);
    glVertex2f(-4.0, 5.0);
    glVertex2f(-4.0, 0.0);
    glVertex2f(10.0, 5.0);
    glVertex2f(10.0, 0.0);
    glVertex2f(7.0, 5.0);
    glVertex2f(7.0, 0.0);
    glVertex2f(4.0, 5.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(-0.90, 5.0);
    glVertex2f(-0.90, -2.0);
    glVertex2f(0.90, 5.0);
    glVertex2f(0.90, -2.0);
    glEnd();
//door handle
   glColor3f(1.0f, 1.0, 1.0);
    drawCircle(1.25, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(0.75, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-1.25, 2.0, 0.09, 100);
    glColor3f(1.0f, 1.0, 1.0);
    drawCircle(-0.75, 2.0, 0.09, 100);
    glColor3f(0.4f, 0.4, 0.4);
    drawCircle(0.0, 17.0, 0.75, 100);
    glColor3f(0.6f, 0.9, 1.0);
    drawCircle(0.0, 17.0, 0.7, 100);

    glEnd();

//upper
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(-35.0, 25.0);
    glVertex2f(-18.00, 22.0);
    glVertex2f(-18.00, 24.30);
    glVertex2f(-35.0, 28.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(-35.0, 25.0);
    glVertex2f(-17.50, 22.0);
    glVertex2f(-17.50, 19.30);
    glVertex2f(-35.0, 21.30);
    glEnd();

    //right
    ///right aiub building
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(35.0, 23.0);
    glVertex2f(18.0, 20.0);
    glVertex2f(18.0, -2.0);
    glVertex2f(35.0, -8.0);
    glEnd();

    glLineWidth(16.50);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 1.0f);
     glVertex2f(35.0, 5.20);
    glVertex2f(17.50, 6.70);
    glVertex2f(17.50, 19.70);
    glVertex2f(35.0, 20.80);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(35.0, 8.50);
    glVertex2f(17.50, 8.50);
     glVertex2f(35.0, 7.00);
    glVertex2f(17.50, 7.00);
 glVertex2f(18.50, 24.20);
    glVertex2f(35.0, 27.90);

    glEnd();

 glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
     glVertex2f(35.0, 18.0);
    glVertex2f(18.80, 16.50);
    glVertex2f(18.80, 12.50);
    glVertex2f(35.0, 13.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(35.0, 2.0);
    glVertex2f(18.80, 4.0);
    glVertex2f(18.80, 0.70);
    glVertex2f(35.0, -4.20);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(35.0, 10.70);
    glVertex2f(18.0, 10.70);
     glColor3f(0.5f, 0.5f, 0.9f);

    glVertex2f(35.0, 15.0);
    glVertex2f(18.80, 15.0);
    glVertex2f(35.0, -1.5);
    glVertex2f(18.80, 2.0);
//window
       glVertex2f(34.0, 17.80);
    glVertex2f(34.0, 13.0);
      glVertex2f(28.0, 17.50);
    glVertex2f(28.0, 12.80);
      glVertex2f(21.0, 17.0);
    glVertex2f(21.0, 12.60);

    glVertex2f(34.0, 2.10);
    glVertex2f(34.0, -4.10);
    glVertex2f(28.0, 3.0);
    glVertex2f(28.0, -2.10);
    glVertex2f(21.0, 4.0);
    glVertex2f(21.0, 0.0);

     glVertex2f(18.0, -2.0);
    glVertex2f(35.0, -8.0);

    glEnd();

//upper
         glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 1.0f);
    glVertex2f(35.0, 25.0);
    glVertex2f(18.00, 22.0);
    glVertex2f(18.00, 24.30);
    glVertex2f(35.0, 28.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.95f);
    glVertex2f(35.0, 25.0);
    glVertex2f(17.50, 22.0);
    glVertex2f(17.50, 19.30);
    glVertex2f(35.0, 21.30);
    glEnd();

///human
 glPushMatrix();
    glTranslatef(moveN3,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-28.00f, -1.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.0, 1.0);
glBegin(GL_QUADS);
glVertex2f(-28.45, -1.5);
glVertex2f(-27.55, -1.50);
glVertex2f(-27.55, -3.50);
glVertex2f(-28.45, -3.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(6.50);
glBegin(GL_LINES);
glVertex2f(-28.20, -3.50);
glVertex2f(-28.20, -5.30);

glVertex2f(-27.80, -3.50);
glVertex2f(-27.80, -5.30);
glEnd();

glPopMatrix();
glPopMatrix();

//second human
 glPushMatrix();
    glTranslatef(moveN4,0.0f,0.0f);
    glPushMatrix();
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(-19.00f, -5.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(1.0, 0.50, 0.0);
glBegin(GL_QUADS);
glVertex2f(-19.45, -5.5);
glVertex2f(-18.55, -5.50);
glVertex2f(-18.55, -7.50);
glVertex2f(-19.45, -7.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(-19.20, -7.50);
glVertex2f(-19.20, -9.30);

glVertex2f(-18.80, -7.50);
glVertex2f(-18.80, -9.30);
glEnd();
glPopMatrix();
glPopMatrix();

//third human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(18.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.6, 0.2, 0.1);
glBegin(GL_QUADS);
glVertex2f(18.45, -0.5);
glVertex2f(17.55, -0.50);
glVertex2f(17.55, -2.50);
glVertex2f(18.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(18.20, -2.50);
glVertex2f(18.20, -4.30);

glVertex2f(17.80, -2.50);
glVertex2f(17.80, -4.30);
glEnd();
//fourth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(17.00f, 0.00f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.0, 0.5, 0.3);
glBegin(GL_QUADS);
glVertex2f(17.45, -0.5);
glVertex2f(16.55, -0.50);
glVertex2f(16.55, -2.50);
glVertex2f(17.45, -2.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(17.20, -2.50);
glVertex2f(17.20, -4.30);

glVertex2f(16.80, -2.50);
glVertex2f(16.80, -4.30);
glEnd();
//fifth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(9.00f, -7.60, 0.35f, 100);
    glEnd();

//body
glColor3f(0.8, 0.0, 0.7);
glBegin(GL_QUADS);
glVertex2f(9.45, -8.1);
glVertex2f(8.55, -8.10);
glVertex2f(8.55, -10.10);
glVertex2f(9.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(9.20, -10.10);
glVertex2f(9.20, -11.90);

glVertex2f(8.80, -10.10);
glVertex2f(8.80, -11.90);
glEnd();
//sixth human
//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(10.00f, -7.60f, 0.35f, 100);
    glEnd();

//body
glColor3f(0.7, 0.3, 0.0);
glBegin(GL_QUADS);
glVertex2f(10.45, -8.1);
glVertex2f(9.55, -8.1);
glVertex2f(9.55, -10.10);
glVertex2f(10.45, -10.10);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.48);
glBegin(GL_LINES);
glVertex2f(10.20, -10.10);
glVertex2f(10.20, -11.90);

glVertex2f(9.80, -10.10);
glVertex2f(9.80, -11.90);
glEnd();

 ///name of school
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-21.4f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "AIUB");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(19.0f, 18.0f, GLUT_BITMAP_TIMES_ROMAN_10, "AIUB");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-32.7f, 22.4f, GLUT_BITMAP_TIMES_ROMAN_10, "D-BUILDING");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(28.7f, 22.4f, GLUT_BITMAP_TIMES_ROMAN_10, "C-BUILDING");
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(-32.7f, 7.85, GLUT_BITMAP_8_BY_13, "where leaders are created");
     glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(22.7f, 7.85, GLUT_BITMAP_8_BY_13, "where leaders are created");
    glColor3f(0.0f, 0.0f, 0.0f);
renderBitmapString(-9.0f, 14.0f, GLUT_BITMAP_8_BY_13, "American International University Bangladesh-AIUB");
    glEnd();


    ///human

 if (visible)
    {

glPushMatrix();
glTranslatef(0.0f, moveMM2, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(0.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(-0.50, -28.5);
glVertex2f(0.50, -28.50);
glVertex2f(0.50, -30.50);
glVertex2f(-0.50, -30.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-0.19, -30.50);
glVertex2f(-0.19, -32.50);
glEnd();

glBegin(GL_LINES);
glVertex2f(0.21, -30.50);
glVertex2f(0.21, -32.50);
glEnd();

glPopMatrix();
glPopMatrix();
    }
     if (extraObjectVisible)
    {
        glPushMatrix();
glTranslatef(0.0f, moveMM2, 0.0f);

//head
glColor3f(0.0, 0.0, 0.0);
drawCircle(0.00f, -28.00f, 0.4f, 100);

//body
glPushMatrix();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_QUADS);
glVertex2f(-0.50, -28.5);
glVertex2f(0.50, -28.50);
glVertex2f(0.50, -30.50);
glVertex2f(-0.50, -30.50);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glLineWidth(7.50);
glBegin(GL_LINES);
glVertex2f(-0.19, -30.50);
glVertex2f(-0.19, -32.50);
glVertex2f(0.21, -30.50);
glVertex2f(0.21, -32.50);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.80, -27.10);
glVertex2f(0.0, -26.60);
glVertex2f(0.80, -27.10);
glVertex2f(0.0, -27.60);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.50, -28.5);
glVertex2f(-0.20, -28.50);
glVertex2f(-0.30, -32.50);
glVertex2f(-0.50, -32.50);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(0.50, -28.5);
glVertex2f(0.20, -28.50);
glVertex2f(0.30, -32.50);
glVertex2f(0.50, -32.50);
glEnd();

glLineWidth(1.50);
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 0.0);
glVertex2f(-0.50, -27.20);
glVertex2f(-0.50, -28.0);
glEnd();

glPopMatrix();
glPopMatrix();
    }

    ///Bus 01
    glPushMatrix();
    glTranslatef(moveW , 0.0f , 0.0f);
    glLineWidth(0.5);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-11.90, -23.50);
    glVertex2f(-7.10, -23.50);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-12.00, -24.00);

    glColor3f(0.7, 0.7, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -24.00);
    glVertex2f(-7.00, -24.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-12.00, -25.00);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-12.00, -25.00);
    glVertex2f(-7.00, -25.00);
    glVertex2f(-7.00, -26.50);
    glVertex2f(-12.00, -26.50);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-11.00f, -24.0f);
    glVertex2f(-11.00f, -25.05f);
    glVertex2f(-10.00f, -24.0f);
    glVertex2f(-10.00f, -25.05f);
    glVertex2f(-9.00f, -24.0f);
    glVertex2f(-9.00f, -25.05f);
    glVertex2f(-8.0f, -24.0f);
    glVertex2f(-8.0f, -25.05f);
    glEnd();

    //wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-7.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-7.80f, -26.30f, 0.25f, 100);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-10.80f, -26.30f, 0.45f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-10.80f, -26.30f, 0.25f, 100);
    glEnd();
    glPopMatrix();

    ///Lamp
    //1st
     glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -21.0);
    glVertex2f(21.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(21.0, -15.00);
    glVertex2f(21.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(21.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(21.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();

         if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(21.0f, -12.50f, 0.35f, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(21.0f,-11.50f, 0.35f, 100);
    glEnd();
    }
     //2nd
     glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-21.0, -21.0);
    glVertex2f(-21.0, -15.0);
     glEnd();
    glLineWidth(26.00);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-21.0, -15.00);
    glVertex2f(-21.0, -10.0);
            glEnd();
    glColor3f(0.55f, 0.55f, 0.0f);
    drawCircle(-21.0f, -13.50f, 0.35f, 100);
    glColor3f(0.6f, 0.0f, 0.0f);
    drawCircle(-21.0f,-12.50f, 0.35f, 100);
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(-21.0f,-11.50f, 0.35f, 100);
    glEnd();

         if (isRightPaused) {
        glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-21.0f, -12.50f, 0.35f, 100);
        glEnd();
    } else {
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(-21.0f,-11.50f, 0.35f, 100);
    glEnd();
    }
glutSwapBuffers();
 }




 ///display function for classRoom
void classRoom() {
    glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_QUADS);
        glColor3f(0.95, 0.95, 0.95);
        glVertex2f(-35.0, -25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(15.0, 3.0);
        glVertex2f(35.0, -25.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.95, 0.95, 0.95);
        glVertex2f(-35.0, -25.0);
        glVertex2f(35.0, -25.0);
        glVertex2f(35.0, -35.0);
        glVertex2f(-35.0, -35.0);
    glEnd();
     glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(-35.0, -25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-35.0, 35.0);
    glEnd();
         glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(35.0, -25.0);
        glVertex2f(15.0, 3.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(35.0, 35.0);
    glEnd();
       glBegin(GL_QUADS);
        glColor3f(0.76, 0.90, 0.51);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 3.0);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-35.0, 35.0);
        glVertex2f(35.0, 35.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(-15.0, 25.0);
    glEnd();
    glLineWidth(1.00);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-35.0, 35.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(-15.0, 3.0);
        glVertex2f(-15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(35.0, 35.0);
        glVertex2f(15.0, 25.0);
        glVertex2f(15.0, 3.0);
         glEnd();
       ///scenary
        glLineWidth(10.00);
       glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.4);
        glVertex2f(-15.0, 13.0);
        glVertex2f(-18.0, 13.0);
        glVertex2f(15.0, 13.0);
        glVertex2f(18.0, 13.0);
        glColor3f(0.95, 0.95, 0.6);
        glVertex2f(10.35, 18.0);
        glVertex2f(10.35, 3.0);
        glEnd();

       glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(-2.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(3.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(3.50, 20.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(14.50, 18.0);
        glVertex2f(10.55, 18.0);
        glVertex2f(10.55, 3.0);
        glVertex2f(14.50, 3.0);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.7);
        glVertex2f(-13.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glEnd();
        glColor3f(0.6f, 0.0f, 0.0f);
        renderBitmapString(-12.70f, 14.0, GLUT_BITMAP_8_BY_13, "WORK ");
        renderBitmapString(-12.70, 11.60f, GLUT_BITMAP_8_BY_13, "HARD");

       glLineWidth(2.00);
       glBegin(GL_LINES);
        glColor3f(0.60, 0.40, 0.4);
        glVertex2f(14.5, 16.0);
        glVertex2f(10.55, 16.0);
        glVertex2f(14.5, 14.0);
        glVertex2f(10.55, 14.0);
        glVertex2f(14.5, 12.0);
        glVertex2f(10.55, 12.0);
        glVertex2f(14.5, 10.0);
        glVertex2f(10.55, 10.0);
        glVertex2f(14.5, 8.0);
        glVertex2f(10.55, 8.0);
        glVertex2f(14.5, 6.0);
        glVertex2f(10.55, 6.0);
        glVertex2f(14.5, 4.0);
        glVertex2f(10.55, 4.0);
        glVertex2f(-13.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 16.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-10.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glVertex2f(-13.50, 10.50);
        glVertex2f(-13.50, 16.50);
        glVertex2f(-2.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 23.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-3.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glVertex2f(-2.50, 20.0);
        glVertex2f(-2.50, 23.0);
        glVertex2f(0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 23.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(-0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glVertex2f(0.50, 20.0);
        glVertex2f(0.50, 23.0);
        glVertex2f(3.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 23.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(2.50, 20.0);
        glVertex2f(3.50, 20.0);
        glVertex2f(3.50, 20.0);
        glVertex2f(3.50, 23.0);
        glEnd();
        drawCircle(12.5,5.0,0.2,100);
        drawCircle(12.5,7.0,0.2,100);
        drawCircle(12.5,9.0,0.2,100);
        drawCircle(12.5,11.0,0.2,100);
        drawCircle(12.5,13.0,0.2,100);
        drawCircle(12.5,15.0,0.2,100);
        drawCircle(12.5,17.0,0.2,100);
        ///window
        glBegin(GL_QUADS);
        glColor3f(0.66, 0.80, 0.51);
        glVertex2f(-35.0, -2.50);
        glVertex2f(-18.10, 7.50);
        glVertex2f(-18.10, 22.50);
        glVertex2f(-35.0, 31.90);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(-35.0, -1.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-35.0, 30.0);
        glEnd();

glPushMatrix();
    glTranslatef(moveC1, 0.0f, 0.0f);
        glColor3f(0.85, 0.9, 1.0);
    drawCircle(-33.0, 18.0, 2, 100);
    drawCircle(-32.0, 15.50, 2, 100);
    drawCircle(-31.0, 15.0, 2, 100);
    drawCircle(-34.0, 16.0, 2, 100);
    drawCircle(-30.0, 16.0, 2, 100);
    drawCircle(-23.0, 15.0, 2, 100);
    drawCircle(-22.0, 15.0, 2, 100);
    drawCircle(-23.0, 12.0, 2, 100);
    drawCircle(-25.0, 13.0, 2, 100);
    drawCircle(-20.70, 13.0, 2, 100);
    glPopMatrix();

        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-35.0, -1.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 8.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-19.0, 22.0);
        glVertex2f(-35.0, 30.0);
        glVertex2f(-27.0, 3.50);
        glVertex2f(-27.0, 26.0);
        glEnd();

        //2nd
         glBegin(GL_QUADS);
        glColor3f(0.66, 0.80, 0.51);
        glVertex2f(35.0, -2.50);
        glVertex2f(18.10, 7.50);
        glVertex2f(18.10, 22.50);
        glVertex2f(35.0, 31.90);
        glEnd();
        glBegin(GL_QUADS);
        glColor3f(0.66, 0.90, 1.0);
        glVertex2f(35.0, -1.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(35.0, 30.0);
        glEnd();

        glPushMatrix();
    glTranslatef(moveC2, 0.0f, 0.0f);
        glColor3f(0.85, 0.9, 1.0);
    drawCircle(33.0, 18.0, 2, 100);
    drawCircle(32.0, 15.50, 2, 100);
    drawCircle(31.0, 15.0, 2, 100);
    drawCircle(34.0, 16.0, 2, 100);
    drawCircle(30.0, 16.0, 2, 100);
    drawCircle(23.0, 15.0, 2, 100);
    drawCircle(22.0, 15.0, 2, 100);
    drawCircle(23.0, 12.0, 2, 100);
    drawCircle(25.0, 13.0, 2, 100);
    drawCircle(20.70, 13.0, 2, 100);
    glPopMatrix();
        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(35.0, -1.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 8.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(19.0, 22.0);
        glVertex2f(35.0, 30.0);
        glVertex2f(27.0, 3.50);
        glVertex2f(27.0, 26.0);
        glVertex2f(-9.0, 8.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 8.0);
        glVertex2f(9.0, 8.0);
        glVertex2f(-9.0, 8.0);
        glEnd();

        ///board
        glBegin(GL_QUADS);
        glColor3f(0.4, 0.7, 0.4);
        glVertex2f(-9.0, 8.0);
        glVertex2f(-9.0, 18.0);
        glVertex2f(9.0, 18.0);
        glVertex2f(9.0, 8.0);
        glEnd();
        ///TREE
        glBegin(GL_QUADS);
        glColor3f(0.8, 0.5, 0.2);
        glVertex2f(-14.15, 3.80);
        glVertex2f(-13.50, 3.80);
        glVertex2f(-12.70, 1.0);
        glVertex2f(-14.95, 1.0);
        glEnd();
        glLineWidth(2.00);
        glBegin(GL_LINES);
        glColor3f(0.8, 0.5, 0.2);
        glVertex2f(-13.80, 3.80);
        glVertex2f(-13.80, 6.80);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.5, 0.2);
        glVertex2f(-14.90, 6.890);
        glVertex2f(-13.60, 6.850);
        glVertex2f(-13.00, 8.0);
        glEnd();

        ///desk shadow
        glLineWidth(5.00);
        glBegin(GL_LINES);
        glColor3f(0.60, 0.40, 0.4);
        glVertex2f(-16.0, -23.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-28.0, -27.0);
        glVertex2f(-12.0, -13.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-23.0, -17.0);
        glVertex2f(-8.20, -3.45);
        glVertex2f(-10.20, -6.80);
        glVertex2f(-10.20, -6.80);
        glVertex2f(-17.70, -6.90);

        //desk
        glVertex2f(16.0, -23.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(28.0, -27.0);
        glVertex2f(12.0, -13.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(23.0, -17.0);
        glVertex2f(8.20, -3.35);
        glVertex2f(10.20, -6.90);
        glVertex2f(10.20, -6.90);
        glVertex2f(17.80, -6.90);

        //desk
        glVertex2f(8.50, -27.0);
        glVertex2f(-8.50, -27.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(-6.0, -17.0);
        glVertex2f(5.0, -6.90);
        glVertex2f(-5.0, -6.90);

         ///handle
        glColor3f(0.60, 0.40, 0.4);
        glVertex2f(-16.0, -23.20);
        glVertex2f(-16.0, -27.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-18.0, -31.0);
        glVertex2f(-27.80, -27.0);
        glVertex2f(-27.80, -31.0);
        glVertex2f(-25.80, -23.0);
        glVertex2f(-25.80, -30.0);
        glVertex2f(-20.80, -13.0);
        glVertex2f(-20.80, -20.0);
        glVertex2f(-12.0, -13.0);
        glVertex2f(-12.0, -18.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-14.0, -22.0);
        glVertex2f(-23.0, -17.0);
        glVertex2f(-23.0, -22.0);
        glVertex2f(-15.60, -3.20);
        glVertex2f(-15.60, -10.20);
        glVertex2f(-8.20, -3.20);
        glVertex2f(-8.20, -8.20);
        glVertex2f(-10.20, -6.90);
        glVertex2f(-10.20, -11.90);
        glVertex2f(-17.80, -6.90);
        glVertex2f(-17.80, -11.90);

        //desk
        glVertex2f(25.80, -23.0);
        glVertex2f(25.80, -30.0);
        glVertex2f(16.0, -23.0);
        glVertex2f(16.0, -27.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(18.0, -31.0);
        glVertex2f(27.70, -27.0);
        glVertex2f(27.70, -31.0);
        glVertex2f(20.80, -13.0);
        glVertex2f(20.80, -20.0);
        glVertex2f(12.0, -13.0);
        glVertex2f(12.0, -17.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(14.0, -21.0);
        glVertex2f(22.70, -17.0);
        glVertex2f(22.70, -21.0);
        glVertex2f(15.60, -3.20);
        glVertex2f(15.60, -10.20);
        glVertex2f(8.20, -3.20);
        glVertex2f(8.20, -7.20);
        glVertex2f(10.20, -6.90);
        glVertex2f(10.20, -10.90);
        glVertex2f(17.60, -6.90);
        glVertex2f(17.60, -10.90);

        //desk
        glVertex2f(-7.0, -23.30);
        glVertex2f(-7.0, -29.0);
        glVertex2f(7.0, -23.30);
        glVertex2f(7.0, -29.0);
        glVertex2f(8.50, -27.0);
        glVertex2f(8.50, -31.0);
        glVertex2f(-8.50, -27.0);
        glVertex2f(-8.50, -31.0);

        glVertex2f(-5.0, -13.30);
        glVertex2f(-5.0, -19.0);
        glVertex2f(5.0, -13.30);
        glVertex2f(5.0, -19.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(6.0, -21.0);
        glVertex2f(-6.0, -17.0);
        glVertex2f(-6.0, -21.0);

        glVertex2f(-4.0, -3.60);
        glVertex2f(-4.0, -9.20);
        glVertex2f(4.0, -3.60);
        glVertex2f(4.0, -9.20);
        glVertex2f(5.0, -6.90);
        glVertex2f(5.0, -10.90);
        glVertex2f(-5.0, -6.90);
        glVertex2f(-5.0, -10.90);
        glEnd();

        ///desk
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-26.0, -23.0);
        glVertex2f(-16.0, -23.0);
        glVertex2f(-18.0, -27.0);
        glVertex2f(-28.0, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-21.0, -13.0);
        glVertex2f(-12.0, -13.0);
        glVertex2f(-14.0, -17.0);
        glVertex2f(-23.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-15.80, -3.20);
        glVertex2f(-8.20, -3.20);
        glVertex2f(-10.20, -6.90);
        glVertex2f(-17.80, -6.90);
        glEnd();

        //desk
         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(26.0, -23.0);
        glVertex2f(16.0, -23.0);
        glVertex2f(18.0, -27.0);
        glVertex2f(28.0, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(21.0, -13.0);
        glVertex2f(12.0, -13.0);
        glVertex2f(14.0, -17.0);
        glVertex2f(23.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(15.80, -3.20);
        glVertex2f(8.20, -3.20);
        glVertex2f(10.20, -6.90);
        glVertex2f(17.80, -6.90);
        glEnd();

        //desk
          glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-7.0, -23.0);
        glVertex2f(7.0, -23.0);
        glVertex2f(8.50, -27.0);
        glVertex2f(-8.50, -27.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-5.0, -13.0);
        glVertex2f(5.0, -13.0);
        glVertex2f(6.0, -17.0);
        glVertex2f(-6.0, -17.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.6);
        glVertex2f(-4.0, -3.20);
        glVertex2f(4.0, -3.20);
        glVertex2f(5.0, -6.90);
        glVertex2f(-5.0, -6.90);
        glEnd();

        //head
        glColor3f(0.0, 0.0, 0.0);
        drawCircle(-23.0, -24.70, 0.5,100);
        drawCircle(-18.0, -14.0, 0.5,100);
        drawCircle(-13.10, -5.30, 0.5,100);
        drawCircle(23.0, -24.70, 0.5,100);
        drawCircle(18.0, -14.0, 0.5,100);
        drawCircle(13.10, -5.30, 0.5,100);
        drawCircle(-0.30, -24.80, 0.5,100);
        drawCircle(-0.30, -14.10, 0.5,100);
        drawCircle(-0.30, -5.30, 0.5,100);

         glLineWidth(25.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 0.20, 0.3);
        glVertex2f(-23.0, -25.20);
        glVertex2f(-23.0, -26.50);
        glVertex2f(-18.0, -14.50);
        glVertex2f(-18.0, -17.0);
        glVertex2f(-13.10, -5.80);
        glVertex2f(-13.10, -9.30);
        glVertex2f(23.0, -25.20);
        glVertex2f(23.0, -28.70);
        glVertex2f(18.0, -14.50);
        glVertex2f(18.0, -17.0);
         glVertex2f(13.10, -5.80);
        glVertex2f(13.10, -9.30);
        glVertex2f(-0.30, -25.30);
        glVertex2f(-0.30, -27.80);
        glVertex2f(-0.30, -14.60);
        glVertex2f(-0.30, -16.10);
        glVertex2f(-0.30, -5.80);
        glVertex2f(-0.30, -8.30);
        glEnd();

        //chair
        glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-24.0, -26.0);
        glVertex2f(-22.0, -26.0);
        glVertex2f(-21.50, -30.0);
        glVertex2f(-24.50, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-19.0, -15.30);
        glVertex2f(-17.0, -15.30);
        glVertex2f(-16.50, -19.0);
        glVertex2f(-19.50, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-14.10, -6.50);
        glVertex2f(-12.30, -6.50);
        glVertex2f(-11.80, -9.50);
        glVertex2f(-14.60, -9.50);
        glEnd();

        //desk
           glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(24.0, -26.0);
        glVertex2f(22.0, -26.0);
        glVertex2f(21.50, -30.0);
        glVertex2f(24.50, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(19.0, -15.30);
        glVertex2f(17.0, -15.30);
        glVertex2f(16.50, -19.0);
        glVertex2f(19.50, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(14.10, -6.50);
        glVertex2f(12.30, -6.50);
        glVertex2f(11.80, -9.50);
        glVertex2f(14.60, -9.50);
        glEnd();

        //desk
             glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.30, -26.0);
        glVertex2f(0.70, -26.0);
        glVertex2f(1.70, -30.0);
        glVertex2f(-2.30, -30.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.20, -15.30);
        glVertex2f(0.60, -15.30);
        glVertex2f(1.60, -19.0);
        glVertex2f(-2.20, -19.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.96, 0.70, 0.20);
        glVertex2f(-1.10, -6.50);
        glVertex2f(0.50, -6.50);
        glVertex2f(1.40, -9.50);
        glVertex2f(-2.00, -9.50);
        glEnd();

         //chair handle
        glLineWidth(4.00);
        glBegin(GL_LINES);
        glColor3f(0.76, 0.30, 0.20);
        glVertex2f(-23.40, -30.0);
        glVertex2f(-24.0, -32.0);
        glVertex2f(-22.50, -30.0);
        glVertex2f(-22.0, -32.0);
        glVertex2f(-18.40, -19.0);
        glVertex2f(-19.10, -21.0);
        glVertex2f(-17.50, -19.0);
        glVertex2f(-16.90, -21.0);
        glVertex2f(-13.70, -9.50);
        glVertex2f(-14.40, -11.50);
        glVertex2f(-12.70, -9.50);
        glVertex2f(-12.10, -11.50);
        glVertex2f(23.40, -30.0);
        glVertex2f(24.0, -32.0);
        glVertex2f(22.50, -30.0);
        glVertex2f(22.0, -32.0);
        glVertex2f(18.40, -19.0);
        glVertex2f(19.10, -21.0);
        glVertex2f(17.50, -19.0);
        glVertex2f(16.90, -21.0);
        glVertex2f(13.70, -9.50);
        glVertex2f(14.30, -11.50);
        glVertex2f(12.80, -9.50);
        glVertex2f(12.30, -11.50);

        //desk
        glVertex2f(0.30, -30.0);
        glVertex2f(0.90, -32.0);
        glVertex2f(-0.90, -30.0);
        glVertex2f(-1.40, -32.0);

        glVertex2f(0.30, -19.0);
        glVertex2f(0.80, -21.0);
        glVertex2f(-0.90, -19.0);
        glVertex2f(-1.30, -21.0);

        glVertex2f(0.20, -9.50);
        glVertex2f(0.70, -11.50);
        glVertex2f(-0.80, -9.50);
        glVertex2f(-1.30, -11.50);
        glEnd();

        ///Text
         glColor3f(1.0f, 1.0f, 0.4f);
         if (isCSEText) {
        renderBitmapString(-6.0f, 16.0f, GLUT_BITMAP_HELVETICA_18, "Computer Science And Engineering");
        renderBitmapString(-3.0f, 13.0f, GLUT_BITMAP_HELVETICA_18, "Computer Graphics");
        renderBitmapString(-5.0f, 10.0f, GLUT_BITMAP_HELVETICA_12, "C++, Open GL, C, JAVA, Python, AI, C#");
    }
    else if (isScienceText) {
        renderBitmapString(-4.0f, 16.0f, GLUT_BITMAP_HELVETICA_12, "Higher Secondary School-HSC");
        renderBitmapString(-2.0f, 13.0f, GLUT_BITMAP_HELVETICA_18, "SCIENCE");
        renderBitmapString(-6.0f, 10.0f, GLUT_BITMAP_HELVETICA_12, "Physics, Chemistry, Biology, ICT, Higher Math");
    }
    else {
        renderBitmapString(-4.50f, 16.0f, GLUT_BITMAP_HELVETICA_12, "Play , Learn And Fun- Primary to SSC");
        renderBitmapString(-3.0f, 13.0f, GLUT_BITMAP_HELVETICA_18, "Rain rain go away...");
        renderBitmapString(-5.0f, 10.0f, GLUT_BITMAP_HELVETICA_12, "Bangla, English, Math, BGS, Islam, Science");
    }

    ///Faculty
    glPushMatrix();
    glTranslatef(moveF1, 0.0f, 0.0f);
        //madam
        glLineWidth(8.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.90);
        glVertex2f(-10.80, 9.10);
        glVertex2f(-10.0, 10.10);

        glVertex2f(-11.50, 0.0);
        glVertex2f(-12.00, 0.0);
        glVertex2f(-10.50, 0.0);
        glVertex2f(-11.00, 0.0);
        glEnd();
        glLineWidth(2.00);
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.70);
        glVertex2f(-10.0, 10.10);
        glVertex2f(-5.0, 14.10);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.2, 0.8, 1.0);
        glVertex2f(-10.80, 11.10);
        glVertex2f(-12.0, 11.10);
        glVertex2f(-12.40, 7.0);
        glVertex2f(-10.40, 7.0);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.7);
        glVertex2f(-12.20, 7.0);
        glVertex2f(-11.10, 7.0);
        glVertex2f(-11.60, 0.0);
        glVertex2f(-12.00, 0.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.55, 0.7);
        glVertex2f(-12.0, 7.0);
        glVertex2f(-10.70, 7.0);
        glVertex2f(-10.60, 0.0);
        glVertex2f(-11.00, 0.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        drawCircle(-11.50, 12.50,0.70,100);
        drawCircle(-11.50, 11.50,0.40,100);
        glEnd();
    glPopMatrix();
    glutSwapBuffers();
 }



///display function for transactionMiddle
void transactionMiddle() {
    glClear(GL_COLOR_BUFFER_BIT);

 /// SKY
   glBegin(GL_QUADS);
    glColor3f(0.4f, 0.5f, 1.0f);
    glVertex2f(-35.0, 35.0);
    glVertex2f(35.0, 35.0);
    glColor3f(0.6f, 1.0f, 1.0f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, 0.0);
    glEnd();

    /// SUN
    if (timeOfDay < 0.5f) {
        glColor3f(1.0f, 1.0f, 0.0f); // Bright yellow for the sun
        drawCircle(10.40f, 27.00f - 10.0f * timeOfDay, 0.8f, 100);
    }
    /// MOON
    if (timeOfDay >= 0.5f) {
        glColor3f(0.9f, 0.9f, 0.9f);
        drawCircle(10.40f, 25.00f + 10.0f * (timeOfDay - 0.5f), 0.8f, 100);
    }
    /// STARS
    if (timeOfDay >= 0.5f) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glPointSize(2.0f);
        glBegin(GL_POINTS);
        glVertex2f(-15.0f, 30.0f);
        glVertex2f(-10.0f, 25.0f);
        glVertex2f(0.0f, 28.0f);
        glVertex2f(5.0f, 32.0f);
        glVertex2f(20.0f, 27.0f);
        glEnd();
    }
    /// Sea
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.9f, 1.0f);
    glVertex2f(-35.0, 19.0);
    glVertex2f(35.0, 19.0);
    glColor3f(0.678f, 0.947f, 0.902f);
    glVertex2f(35.0, 9.0);
    glVertex2f(-35.0, 15.0);
    glEnd();

     ///boat and bird and cloud
    drawBoat1();
    drawCloudAndBird();

    ///green middle ground
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.9f, 0.3f);
    glVertex2f(-35.0, 15.0);
    glVertex2f(35.0, 9.0);
    glColor3f(0.0f, 0.692f, 0.0f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, -1.0);
    glEnd();

    ///tree
    glLineWidth(5.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.3, 0.2);
     glVertex2f(-30.0, 12.30);
     glVertex2f(-30.00, -2.0);
     glVertex2f(-29.0, 13.00);
     glVertex2f(-29.00, -2.0);
     glVertex2f(-28.0, 12.30);
     glVertex2f(-28.00, -2.0);
     glEnd();

     glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
     glVertex2f(-30.50, 12.30);
     glVertex2f(-29.50, 12.0);
    glVertex2f(-30.00, 14.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
    glVertex2f(-28.30, 13.0);
    glVertex2f(-29.70, 13.0);
    glVertex2f(-29.0, 15.0);
    glEnd();

   glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
     glVertex2f(-28.70, 12.30);
     glVertex2f(-27.50, 12.0);
    glVertex2f(-28.00, 14.0);
    glEnd();

    ///tree 02
    glLineWidth(5.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.3, 0.2);
     glVertex2f(-20.0, 11.30);
     glVertex2f(-20.00, -2.0);
     glVertex2f(-19.0, 12.00);
     glVertex2f(-19.00, -2.0);
     glVertex2f(-18.0, 11.30);
     glVertex2f(-18.00, -2.0);
     glEnd();

     glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
     glVertex2f(-20.50, 11.30);
     glVertex2f(-19.50, 11.0);
    glVertex2f(-20.00, 13.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
    glVertex2f(-18.30, 12.0);
    glVertex2f(-19.70, 12.0);
    glVertex2f(-19.0, 14.0);
    glEnd();

   glBegin(GL_TRIANGLES);
    glColor3f(0.2, 0.7, 0.2);
     glVertex2f(-18.70, 11.30);
     glVertex2f(-17.50, 11.0);
    glVertex2f(-18.00, 13.0);
    glEnd();

      ///half  ground
     glBegin(GL_QUADS);
    glColor3f(0.7f, 0.9f, 0.4f);
    glVertex2f(-35.0, 12.0);
    glVertex2f(35.0, 3.0);
    glColor3f(0.0f, 0.692f, 0.0f);
    glVertex2f(35.0, 0.0);
    glVertex2f(-35.0, -1.0);
    glEnd();

    ///DESERT
    glBegin(GL_QUADS);
        glColor3f(0.96, 0.80, 0.41);
        glVertex2f(-35.0, -1.0);
    glVertex2f(35.0, 0.0);
        glColor3f(0.89, 0.70, 0.41);
glColor3f(0.98, 0.89, 0.65);
    glVertex2f(35.0, -35.0);
    glVertex2f(-35.0, -35.0);
    glEnd();

    ///PYRAMYD
//1ST
 glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.6, 0.2);
    glVertex2f(-35.30f, -3.0f);
    glVertex2f(-26.2f, -3.0f);
    glVertex2f(-31.0f, 9.0f);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(0.7, 0.5, 0.2);
    glVertex2f(-26.2f, -3.0f);
    glVertex2f(-23.0f, -3.0f);
    glVertex2f(-31.0f, 9.0f);
    glEnd();
//2ND
     glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.6, 0.2);
    glVertex2f(-20.50f, -3.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-16.0f, 9.0f);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(0.7, 0.5, 0.2);
    glVertex2f(-12.f, -3.0f);
    glVertex2f(-10.0f, -3.0f);
    glVertex2f(-16.0f, 9.0f);
    glEnd();
//3RD
    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.6, 0.2);
    glVertex2f(-30.50f, -6.0f);
    glVertex2f(-18.2f, -6.0f);
    glVertex2f(-24.0f, 12.0f);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(0.7, 0.5, 0.2);
    glVertex2f(-18.2f, -6.0f);
    glVertex2f(-15.0f, -6.0f);
    glVertex2f(-24.0f, 12.0f);
    glEnd();

    //SHADOW OF DESERT
     glBegin(GL_QUADS);
    glColor3f(0.96, 0.88, 0.41);
    glVertex2f(-35.0, -6.0);
    glVertex2f(35.0, -12);
    glColor3f(0.96, 0.70, 0.41);
    glVertex2f(35.0, -35.0);
    glColor3f(0.96, 0.75, 0.41);
    glVertex2f(-35.0, -35.0);
    glEnd();

    ///RAIL WAY STATION
    ///Rail upeer side electic
    glLineWidth(1.30);
    glBegin(GL_LINES);
    glColor3f(0.2, 0.2, 0.2);
     glVertex2f(18.0, 7.0);
     glVertex2f(35.00, 7.0);
     glVertex2f(18.0, 10.0);
     glVertex2f(27.00, 8.0);
    glVertex2f(27.00, 8.0);
    glVertex2f(35.00, 10.0);
    glVertex2f(20.00, 9.52);
    glVertex2f(20.00, 7.0);
    glVertex2f(24.00, 8.52);
    glVertex2f(24.00, 7.0);
    glVertex2f(29.00, 8.52);
    glVertex2f(29.00, 7.0);
    glVertex2f(33.00, 9.52);
    glVertex2f(33.00, 7.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(19.50, 9.00);
     glVertex2f(19.50, -7.50);
     glVertex2f(17.50, -7.50);
    glVertex2f(17.50, 9.00);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.8);
     glVertex2f(19.80, 9.0);
     glVertex2f(17.20, 9.0);
    glVertex2f(17.20, 10.0);
    glVertex2f(19.80, 10.0);
     glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(20.0, 2.0);
    glVertex2f(34.0, 2.00);
    glVertex2f(34.0, -7.0);
    glVertex2f(20.0, -7.0);
    glEnd();
    glLineWidth(6.00);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(17.0, -7.25);
    glVertex2f(19.80, -7.25);
    glVertex2f(16.90, -7.60);
    glVertex2f(20.0, -7.60);
    glColor3f(0.5, 0.5, 0.6);
    glVertex2f(34.60, -7.10);
    glVertex2f(19.40, -7.10);
     glVertex2f(34.80, -7.60);
    glVertex2f(19.20, -7.60);
    glEnd();
    glLineWidth(20.00);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.4);
     glVertex2f(23.50, 4.80);
    glVertex2f(30.50, 4.80);
    glVertex2f(34.0, -1.0);
    glVertex2f(20.0, -1.0);
    glVertex2f(17.50, 6.50);
    glVertex2f(19.50, 6.50);
        glEnd();
    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(24.0, 3.90);
    glVertex2f(24.0, -7.0);
    glVertex2f(30.0, 3.90);
    glVertex2f(30.0, -7.0);
        glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.7, 0.8);
    glVertex2f(19.40, 3.0);
    glVertex2f(34.60, 3.0);
    glVertex2f(34.60, 2.0);
    glVertex2f(19.40, 2.0);
    glEnd();
    glLineWidth(6.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.5, 0.8);
    glVertex2f(19.80, 3.10);
    glVertex2f(34.20, 3.10);
       glVertex2f(19.50, 7.90);
     glVertex2f(17.50, 7.90);
     glVertex2f(19.50, 5.0);
     glVertex2f(17.50, 5.0);
     glVertex2f(19.50, 10.30);
     glVertex2f(17.50, 10.30);
      glVertex2f(19.50, 10.70);
     glVertex2f(17.50, 10.70);
        glEnd();

    ///name of STATION
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(24.90f, 4.70f, GLUT_BITMAP_TIMES_ROMAN_10, "RAILWAY STATION");
    glEnd();
    glColor3f(0.6, 0.6, 0.9);
    drawCircle(27.0, 0.70, 0.3, 100);
        glEnd();

    ///HUMAN1
    glColor3f(0.10, 0.10, 0.10);
    drawCircle(21.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.0, 0.9);
     glVertex2f(21.00, -4.00);
     glVertex2f(21.00, -5.50);
        glEnd();
      glLineWidth(3.00);
       glBegin(GL_LINES);
     glColor3f(0.7, 0.4, 0.4);
     glVertex2f(20.90, -5.50);
     glVertex2f(20.90, -6.85);
     glVertex2f(21.10, -5.50);
     glVertex2f(21.10, -6.85);
        glEnd();

    //HUMAN2
     glColor3f(0.10, 0.10, 0.10);
    drawCircle(22.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
     glVertex2f(22.00, -4.00);
     glVertex2f(22.00, -5.50);
        glEnd();
      glLineWidth(3.00);
       glBegin(GL_LINES);
     glColor3f(1.0, 0.0, 0.0);
     glVertex2f(21.90, -5.50);
     glVertex2f(21.90, -6.85);
     glVertex2f(22.10, -5.50);
     glVertex2f(22.10, -6.85);
        glEnd();
//HUMAN3
 glColor3f(0.10, 0.10, 0.10);
    drawCircle(23.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.7, 1.0);
     glVertex2f(23.00, -4.00);
     glVertex2f(23.00, -5.50);
        glEnd();
      glLineWidth(3.00);
       glBegin(GL_LINES);
     glColor3f(0.3, 0.4, 0.4);
     glVertex2f(22.90, -5.50);
     glVertex2f(22.90, -6.85);
     glVertex2f(23.10, -5.50);
     glVertex2f(23.10, -6.85);
        glEnd();

    //HUMAN4
    glColor3f(0.10, 0.10, 0.10);
    drawCircle(25.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.0, 0.9);
     glVertex2f(25.00, -4.00);
     glVertex2f(25.00, -5.50);
        glEnd();
      glLineWidth(3.00);
       glBegin(GL_LINES);
     glColor3f(0.7, 0.4, 0.4);
     glVertex2f(24.90, -5.50);
     glVertex2f(24.90, -6.85);
     glVertex2f(25.10, -5.50);
     glVertex2f(25.10, -6.85);
        glEnd();

    //HUMAN5
     glColor3f(0.10, 0.10, 0.10);
    drawCircle(27.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
     glVertex2f(27.00, -4.00);
     glVertex2f(27.00, -5.50);
        glEnd();
      glLineWidth(3.00);
       glBegin(GL_LINES);
     glColor3f(1.0, 0.0, 0.0);
     glVertex2f(26.90, -5.50);
     glVertex2f(26.90, -6.85);
     glVertex2f(27.10, -5.50);
     glVertex2f(27.10, -6.85);
        glEnd();
//HUMAN6
 glColor3f(0.10, 0.10, 0.10);
    drawCircle(29.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.7, 1.0);
     glVertex2f(29.00, -4.00);
     glVertex2f(29.00, -5.50);
    glEnd();
      glLineWidth(3.00);
    glBegin(GL_LINES);
     glColor3f(0.3, 0.4, 0.4);
     glVertex2f(28.90, -5.50);
     glVertex2f(28.90, -6.85);
     glVertex2f(29.10, -5.50);
     glVertex2f(29.10, -6.85);
        glEnd();

    //HUMAN7
    glColor3f(0.10, 0.10, 0.10);
    drawCircle(31.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.0, 0.9);
     glVertex2f(31.00, -4.00);
     glVertex2f(31.00, -5.50);
    glEnd();
    glLineWidth(3.00);
    glBegin(GL_LINES);
     glColor3f(0.7, 0.4, 0.4);
     glVertex2f(30.90, -5.50);
     glVertex2f(30.90, -6.85);
     glVertex2f(31.10, -5.50);
     glVertex2f(31.10, -6.85);
        glEnd();

    //HUMAN8
     glColor3f(0.10, 0.10, 0.10);
    drawCircle(32.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
     glVertex2f(32.00, -4.00);
     glVertex2f(32.00, -5.50);
    glEnd();
    glLineWidth(3.00);
    glBegin(GL_LINES);
     glColor3f(1.0, 0.0, 0.0);
     glVertex2f(31.90, -5.50);
     glVertex2f(31.90, -6.85);
     glVertex2f(32.10, -5.50);
     glVertex2f(32.10, -6.85);
    glEnd();
    //HUMAN9
    glColor3f(0.10, 0.10, 0.10);
    drawCircle(33.0, -3.70, 0.2, 1000);
    glEnd();
    glLineWidth(11.00);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.7, 1.0);
    glVertex2f(33.00, -4.00);
    glVertex2f(33.00, -5.50);
    glEnd();
    glLineWidth(3.00);
    glBegin(GL_LINES);
    glColor3f(0.3, 0.4, 0.4);
    glVertex2f(32.90, -5.50);
    glVertex2f(32.90, -6.85);

    glVertex2f(33.10, -5.50);
    glVertex2f(33.10, -6.85);
    glEnd();

    //RAIL LINE
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.6, 0.3);
    glVertex2f(-35.0, -12.80);
    glVertex2f(35.0, -12.80);
    glVertex2f(35.0, -18.20);
    glVertex2f(-35.0, -18.20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.6, 0.3);
    glVertex2f(-35.0, -20.80);
    glVertex2f(35.0, -20.80);
    glVertex2f(35.0, -26.20);
    glVertex2f(-35.0, -26.20);
    glEnd();

    glLineWidth(1.00);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(35.0, -18.20);
    glVertex2f(-35.0, -18.20);
    glVertex2f(35.0, -26.20);
    glVertex2f(-35.0, -26.20);
    glEnd();

    //LINE
    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-35.0, -13.50);
    glVertex2f(35.0, -13.50);
    glVertex2f(35.0, -17.50);
    glVertex2f(-35.0, -17.50);
    glVertex2f(-35.0, -21.50);
    glVertex2f(35.0, -21.5);
    glVertex2f(35.0, -25.50);
    glVertex2f(-35.0, -25.50);

    //MIDDLE LINE

    glVertex2f(-34.0, -13.50);
    glVertex2f(-35.0, -17.50);
    glVertex2f(-33.0, -13.50);
    glVertex2f(-34.0, -17.50);
    glVertex2f(-32.0, -13.50);
    glVertex2f(-33.0, -17.50);
    glVertex2f(-31.0, -13.50);
    glVertex2f(-32.0, -17.50);
    glVertex2f(-30.0, -13.50);
    glVertex2f(-31.0, -17.50);
    glVertex2f(-29.0, -13.50);
    glVertex2f(-30.0, -17.50);
    glVertex2f(-28.0, -13.50);
    glVertex2f(-29.0, -17.50);
    glVertex2f(-27.0, -13.50);
    glVertex2f(-28.0, -17.50);
    glVertex2f(-26.0, -13.50);
    glVertex2f(-27.0, -17.50);
    glVertex2f(-25.0, -13.50);
    glVertex2f(-26.0, -17.50);
    glVertex2f(-24.0, -13.50);
    glVertex2f(-25.0, -17.50);
    glVertex2f(-23.0, -13.50);
    glVertex2f(-24.0, -17.50);
    glVertex2f(-22.0, -13.50);
    glVertex2f(-23.0, -17.50);
    glVertex2f(-21.0, -13.50);
    glVertex2f(-22.0, -17.50);
    glVertex2f(-20.0, -13.50);
    glVertex2f(-21.0, -17.50);
    glVertex2f(-19.0, -13.50);
    glVertex2f(-20.0, -17.50);
    glVertex2f(-18.0, -13.50);
    glVertex2f(-19.0, -17.50);
    glVertex2f(-17.0, -13.50);
    glVertex2f(-18.0, -17.50);
    glVertex2f(-16.0, -13.50);
    glVertex2f(-17.0, -17.50);
    glVertex2f(-15.0, -13.50);
    glVertex2f(-16.0, -17.50);
    glVertex2f(-14.0, -13.50);
    glVertex2f(-15.0, -17.50);
    glVertex2f(-13.0, -13.50);
    glVertex2f(-14.0, -17.50);
    glVertex2f(-12.0, -13.50);
    glVertex2f(-13.0, -17.50);
    glVertex2f(-11.0, -13.50);
    glVertex2f(-12.0, -17.50);
    glVertex2f(-10.0, -13.50);
    glVertex2f(-11.0, -17.50);
    glVertex2f(-9.0, -13.50);
    glVertex2f(-10.0, -17.50);
    glVertex2f(-8.0, -13.50);
    glVertex2f(-9.0, -17.50);
    glVertex2f(-7.0, -13.50);
    glVertex2f(-8.0, -17.50);
    glVertex2f(-6.0, -13.50);
    glVertex2f(-7.0, -17.50);
    glVertex2f(-5.0, -13.50);
    glVertex2f(-6.0, -17.50);
    glVertex2f(-4.0, -13.50);
    glVertex2f(-5.0, -17.50);
    glVertex2f(-3.0, -13.50);
    glVertex2f(-4.0, -17.50);
    glVertex2f(-2.0, -13.50);
    glVertex2f(-3.0, -17.50);
    glVertex2f(-1.0, -13.50);
    glVertex2f(-2.0, -17.50);
    glVertex2f(0.0, -13.50);
    glVertex2f(-1.0, -17.50);
    glVertex2f(1.0, -13.50);
    glVertex2f(0.0, -17.50);
    glVertex2f(2.0, -13.50);
    glVertex2f(1.0, -17.50);
    glVertex2f(3.0, -13.50);
    glVertex2f(2.0, -17.50);
    glVertex2f(4.0, -13.50);
    glVertex2f(3.0, -17.50);
    glVertex2f(5.0, -13.50);
    glVertex2f(4.0, -17.50);
    glVertex2f(6.0, -13.50);
    glVertex2f(5.0, -17.50);
    glVertex2f(7.0, -13.50);
    glVertex2f(6.0, -17.50);
    glVertex2f(8.0, -13.50);
    glVertex2f(7.0, -17.50);
    glVertex2f(9.0, -13.50);
    glVertex2f(8.0, -17.50);
    glVertex2f(10.0, -13.50);
    glVertex2f(9.0, -17.50);
    glVertex2f(11.0, -13.50);
    glVertex2f(10.0, -17.50);
    glVertex2f(12.0, -13.50);
    glVertex2f(11.0, -17.50);
    glVertex2f(13.0, -13.50);
    glVertex2f(12.0, -17.50);
    glVertex2f(14.0, -13.50);
    glVertex2f(13.0, -17.50);
    glVertex2f(15.0, -13.50);
    glVertex2f(14.0, -17.50);
    glVertex2f(16.0, -13.50);
    glVertex2f(15.0, -17.50);
    glVertex2f(17.0, -13.50);
    glVertex2f(16.0, -17.50);
    glVertex2f(18.0, -13.50);
    glVertex2f(17.0, -17.50);
    glVertex2f(19.0, -13.50);
    glVertex2f(18.0, -17.50);
    glVertex2f(20.0, -13.50);
    glVertex2f(19.0, -17.50);
    glVertex2f(21.0, -13.50);
    glVertex2f(20.0, -17.50);
    glVertex2f(22.0, -13.50);
    glVertex2f(21.0, -17.50);
    glVertex2f(23.0, -13.50);
    glVertex2f(22.0, -17.50);
    glVertex2f(24.0, -13.50);
    glVertex2f(23.0, -17.50);
    glVertex2f(25.0, -13.50);
    glVertex2f(24.0, -17.50);
    glVertex2f(26.0, -13.50);
    glVertex2f(25.0, -17.50);
    glVertex2f(27.0, -13.50);
    glVertex2f(26.0, -17.50);
    glVertex2f(28.0, -13.50);
    glVertex2f(27.0, -17.50);
    glVertex2f(29.0, -13.50);
    glVertex2f(28.0, -17.50);
    glVertex2f(30.0, -13.50);
    glVertex2f(29.0, -17.50);
    glVertex2f(31.0, -13.50);
    glVertex2f(30.0, -17.50);
    glVertex2f(32.0, -13.50);
    glVertex2f(31.0, -17.50);
    glVertex2f(33.0, -13.50);
    glVertex2f(32.0, -17.50);
    glVertex2f(34.0, -13.50);
    glVertex2f(33.0, -17.50);
    glVertex2f(35.0, -13.50);
    glVertex2f(34.0, -17.50);

    //SECOND MID LINE
    glVertex2f(-34.0, -21.50);
    glVertex2f(-35.0, -25.50);
    glVertex2f(-33.0, -21.50);
    glVertex2f(-34.0, -25.50);
    glVertex2f(-32.0, -21.50);
    glVertex2f(-33.0, -25.50);
    glVertex2f(-31.0, -21.50);
    glVertex2f(-32.0, -25.50);
    glVertex2f(-30.0, -21.50);
    glVertex2f(-31.0, -25.50);
    glVertex2f(-29.0, -21.50);
    glVertex2f(-30.0, -25.50);
    glVertex2f(-28.0, -21.50);
    glVertex2f(-29.0, -25.50);
    glVertex2f(-27.0, -21.50);
    glVertex2f(-28.0, -25.50);
    glVertex2f(-26.0, -21.50);
    glVertex2f(-27.0, -25.50);
    glVertex2f(-25.0, -21.50);
    glVertex2f(-26.0, -25.50);
    glVertex2f(-24.0, -21.50);
    glVertex2f(-25.0, -25.50);
    glVertex2f(-23.0, -21.50);
    glVertex2f(-24.0, -25.50);
    glVertex2f(-22.0, -21.50);
    glVertex2f(-23.0, -25.50);
    glVertex2f(-21.0, -21.50);
    glVertex2f(-22.0, -25.50);
    glVertex2f(-20.0, -21.50);
    glVertex2f(-21.0, -25.50);
    glVertex2f(-19.0, -21.50);
    glVertex2f(-20.0, -25.50);
    glVertex2f(-18.0, -21.50);
    glVertex2f(-19.0, -25.50);
    glVertex2f(-17.0, -21.50);
    glVertex2f(-18.0, -25.50);
    glVertex2f(-16.0, -21.50);
    glVertex2f(-17.0, -25.50);
    glVertex2f(-15.0, -21.50);
    glVertex2f(-16.0, -25.50);
    glVertex2f(-14.0, -21.50);
    glVertex2f(-15.0, -25.50);
    glVertex2f(-13.0, -21.50);
    glVertex2f(-14.0, -25.50);
    glVertex2f(-12.0, -21.50);
    glVertex2f(-13.0, -25.50);
    glVertex2f(-11.0, -21.50);
    glVertex2f(-12.0, -25.50);
    glVertex2f(-10.0, -21.50);
    glVertex2f(-11.0, -25.50);
    glVertex2f(-9.0, -21.50);
    glVertex2f(-10.0, -25.50);
    glVertex2f(-8.0, -21.50);
    glVertex2f(-9.0, -25.50);
    glVertex2f(-7.0, -21.50);
    glVertex2f(-8.0, -25.50);
    glVertex2f(-6.0, -21.50);
    glVertex2f(-7.0, -25.50);
    glVertex2f(-5.0, -21.50);
    glVertex2f(-6.0, -25.50);
    glVertex2f(-4.0, -21.50);
    glVertex2f(-5.0, -25.50);
    glVertex2f(-3.0, -21.50);
    glVertex2f(-4.0, -25.50);
    glVertex2f(-2.0, -21.50);
    glVertex2f(-3.0, -25.50);
    glVertex2f(-1.0, -21.50);
    glVertex2f(-2.0, -25.50);
    glVertex2f(0.0, -21.50);
    glVertex2f(-1.0, -25.50);
    glVertex2f(1.0, -21.50);
    glVertex2f(0.0, -25.50);
    glVertex2f(2.0, -21.50);
    glVertex2f(1.0, -25.50);
    glVertex2f(3.0, -21.50);
    glVertex2f(2.0, -25.50);
    glVertex2f(4.0, -21.50);
    glVertex2f(3.0, -25.50);
    glVertex2f(5.0, -21.50);
    glVertex2f(4.0, -25.50);
    glVertex2f(6.0, -21.50);
    glVertex2f(5.0, -25.50);
    glVertex2f(7.0, -21.50);
    glVertex2f(6.0, -25.50);
    glVertex2f(8.0, -21.50);
    glVertex2f(7.0, -25.50);
    glVertex2f(9.0, -21.50);
    glVertex2f(8.0, -25.50);
    glVertex2f(10.0, -21.50);
    glVertex2f(9.0, -25.50);
    glVertex2f(11.0, -21.50);
    glVertex2f(10.0, -25.50);
    glVertex2f(12.0, -21.50);
    glVertex2f(11.0, -25.50);
    glVertex2f(13.0, -21.50);
    glVertex2f(12.0, -25.50);
    glVertex2f(14.0, -21.50);
    glVertex2f(13.0, -25.50);
    glVertex2f(15.0, -21.50);
    glVertex2f(14.0, -25.50);
    glVertex2f(16.0, -21.50);
    glVertex2f(15.0, -25.50);
    glVertex2f(17.0, -21.50);
    glVertex2f(16.0, -25.50);
    glVertex2f(18.0, -21.50);
    glVertex2f(17.0, -25.50);
    glVertex2f(19.0, -21.50);
    glVertex2f(18.0, -25.50);
    glVertex2f(20.0, -21.50);
    glVertex2f(19.0, -25.50);
    glVertex2f(21.0, -21.50);
    glVertex2f(20.0, -25.50);
    glVertex2f(22.0, -21.50);
    glVertex2f(21.0, -25.50);
    glVertex2f(23.0, -21.50);
    glVertex2f(22.0, -25.50);
    glVertex2f(24.0, -21.50);
    glVertex2f(23.0, -25.50);
    glVertex2f(25.0, -21.50);
    glVertex2f(24.0, -25.50);
    glVertex2f(26.0, -21.50);
    glVertex2f(25.0, -25.50);
    glVertex2f(27.0, -21.50);
    glVertex2f(26.0, -25.50);
    glVertex2f(28.0, -21.50);
    glVertex2f(27.0, -25.50);
    glVertex2f(29.0, -21.50);
    glVertex2f(28.0, -25.50);
    glVertex2f(30.0, -21.50);
    glVertex2f(29.0, -25.50);
    glVertex2f(31.0, -21.50);
    glVertex2f(30.0, -25.50);
    glVertex2f(32.0, -21.50);
    glVertex2f(31.0, -25.50);
    glVertex2f(33.0, -21.50);
    glVertex2f(32.0, -25.50);
    glVertex2f(34.0, -21.50);
    glVertex2f(33.0, -25.50);
    glVertex2f(35.0, -21.50);
    glVertex2f(34.0, -25.50);
    glEnd();

    ///TRAIN 1
    glPushMatrix();
    glTranslatef(moveT2, 0.0f, 0.0f);
    glPushMatrix();

    glLineWidth(5.00);
    glBegin(GL_LINES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-32.00, -14.50);
    glVertex2f(18.00, -14.5);
    glVertex2f(-32.00, -16.00);
    glVertex2f(18.00, -16.00);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    drawCircle(-29.0, -16.50, 0.95,100);
    drawCircle(-26.90, -16.70, 0.75,100);
    drawCircle(-18.90, -16.50, 0.95,100);
    drawCircle(-21.0, -16.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(-32.0, -10.0);
    glVertex2f(-16.0, -10.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(-16.0, -16.40);
    glVertex2f(-32.0, -16.40);
    glEnd();

   //TRAIN
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(-12.0, -16.50, 0.95,100);
    drawCircle(-9.90, -16.70, 0.75,100);
    drawCircle(-1.90, -16.50, 0.95,100);
    drawCircle(-4.0, -16.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(-15.0, -10.0);
    glVertex2f(1.0, -10.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(1.0, -16.40);
    glVertex2f(-15.0, -16.40);
    glEnd();

   //TRAIN
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(15.20, -16.50, 0.95,100);
    drawCircle(13.10, -16.70, 0.75,100);
    drawCircle(4.70, -16.50, 0.95,100);
    drawCircle(6.80, -16.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(18.0, -10.0);
    glVertex2f(2.0, -10.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(2.0, -16.40);
    glVertex2f(18.0, -16.40);
    glEnd();
    //FRONT SIDE
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(18.0, -10.0);
    glVertex2f(19.0, -13.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(19.0, -16.40);
    glVertex2f(18.0, -16.40);
    glEnd();

    //DESIGN
    glColor3f(1.0, 1.0, 0.4);
    drawCircle(16.80, -15.0, 0.15, 100);
    drawCircle(17.50, -15.0, 0.15, 100);
    drawCircle(18.20, -15.0, 0.15, 100);

    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.4);
    glVertex2f(-32.00, -10.30);
    glVertex2f(-16.00, -10.30);
    glVertex2f(-15.00, -10.30);
    glVertex2f(1.00, -10.30);
    glVertex2f(2.00, -10.30);
    glVertex2f(17.90, -10.30);
    glVertex2f(17.90, -10.30);
    glVertex2f(18.80, -13.0);
    glVertex2f(18.80, -13.0);
    glVertex2f(18.80, -16.30);
    glVertex2f(12.0, -10.30);
    glVertex2f(12.0, -16.40);
    glVertex2f(8.0, -10.30);
    glVertex2f(8.0, -16.40);
    glVertex2f(-5.0, -10.30);
    glVertex2f(-5.0, -16.40);
    glVertex2f(-9.0, -10.30);
    glVertex2f(-9.0, -16.40);
    glVertex2f(-22.0, -10.30);
    glVertex2f(-22.0, -16.40);
    glVertex2f(-26.0, -10.30);
    glVertex2f(-26.0, -16.40);
    glEnd();

    //WINDOW
     glLineWidth(18.00);
     glBegin(GL_LINES);
     glColor3f(0.8, 0.9, 1.0);
     glVertex2f(16.00, -11.50);
     glVertex2f(16.00, -13.50);
     glVertex2f(14.50, -11.50);
     glVertex2f(14.50, -13.50);
     glVertex2f(13.00, -11.50);
     glVertex2f(13.00, -13.50);
     glVertex2f(9.50, -11.30);
     glVertex2f(9.50, -16.00);
     glVertex2f(10.50, -11.30);
     glVertex2f(10.50, -16.00);
     glVertex2f(7.0, -11.50);
     glVertex2f(7.0, -13.50);
     glVertex2f(5.50, -11.50);
     glVertex2f(5.50, -13.50);
     glVertex2f(4.0, -11.50);
     glVertex2f(4.0, -13.50);
     glVertex2f(-1.00, -11.50);
     glVertex2f(-1.00, -13.50);
     glVertex2f(-2.50, -11.50);
     glVertex2f(-2.50, -13.50);
     glVertex2f(-4.00, -11.50);
     glVertex2f(-4.0, -13.50);
     glVertex2f(-6.50, -11.30);
     glVertex2f(-6.50, -16.00);
     glVertex2f(-7.50, -11.30);
     glVertex2f(-7.50, -16.00);
     glVertex2f(-10.00, -11.50);
     glVertex2f(-10.00, -13.50);
     glVertex2f(-11.50, -11.50);
     glVertex2f(-11.50, -13.50);
     glVertex2f(-13.0, -11.50);
     glVertex2f(-13.0, -13.50);
     glVertex2f(-18.00, -11.50);
     glVertex2f(-18.00, -13.50);
     glVertex2f(-19.50, -11.50);
     glVertex2f(-19.50, -13.50);
     glVertex2f(-21.00, -11.50);
     glVertex2f(-21.0, -13.50);
     glVertex2f(-23.50, -11.30);
     glVertex2f(-23.50, -16.00);
     glVertex2f(-24.50, -11.30);
     glVertex2f(-24.50, -16.00);
     glVertex2f(-27.00, -11.50);
     glVertex2f(-27.00, -13.50);
     glVertex2f(-28.50, -11.50);
     glVertex2f(-28.50, -13.50);
     glVertex2f(-30.0, -11.50);
     glVertex2f(-30.0, -13.50);
     glEnd();
     glPopMatrix();
     glPopMatrix();

    ///TRAIN 2
    glPushMatrix();
    glTranslatef(moveT1, 0.0f, 0.0f);
    glPushMatrix();

    //TRAIN
     glLineWidth(5.00);
     glBegin(GL_LINES);
     glColor3f(0.3, 0.3, 0.3);
     glVertex2f(-32.00, -22.50);
     glVertex2f(18.00, -22.5);
     glVertex2f(-32.00, -24.00);
     glVertex2f(18.00, -24.00);
     glEnd();

    glColor3f(0.2, 0.2, 0.2);
    drawCircle(-29.0, -24.50, 0.95,100);
    drawCircle(-26.90, -24.70, 0.75,100);
    drawCircle(-18.90, -24.50, 0.95,100);
    drawCircle(-21.0, -24.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.2f, 0.7f);
    glVertex2f(-32.0, -18.0);
    glVertex2f(-16.0, -18.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(-16.0, -24.40);
    glVertex2f(-32.0, -24.40);
    glEnd();
    //BEHIND SIDE
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.2f, 0.7f);
    glVertex2f(-32.0, -18.0);
    glVertex2f(-33.0, -21.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(-33.0, -24.40);
    glVertex2f(-32.0, -24.40);
    glEnd();

   //TRAIN
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(-12.0, -24.50, 0.95,100);
    drawCircle(-9.90, -24.70, 0.75,100);
    drawCircle(-1.90, -24.50, 0.95,100);
    drawCircle(-4.0, -24.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.2f, 0.7f);
    glVertex2f(-15.0, -18.0);
    glVertex2f(1.0, -18.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(1.0, -24.40);
    glVertex2f(-15.0, -24.40);
    glEnd();

    //TRAIN
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(15.20, -24.50, 0.95,100);
    drawCircle(13.10, -24.70, 0.75,100);
    drawCircle(4.70, -24.50, 0.95,100);
    drawCircle(6.80, -24.70, 0.75,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.2f, 0.7f);
    glVertex2f(18.0, -18.0);
    glVertex2f(2.0, -18.0);
    glColor3f(0.45f, 0.45f, 0.45f);
    glVertex2f(2.0, -24.40);
    glVertex2f(18.0, -24.40);
    glEnd();

   //DESIGN
    glColor3f(1.0, 1.0, 0.4);
   drawCircle(-30.80, -23.0, 0.20, 100);
   drawCircle(-31.50, -23.0, 0.20, 100);
   drawCircle(-32.20, -23.0, 0.20, 100);

    glLineWidth(2.00);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.4);
    glVertex2f(-31.80, -18.30);
    glVertex2f(-16.00, -18.30);
    glVertex2f(-15.00, -18.30);
    glVertex2f(1.00, -18.30);
    glVertex2f(2.00, -18.30);
    glVertex2f(18.0, -18.30);
    glVertex2f(-31.80, -18.30);
    glVertex2f(-32.80, -21.0);
    glVertex2f(-32.80, -21.0);
    glVertex2f(-32.80, -24.30);
    glVertex2f(12.0, -18.30);
    glVertex2f(12.0, -24.40);
    glVertex2f(8.0, -18.30);
    glVertex2f(8.0, -24.40);
    glVertex2f(-5.0, -18.30);
    glVertex2f(-5.0, -24.40);
    glVertex2f(-9.0, -18.30);
    glVertex2f(-9.0, -24.40);
    glVertex2f(-22.0, -18.30);
    glVertex2f(-22.0, -24.40);
    glVertex2f(-26.0, -18.30);
    glVertex2f(-26.0, -24.40);
    glEnd();

    //WINDOW
    glLineWidth(18.00);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.9, 1.0);
     glVertex2f(16.00, -19.50);
     glVertex2f(16.00, -21.50);

     glVertex2f(14.50, -19.50);
     glVertex2f(14.50, -21.50);
     glVertex2f(13.00, -19.50);
     glVertex2f(13.00, -21.50);
     glVertex2f(9.50, -19.30);
     glVertex2f(9.50, -24.00);
     glVertex2f(10.50, -19.30);
     glVertex2f(10.50, -24.00);
     glVertex2f(7.0, -19.50);
     glVertex2f(7.0, -21.50);
     glVertex2f(5.50, -19.50);
     glVertex2f(5.50, -21.50);
     glVertex2f(4.0, -19.50);
     glVertex2f(4.0, -21.50);
     glVertex2f(-1.00, -19.50);
     glVertex2f(-1.00, -21.50);
     glVertex2f(-2.50, -19.50);
     glVertex2f(-2.50, -21.50);
     glVertex2f(-4.00, -19.50);
     glVertex2f(-4.0, -21.50);
     glVertex2f(-6.50, -19.30);
     glVertex2f(-6.50, -24.00);
     glVertex2f(-7.50, -19.30);
     glVertex2f(-7.50, -24.00);
     glVertex2f(-10.00, -19.50);
     glVertex2f(-10.00, -21.50);
     glVertex2f(-11.50, -19.50);
     glVertex2f(-11.50, -21.50);
     glVertex2f(-13.0, -19.50);
     glVertex2f(-13.0, -21.50);
     glVertex2f(-18.00, -19.50);
     glVertex2f(-18.00, -21.50);
     glVertex2f(-19.50, -19.50);
     glVertex2f(-19.50, -21.50);
     glVertex2f(-21.00, -19.50);
     glVertex2f(-21.0, -21.50);
     glVertex2f(-23.50, -19.30);
     glVertex2f(-23.50, -24.00);
     glVertex2f(-24.50, -19.30);
     glVertex2f(-24.50, -24.00);
     glVertex2f(-27.00, -19.50);
     glVertex2f(-27.00, -21.50);
     glVertex2f(-28.50, -19.50);
     glVertex2f(-28.50, -21.50);
     glVertex2f(-30.0, -19.50);
     glVertex2f(-30.0, -21.50);
        glEnd();
    glPopMatrix();
    glPopMatrix();

    ///Text
     glColor3f(0.6f, 0.0f, 0.3f);
    if (showTitle) {
                renderBitmapString(-7.0f, -6.0f, GLUT_BITMAP_HELVETICA_18, "\"The Journey of Education : From School to University\"");
                renderBitmapString(0.0f, -3.0f, GLUT_BITMAP_HELVETICA_12, "\"Welcome To Project\"");
                renderBitmapString(-33.0f, 32.0f, GLUT_BITMAP_HELVETICA_18, "\"The Journey of Education : From School to University\"");
                renderBitmapString(-33.0f, 29.5f, GLUT_BITMAP_HELVETICA_12, "Course Faculty: Noboranjan Dey");
                renderBitmapString(-33.0f, 27.5f, GLUT_BITMAP_HELVETICA_12, "Developed By:");
                renderBitmapString(-33.0f, 25.5f, GLUT_BITMAP_HELVETICA_12, "Naznin Akter Roshmny");
                renderBitmapString(-33.0f, 23.5f, GLUT_BITMAP_HELVETICA_12, "22-46092-1");

            }
    if (showThankYou) {
                renderBitmapString(-8.0f, -5.0f, GLUT_BITMAP_HELVETICA_18, "\"Go confidently in the direction of your dreams.\"");
                renderBitmapString(-4.0f, -7.0f, GLUT_BITMAP_HELVETICA_18, "\"Live the life you have imagined.\"");
                renderBitmapString(0.0f, -2.50f, GLUT_BITMAP_HELVETICA_12, "\"Thank You.\"");

            }
            if (showTransitionText) {
    if (transitionType == 1){
                renderBitmapString(-3.0f, -7.0f, GLUT_BITMAP_HELVETICA_12, "\"School days fade, and college dreams take flight.\"");
                renderBitmapString(0.0f, -3.50f, GLUT_BITMAP_HELVETICA_18, "\"School to College.\"");
   } else if (transitionType == 2){
                renderBitmapString(-4.0f, -7.0f, GLUT_BITMAP_HELVETICA_12, "\"Leaving behind college memories, embracing university opportunities.\"");
                renderBitmapString(0.0f, -3.50f, GLUT_BITMAP_HELVETICA_18, "\"College to University.\"");
   }

            }
glutSwapBuffers();
 }


///Timer Function
///cloud
//cloud 01
    void updateC(int value)
{
    if(moveC > +70)
    {
        moveC = -43;
    }
    moveC += 0.15;

    glutTimerFunc(50, updateC, 0);
    glutPostRedisplay();
}
//cloud 02
    void updateC1(int value)
{
    if(moveC1 < -25.0)
    {
        moveC1 = 0;
    }
    moveC1 -= 0.15;

    glutTimerFunc(30, updateC1, 0);
    glutPostRedisplay();
}
//cloud 03
    void updateC2(int value)
{
    if(moveC2 > 25.0)
    {
        moveC2 = 0;
    }
    moveC2 += 0.15;

    glutTimerFunc(30, updateC2, 0);
    glutPostRedisplay();
}
///faculty
    void updateF1(int value) {
    if (moveRight) {
        if (moveF1 > 12.0f) {
            moveRight = false;
        }
        moveF1 += 0.05f;
    } else {
        if (moveF1 < -2.0f) {
            moveRight = true;
        }
        moveF1 -= 0.05f;
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateF1, 0);
}
///bus 01
    void updateW(int value)
{
     if (isRightPaused) {
        glutTimerFunc(10, updateW, 0);
        return;
    }
    if(moveW > 50)
    {
        moveW = -35;
    }
    moveW += 0.16;

    glutTimerFunc(20, updateW, 0);
    glutPostRedisplay();
}
///bus 02
void updateY(int value) {
    if (isLeftPaused) {
        glutPostRedisplay();
        glutTimerFunc(10, updateY, 0);
        return;
    }
    moveY -= 0.16f;
    if (moveY < -50.0f) {
        moveY = 35.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateY, 0);
}
///bird
void updateB(int value)
{
    if (moveB >35)
    {
        moveB = -2.0;
    }
    moveB += 0.15;
    glutTimerFunc(20, updateB, 0);
    glutPostRedisplay();
}
///boat 01
   void updateB1(int value) {
    if (moveB1 < -35.0f) moveB1 = 35.0f;
    moveB1 -= 0.05f;

    glutPostRedisplay();
    glutTimerFunc(40, updateB1, 0);
}
///boat 02
   void updateB2(int value) {
    if (moveB2 > 35.0f) moveB2 = -35.0f;
    moveB2 += 0.05f;

    glutPostRedisplay();
    glutTimerFunc(40, updateB2, 0);
}

///man moving for schoolLife
void updateM2(int value)
{
    if (isVisible)
    {
        if (movingDown)
        {
            moveM2 -= 0.15;
            if (moveM2 <= 16)
            {
                isVisible = false;
                movingDown = false;
                moveM2 = -10.0f;
                glutTimerFunc(12000, updateM2, 0);
                return;
            }
        }
        else
        {
            moveM2 += 0.15;
            if (moveM2 >= 38)
            {
                isVisible = false;
                glutTimerFunc(10000, updateM2, 0);
                movingDown = true;
                return;
            }
        }
    }
    else
    {
        if (movingDown)
        {
            moveM2 = 38;
        }
        else
        {
            moveM2 = -10;
        }
        isVisible = true;
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateM2, 0);
}

///man moving for collegeLife
void updateN(int value)
{
    if (isShown)
    {
        if (slideDown)
        {
            moveN -= 0.15;
            if (moveN <= 8)//back down and stop position
            {
                isShown = false;
                slideDown = false;
                moveN = 10.0f;
                glutTimerFunc(18500, updateN, 0);
                return;
            }
        }
        else
        {
            moveN += 0.15;
            if (moveN >= 25)//up and vanish at 25
            {
                isShown = false;
                glutTimerFunc(18500, updateN, 0);
                slideDown = true;
                return;
            }
        }
    }
    else
    {
        if (slideDown)
        {
            moveN = 25;//start to turn back
        }
        else
        {
            moveN = 8; //start
        }

        isShown = true; //object visible
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateN, 0);
}

///man moving for universityLife
void updateMM2(int value)
{
    if (visible)
    {
        if (down)
        {
            moveMM2 -= 0.03;
            if (moveMM2 <= 8)
            {   extraObjectVisible = false;
                visible = false;
                down = false;
                glutTimerFunc(18000, updateMM2, 0);
                return;
            }
        }
        else
        {
            moveMM2 += 0.15;
            if (moveMM2 >= 30)
            {
                visible = false;
                down = true;
                extraObjectVisible = false;
                glutTimerFunc(18000, updateMM2, 0);
                return;
            }
        }
    }
    else
    {
        if (down)
        {
            extraObjectVisible = true;
            moveMM2 = 30;
            isVisible = false;

        }
        else
        {

        extraObjectVisible = false;

          moveMM2 = 6;
        }

        visible = true;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updateMM2, 0);
}
///college life other man
//man 01
void updateM4(int value) {
    if (moveM4 < -18.0f)
        moveM4 = 4.0f;
    moveM4 -= 0.15;

    glutTimerFunc(90, updateM4, 0);
        glutPostRedisplay();

}
//man 02
void updateM3(int value)
{
    if(moveM3 > 14)
    {
        moveM3 = -12;
    }
    moveM3 += 0.15;
    glutTimerFunc(90, updateM3, 0);
    glutPostRedisplay();
}

///university life other man
//man 01
void updateN4(int value) {
    if (moveN4 < -11.0f)
        moveN4 = 5.0f;
    moveN4 -= 0.15;

    glutTimerFunc(60, updateN4, 0);
        glutPostRedisplay();

}
//man 02
void updateN3(int value)
{
    if(moveN3 > 16)
    {
        moveN3 = 2;
    }
    moveN3 += 0.15;
    glutTimerFunc(60, updateN3, 0);
    glutPostRedisplay();
}
///train moving
//train 01
void updateT1(int value) {
    if (moveT1 < -60.0f)
        moveT1 = +70.0f;
    moveT1 -= 0.10f;

    glutPostRedisplay();
    glutTimerFunc(10, updateT1, 0);
}
//train 02
void updateT2(int value) {
    if (moveT2 > +70.0f)
        moveT2 = -60.0f;
    moveT2 += 0.10f;

    glutPostRedisplay();
    glutTimerFunc(10, updateT2, 0);
}
///sun move
void update(int value) {
    timeOfDay += 0.01f;
    if (timeOfDay > 1.0f) timeOfDay = 0.0f;
    glutPostRedisplay();
    glutTimerFunc(80, update, 0);
}
///turbine move
void timer(int) {
    angle += 2.0f;
    if (angle > 360.0f)
        angle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

///scene handle with button
void renderScene() {
    if (currentScene == 1) {
        transactionMiddle();
    }
        else if (currentScene == 2){
            schoolLife();
    }
    else if (currentScene == 3){
             collegeLife();
    }
    else if (currentScene == 4){
             universityLife();
    }
    else if (currentScene == 5){
             classRoom();
    }
}

///funtion for button handle
void handleKeyPress(unsigned char key, int x, int y) {
    if (key == '1') {
        if (currentScene == 4) {
            showTransitionText = false;
            transitionType = 0;
            showTitle = false;
            showThankYou = true;
        } else if (currentScene == 2) {
            showTitle = false;
            showThankYou = false;
            showTransitionText = true;
            transitionType = 1;
        } else if (currentScene == 3) {
            showTitle = false;
            showThankYou = false;
            showTransitionText = true;
            transitionType = 2;
        } else {
            showThankYou = false;
            isScienceText = false;
            isCSEText= false;
            showTitle = true;
        }
        currentScene = 1;
    } else if (key == '2') {

        currentScene = 2;
    } else if (key == '5') {
        if (currentScene == 2) {
            currentScene = 5;
            isScienceText = false;
        } else if (currentScene == 3) {
            currentScene = 5;
            isScienceText = true;
        } else if (currentScene == 4) {
            currentScene = 5;
            isCSEText = true;
        }
    } else if (key == '3') {
        currentScene = 3;
    } else if (key == '4') {
        currentScene = 4;
    } else if (key == '7') {
        isLeftPaused = true;
    } else if (key == '6') {
        isRightPaused = true;
    }

    glutPostRedisplay();
}

///function for mouse handle
void mouseControl(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        isRightPaused = false;
    }else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isLeftPaused = false;
    }
}

///display auto without button handle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (currentScene) {
        case 1:
            transactionMiddle();
            break;
        case 2:
           schoolLife();
            break;
        case 3:
            collegeLife();
            break;
        case 4:
            universityLife();
            break;
        case 5:
            classRoom();
            break;
        default:
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            renderBitmapString(0.2f, 0.8f, GLUT_BITMAP_HELVETICA_18, "Unknown Scene");
            break;
    }

    glutSwapBuffers();
}
///scene update one by one
void updateScene(int value) {
    static int sceneStep = 0;
    int sceneDuration = 4000;

    switch (sceneStep) {
        //transactionMiddle
        case 0:
            showThankYou=false;
            showTitle=true;
            currentScene = 1;
            sceneDuration=6500;
            sndPlaySound("train.wav", SND_ASYNC);

            break;
         //schoolLife
        case 1:
            currentScene = 2;
            sceneDuration=11500;
            sndPlaySound("bird.wav", SND_ASYNC);

            break;
         //classRoom: Rain Rain
        case 2:
            currentScene = 5;
            isScienceText = false;
            isCSEText=false;
            sceneDuration=7000;
            sndPlaySound("kids-in-classroom.wav", SND_ASYNC);

            break;
        //again schoolLife
        case 3:
            currentScene = 2;
            sceneDuration=13000;
            sndPlaySound("SCHOOL_BELL.wav", SND_ASYNC);

            break;
        //transactionMiddle
        case 4:
            showTitle=false;
            showThankYou=false;
            currentScene = 1;
            showTransitionText = true;
            transitionType = 1;
            sceneDuration=12000;
            sndPlaySound("train.wav", SND_ASYNC);

            break;
        //collegeLife
        case 5:
            currentScene = 3;
            sceneDuration=13000;
            sndPlaySound("bird.wav", SND_ASYNC);

            break;
        //classRoom: Science
        case 6:
            currentScene = 5;
            isCSEText=false;
            isScienceText = true;
            sceneDuration=10700;
            sndPlaySound("classroom-college.wav", SND_ASYNC);

            break;
        //again collegeLife
        case 7:
            currentScene = 3;
            sceneDuration=13000;
            sndPlaySound("SCHOOL_BELL.wav", SND_ASYNC);

            break;
        //transactionMiddle
        case 8:
            showTitle=false;
            showThankYou=false;
            currentScene = 1;
            showTransitionText = true;
            transitionType = 2;
            sceneDuration=12000;
            sndPlaySound("train.wav", SND_ASYNC);

            break;
        //universityLife
        case 9:
            currentScene = 4;
            sceneDuration=12500;
            sndPlaySound("bird.wav", SND_ASYNC);

            break;
        //classRoom: CSE
        case 10:
            currentScene = 5;
            isCSEText = true;
            sceneDuration=15000;
            sndPlaySound("uni_classroom.wav", SND_ASYNC);

            break;
        //again universityLife
        case 11:
            currentScene = 4;
            sceneDuration=27000;
            sndPlaySound("purple.wav", SND_ASYNC);

            break;
        //transactionMiddle
        case 12:
            showTitle=false;
            showThankYou=true;
             showTransitionText = false;
            transitionType = 0;
            currentScene = 1;
            sceneDuration=22000;
            //sndPlaySound("purple.wav", SND_ASYNC);

            break;
        default:
            sceneStep = -1;
            break;
    }

    sceneStep++;
    glutPostRedisplay();
    glutTimerFunc(sceneDuration, updateScene, 0);
}

///co-ordinate(-35.0, 35.0, -35.0, 35.0);
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-35.0, 35.0, -35.0, 35.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("The Journey of Education: From School to University");

    init();
    //cloud
    glutTimerFunc(100, updateC, 1);
    glutTimerFunc(100, updateC1, 1);
    glutTimerFunc(100, updateC2, 1);
    //faculty
    glutTimerFunc(100, updateF1, 1);
    //bus
    glutTimerFunc(7000, updateW, 1);
    glutTimerFunc(7000, updateY, 1);
    //bird
    glutTimerFunc(100, updateB, 0);
    //boat
    glutTimerFunc(100, updateB1, 0);
    glutTimerFunc(100, updateB2, 0);

    //man movement for schoolLife
    glutTimerFunc(7000, updateM2, 1);

    //man movement for collegeLife
    glutTimerFunc(57000, updateN, 1);
    glutTimerFunc(100, updateM4, 0);
    glutTimerFunc(100, updateM3, 0);

    //man movement for universityLife
    glutTimerFunc(106000, updateMM2, 1);
    glutTimerFunc(100, updateN4, 0);
    glutTimerFunc(100, updateN3, 0);
    //sun move
    glutTimerFunc(10000, update, 0);
    //train
    glutTimerFunc(100, updateT1, 0);
    glutTimerFunc(100, updateT2, 0);
    //turbine
    glutTimerFunc(0, timer, 0);


    ///display without button press
     glutDisplayFunc(display);
     glutTimerFunc(500, updateScene, 0);

    glutDisplayFunc(renderScene);
    glutKeyboardFunc(handleKeyPress);
    glutMouseFunc(mouseControl);

    ///sound 01 and 02

    //sndPlaySound("purple.wav", SND_ASYNC);
    //sndPlaySound("Anime.wav", SND_ASYNC);
    glutMainLoop();
    return 0;
}
