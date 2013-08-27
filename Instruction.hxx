/* Maciej Poleski (C) 2012 */

#ifndef INSTRUCTION_HXX
#define INSTRUCTION_HXX

#include <vector>
#include <memory>

class InstructionPart;

class Instruction
{
public:
    Instruction();
    Instruction(const Instruction &instruction);

    void addPart(std::shared_ptr< InstructionPart > textPart);

    std::vector< std::shared_ptr< InstructionPart > >::iterator begin();
    std::vector< std::shared_ptr< InstructionPart > >::iterator end();
    std::vector< std::shared_ptr< InstructionPart > >::const_iterator cbegin() const;
    std::vector< std::shared_ptr< InstructionPart > >::const_iterator cend() const;

private:
    std::vector<std::shared_ptr<InstructionPart>> _instructionParts;
};

#endif // INSTRUCTION_HXX
