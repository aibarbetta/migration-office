#include "AlertDeserializer.h"
#include "ConfigurationFileReader.h"

WantedPersonAlert* AlertDeserializer::deserialize(std::string& serialized_alert) {
    std::vector<std::string> tokenized_line = ConfigurationFileReader::split_line_into_tokens(serialized_alert);

    std::vector<std::string> raw_features(tokenized_line.begin(), tokenized_line.end());
    std::list<Feature*> features = ConfigurationFileReader::extract_features(raw_features);

    return new WantedPersonAlert(features);
}