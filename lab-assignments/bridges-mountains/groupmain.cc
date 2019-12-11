  //Gehret, Zamudio, and Lowe
  
  #include "Bridges.h"
  #include "ColorGrid.h"
  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include <string>
  #include <cassert>
  using namespace std;
  using namespace bridges;
  
  void readData(vector<vector<int>> &elev_data, int &width, int &height, int &maxVal, string file_name) {
  
      ifstream infile(file_name.c_str());
  
      // read header
      int max = 0, w, h, val;
      infile >> w >> h;
  
      width = w;
      height = h;
  
      // allocate space for the input data
      // we will use a 1D array
    int size = w * h;
      //  int *elev_data = new int[size];
      //  assert(elev_data); //WRK
      // read the elevation data
      for (int k = 0; k < height; k++) {
          vector<int> row;
          while (true) {
            if (row.size() >= width) break;
              infile >>  val;
              if (val <= 0) val = 0;
              row.push_back(val);
          }
  
  
          // update the max val
          max = (val > max) ? val : max;
  
          // store elevation in a 2D vector
          elev_data.push_back(row);
      }
      // record the max value
      maxVal = max;
  
      //  return elev_data;
  }
    // takes in the processed elevation data and returns a color grid for
  // visualization using BRIDGES
  ColorGrid *getImage(vector<vector<int>> elev_data, int width, int height, int maxVal) {
      // create color grid
      ColorGrid *cg = new ColorGrid(height, width);
      float pixel_val;
  //  int n = 0, gray;
  
      // load the elevation data
      for (int j = 0; j < height; j++)
          for (int k = 0; k < width; k++) {
              pixel_val = (float) elev_data.at(j).at(k);
              //      if (pixel_val == -1.) {
              if (elev_data.at(j).at(k) == -1) {
  
                  //YOU: Change the color
                  cg->set(j, k, Color(12, 248, 248));
              } else {
                  // scale value to be within 0-255, for r,g,b range
                  if (pixel_val < -1) pixel_val = 0;
                gray = (int)((pixel_val * 255.00) / maxVal);
                  //  if (gray <= 0) gray = 0;
                if (gray >= 255) gray = 255;
                  //          gray = (int) (elev_data.at(j).at(k) / maxVal) * 255;
               cg->set(j, k, Color(gray, gray, gray));
                  //          cg->set(j, k, Color(255, 255, 255));
  
              }
          }
  
      return cg;
  }
  
  // determines the least effort path through the mountain starting a point on
  // the left edge of the image
void findPath(vector<vector<int>> &elev_data, int imgWidth, int imgHeight, int startRow, int maxVal) {
  
      if (startRow < 0 || startRow >= imgHeight) {
          cout << "Invalid starting row.\n"; //WRK Let them know
          return;
      }
      int col = 0, row = startRow;
      while (col < imgWidth - 1) {
          int pixelAddress = elev_data.at(row).at(col);
          if (row == 0) {
              int right = elev_data.at(row).at(col + 1);
              int downR = elev_data.at(row + 1).at(col + 1);
              int diffR = abs(pixelAddress - right);
              int diffDR = abs(pixelAddress - downR);
              if (diffR > diffDR) row++;
          } else if (row == imgHeight - 1) {
              int upR = elev_data.at(row - 1).at(col + 1);
              int right = elev_data.at(row).at(col + 1);
              int diffUR = abs(pixelAddress - upR);
              int diffR = abs(pixelAddress - right);
              if (diffR > diffUR) row--;
          } else {
              int upR = elev_data.at(row - 1).at(col + 1);
              int right = elev_data.at(row).at(col + 1);
              int downR = elev_data.at(row + 1).at(col + 1);
              int diffUR = abs(pixelAddress - upR);
              int diffR = abs(pixelAddress - right);
              int diffDR = abs(pixelAddress - downR);
              if (diffR > diffUR and diffDR > diffUR) row--;
              if (diffR > diffDR and diffUR > diffDR) row++;
          }
          col++;
          elev_data.at(row).at(col) = -1;
          //You will set the elevation at that point to be -1
      }
  }
  // This program implements the mountain paths assignment in C++. See the README.md for a
  // detailed description
  
  // function prototypes
  //ColorGrid *getImage (vector<int> img_arr, int imgWidth, int imgHeight, int maxVal);
  //void readData (vector<int> &elev_data, int *imgWidth, int *imgHeight, int *maxVal, string file_name);
  //void findPath(vector<int> img_arr, int imgWidth, int imgHeight, int startRow, int maxVal);
    int main(int argc, char **argv) {
      const int bridges_project_id = 1001;
      const string bridges_username = "dgehret";
      const string bridges_api_key  = "348714041770";
  
  
  
      // bridges object initialization
      Bridges bridges(bridges_project_id, bridges_username, bridges_api_key);
  
      // read input elevation data
      int width, height, maxVal;
      //  int *elev_data;
      vector<vector<int>> elev_data;
      // parse command line arguments
      // argument 2 is input file
      string filename = "./colorado1.dat";
      if (argc >= 2) filename = argv[1]; //This is how you read a command line parameter
      readData(elev_data, width, height, maxVal, filename);
  
      // set title
      //YOU: Change this to "Mountain Paths - Dijkstra's"
      bridges.setTitle("Mountain Paths "s + filename + " - Greedy Algorithms Example");
      //WRK - Added this section
      //Get starting row and column - the greedy algorithm only needs starting row,
      // but you will use the two locations for doing Dijkstra's
      int startRow = 0;
      cout << "Please enter starting row:" << endl;
      cin >> startRow;
  
      // find path by applying a greedy algorithm from the left side of the screen to the right
      findPath(elev_data, width, height, startRow, maxVal);
  
      // get the path written into a color grid for visualization
      //YOU: Change the path color to blue
      ColorGrid *cg = getImage(elev_data, width, height, maxVal);
  
      // visualize
      bridges.setDataStructure(cg);
  
      bridges.visualize();
  
      //  delete cg; //WRK Fix memory leak in BRIDGES
      //  delete[] elev_data; //WRK Ditto
  }