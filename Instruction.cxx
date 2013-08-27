/* Maciej Poleski (C) 2012 */

#include "Instruction.hxx"

#include "InstructionPart.hxx"

Instruction::Instruction()
{

}

Instruction::Instruction(const Instruction& instruction)
{
for(auto i : instruction._instructionParts)
        _instructionParts.push_back(i->clone());
}

void Instruction::addPart(std::shared_ptr< InstructionPart > textPart)
{
    _instructionParts.push_back(textPart);
}

std::vector< std::shared_ptr< InstructionPart > >::iterator Instruction::begin()
{
    return _instructionParts.begin();
}

std::vector< std::shared_ptr< InstructionPart > >::iterator Instruction::end()
{
    return _instructionParts.end();
}

std::vector< std::shared_ptr< InstructionPart > >::const_iterator
Instruction::cbegin() const
{
    return _instructionParts.cbegin();
}

std::vector< std::shared_ptr< InstructionPart > >::const_iterator
Instruction::cend() const
{
    return _instructionParts.cend();
}
