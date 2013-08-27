#include <memory>

#include <QtCore/QTextCodec>
#include <QtGui/QApplication>

#include "InstructionEdit.hxx"
#include "Instruction.hxx"
#include "TextPart.hxx"
#include "BitsTagPart.hxx"
#include "ArgumentTagPart.hxx"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    Instruction instruction;
    instruction.addPart(std::make_shared<TextPart>("Jakiś tekst "));
    instruction.addPart(std::make_shared<BitsTagPart>(0,4));
    instruction.addPart(std::make_shared<TextPart>(" znowu jakiś tekst "));
    instruction.addPart(std::make_shared<BitsTagPart>(1,8));
    instruction.addPart(std::make_shared<TextPart>(" kolejny tekst "));
    instruction.addPart(std::make_shared<ArgumentTagPart>(0));
    instruction.addPart(std::make_shared<TextPart>(" ostatni tekst."));
    InstructionEdit textEdit;
    textEdit.setInstruction(instruction);
    textEdit.show();
    return app.exec();
}
