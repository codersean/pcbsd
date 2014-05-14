//===========================================
//  Lumina-DE source code
//  Copyright (c) 2014, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#include "LPlugins.h"

LPlugins::LPlugins(){
  LoadPanelPlugins();
  LoadDesktopPlugins();
  LoadMenuPlugins();
}

LPlugins::~LPlugins(){
}

//Plugin lists
QStringList LPlugins::panelPlugins(){
  return PANEL.keys();
}
QStringList LPlugins::desktopPlugins(){
  return DESKTOP.keys();
}
QStringList LPlugins::menuPlugins(){
  return MENU.keys();
}

//Information on individual plugins
LPI LPlugins::panelPluginInfo(QString plug){
  if(PANEL.contains(plug)){ return PANEL[plug]; }
  else{ return LPI(); }
}
LPI LPlugins::desktopPluginInfo(QString plug){
  if(DESKTOP.contains(plug)){ return DESKTOP[plug]; }
  else{ return LPI(); }
}
LPI LPlugins::menuPluginInfo(QString plug){
  if(MENU.contains(plug)){ return MENU[plug]; }
  else{ return LPI(); }
}

//===================
//             PLUGINS
//===================
void LPlugins::LoadPanelPlugins(){
  PANEL.clear();
  //User Button
  LPI info;
    info.name = QObject::tr("User Button");
    info.description = QObject::tr("This is the main system access button for the user (applications, directories, settings, log out).");
    info.ID = "userbutton";
    info.icon = "user-identity";
  PANEL.insert(info.ID, info);
  //Desktop Bar
  info = LPI(); //clear it
    info.name = QObject::tr("Desktop Bar");
    info.description = QObject::tr("This provides shortcuts to everything in the desktop folder - allowing easy access to all your favorite files/applications.");
    info.ID = "desktopbar";
    info.icon = "user-desktop";
  PANEL.insert(info.ID, info);  
  //Spacer
  info = LPI(); //clear it
    info.name = QObject::tr("Spacer");
    info.description = QObject::tr("Invisible spacer to separate plugins.");
    info.ID = "spacer";
    info.icon = "transform-move";
  PANEL.insert(info.ID, info);  	
  //Desktop Switcher
  info = LPI(); //clear it
    info.name = QObject::tr("Desktop Switcher");
    info.description = QObject::tr("Controls for switching between the various virtual desktops.");
    info.ID = "desktopswitcher";
    info.icon = "preferences-desktop-display-color";
  PANEL.insert(info.ID, info);  	
  //Battery
  info = LPI(); //clear it
    info.name = QObject::tr("Battery Monitor");
    info.description = QObject::tr("Keep track of your battery status.");
    info.ID = "battery";
    info.icon = "battery-charging";
  PANEL.insert(info.ID, info);  	
  //Clock
  info = LPI(); //clear it
    info.name = QObject::tr("Time/Date");
    info.description = QObject::tr("View the current time and date.");
    info.ID = "clock";
    info.icon = "preferences-system-time";
  PANEL.insert(info.ID, info);  	
}

void LPlugins::LoadDesktopPlugins(){
  DESKTOP.clear();
  //No desktop plugins yet
}

void LPlugins::LoadMenuPlugins(){
  MENU.clear();
  //Terminal
  LPI info;
    info.name = QObject::tr("Terminal");
    info.description = QObject::tr("Start the default system terminal.");
    info.ID = "terminal";
    info.icon = "utilities-terminal";
  MENU.insert(info.ID, info);
  //Applications
  info = LPI(); //clear it
    info.name = QObject::tr("Applications");
    info.description = QObject::tr("Show the system applications menu.");
    info.ID = "applications";
    info.icon = "system-run";
  MENU.insert(info.ID, info);
  //Line seperator
  info = LPI(); //clear it
    info.name = QObject::tr("Separator");
    info.description = QObject::tr("Static horizontal line.");
    info.ID = "line";
    info.icon = "insert-horizontal-rule";
  MENU.insert(info.ID, info);
  //Settings
  info = LPI(); //clear it
    info.name = QObject::tr("Settings");
    info.description = QObject::tr("Show the desktop settings menu.");
    info.ID = "settings";
    info.icon = "configure";
  MENU.insert(info.ID, info);

}