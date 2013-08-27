/* Maciej Poleski (C) 2012 */

#ifndef TEXTEDIT_HXX
#define TEXTEDIT_HXX

#include <QtGui/QTextEdit>

#include "Instruction.hxx"

class InstructionEdit : public QTextEdit
{
    Q_OBJECT
    enum class Mode : uint8_t;
    enum class Environment : uint8_t;

public:
    InstructionEdit(QWidget *parent=0);

    void setInstruction(const Instruction &instruction);
    Instruction instruction() const;

    virtual void keyPressEvent(QKeyEvent* e) override;
    virtual void dragEnterEvent(QDragEnterEvent* e) override;
    virtual void dragLeaveEvent(QDragLeaveEvent* e) override;
    virtual void dragMoveEvent(QDragMoveEvent* e) override;
    virtual void dropEvent(QDropEvent* e) override;
    virtual void inputMethodEvent(QInputMethodEvent* e) override;
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery property) const override;
    virtual void keyReleaseEvent(QKeyEvent* e) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
    virtual void mousePressEvent(QMouseEvent* e) override;
    virtual void mouseReleaseEvent(QMouseEvent* e) override;
    virtual void wheelEvent(QWheelEvent* e) override;

private:
    Environment currentEnvironment() const;
    void repopulate();

    Instruction _instruction;

    enum class Mode : uint8_t
    {
        standard,
        control,
    } _mode;

    enum class Environment : uint8_t
    {
        text,
        tag,
    };
};

#endif // TEXTEDIT_HXX
