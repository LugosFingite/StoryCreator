/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "nodeInfoChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "NodeInfo"
QT_MOC_LITERAL(4, 37, 22), // "on_pageEdit_textEdited"
QT_MOC_LITERAL(5, 60, 3), // "txt"
QT_MOC_LITERAL(6, 64, 24), // "on_addLinkButton_clicked"
QT_MOC_LITERAL(7, 89, 22), // "on_link1Button_clicked"
QT_MOC_LITERAL(8, 112, 22), // "on_link2Button_clicked"
QT_MOC_LITERAL(9, 135, 27), // "on_deleteEdgeButton_clicked"
QT_MOC_LITERAL(10, 163, 22), // "on_imageButton_clicked"
QT_MOC_LITERAL(11, 186, 20), // "on_sonButton_clicked"
QT_MOC_LITERAL(12, 207, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(13, 232, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(14, 257, 23), // "on_action_New_triggered"
QT_MOC_LITERAL(15, 281, 15), // "handleNodeFocus"
QT_MOC_LITERAL(16, 297, 20), // "handleNodeInfoChange"
QT_MOC_LITERAL(17, 318, 14), // "updateNodeInfo"
QT_MOC_LITERAL(18, 333, 14) // "updateEdgeInfo"

    },
    "MainWindow\0nodeInfoChanged\0\0NodeInfo\0"
    "on_pageEdit_textEdited\0txt\0"
    "on_addLinkButton_clicked\0"
    "on_link1Button_clicked\0on_link2Button_clicked\0"
    "on_deleteEdgeButton_clicked\0"
    "on_imageButton_clicked\0on_sonButton_clicked\0"
    "on_action_Save_triggered\0"
    "on_action_Open_triggered\0"
    "on_action_New_triggered\0handleNodeFocus\0"
    "handleNodeInfoChange\0updateNodeInfo\0"
    "updateEdgeInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   92,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeInfoChanged((*reinterpret_cast< NodeInfo(*)>(_a[1]))); break;
        case 1: _t->on_pageEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_addLinkButton_clicked(); break;
        case 3: _t->on_link1Button_clicked(); break;
        case 4: _t->on_link2Button_clicked(); break;
        case 5: _t->on_deleteEdgeButton_clicked(); break;
        case 6: _t->on_imageButton_clicked(); break;
        case 7: _t->on_sonButton_clicked(); break;
        case 8: _t->on_action_Save_triggered(); break;
        case 9: _t->on_action_Open_triggered(); break;
        case 10: _t->on_action_New_triggered(); break;
        case 11: _t->handleNodeFocus(); break;
        case 12: _t->handleNodeInfoChange(); break;
        case 13: _t->updateNodeInfo((*reinterpret_cast< NodeInfo(*)>(_a[1]))); break;
        case 14: _t->updateEdgeInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(NodeInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::nodeInfoChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::nodeInfoChanged(NodeInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE