#include <csignal>
#include "Person.h"
#include "PersonSerializer.h"
#include "SignalHandler.h"
#include "ConfigurationFileReader.h"
#include "PeopleSpawner.h"

const static std::string fifo_file = "./migration_spawner";

PeopleSpawner::PeopleSpawner(const std::string& people_file, const bool debug, const std::string& log_file)
        : Spawner(people), people_file(people_file), debug(debug), log_file(log_file), fifo(fifo_file) {

    ConfigurationFileReader fr;
    fr.load_persons(people_file, people);

    fifo.fifo_open();

    SignalHandler::get_instance()->register_handler(SIGINT, &sigint_handler);
}

void PeopleSpawner::spawn(Spawnable* spawnable) {
    std::string serialized_person = PersonSerializer::serialize((Person*)spawnable);
    unsigned long serialization_length = serialized_person.size();
    fifo.fifo_write(&serialization_length, sizeof(unsigned long));
    fifo.fifo_write(serialized_person.c_str(), sizeof(char) * serialization_length);
}

bool PeopleSpawner::quit() {
    return sigint_handler.get_graceful_quit() == 1;
}

PeopleSpawner::~PeopleSpawner() {
    SignalHandler::destroy();
}