#ifndef SCRIBBLE_H
#define SCRIBBLE_H
#include "Color.h"
#include <GL/freeglut.h>
#include "Shape.h"
#include "Point.h"
#include "Color.h"
struct Scribble : public Shape{
private:
    int counter;
    Point points[1000];
    float x;
    float y;
    float leftX;
    float rightX;
    float topY;
    float bottomY;

public: 
    Scribble(){
        counter=0;
    }
    Scribble( float mx, float my, float r, float g, float b){
        counter=0;
        leftX=mx;
        rightX=mx;
        topY=my;
        bottomY=my;
        selected=false;
        color.setColor(r,g,b);
        this->addPoint(Point(mx,my,color));
        leftX=mx;
        rightX=mx;
        topY=my;
        bottomY=my;
    }
    Scribble( float mx, float my, Color c){
        counter=0;
        leftX=mx;
        rightX=mx;
        topY=my;
        bottomY=my;
        selected=false;
        color.setColor(c.getR(),c.getG(),c.getB());
        this->addPoint(Point(mx,my,color));
        leftX=mx;
        rightX=mx;
        topY=my;
        bottomY=my;
    }
    void draw(){
        for(int x=0;x<counter;x++){
            points[x].setColor(color);
            points[x].draw();     
        }
        if(selected==true){
            this->drawSelectionBox();
        }
    }
    void move(float mx, float my){
        
        float centerX=(leftX+rightX)/2;
        float centerY=(bottomY+topY)/2;
        float moveX= mx-centerX;
        float moveY= my-centerY;
    
        for(int x=0;x<counter;x++){
            points[x].setmx(points[x].getmx()+moveX);
            points[x].setmy(points[x].getmy()+moveY);
        }
        leftX=leftX+moveX;
        rightX=rightX+moveX;
        bottomY=bottomY+moveY;
        topY=topY+moveY;       
    }

    bool isSelected(float mx, float my){       
        if (mx >= leftX && mx <= rightX && my >= bottomY && my <= topY) {
            selected=true; 
            this->drawSelectionBox();
            glutSwapBuffers();   
            return true;
        } else {
            if(my<0.34){
            selected=false;
            this->drawSelectionBox();
            glutSwapBuffers();
            return false;
            }
        }
    }

    void addPoint(Point point){
        point.setB(color.getB());
        if(counter+1<=1000){
            float x = point.getmx();
            float y = point.getmy();

            points[counter] = point;
            counter++;
            
            if(x<=leftX){
                leftX=x;
            }
            if(x>=rightX){
                rightX=x;
            }
            if(y>=topY){
                topY=y;
            }
            if(y<=bottomY){
                bottomY=y;
            }
        }
    }

    void drawSelectionBox(){
            glColor3f(0.5, 0.5, 0.5);
            glLineWidth(5.0f);
        if(selected==true){
            glBegin(GL_LINES);
                glVertex2f(leftX,topY);
                glVertex2f(rightX,topY);

                glVertex2f(rightX,topY);
                glVertex2f(rightX,bottomY);  

                glVertex2f(rightX,bottomY);
                glVertex2f(leftX,bottomY);

                glVertex2f(leftX,bottomY);
                glVertex2f(leftX,topY);         
            glEnd();
            glutSwapBuffers();
        }
    }
};
#endif
