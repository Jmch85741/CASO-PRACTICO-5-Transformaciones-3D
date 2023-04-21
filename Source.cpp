#include<gl/glut.h>
#include<GL/freeglut.h>
#include<Windows.h>
#include<Math.h>
#include<stdlib.h>

void reshape(int, int);
void time(int);

GLfloat a_pos= 1.0f;
GLfloat b_pos = -1.0f;
GLfloat c_pos = 0.0f;

GLfloat angle = 10;


void Figura()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glLoadIdentity();
	glColor3f(1.0f, 0.0f, 0.0f);

	/*glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);*/

	glVertex3f(c_pos,a_pos,c_pos);
	glVertex3f(b_pos,b_pos,a_pos);
	glVertex3f(a_pos,b_pos,a_pos);


	glColor3f(0.0f, 1.0f, 0.0f);
	/*glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);*/

	glVertex3f(c_pos, a_pos, c_pos);
	glVertex3f(b_pos, b_pos, b_pos);
	glVertex3f(a_pos, b_pos, b_pos);

	glColor3f(0.0f, 0.0f, 1.0f);
	/*glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);*/

	glVertex3f(c_pos, a_pos, c_pos);
	glVertex3f(b_pos, b_pos, b_pos);
	glVertex3f(b_pos, b_pos, a_pos);

	glColor3f(0.0f, 1.0f, 1.0f);
	/*glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);*/

	glVertex3f(c_pos, a_pos, c_pos);
	glVertex3f(a_pos, b_pos, b_pos);
	glVertex3f(a_pos, b_pos, a_pos);


	glEnd();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void reshape2(GLsizei width, GLsizei height)
{
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) /*TECLADO*/
{
	if (key == 'w' or key == 'W') /*ARRIBA*/
	{
		glTranslatef(0.0f,1.0f,0.0f);
		glEnd();
		glFlush();
	}
	else if (key == 'e' or key == 'E') /*ROTAR DERECHA*/
	{
		glRotatef(angle, 1.0f, 1.0f, 0.0f);
		glEnd();
		glFlush();
	}
	else if (key == 'a' or key == 'A') /*IZQUIERDA*/
	{
		glTranslatef(-1.0f, 0.0f, 0.0f);
		glEnd();
		glFlush();
	}
	else if (key == 'd' or key == 'D') /*DERECHA*/
	{
		glTranslatef(1.0f, 0.0f, 0.0f);
		glEnd();
		glFlush();
	}
	else if (key == 'q' or key == 'Q') /*ROTAR IZQUIERDA*/
	{
		glRotatef(-angle, -1.0f, -1.0f, -1.0);
		glEnd();
		glFlush();
	}
	else if (key == 's' or key == 'S') /*ABAJO*/
	{
		glTranslatef(0.0f, -1.0f, 0.0f);
		glEnd();
		glFlush();
	}
	else if (key == 'x' or key == 'X') /*Reset*/
	{
		glLoadIdentity();
	}
	else if (key == 'c' or key == 'C') /*Aumentar*/
	{
		glScalef(+1.5f, +1.5f, +1.5f);
	}
	else if (key == 'v' or key == 'V') /*Dismunuir*/
	{
		glScalef(-0.5f, -0.5f, -0.5f);
	}
	
}

void time(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, time, 0);
}

void mouse(int button, int state, int x, int y)
{
	switch (button)   /*Escala*/
	{
	case GLUT_LEFT_BUTTON: /*CLICK IZQUIERDO*/

		break;

	case GLUT_RIGHT_BUTTON: /*CLICK DERECHO*/
		glTranslatef(0.0f, 0.0f, -1.0f);
		glEnd();
		glFlush();
		break;
	default:
		break;
	}
}
	int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(600, 600);
		glutCreateWindow("Practica 4");
		glutReshapeFunc(reshape);
		glutDisplayFunc(Figura);
		glutTimerFunc(0, time, 0);
		glutMouseFunc(mouse);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0 ;
	}
