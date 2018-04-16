#ifndef MIGRATION_OFFICE_POLICE_H
#define MIGRATION_OFFICE_POLICE_H

#include "Resident.h"
#include "Foreigner.h"
#include "FifoReader.h"
#include "ExclusiveLock.h"

#include <vector>

class Police {

    private:
        FifoReader fugitives_fifo;
        ExclusiveLock fugitives_fifo_lock;
        std::vector<unsigned int> fugitives;

        void receive_fugitives();
    public:
        Police();
        bool is_fugitive(Resident* resident);
        bool is_wanted_person(Foreigner* foreigner);
        void report(Resident* resident);

};


#endif //MIGRATION_OFFICE_POLICE_H
