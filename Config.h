#pragma once

#include <string>

using namespace std;

class Config {
  private:
    int rows_; //board rows
    int columns_; // board columns
    
    // Gets the board's rows and columns and returns whether the action was successful or not
    bool configureBoard(string configLine, int index);

    // Gets the boat's name and length and returns whether the action was successful or not
    bool configureBoat(string configLine, int index);

  public:
    Config() {
      rows_ = 0;
      columns_ = 0;
    }

   // Reads the config file provided and returns whether the action was successful or not
    bool readConfigFile();
    
   // Getter for number of rows
    int rows() {
      return rows_;
    }
    
    // Getter for number of columns
    int columns() {
      return columns_;
    }
};