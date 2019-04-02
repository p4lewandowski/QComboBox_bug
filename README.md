# QComboBox_bug

This reportisory is related to the qtBug issue: https://bugreports.qt.io/browse/QTBUG-74890.
It concerns the problem with setting the input of editable QComboBox using setCurrentText() followed by selectAll().

## Startup
Compile the project using ComboBoxTest.pro file and run the executable, it will display simple window with QPushButton and editable QComboBox.

## Expected behaviour
Whenever the button is pressed new value should be *displayed* in the QComboBox. Whenever the Enter key is pressed the new value should be validated and *accepted* (added to the QCombobox).

## Problem
The code has two slots:
* **addEntry()** - calls setCurrentText() and selectAll() for new value whenever the button is clicked.
* **printValue()** - prints currentText() to qDebug() after signal &QLineEdit::editingFinished is emitted.

Whenever the button is pressed new value is displayed (OK).

When the Enter key is clicked for the first time given value is accepted by QComboBox (OK).

When user wants to accept new values the QComboBox by clicking the Enter key these are rejected and initial, first added value, is being shown (**not OK**).

### Steps to recreate
1. First Step
    1. Click "Add entry"
        * "0" in the combobox
        * "" outputted in qDebug()
    2. Click Enter key
        * "0" in the combobox
        * "0" outputted in qDebug()
  2. Second step
      1. Click "Add entry" again
          * "1" in the combobox
          * "0" outputted in qDebug()
      1. Click Enter key
          * **"0" in the combobox** (Not ok, there should be 1 in here)
          * "0" outputted in qDebug()

