#include "glspoutimagewidget.h"
int j=1;
#include <QOpenGLTexture>
extern QString SpoutSendname;
extern GLuint m_SpoutTexID;    //纹理Id
GLSpoutImageWidget::GLSpoutImageWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(320,200);
//    this->setMinimumSize(320,200);
    this->setMaximumSize(320,200);
    mainLayout = new QGridLayout();

    pa.setColor(QPalette::WindowText,Qt::white);


    clearColor.setHsv(0, 255, 63);

    for( int i =0;i<3;i++){
        label[i] = new QLabel(this);
        label[i]->setPalette(pa);
//        label[i]->setText("1111111");
        glWidgets[i] = new GLWidget(112, 63, 1, Qt::green);
        glWidgets[i]->setClearColor(clearColor);
        glWidgets[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        qDebug()<<i;
        connect(glWidgets[i], &GLWidget::clicked, this, &GLSpoutImageWidget::setCurrentGlWidget);
    }
    //gridlayout 布局
    mainLayout->setContentsMargins(0,0,0,0);//上下左右间隔
    mainLayout->setRowMinimumHeight(0,20);//设置最小高度
    mainLayout->setRowMinimumHeight(1,112);
    mainLayout->setRowMinimumHeight(2,20);
    mainLayout->setRowMinimumHeight(3,112);

    mainLayout->addWidget(label[0],0,0,1,1);
    mainLayout->addWidget(label[1],0,1,1,1);
    mainLayout->addWidget(label[2],2,0,1,1);
    mainLayout->addWidget(glWidgets[0],1,0,1,1);
    mainLayout->addWidget(glWidgets[1],1,1,1,1);
    mainLayout->addWidget(glWidgets[2],3,0,1,1);

    currentGlWidget = glWidgets[0];
    setLayout(mainLayout);
    timer = new QTimer(this);
    timer->start(40);
    connect(timer, SIGNAL(timeout()), this, SLOT(getImageData()));
}
GLSpoutImageWidget::~GLSpoutImageWidget()
{
    delete currentGlWidget;
    delete[] glWidgets[3];
    delete this;
}
void GLSpoutImageWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
}

void GLSpoutImageWidget::setCurrentGlWidget()
{
    currentGlWidget = qobject_cast<GLWidget*>(sender());
}

void GLSpoutImageWidget::setupReceivers()
{
    m_SpoutReceivers[0].SetReceiverName("Camera_Horizontal2");
    m_SpoutReceivers[1].SetReceiverName("Camera_Horizontal1");
    m_SpoutReceivers[2].SetReceiverName("Camera_Horizontal3");
//    m_SpoutReceivers[2].SetReceiverName("MRstageCamera");
}

void GLSpoutImageWidget::getImageData()
{
    setupReceivers();
    for (auto i = 0; i < 3; i++)
    {
        glWidgets[i]->update();
    }

    for (auto i = 0; i < 3; i++)
    {
        if (m_SpoutReceivers[i].ReceiveTexture(m_SpoutTexIDs[i], GL_TEXTURE_2D, true))
        {
            if (m_SpoutReceivers[i].IsUpdated())
            {
                g_SenderWidth = m_SpoutReceivers[i].GetSenderWidth();
                g_SenderHeight = m_SpoutReceivers[i].GetSenderHeight();
                g_SenderFormat = m_SpoutReceivers[i].GetSenderFormat();

                glWidgets[i]->updateAspectRatio(g_SenderWidth, g_SenderHeight);
                glWidgets[i]->createTexture(g_SenderWidth, g_SenderHeight);
                glBindTexture(GL_TEXTURE_2D, m_SpoutTexIDs[i]);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            }
        }
    }
}
