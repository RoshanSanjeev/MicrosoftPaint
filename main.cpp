#include <GL/freeglut_std.h>
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Point.h"
#include "Button.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Scribble.h"
//Roshan Sanjeev
// Window width and height
int width = 400;
int height = 400;
//color of line
Color color;
//mouse coordinates
float mx;
float my;

//font
float size=10.5f;
int counter=0;
int drag=0;

enum Tool {
    Unspecified,//0
    SquareTool, // 1
    RectangleTool,//2
    TriangleTool, //3
    RhombusTool, //4
    ScribbleTool, //5
    EraserTool,
    ClearTool,
    SelectTool
};
Tool selectedTool = Tool :: Unspecified;
int selectedShape=-1;
const int SHAPES_SIZE=5000;
Shape* shapes[SHAPES_SIZE];
Button Margin(0.2f,0.2f,0.2f,-1,1,1,1,1,0.34f,-1,0.34f);
//top row functions
Button Select(0.5f,0.5f,0.5f,0.02,1.0f,0.48,1.0f,0.48,0.8,0.02,0.8);
Button Front(0.5f,0.5f,0.5f,0.5,1.0f,0.73,1.0f,0.73,0.8,0.5,0.8);
Button Back(0.5f,0.5f,0.5f,0.75,1.0f,0.98,1.0f,0.98,0.8,0.75,0.8);
//color display box
Button whiteBox(0.5f,0.5f,0.5f,-0.98f,1,-0.78f,1,-0.78,0.8f,-0.98f,0.8f);
Button whiteBox2(0.5f,0.5f,0.5f,-0.78f,1,-0.58,1,-0.58,0.8,-0.78,0.8);
//Middle row function keys
Button Clear(0.5f,0.5f,0.5f,-0.98,0.78f,-0.5,0.78f,-0.5,0.58,-0.98,0.58);
Button Brush(0.5f,0.5f,0.5f,-0.48,0.78f,0,0.78f,0,0.58,-0.48,0.58);
Button Eraser(0.5f,0.5f,0.5f,0.02,0.78f,0.48,0.78f,0.48,0.58,0.02,0.58);
//bottom row function keys
Button RhombusButton(0.5f,0.5f,0.5f,-0.98,0.56f,-0.5,0.56f,-0.5,0.36,-0.98,0.36);
Button SquareButton(0.5f,0.5f,0.5f,-0.48,0.56f,0,0.56f,0,0.36,-0.48,0.36);
Button RectangleButton(0.5f,0.5f,0.5f,0.02,0.56f,0.48,0.56f,0.48,0.36,0.02,0.36);
Button TriangleButton(0.5f,0.5f,0.5f,0.5,0.56f,0.98,0.56f,0.98,0.36,0.5,0.36);

//Colorfunctions
Button RedBar(0.5f,0.5f,0.5f,-0.56,0.98f,0,0.98f,0,0.95,-0.56,0.95);
Button GreenBar(0.5f,0.5f,0.5f,-0.56,0.91f,0,0.91f,0,0.88,-0.56,0.88);
Button BlueBar(0.5f,0.5f,0.5f,-0.56,0.84f,0,0.84f,0,0.81,-0.56,0.81);

Button RedSlider(1.0f,0.0f,0.0f,-0.56,1.0f,-0.5f,1.0f,-0.5f,0.93f,-0.56,0.93);
Button GreenSlider(0.0f,1.0f,0.0f,-0.56,0.93f,-0.5f,0.93f,-0.5f,0.86f,-0.56,0.86);
Button BlueSlider(0.0f,0.0f,1.0f,-0.56,0.86f,-0.5f,0.86f,-0.5f,0.79f,-0.56,0.79);


Button colorDisplay(0.0f,0.0f,0.0f,-0.96f,0.98,-0.6f,0.98,-0.6,0.82,-0.96,0.82);

void windowToScene(float& x, float& y) {
    x = (2.0f * (x / float(width))) - 1.0f;
    y = 1.0f - (2.0f * (y / float(height)));
}

void createButtons(){

    //Create Buttons
    Margin.draw();
    //tools
    Clear.draw();
    Brush.draw();
    //Select brush on the start
    Eraser.draw();
    SquareButton.draw();
    RectangleButton.draw();
    TriangleButton.draw();
    RhombusButton.draw();
    Select.draw();
    Front.draw();
    Back.draw();

    //Color Selector
    whiteBox.draw();
    whiteBox2.draw();
    colorDisplay.draw();
    RedBar.draw();
    GreenBar.draw();
    BlueBar.draw();
    RedSlider.draw();
    GreenSlider.draw();
    BlueSlider.draw();
}

void styleButtons(){
    //animate Front with letter F
    glColor3f(1,1,1);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(0.6,0.98);
        glVertex2f(0.6,0.82);
        glVertex2f(0.6,0.98);
        glVertex2f(0.71,0.98);
        glVertex2f(0.6,0.88);
        glVertex2f(0.71,0.88);
        
    glEnd();
    //animate Back button with letter b
    //Button Back(0.5f,0.5f,0.5f,0.75,1.0f,0.98,1.0f,0.98,0.8,0.75,0.8);
    glBegin(GL_LINES);
        glVertex2f(-0.3+0.9+0.19,0.75+0.2);
        glVertex2f(-0.15+0.9+0.19,0.73+0.2);
        glVertex2f(-0.15+0.9+0.19,0.73+0.2);
        glVertex2f(-0.3+0.9+0.19,0.7+0.2);
        glVertex2f(-0.3+0.9+0.19,0.75+0.2);
        glVertex2f(-0.3+0.9+0.19,0.63+0.2);
        glVertex2f(-0.3+0.9+0.19,0.69+0.2);
        glVertex2f(-0.15+0.9+0.19,0.67+0.2);
        glVertex2f(-0.15+0.9+0.19,0.67+0.2);
        glVertex2f(-0.3+0.9+0.19,0.64+0.2);
    glEnd();
     //animate brush with letter b
    glColor3f(1,1,1);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.3,0.75);
        glVertex2f(-0.15,0.73);
        glVertex2f(-0.15,0.73);
        glVertex2f(-0.3,0.7);
        glVertex2f(-0.3,0.75);
        glVertex2f(-0.3,0.63);
        glVertex2f(-0.3,0.69);
        glVertex2f(-0.15,0.67);
        glVertex2f(-0.15,0.67);
        glVertex2f(-0.3,0.64);
    glEnd();
     //Style the buttons
    //animate Clear with a letter C
    glColor3f(1,1,1);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.8,0.75);
        glVertex2f(-0.65,0.75);
        glVertex2f(-0.8,0.75);
        glVertex2f(-0.8,0.65);
        glVertex2f(-0.8,0.65);
        glVertex2f(-0.65,0.65);
    glEnd();
    //Style Eraser with letter E
    glBegin(GL_LINES);
        glVertex2f(0.15,0.75);
        glVertex2f(0.3,0.75);
        
        glVertex2f(0.15,0.69);
        glVertex2f(0.3,0.69);

        glVertex2f(0.15,0.75);
        glVertex2f(0.15,0.64);

        glVertex2f(0.15,0.64);
        glVertex2f(0.3,0.64);
    glEnd();
    //Style Select with letter S
    glBegin(GL_LINES);
        glVertex2f(0.2,0.97);
        glVertex2f(0.35,0.97);
        
        glVertex2f(0.2,0.91);
        glVertex2f(0.35,0.91);

        glVertex2f(0.2,0.85);
        glVertex2f(0.35,0.85);

        glVertex2f(0.2,0.97);
        glVertex2f(0.2,0.91);

        glVertex2f(0.35,0.91);
        glVertex2f(0.35,0.85);
    glEnd();
    //Style Rhombus button with a rhombus
    float zx=-0.74;
    float zy=0.46;
    glBegin(GL_POLYGON);
        glVertex2f(zx,zy+0.07);
        glVertex2f(zx+0.07,zy);
        glVertex2f(zx,zy-0.07);   
        glVertex2f(zx-0.07,zy);         
    glEnd();
    //Style Square button with a square
    zx=-0.23;
    zy=0.46;
    glBegin(GL_POLYGON);
        glVertex2f(zx-0.07,zy+0.07);
        glVertex2f(zx+0.07,zy+0.07);
        glVertex2f(zx+0.07,zy-0.07);   
        glVertex2f(zx-0.07,zy-0.07);         
    glEnd();
    //style Rectangle button with rectangle
    zx=0.26;
    zy=0.46;
    glBegin(GL_POLYGON);
        glVertex2f(zx-0.14,zy+0.07);
        glVertex2f(zx+0.14,zy+0.07);
        glVertex2f(zx+0.14,zy-0.07);   
        glVertex2f(zx-0.14,zy-0.07);         
    glEnd();
    //style Triangle button with rectangle
    zx=0.75;
    zy=0.46;
    glBegin(GL_POLYGON);
        glVertex2f(zx,zy+0.07);
        glVertex2f(zx+0.07,zy-0.07);
        glVertex2f(zx-0.07,zy-0.07);           
    glEnd();
}

void drawScene(){
    // Clear the screen and set it to current color (white)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    // Objects to be drawn go here
    glEnable(GL_POINT_SMOOTH);
    createButtons();
    styleButtons();
    //live time drawing
    if(selectedTool==ScribbleTool){
        Brush.Clicked(0);//start the program with the brush clicked
    }
    if(selectedTool==EraserTool){
        Eraser.Clicked(0);
    }
    if((selectedTool==SelectTool)){
        Select.Clicked(0);
    }
    if((selectedTool==ClearTool)){
        Clear.Clicked(0);
    }
    //shape button clicks
    if((selectedTool==RhombusTool)){
        RhombusButton.Clicked(0);
    }
    if((selectedTool==SquareTool)){
        SquareButton.Clicked(0);
    }
    if((selectedTool==RectangleTool)){
        RectangleButton.Clicked(0);
    }
    if((selectedTool==TriangleTool)){
        TriangleButton.Clicked(0);
    }
    for(int i=0;i<counter;i++){
        shapes[i]->draw();
    }
    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();

}
void setButtonActiveOnClick(float mx, float my){
    bool isWithinBarLength = mx>-0.53&&mx<-0.02;//you can only slide a certain amount to the right or to the left
    if(isWithinBarLength){
        if(RedSlider.isClicked(mx,my)){
            RedSlider.move(mx);
            color.setR((RedSlider.getx1()+0.53)/0.47);
        }
        if(GreenSlider.isClicked(mx,my)){
            GreenSlider.move(mx);
            color.setG((GreenSlider.getx1()+0.53)/0.47);
        }
        if(BlueSlider.isClicked(mx,my)){
            BlueSlider.move(mx);
            color.setB((BlueSlider.getx1()+0.53)/0.47);
        }
        colorDisplay.setR(color.getR());
        colorDisplay.setG(color.getG());
        colorDisplay.setB(color.getB());
        if(selectedShape!=-1){//livetime color changing as you drag selector
            shapes[selectedShape]->setColor(color.getR(),color.getG(), color.getB());
        }
    }
     //current
    if(Select.isClicked(mx,my)){
        selectedTool= Tool :: SelectTool;
        return;
    }
     //Clear
    if(Clear.isClicked(mx,my)){
        for(int x=0;x<counter;x++){
            delete shapes[x];
        }
        selectedShape=-1;
        //reset everything
        selectedTool= Tool :: ClearTool;
        counter=0;
        return;
    }
    //brush
    if(Brush.isClicked(mx,my)){
        selectedTool = Tool :: ScribbleTool;
        //deselect previous selected shape if needed
        for(int i=0;i<counter;i++){
            shapes[i]->setSelected(false);
            shapes[i]->draw();
            glutSwapBuffers();
        }     
        for(int i=0;i<counter;i++){
            shapes[i]->setSelected(false);
            shapes[i]->draw();
            glutSwapBuffers();
        }
        colorDisplay.setColor(0.0f,0.0f,0.0f);
        return;
    }
    if(Eraser.isClicked(mx,my)){
        selectedTool = Tool :: EraserTool;
    }
    if(RhombusButton.isClicked(mx,my)){
        selectedTool = Tool :: RhombusTool;
    }
    if(SquareButton.isClicked(mx,my)){
        selectedTool = Tool :: SquareTool;
    }
    if(RectangleButton.isClicked(mx,my)){
        selectedTool = Tool :: RectangleTool;
    }
    if(TriangleButton.isClicked(mx,my)){
        selectedTool = Tool :: TriangleTool;
    }
    glutSwapBuffers();
}

void addShapeToShapes(float mx, float my){
    if(selectedTool==SquareTool){
        shapes[counter]= new Square(mx,my,color.getR(), color.getG(), color.getB());
        counter++;
    }

    if(selectedTool==RectangleTool){
        shapes[counter]= new Rectangle(mx,my,color.getR(), color.getG(), color.getB());
        counter++;
    }

    if(selectedTool==TriangleTool){
        shapes[counter]= new Triangle(mx,my,color.getR(), color.getG(), color.getB());
        counter++;
    }

    if(selectedTool==RhombusTool){
        shapes[counter]= new Rhombus(mx,my,color.getR(), color.getG(), color.getB());
        counter++;
    }       
    if(selectedTool==ScribbleTool){
        shapes[counter] = new Scribble(mx,my,color);     
        counter++;
    }

}
void mouse(int button, int state, int x, int y) {
    /*                         
        button: 0 -> left mouse button
                1 -> right mouse button
        
        state:  0 -> mouse click
                2 -> mouse release
        
        x, y:   mouse location in window relative coordinates
    */
    float mx=x;
    float my=y;
    windowToScene(mx,my);
    
    bool isLeftMouseClick = button==0 && state==0;
    bool isBelowTopBounds = my < 0.34;
    bool isAboveBottomBounds = my>-1.0;
    bool haveSpaceInShapesArray =  counter<SHAPES_SIZE;

//use color input to change the color of the color display(shows what color you have selected)
    colorDisplay.setColor(color); 
//button functions:
    if(isLeftMouseClick){
        setButtonActiveOnClick(mx, my);
    }
    if(selectedTool==SelectTool){//find selected shape
        if(isLeftMouseClick && isBelowTopBounds && isAboveBottomBounds && haveSpaceInShapesArray ){
            for(int x=counter-1;x>-1;x--){
                if(shapes[x]->isSelected(mx,my)==true){
                    
                    //deselect previous selected shape when selecting different shapes(only one selection at a time)
                    if(selectedShape!=-1){                       
                        for(int i=0;i<counter;i++){
                            shapes[i]->setSelected(false);
                            shapes[i]->draw();
                            glutSwapBuffers();
                        }
                        shapes[selectedShape]->setBorderColor(shapes[selectedShape]->getR(),shapes[selectedShape]->getG(),shapes[selectedShape]->getB());
                    }

                    selectedShape=x;//hold the place of the selected shape in the master array
                    //draw a grey box around shape to show selection
                    shapes[selectedShape]->setBorderColor(0.5f,0.5f,0.5f);
                    
                    //change master values to selected shape
                    color.setColor(shapes[selectedShape]->getR(),shapes[selectedShape]->getG(),shapes[selectedShape]->getB());
                    colorDisplay.setColor(shapes[selectedShape]->getR(),shapes[selectedShape]->getG(),shapes[selectedShape]->getB());
                    float rPos=0.47*(shapes[selectedShape]->getR())-0.53;
                    float gPos=0.47*(shapes[selectedShape]->getG())-0.53;
                    float bPos=0.47*(shapes[selectedShape]->getB())-0.53;
                    RedSlider.move(rPos);
                    GreenSlider.move(gPos);
                    BlueSlider.move(bPos);
                    break;
                }
            }
        }
    }
    //change the color, or front or back of a selected shape
    if(selectedTool==SelectTool&&selectedShape!=-1){
            shapes[selectedShape]->setColor(color.getR(),color.getG(),color.getB());//change the color
            shapes[selectedShape]->draw();//show immediately
            if(counter+1<SHAPES_SIZE){
                if(Front.isClicked(mx,my)){//move shape to the front
                    shapes[counter]=shapes[selectedShape];
                    shapes[selectedShape]= new Scribble(100,100,0,0,0);
                    counter++;
                    selectedShape=counter-1;
                }
                if(Back.isClicked(mx,my)){//move shape to the back
                    Shape* hold=shapes[selectedShape];
                    shapes[selectedShape]=new Scribble(100,100,0,0,0);
                    for(int i=counter;i>0;i--){
                    shapes[i]=shapes[i-1];
                    }
                    shapes[0]=hold;
                    selectedShape=0;
                    counter++;
                }
            }
    }
    if(selectedTool!=SelectTool&&selectedShape!=-1){
        //remove selection box
        //and deselect shape when using another tool
        shapes[selectedShape]->setBorderColor(shapes[selectedShape]->getR(),shapes[selectedShape]->getG(),shapes[selectedShape]->getB());
        shapes[selectedShape]->setSelected(false);
        shapes[selectedShape]->draw();
        selectedShape=-1;
    }
    if(selectedTool==EraserTool){
        if(isLeftMouseClick && isBelowTopBounds && isAboveBottomBounds && haveSpaceInShapesArray ){
            for(int x=counter-1;x>-1;x--){
                if(shapes[x]->isSelected(mx,my)==true){
                    shapes[x]= new Scribble(100,100,0,0,0);
                    break;
                }
            }
        }
    }

    //add points and shapes to arrays that will get drawn in draw function
    if(isLeftMouseClick && isBelowTopBounds && isAboveBottomBounds && haveSpaceInShapesArray ){
        addShapeToShapes(mx, my);
    }

    // We have been drawing to the back buffer, put it in the front
    glutPostRedisplay();
}   

void motion(int x, int y) {
    
    //x, y:   mouse location in window relative coordinates
    float mx=x;
    float my=y;
    windowToScene(mx,my);

    bool isBelowTopBounds = my < 0.34;
    bool isAboveBottomBounds = my>-1.0;
    bool isWithinColorSliderBounds = mx>-0.53 && mx < -0.02 && my>0.78;

    //use color sliders
    if(isWithinColorSliderBounds){//ensures that you don't accidentally click other buttons while using the color sliders
        setButtonActiveOnClick(mx,my);//only want to call this function in motion when you are within the color slider bounds
        //the code below makes sure that when sliders are clicked the selection box stays
        if(selectedShape!=-1){
            shapes[selectedShape]->setSelected(true);
            shapes[selectedShape]->draw();
        }
    }
    //draw a scribble
    if(selectedTool==ScribbleTool){
        if(counter<SHAPES_SIZE && isBelowTopBounds && isAboveBottomBounds){    
           ((Scribble*)shapes[counter-1])->addPoint(Point(mx, my, color));
           shapes[counter-1]->draw();
        }
    }
    //select any shape and move it while dragging   
    if(selectedTool==SelectTool && counter>0 && selectedShape!=-1 &&isBelowTopBounds){
        if(shapes[selectedShape]->isSelected(mx,my)==true){
            shapes[selectedShape]->move(mx,my);
        }
    }  
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    /*
        key:    ASCII character of the keyboard key that was pressed
        x, y:   mouse location in window relative coordinates
    */
}

int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT App");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Set the Mouse Function
    glutMouseFunc(mouse);

    // Set the Motion Function
    glutMotionFunc(motion);

    // Set the Keyboard Funcion
    glutKeyboardFunc(keyboard);

    // Run the program
    glutMainLoop();

    return 0;
}
