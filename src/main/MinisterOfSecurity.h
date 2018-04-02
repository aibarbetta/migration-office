#ifndef MIGRATION_OFFICE_MINISTEROFSECURITY_H
#define MIGRATION_OFFICE_MINISTEROFSECURITY_H

#include "WantedPersonAlert.h"
#include "Spawner.h"

class MinisterOfSecurity {

    private:
        Spawnables alerts;
        void load_alerts(const std::string& file_path);

    public:
        explicit MinisterOfSecurity(const std::string& alerts_file_path);
        Spawnables& get_alerts();
        ~MinisterOfSecurity();

};


#endif //MIGRATION_OFFICE_MINISTEROFSECURITY_H
