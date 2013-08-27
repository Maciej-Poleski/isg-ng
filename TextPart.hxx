/* Maciej Poleski (C) 2012 */

#ifndef TEXTPART_HXX
#define TEXTPART_HXX

#include <string>

#include "InstructionPart.hxx"

class TextPart : public InstructionPart
{
public:
    explicit TextPart(const std::string &text);
    TextPart(const TextPart &textPart);

    virtual std::shared_ptr< InstructionPart > clone() const override;
    virtual std::string code() const override;
    virtual std::string description() const override;
    virtual QColor color() const override;

private:
    std::string _text;
};

#endif // TEXTPART_HXX
