/* Maciej Poleski (C) 2012 */

#ifndef INSTRUCTIONPART_HXX
#define INSTRUCTIONPART_HXX

#include <memory>

#include <QtGui/QColor>

class InstructionPart
{
public:
    virtual ~InstructionPart();

    virtual std::shared_ptr<InstructionPart> clone() const=0;

    virtual std::string description() const=0;
    virtual std::string code() const=0;
    virtual QColor color() const=0;
};

#endif // INSTRUCTIONPART_HXX
