#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext> // 必须引入这个
#include "backend.h"   // 引入你的 C++ 类头文件
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    // 【关键步骤】实例化 C++ 对象，并注入到 QML 环境中
    Backend myBackend;
    // 把 myBackend 对象命名为 "backend"，QML 里就能用这个名字了
    engine.rootContext()->setContextProperty("backend", &myBackend);



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
