#ifndef MIGRATION_OFFICE_FIFOREADER_H
#define MIGRATION_OFFICE_FIFOREADER_H

#include "Fifo.h"

class FifoReader : public Fifo {

	public:
		FifoReader(const std::string name);
		void fifo_open();
		ssize_t fifo_read(void* buffer, const ssize_t buffsize) const;
		~FifoReader();

};

#endif /* MIGRATION_OFFICE_FIFOREADER_H */