/* Maciej Poleski (C) 2012 */

#include "TextPart.hxx"

TextPart::TextPart(const std::string& text) : _text(text)
{

}

TextPart::TextPart(const TextPart& textPart) : _text(textPart._text)
{

}

std::shared_ptr< InstructionPart > TextPart::clone() const
{
    return std::make_shared<TextPart>(*this);
}

std::string TextPart::code() const
{
    return _text;
}

std::string TextPart::description() const
{
    return _text;
}

QColor TextPart::color() const
{
    return QColor(Qt::GlobalColor::black);
}
