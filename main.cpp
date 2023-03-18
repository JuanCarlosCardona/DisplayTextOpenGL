#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

const GLint WIDTH = 650;
const GLint HEIGHT = 650;

// Struct para representar colores
struct Color {
    Color(float d, float d1, float d2) {
        red = d;
        green = d1;
        blue = d2;
    }

    float red;
    float green;
    float blue;
};

std::string sampleText = "Hola! Soy un Ejemplo"; // Texto de ejemplo
GLint rasterX = WIDTH / 2; // Posiciones iniciales del texto
GLint rasterY = HEIGHT / 2;
Color textColor(1.0f, 1.0f, 1.0f);


void display(){

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(textColor.red, textColor.green, textColor.blue);
    glRasterPos2i(rasterX, rasterY); // Posicion del texto a mostrar

    const char* displayedText = sampleText.c_str();
    std::cout << displayedText << std::endl;

    //Lee cada caracter del string sampleText y lo gráfica en pantalla
    for(const char* c = displayedText; *c != '\0'; ++c){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){

    //Cierra el programa
    if(key == 'Q')
        exit(0);

    /*
     * D + SHIFT = Elimina un caracter del texto en pantalla
     * R + SHIFT = Cambia el texto a color rojo
     * G + SHIFT = Cambia el texto a color verde
     * B + SHIFT = Cambia el texto a color azul
     */
    if(key == 'D' && (glutGetModifiers() & GLUT_ACTIVE_SHIFT)){
        sampleText.pop_back();
        glutPostRedisplay();
        return;
    }

    if(key == 'R' && (glutGetModifiers() & GLUT_ACTIVE_SHIFT)){
        textColor = Color(1.0f, 0.0f, 0.0f);
        glutPostRedisplay();
        return;
    }

    if(key == 'G' && (glutGetModifiers() & GLUT_ACTIVE_SHIFT)){
        textColor = Color(0.0f, 1.0f, 0.0f);
        glutPostRedisplay();
        return;
    }


    if(key == 'B' && (glutGetModifiers() & GLUT_ACTIVE_SHIFT)){
        textColor = Color(0.0f, 0.0f, 1.0f);
        glutPostRedisplay();
        return;
    }

    // Añade la tecla presionada al texto mostrado en pantalla
    sampleText.push_back(key);
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y){

    // Se utilizan las flechas para mover la posición en pantalla del texto
    switch (key) {
        case GLUT_KEY_LEFT:
            rasterX -= 10;
            break;
        case GLUT_KEY_RIGHT:
            rasterX += 10;
            break;
        case GLUT_KEY_UP:
            rasterY += 10;
            break;
        case GLUT_KEY_DOWN:
            rasterY -= 10;
            break;
        default:
            return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Display Text");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();


    return 0;
}