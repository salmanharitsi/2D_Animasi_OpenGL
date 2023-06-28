#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
GLfloat sun_scale_factor = 1.0;
float shearx, sheary, shearxy = 0;
float shearx2, sheary2 = 0;
bool sun_increasing = true;
float cloudScale = 1.0f;        
bool increaseScale = true;      

void init(void)
{
	glClearColor(.40, .110, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

///============================================================================================================///

///=================///
///*** All_Model ***///
///=================///

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

float pindahx, pindahy;
/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(400+pindahx,200+pindahy,0);
    circle(60);
    glPopMatrix();
}

float sunScale = 1;

void Sun_Model2(){
    glPushMatrix();
    circle(60);
    glPopMatrix();
}

//besar ke kecil
void Moving_Sun_Model() {
    glPushMatrix();
    glRotatef(-sun_spin, 0, 0, -0.009);

    // Faktor skala untuk mengatur ukuran matahari
    GLfloat min_scale = 5.0;
    GLfloat max_scale = 0.01;
    static GLfloat current_scale = min_scale;
    static bool increasing = true;

    // Menerapkan skala matahari
    glScalef(current_scale, current_scale, current_scale);

    Sun_Model();
    glPopMatrix();

    // Memperbarui faktor skala untuk membuat matahari berubah dari kecil ke besar
    if (increasing) {
        current_scale -= 0.0003;  // Nilai peningkatan skala
        if (current_scale <= max_scale) {
            current_scale = max_scale;
            increasing = false;
        }
    } else {
        current_scale += 5;  // Nilai penurunan skala
        if (current_scale >= min_scale) {
            current_scale = min_scale;
            increasing = true;
        }
    }
}

///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();

    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();
    
    

    ///****Fill End****
}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
//    glTranslatef(305,205,0);
    glTranslatef(-15,-5,0);
    circle(10);
    glPopMatrix();

    ///Top
    glPushMatrix();
//    glTranslatef(320,210,0);
    glTranslatef(0,0,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
//    glTranslatef(334,207,0);
    glTranslatef(14,-3,0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Three(bool reflected, int r, int g, int b){
	
	int reflect;
	int repost;
	if(reflected == true){
		reflect = -1;
		repost = 300;
	}else{
		reflect = 1;
		repost = 0;
	}
    glColor3f(r, g, b);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200*reflect+repost,0);
    circle(15);
    glPopMatrix();

    ///Top_Left
    glPushMatrix();
    glTranslatef(320,210*reflect+repost,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220*reflect+repost,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210*reflect+repost,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200*reflect+repost,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190*reflect+repost,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190*reflect+repost,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190*reflect+repost,0);
    circle(20);
    glPopMatrix();

    ///****Fill End****
}

///*** Hill_Model***///
void hill_big(){	

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.19, 0.19, 0.19);
	glVertex2i(70, 70);
	glVertex2i(200+shearx, 225+sheary);
	glVertex2i(330, 70);

	glEnd();

    glPushMatrix();
    glTranslatef(200+shearx, 225+sheary, 0);
    glBegin(GL_POLYGON);
    glEnd();
    glPopMatrix();
}

void hill_big2(){	

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.19, 0.19, 0.19);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    // Hill_Snow dengan perubahan skala
    glPushMatrix();
    glTranslatef(200, 225, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glEnd();
    glPopMatrix();
}
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);

	glEnd();
}

bool isDarkening = false;
float red = 9.0f;
float green = 163.0f;
float blue = 204.0f;
float transitionTime = 150.0f; // Waktu transisi gelap/terang (dalam detik)
float elapsedTime = 0.0f;    // Waktu yang telah berlalu

void sky_model() {
    if (isDarkening) {
        red -= 9.0f / transitionTime * 0.01f;
        green -= 163.0f / transitionTime * 0.01f;
        blue -= 204.0f / transitionTime * 0.01f;
        elapsedTime += 0.01f;

        if (elapsedTime >= transitionTime) {
            isDarkening = false;
        }
    } else {
        red += 9.0f / transitionTime * 0.01f;
        green += 163.0f / transitionTime * 0.01f;
        blue += 204.0f / transitionTime * 0.01f;
        elapsedTime -= 0.01f;

        if (elapsedTime <= 0.0f) {
            isDarkening = true;
        }
    }

    glColor3ub(static_cast<GLubyte>(red), static_cast<GLubyte>(green), static_cast<GLubyte>(blue));
    glBegin(GL_POLYGON);
    glVertex2i(-500, 500);
    glVertex2i(500, 500);
    glVertex2i(500, -500);
    glVertex2i(-500, -500);
    glEnd();
}

void sky_model2(){
	glClear(GL_COLOR_BUFFER_BIT);  // clear color buffer
  	glColor3f(1.0, 1.0, 1.0);      // set drawing color to white
	glLoadIdentity();
	
	if (sunScale > 0) {
       // langit 
  	glBegin(GL_POLYGON);
  	glColor3ub(173, 10, 108);
 	glVertex2f(-1.0, 1.0);
  
 	glColor3ub(255, 204, 0);
  	glVertex2f(-1.0, -1.0);
  
 	glColor3ub(255, 204, 0);
 	glVertex2f(1.0, -1.0);
  
  	glColor3ub(173, 10, 108);
  	glVertex2f(1.0, 1.0);
  	glEnd();
    } 
    else {
       	glBegin(GL_POLYGON);
  	glColor3ub(0, 0, 0);
 	glVertex2f(-1.0, 1.0);
 	
 	glColor3ub(32, 37, 102);
  	glVertex2f(-1.0, -1.0);
  
 	glColor3ub(32, 37, 102);
 	glVertex2f(1.0, -1.0);
  
  	glColor3ub(0, 0, 0);
  	glVertex2f(1.0, 1.0);
  	glEnd();
    }
}

///*** Tilla_Model ***///
void Tilla_One_Model(){
    ///Tilla
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}

void Tilla_Two_Model(){

	glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();
}



///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285+shearx2, 105+sheary2);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285+shearx2, 105+sheary2);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();
}

void house2(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.41, 0.41, 0.41);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();
}

///*** Field_Model ***///
void field(){
    ///Field
	glBegin(GL_POLYGON);
    glColor3ub(0, 115, 27);
	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 50);

	glEnd();

    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub(0, 65, 25);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);

	glEnd();


}
///*** Tree_Model ***///
void Tree_Model_One(){
	
    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}


void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 110);
	glVertex2f(129, 124);
	glVertex2f(131, 124);
	glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three(){

    glBegin(GL_POLYGON);

	glVertex2f(125, 123);
	glVertex2f(133, 145);
	glVertex2f(141, 123);

	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 110);
	glVertex2f(132, 124);
	glVertex2f(134, 124);
	glVertex2f(134, 110);

    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

//mengubah arah putaran kincir angin
void Windmill_Blade(){
    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,-90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,-90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,-90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}

void Windmill_Blade2(){
    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}

///*** Windmill_Final_Model ***///
void Windmill(){

        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();
}

void Windmill2(){

        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade2();
    glPopMatrix();
}


///Model_End
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

float scalexy1;
void Sun2(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(600+pindahx,400+pindahy,0);
    glScalef(sunScale,sunScale,1);
    
    if (sunScale > 0){
    	Sun_Model2();
	}
	else{
		glColor3f(1, 1, 1);
		Sun_Model2();
	}
    
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,-40,0);
    cloud_model_one();
    glPopMatrix();
}

///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model_one();
    glPopMatrix();
}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax+80,310,0);
    cloud_model_Two();
//    cloud_model_Two(false, 1,1,1);
//    cloud_model_Two(true, 0,0,0);
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
//    cloud_model_Two(false, 1,1,1);
//    cloud_model_Two(true, 0,0,0);
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five(){
    cloud_model_Three(false, 1,1,1);
    cloud_model_Three(true,0,0,0);
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six(){

    glPushMatrix();
    glTranslatef(cx+-500,20,0);
    cloud_model_Three(false,1,1,1);
    cloud_model_Three(true,0,0,0);
    glPopMatrix();
}

///*** House_One ***///
void house_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}
//bayangan rumah
void house_one2(){
    glPushMatrix();
    glScalef(1,-1,1);
    glTranslatef(0,-140,0);
    house2();
    glPopMatrix();
}
///*** House_Two ***///
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
//bayangan rumah
void house_two2(){
    glPushMatrix();
    glScalef(1,-1,1);
    glTranslatef(450,-140,0);
    house2();
    glPopMatrix();
}
///*** House_Two ***///
void house_three(){
    glPushMatrix();
    glTranslatef(320, 37,0);
    house();
    glPopMatrix();
}
///*** Sky ***///
void sky(){
	glPushMatrix();
    glTranslatef(500,0,0);
    sky_model();
    glPopMatrix();
}

void sky2(){
	glPushMatrix();
    glTranslatef(500,0,0);
    sky_model2();
    glPopMatrix();
}

///*** Hill_big_One ***///
void Hill_Big_One(){
    glPushMatrix();
//    glScalef(1+scalexy,1+scalexy,1);
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_big2();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_small();
    glPopMatrix();

}
/// *** Tilla_One_Model_One ***///
void Tilla_One(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three(){

    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four(){

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    Tilla_One_Model();
    glPopMatrix();
}
///*** Tree_1 ***///
void Tree_One(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model_One();
//    Tree_Model_One(false);
//    Tree_Model_One(true);
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540,0,0);
	Tree_Model_One();
//    Tree_Model_One(false);
//    Tree_Model_One(true);
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
//    Tree_Model_One(false);
//    Tree_Model_One(true);
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,0,0);
    Tree_Model_One();
//    Tree_Model_One(false);
//    Tree_Model_One(true);
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-20,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve(){
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-190,-40,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill2();
    glPopMatrix();

}
///Object_End
///=========================================================================================================///


///========================///
///*** Display Function ***///
///========================///

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///

	sky2();
    Sun();

    Windmill_Three();

    Hill_Big_One();
    Hill_Big_Two();
    cloud_three();
    Windmill_One();
    Windmill_Two();

	field();
	house_one();

    cloud_one();
    house_two();
    
	Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();

    cloud_six();
    
	glFlush();
}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move(){

    sun_spin = sun_spin + 0.0;

}

//mengubah arah gerak awan
void move_right(){

    sun_move();

    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    
	if(ax>1000){
        ax = -500;
    }
    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
        bx= -500;
    }
    if(cx>1000){
        cx= -500;
    }
    if(dx>1000){
        dx= -500;
    }

    glutPostRedisplay();
}

//Keyboard
void keyboardFunc(unsigned char key, int x, int y) {
    if (key == 27)  // ESC key
        exit(0);
        else if(key == 'i'){
        	sheary += 0.9;
        }else if(key == 'k'){
        	sheary -= 0.9;
        }else if(key == 'j'){
        	 shearx -= 0.9;
        }else if(key == 'l'){
        	shearx += 0.9;
        }else if(key == 'p'){
        	sunScale += 0.1;
        }else if(key == 'o'){
        	sunScale -= 0.1;
        }
        else if(key == 'w'){
        	sheary2 += 0.9;
        }else if(key == 's'){
        	sheary2 -= 0.9;
        }else if(key == 'a'){
        	 shearx2 -= 0.9;
        }else if(key == 'd'){
        	shearx2 += 0.9;
        }
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 450);
	glutCreateWindow("UAS-SALMAN AL HARITSI");
	init();
	glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboardFunc);
	glutMainLoop();
}
