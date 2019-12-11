#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;

//This will dump the contents of an image file to the screen
//Useful for debugging your code
void print_image(unsigned char in[], int width, int height) {
    for (int i = 0; i < width * height * 3; i++)
        cout << (unsigned int) in[i] << endl;
}

//Globals for our current image
int width = 0;
int height = 0;
int stride = 0; //width*height

//These are helper functions that will return the red, green, or blue value at
// any given location, or allow you to set the value there as well.
//We're accessing a 1D array as if it was a 3D array

int R(int i, int j) {
    return j * width + i;
}
int G(int i, int j) {
    return stride + j * width + i;
}
int B(int i, int j) {
    return stride + stride + j * width + i;
}

void set_rekt(unsigned char out[], int x_min, int y_min, int x_max, int y_max) {
    for (int i = x_min; i <= x_max; i++) {
        for (int j = y_min; j <= y_max; j++) {
            out[R(i,j)] = 0;
            out[G(i,j)] = 0;
            out[B(i,j)] = 0;
        }
    }
}
/* Gradient code
   unsigned int new_r = (unsigned int)in[R(i,j)];
   float percentage = float(i)/width;
   new_r += percentage * 255;
   if (new_r > 255) new_r = 255;
   out[R(i,j)] = new_r;
   out[G(i,j)] = in[G(i,j)];
   out[B(i,j)] = in[B(i,j)];
  */
void thresh_mono(unsigned char in[], unsigned char out[], unsigned char threshold) {
    //Note: i is the x coordinate, j is the y coordinate
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) { //At each pixel...
            if (in[R(i,j)] > threshold) {
                out[R(i, j)] = in[R(i, j)];
                out[G(i, j)] = in[G(i, j)];
                out[B(i, j)] = in[B(i, j)];
            }
            else {
                unsigned int brightness = (unsigned int)in[R(i,j)];
                brightness += in[G(i,j)];
                brightness += in[B(i,j)];
                brightness /= 3;
                out[R(i,j)] = brightness;
                out[G(i,j)] = brightness;
                out[B(i,j)] = brightness;
            }
        }
    }
    set_rekt(out,20,30,40,50);

    return;
}

void usage() {
    cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
    cout << "For example, a.out kyoto.jpg\n";
    exit(1);
}
int main(int argc, char **argv) {
    if (argc != 2) usage(); //Check command line parameters

    //PHASE 1 - Load the image
    clock_t start_time = clock();
    CImg<unsigned char> image(argv[1]);
    string filename = argv[1];
    width = image.width(); //Set the globals
    height = image.height();
    stride = width * height;
    CImg<unsigned char> darkimage(image.width(), image.height(), 1, 3, 0);
    CImg<unsigned char> sepia_image(image.width(), image.height(), 1, 3, 0);
    //If you want to make an animated gif, use this:
    CImgList<unsigned char> harambe(0,image.width(), image.height(), 1, 3);
    clock_t end_time = clock();
    cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

    //PHASE 2 - Darken the image
    start_time = clock();
    //This is how you make an animated gif
    for (int i = 0; i < 512; i = i + 10) {
        int thresh = i;
        if (thresh >= 256) thresh = 512 - thresh;
        thresh_mono(image, darkimage, thresh);
        harambe.push_back(darkimage);
    }
    end_time = clock();
    cerr << "Thresh_mono time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

    //PHASE 3 - Write the image
    start_time = clock();
        filename = filename + ".gif";
        harambe.save_gif_external(filename.c_str(), 25, 0); //Animated gif a
    end_time = clock();
    cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}