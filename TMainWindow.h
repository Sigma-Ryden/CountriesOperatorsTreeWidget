#ifndef TMAIN_WINDOW_H
#define TMAIN_WINDOW_H

#include <QMainWindow>
#include <QString>

#include "TCountriesOperatorsDatabase.h"

class TCountriesOperatorsTreeViewWidget;

class TMainWindow : public QMainWindow {
    Q_OBJECT

    public:
    TMainWindow(QWidget* parent = nullptr);
    ~TMainWindow();

    protected:
    void ConnectDatabase();
    void CreateWidgets();
    void SetupDemo(); // TODO: only for demo

    public:
    inline static QString const sConnectIniFileNamePath = "connect.ini";

    protected:
    TCountriesOperatorsDatabase m_xCountriesOperatorsDatabase;

    protected:
    TCountriesOperatorsTreeViewWidget* m_pCountriesOperatorsTreeViewWidget = nullptr;
};

#endif // TMAIN_WINDOW_H
