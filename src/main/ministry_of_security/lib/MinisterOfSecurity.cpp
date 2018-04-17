#include "MinisterOfSecurity.h"
#include "ConfigurationFileReader.h"

#include <fstream>
#include <sstream>
#include <iostream>

MinisterOfSecurity::MinisterOfSecurity(const std::string& alerts_file_path) {
    ConfigurationFileReader fr;
    fr.load_alerts(alerts_file_path, alerts);
}

Spawnables& MinisterOfSecurity::get_alerts() {
    return alerts;
}