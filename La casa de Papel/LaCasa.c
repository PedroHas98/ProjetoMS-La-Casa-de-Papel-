#include "../headers/LaCasa.h"
#include "../headers/Textura.h"
#include "../headers/Geometria.h"

#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GLint pb[6][4] = {

    {0,1,2,3}, {3,2,6,7},{7,6,5,4},
    {4,5,1,0}, {5,6,2,1},{7,4,0,3}

};
GLfloat v[8][3];
static void define (float l, float c, float a)
{
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -l/2.0;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = l/2.0;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = 0;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = a;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = c/2.0;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = -c/2.0;

}

GLint faces[6][4] = {
 {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
 {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3}
};

GLfloat v1[8][3] = {
{-2.5, -1.5, 9}, {-2.5, -1.5, -9},
{-2.5, 1.5, -9}, {-2.5, 1.5, 9},
{2.5, -1.5, 9}, {2.5, -1.5, -9},
{2.5, 0.0, -9}, {2.5, 0.0, 9}
};

GLfloat v3[8][3] = {
{-0.5, -0.5, 1}, {-0.5, -0.5, -1},
{-0.5, 0.5, -1}, {-0.5, 0.5, 1},
{0.5, -0.5, 1}, {0.5, -0.5, -1},
{0.5, 0.0, -1}, {0.5, 0.0, 1}
};

void drawCube(int fatorr)
{
 int i;
 glPushMatrix();
  glColor3f(255,193,37);
 glTranslatef(-6.4, 1.0, 6.5);
 glRotatef(180, 180, 1.0, 0.0);
 for (i = 0; i < 6; i++) {
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0);
   glVertex3fv(&v1[faces[i][0]][0]);

   glTexCoord2f(0.0, fatorr * 1.0);
   glVertex3fv(&v1[faces[i][1]][0]);

   glTexCoord2f(fatorr * 1.0, fatorr *  1.0);
   glVertex3fv(&v1[faces[i][2]][0]);

   glTexCoord2f(fatorr * 1.0, 0.0);
   glVertex3fv(&v1[faces[i][3]][0]);
   glEnd();
 }
 glPopMatrix();
}

void drawCube2(int fatorr)
{
 int i;
 glPushMatrix();
 glTranslatef(6.4, 1.0, 6.5);
 glRotatef(-180, 0, 0, 0);
 for (i = 0; i < 6; i++) {
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0);
   glVertex3fv(&v1[faces[i][0]][0]);

   glTexCoord2f(0.0, fatorr * 1.0);
   glVertex3fv(&v1[faces[i][1]][0]);

   glTexCoord2f(fatorr * 1.0, fatorr *  1.0);
   glVertex3fv(&v1[faces[i][2]][0]);

   glTexCoord2f(fatorr * 1.0, 0.0);
   glVertex3fv(&v1[faces[i][3]][0]);
   glEnd();
 }
 glPopMatrix();
}

void Bancada1(int fatorr)
{
 int i;
 glPushMatrix();
 glRotatef(-180, 0, 0, 0);
 for (i = 0; i < 6; i++) {
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0);
   glVertex3fv(&v3[faces[i][0]][0]);
	glTexCoord2f(0.0, fatorr * 1.0);
   glVertex3fv(&v3[faces[i][1]][0]);
	glTexCoord2f(fatorr * 1.0, fatorr *  1.0);
   glVertex3fv(&v3[faces[i][2]][0]);
	glTexCoord2f(fatorr * 1.0, 0.0);
   glVertex3fv(&v3[faces[i][3]][0]);
   glEnd();

 }
 glPopMatrix();
}

void Bancada2(int fatorr)
{
 int i;
 glPushMatrix();
 glRotatef(-180, 180, 0, 0);
 for (i = 0; i < 6; i++) {
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0);
   glVertex3fv(&v3[faces[i][0]][0]);
	glTexCoord2f(0.0, fatorr * 1.0);
   glVertex3fv(&v3[faces[i][1]][0]);
	glTexCoord2f(fatorr * 1.0, fatorr *  1.0);
   glVertex3fv(&v3[faces[i][2]][0]);
	glTexCoord2f(fatorr * 1.0, 0.0);
   glVertex3fv(&v3[faces[i][3]][0]);
   glEnd();
 }
 glPopMatrix();
}

void Base (float largura, float comprimento, float altura, int fatorr)
{
   int i;
   define(largura, comprimento, altura);
   	   for(i = 0; i < 6; i++){
        glBegin(GL_QUADS);
   			glTexCoord2f(0.0, 0.0);
            glVertex3fv(&v[pb[i][0]][0]);
   			glTexCoord2f(0.0, fatorr * 1.0);
            glVertex3fv(&v[pb[i][1]][0]);
   			glTexCoord2f(fatorr * 1.0, fatorr *  1.0);
            glVertex3fv(&v[pb[i][2]][0]);
   			glTexCoord2f(fatorr * 1.0, 0.0);
            glVertex3fv(&v[pb[i][3]][0]);
        glEnd();
    }
}

void LaCasa (GLuint* t, GLuint* m, float rot){

    int i;
    int dim = 24;
    int altpp = 7; //Altura pilar
    float niv = 0;
    float salto = .3;

	// Escadas
	glBindTexture(GL_TEXTURE_2D, t[11]);
    for (i = 0; i < 10; i++){
        glTranslatef(0, .2, -0.8);
        	glPushMatrix();
			Base(dim-niv+2, dim-niv+8.5, .4, 5);
        glPopMatrix();
        niv += salto;
    };
	//Meio da Casa
glBindTexture(GL_TEXTURE_2D, t[18]);


//----------------------------------------
    // Paredes laterais
    //parede maior
	glPushMatrix();
        glTranslatef(-8, salto, -1.5);
        Base(.3, 27, altpp+5, 1);
    glPopMatrix();

//parede
    glPushMatrix();
        glTranslatef(8, salto, -1.5);
        Base(.3, 27, altpp+5, 1);
    glPopMatrix();
   glBindTexture(GL_TEXTURE_2D, t[14]);
//lado esquerdo
   //paredinha divisoria
    glPushMatrix();
        glTranslatef(-7.9, salto+6, -1.5);
        Base(.2, 27, .3, 1);
    glPopMatrix();
       //paredinha divisoria
    glPushMatrix();
        glTranslatef(-7.9, salto+5, -1.5);
        Base(.2, 27, .3, 1);
    glPopMatrix();

    //paredinha divisoria
    glPushMatrix();
        glTranslatef(7.9, salto+6, -1.5);
        Base(.2, 27, .3, 1);
    glPopMatrix();
       //paredinha divisoria
    glPushMatrix();
        glTranslatef(7.9, salto+5, -1.5);
        Base(.2, 27, .3, 1);
    glPopMatrix();
//lado direito
	  glPushMatrix();
        glTranslatef(-7.9, salto, -14.6);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(-7.9, salto, -5.6);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(-7.9, salto, 3);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(-7.9, salto, 11.5);
        Base(.2, .3, 6, 1);
    glPopMatrix();


  glPushMatrix();
        glTranslatef(7.9, salto, -14.6);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(7.9, salto, -5.6);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(7.9, salto, 3);
        Base(.2, .3, 6, 1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(7.9, salto, 11.5);
        Base(.2, .3, 6, 1);
    glPopMatrix();
//-----------------------------------------
  	glBindTexture(GL_TEXTURE_2D, t[8]);
   // Paredes traseira
    glPushMatrix();
        glTranslatef(0, salto-3, -16.1);
        Base(20, 2, altpp+8, 10);
    glPopMatrix();
//parede da frente

    glPushMatrix();
        glTranslatef(0, salto, 11.8);
        Base(20, .5, altpp+5, 10);
    glPopMatrix();
//----------------------------------
//INICIO DA CRIA픈O DO TOPO
    // Topo central

    glPushMatrix();
     glBindTexture(GL_TEXTURE_2D, t[1]);
        glTranslatef(0, salto+9, 12.2);
        Base(10, 0.2, 2.5, 1);
    glBindTexture(GL_TEXTURE_2D, t[9]);
        glTranslatef(0, salto, 0.2);
        TQuadrado(2,2,0);
    glPopMatrix();

//FIM DA CRIA플O DO TOPO
//------------------------------------------
//INICIO DA CRIA플O DE TODAS AS PORTAS
    // Porta central
    glBindTexture(GL_TEXTURE_2D, t[4]);
    glPushMatrix();
        glTranslatef(0, salto, 12.2);
        Base(2, .2, 3.4, 1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, salto, 11.3);
        Base(2, .2, 3.4, 1);
    glPopMatrix();

	//Porta Direita
	glPushMatrix();
        glTranslatef(6, salto, 12.2);
        Base(2, .2, 3.4, 1);
    glPopMatrix();


	// Porta Esquerda

    glPushMatrix();
        glTranslatef(-6, salto, 12.2);
        Base(2, .2, 3.4, 1);
    glPopMatrix();

//FIM DA CRIA플O DAS PORTAS
//------------------------------------------

//------------------------------------------
//JANELAS MEIO LATERAL DIREITA
         glBindTexture(GL_TEXTURE_2D, t[7]);
    glPushMatrix();
        glTranslatef(12, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(15, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(18, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(21, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(24, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(27, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();

//FIM DA PRIMEIRA FILEIRA DE JANELAS
//------------------------------------------------


//------------------------------------------
//JANELAS MEIO LATERAL ESQUERDA
         glBindTexture(GL_TEXTURE_2D, t[7]);
    glPushMatrix();
        glTranslatef(-12, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-15, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-18, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-21, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-24, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-27, salto+5, 11.2);
        Base(1.6, .2, 3, 1);
    glPopMatrix();

//FIM DA PRIMEIRA FILEIRA DE JANELAS
//------------------------------------------------

//------------------------------------------------
//CRIA플O DA SEGUNDA FILEIRA DE JANELAS
     glBindTexture(GL_TEXTURE_2D, t[5]);
    glPushMatrix();
        glTranslatef(12, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(15, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(18, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(21, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(24, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(27, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();

//------------------------------------------------
//------------------------------------------------
//CRIA플O DA SEGUNDA FILEIRA DE JANELAS LADO ESQUERDO
     glBindTexture(GL_TEXTURE_2D, t[5]);
    glPushMatrix();
        glTranslatef(-12, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-15, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-18, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-21, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-24, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(-27, salto+1, 11.2);
        Base(1.6, .2, 2.5, 1);
    glPopMatrix();

//------------------------------------------
//------------------------------------------
//JANELAS PARTE DE BAIXO

	glBindTexture(GL_TEXTURE_2D, t[5]);
    glPushMatrix();
        glTranslatef(15, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(18, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(21, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(24, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(27, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

//------------------------------------------
//------------------------------------------
//JANELAS PARTE DE BAIXO LADO ESQUERDO

	glBindTexture(GL_TEXTURE_2D, t[5]);
    glPushMatrix();
        glTranslatef(-15, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(-18, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(-21, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(-24, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(-27, salto-2, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
//------------------------------------------
    //JANELAS PARTE DE CIMA


	glBindTexture(GL_TEXTURE_2D, t[5]);
	   glPushMatrix();
        glTranslatef(12, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(15, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(18, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(21, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(24, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

        glPushMatrix();
        glTranslatef(27, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();


//------------------------------------
// JANELAS SUPERIORES PARTE DE CIMA DAS PORTAS
    glBindTexture(GL_TEXTURE_2D, t[5]);
    glPushMatrix();
        glTranslatef(-6, salto+4, 12.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
    //segundajanelaporta
      glPushMatrix();
        glTranslatef(0, salto+4, 12.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
    ///terceirajanelaporta3
      glPushMatrix();
        glTranslatef(6, salto+4, 12.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

//-------------------------------------------------
//JANELAS SUPERIORES PARTE CENTRAL

glBindTexture(GL_TEXTURE_2D, t[5]);
	 glPushMatrix();
        glTranslatef(-12, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
	 glPushMatrix();
        glTranslatef(-15, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
	 glPushMatrix();
        glTranslatef(-18, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-21, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-24, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

	glPushMatrix();
        glTranslatef(-27, salto+9, 11.2);
        Base(1.6, .2, 1.6, 1);
    glPopMatrix();

//---------------------------------------------------------
//---------------------------------------------------------
    // PILARES
    glBindTexture(GL_TEXTURE_2D, t[0]);
    float tr = -8;
    for (i = 0; i < 4; i++){
        if(i==0){
			glPushMatrix();
            	glTranslatef(tr-0.8, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();

            glPushMatrix();
            	glTranslatef(tr+0.2, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();
		}

		if(i==1){
			glPushMatrix();
            	glTranslatef(tr+2.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();

            glPushMatrix();
            	glTranslatef(tr+1.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();
		}

		if(i==2){
			glPushMatrix();
            	glTranslatef(tr+6.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();

            glPushMatrix();
            	glTranslatef(tr+5.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();
		}

		if(i==3){
			glPushMatrix();
            	glTranslatef(tr+8.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();

            glPushMatrix();
            	glTranslatef(tr+7.0, salto, 14);
            	Cilindro(20, 20, altpp, .4);
            glPopMatrix();
		}

        tr += 3;
    }

    tr = -10.5;

//-------------------------------------------------
 //TETO ACIMA DOS PILARES
   glBindTexture(GL_TEXTURE_2D, t[1]);
    glPushMatrix();
        glTranslatef(0, salto+altpp, 13);
        Base(21, 3.5, 1, 4);
    glPopMatrix();

//---------------------------------------------------
//PREDIO LATERAL DIREITA
//--------------------------------------------
 	glBindTexture(GL_TEXTURE_2D, t[8]);
    // Paredes laterais
    //predio direito
    glPushMatrix();
        glTranslatef(28.5, salto-3, 0.0);
        Base(.3, 22.5, 15, 10);
    glPopMatrix();


//-------------------------------------------
//Paredes frontal e traseira do Predio direito
//parede traseira
    glPushMatrix();
        glTranslatef(19, salto-3, -11);
        Base(19, 12.1, altpp+8, 10);
    glPopMatrix();
//parede frontal
    glPushMatrix();
        glTranslatef(19, salto-3, 11.1);
        Base(19, .3, altpp+8, 10);
    glPopMatrix();
//--------------------------------------------

//------------------------------------
//lado esquerdo
   glPushMatrix();
        glTranslatef(-19, salto-3, -11);
        Base(19, 12.1, altpp+8, 10);
    glPopMatrix();
	//parede frontal
    glPushMatrix();
        glTranslatef(-19, salto-3, 11.1);
        Base(19, .3, altpp+8, 10);
    glPopMatrix();
  glPushMatrix();
        glTranslatef(-28.5, salto-3, 0.0);
        Base(.3, 22.5, 15, 10);
    glPopMatrix();

//-----------------------------------------------------------
//PILAR ESCADA, 1 PILAR ESQUERDO
 glBindTexture(GL_TEXTURE_2D, t[17]);
 	 glPushMatrix();
        glTranslatef(-2.3, salto-1, 1.5);
        Base(.5,.7, 3.2, 10);
     glPopMatrix();
//----------------------------------
//PAREDE ENTRE OS PILARES 1 E 2 LADO ESQUERDO
  	 glPushMatrix();
  	 glRotatef(25, 25, 0, 0);
        glTranslatef(-2.3, salto+0.1, -2.2);
        Base(.3,5.2, 2.2, 10);
     glPopMatrix();
//--------------------------------------------
//PILAR DIREITO, 1 PILAR
 	 glPushMatrix();
        glTranslatef(2.3, salto-1, 1.5);
        Base(.5,.7, 3.2, 10);
     glPopMatrix();
//------------------------------------------
//PAREDE ENTRE OS PILARES 1 E 2 DIREITO
   	 glPushMatrix();
  	 glRotatef(25, 25, 0, 0);
        glTranslatef(2.3, salto+0.1, -2.2);
        Base(.3,5.2, 2.2, 10);
     glPopMatrix();
//-----------------------------------------------------------
//PILAR ESCADA, 2 PILAR ESQUERDO
    glPushMatrix();
        glTranslatef(-2.3, salto+1, -3.5);
        Base(.5,.5, 3.5, 10);
    glPopMatrix();
//--------------------------------------------
//PILAR DIREITO, 2 PILAR
    glPushMatrix();
        glTranslatef(2.3, salto+1, -3.5);
        Base(.5,.5, 3.5, 10);
    glPopMatrix();
//-----------------------------------------------------------
//PILAR ESCADA, 3 PILAR ESQUERDO
 glPushMatrix();
        glTranslatef(-2.3, salto+4, -8.5);
        Base(.5,1, 3, 10);
    glPopMatrix();
//----------------------------------
//PAREDE ENTRE OS PILARES 2 E 3 LADO ESQUERDO
  	 glPushMatrix();
  	 glRotatef(30, 30, 0, 0);
        glTranslatef(-2.3, salto-0.5, -8);
        Base(.3,5.3, 2.2, 10);
     glPopMatrix();
//--------------------------------------------
//PILAR DIREITO, 3 PILAR
 glPushMatrix();
        glTranslatef(2.3, salto+4, -8.5);
        Base(.5,1, 3, 10);
    glPopMatrix();
//------------------------------------------
//PAREDE ENTRE OS PILARES 2 E 3 DIREITO
   	 glPushMatrix();
  	 glRotatef(30, 30, 0, 0);
        glTranslatef(2.3, salto-0.5, -8);
        Base(.3,5.3, 2.2, 10);
     glPopMatrix();
//-----------------------------------------------------------
//PILAR ESCADA, 4 PILAR ESQUERDO
 glPushMatrix();
        glTranslatef(-2.3, salto+6, -15);
        Base(.5,.7, 3, 10);
    glPopMatrix();
//PAREDE ENTRE OS PILARES 3 E 4 LADO ESQUERDO
  	 glPushMatrix();
  	 glRotatef(20, 20, 0, 0);
        glTranslatef(-2.3, salto+1, -14);
        Base(.3,6.2, 2.2, 10);
     glPopMatrix();
//--------------------------------------------

//PILAR DIREITO, 4 PILAR
 glPushMatrix();
        glTranslatef(2.3, salto+6, -15);
        Base(.5,.7, 3, 10);
    glPopMatrix();
//------------------------------------------
//PAREDE ENTRE OS PILARES 3 E 4 DIREITO
   	 glPushMatrix();
  	 glRotatef(20, 20, 0, 0);
        glTranslatef(2.3, salto+1, -14);
        Base(.3,6.2, 2.2, 10);
     glPopMatrix();
//--------------------------------------------

//--------------------------------------------------------
// ESCADA INTERIOR
	glBindTexture(GL_TEXTURE_2D, t[12]);
    for (i = 0; i < 14; i++){
        glTranslatef(0, 0.5, -1);
  		glPushMatrix();
			Base(4, 6, 0.5, 1);
        glPopMatrix();
        niv += salto;
    };
glBindTexture(GL_TEXTURE_2D, t[14]);
//	tetoInterior();
//--------------------------------------------------------------
//teto todo
// Base do teto lado direito
    glBindTexture(GL_TEXTURE_2D, t[1]);
    glPushMatrix();
        glTranslatef(0, salto+4.9,12.45);
        Base(57, 28, .3, 4);
    glPopMatrix();

//termina

 //QUADRO LADO ESQUERDO
   glBindTexture(GL_TEXTURE_2D, t[10]);
  glPushMatrix();
        glTranslatef(7.8, salto-4.5, 23);
	    Quadro(2, 2, t, m, 0, 1);
    glPopMatrix();

     glBindTexture(GL_TEXTURE_2D, t[13]);
  glPushMatrix();
        glTranslatef(7.8, salto-4.5, 20);
	    Quadro(2, 2, t, m, 0, 1);
    glPopMatrix();

 //QUADRO LADO DIREITO
glBindTexture(GL_TEXTURE_2D, t[15]);
  glPushMatrix();
        glTranslatef(-7.7, salto-4.5, 23);
	    Quadro(2, 2, t, m, 0, -1);
    glPopMatrix();

     glBindTexture(GL_TEXTURE_2D, t[16]);
  glPushMatrix();
        glTranslatef(-7.7, salto-4.5, 20);
	    Quadro(2, 2, t, m, 0, -1);
    glPopMatrix();

    //-----------------------------------
glBindTexture(GL_TEXTURE_2D, t[18]);
	  drawCube(1);
	  drawCube2(1);
//BANCADAS ABAIXO DOS QUADROS
	glBindTexture(GL_TEXTURE_2D, t[14]);
	glPushMatrix();
		glTranslatef(6.4,-5,23);
		Bancada1(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(6.4,-5,20);
		Bancada1(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-6.4,-5,23);
		Bancada2(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-6.4,-5,20);
		Bancada2(1);
	glPopMatrix();
//-------------------------------------------------------
// janela taseira central
    glBindTexture(GL_TEXTURE_2D, t[19]);
    glPushMatrix();
        glTranslatef(0, salto-10, -1.1);
        Base(4, .2, 15, 7);
    glPopMatrix();

//Janela traseira Direita
glPushMatrix();
        glTranslatef(5, salto-9, -1.1);
        Base(4, .2, 11, 7);
    glPopMatrix();

// Janela traseira Esquerda

    glPushMatrix();
        glTranslatef(-5, salto-9, -1.1);
        Base(4, .2, 11, 7);
    glPopMatrix();

}
void Cenario (GLuint* t, float x, float z, float rot)
{
	float p = 2*sin((3.14*rot)/180.0);
	glBindTexture(GL_TEXTURE_2D, t[3]);
	glPushMatrix();
		glTranslatef(0, -0.1, 0);
		Base(300, 300, 0.1, 15);
	glPopMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, t[6]);
		glTranslatef(0+p, 30, 0);
		Base(300, 300, 0.1, 1);
	glPopMatrix();

}
void Quadro (float lar, float alt, GLuint* t, GLuint* m, int n, int inv)
{
	glPushMatrix();
		glRotatef((float) inv * 90, 0, 1, 0);
        Base(lar+0.2, .1, alt+0.2, 1);
		glBindTexture(GL_TEXTURE_2D, m[n]);
		glTranslatef(0, .1, .1);
        TQuadrado(lar, alt, 0);
    glPopMatrix();

}


