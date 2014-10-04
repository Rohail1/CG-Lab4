#include<iostream>
#include<math.h>
#include<glut.h>
#include"supportedClass.h"
#include"Turtle.h"

void mydisplay();
void drawArc(Point2, float, float, float);

using namespace std;

Point2 point(100, 150);
Turtle turtle(Point2(0, 0), 90);


void initializewindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("CG Lab4");
}
void registercallbacks()
{
	glutDisplayFunc(mydisplay);
}

void initGL()
{
	glClearColor(0.3, 1.0f, 1.0f, 0.0);
	glColor3f(0, 0, 0);
	glPointSize(4.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glViewport(0, 0, 639, 479);
}


void drawArc(Point2 center, float radius, float startAngle, float Sweep)
{
	const int n = 30;
	float angle = startAngle*3.14159265 / 180;
	float angleInc = Sweep*3.14159265 / (180 * n);
	float cx = center.getX(), cy = center.getY();
	turtle.moveTo(Point2 (cx + radius*cos(angle), cy + radius*sin(angle)));
	for (int k = 1; k < n; k++, angle += angleInc)
	{
		turtle.lineTo(Point2(cx + radius*cos(angle), cy + radius*sin(angle)));
	}
	
}

void ngon(int n, double cx,double cy,double radius, double rotAngle)
{
	if (n < 3)
	{
		return;
	}
	double angle = rotAngle*3.14 / 180;
	double angleInc = 2 * 3.14 / n;
	turtle.moveTo(Point2(radius*cos(angle) + cx, radius*sin(angle) + cy));
	for (int k = 0; k < n; k++)
	{
		angle += angleInc;
		turtle.lineTo(Point2(radius*cos(angle) + cx, radius*sin(angle) + cy));
	}

}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(90, 178, 232);
	drawArc(point, 100, 0, 270);
	ngon(15, 200, 200, 50, 17);
	glFlush();

}

void main(int agrc, char *argv[])
{
	glutInit(&agrc, argv);
	initializewindow();
	registercallbacks();
	initGL();
	glutMainLoop();
}