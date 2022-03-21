#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>

static int alfa = 0, alfaLumina = 0, alfaMacara = 0;;

void CALLBACK mutaStanga(void)
{
    alfa = alfa - 5;
}
void CALLBACK mutaDreapta(void)
{
    alfa = alfa + 5;
}

void CALLBACK mutaStangaMacara(void)
{
    alfaMacara -= 5;
}
void CALLBACK mutaDreaptaMacara(void)
{
    alfaMacara += 5;
}

void myinit(void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float lightAmbient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    float modelAmbient[] = { 0.4, 0.4, 0.4, 1.0 };
    float localView[] = { 0.0 };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmbient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, localView);


    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    float lightSoursePosition[] = { -5.0, 1.0, -1.0, 1.0 };
    float matAmbient1[] = { 1.0, 0.9, 0.0, 0.0 };
    float matDiffuse1[] = { 1.0, 0.9, 0.0, 0.0 };

    float matAmbient2[] = { 0.2, 0.2, 0.2, 0.0 };
    float matDiffuse2[] = { 0.2, 0.2, 0.2, 0.0 };

    float matAmbient3[] = { 0.5, 0.0, 0.0, 0.0 };
    float matDiffuse3[] = { 0.5, 0.0, 0.0, 0.0 };

    float matAmbient4[] = { 0.0, 0.5, 0.5, 0.0 };
    float matDiffuse4[] = { 0.0, 0.5, 0.5, 0.0 };

    float matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
    float shininess[] = { 100.0 };

    glPushMatrix();
    glRotatef(alfaMacara, 1, 0, 1);

    // SURSA LUMINA
    {
        glPushMatrix();
        glRotatef(alfaLumina, 0, 1, 0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightSoursePosition);
        glTranslatef(-6.0, 2.0, -1.0);
        glColor3f(1.0, 1.0, 0);
        glDisable(GL_LIGHTING);
        auxWireSphere(0.4);
        glEnable(GL_LIGHTING);
        glPopMatrix();
    }

    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    // CABINA
    {
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient4);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse4);
        glTranslatef(0.0, -0.5, -4.0);
        glRotatef(-10, -1.0, 1.0, 0.0);
        glColor3f(0.0, 1.0, 1.0);
        auxSolidCube(1);
    }
    // TURN 1
    {
        GLUquadricObj* quadric = gluNewQuadric();
        glColor3f(1.0, 0.5, 0.0);
        
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse1);
        float baseRadius = 0.3;
        float topRadius = 0.3;
        float height = 1.0;
        float stacks = 25.0;
        float slices = 25.0;

        glTranslatef(0.0, 1.5, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);
        
        gluQuadricDrawStyle(quadric, GLU_LINE);
        gluCylinder(quadric, baseRadius, topRadius, height, stacks, slices);
        glPopMatrix();
        gluDeleteQuadric(quadric);
        glFlush();
    }
    // TURN 2
    {
        GLUquadricObj* quadric = gluNewQuadric();
        glColor3f(1.0, 0.5, 0.0);

        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse1);
        float baseRadius = 0.2;
        float topRadius = 0.2;
        float height = 1.0;
        float stacks = 25.0;
        float slices = 25.0;

        glTranslatef(0.0, 2.5, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);

        gluQuadricDrawStyle(quadric, GLU_LINE);
        gluCylinder(quadric, baseRadius, topRadius, height, stacks, slices);
        glPopMatrix();
        gluDeleteQuadric(quadric);
        glFlush();
    }
    // TURN 3
    {
        GLUquadricObj* quadric = gluNewQuadric();
        glColor3f(1.0, 0.5, 0.0);

        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse1);
        float baseRadius = 0.1;
        float topRadius = 0.1;
        float height = 1.0;
        float stacks = 25.0;
        float slices = 25.0;

        glTranslatef(0.0, 3.5, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);

        gluQuadricDrawStyle(quadric, GLU_LINE);
        gluCylinder(quadric, baseRadius, topRadius, height, stacks, slices);
        glPopMatrix();
        gluDeleteQuadric(quadric);
        glFlush();
    }
    // FIR 1
    {
        glColor3f(0.5, 0.5, 0.5);
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse2);
        glTranslatef(0.0, 3.5, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(-3.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glEnd();
        glPopMatrix();
    }
    // ANSAMBLU FIR 2 + GREUTATE
    glTranslatef(0.0, 3.5, 0.0);
    glRotatef(alfa, 1.0, 0.0, 0.0);
    glRotatef(180, 1.0, 0.0, 0.0);
    // FIR 2
    {
        glColor3f(0.5, 0.5, 0.5);
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse2);
        glTranslatef(-3.0, 3.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, -3.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glEnd();
        glPopMatrix();
    }
    // GREUTATE 
    {
        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient3);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse3);
        glTranslatef(-3.0, 3.0, 0.0);
        auxSolidSphere(0.3);
        glPopMatrix();
    }
    glPopMatrix();
    auxSwapBuffers();
}

void CALLBACK IdleFunction(void)
{
    alfaLumina += 1.0;
    display();
    Sleep(1);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
            +6.0 * (GLfloat)h / (GLfloat)w, -50.0, 50.0);
    else
        glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
            5.0 * (GLfloat)w / (GLfloat)h, -5.0, 6.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGB | AUX_DEPTH);
    auxInitPosition(10, 10, 1200, 800);
    auxInitWindow("Macara");
    myinit();
    auxKeyFunc(AUX_LEFT, mutaStanga);
    auxKeyFunc(AUX_RIGHT, mutaDreapta);
    auxKeyFunc(AUX_UP, mutaStangaMacara);
    auxKeyFunc(AUX_DOWN, mutaDreaptaMacara);
    auxReshapeFunc(myReshape);
    auxIdleFunc(IdleFunction);
    auxMainLoop(display);
    return(0);
}