#ifndef INSTALLER_H
#define INSTALLER_H

#include <QtGui/QWidget>
#include <QMessageBox>
#include <QFile>
#include <QMenu>
#include <QProcess>
#include <QGraphicsScene>
#include <QTranslator>

#include "ui_installer.h"
#include "dialogHelp.h"
#include "dialogKeyboard.h"
#include "dialogDesktopSelection.h"
#include "dialogCheckHardware.h"
#include "wizardFreeBSD.h"
#include "wizardDisk.h"

#define wFREEBSD 1
#define wPCSERVER 2
#define wKDE 3
#define wLXDE 4
#define wGNOME 5
#define wXFCE 6

#include "backend.h"

class Installer : public QMainWindow, private Ui::Installer
{
    Q_OBJECT

public:
    Installer(QWidget *parent = 0);
    ~Installer();
    void changeLang(QString code);
    void initInstall();

private slots:
    void slotAbort();
    void slotBack();
    void slotHelp();
    void slotNext();
    void slotFinished();
    void slotChangeLanguage();
    void slotCheckHardware();

    // Disk slots
    void slotDiskCustomizeClicked();
    void slotSaveDiskChanges(QList<QStringList>, bool, bool);

    // Slots for the installation
    void slotInstallProcFinished( int exitCode, QProcess::ExitStatus status);
    void slotReadInstallerOutput();

    // Start xvkbd
    void slotPushVirtKeyboard();

    // Keyboard selector
    void slotPushKeyLayout();

    // Options related to USB config files 
    void slotSaveConfigUSB();
    void slotLoadConfigUSB();

    // Desktop selector slots
    void slotDesktopLeftClicked();
    void slotDesktopRightClicked();
    void slotDesktopCustomizeClicked();
    void slotSaveMetaChanges(QStringList);
    void slotSaveFBSDSettings(QString, QString, QString, QString, QString, QString, bool, bool, bool, QStringList);


private:

    void setArch();
    void startInstall(); // Function which begins the install process
    void installFailed(); // Function which does post-install failure stuff

    // Disk functions
    void loadDiskInfo();
    bool autoGenPartitionLayout(QString target, bool isDisk);
    QStringList getDiskSummary();

    // Functions which return parts of the config file
    QStringList getGlobalCfgSettings();
    QStringList getDiskCfgSettings();
    QStringList getComponentCfgSettings();

    void startConfigGen(); // Function which takes pieces of cfg, and assembles
    void checkSpaceWarning(); // Function to check space of disk drive

    void proceed(bool);
    bool isInstalled();
    bool checkDiskRequirements();

    // Desktop packages
    void initDesktopSelector();
    void moveDesktopWheel(bool direction);
    void changeMetaPkgSelection();
    QStringList getDeskPkgCfg();
    QStringList wheelIcons;
    QStringList wheelName;
    QStringList wheelDesc;
    int wheelCurItem;
    bool availDesktopPackageData;
    bool availServerPackageData;
    QList<QStringList> listDeskPkgs; // QStringList for our available desktop pkgs
    QList<QStringList> listServerPkgs; // QStringList for our available server pkgs
    QStringList selectedPkgs; // QStringList for selected packages
    desktopSelection *desks;
    QGraphicsScene *defaultScene;
    QGraphicsScene *customScene;
    
    // Encryption bits
    QString autoEncPass;
    void warnEncryption();

    QList<QStringList> sysDisks; // Our lists which contains disk info
    QList<QStringList> sysPartitions; // Our lists which contains partition info
    QList<QStringList> sysFinalDiskLayout; // Our lists which contains the final disk layout
    bool loadMBR;
    bool loadGPT;
    int systemMemory; // Ammount of system RAM we have in MB
    QList<QStringList> listComponents; // QStringList for our available components
    QStringList languages;
    QStringList updatePartitions;
    QString Arch;
    QProcess *installProc;
    bool installFoundCounter;
    bool installFoundMetaCounter;
    bool installFoundFetchOutput;
    bool isLiveMode;
    bool hasPkgsOnMedia;
    bool hasInstallOnMedia;
    bool hasFreeBSDOnMedia;
    bool toggleKeyLayout;
    bool haveWarnedSpace;

    // Hardware checker
    dialogCheckHardware *pcHardware;

    // Help Stuff
    dialogHelp *pcHelp;

    // Infobox 
    dialogInfoBox *dIB;
    QMenu *popup;

    // FreeBSD setup wizard
    wizardFreeBSD *wFBSD;
    
    // FreeBSD options
    QString fRootPW;
    QString fName;
    QString fUserName;
    QString fUserPW;
    QString fShell;
    QString fHost;
    bool fSSH;
    bool fSRC;
    bool fPORTS;
    QStringList fNetSettings;
    QStringList getUsersCfgSettings();

    // Keyboard Widget
    widgetKeyboard *wKey;
    QStringList keyModels;
    QStringList keyLayouts;

    // Disk setup wizard
    wizardDisk *wDisk;
    QTranslator *translator;

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // INSTALLER_H
