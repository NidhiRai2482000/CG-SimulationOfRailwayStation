#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include "mmsystem.h"
#define SPEED 80.0


float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;
int light=1,day=1,plane=0,comet=0,xm=900,train=0;
int man_show=1;
char ch;
int c_menu;


void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}


void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void face(int h,int k){
    glBegin(GL_POLYGON);
    glColor3ub(255,191,128);
    for(int i=1;i<=14;i++)
        draw_circle(h,k,i);
	glPushMatrix();
	glTranslatef(h,k,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540,294,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glEnd();
}


void man()
{
    face(320,271);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540-220,195+76);
 		glVertex2i(540-220,190+76); //nose
  		glVertex2i(531-220,200+76);
 		glVertex2i(537-220,200+76);//eyebrow
  		glVertex2i(543-220,200+76);
 		glVertex2i(549-220,200+76);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14-220,194+1+76);
	glVertex2i(540-14-220,190+1+76);
	glVertex2i(538-14-220,189+1+76);
	glVertex2i(538-14-220,195+1+76);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554-220,195+76);
	glVertex2i(556-220,196+76);
	glVertex2i(556-220,191+76);
	glVertex2i(554-220,190+76);
	glEnd();
//hair
	glBegin(GL_POLYGON);
	  glColor3ub(0,0,0);
	  glVertex2i(527-220,203+76);
	  glVertex2i(553-220,203+76);
	  glVertex2i(547-220,210+76);
	  glVertex2i(533-220,210+76);
	glEnd();

	// eyes
 	glBegin(GL_POLYGON);
 		glVertex2i(533-220,198+76);
 		glVertex2i(535-220,198+76);
 		glVertex2i(535-220,196+76);
 		glVertex2i(533-220,196+76);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545-220,198+76);
 		glVertex2i(547-220,198+76);
 		glVertex2i(547-220,196+76);
 		glVertex2i(545-220,196+76);
glEnd();
 	// mouth
glBegin(GL_POLYGON);
 		glVertex2i(535-220,187+76);
 		glVertex2i(540-220,185+76);
 		glVertex2i(545-220,187+76);
 		glVertex2i(540-220,187+76);
glEnd();
//beard
glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(538-220,180+76);
	glVertex2i(542-220,180+76);
	glVertex2i(542-220,184+76);
	glVertex2i(538-220,184+76);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(55,50,70);
	    glVertex2i(529-220,180+76);
 		glVertex2i(551-220,180+76);
 		glVertex2i(566-220,169+76);
 		glVertex2i(561-220,161+76);
 		glVertex2i(556-220,165+76);
        glVertex2i(556-220,145+76);
 		glVertex2i(524-220,145+76);
 		glVertex2i(524-220,165+76);
 		glVertex2i(519-220,160+76);
 		glVertex2i(514-220,169+76);
glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565-220,168+76);
 		glVertex2i(575-220,153+76);
 		glVertex2i(567-220,154+76);
 		glVertex2i(562-220,162+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575-220,153+76);
 		glVertex2i(556-220,138+76);
 		glVertex2i(556-220,145+76);
 		glVertex2i(567-220,154+76);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515-220,168+76);
 		glVertex2i(505-220,153+76);
 		glVertex2i(513-220,154+76);
 		glVertex2i(518-220,162+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505-220,153+76);
   		glVertex2i(524-220,138+76);
   		glVertex2i(524-220,145+76);
   		glVertex2i(513-220,154+76);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(150,12,30);
 		glVertex2i(556-220,145+76);
 		glVertex2i(524-220,145+76);
 		glVertex2i(524-220,140+76);
		glVertex2i(524-220,140+76);
 		glVertex2i(556-220,140+76);
glEnd();
// collar
 	glBegin(GL_POLYGON);
		glColor3ub(200,140,110+76);
 		glVertex2i(529-220,180+76);
 		glVertex2i(551-220,180+76);
 		glVertex2i(546-220,170+76);
 		glVertex2i(534-220,170+76);
glEnd();

 	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
 		glVertex2i(540-220,177+76);
  		glVertex2i(545-220,170+76);
 		glVertex2i(535-220,170+76);
glEnd();

// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,165+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,158+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,151+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();

	// pant
glBegin(GL_POLYGON);
		glColor3ub(80,80,230);
glVertex2i(555-220,140+76);
glVertex2i(525-220,140+76);
glVertex2i(520-220,105+76);
glVertex2i(530-220,105+76);
glVertex2i(533-220,138+76);
glVertex2i(550-220,105+76);
glVertex2i(560-220,105+76);
	glEnd();
		//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(530-220,105+76);
	glVertex2i(530-220,96+76);
	glVertex2i(512-220,96+76);
	glVertex2i(520-220,105+76);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(550-220,105+76);
	glVertex2i(550-220,96+76);
	glVertex2i(568-220,96+76);
	glVertex2i(560-220,105+76);
	glEnd();
}


void women()
{
    face(540,295);
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,294);
 		glVertex2i(540,290); //nose
  		glVertex2i(531,298);
		glVertex2i(532,299);
 		glVertex2i(532,299);
		glVertex2i(537,298);//eyebrow
  	    glVertex2i(549,298);
		glVertex2i(548,299);
		glVertex2i(548,299);
 		glVertex2i(543,298);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14,294+1);
	glVertex2i(540-14,290+1);
	glVertex2i(538-14,289+1);
	glVertex2i(538-14,295+1);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554,295);
	glVertex2i(556,296);
	glVertex2i(556,291);
	glVertex2i(554,290);
	glEnd();
	//ear ring right
	glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(539-14,292);
	glVertex2i(542-14,285);
	glVertex2i(536-14,285);

	glEnd();
	//ear ring left
   glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(551,285);
	glVertex2i(555,292);
	glVertex2i(558,285);
	glEnd();

//hair
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(525,299);
	glVertex2i(549,309);
	glVertex2i(540,312);
	glVertex2i(528,307);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(540,307);
	glVertex2i(549,309);
	glVertex2i(552,307);
	glVertex2i(555,299);
	glEnd();
	// eyes
        glBegin(GL_POLYGON);
 		glVertex2i(533,296);
 		glVertex2i(535,296);
 		glVertex2i(535,294);
 		glVertex2i(533,294);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545,296);
 		glVertex2i(547,296);
     	glVertex2i(547,294);
 		glVertex2i(545,294);
glEnd();
//mouth
glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,287);
 		glVertex2i(540,284);
 		glVertex2i(546,287);
 		glVertex2i(540,285);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(204,0,204);
        glVertex2i(529,280);
 		glVertex2i(551,280);
 		glVertex2i(566,269);
 		glVertex2i(561,260);
 		glVertex2i(556,265);
        glVertex2i(556,245);
 		glVertex2i(524,245);
 		glVertex2i(524,265);
 		glVertex2i(519,260);
 		glVertex2i(514,269);
glEnd();
//neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,280);
        glVertex2i(547,280);
        glVertex2i(545,271);
        glVertex2i(535,271);
    glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,268);
 		glVertex2i(575,253);
 		glVertex2i(567,254);
 		glVertex2i(562,262);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,253);
 		glVertex2i(556,238);
 		glVertex2i(556,245);
 		glVertex2i(567,254);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515,268);
 		glVertex2i(505,253);
 		glVertex2i(513,254);
 		glVertex2i(518,262);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505,253);
   		glVertex2i(524,238);
   		glVertex2i(524,245);
   		glVertex2i(513,254);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(0,0,0);
 		glVertex2i(556,245);
 		glVertex2i(524,245);
 		glVertex2i(524,240);
 		glVertex2i(556,240);
glEnd();

	// leg
glBegin(GL_POLYGON);
glColor3ub(255,190,128);
glVertex2i(555,240);
glVertex2i(525,240);
glVertex2i(520,205);
glVertex2i(530,205);
glVertex2i(533,238);
glVertex2i(550,205);
glVertex2i(560,205);
	glEnd();
//skirt
    glBegin(GL_POLYGON);
	    glColor3ub(0,0,0);
		glVertex2i(524,240);
		glVertex2i(556,240);
		glVertex2i(566,210);
		glVertex2i(514,210);
    glEnd();
	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(530,205);
	glVertex2i(530,196);
	glVertex2i(528,196);
	glVertex2i(528,204);
	glVertex2i(522,196);
	glVertex2i(512,196);
	glVertex2i(520,205);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(550,205);
	glVertex2i(550,196);
	glVertex2i(552,196);
	glVertex2i(552,204);
	glVertex2i(558,196);
	glVertex2i(568,196);
	glVertex2i(560,205);
	glEnd();
}

void draw_object()
{
    int l;
    if(day==1)
    {
    //sky
        glColor3f(0.0,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,380);
        glEnd();

    //sun

        for(l=0;l<=35;l++)
    {
            glColor3f(1.0,0.9,0.0);
            draw_circle(100,625,l);
    }

    //plane
    if(plane==1)
    {
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
        glVertex2f(1015+n,640+o);
        glVertex2f(1030+n,650+o);
        glVertex2f(1050+n,650+o);
        glVertex2f(1010+n,625+o);
    glEnd();

        glColor3f(0.8,0.8,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
        glVertex2f(1015+n,640+o);
        glVertex2f(1030+n,650+o);
        glVertex2f(1050+n,650+o);
        glVertex2f(1010+n,625+o);
    glEnd();

    }

    //cloud1

        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(160+m,625,l);

        }

        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(200+m,625,l);
            draw_circle(225+m,625,l);
        }

        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(265+m,625,l);
        }

    //cloud2

        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(370+m,615,l);
        }

        for(l=0;l<=35;l++)
        {

            glColor3f(1.0,1.0,1.0);
            draw_circle(410+m,615,l);
            draw_circle(435+m,615,l);
            draw_circle(470+m,615,l);
        }

    for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(500+m,615,l);
        }

    //grass
    glColor3f(0.0,0.9,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,160);
    glVertex2f(0,380);
    glVertex2f(1100,380);
    glVertex2f(1100,160);
    glEnd();

    }

    else
    {

    //sky
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,380);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,380);
    glEnd();

    //moon
    int l;

        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(100,625,l);
        }

    //star1

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(575,653);
    glVertex2f(570,645);
    glVertex2f(580,645);
    glVertex2f(575,642);
    glVertex2f(570,650);
    glVertex2f(580,650);
    glEnd();

    //star2
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(975,643);
    glVertex2f(970,635);
    glVertex2f(980,635);
    glVertex2f(975,632);
    glVertex2f(970,640);
    glVertex2f(980,640);
    glEnd();

    //star3
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(875,543);
    glVertex2f(870,535);
    glVertex2f(880,535);
    glVertex2f(875,532);
    glVertex2f(870,540);
    glVertex2f(880,540);
    glEnd();

    //star4
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(375,598);
    glVertex2f(370,590);
    glVertex2f(380,590);
    glVertex2f(375,587);
    glVertex2f(370,595);
    glVertex2f(380,595);
    glEnd();

    //star5
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(750,628);
    glVertex2f(745,620);
    glVertex2f(755,620);
    glVertex2f(750,618);
    glVertex2f(745,625);
    glVertex2f(755,625);
    glEnd();

    //star6
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(200,628);
    glVertex2f(195,620);
    glVertex2f(205,620);
    glVertex2f(200,618);
    glVertex2f(195,625);
    glVertex2f(205,625);
    glEnd();

    //star7
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(100,528);
    glVertex2f(95,520);
    glVertex2f(105,520);
    glVertex2f(100,518);
    glVertex2f(95,525);
    glVertex2f(105,525);
    glEnd();

    //star8
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(300,468);
    glVertex2f(295,460);
    glVertex2f(305,460);
    glVertex2f(300,458);
    glVertex2f(295,465);
    glVertex2f(305,465);
    glEnd();

    //star9
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(500,543);
    glVertex2f(495,535);
    glVertex2f(505,535);
    glVertex2f(500,532);
    glVertex2f(495,540);
    glVertex2f(505,540);
    glEnd();


    //comet
    if(comet==1)
    {
        for(l=0;l<=7;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(300+c,675,l);
        }

    glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200+c,675);
        glVertex2f(300+c,682);
        glVertex2f(300+c,668);
        glEnd();
    }

    //Plane
    if(plane==1)
    {

        for(l=0;l<=1;l++)
        {
            glColor3f(1.0,0.0,0.0);
            draw_circle(950+n,625+o,l);
            glColor3f(1.0,1.0,0.0);
            draw_circle(954+n,623+o,l);

        }

    }

    //grass
    glColor3f(0.0,0.3,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,160);
    glVertex2f(0,380);
    glVertex2f(1100,380);
    glVertex2f(1100,160);
    glEnd();

    }


    //track boundary
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,150);
    glVertex2f(0,160);
    glVertex2f(1100,160);
    glVertex2f(1100,150);
    glEnd();

    //platform

    glColor3f(0.560784,0.560784,0.737255);
    glBegin(GL_POLYGON);
    glVertex2f(0,160);
    glVertex2f(0,250);
    glVertex2f(1100,250);
    glVertex2f(1100,160);
    glEnd();

    //table 1

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(140,190);
    glVertex2f(140,210);
    glVertex2f(155,210);
    glVertex2f(155,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(130,210);
    glVertex2f(130,215);
    glVertex2f(225,215);
    glVertex2f(225,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(200,190);
    glVertex2f(200,210);
    glVertex2f(215,210);
    glVertex2f(215,190);
    glEnd();

    //table 2

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(390,190);
    glVertex2f(390,210);
    glVertex2f(405,210);
    glVertex2f(405,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(380,210);
    glVertex2f(380,215);
    glVertex2f(475,215);
    glVertex2f(475,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(450,190);
    glVertex2f(450,210);
    glVertex2f(465,210);
    glVertex2f(465,190);
    glEnd();

    //table 3

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(840,190);
    glVertex2f(840,210);
    glVertex2f(855,210);
    glVertex2f(855,190);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(830,210);
    glVertex2f(830,215);
    glVertex2f(925,215);
    glVertex2f(925,210);
    glEnd();

    glColor3f(1.0,0.498039,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(900,190);
    glVertex2f(900,210);
    glVertex2f(915,210);
    glVertex2f(915,190);
    glEnd();

    //below track
    glColor3f(0.623529,0.623529,0.372549);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,150);
    glVertex2f(1100,150);
    glVertex2f(1100,0);
    glEnd();

    //Railway track

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-100,0);
    glVertex2f(-100,20);
    glVertex2f(1100,20);
    glVertex2f(1100,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-100,80);
    glVertex2f(-100,100);
    glVertex2f(1100,100);
    glVertex2f(1100,80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,80);
    glVertex2f(10,80);
    glVertex2f(10,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(80,0);
    glVertex2f(80,80);
    glVertex2f(90,80);
    glVertex2f(90,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(150,0);
    glVertex2f(150,80);
    glVertex2f(160,80);
    glVertex2f(160,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(220,0);
    glVertex2f(220,80);
    glVertex2f(230,80);
    glVertex2f(230,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(290,0);
    glVertex2f(290,80);
    glVertex2f(300,80);
    glVertex2f(300,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(360,0);
    glVertex2f(360,80);
    glVertex2f(370,80);
    glVertex2f(370,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(430,0);
    glVertex2f(430,80);
    glVertex2f(440,80);
    glVertex2f(440,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(500,0);
    glVertex2f(500,80);
    glVertex2f(510,80);
    glVertex2f(510,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(570,0);
    glVertex2f(570,80);
    glVertex2f(580,80);
    glVertex2f(580,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(640,0);
    glVertex2f(640,80);
    glVertex2f(650,80);
    glVertex2f(650,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(710,0);
    glVertex2f(710,80);
    glVertex2f(720,80);
    glVertex2f(720,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(770,0);
    glVertex2f(770,80);
    glVertex2f(780,80);
    glVertex2f(780,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(840,0);
    glVertex2f(840,80);
    glVertex2f(850,80);
    glVertex2f(850,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(900,0);
    glVertex2f(900,80);
    glVertex2f(910,80);
    glVertex2f(910,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(970,0);
    glVertex2f(970,80);
    glVertex2f(980,80);
    glVertex2f(980,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1040,0);
    glVertex2f(1040,80);
    glVertex2f(1050,80);
    glVertex2f(1050,0);
    glEnd();

    //track bounbary
    glColor3f(0.647059,0.164706,0.164706);
    glBegin(GL_POLYGON);
    glVertex2f(-100,100);
    glVertex2f(-100,150);
    glVertex2f(1100,150);
    glVertex2f(1100,100);
    glEnd();

    //railway station boundary (fence)
    glColor3f(0.647059,0.164706,0.164706);
    glBegin(GL_POLYGON);
    glVertex2f(0,250);
    glVertex2f(0,310);
    glVertex2f(5,320);
    glVertex2f(10,310);
    glVertex2f(10,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(90,250);
    glVertex2f(90,310);
    glVertex2f(95,320);
    glVertex2f(100,310);
    glVertex2f(100,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(140,250);
    glVertex2f(140,310);
    glVertex2f(145,320);
    glVertex2f(150,310);
    glVertex2f(150,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190,250);
    glVertex2f(190,310);
    glVertex2f(195,320);
    glVertex2f(200,310);
    glVertex2f(200,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(240,250);
    glVertex2f(240,310);
    glVertex2f(245,320);
    glVertex2f(250,310);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(340,250);
    glVertex2f(340,310);
    glVertex2f(345,320);
    glVertex2f(350,310);
    glVertex2f(350,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(390,250);
    glVertex2f(390,310);
    glVertex2f(395,320);
    glVertex2f(400,310);
    glVertex2f(400,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,250);
    glVertex2f(950,310);
    glVertex2f(955,320);
    glVertex2f(960,310);
    glVertex2f(960,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1000,250);
    glVertex2f(1000,310);
    glVertex2f(1005,320);
    glVertex2f(1010,310);
    glVertex2f(1010,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1050,250);
    glVertex2f(1050,310);
    glVertex2f(1055,320);
    glVertex2f(1060,310);
    glVertex2f(1060,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,295);
    glVertex2f(950,305);
    glVertex2f(1100,305);
    glVertex2f(1100,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(950,265);
    glVertex2f(950,275);
    glVertex2f(1100,275);
    glVertex2f(1100,265);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,295);
    glVertex2f(0,305);
    glVertex2f(400,305);
    glVertex2f(400,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,265);
    glVertex2f(0,275);
    glVertex2f(400,275);
    glVertex2f(400,265);
    glEnd();

    //tree 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(50,185);
    glVertex2f(50,255);
    glVertex2f(65,255);
    glVertex2f(65,185);
    glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}

    //tree 2
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(300,185);
    glVertex2f(300,255);
    glVertex2f(315,255);
    glVertex2f(315,185);
    glEnd();


        for(l=0;l<=30;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(290,250,l);
            draw_circle(330,250,l);
        }

        for(l=0;l<=25;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(300,290,l);
            draw_circle(320,290,l);
        }

        for(l=0;l<=20;l++)
        {
            glColor3f(0.0,0.5,0.0);
            draw_circle(310,315,l);
        }


    //tree 5
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1050,185);
    glVertex2f(1050,255);
    glVertex2f(1065,255);
    glVertex2f(1065,185);
    glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,250,l);
		draw_circle(1080,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,290,l);
		draw_circle(1070,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,315,l);
	}


    //railway station
    glColor3f(0.647059,0.164706,0.164706);
    glBegin(GL_POLYGON);
    glVertex2f(400,250);
    glVertex2f(400,450);
    glVertex2f(950,450);
    glVertex2f(950,250);
    glEnd();

    //roof
    glColor3f(0.556863,0.419608,0.137255);
    glBegin(GL_POLYGON);
    glVertex2f(350,450);
    glVertex2f(450,500);
    glVertex2f(900,500);
    glVertex2f(1000,450);
    glEnd();
    //side window
    glColor3f(0.556863,0.419608,0.137255);
    glBegin(GL_POLYGON);
    glVertex2f(400,400);
    glVertex2f(350,350);
    glVertex2f(400,350);
    glEnd();

    //side window
    glColor3f(0.556863,0.419608,0.137255);
    glBegin(GL_POLYGON);
    glVertex2f(950,400);
    glVertex2f(1000,350);
    glVertex2f(950,350);
    glEnd();


    glColor3f(0.847059,0.847059,0.74902);
    glBegin(GL_POLYGON);
    glVertex2f(425,250);
    glVertex2f(425,250);
    glVertex2f(425,400);
    glVertex2f(450,425);
    glVertex2f(550,425);
    glVertex2f(575,400);
    glVertex2f(575,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(600,250);
    glVertex2f(600,400);
    glVertex2f(625,425);
    glVertex2f(725,425);
    glVertex2f(750,400);
    glVertex2f(750,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(775,250);
    glVertex2f(775,400);
    glVertex2f(800,425);
    glVertex2f(900,425);
    glVertex2f(925,400);
    glVertex2f(925,250);
    glEnd();

    //window 1
    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(450,300);
    glVertex2f(450,375);
    glVertex2f(550,375);
    glVertex2f(550,300);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(450,337.5);
    glVertex2f(550,337.5);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(500,375);
    glVertex2f(500,300);
    glEnd();


    //window 2
    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(800,300);
    glVertex2f(800,375);
    glVertex2f(900,375);
    glVertex2f(900,300);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(800,337.5);
    glVertex2f(900,337.5);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(850,375);
    glVertex2f(850,300);
    glEnd();

    //door
    glColor3f(0.329412,0.329412,0.329412);
    glBegin(GL_POLYGON);
    glVertex2f(625,250);
    glVertex2f(625,375);
    glVertex2f(725,375);
    glVertex2f(725,250);
    glEnd();


//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}
	man();
	if(man_show==1){
	women();

	}


    if(train==1)
    {
    //train carrier 3

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-600+i-xm,50);
    glVertex2f(-600+i-xm,300);
    glVertex2f(-1000+i-xm,300);
    glVertex2f(-1000+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-590+i-xm,300);
    glVertex2f(-590+i-xm,310);
    glVertex2f(-1010+i-xm,310);
    glVertex2f(-1010+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-825+i-xm,175);
    glVertex2f(-825+i-xm,285);
    glVertex2f(-985+i-xm,285);
    glVertex2f(-985+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-615+i-xm,175);
    glVertex2f(-615+i-xm,285);
    glVertex2f(-775+i-xm,285);
    glVertex2f(-775+i-xm,175);
    glEnd();

    // carrier 3 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-675+i-xm,50,l);
        draw_circle(-925+i-xm,50,l);
       }

    //train carrier 2

    glColor3f(255.0,255.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-150+i-xm,50);
    glVertex2f(-150+i-xm,300);
    glVertex2f(-550+i-xm,300);
    glVertex2f(-550+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-140+i-xm,300);
    glVertex2f(-140+i-xm,310);
    glVertex2f(-560+i-xm,310);
    glVertex2f(-560+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-375+i-xm,175);
    glVertex2f(-375+i-xm,285);
    glVertex2f(-535+i-xm,285);
    glVertex2f(-535+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-165+i-xm,175);
    glVertex2f(-165+i-xm,285);
    glVertex2f(-325+i-xm,285);
    glVertex2f(-325+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-550+i-xm,75);
    glVertex2f(-550+i-xm,95);
    glVertex2f(-600+i-xm,95);
    glVertex2f(-600+i-xm,75);
    glEnd();

    // carrier 2 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-225+i-xm,50,l);
        draw_circle(-475+i-xm,50,l);
       }

    // train carrier 1


    glColor3f(0.258824,0.435294,0.258824);
    glBegin(GL_POLYGON);
    glVertex2f(300+i-xm,50);
    glVertex2f(300+i-xm,300);
    glVertex2f(-100+i-xm,300);
    glVertex2f(-100+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(310+i-xm,300);
    glVertex2f(310+i-xm,310);
    glVertex2f(-110+i-xm,310);
    glVertex2f(-110+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(75+i-xm,175);
    glVertex2f(75+i-xm,285);
    glVertex2f(-85+i-xm,285);
    glVertex2f(-85+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(285+i-xm,175);
    glVertex2f(285+i-xm,285);
    glVertex2f(125+i-xm,285);
    glVertex2f(125+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-100+i-xm,75);
    glVertex2f(-100+i-xm,95);
    glVertex2f(-150+i-xm,95);
    glVertex2f(-150+i-xm,75);
    glEnd();

    // carrier 1 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-25+i-xm,50,l);
        draw_circle(225+i-xm,50,l);
       }

    //train base

    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,50);
    glVertex2f(350+i-xm,125);
    glVertex2f(755+i-xm,125);
    glVertex2f(820+i-xm,50);
    glEnd();

    //train control chamber

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(360+i-xm,125);
    glVertex2f(360+i-xm,325);
    glVertex2f(560+i-xm,325);
    glVertex2f(560+i-xm,125);
    glEnd();

    //window

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(375+i-xm,175);
    glVertex2f(375+i-xm,315);
    glVertex2f(545+i-xm,315);
    glVertex2f(545+i-xm,175);
    glEnd();

    //train top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,325);
    glVertex2f(350+i-xm,350);
    glVertex2f(570+i-xm,350);
    glVertex2f(570+i-xm,325);
    glEnd();

    //train engine
    glColor3f(1.0,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(560+i-xm,125);
    glVertex2f(560+i-xm,225);
    glVertex2f(755+i-xm,225);
    glVertex2f(755+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(580+i-xm,125);
    glVertex2f(580+i-xm,225);
    glVertex2f(590+i-xm,225);
    glVertex2f(590+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(600+i-xm,125);
    glVertex2f(600+i-xm,225);
    glVertex2f(610+i-xm,225);
    glVertex2f(610+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(735+i-xm,125);
    glVertex2f(735+i-xm,225);
    glVertex2f(745+i-xm,225);
    glVertex2f(745+i-xm,125);
    glEnd();

    //tain smoke

    glColor3f(0.196078,0.6,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(650+i-xm,225);
    glVertex2f(650+i-xm,275);
    glVertex2f(700+i-xm,275);
    glVertex2f(700+i-xm,225);
    glEnd();

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(640+i-xm,275);
    glVertex2f(640+i-xm,300);
    glVertex2f(710+i-xm,300);
    glVertex2f(710+i-xm,275);
    glEnd();

    //train head-light

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(765+i-xm,225);
    glVertex2f(765+i-xm,185);
    glVertex2f(755+i-xm,185);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(785+i-xm,225);
    glVertex2f(755+i-xm,205);

    glEnd();

    // train connector

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,75);
    glVertex2f(350+i-xm,95);
    glVertex2f(300+i-xm,95);
    glVertex2f(300+i-xm,75);
    glEnd();

    //train wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(425+i-xm,50,l);
        draw_circle(700+i-xm,50,l);
       }
}
   //Railway Station Board

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(580,500);
    glVertex2f(580,520);
    glVertex2f(590,520);
    glVertex2f(590,500);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(770,500);
    glVertex2f(770,520);
    glVertex2f(780,520);
    glVertex2f(780,500);
    glEnd();

    glColor3f(0.435294,0.258824,0.258824);
    glBegin(GL_POLYGON);
    glVertex2f(560,510);
    glVertex2f(560,540);
    glVertex2f(580,550);
    glVertex2f(780,550);
    glVertex2f(800,540);
    glVertex2f(800,510);
    glEnd();

    glColor3f(1.0,1.0,1.0);
         glRasterPos2f(570,520);
         declare("RAILWAY STATION");

    glFlush();
}


void train_comp()
{
    int l;

    //base
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(400,360);
    glVertex2f(700,360);
    glVertex2f(1100,0);
    glEnd();

    //borderbase
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(400,350);
    glVertex2f(400,360);
    glVertex2f(700,360);
    glVertex2f(700,350);
    glEnd();

    //front
   glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(400,360);
    glVertex2f(400,1250);
    glVertex2f(700,360);
    glVertex2f(700,1250);
    glEnd();

    //borderfront1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(390,350);
    glVertex2f(390,1250);
    glVertex2f(400,350);
    glVertex2f(400,1250);
    glEnd();

    //borderfront2
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(700,350);
    glVertex2f(700,1250);
    glVertex2f(710,1250);
    glVertex2f(710,350);
    glEnd();

     //left
   glColor3f(0.0, 0.4, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,1250);
    glVertex2f(390,1250);
    glVertex2f(390,350);
    glEnd();

    //right
    glColor3f(0.0, 0.4, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(710,350);
    glVertex2f(710,1250);
    glVertex2f(1100,1250);
    glVertex2f(1100,0);
    glEnd();

    //Left window 1
    //blue
   glColor3f(0.0, 255.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(20,275);
    glVertex2f(20,500);
    glVertex2f(155,575);
    glVertex2f(155,380);
    glEnd();
    //white
    glColor3f(1.0,1.6,1.8);
    glBegin(GL_POLYGON);
    glVertex2f(25,300);
    glVertex2f(25,475);
    glVertex2f(150,550);
    glVertex2f(150,395);
    glEnd();

    //tree 1
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(70,335);
    glVertex2f(70,400);
    glVertex2f(90,400);
    glVertex2f(90,350);
    glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,400,l);
		draw_circle(100,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(70,440,l);
		draw_circle(90,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(80,470,l);
	}


    //Left grills 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(25,350);
    glVertex2f(150,435);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(25,390);
    glVertex2f(150,475);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(25,430);
    glVertex2f(150,515);
    glEnd();


    //Left window 2
    //blue
    glColor3f(0.0, 255.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200,400);
    glVertex2f(200,590);
    glVertex2f(340,675);
    glVertex2f(340,505);
    glEnd();
    //white
    glColor3f(1.0,1.6,1.8);
    glBegin(GL_POLYGON);
    glVertex2f(210,425);
    glVertex2f(210,575);
    glVertex2f(330,650);
    glVertex2f(330,510);
    glEnd();



    //tree 2
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(260,455);
    glVertex2f(260,500);
    glVertex2f(280,500);
    glVertex2f(280,470);
    glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(245,500,l);
		draw_circle(280,520,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(250,535,l);
		draw_circle(270,550,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(260,570,l);
	}

     //Left grills 2

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(210,535);
    glVertex2f(330,610);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(210,495);
    glVertex2f(330,570);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(210,455);
    glVertex2f(330,535);
    glEnd();


     //Right window 1
     //blue
    glColor3f(0.0, 255.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(930,380);
    glVertex2f(930,570);
    glVertex2f(1070,500);
    glVertex2f(1070,275);
    glEnd();
    //white
    glColor3f(1.0,1.6,1.8);
    glBegin(GL_POLYGON);
    glVertex2f(940,390);
    glVertex2f(940,545);
    glVertex2f(1060,480);
    glVertex2f(1060,305);
    glEnd();


    //tree
    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(990,355);
    glVertex2f(990,455);
    glVertex2f(1010,455);
    glVertex2f(1010,340);
    glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(980,420,l);
		draw_circle(1020,410,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(990,450,l);
		draw_circle(1010,450,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1000,480,l);
	}

    //right grills 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(940,500);
    glVertex2f(1060,435);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(940,465);
    glVertex2f(1060,400);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(940,430);
    glVertex2f(1060,360);
    glEnd();

    //Right window 2
    //blue
    glColor3f(0.0, 255.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(750,480);
    glVertex2f(750,650);
    glVertex2f(880,585);
    glVertex2f(880,400);
    glEnd();
    //white
    glColor3f(1.0,1.6,1.8);
    glBegin(GL_POLYGON);
    glVertex2f(760,490);
    glVertex2f(760,630);
    glVertex2f(870,570);
    glVertex2f(870,420);
    glEnd();

    glColor3f(0.9,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(805,460);
    glVertex2f(805,525);
    glVertex2f(825,565);
    glVertex2f(825,444);
    glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(795,510,l);
		draw_circle(835,500,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(805,550,l);
		draw_circle(825,545,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(815,570,l);
	}



    //grills2
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(760,525);
    glVertex2f(870,460);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(760,590);
    glVertex2f(870,530);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(760,560);
    glVertex2f(870,500);
    glEnd();

    //seats 6 left4
		glPushMatrix();
		glTranslatef(40,0,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();

		//seats 7 left3
		glPushMatrix();
		glTranslatef(-10,-100,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();


    man();
    women();



    //seats 8 right4
		glPushMatrix();
		glTranslatef(280,0,0);
	    glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();

		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();


        //seats 1 right3
		glPushMatrix();
		glTranslatef(330,-100,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,310);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();

        //seats 2 right2
        glPushMatrix();
		glTranslatef(380,-200,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,310);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();

        //seats 3 right1
		glPushMatrix();
		glTranslatef(430,-300,0);
glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();

		//seats 4 left 2nd
		glPushMatrix();
		glTranslatef(-70,-200,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();


		//seats 5 top left
		glPushMatrix();
		glTranslatef(-100,-300,0);
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(310,410);
			glVertex2f(470,410);
			glVertex2f(480,350);
		glEnd();
        glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
			glVertex2f(300,350);
			glVertex2f(280,330);
			glVertex2f(460,330);
			glVertex2f(480,350);
		glEnd();
		//seat legs
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(480,350);
			glVertex2f(480,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(460,330);
			glVertex2f(460,300);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(280,330);
			glVertex2f(280,280);
		glEnd();
		glColor3f(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(300,330);
			glVertex2f(300,300);
		glEnd();
		glPopMatrix();

    glFlush();
}


void hill()
{
int l;

    //sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glColor3f(1,1,1 );
glVertex2f(0,380);
glColor3f(0.3,0.2,1 );
glVertex2f(0,700);
glVertex2f(1100,700);
glColor3f(1,1,1 );
glVertex2f(1100,380);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(300,625,l);
}


    //hills
    glColor3f(0.6,0.3,0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0,420);
	glVertex2f(150,640);
	glVertex2f(300,420);
	glEnd();

	glColor3f(0.6,0.3,0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(280,420);
	glVertex2f(430,640);
	glVertex2f(580,420);
	glEnd();

	glColor3f(0.6,0.3,0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(550,420);
	glVertex2f(700,640);
	glVertex2f(850,420);
	glEnd();

	glColor3f(0.6,0.3,0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(820,420);
	glVertex2f(970,640);
	glVertex2f(1100,420);
	glEnd();
//grass
glColor3f(0.4,0.8,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,420);
glVertex2f(1100,420);
glVertex2f(1100,160);
glEnd();



//below track
glColor3f(0.623529,0.623529,0.372549);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,0);
glEnd();

//Railway track

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(80,0);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(150,0);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(220,0);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(290,0);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(360,0);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(430,0);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(500,0);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(570,0);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(640,0);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(710,0);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(770,0);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(840,0);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(900,0);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(970,0);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1040,0);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,0);
glEnd();

//track bounbary
glColor3f(0.8,0.4,0);
glBegin(GL_POLYGON);
glVertex2f(-100,100);
glVertex2f(-100,160);
glVertex2f(1100,160);
glVertex2f(1100,100);
glEnd();

//tree 1
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(50,245);
glVertex2f(50,355);
glVertex2f(70,355);
glVertex2f(70,245);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(40,350,l);
		draw_circle(80,350,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(50,390,l);
		draw_circle(70,390,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(60,415,l);
	}

//tree 2
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(300,245);
glVertex2f(300,355);
glVertex2f(320,355);
glVertex2f(320,245);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(290,350,l);
		draw_circle(330,350,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(300,390,l);
		draw_circle(320,390,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(310,415,l);
	}

    //house

    //roof
	glColor3f(0.6,0.2,0.12);
	glBegin(GL_POLYGON);
    glVertex2f(500,320);
    glVertex2f(650,400);
    glVertex2f(750,400);
    glVertex2f(900,320);
	glEnd();
	//room
	glColor3f(0.8,0.7,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(550,200);
    glVertex2f(550,320);
    glVertex2f(850,320);
    glVertex2f(850,200);
    glEnd();

    //door
    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(670,200);
    glVertex2f(670,300);
    glVertex2f(730,300);
    glVertex2f(730,200);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(670,200);
    glVertex2f(670,300);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(670,300);
    glVertex2f(730,300);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);

    glVertex2f(730,300);
    glVertex2f(730,200);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(700,200);
    glVertex2f(700,300);
    glEnd();

    //window1

    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(570,250);
    glVertex2f(570,300);
    glVertex2f(650,300);
    glVertex2f(650,250);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(570,275);
    glVertex2f(650,275);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(610,250);
    glVertex2f(610,300);
    glEnd();

    //window1

    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(750,250);
    glVertex2f(750,300);
    glVertex2f(830,300);
    glVertex2f(830,250);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(750,275);
    glVertex2f(830,275);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(790,250);
    glVertex2f(790,300);
    glEnd();





//tree 5
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(1030,245);
glVertex2f(1030,355);
glVertex2f(1050,355);
glVertex2f(1050,245);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1020,350,l);
		draw_circle(1060,350,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1030,390,l);
		draw_circle(1050,390,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1040,415,l);
	}


 if(train==1)
    {
    //train carrier 3

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-600+i-xm,50);
    glVertex2f(-600+i-xm,300);
    glVertex2f(-1000+i-xm,300);
    glVertex2f(-1000+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-590+i-xm,300);
    glVertex2f(-590+i-xm,310);
    glVertex2f(-1010+i-xm,310);
    glVertex2f(-1010+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-825+i-xm,175);
    glVertex2f(-825+i-xm,285);
    glVertex2f(-985+i-xm,285);
    glVertex2f(-985+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-615+i-xm,175);
    glVertex2f(-615+i-xm,285);
    glVertex2f(-775+i-xm,285);
    glVertex2f(-775+i-xm,175);
    glEnd();

    // carrier 3 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-675+i-xm,50,l);
        draw_circle(-925+i-xm,50,l);
       }

    //train carrier 2

    glColor3f(255.0,255.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-150+i-xm,50);
    glVertex2f(-150+i-xm,300);
    glVertex2f(-550+i-xm,300);
    glVertex2f(-550+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-140+i-xm,300);
    glVertex2f(-140+i-xm,310);
    glVertex2f(-560+i-xm,310);
    glVertex2f(-560+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-375+i-xm,175);
    glVertex2f(-375+i-xm,285);
    glVertex2f(-535+i-xm,285);
    glVertex2f(-535+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-165+i-xm,175);
    glVertex2f(-165+i-xm,285);
    glVertex2f(-325+i-xm,285);
    glVertex2f(-325+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-550+i-xm,75);
    glVertex2f(-550+i-xm,95);
    glVertex2f(-600+i-xm,95);
    glVertex2f(-600+i-xm,75);
    glEnd();

    // carrier 2 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-225+i-xm,50,l);
        draw_circle(-475+i-xm,50,l);
       }

    // train carrier 1


    glColor3f(0.258824,0.435294,0.258824);
    glBegin(GL_POLYGON);
    glVertex2f(300+i-xm,50);
    glVertex2f(300+i-xm,300);
    glVertex2f(-100+i-xm,300);
    glVertex2f(-100+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(310+i-xm,300);
    glVertex2f(310+i-xm,310);
    glVertex2f(-110+i-xm,310);
    glVertex2f(-110+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(75+i-xm,175);
    glVertex2f(75+i-xm,285);
    glVertex2f(-85+i-xm,285);
    glVertex2f(-85+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(285+i-xm,175);
    glVertex2f(285+i-xm,285);
    glVertex2f(125+i-xm,285);
    glVertex2f(125+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-100+i-xm,75);
    glVertex2f(-100+i-xm,95);
    glVertex2f(-150+i-xm,95);
    glVertex2f(-150+i-xm,75);
    glEnd();

    // carrier 1 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-25+i-xm,50,l);
        draw_circle(225+i-xm,50,l);
       }

    //train base

    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,50);
    glVertex2f(350+i-xm,125);
    glVertex2f(755+i-xm,125);
    glVertex2f(820+i-xm,50);
    glEnd();

    //train control chamber

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(360+i-xm,125);
    glVertex2f(360+i-xm,325);
    glVertex2f(560+i-xm,325);
    glVertex2f(560+i-xm,125);
    glEnd();

    //window

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(375+i-xm,175);
    glVertex2f(375+i-xm,315);
    glVertex2f(545+i-xm,315);
    glVertex2f(545+i-xm,175);
    glEnd();

    //train top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,325);
    glVertex2f(350+i-xm,350);
    glVertex2f(570+i-xm,350);
    glVertex2f(570+i-xm,325);
    glEnd();

    //train engine
    glColor3f(1.0,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(560+i-xm,125);
    glVertex2f(560+i-xm,225);
    glVertex2f(755+i-xm,225);
    glVertex2f(755+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(580+i-xm,125);
    glVertex2f(580+i-xm,225);
    glVertex2f(590+i-xm,225);
    glVertex2f(590+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(600+i-xm,125);
    glVertex2f(600+i-xm,225);
    glVertex2f(610+i-xm,225);
    glVertex2f(610+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(735+i-xm,125);
    glVertex2f(735+i-xm,225);
    glVertex2f(745+i-xm,225);
    glVertex2f(745+i-xm,125);
    glEnd();

    //tain smoke

    glColor3f(0.196078,0.6,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(650+i-xm,225);
    glVertex2f(650+i-xm,275);
    glVertex2f(700+i-xm,275);
    glVertex2f(700+i-xm,225);
    glEnd();

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(640+i-xm,275);
    glVertex2f(640+i-xm,300);
    glVertex2f(710+i-xm,300);
    glVertex2f(710+i-xm,275);
    glEnd();

    //train head-light

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(765+i-xm,225);
    glVertex2f(765+i-xm,185);
    glVertex2f(755+i-xm,185);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(785+i-xm,225);
    glVertex2f(755+i-xm,205);

    glEnd();

    // train connector

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,75);
    glVertex2f(350+i-xm,95);
    glVertex2f(300+i-xm,95);
    glVertex2f(300+i-xm,75);
    glEnd();

    //train wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(425+i-xm,50,l);
        draw_circle(700+i-xm,50,l);
       }
}

glFlush();
}


void river()
{
int l;

    //sky

glBegin(GL_POLYGON);
glColor3f(1,0.3,0.2);
glVertex2f(0,380);
glColor3f(0.2,0.4,1);
glVertex2f(0,700);
glVertex2f(1100,700);
glColor3f(1,0.3,0.2);
glVertex2f(1100,380);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1,0.5,0);
		draw_circle(580,380,l);
}

//grass
glBegin(GL_POLYGON);
glColor3f(0.1,0.3,0);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

//river
glBegin(GL_POLYGON);
glColor3f(0.3,0,0.8);
glColor3f(0.3,0,1);
glColor3f(0.3,0.1,0.9);
glVertex2f(0,160);
glColor3f(1,0.6,0.4);
glVertex2f(400,380);
glVertex2f(800,380);
glColor3f(0.3,0,1);
glColor3f(0.3,0.1,0.9);
glVertex2f(1100,160);
glEnd();

//boat
glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(460,240);
glVertex2f(410,270);
glVertex2f(580,270);
glVertex2f(520,240);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(470,270);
glVertex2f(490,300);
glVertex2f(510,270);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(720,330);
glVertex2f(890,330);
glVertex2f(850,305);
glVertex2f(770,305);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(780,330);
glVertex2f(805,350);
glVertex2f(830,330);
glEnd();

//below track
glColor3f(0.623529,0.623529,0.372549);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,0);
glEnd();

//Railway track

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(80,0);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(150,0);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(220,0);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(290,0);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(360,0);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(430,0);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(500,0);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(570,0);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(640,0);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(710,0);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(770,0);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(840,0);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(900,0);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(970,0);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1040,0);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,0);
glEnd();

//track bounbary
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(-100,100);
glVertex2f(-100,160);
glVertex2f(1100,160);
glVertex2f(1100,100);
glEnd();

//tree 1
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(50,245);
glVertex2f(50,355);
glVertex2f(70,355);
glVertex2f(70,245);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(40,350,l);
		draw_circle(80,350,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(50,390,l);
		draw_circle(70,390,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(60,415,l);
	}

//tree 2
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(170,300);
glVertex2f(170,405);
glVertex2f(190,405);
glVertex2f(190,300);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(160,400,l);
		draw_circle(200,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(170,440,l);
		draw_circle(190,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(180,460,l);
	}

	//tree 2
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(940,300);
glVertex2f(940,405);
glVertex2f(960,405);
glVertex2f(960,300);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(930,400,l);
		draw_circle(970,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(930,440,l);
		draw_circle(960,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(945,460,l);
	}




//tree 4
glColor3f(0.5,0.1,0);
glBegin(GL_POLYGON);
glVertex2f(1030,245);
glVertex2f(1030,355);
glVertex2f(1050,355);
glVertex2f(1050,245);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1020,350,l);
		draw_circle(1060,350,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1030,390,l);
		draw_circle(1050,390,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.2,0.0);
		draw_circle(1040,415,l);
	}

 if(train==1)
    {
    //train carrier 3

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-600+i-xm,50);
    glVertex2f(-600+i-xm,300);
    glVertex2f(-1000+i-xm,300);
    glVertex2f(-1000+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-590+i-xm,300);
    glVertex2f(-590+i-xm,310);
    glVertex2f(-1010+i-xm,310);
    glVertex2f(-1010+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-825+i-xm,175);
    glVertex2f(-825+i-xm,285);
    glVertex2f(-985+i-xm,285);
    glVertex2f(-985+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-615+i-xm,175);
    glVertex2f(-615+i-xm,285);
    glVertex2f(-775+i-xm,285);
    glVertex2f(-775+i-xm,175);
    glEnd();

    // carrier 3 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-675+i-xm,50,l);
        draw_circle(-925+i-xm,50,l);
       }

    //train carrier 2

    glColor3f(255.0,255.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-150+i-xm,50);
    glVertex2f(-150+i-xm,300);
    glVertex2f(-550+i-xm,300);
    glVertex2f(-550+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-140+i-xm,300);
    glVertex2f(-140+i-xm,310);
    glVertex2f(-560+i-xm,310);
    glVertex2f(-560+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-375+i-xm,175);
    glVertex2f(-375+i-xm,285);
    glVertex2f(-535+i-xm,285);
    glVertex2f(-535+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-165+i-xm,175);
    glVertex2f(-165+i-xm,285);
    glVertex2f(-325+i-xm,285);
    glVertex2f(-325+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-550+i-xm,75);
    glVertex2f(-550+i-xm,95);
    glVertex2f(-600+i-xm,95);
    glVertex2f(-600+i-xm,75);
    glEnd();

    // carrier 2 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-225+i-xm,50,l);
        draw_circle(-475+i-xm,50,l);
       }

    // train carrier 1


    glColor3f(0.258824,0.435294,0.258824);
    glBegin(GL_POLYGON);
    glVertex2f(300+i-xm,50);
    glVertex2f(300+i-xm,300);
    glVertex2f(-100+i-xm,300);
    glVertex2f(-100+i-xm,50);
    glEnd();

    //top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(310+i-xm,300);
    glVertex2f(310+i-xm,310);
    glVertex2f(-110+i-xm,310);
    glVertex2f(-110+i-xm,300);
    glEnd();

    // Windows

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(75+i-xm,175);
    glVertex2f(75+i-xm,285);
    glVertex2f(-85+i-xm,285);
    glVertex2f(-85+i-xm,175);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(285+i-xm,175);
    glVertex2f(285+i-xm,285);
    glVertex2f(125+i-xm,285);
    glVertex2f(125+i-xm,175);
    glEnd();

    //connecter

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(-100+i-xm,75);
    glVertex2f(-100+i-xm,95);
    glVertex2f(-150+i-xm,95);
    glVertex2f(-150+i-xm,75);
    glEnd();

    // carrier 1 Wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(-25+i-xm,50,l);
        draw_circle(225+i-xm,50,l);
       }

    //train base

    glColor3f(0.196078,0.6,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,50);
    glVertex2f(350+i-xm,125);
    glVertex2f(755+i-xm,125);
    glVertex2f(820+i-xm,50);
    glEnd();

    //train control chamber

    glColor3f(1.0,0.25,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(360+i-xm,125);
    glVertex2f(360+i-xm,325);
    glVertex2f(560+i-xm,325);
    glVertex2f(560+i-xm,125);
    glEnd();

    //window

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(375+i-xm,175);
    glVertex2f(375+i-xm,315);
    glVertex2f(545+i-xm,315);
    glVertex2f(545+i-xm,175);
    glEnd();

    //train top

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,325);
    glVertex2f(350+i-xm,350);
    glVertex2f(570+i-xm,350);
    glVertex2f(570+i-xm,325);
    glEnd();

    //train engine
    glColor3f(1.0,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(560+i-xm,125);
    glVertex2f(560+i-xm,225);
    glVertex2f(755+i-xm,225);
    glVertex2f(755+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(580+i-xm,125);
    glVertex2f(580+i-xm,225);
    glVertex2f(590+i-xm,225);
    glVertex2f(590+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(600+i-xm,125);
    glVertex2f(600+i-xm,225);
    glVertex2f(610+i-xm,225);
    glVertex2f(610+i-xm,125);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(735+i-xm,125);
    glVertex2f(735+i-xm,225);
    glVertex2f(745+i-xm,225);
    glVertex2f(745+i-xm,125);
    glEnd();

    //tain smoke

    glColor3f(0.196078,0.6,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(650+i-xm,225);
    glVertex2f(650+i-xm,275);
    glVertex2f(700+i-xm,275);
    glVertex2f(700+i-xm,225);
    glEnd();

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(640+i-xm,275);
    glVertex2f(640+i-xm,300);
    glVertex2f(710+i-xm,300);
    glVertex2f(710+i-xm,275);
    glEnd();

    //train head-light

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(765+i-xm,225);
    glVertex2f(765+i-xm,185);
    glVertex2f(755+i-xm,185);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(755+i-xm,225);
    glVertex2f(785+i-xm,225);
    glVertex2f(755+i-xm,205);

    glEnd();

    // train connector

    glColor3f(0.309804,0.184314,0.184314);
    glBegin(GL_POLYGON);
    glVertex2f(350+i-xm,75);
    glVertex2f(350+i-xm,95);
    glVertex2f(300+i-xm,95);
    glVertex2f(300+i-xm,75);
    glEnd();

    //train wheels

    for(l=0;l<50;l++)
       {
        glColor3f(0.35,0.16,0.14);
        draw_circle(425+i-xm,50,l);
        draw_circle(700+i-xm,50,l);
       }
    }
glFlush();
}


void traffic_light()
{
        int l;
    if(light==1)
          {
    for(l=0;l<=20;l++)
            {

    glColor3f(0.0,0.0,0.0);
            draw_circle(1065,475,l);

            glColor3f(0.0,0.7,0.0);
            draw_circle(1065,375,l);
            }
          }

        else
          {

    for(l=0;l<=20;l++)
            {
            glColor3f(1.0,0.0,0.0);
            draw_circle(1065,475,l);

            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,375,l);
            }
          }
}


void idle()
{
    glClearColor(1.0,1.0,1.0,1.0);

    if(light==0 && (i>=0 && i<=1150))
     {

         i+=SPEED/10;
         m+=SPEED/150;
        n-=2;
         o+=0.2;
        c+=2;

     }

     if(light==0 && (i>=2600 && i<=3000))
     {

         i+=SPEED/10;
         m+=SPEED/150;
        n-=2;
         o+=0.2;
        c+=2;

     }

    if(light==0)
     {
         i=i;
         m+=SPEED/150;
        n-=2;
         o+=0.2;
        c+=2;

     }

    else
     {

         i+=SPEED/10;
         m+=SPEED/150;
        n-=2;
         o+=0.2;
        c+=2;
     }
    if(i>3500)
         i=0.0;
    if(m>1100)
         m=0.0;
    if( o>75)
     {
        plane=0;
     }
    if(c>500)
     {
        comet=0;
     }
    glutPostRedisplay();

}


void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
    exit(0);
}


void drawstring(float x,float y,float z,char *string)
{
     char *c;
     glRasterPos3f(x,y,z);
     for(c=string;*c!='\0';c++)
     {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
     }
}


void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}


void display(void)
{

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0,0.0,0.0);
        drawstring(400,515,0.0,"Simulation of Railway Station");

        glColor3f(1.0,0.0,0.0);
        drawstring(250,280,0.0,"Mahima Biswas");
        drawstring(250,250,0.0,"Nidhi Rai");
            glColor3f(1.0,0.0,0.0);
            drawstring(600,280,0.0,"4NM18CS087");
        drawstring(600,250,0.0,"4NM18CS103");
        drawstring(380,150,0.0,"*Click on this page and Press enter*");
        glFlush();
}

void display_front()
{
   glClear(GL_COLOR_BUFFER_BIT);
   display();
   glFlush();
}


void display_screen()
{
   glClear(GL_COLOR_BUFFER_BIT);
   draw_object();
   traffic_light();
   glFlush();
}


void display_comp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    train_comp();
    glFlush();
}


void display_hill()
{
    glClear(GL_COLOR_BUFFER_BIT);
    hill();
    glFlush();
}


void display_river()
{
    glClear(GL_COLOR_BUFFER_BIT);
    river();
    glFlush();
}

void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'p':
case 'P':
     glutDisplayFunc(display_screen);
     glutPostRedisplay();
     break;


case 'g':
case 'G':
light=1;
break;

	case 'r':
	case 'R':
		light=0;
        man_show=0;

		break;

case 'd':
	case 'D':
		day=1;
		break;

	case 'n':
case 'N':
		day=0;
		break;

	case 't':
case 'T':
		train=1;
		i=0;
		break;

case 'i':
case 'I':
     glutDisplayFunc(display_comp);
     glutPostRedisplay();
     break;

case 'h':
case 'H':
     glutDisplayFunc(display_hill);
     glutPostRedisplay();
     break;

case 'v':
case 'V':
     glutDisplayFunc(display_river);
     glutPostRedisplay();
     break;
    };

}


void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	}
}


void keyFun(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 13:

            glutDisplayFunc(display_screen);
            glutMouseFunc(mouse);
            glutIdleFunc(idle);
            glutKeyboardFunc(keyboardFunc);
            glutPostRedisplay();
            break;

    };
}


int main(int argc,char** argv)
{
    PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\3. Projects - Engineering\\Computer Graphics\\music.wav"),NULL,SND_ASYNC);
    printf("\n---------------------------");
    printf("ARRIVAL AND DEPARTURE OF TRAIN");
    printf("-----------------------------\n");
	printf("\nPress 'r' or 'R' to change the signal light to red. \n\n");
	printf("Press 'g' or 'G' to change the signal light to green. \n\n");
    printf("Press 'd' or 'D' to make it day. \n\n");
	printf("Press 'n' or 'N' to make it night. \n\n");
	printf("Press 't' or 'T' Train arrive at station.\n\n");
	printf("Press RIGHT MOUSE BUTTON to display menu. \n\n");
	printf("Press LEFT MOUSE BUTTON to quit the program. \n\n");
	printf("Press 'i' for the next screen .\n\n\n");
	printf("Press any key and Hit ENTER.\n");
	scanf("%s",&ch);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
    glutCreateWindow("Simulation of Railway Station");

    glutDisplayFunc(display);
    myinit();

    glutIdleFunc(idle);
    glutKeyboardFunc(keyFun);

    c_menu=glutCreateMenu(main_menu);
    glutAddMenuEntry("Aeroplane",1);
    glutAddMenuEntry("Comet",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;

}
