#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Color.h"
#include <GL/freeglut.h>
#include "Shape.h"
struct Triangle : public Shape{
private:
    float mx;
    float my;
    //below are the rgb values for the selection box on the shape
public: 
    Triangle(){
        mx=0;
        my=0;
    }
    Triangle(float mx, float my, float r, float g, float b){
        this->mx=mx;
        this->my=my;
        color.setColor(r,g,b);
        selectedColor.setColor(r,g,b);        
    }
    float getmx(){
        return mx;
    }
    float getmy(){
        return my;
    }
 
    void setmx(float mx){
        this->mx=mx;
    }
    void setmy(float my){
        this->my=my;
    }
    void draw(){
        glPointSize(10.5f);
        glColor3f(color.getR(), color.getG(), color.getB());
                glBegin(GL_POLYGON);
                    glVertex2f(mx,my+0.12);
                    glVertex2f(mx+0.12,my-0.12);
                    glVertex2f(mx-0.12,my-0.12);           
                glEnd();
                coordinates[0]=mx-0.05;
                coordinates[1]=mx+0.05;
                coordinates[2]=my-0.1;
                coordinates[3]=my+0.05;  
        //draw shape selection box that only changes color when shape is selected
        //for the rectangle and the square and the rhombus
            //draw selection box
            glColor3f(selectedColor.getR(), selectedColor.getG(), selectedColor.getB());
            glLineWidth(3.0f);

                glBegin(GL_LINES);
                glVertex2f(mx,my+0.12);
                glVertex2f(mx+0.12,my-0.12);

                glVertex2f(mx+0.12,my-0.12);
                glVertex2f(mx-0.12,my-0.12);  

                glVertex2f(mx-0.12,my-0.12);   
                glVertex2f(mx,my+0.12);  
                glEnd();
    }
    bool isSelected(float mx, float my){
        if(mx>coordinates[0]&&mx<coordinates[1]
                &&my>coordinates[2]&&my<coordinates[3]){   
        
                return true;
            }
            else{
         
                return false;
            }
    }
    void move(float mx, float my){
        this->mx=mx;
        this->my=my;
        coordinates[0]=mx-0.05;
        coordinates[1]=mx+0.05;
        coordinates[2]=my-0.1;
        coordinates[3]=my+0.05;  
    }
};
#endif
