#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtmetamacros.h>
#include <vector>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include "../utils/ColorPiseVal.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkImageViewer2> axialViewer;
    vtkNew<vtkImageViewer2> coronalViewer;
    vtkNew<vtkImageViewer2> sagittalViewer;
    vtkNew<vtkColorTransferFunction> colorFun;
    vtkNew<vtkPiecewiseFunction> opacityFun;
    QTimer *debounceTimer;
    inilizeProperties proper;
    Ui::MainWindow *ui;
    void addTransfers(std::vector<VolumePrope> &trans);
    void iterateTransferList();
    void updatePropertiesTransfers(std::vector<VolumePrope> &trans);

private slots:
  void onSliderValueChangedAxial(int value);
  void onSliderValueChangedCoronal(int value);
  void onSliderValueChangedSagittal(int value);
  void onMuscleButtonClick();
  void onBoneButtonClick();
  void onSkinButtonClick();
  void onLungButtonClick();
  void onSliderTimeout();
  void onNewTransferClick();
  void onDeleteAllClick();
  void onUpdateCLick();
};

#endif // MAINWINDOW_H
