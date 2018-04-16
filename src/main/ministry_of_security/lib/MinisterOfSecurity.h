#ifndef MIGRATION_OFFICE_MINISTEROFSECURITY_H
#define MIGRATION_OFFICE_MINISTEROFSECURITY_H

#include "WantedPersonAlert.h"
#include "Spawner.h"
#include "FifoWriter.h"

#include <vector>


class MinisterOfSecurity {

    private:
        FifoWriter fifo;
        Spawnables alerts;
        std::vector<unsigned int> fugitives;
        const size_t booths_number;

    public:
        MinisterOfSecurity(const std::string& alerts_file_path,
                           const std::string& fugitives_file_path,
                           const size_t booths_number);
        void open();
        void send_fugitives();
        Spawnables& get_alerts();
        ~MinisterOfSecurity() = default;

};


#endif //MIGRATION_OFFICE_MINISTEROFSECURITY_H
