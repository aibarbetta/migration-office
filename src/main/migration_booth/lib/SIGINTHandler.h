#ifndef MIGRATION_OFFICE_SIGINTHANDLER_H
#define MIGRATION_OFFICE_SIGINTHANDLER_H

#include <signal.h>

#include "EventHandler.h"

class SIGINTHandler : public EventHandler {

    private:
        sig_atomic_t graceful_quit;

    public:
        SIGINTHandler();
        ~SIGINTHandler();
        virtual int handle_signal(int signum);
        sig_atomic_t get_graceful_quit() const;

};


#endif //MIGRATION_OFFICE_SIGINTHANDLER_H
