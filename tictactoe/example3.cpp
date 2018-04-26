/*
example3.cpp

Using drawing functions and mouse input
*/
#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

// Usefull colors
unsigned char
  grid_color[3]={0,0,255},
  play1_color[3]={204,0,0},
  play2_color[3]={0,102,0};
  
// Declare an image to draw the grid
  CImg<unsigned char> grid(300,300,1,3,255);
  for (int i=1;i<3;i++) grid.draw_line(0,100*i,300,100*i,grid_color);
  for (int j=1;j<3;j++) grid.draw_line(100*j,0,100*j,300,grid_color);
  
// Declare a display to draw the scene
  CImgDisplay disp(grid,"Tic-tac-toe",0,false,false);

// Center the window on the screen
   disp.move((CImgDisplay::screen_width() - disp.width())/2,
            (CImgDisplay::screen_height() - disp.height())/2);

// Declare an image to display the scene
CImg<unsigned char> scene=grid;
// Usefull variables
int player=1;
int table[3][3]={0,0,0,0,0,0,0,0,0};

// Main loop, exit if the display window is closed or if ESC or Q key is hit
  while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {
    
    // Display the scene
    scene.display(disp);
    
    // Detect mouse click
    if (disp.button()&1) { // Left button clicked.
      int i=3*disp.mouse_y()/disp.height();
      int j=3*disp.mouse_x()/disp.width();
      
      if (table[i][j]==0) {
        // Player 1, draw circle
        if (player==1) {
          scene.draw_circle(50+j*100,50+i*100,40,play1_color,1,~0U);
          table[i][j]=1;
        }
        // Player 2, draw cross
        else {
          scene.draw_line(10+j*100,10+i*100,90+j*100,90+i*100,play2_color);
          scene.draw_line(10+j*100,90+i*100,90+j*100,10+i*100,play2_color);
          table[i][j]=2;
        }
      player=3-player;
      }
      // If the scene is full, reset the game
      else {
        bool find_void=false;
        int *t=&table[0][0];
        for (int k=0; !find_void && k<9;k++) if (t[k]==0) find_void=true;
        if (!find_void) {
          for(int k=0;k<9;k++) t[k]=0;
          scene=grid;
        }
      }
    }
    disp.wait();
    
    // Handle window resize
    if (disp.is_resized()) disp.resize();
    }
    
  return 0;
}
