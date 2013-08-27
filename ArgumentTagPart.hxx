/* Maciej Poleski (C) 2012 */

#ifndef ARGUMENTTAGPART_HXX
#define ARGUMENTTAGPART_HXX

#include <cstdint>
#include <string>

#include "TagPart.hxx"

class ArgumentTagPart : public TagPart
{
public:
    explicit ArgumentTagPart(uint8_t argument);
    ArgumentTagPart(const ArgumentTagPart &o);

    uint8_t argument() const;
    void setArgument(const uint8_t argument);

    virtual std::shared_ptr< InstructionPart > clone() const override;
    virtual std::string code() const override;
    virtual std::string description() const override;
    virtual QColor color() const override;

private:
    uint8_t _argument;
};

#endif // ARGUMENTTAGPART_HXX

