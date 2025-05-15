#include "TMainWindow.h"
#include "TCountriesOperatorsTreeViewWidget.h"
#include "TCountriesOperatorsItemModel.h"

TMainWindow::TMainWindow(QWidget* parent) : QMainWindow(parent) {
    ConnectDatabase();
    CreateWidgets();
    SetupDemo();
}

TMainWindow::~TMainWindow() {
}

void TMainWindow::ConnectDatabase() {
    m_xCountriesOperatorsDatabase.Init(sConnectIniFileNamePath);
}

void TMainWindow::CreateWidgets() {
    m_pCountriesOperatorsTreeViewWidget = new TCountriesOperatorsTreeViewWidget(this);
    setCentralWidget(m_pCountriesOperatorsTreeViewWidget);
}

void TMainWindow::SetupDemo() {
    m_pCountriesOperatorsTreeViewWidget->setFixedSize(600, 400);
    m_pCountriesOperatorsTreeViewWidget->CountriesOperatorsItemModel()->AddCountries(m_xCountriesOperatorsDatabase.Dump());
}
