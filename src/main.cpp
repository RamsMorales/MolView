#include <iostream>
#include <GL/freeglut.h>

// Default window dimensions
int WIDTH = 1200, HEIGHT = 900;

// Display callback function
void display() {
    //glClearColor(0,0,1,0); //sets background color to blue
    glClear(GL_COLOR_BUFFER_BIT); // Clears the screen
    glFlush();                    // Renders the clear
}

// Keyboard callback function
void handleKeyboard(unsigned char key, int x, int y){

    std::cout << "You pressed the " << key << " key!" << std::endl;
    
    if (key == 27) {
        glutLeaveMainLoop(); //close the window
        
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("MolView++ Window Setup");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);

    glutMainLoop();

    return 0;
}