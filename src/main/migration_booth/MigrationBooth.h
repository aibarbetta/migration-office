#ifndef MIGRATION_OFFICE_MIGRATIONBOOTH_H
#define MIGRATION_OFFICE_MIGRATIONBOOTH_H

#include <string>
#include <src/main/common/entities/Person.h>
#include <src/main/common/entities/Resident.h>
#include <src/main/common/entities/Foreigner.h>

class MigrationBooth {

    private:
        const std::string people_file, alerts_file, fugitives_file;
        const bool debug;
        const std::string log_file;

        std::list<int> arrived_residents_ids;

        void attend_resident(Resident* resident);
        void attend_foreigner(Foreigner* foreigner);

        // FIXME we dont belong here
        Stamper* get_stamper();
        bool is_fugitive(Resident* resident);
        bool is_wanted_person(Foreigner* foreigner);
        void report_to_police(Resident* resident);
        bool queue_empty();
        Person* front();

    public:
        MigrationBooth(const std::string people_file, const std::string alerts_file, const std::string fugitives_file,
                       const bool debug, const std::string log_file);
        void open();

};


#endif //MIGRATION_OFFICE_MIGRATIONBOOTH_H
