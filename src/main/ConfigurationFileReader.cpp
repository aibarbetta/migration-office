#include <fstream>
#include <sstream>

#include "ConfigurationFileReader.h"
#include "Feature.h"
#include "WantedPersonAlert.h"

void ConfigurationFileReader::load_alerts(const std::string& alerts_file_path, Spawnables& alerts) {
    std::ifstream ifs(alerts_file_path);
    std::string line;

    // Get header
    std::getline(ifs, line);
    while (std::getline(ifs, line)) {

        std::list<Feature*> wanted_person_features;

        std::stringstream ss(line);
        std::string feature_str;

        std::getline(ss, feature_str, ',');
        int timestamp = stoi(feature_str);

        while (std::getline(ss, feature_str, ','))  {
            Feature* feature = new Feature(feature_str);
            wanted_person_features.push_back(feature);
        }

        alerts.push_spawnable(timestamp, new WantedPersonAlert(wanted_person_features));
    }
}

void ConfigurationFileReader::load_fugitives_ids(std::list<std::string>& fugitives_ids) {
    std::ifstream ifs("../resources/fugitives.txt");
    std::string fugitive_id;

    // Get header
    std::getline(ifs, fugitive_id);
    while (std::getline(ifs, fugitive_id)) {
        fugitives_ids.emplace_back(fugitive_id);
    }
}