#include <vtkSTLReader.h>
#include <vtkSTLReader.h>
#include <qstring.h>
#include <Shape.h>


static class Settings {


public:
    Settings();
    static Shape LoadShape(const char* mapperPath, const char* dataPath);
    static Shape LoadShapeMapper(const char* path);
    static void LoadShapeData(Shape &shape, const char* path);

    static void SaveShape(Shape& shape, const char* mapperPath, const char* dataPath);
    static void SaveShapeMapper(Shape& shape, const char* path);
    static void SaveShapeData(Shape& shape, const char* path);

};

