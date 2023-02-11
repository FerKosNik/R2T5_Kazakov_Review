#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QFile>
#include <QTextEdit>
#include <QSharedPointer>
#include "helpbrowser.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  Ui::MainWindow *ui;

  //Указатель на текущий редактируемый файл
  QFile *file;

  QSharedPointer<HelpBrowser> hb;

  /*! KuznecovAG
    Переменная для текущего стиля (пока только white и grey) */
  QString currentStyle = "white";

  //Пункты меню
  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *settingsMenu;
  QMenu *questionMenu;

  //Вспомогательные методы для читабельности конструктора
  void createAction(QAction **, const QString &, const QString &,
                    void (MainWindow::*)());
  void createActions();
  void createMenus();

  //Элементы подменю 'File'
  QAction *newAction;
  QAction *openAction;
  QAction *closeAction;
  QAction *saveAction;
  QAction *saveAsAction;
  QAction *printAction;
  QAction *exitAction;

  //Элементы подменю 'Edit'
  QAction *copyTextFormatAction;
  QAction *applyTextFormatAction;
  QAction *alignTextRightAction;
  QAction *alignTextLeftAction;
  QAction *alignTextCenterAction;
  QAction *switchFontAction;

  //Элементы подменю 'Settings'
  QAction *changeLangAction;
  QAction *changeKeyBindAction;
  QAction *changeStyleAction;

  //Поле для размещения редактируемого текста
  QTextEdit *textEdit;
  QString lastFilename;
    
  //Элементы подменю '?'
  QAction *helpAction;
  QAction *aboutAction;

private slots:
  //Основные функции приложения
  void onNew();
  void onOpen();
  void onClose();
  void onSave();
  void onSaveAs();
  void onPrint();
  void onExit();
  void onCopyTextFormat();
  void onApplyTextFormat();
  void onAlignTextRight();
  void onAlignTextLeft();
  void onAlignTextCenter();
  void onSwitchFont();
  void onChangeLang();
  void onChangeKeyBind();
  void onChangeStyle();
  void onHelp();
  void onAbout();
};
#endif // MAINWINDOW_H
