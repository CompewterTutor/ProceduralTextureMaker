/**
 * Part of the ProceduralTextureMaker project.
 * http://github.com/johanokl/ProceduralTextureMaker
 * Released under GPLv3.
 * Johan Lindqvist (johan.lindqvist@gmail.com)
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "generators/texturegenerator.h"

class TexGenApplication;
class TextureProject;
class ViewNodeScene;
class ViewNodeView;
class ItemInfoPanel;
class AddNodePanel;
class QCloseEvent;
class MenuActions;
class PreviewImagePanel;
class Preview3dPanel;
class SettingsPanel;
class SettingsManager;
class JSTexGenManager;

/**
 * @brief The MainWindow class
 *
 * The application's main window, containing all the scenes and panels.
 *
 * It initializes and configures the TextureProject with its submodules,
 * including which texture generators should be loaded.
 */
class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(TexGenApplication* parent = 0);
   virtual ~MainWindow();
   TextureProject* getTextureProject() { return project; }
   TexGenApplication* parent() { return parentapp; }
   MenuActions* getMenu() { return menuactions; }

public slots:
   bool saveAs();
   bool saveFile(bool newFileName = false);
   void openFile(QString);
   void clearScene();
   void showAbout();
   void showHelp();
   virtual void closeEvent(QCloseEvent*);
   void copyNode();
   void pasteNode();
   void cutNode();
   void saveImage(int id = 0);
   void reloadSceneView();
   void moveToFront();
   void resetViewZoom();
   void generatorNameCollision(TextureGeneratorPtr, TextureGeneratorPtr);

private:
   void drawScene();
   void createActions();
   bool maybeSave();
   ViewNodeScene* createScene(ViewNodeScene* source=0);

   TexGenApplication* parentapp;
   TextureProject* project;
   QString savedFileName;
   MenuActions* menuactions;

   ViewNodeScene* scene;
   ViewNodeView* view;
   SettingsManager* settingsManager;
   JSTexGenManager* jstexgenManager;
   ItemInfoPanel* iteminfopanel;
   SettingsPanel* settingspanel;
   AddNodePanel* addnodewidget;
   PreviewImagePanel* previewimagewidget;
   Preview3dPanel* preview3dwidget;
};

#endif // MAINWINDOW_H
