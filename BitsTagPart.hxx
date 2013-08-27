/* Maciej Poleski (C) 2012 */

#ifndef BITSTAGPART_HXX
#define BITSTAGPART_HXX

#include <cstdint>
#include <string>

#include "TagPart.hxx"

class BitsTagPart : public TagPart
{
public:
    BitsTagPart(uint8_t position,uint8_t count);
    BitsTagPart(const BitsTagPart &o);

    uint8_t position() const;
    void setPosition(const uint8_t& position);
    uint8_t count() const;
    void setCount(const uint8_t& count);

    virtual std::shared_ptr< InstructionPart > clone() const override;
    virtual std::string code() const override;
    virtual std::string description() const override;
    virtual QColor color() const override;

private:
    uint8_t _position;
    uint8_t _count;
};

#endif // BITSTAGPART_HXX
