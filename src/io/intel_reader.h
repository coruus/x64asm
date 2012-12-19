#ifndef X64_SRC_IO_INTEL_READER_H
#define X64_SRC_IO_INTEL_READER_H

#include <iostream>

#include "src/code/code.h"

namespace x64 {

class IntelReader {
	public:
		void read(std::istream& is, Code& code) const;
};

} // namespace x64

#endif