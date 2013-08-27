/* Maciej Poleski (C) 2012 */

#include "BitsTagPart.hxx"

BitsTagPart::BitsTagPart(uint8_t position, uint8_t count) : _position(position),
    _count(count)
{

}

BitsTagPart::BitsTagPart(const BitsTagPart& o) : _position(o._position),
    _count(o._count)
{

}

uint8_t BitsTagPart::position() const
{
    return _position;
}

void BitsTagPart::setPosition(const uint8_t& position)
{
    _position=position;
}

uint8_t BitsTagPart::count() const
{
    return _count;
}

void BitsTagPart::setCount(const uint8_t& count)
{
    _count=count;
}

std::shared_ptr< InstructionPart > BitsTagPart::clone() const
{
    return std::make_shared<BitsTagPart>(*this);
}

std::string BitsTagPart::code() const
{
    return "[bits"+std::to_string(_position)+","+std::to_string(_count)+"]";
}

std::string BitsTagPart::description() const
{
    return "argument wbudowany w opcode";
}

QColor BitsTagPart::color() const
{
    return QColor(Qt::GlobalColor::magenta);
}
