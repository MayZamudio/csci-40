#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;

//This will dump the contents of an image file to the screen
//Useful for debugging your code
void print_image (unsigned char in[], int width, int height) {
    for (int i = 0; i < width * height * 3; i++)
        cout << (unsigned int) in[i] << endl;
}

//These are helper functions that will return the red, green, or blue value at
// any given location, or allow you to set the value there as well.
//We're accessing a 1D array as if it was a 3D array
#define R(i,j) (j*width+i)
#define G(i,j) (stride+j*width+i)
#define B(i,j) (stride+stride+j*width+i)

//This function will reduce the brightness of all colors in the image by half, and write the results to out
void darken (unsigned char in[], unsigned char out[], int width, int height) {
    const int stride = width * height;
    //Note: i is the x coordinate, j is the y coordinate
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) { //At each pixel...
            short temp_r = in[R(i,j)] * 2;
            if (temp_r > 255) temp_r = 255;
            out[R (i, j)] = temp_r; //Divide the value of red by half...
            short temp_g = in[G(i,j)] * 2;
            if (temp_g > 255) temp_g = 255;
            out[G (i, j)] = temp_g; //Divide the value of red by half...
            short temp_b = in[B(i,j)] * 2;
            if (temp_b > 255) temp_b = 255;
            out[B (i, j)] = temp_b; //Divide the value of red by half...
        }
    }
    return;
}

//This code will sepia tone the image
//In is the input array, out is the output array
//Notice how there is absolutely no difference between using a pointer and an array
void sepia (unsigned char *in, unsigned char *out, int width, int height) {
    const int stride = width * height;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned short r = in[R (i, j)] * 0.393 + in[G (i, j)] * 0.769 + in[B (i, j)] * 0.189;
            unsigned short g = in[R (i, j)] * 0.349 + in[G (i, j)] * 0.686 + in[B (i, j)] * 0.168;
            unsigned short b = in[R (i, j)] * 0.272 + in[G (i, j)] * 0.534 + in[B (i, j)] * 0.131;
            if (r > 255) r = 255; //Saturate the values
            if (g > 255) g = 255;
            if (b > 255) b = 255;
            out[R (i, j)] = r; //Write them into the output array
            out[G (i, j)] = g;
            out[B (i, j)] = b;
        }
    }
    return;
}

void usage() {
    cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
    cout << "For example, a.out kyoto.jpg\n";
    exit (1);
}

int main (int argc, char **argv) {
    if (argc != 2) usage(); //Check command line parameters

    //PHASE 1 - Load the image
    clock_t start_time = clock();
    CImg<unsigned char> image (argv[1]);
    CImg<unsigned char> darkimage (image.width(), image.height(), 1, 3, 0);
    CImg<unsigned char> sepia_image (image.width(), image.height(), 1, 3, 0);
    clock_t end_time = clock();
    cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

    //Uncomment this next line to get debugging on the image data loaded
    //print_image(image,image.width(),image.height());

    //PHASE 2 - Darken the image
    start_time = clock();
    darken (image, darkimage, image.width(), image.height());
    end_time = clock();
    cerr << "Darken time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

    //PHASE 3 - Sepia tone the image
    start_time = clock();
    //sepia (darkimage, sepia_image, image.width(), image.height());
    end_time = clock();
    cerr << "Sepia time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

    //PHASE 3 - Write the image
    start_time = clock();
    //Uncomment this if you want to see the darkened image, and in .PNG format
    darkimage.save_png("output.png");
    //sepia_image.save_jpeg ("output.jpg", 50); //50% quality 
    end_time = clock();
    cerr << "Image write time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}