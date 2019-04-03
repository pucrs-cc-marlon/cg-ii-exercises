// **********************************************************************
// PUCRS/FACIN
// Programa de testes para manipulação de Imagens
//
// Marcio Sarroglia Pinho
//
// pinho@pucrs.br
// **********************************************************************

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifdef _MSC_VER


#endif

#ifdef WIN32
#include <windows.h>
#include "gl\glut.h"
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#include "SOIL/SOIL.h"

#include "ImageClass.h"

ImageClass Image, NewImage;

const int LIMIAR = 100;
#define LARGURA_JAN 1000
#define ALTURA_JAN 500

// **********************************************************************
//
// **********************************************************************
#include <fstream>
float ImageMat[512][512];

// **********************************************************************
//  void ConvertBlackAndWhite()
// **********************************************************************
int LoadTXT(const char *Nome)
{
    cout << "Iniciou LoadTXT....";
    ifstream ArqImg;

    Image.SetSize(512,512, 3); // define o tamanho da imagem conforme a especificaçao

    ArqImg.open(Nome, ios::in);
    if(!ArqImg)
    {
        cout << "Erro na abertura do arquivo TXT!" << endl;
        return 0;
    }
    for(int x=0; x<Image.SizeX(); x++)
        for(int y=0; y<Image.SizeY(); y++)
        {
            ArqImg >> ImageMat[x][y];
        }
    ArqImg.close();

    for(int x=0; x<Image.SizeX(); x++)
    {
        for(int y=0; y<Image.SizeY(); y++)
        {
            unsigned char r,g,b;
            float fator = 255.0/3500.0;  // este cálculo deve ser refeito para que os áâmetros BROLHJo E CONTRASTE seja
            r = g = b = ImageMat [y][x] * fator;
            Image.DrawPixel(x, y, r,g,b);
        }
    }
    cout << "Terminou LoadTXT....";

    return 1;
}
// **********************************************************************
//  void ConvertBlackAndWhite()
// **********************************************************************
void ConvertBlackAndWhite()
{
    unsigned char r,g,b;
    int x,y;
    int i;
    cout << "Iniciou Black & White....";

    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // VERIFICA O TOM DE CINZA DA IMAGEM
            // Image.ReadPixel(x,y,r,g,b);

            if (i < LIMIAR)
            {
                NewImage.DrawPixel(x, y,0,0,0);  // exibe um ponto PRETO na imagem
            }
            else NewImage.DrawPixel(x, y, 255,255,255); // exibe um ponto VERMELHO na imagem
        }
    }
    cout << "Concluiu Black & White.\n";
}


// **********************************************************************
// void DetectImageBorders()
// **********************************************************************
void DetectImageBorders()
{
    cout << "Iniciou DetectImageBorders....";
#define SENSIBILIDADE 10


    cout << "Iniciou DetectImageBorders...." << endl;
}

// **********************************************************************
// void ConvertToGrayscale()
// **********************************************************************
void ConvertToGrayscale()
{
    cout << "Iniciou ConvertToGrayscale..." << endl;
    int x,y;
    int i;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // Le o TOM DE CINZA DA IMAGEM
            NewImage.DrawPixel(x, y,i,i,i);  // exibe um ponto CINZA na imagem da direita
        }
    }
    cout << "Concluiu ConvertToGrayscale." << endl;
}

// **********************************************************************
// void ConvertToGrayscale()
// **********************************************************************
void Convulucao()
{
    cout << "Iniciou ConvertToGrayscale..." << endl;
    int x,y;
    int i;
    for(x=0; x<Image.SizeX()-1; x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            i = Image.GetPointIntensity(x,y); // Le o TOM DE CINZA DA IMAGEM
            NewImage.DrawPixel(x, y,i,i,i);  // exibe um ponto CINZA na imagem da direita
        }
    }
    cout << "Concluiu ConvertToGrayscale." << endl;
}


// **********************************************************************
// void InvertImage()
// **********************************************************************
void InvertImage()
{
    cout << "Iniciou InvertImage..." << endl;

    int x,y;
    int r;
    int g;
    int b;
    for(x=0; x<Image.SizeX(); x++)
    {
        for(y=0; y<Image.SizeY(); y++)
        {
            r = 255 - Image.ReadR(x,y);
            g = 255 - Image.ReadG(x,y);
            b = 255 - Image.ReadB(x,y);
            NewImage.DrawPixel(x, y, r,g,b);  // exibe um ponto CINZA na imagem da direita
        }
    }

    cout << "Concluiu InvertImage." << endl;
}


void OrdenaVetor(int window[])
{
    int temp, i, j;
    for(i = 0; i < 9; i++)
    {
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--)
        {
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}
void MontaVetor(int Px, int Py, int Vetor[9])
{

}
// **********************************************************************
// void Mediana()
// **********************************************************************
void Mediana()
{
cout << "Iniciou Mediana..." << endl;

    int x,y;
    int r;
    int g;
    int b;
    int i;
    int edgex = (Image.SizeX() / 2);
    int edgey = (Image.SizeY() / 2);
    for(x=edgex; x<Image.SizeX()-edgex; x++)
    {
        for(y=edgey; y<Image.SizeY()-edgey; y++)
        {
            i = 0;
            for(fx=0; fx<Image.SizeX(); fx++)
            {
                for(fy=0; fy<Image.SizeY(); fy++)
                {
                    NewImage.DrawPixel(x, y, r,g,b);
                }
            }
              // exibe um ponto CINZA na imagem da direita
        }
    }

    cout << "Concluiu Mediana." << endl;

}

// **********************************************************************
//  void init(void)
// **********************************************************************
void init()
{
    int r;
    // Carrega a uma imagem
    string nome;

#ifdef __APPLE__
    nome = "ArquivosCodeBlocks/Imagens/";
#endif
    nome += "exame_sem_cranio.txt";
    //nome += "Falcao.jpg";
    // nome += "Colegio.png";
    //nome += "Ruido2.bmp";
    //r = Image.Load(nome.c_str()); // Carrega uma imagem
    r = LoadTXT (nome.c_str());

    if (!r) exit(1); // Erro na carga da imagem
    else cout << ("Imagem carregada!\n");

    // Ajusta o tamanho da imagem da direita, para que ela
    // passe a ter o mesmo tamnho da imagem recem carregada
    // Caso precise alterar o tamanho da nova imagem, mude os parâmetros
    // da na chamada abaixo
    NewImage.SetSize(Image.SizeX(), Image.SizeY(), Image.Channels());
    cout << "Nova Imagem Criada" << endl;

}
// **********************************************************************
//  void reshape( int w, int h )
//  trata o redimensionamento da janela OpenGL
// **********************************************************************
void reshape( int w, int h )
{

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0,w,0,h);

    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
// **********************************************************************
//  void display( void )
// **********************************************************************
void display( void )
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fundo de tela preto
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    float zoomH = (glutGet(GLUT_WINDOW_WIDTH)/2.0)/(double)Image.SizeX();
    float zoomV = (glutGet(GLUT_WINDOW_HEIGHT))/(double)Image.SizeY();
    Image.SetZoomH(zoomH);
    Image.SetZoomV(zoomV);

// posiciona a imagem no canto inferior esquerdo da janela
    Image.SetPos(0, 0);

// posiciona a imagem nova na metada da direita da janela
    NewImage.SetPos(glutGet(GLUT_WINDOW_WIDTH)/2, 0);

// Ajusta o ZOOM da imagem para que apareca na metade da janela
    NewImage.SetZoomH(zoomH);
    NewImage.SetZoomV(zoomV);

// Coloca as imagens na tela
    Image.Display();
    NewImage.Display();

// Mostra a tela OpenGL
    glutSwapBuffers();
}
// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27: // Termina o programa qdo
        cout << "FIM!" << endl;
        //NewImage.Delete();
        //Image.Delete();
        cout << "FIM!" << endl;
        exit ( 1 );   // a tecla ESC for pressionada
        break;
    case '2':
//        ConvertBlackAndWhite(220, 255);
        ConvertBlackAndWhite();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    case 'g':
        ConvertToGrayscale();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;

    case 'b':
        DetectImageBorders();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    case 'i':
        InvertImage();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    case 'm':
        Mediana();
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    case 'c':
        NewImage.CopyTo(&Image);
        glutPostRedisplay();    // obrigatório para redesenhar a tela
        break;
    default:
        break;
    }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )
{
    switch ( a_keys )
    {
    case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        break;
    case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...

        break;
    default:
        break;
    }
}

// **********************************************************************
// **********************************************************************
void Mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        cout << "(" << x << "," << y << "): " ;
        cout << Image.GetPointIntensity(x,y) << endl;
        Image.DrawPixel(x,y,255,0,0);
        glutPostRedisplay();
    }


}

// **********************************************************************
//  void main ( int argc, char** argv )
// **********************************************************************

int main ( int argc, char** argv )
{
    glutInit            ( &argc, argv );

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (10,10);

    // Define o tamanho da janela gráfica do programa
    glutInitWindowSize  ( LARGURA_JAN, ALTURA_JAN);
    glutCreateWindow    ( "Image Loader" );

    init ();

    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    glutMouseFunc(Mouse);

    //glutIdleFunc ( display );

    glutMainLoop ( );
    return 0;
}


