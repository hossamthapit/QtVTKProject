#include "settings.h"
#include <qstring.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <Shape.h>
#include <Sphere.h>
#include <MainWindow.h>
#include <vtkSTLWriter.h>

Settings::Settings() {

}

Shape Settings::LoadShape(const char* mapperPath, const char* dataPath) {
    Shape shape = LoadShapeMapper(mapperPath);
    LoadShapeData(shape, dataPath);
    return shape;
}

Shape Settings::LoadShapeMapper(const char* path) {
    vtkSmartPointer < vtkSTLReader > tempReader = vtkSmartPointer<vtkSTLReader>::New();
    tempReader->SetFileName(path);
    tempReader->Update();

    vtkSmartPointer<vtkPolyDataMapper> tempMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    tempMapper->SetInputConnection(tempReader->GetOutputPort());

    Shape shape = Shape();
    shape.actor->SetMapper(tempMapper);
    return shape;
}

void Settings::LoadShapeData(Shape &shape, const char* path) {
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);

        in >> shape;
        file.close();
    }
}

void Settings::SaveShape(Shape &shape, const char* mapperPath, const char* dataPath) {
    SaveShapeMapper(shape, mapperPath);
    SaveShapeData(shape, dataPath);
}

void Settings::SaveShapeMapper(Shape& shape, const char* path) {
    vtkSmartPointer<vtkSTLWriter> tempStlWriter = vtkSmartPointer<vtkSTLWriter>::New();
    tempStlWriter->SetFileName(path);

    tempStlWriter->SetInputConnection(shape.shapeSource->GetOutputPort());
    tempStlWriter->Write();
}

void Settings::SaveShapeData(Shape& shape, const char* path) {
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);

        out << shape;
        file.close();
    }
}
