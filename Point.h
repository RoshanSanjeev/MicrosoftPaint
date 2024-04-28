#ifndef POINT_H
#define POINT_H
#include <GL/freeglut.h>
#include "Color.h"
struct Point{
private:
    float mx;
    float my; 
    Color color;
public:
    Point(){
    }

    Point(float mx, float my, Color color){
        this->mx=mx;
        this->my=my;
        this->color=color;
    }
    Point(float mx, float my, float r, float g, float b){
        this->mx=mx;
        this->my=my;
        color.setColor(r,g,b);
    }
    float getmx(){
        return mx;
    }
    float getmy(){
        return my;
    }
    void isSelected(float mx){
        
    }
    void setmx(float mx){
        this->mx=mx;
    }
    void setmy(float my){
        this->my=my;
    }
    void setB(float blue){
        color.setB(blue);

    }
    void draw(){
        glColor3f(color.getR(), color.getG(), color.getB());
        glPointSize(10.5f);
        glBegin(GL_POINTS);
            glVertex2f(mx,my);
        glEnd();       
    }

    void setColor(Color c) {
        color.setColor(c.getR(),c.getG(),c.getB());
    }
    void setColor(float r, float g, float b){
        color.setColor(r,g,b);
    }
};

#endif
