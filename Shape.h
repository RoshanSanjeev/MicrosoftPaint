#ifndef SHAPE_H
#define SHAPE_H
#include "Color.h"
#include <GL/freeglut.h>
struct Shape {
protected:
    Color color;//color 
    Color selectedColor;//selection box color
    bool selected;
    float coordinates[4];//stores the coordinates for selection box
public: 
    Shape(){
        
    }
    Shape(float r, float g, float b){
        color.setColor(r,g,b);
        selectedColor.setColor(color.getR(),color.getG(),color.getB());
    }
    virtual void draw()=0;
    virtual bool isSelected(float ,float)=0;
    virtual void move(float, float)=0;
    
    void setColor(float r, float g, float b){
        color.setColor(r,g,b);
    }  
    void setBorderColor(float r, float g, float b){
        selectedColor.setColor(r,g,b);
        glutPostRedisplay();
    }  
    void setBorderColor(Color c){
        selectedColor.setR(c.getR());
        selectedColor.setR(c.getG());
        selectedColor.setR(c.getB());
    }
    void setSelected(bool x){
        selected=x;
    }
    bool getSelected(){
        return selected;
    }
    float getR() {
        return color.getR();
    }

    float getG() {
        return color.getG();
    }

    float getB() {
        return color.getB();
    }
    void setR(float r) {
        color.setR(r);
    }

    void setG(float g) {
        color.setG(g);
    }

    void setB(float b) {
        color.setB(b);
    }
};
#endif
