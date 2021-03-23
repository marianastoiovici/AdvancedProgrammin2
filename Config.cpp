#include <iostream>
#include <fstream>

using namespace std;

#include "Config.h"


//read the config file (adaship_config.ini) and returns whether this was completed successfully or not
bool Config::readConfigFile() {
  cout << "Reading the config file...\n";
  ifstream configFile;
  string configLine = "";

  // set variables to check whether the board dimensions have been set and
  // at least one boat has been added
  bool boardConfigured = false;
  bool boatConfigured = false;

  configFile.open("adaship_config.ini");

  // read the file line by line 
  while(!configFile.eof()) { // while not at the end of the file
    getline(configFile, configLine); //read line from file and store it in configLine variable
    string type = "";
    int index = 0;
    //read the configLine until the ':' to get whether is config for the board or boat
    while (index < configLine.length() && configLine[index] != ':') {
      //update variable type 
      type += tolower(configLine[index]);
      index++; // update index
    }
    // skip over the ':'
    index += 1;
    // if is a board update the board with the rest of the configLine
    if (type == "board") {
      if (configureBoard(configLine, index)) {
        //cout << "Board is set" << "\n";
        boardConfigured = true;
      }
      // if is a boat update boats
    } else if (type == "boat") {
      if (configureBoat(configLine, index)) {
        //cout << "Boat is set" << "\n";
        boatConfigured = true;
      }
    }
    
  }

  // close the file
  configFile.close();
  cout << "\nConfig file finished and closed.\n\n";
	return (boatConfigured && boardConfigured);
}

 // Sets the board configuration according to the config file and returns whether this completed successfully or not
bool Config::configureBoard(string configLine, int index) {
  string rows = "";
  string columns = "";
  
  //skip the non digit characters after ':'
  while (index < configLine.length() && !isdigit(configLine[index])) {
    index++;
    if (index == configLine.length()) {
      return false;
    }
  }
 // get numeric characters and store them in the 'rows' string
  while (index < configLine.length() && isdigit(configLine[index])) {
    rows += configLine[index];
    index++;
    //cout << "rows: " << rows << "\n";
    if (index == configLine.length()) {
      return false;
    }
  }
  // skip over the 'x' char or any other extra white spaces
  while (index < configLine.length() && !isdigit(configLine[index])) {
    index++;
    if (index == configLine.length()) {
      return false;
    }
  }
  // get numeric characters and store them in the 'columns' string
  while (index < configLine.length() && isdigit(configLine[index])) {
    columns += configLine[index];
    // cout << "columns: " << columns << "\n";
    index++;
    // end of line reached => invalid config file line
  }

  rows_ = stoi(rows);// convert string to int for rows
  columns_ = stoi(columns); // convert string to int for columns
  cout << "Board has rows: " << rows_ << " and columns: " << columns_ << "\n";
  return true; 
}

// reads the length of the boat from the config file 
bool Config::configureBoat(string configLine, int index) {
  //skip the white spaces after ':'
  if (configLine[index] == ' ') {
    index++;
  }
  // get the name of the boat by reading up until ','
  string name = "";
  while (index < configLine.length() && configLine[index] != ',') {
    name += configLine[index];
    index++;
    if (index == configLine.length()) {
      return false;
    }
  }
  cout << "name: " << name << "\n";

  // skip over  ',' or white spaces 
  while (index < configLine.length() && !isdigit(configLine[index])) {
    index++;
    if (index == configLine.length()) {
      return false;
    }
  }
  // get the length of the boat from here
  string length = "";
  while (index < configLine.length() && isdigit(configLine[index])) {
    length += configLine[index];
    index++;
  }
  cout << "Boat's length is:  " << length  << "\n";

  return true;
}