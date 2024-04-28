#ifndef BUTTON_H
#define BUTTON_H
#include <GL/freeglut.h>
#include "Color.h"

struct Button{
private:
    Color color;
    float x1;
    float x2;
    float y1;
    float y2;
    float a1;
    float a2;
    float z1;
    float z2;
public:
    Button(){
        x1=-0.2f;
        x2=0.2f;
        y1=0.2f;
        y2=0.2f;
        a1=0.2f;
        a2=-0.2f;
        z1=-0.2f;
        z2=-0.2f;
    } 
    Button(Color color,float tx1,float tx2, float ty1,float ty2,float ta1, float ta2,float tz1,float tz2){
        this->color=color;
        x1=tx1;
        x2=tx2;
        y1=ty1;
        y2=ty2;
        a1=ta1;
        a2=ta2;
        z1=tz1;
        z2=tz2;
        glColor3f(color.getR(), color.getG(), color.getB());
    }  
    Button(float tr,float tg, float tb,float tx1,float tx2, float ty1,float ty2,float ta1, float ta2,float tz1,float tz2){
        color.setColor(tr,tg,tb);
        x1=tx1;
        x2=tx2;
        y1=ty1;
        y2=ty2;
        a1=ta1;
        a2=ta2;
        z1=tz1;
        z2=tz2;
        glColor3f(color.getR(), color.getG(), color.getB());

    }  
    float getx1(){
        return x1;
    }
    float gety1(){
        return y1;
    }
    void draw(){

        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
            glVertex2f(x1,x2);
            glVertex2f(y1,y2);
            glVertex2f(a1,a2);
            glVertex2f(z1,z2);           
        glEnd();
    }
    void setR(float r){
        color.setR(r);
    }
    void setG(float g){
        color.setG(g);
    }
    void setB(float b){
        color.setB(b);
    }
    void setColor(Color COLOR) {
        color=COLOR;
    }
    void setColor(float r, float g, float b){
        color.setColor(r,g,b);
    }   
    //the following functions are used for the size selection buttons to indicate which ones are pressed
    //by setting them as either the color green for on, or black for off.
    void setGreen(){
        color.setColor(0.0f,1.0f,0.0f);
    }
    void setBlack(){
        color.setColor(0.0f,0.0f,0.0f);
    }
    //returns if a button is clicked
    bool isClicked(float mx, float my) {
        if (mx>=x1 &&mx<=y1 && my>=z2 &&my<=x2) {
            return true;
        } else {
            return false;
        }
    }
    void move(float mx){
        x1=mx-.03;

        y1=mx+0.03;

        a1=mx+0.03;

        z1=mx-0.03;
    }

    //function for buttons that shows whether they are selected or not
    void Clicked(int x){
        if(x==0){//yes selected
            glColor3f(1,1,1);
        }
        if(x==1){
            glColor3f(0.5,0.5,0.5);
        }
        glLineWidth(0.1f);
        //Draw select box
        glBegin(GL_LINES);
            glVertex2f(x1+0.005,x2-0.005);
            glVertex2f(y1-0.005,y2-0.005);
            glVertex2f(y1-0.005,y2-0.005);
            glVertex2f(a1-0.005,a2+0.01);
            glVertex2f(a1-0.005,a2+0.01);
            glVertex2f(z1+0.005,z2+0.01);
            glVertex2f(z1+0.005,z2+0.01);
            glVertex2f(x1+0.005,x2-0.005);
        glEnd();
    }
};

#endif
