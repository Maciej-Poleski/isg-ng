/* Maciej Poleski (C) 2012 */

#include "InstructionEdit.hxx"

#include <iostream>

#include <QtGui/QKeyEvent>

#include "InstructionPart.hxx"

InstructionEdit::InstructionEdit(QWidget* parent): QTextEdit(parent),
    _mode(Mode::control)
{
    setContextMenuPolicy(Qt::NoContextMenu);
    setUndoRedoEnabled(false);
    resize(600,100);
}

Instruction InstructionEdit::instruction() const
{
    return _instruction;
}

void InstructionEdit::setInstruction(const Instruction& instruction)
{
    _instruction=instruction;
    repopulate();
}

void InstructionEdit::keyPressEvent(QKeyEvent* e)
{
    // strategy pattern here
    // getStrategyForPosition - after change of cursor position
    // flyweight - for commiting user changes into TextEdit (this)
    if(e->key()==Qt::Key_Enter || e->key()==Qt::Key_Return)
    {
        std::cout<<"Enter"<<std::endl;
        setTextColor(QColor(Qt::blue));
    }
    else if(e->key()==Qt::Key_Delete)
    {
        // ignore
    }
    else if(e->text().isEmpty()==false)
    {
        insertPlainText(e->text());
        std::cout<<this->toHtml().toStdString()<<std::endl;
    }
    else
    {
        std::cout<<"Empty"<<std::endl;
        setTextColor(QColor(Qt::red));
    }
    // ESC, Delete, Backspace
    
    // already accepted
}

void InstructionEdit::repopulate()
{
    clear();
    for(auto instructionPart : _instruction)
    {
        setTextColor(instructionPart->color());
        insertPlainText(instructionPart->code().c_str());
    }
}

void InstructionEdit::dragEnterEvent(QDragEnterEvent* e)
{
    e->ignore();
}

void InstructionEdit::dragLeaveEvent(QDragLeaveEvent* e)
{
    e->ignore();
}

void InstructionEdit::dragMoveEvent(QDragMoveEvent* e)
{
    e->ignore();
}

void InstructionEdit::dropEvent(QDropEvent* e)
{
    e->ignore();
}

void InstructionEdit::inputMethodEvent(QInputMethodEvent* e)
{
    e->ignore();
}

QVariant InstructionEdit::inputMethodQuery(Qt::InputMethodQuery property) const
{
    return QTextEdit::inputMethodQuery(property);
}

void InstructionEdit::keyReleaseEvent(QKeyEvent* e)
{
    Q_UNUSED(e);
    // already accepted
}

void InstructionEdit::mouseDoubleClickEvent(QMouseEvent* e)
{
    e->ignore();
}

void InstructionEdit::mouseMoveEvent(QMouseEvent* e)
{
    e->ignore();
}

void InstructionEdit::mousePressEvent(QMouseEvent* e)
{
    e->ignore();
}

void InstructionEdit::mouseReleaseEvent(QMouseEvent* e)
{
    e->ignore();
}

void InstructionEdit::wheelEvent(QWheelEvent* e)
{
    e->ignore();
}


