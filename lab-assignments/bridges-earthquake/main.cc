#include "Bridges.h"
#include "DataSource.h"
#include "Array.h"
#include "SLelement.h"
#include <numeric>
#include <algorithm>
using namespace bridges;

/*
 * Case Sensitive Implementation of endsWith()
 * It checks if the string 'mainStr' ends with given string 'toMatch'
 * Use this to see if a earthquake is in Alaska or Hawaii
 *
 * From: http://thispointer.com/c-how-to-check-if-a-string-ends-with-an-another-given-string/
 */
bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
    if(mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
        return true;
    else
        return false;
}

void setProperties(SLelement<EarthquakeUSGS>* el) {
    //TODO: set the properties on the element based on location, magnitude of the earthquake
    //Documentation link for the EarthquakeUSGS class:
    //https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1dataset_1_1_earthquake_u_s_g_s.html
    EarthquakeUSGS val = el->getValue();

    //You get members of normal variables with ., from pointers with ->
    string loc = val.getLocation();

    vector<string> vec;
    string place;
//  getline(cin, location);

    stringstream ss(loc);

    while (ss) {
        ss >> place;
        if (!ss) break;
        vec.push_back(place);
    }
//  cout << vec.size() << endl;
    if (vec.back() == "Hawaii"){
    //  cerr << " Hawaii" << endl;
        el->setShape(Shape::CROSS);
    }
    else if (vec.back() == "Alaska"){
        el->setShape(Shape::DIAMOND);
    } else el->setShape(Shape::CIRCLE);
//      cerr << "Location: " << loc << endl;
//      cerr << "Mag: " << val.getMagnitude() << endl;
        //DELETEME
    //Here's how you get the magnitude of the quake
//  cout << loc << endl;
    float obscureval42 = val.getMagnitude(); //DELETEME
    if (obscureval42 >= 5) el->setSize(20);
    else
    el->setSize(10 + 2.5 * (obscureval42-1));

    if (obscureval42 <= 1.0) el->setColor("blue");
    if (obscureval42 >= 1.1 && obscureval42 <= 1.9) el->setColor("green");
    if (obscureval42 >= 2.0 && obscureval42 <= 2.9) el->setColor("yellow");
    if (obscureval42 >= 3.0 && obscureval42 <= 3.9) el->setColor("orange");
    if (obscureval42 >= 4.0 && obscureval42 <= 4.9) el->setColor("red");
    if (obscureval42 >= 5.0) el->setColor("purple");
    //TODO: Change all these - they're just here to show you how to do it
    //Documentation link for the Element class:

    //https://bridgesuncc.github.io/doc/cxx-api/current/html/classbridges_1_1datastructure_1_1_element.html
/*
    el->setSize(rand()%20+1); //Sets a random size
    el->setColor("green");
    el->setColor("yellow");
    el->setColor("orange");
    el->setColor("red");
    el->setColor("purple");
    el->setShape(Shape::CROSS);
    el->setShape(Shape::CIRCLE);
    el->setShape(Shape::DIAMOND); //This will set the node to be a diamond
*/}
//double
double mean(std::vector<EarthquakeUSGS>vec){
    vector<double>val;
    double sum = 0;
    for(auto m : vec){
        val.push_back(m.getMagnitude());
        sum = sum + m.getMagnitude();
//      cout << "Inside Mean: " << m.getMagnitude() << endl;
    }
//  cout << "Val Size: " << val.size() << endl;
//  double sum = accumulate(val.begin(),val.end(),0);
//  cout << "Sum: " << sum << " Temp Mean: " << temp / val.size() << endl;
    return sum / val.size();
}
int mode(std::vector<EarthquakeUSGS>vec) {
    if (!vec.size()) return 0;
    vector<int>val;
    for(auto m : vec){
        val.push_back(m.getMagnitude());
    }
    int mode = val.front();
    int max = 0;
    for (size_t i = 0; i < vec.size(); i++){
        int temp = val.at(i);
        int counter = std::count(val.begin()+ i + 1, val.end(), temp);
        if (counter > max){
        mode = temp;
        max = counter;
        }
    }
    return mode;
}
double median(std::vector<EarthquakeUSGS>vec) {
 /*   for (auto m : vec){

        cout << "Check Median " << m.getMagnitude() << endl;
    }*/
//  cout << "\n First half: "<< vec.at(vec.size() / 2).getMagnitude() << endl;
//  cout <<" Second half: " <<vec.at(vec.size() / 2 - 2).getMagnitude() << endl;
//  cout << " Second half + 1: " <<vec.at(vec.size() / 2 + 2).getMagnitude() << endl;
    vector<double>val;
      for(auto m : vec){
          val.push_back(m.getMagnitude());
      }
      sort(val.begin(),val.end());
    if (!val.size()) return 0;

    if (val.size() % 2) return val.at(val.size() / 2);
    else return (val.at(val.size() / 2) + val.at(val.size() / 2 + 1)) / 2;
}
int main() {
    //Put your BRIDGES username and API key here, then delete the static_assert
    const int bridges_project_id = 1002;
    const string bridges_username = "mzamudio";
    const string bridges_api_key  = "816786603169";
    //Delete this line once you get registered on BRIDGES
    //  static_assert(false,"You must register on BRIDGES and put your own username and API key here.");

    // bridges object initialization
    Bridges bridges(bridges_project_id, bridges_username, bridges_api_key);

    bridges.setTitle("100 Most Recent Earthquakes");

    //Get Earthquake data
    DataSource ds;
    std::vector< EarthquakeUSGS > eqs = ds.getEarthquakeUSGSData(100); //Get 100 most recent earthquakes

    //Building linked list
    SLelement<EarthquakeUSGS>* head = nullptr;

    for (auto eq : eqs) {
        SLelement<EarthquakeUSGS>* newone = new SLelement<EarthquakeUSGS> (eq,eq.getTitle());
        newone->setNext(head);
        head = newone;
    }
        //Setting properties.
    SLelement<EarthquakeUSGS>* current = head;
    while (current != nullptr) {
        setProperties(current);
        current = current->getNext();
    }

    // tell Bridges what data structure to visualize
    bridges.setDataStructure(head);

    // visualize the list
    bridges.visualize();

    //TODO: Output the mean, median, and mode of the earthquakes, using integers (no floats)
    cout << "AVERAGE = " << mean(eqs) << endl;
    cout << "MEDIAN = " << median(eqs) << endl;
    cout << "MODE =  " << round(mode(eqs)) << endl;

    //free memory
    while (head != nullptr) {
        auto next = head->getNext();
        delete head;
        head = next;
    }

    return 0;
}