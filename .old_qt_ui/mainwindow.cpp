#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "session/session.h"
#include "session/sessionviewportmanager.h"
#include "session/viewport.h"
#include <sstream>
#include <iomanip>

static SessionViewportManager SessionViewportMgr {};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOE_Test_triggered()
{
    std::ostringstream os;
    ui->statusText->setText("Omega Edit Test Button pressed");
    session_ = new Session();

    SessionViewportMgr.Register(session_);

    if(!session_) {

        ui->statusText->setTextColor(QColor(Qt::GlobalColor::red));
        ui->statusText->setText("Could not create OmegaEdit session");
    }
    else{
        SessionViewportMgr.AddViewport(session_, new Viewport());
        // viewport_ = new Viewport(session, 2048);
        os << "OmegaEdit session created @ " << session_;
        ui->statusText->setTextColor(QColor(Qt::GlobalColor::darkGreen));
        ui->statusText->setText(QString::fromStdString(os.str()));
        os.seekp(0);
        // ui->Txt_VPBinDataOutput->setFontFamily("Anonymous Pro");
        // const auto data = viewport_->data();
        // if(!data)
        //     ui->Txt_VPBinDataOutput->setText("Invalid Viewport Data Pointer");
        // else {
        //     for(auto i = 0; i < viewport_->capacity(); i++)
        //         os << std::setw(2) << std::setfill('0') << std::hex << (uint16_t)data[i] << " ";
        //     ui->Txt_VPBinDataOutput->setText(QString::fromStdString(os.str()));
        // }
    }
}

