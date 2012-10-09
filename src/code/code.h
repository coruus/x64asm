#ifndef X64_SRC_CODE_CODE_H
#define X64_SRC_CODE_CODE_H

#include <cassert>
#include <initializer_list>
#include <iostream>

#include "src/code/instruction.h"

namespace x64 {

/** A list of Instruction, suitable for printing to assembly.
	  Supports basic modification.
*/
class Code {
	public:
		typedef std::vector<Instruction>::iterator iterator;
		typedef std::vector<Instruction>::const_iterator const_iterator;

		/** Constructs an empty Code block.
		*/
		inline Code() { }

		/** Constructs a non-empty Code block.
			  @param instrs Instruction to populate the block with.
		*/
		inline Code(const std::initializer_list<Instruction>& instrs) 
				: instrs_(instrs) {
		}

		/** Returns the number of Instruction in the block.
		*/
		inline size_t size() const {
			return instrs_.size();
		}

		/** Returns a reference to an Instruction.
				@param index The index of the Instruction, asserts if out of range.
		*/
		inline Instruction& get(size_t index) {
			assert(index < size());
			return instrs_[index];
		}

		/** Returns a const reference to an Instruction.
				@param index The index of the Instruction, asserts if out of range.
		*/
		inline const Instruction& get(size_t index) const {
			assert(index < size());
			return instrs_[index];
		}

		inline iterator begin() {
			return instrs_.begin();
		}

		inline iterator end() {
			return instrs_.end();
		}

		inline const_iterator begin() const {
			return instrs_.begin();
		}

		inline const_iterator end() const {
			return instrs_.end();
		}

		inline void append(const Instruction& instr) {
			instrs_.push_back(instr);
		}

		template <typename InputIterator>
		inline void assign(InputIterator begin, InputIterator end) {
			instrs_.assign(begin, end);
		}

		inline void clear() {
			instrs_.clear();
		}

		void read_att(std::istream& is);

		inline void write_att(std::ostream& os) const {
			for ( const auto instr : instrs_ ) {
				instr.write_att(os);
				os << std::endl;
			}
		}

	private:	
		std::vector<Instruction> instrs_;
};

} // namespace x64

#endif