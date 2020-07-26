#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include "headers/LaCasa.h"
#include "headers/Textura.h"


#define WIDTH 1300
#define HEIGHT 720
#define FPS 16


float theta = 0.0;
GLuint texturas[20];
GLuint quadros[4];
static float posx = 0.0, posz = -30.0, posy = -3.0, angle = 0.0;
enum tMode {TRANSLATE = 0, SCALE} transformMode;

float springiness = 50;

void init(void);
void initTex(void);
void display(void);
void defineIlumination(void);
void keyboard(unsigned char key, int x, int y);
void keyboard2(int key, int moposx, int mouse_y);
void timer (int id);
void idle (void);
void initTex(void);
void mouseFunc(int button, int state, int x, int y);
void mouseMotionFunc(int x, int y);

int nWindowID;

// atributos de camera
float viewerPosition[3] = { 0.0, 0.0, -2.0 };
float viewerDirection[3] = { 0.0, 0.0, 0.0 };
float viewerUp[3] = { 0.0, 1.0, 0.0 };

// valores de rotação para a navegação
float navigationRotation[3]	= { 0.0, 0.0, 0.0 };

// parametros do contador de frames
char pixelstring[30];
int cframe = 0;
int time = 0;
int timebase = 0;

// parâmetros para navegação

// posição do mouse qauando pressionado
int mousePressedX = 0, mousePressedY = 0;
float lastXOffset = 0.0, lastYOffset = 0.0, lastZOffset = 0.0;
// estados do botão do mouse
int leftMouseButtonActive = 0, middleMouseButtonActive = 0, rightMouseButtonActive = 0;
// alterar estado
int shiftActive = 0, altActive = 0, ctrlActive = 0;



int main (int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casa da Moeda");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboard2);
    glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMotionFunc);
    glutIdleFunc(idle);
    init();
    glutMainLoop();

    return 0;

}

void init (void)
{

    transformMode = TRANSLATE;

    initTex();
    glClearColor(0.50980392156862745098039215686275,
				 0.77647058823529411764705882352941,
				 0.91372549019607843137254901960784, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)WIDTH/(float)HEIGHT, 1.0f, 100.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glTranslatef(posx, posy, posz);
    glMatrixMode(GL_MODELVIEW);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

}

void initTex (void)
{

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(3, texturas);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    texturas[0] = carregaBmp("textura/lacasateto.bmp");
    texturas[1] = carregaBmp("textura/mpar.bmp");
    texturas[2] = carregaBmp("textura/chaointerior.bmp");
    texturas[3] = carregaBmp("textura/asfalto.bmp");
    texturas[4] = carregaBmp("textura/porta.bmp");
    texturas[5] = carregaBmp("textura/janeladecima.bmp");
    texturas[6] = carregaBmp("textura/ceu.bmp");
	texturas[7] = carregaBmp("textura/janela.bmp");
    texturas[8] = carregaBmp("textura/Parede.bmp");
    texturas[9] = carregaBmp("textura/Topo.bmp");
	texturas[10] = carregaBmp("textura/quadro2.bmp");
	texturas[11] = carregaBmp("textura/escada.bmp");
    texturas[12] = carregaBmp("textura/textescada.bmp");
    texturas[13] = carregaBmp("textura/images1.bmp");
    texturas[14] = carregaBmp("textura/bancada.bmp");
    texturas[15] = carregaBmp("textura/quadronovo1.bmp");
    texturas[16] = carregaBmp("textura/quadron3.bmp");
    texturas[17] = carregaBmp("textura/lateralescada2.bmp");
    texturas[18] = carregaBmp("textura/paredesechao.bmp");
    texturas[19] = carregaBmp("textura/janelinha.bmp");
}

void timer (int id)
{

    theta += 0.1;
    glutPostRedisplay();
    glutTimerFunc(FPS, timer, 0);

}

void idle (void)
{
    theta = 0.1 * glutGet(GLUT_ELAPSED_TIME);
    glutSwapBuffers();
    glutPostRedisplay();

}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    GLfloat	lightpos[4] = { 5.0, 15.0, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	glTranslatef(viewerPosition[0], viewerPosition[1], viewerPosition[2]);

	// adicionar rotação de navegação

	glRotatef(navigationRotation[0], 1.0f, 0.0f, 0.0f);
	glRotatef(navigationRotation[1], 0.0f, 1.0f, 0.0f);

    Cenario (texturas, posx, posz, theta);
    LaCasa(texturas, quadros, theta);

    theta += 0.000001;
    glutPostRedisplay();

    glFlush();

}

void keyboard (unsigned char key,int x, int y)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)WIDTH/(float)HEIGHT, 1.0f, 100.0f);

    switch(key)
	{
        case 27:
          exit(0);
        break;
        case 't':
        case 'T':
            transformMode = TRANSLATE;
        break;
        case 'c':
        case 'C':
            transformMode = SCALE;
        break;
        case 'w':
        case 'W':
            posz += 0.5*cos(M_PI*angle/180.0);
            posx += 0.5*sin(M_PI*angle/180.0);
        break;
        case 's':
        case 'S':
            posz -= 0.5*cos(M_PI*angle/180.0);
            posx -= 0.5*sin(M_PI*angle/180.0);
        break;
        case 'q':
        case 'Q':
            posz += -0.5*sin(M_PI*angle/180.0);
            posx += 0.5*cos(M_PI*angle/180.0);
        break;
        case 'e':
        case 'E':
            posz -= -0.5*sin(M_PI*angle/180.0);
            posx -= 0.5*cos(M_PI*angle/180.0);
        break;
    	case 'r':
        case 'R':
            posy -= -0.5*sin(M_PI*angle/180.0);
            posy -= 0.5*cos(M_PI*angle/180.0);
		break;
		case 'f':
        case 'F':
            posy += -0.5*sin(M_PI*angle/180.0);
            posy += 0.5*cos(M_PI*angle/180.0);
		break;
        case 'a':
        case 'A':
            angle += 3;
        break;
        case 'd':
        case 'D':
            angle -= 3;
        break;

    }

    glRotatef(-angle, 0.0, 1.0, 0.0);
    glTranslatef(posx, posy, posz);

}

void keyboard2(int key, int moposx, int mouse_y)
{

    int x=0, y=0, z=0;

    switch(key){
        case GLUT_KEY_PAGE_UP:
            posz++;
        break;
        case GLUT_KEY_PAGE_DOWN:
            posz--;
        break;
    }

    glMatrixMode(GL_PROJECTION);
    switch(transformMode){
        case TRANSLATE:
            glTranslatef(x, y, z);
        break;
        case SCALE:
            glScalef(1.0+x/10.0, 1.0+y/10.0, 1.0+z/10.0);
        break;
    }
    glutPostRedisplay();

}


// mouse callback

void mouseFunc(int button, int state, int x, int y)
{

	// recuperar os modificadores

	switch (glutGetModifiers())
	{
		case GLUT_ACTIVE_SHIFT:
			shiftActive = 1;
			break;
		case GLUT_ACTIVE_ALT:
			altActive	= 1;
			break;
		case GLUT_ACTIVE_CTRL:
			ctrlActive	= 1;
			break;
		default:
			shiftActive = 0;
			altActive	= 0;
			ctrlActive	= 0;
			break;
	}

	// recuperar os botões do mouse

	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN)
		{
			leftMouseButtonActive += 1;
		}
		else
			leftMouseButtonActive -= 1;
	}

	else if (button == GLUT_MIDDLE_BUTTON){
		if (state == GLUT_DOWN)
		{
			middleMouseButtonActive += 1;
			lastXOffset = 0.0;
			lastYOffset = 0.0;
		}
		else
			middleMouseButtonActive -= 1;
	}

	else if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN)
		{
			rightMouseButtonActive += 1;
			lastZOffset = 0.0;
		}
		else
			rightMouseButtonActive -= 1;
	}

	mousePressedX = x;
	mousePressedY = y;

}

//-----------------------------------------------------------------------------

void mouseMotionFunc(int x, int y)
{

	float xOffset = 0.0, yOffset = 0.0, zOffset = 0.0;

	// navegação

	if (leftMouseButtonActive)
	{

		navigationRotation[0] += ((mousePressedY - y) * 180.0f) / 2000.0f;
		navigationRotation[1] += ((mousePressedX - x) * 180.0f) / 2000.0f;

		mousePressedY = y;
		mousePressedX = x;
	}

	// panning
	else if (middleMouseButtonActive)
	{

		xOffset = (mousePressedX + x);
		if (!lastXOffset == 0.0) {
			viewerPosition[0]	-= (xOffset - lastXOffset) / 32.0;
			viewerDirection[0]	-= (xOffset - lastXOffset) / 32.0;
		}
		lastXOffset = xOffset;

		yOffset = (mousePressedY + y);
		if (!lastYOffset == 0.0) {
			viewerPosition[1]	+= (yOffset - lastYOffset) / 32.0;
			viewerDirection[1]	+= (yOffset - lastYOffset) / 32.0;
		}
		lastYOffset = yOffset;

	}

	// profundidade do movimento

	else if (rightMouseButtonActive)
	{
		zOffset = (mousePressedX + x);
		if (!lastZOffset == 0.0)
		{
			viewerPosition[2] -= (zOffset - lastZOffset) / 30.0;
			viewerDirection[2] -= (zOffset - lastZOffset) / 30.0;
		}
		lastZOffset = zOffset;
	}
}
