#ifndef TCP_H
#define TCP_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include <QPalette>
#include <QMovie>
#include <QMoveEvent>
#include <QMessageBox>
#include <QSpacerItem>
#include "server.h"
//#include "dialog.h"
#include "switchwidget.h"
#include "djwidget.h"
#include "MyButton.h"
#include "switchwidget.h"
#include "scenchangwidget.h"
#include "glspoutimagewidget.h"
#include "bigsreenform.h"
#include "mymouseqlabel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Tcp; }
QT_END_NAMESPACE

class Tcp : public QWidget
{
    Q_OBJECT

public:
    Tcp(QWidget *parent = nullptr);
    ~Tcp();
    void keyPressEvent(QKeyEvent  *event);

    void HandleAllInteractionInfMsg(QJsonObject jsonObject);
    void HandleErrorMsg(QJsonObject jsonObject);
    void HandleSwitchCameraMsg(QJsonObject jsonObject);
    void HandleAutoMotionMsg(QJsonObject jsonObject);
    void HandlesenceChange(QJsonObject jsonObject);
    //添加道具界面
    void AddAnyWidget();
    void updadewidget();
    void updatelist();

    //纹理贴图需要的函数
    void UpdateTextureName(QString);
public slots:
    // server
    void CreateServer();
    void HandleMsg(const QString &str);
    void DisplayErrorMsg(QString msg);
    // qml
    void SendCameraMsg(QString motion);
    void SendCameraWidgetMsg(QString motion);
    void OpenScreenFile();
    void SendItemMsg(QString item);
    void SendAutoMotionMsg(QString name,bool state);
    void SendAutoFwBtnMsg(QString name);
    void Open_SChangWidget();
    void HandleCameraChangeMsg(QString);
    void sendScenceMsg(QString name);
    void sendSliderValue(int value);


signals:
    // server
    void serverMsg(const QString &);
    void UpdateSpoutWidgetsignal();
private:
private:
    Ui::Tcp *ui;
    Server *server;
    QThread *serverThread;
    QString mapName;
    QList<QString> itemList;
    QTimer* msgDisplayTimer;
    QTimer* test1Timer;
    QTimer* test2Timer;
    QTimer* errormsgTimer;
    QMessageBox *errormsgBox;

    QList<QString> DjList;
    DjWidget *djwidget[100];

    QList<QString> FwList;
    KeyButton *fwbutton[100];

    SwitchWidget *switwchidget[100];
    QList<QString> SWList;

    QMap<QString,QList<QString>> cameraMap;
    GLSpoutImageWidget *glspoutwidget;
    KeyButton *Jwbutton[10];

    BigSreenForm *bigSreenWidget[10];
    QList<QString> BScreenList;
    QList<QString> BScreenList2;
    ScenChangWidget *SCForm;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QList<QString> scencForm;
    QList<QString> scencFormname;
    QString cameraString;
    GLuint m_SpoutTexIDs[3] = { 6, 8, 10 };
    KeyButton *JwSpoutButton[10];
};
#endif // TCP_H
