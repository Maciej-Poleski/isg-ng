/* Maciej Poleski (C) 2012 */

#include "ArgumentTagPart.hxx"

ArgumentTagPart::ArgumentTagPart(uint8_t argument) : _argument(argument)
{

}

ArgumentTagPart::ArgumentTagPart(const ArgumentTagPart& o):
    _argument(o._argument)
{

}

uint8_t ArgumentTagPart::argument() const
{
    return _argument;
}
void ArgumentTagPart::setArgument(const uint8_t argument)
{
    _argument = argument;
}

std::shared_ptr< InstructionPart > ArgumentTagPart::clone() const
{
    return std::make_shared<ArgumentTagPart>(*this);
}

std::string ArgumentTagPart::code() const
{
    return "[arg" + std::to_string(_argument) + "]";
}

std::string ArgumentTagPart::description() const
{
    return std::to_string(_argument) + ". argument";
}

QColor ArgumentTagPart::color() const
{
    return QColor(Qt::GlobalColor::blue);
}
