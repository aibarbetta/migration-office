#ifndef MIGRATION_OFFICE_MIGRATIONOFFICE_H
#define MIGRATION_OFFICE_MIGRATIONOFFICE_H

#include <list>
#include <string>
#include <vector>

#include "Stampers.h"
#include "Logger.h"
#include "SIGINTHandler.h"

class MigrationOffice {

    private:
        const int booths_number, stampers_number;
        const std::string people_file, alerts_file, fugitives_file;
        const bool debug;
        const std::string log_file;

        Stampers stampers;
        SIGINTHandler sigint_handler;
        Logger logger;

        std::list<pid_t> children_pids;
        std::vector<pid_t> booth_pids;

        void wait_children();

    public:
        MigrationOffice(const int booths_number, const int stampers_number,
                        const std::string people_file, const std::string alerts_file,
                        const std::string fugitives_file, const bool debug, const std::string log_file);
        void start();
        void open_ministry_of_security();
        void open_booths();
        void fork_spawner();
        void open_statistics();
        ~MigrationOffice();

};


#endif //MIGRATION_OFFICE_MIGRATIONOFFICE_H
