#include <iostream>
using namespace std;

#include "Config.h"

int main() {
  // Instantiate a Config object
  Config config;

  // Read in the relevant data from the config file ('adaship_config.ini')
  bool configDone = config.readConfigFile();

  // If configuration fails, inform user and exit
  if (!configDone) {
    cout << "There seems to be a problem with the config file.\n";
    return 0;
  }

  return 0;
}