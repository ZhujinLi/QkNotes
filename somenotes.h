#ifndef SOMENOTES_H
#define SOMENOTES_H

#include <QWidget>
#include "contentmanager.h"
#include "noteblock.h"

class SomeNotes : public QWidget
{
    Q_OBJECT

public:
    explicit SomeNotes(QWidget *parent = nullptr);
    ~SomeNotes() override;

public slots:
    void backup();

private slots:
    void onCommitDataRequest() { m_mgr.save(); }
    void placeholderTextChanged();
    void onNoteBlockNoteDeleted(NoteBlock* noteBlock);
    void onNoteBlockTryMove(NoteBlock* noteBlock);
    void onNoteBlockDragProgress(bool isVertical, qreal progress, NoteBlock* noteBlock);
    void onNoteBlockDragReset();
    void onAutoSaveTimeout() { m_mgr.save(); }

private:
    ContentManager m_mgr;
    std::vector<NoteBlock*> m_noteBlocks;
    NoteBlockPlaceholder* m_placeholder;

    void _focusToNoteBlock(QPlainTextEdit* noteBlock);
    NoteBlock* _addNoteBlock(NoteBlockContent* content);
    void _setBgColor(QColor color);
    NoteBlock* _findOverlappingNoteBlock(NoteBlock* query);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SOMENOTES_H