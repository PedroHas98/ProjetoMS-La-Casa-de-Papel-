#include "../headers/Textura.h"
#include "../headers/Textura.h"

#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Cilindro (GLint rdiv, GLint hdiv, GLfloat alt, GLfloat raio)
{
    int i, j;

    GLfloat delta, theta, theta_;
    GLfloat alt_, delta_H;

    delta = (2*M_PI)/rdiv;
    delta_H = alt/hdiv;

    for(i = 0; i < rdiv; i++)
    {
        theta = i * delta;
        theta_ = theta + delta;

        glBegin(GL_LINE_LOOP);
            glVertex3f(0.0, alt, 0.0);
            glVertex3f(raio*cos(theta), alt, raio*sin(theta));
            glVertex3f(raio*cos(theta+delta), alt, raio*sin(theta+delta));
        glEnd();

        for (j = 0; j < hdiv; j++)
        {
            alt_ = j * delta_H;

            glBegin(GL_QUADS);

                	glTexCoord2f(theta/2*M_PI, (alt_)/alt);
                glVertex3f(raio*cos(theta), alt_, raio*sin(theta));

                	glTexCoord2f(theta/2*M_PI, (alt_+delta_H)/alt);
                glVertex3f(raio*cos(theta), alt_+delta_H, raio*sin(theta));

                	glTexCoord2f(theta_/2*M_PI, (alt_+delta_H)/alt);
                glVertex3f(raio*cos(theta_), alt_+delta_H, raio*sin(theta+delta));

                	glTexCoord2f(theta_/2*M_PI, (alt_)/alt);
                glVertex3f(raio*cos(theta_), alt_, raio*sin(theta+delta));

            glEnd();
        }

        glBegin(GL_LINE_LOOP);
            glVertex3f(0.0,0.0,0.0);
            glVertex3f(raio*cos(theta), 0.0, raio*sin(theta));
            glVertex3f(raio*cos(theta+delta), 0.0, raio*sin(theta+delta));
        glEnd();
    }
}


void TQuadrado (GLfloat lar, GLfloat alt, GLfloat ang)
{
	glRotatef(ang, 0, 1, 0);
	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
		glVertex3f(-lar/2.0, 0, 0);
			glTexCoord2f(0.0, 1.0);
		glVertex3f(-lar/2.0, alt, 0);
			glTexCoord2f(1.0, 1.0);
		glVertex3f(lar/2.0, alt, 0);
			glTexCoord2f(1.0, 0.0);
		glVertex3f(lar/2.0, 0, 0);
	glEnd();
}
