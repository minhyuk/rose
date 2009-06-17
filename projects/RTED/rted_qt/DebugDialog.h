#ifndef DEBUG_DIALOG_H
#define DEBUG_DIALOG_H

#include <QDialog>

#include "ui_DebugDialog.h"


class RuntimeVariablesType;
class MemoryType;
class ArraysType;

class PropertyTreeWidget;

class RuntimeVariablesModel;
class MemoryTypeModel;
class QSortFilterProxyModel;

class DebugDialog : public QDialog
{
    Q_OBJECT

    public:
        DebugDialog(QWidget * parent =0);

        void setHeapVars(RuntimeVariablesType * arr, int arrSize);
        void setStackVars(RuntimeVariablesType * arr, int arrSize);

        void setMemoryLocations(MemoryType * arr, int arrSize);

    protected slots:
        void on_lstHeap_clicked(const QModelIndex & ind);
        void on_lstStack_clicked(const QModelIndex & ind);
        void on_lstMem_clicked(const QModelIndex & ind);


    protected:
        void displayRuntimeVariable(RuntimeVariablesType * rv, PropertyTreeWidget * w);
        void displayMemoryType(MemoryType * mt, PropertyTreeWidget * w);

        void addArraySection(PropertyTreeWidget * w, int sectionId, ArraysType * at);
        void addMemorySection(PropertyTreeWidget * w, int sectionId, MemoryType * mt);
        void addVariableSection(PropertyTreeWidget * w, int id, RuntimeVariablesType * rv);

        RuntimeVariablesModel * heapModel;
        QSortFilterProxyModel * heapProxyModel;

        RuntimeVariablesModel * stackModel;
        QSortFilterProxyModel * stackProxyModel;

        MemoryTypeModel *  memModel;
        QSortFilterProxyModel * memProxyModel;

        Ui::DebugDialog ui;
};

#endif

