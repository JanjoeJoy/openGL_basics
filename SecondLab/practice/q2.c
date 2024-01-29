#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat x,y;
};

struct Point p[10];
int count = 0;

void readInput()
{
    FILE *fptr = fopen("input2.txt", "r");
    if(fptr)
    {
        while(fscanf(fptr, "%f %f", &(p[count].x), &(p[count].y))!=EOF)
        {
            count++;
        }
        fclose(fptr);
    }
}

void renderFunction()
{
    int i=0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    while(i < count - 1)
    {
        glBegin(GL_LINES);
        glColor3f(0.5,0.5,1.0);
        glVertex2f(p[i].x, p[i].y);
        glVertex2f(p[i + 1].x, p[i + 1].y);
        i++;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    readInput();
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}