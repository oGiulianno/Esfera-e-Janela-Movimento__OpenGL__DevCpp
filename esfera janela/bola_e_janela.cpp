/************************************************/
// Exercicio de Computação gráfica
//
// Modificar o arquivo cores.c
//
// Criar uma esfera semelhante a uma bola de futebol
// A esfera deve ter partes coloridas
// Criar uma janelas com diferentes opacidades
// A janela deve se mover pela tela
//-----------------------------------------------
// Alunos:	Giulianno G. Latorraca
//			Raiane Pereira Alcantara
//			Vinicius Henrique da Silva Souza
//-----------------------------------------------
//Professor: Gustavo Vinhal
//			 Computação Gráfica
//
/************************************************/

#include <GL\glut.h>
#include <windows.h>
#include <stdlib.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 1;

float AlfaVidro = 0.5f;
float ratio;
float xrot;
float yrot;
float zrot;


void display(void);
void reshape(int x, int y);


void DesenhaPlano(GLfloat alfa)
{
	glBegin(GL_QUADS);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glEnd();
}

void DesenhaPlano2(GLfloat alfa)
{
	glBegin(GL_QUADS);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

		glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glEnd();
}

void DesenhaPlano3(GLfloat alfa)
{
	glBegin(GL_QUADS);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glEnd();
}

void DesenhaPlano4(GLfloat alfa)
{
	glBegin(GL_QUADS);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glVertex3f(-0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, -0.5f, 1.0f);
	glVertex3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 1.0f);

	glEnd();
}


void DesenhaVidro(GLfloat alfa)
{
	static float x = -2;
	static float delta = -0.001f;
	glPushMatrix();
	glTranslatef(x, 0, 0);
	//glRotatef(x, 1.0,0.0,0.0);
	if ((x > 2) || (x < -2))
		delta *= -1;
	x += delta;

	glColor4f(1, 1, 1, alfa);

	glTranslatef(0, -0.5, 0);
	DesenhaPlano(1);

	glTranslatef(-1.1, 0.0, 0);
	DesenhaPlano2(1);

	glTranslatef(1.1, 1.1, 0);
	DesenhaPlano3(1);

	glTranslatef(-1.1, 0.0, 0);
	DesenhaPlano4(1);

	glPopMatrix();

}


void reshape(int x, int y)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (y == 0)
		y = 1;

	ratio = 1.0f * x / y;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, x, y);

	// Seta o ângulo de visão
	gluPerspective(50, ratio, 1, 200);

	// Define a posição do observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5,
		0, 0, 0,
		0.0f, 1.0f, 0.0f);

}


void DesenhaBola(GLfloat alfa)
{

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -5.0);
	// Red color used to draw.
	glColor3f(0.9, 0.3, 0.2);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xrot, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yrot, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zrot, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius, 20, 20);
	// Flush buffers to screen

	glFlush();
	// sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Desabilita o BLEND par ao primeiro objeto
	glDisable(GL_BLEND);
	glPushMatrix();
	glTranslatef(0, 0, -1);
	glRotatef(xrot, 1.0, 0.0, 0.0);
	glRotatef(yrot, 0.0, 1.0, 0.0);
	glRotatef(zrot, 0.0, 0.0, 1.0);

	// habilita remoção de faces traseiras
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	DesenhaBola(0.5);
	glPopMatrix();

	// Habilita o BLEND para ao segundo objeto
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// NovaCorNaTela = CorDoObjeto * AlfaDoObjeto + CorAntigaNaTele * (1-AlfaDoObjeto)

	glPushMatrix();
	glTranslatef(0, 0, 0);
	DesenhaVidro(AlfaVidro);
	glPopMatrix();

	xrot += 3.01f;
	yrot += 3.001f;
	zrot += 3.02f;
	glutSwapBuffers();
}



void idle(void)
{
	xRotated += 0.01;
	//yRotated += 0.01;
	zRotated += 0.01;
	display();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 500);
	glutCreateWindow("Bola e Vidro");
	xRotated = yRotated = zRotated = 30.0;
	xRotated = 43;
	yRotated = 50;

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutIdleFunc(idle);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}

