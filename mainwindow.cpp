#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "omegaeditclientfacade.h"

#include <sstream>
#include <iomanip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , oe_client_{new OmegaEditClientFacade}
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
    auto session = oe_client_->CreateSession(ui->filePathLineEdit->text().toStdString().c_str());

    if(!session) {

        ui->statusText->setTextColor(QColor(Qt::GlobalColor::red));
        ui->statusText->setText("Could not create OmegaEdit session");
    }
    else{
        viewport_ = new Viewport(session, 2048);
        os << "OmegaEdit session created @ " << session << " | Data -> " << viewport_;
        ui->statusText->setTextColor(QColor(Qt::GlobalColor::darkGreen));
        ui->statusText->setText(QString::fromStdString(os.str()));
        os.seekp(0);
        ui->Txt_VPBinDataOutput->setFontFamily("Anonymous Pro");
        const auto data = viewport_->data();
        if(!data)
            ui->Txt_VPBinDataOutput->setText("Invalid Viewport Data Pointer");
        else {
            for(auto i = 0; i < viewport_->capacity(); i++)
                os << std::setw(2) << std::setfill('0') << std::hex << (uint16_t)data[i] << " ";
            ui->Txt_VPBinDataOutput->setText(QString::fromStdString(os.str()));
        }
    }
}

