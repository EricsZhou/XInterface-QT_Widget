#ifndef GLSPOUTIMAGEWIDGET_H
#define GLSPOUTIMAGEWIDGET_H
#include "glwidget.h"
#include <QWidget>
#include <SpoutGL/Spout.h>
#include <SpoutGL/SpoutReceiver.h>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
class GLSpoutImageWidget : public QWidget
{
    Q_OBJECT
public:
    GLSpoutImageWidget(QWidget *parent = nullptr);
    ~GLSpoutImageWidget();
protected:
    void resizeEvent(QResizeEvent* event) override;
public:

    GLuint m_SpoutTexIDs[3] = { 6, 8, 10 };    //纹理Id
    QTimer* timer;
    SpoutReceiver m_SpoutReceivers[3];
    unsigned int g_SenderWidth;
    unsigned int g_SenderHeight;
    unsigned int g_SenderFormat;
    QGridLayout *mainLayout;
    QLabel *label[3];
    GLWidget* currentGlWidget;
    GLWidget* glWidgets[3];
    QColor clearColor;
    QPalette pa;
public slots:
    void getImageData();
    void setCurrentGlWidget();
    void setupReceivers();

signals:
};

#endif // GLSPOUTIMAGEWIDGET_H
