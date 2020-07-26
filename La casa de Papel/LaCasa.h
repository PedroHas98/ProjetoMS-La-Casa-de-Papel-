#ifndef LACASA_H_INCLUDED
#define LACASA_H_INCLUDED

#include <GL/glut.h>
#include <GL/glu.h>

void Base (float largura, float comprimento, float altura, int fatorr);

void LaCasa (GLuint* t, GLuint* m, float rot);

void Cenario (GLuint* t, float x, float z, float rot);

void Quadro (float lar, float alt, GLuint* t, GLuint* m, int n, int inv);

#endif // LACASA_H_INCLUDED
